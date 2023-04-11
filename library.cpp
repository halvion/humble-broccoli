#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 50

void insertBook(char*, char*, char*, int); void deleteBook(char*); void viewMenu();

struct Node 
{ int bookIndex;
  int pageNum;
  int key;
  char bookId[20];
  char bookTitle[50];
  char bookAuthor[50];
  char bookISBN[20];
  Node *next; 
} *head[SIZE] = {NULL};

int bookTotal = 1;

Node *createNewNode(char bookTitle[50], char bookAuthor[50], char bookISBN[20], int pageNum, char bookId[20], int bookIndex, int key)
 { Node *newNode = (Node*)malloc(sizeof(Node));
   strcpy(newNode->bookTitle, bookTitle);
   strcpy(newNode->bookAuthor, bookAuthor);
   strcpy(newNode->bookISBN, bookISBN);
   strcpy(newNode->bookId, bookId);
   newNode->pageNum = pageNum; newNode->bookIndex = bookIndex; newNode->key = key; newNode->next = NULL; return newNode; }

void insertBook(char title[], char author[], char ISBN[], int pageNum) { char bookId[20]; sprintf(bookId, "B-%05d-%c-%c", bookTotal, toupper(title[0]), toupper(title[1])); int key = 0; for (int i = 0; i < strlen(bookId); i++) { key += bookId[i]; } key %= SIZE; Node *book = createNewNode(title, author, ISBN, pageNum, bookId, bookTotal, key); if (head[key] == NULL) { head[key] = book; } else { Node *curr = head[key]; while (curr->next != NULL) { curr = curr->next; } curr->next = book; } bookTotal++; }

void viewBooks() { printf("LIST OF BOOKS\n"); printf("--------------------\n\n"); int flag = 0; for (int i = 0; i < SIZE; i++) { Node *curr = head[i]; while (curr != NULL) { printf("Book ID: %s\n", curr->bookId); printf("Title: %s\n", curr->bookTitle); printf("Author: %s\n", curr->bookAuthor); printf("ISBN: %s\n", curr->bookISBN); printf("Page Number: %d\n", curr->pageNum); printf("\n"); curr = curr->next; flag = 1; } } if (flag == 0) { printf("No data inside!!!\n"); } printf("Press any key to continue..."); getchar(); getchar(); system("clear"); viewMenu(); }

void deleteBook(char id[]) {
     int key = 0;
      for (int i = 0; i < strlen(id); i++) 
      { key += id[i]; } key %= SIZE;
       if (head[key] == NULL) {
         printf("|| DATA NOT FOUND||\n"); 
         printf("Press any key to continue...");
          getchar(); 
          getchar(); 
          system("clear"); 
          viewMenu(); } 
          if (strcmp(head[key]->bookId, id) == 0) { 
            Node *temp = head[key]; 
            printf("%s - %s Deleted.\n", head[key]->bookId, head[key]->bookTitle); 
            head[key] = head[key]->next; temp = NULL; free(temp); 
            printf("Press any key to continue..."); 
            getchar(); getchar(); system("clear"); viewMenu(); 
            }else { 
                Node *curr = head[key]; 
                while (curr->next != NULL && strcmp(curr->next->bookId, id) != 0) { 
                    curr = curr->next; 
                    } 
                    if (curr->next == NULL) { 
                        printf("|| DATA NOT FOUND||\n"); 
                        printf("Press any key to continue..."); 
                        getchar(); 
                        getchar(); 
                        system("clear"); 
                        viewMenu(); 
                        } 
                        printf("%s - %s Deleted.\n", curr->next->bookId, curr->next->bookTitle); 
                        Node *temp = curr->next; curr->next = temp->next; temp = NULL; free(temp); 
                        printf("Press any key to continue..."); 
                        getchar(); 
                        getchar(); 
                        system("clear"); 
                        viewMenu(); 
                 } 
}

void viewMenu() { printf("|| Bluejack Library ||\n1. Insert Book\n"); printf("2. View Books\n"); printf("3. Delete Book\n"); printf("4. Exit\n"); printf("Choose an option: "); int choice; scanf("%d", &choice); getchar(); switch (choice) { case 1: { char title[50], author[50], ISBN[20]; int pageNum; printf("Enter Book Title: "); fgets(title, 50, stdin); title[strcspn(title, "\n")] = 0; printf("Enter Book Author: "); fgets(author, 50, stdin); author[strcspn(author, "\n")] = 0; printf("Enter Book ISBN: "); fgets(ISBN, 20, stdin); ISBN[strcspn(ISBN, "\n")] = 0; printf("Enter Page Number: "); scanf("%d", &pageNum); getchar(); insertBook(title, author, ISBN, pageNum); break; } case 2: { viewBooks(); break; } case 3: { char id[20]; printf("Enter Book ID: "); fgets(id, 20, stdin); id[strcspn(id, "\n")] = 0; deleteBook(id); break; } case 4: { printf("Thank you for using Bluejack Library!\n"); exit(0); } default: { printf("Invalid choice! Please choose again.\n"); viewMenu(); } } }
int main() { while (1) { viewMenu(); } return 0; }

