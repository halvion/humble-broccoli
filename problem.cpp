#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#define SIZE 50

void insertProp(char*, char*, char*, int, char*, char*, int, int);

void deleteProp(char*, int);

void viewMenu();

struct Node
{
    int propertyIndex;
    int roomQuant;
    int key;
    char propertyId[10];
    char ownerName[50];
    char propertyName[21];
    char propertyType[15];
    char streetName[SIZE];
    Node *next;
}*head[SIZE] = {NULL};
int propTotal = 1;

Node *createNewNode(char propertyName[21],char propertyType[15], char ownerName[50], int roomQuant, char streetName[50], char propertyId[10], int propertyIndex, int key){
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->propertyName, propertyName);
    strcpy(newNode->propertyId, propertyId);
    strcpy(newNode->propertyType, propertyType);
    strcpy(newNode->ownerName, ownerName);
    strcpy(newNode->streetName, streetName);
    newNode->roomQuant = roomQuant;
    newNode->propertyIndex = propertyIndex;
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

void insertProp(char name[], char type[], char ownerName[], int room, char street[], char id[], int index, int key){
    Node *property = createNewNode(name, type, ownerName, room, street, id, index, key);
    if(head[key] == NULL){
        head[key] = property;
    }
    else{
        Node *curr = head[key];
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = property;
       
    }
}

char* propertyId(char type[], int propertyIndex){
    char* propId = (char*)malloc(8 * sizeof(char));
    sprintf(propId,"%c%c%03d", toupper(type[0]), toupper(type[1]), propertyIndex);
    return propId;
}

int hashKey(char id[]) {
    int sum = 0;
    int len = strlen(id);
    for (int i = 0; i < len; i++) {
        sum += id[i];
    }
    return sum % SIZE;
}


int chPropertyType(char propType[]){
    if(strcmp(propType, "Mansion") == 0 || strcmp(propType, "Cluster") == 0 || strcmp(propType, "Bungalow") == 0){
        return 1;
    }
    return -1;
}
int chOwnerName(char name[]){
    if(strncmp(name, "Mr.", 3) == 0 || strncmp(name, "Mrs.", 4)==0){
        return 1;
    }
    return -1;
}
int chStreetName(char street[]){
    int len = strlen(street);

    if(strncmp(street + len - 6, "street", 6)== 0){
        return 1;
    }
    return -1;
}



void addNewProperty(){
    system("clear");
    int length = 0;
    int propQuantity = 0;
    char ownerName[50];
    char propertyName[21];
    char propertyType[15];
    char streetName[50];
    do{
        printf("Input property name [length 5...20]:\n > ");
        getchar();
        scanf("%[^\n]", propertyName); getchar();
        length = strlen(propertyName);
    }while(length < 5 || length > 20);
    do{
        printf("Input property type [Mansion|Bungalow|Cluster](Case Sensitive):\n > ");
        scanf("%s", propertyType); getchar();
    }while(chPropertyType(propertyType) == -1);
    char *propId = propertyId(propertyType, propTotal);
    int key = hashKey(propId);
    printf("Key : %d\n", key);
    do{
        printf("Input room quantity [1..8]:\n > ");
        scanf("%d", &propQuantity);
    }while(propQuantity < 1 || propQuantity > 8);
    do{
        printf("Input owner name startwith Mr. or Mrs. :\n > "); 
        getchar();
        scanf("%[^\n]", ownerName); 


    }while(chOwnerName(ownerName) == -1);
    do{
        printf("Input street name of property endswith 'street' (case sensitive) :\n > ");
        getchar();
        scanf("%[^\n]", streetName); getchar();

    }while(chStreetName(streetName) == -1);
    system("clear");
    char select;
    printf("Are you sure to add this property[Y or N](case sensitive):\n > ");
    scanf("%c", &select); getchar();
    if(select == 'N'){
        system("clear");
        viewMenu();
    }
    else if (select == 'Y'){
        insertProp(propertyName, propertyType, ownerName, propQuantity, streetName, propId, propTotal, key);
        propTotal++;
        system("clear");
        viewMenu();


    }

}

void viewProperties(){
    system("clear");
    puts("LIST OF PROPERTIES\n");
    puts("--------------------");
    puts("\n");
    int flag = 0;
    int i = 0;
        
    for(i; i < SIZE ; i++){
        Node *curr = head[i];
        while(curr!=NULL){
            printf("Property Id : [%s]\n", curr->propertyId);
            printf("Property Name : %s\n", curr->propertyName);
            printf("Property Type : %s\n", curr->propertyType);
            printf("Room Quantity : %d\n", curr->roomQuant);
            printf("Owner : %s\n", curr->ownerName);
            printf("Property Street : %s\n", curr->streetName);
            puts("\n");
            curr = curr->next;
            flag = 1;
        }
        
    }
    if(flag == 0){
            printf("No data inside!!!\n");
            printf("Press any key to continue...");
            getchar();
            getchar();
            system("clear");
            viewMenu();
        }
        printf("Press any key to continue...");
            getchar();
            getchar();
            system("clear");
            viewMenu(); 

    
    
}

void deleteProperties(){
    system("clear");
    puts("LIST OF PROPERTIES\n");
    puts("--------------------");
    puts("\n");
    int flag = 0;
    int i = 0;
        
    for(i; i < SIZE ; i++){
        Node *curr = head[i];
        while(curr!=NULL){
            printf("Property Id : [%s]\n", curr->propertyId);
            printf("Property Name : %s\n", curr->propertyName);
            printf("Property Type : %s\n", curr->propertyType);
            printf("Room Quantity : %d\n", curr->roomQuant);
            printf("Owner : %s\n", curr->ownerName);
            printf("Property Street : %s\n", curr->streetName);
            puts("\n");
            curr = curr->next;
            flag = 1;
        }
        
    }
    if(flag == 0){
            printf("No data inside!!!\n");
            printf("Press any key to continue...");
            getchar();
            getchar();
            system("clear");
            viewMenu();
        }
    
    
    printf("Enter the Property's ID [MA*** | BA*** | CL***]\n > ");
    char id[10]; int key;
    scanf("%s", id);
    key = hashKey(id);
    printf("Key: %d\n", key); // debug statement
    if (key < 0 || key >= SIZE) {
        printf("Invalid key. Please try again.\n");
        printf("Press any key to continue...");
        getchar();
        getchar();
        system("clear");
        viewMenu();
    }
    printf("Calling deleteProp()...\n"); // debug statement
    deleteProp(id, key);
}

void deleteProp(char id[], int key){
    printf("deleteProp() called with id=%s, key=%d\n", id, key); // debug statement
    if (head == NULL || head[key] == NULL) {
        printf("|| DATA NOT FOUND||\n");
        printf("Press any key to continue...");
        getchar();
        getchar();
        system("clear");
        viewMenu();
    }
    if(strcmp(head[key]->propertyId, id)== 0){
        
        Node *temp = head[key];
        printf("%s - %s Deleted.\n", head[key]->propertyId, head[key]->next->propertyName);
        head[key] = head[key]->next;
        temp = NULL;
        free(temp);
        puts("\n");
        printf("Press any key to continue...");
        getchar();
        getchar();
        system("clear");
        viewMenu();
    }
    else{
        Node *curr = head[key];
        while(curr->next != NULL && strcmp(curr->next->propertyId, id)!= 0){
            curr = curr->next;
        }
        if(curr->next == NULL){
            printf("|| DATA NOT FOUND||\n");
            printf("Press any key to continue...");
            getchar();
            getchar();
            system("clear");
            viewMenu();
        }
        printf("%s - %s Deleted.\n", curr->next->propertyId, curr->next->propertyName);
        Node *temp = curr->next;
        curr->next = temp->next;
        temp = NULL;
        free(temp);
        puts("\n");
        printf("Press any key to continue...");
        getchar();
        getchar();
        system("clear");
        viewMenu();
    }
}


void viewMenu(){
     printf("|| BlueJack Properties. ||\n");
        printf("--------------------------\n");
        printf("|| 1. Add new Properties  \n");
        printf("|| 2. View Properties     \n");
        printf("|| 3. Delete Property.    \n");
        printf("|| 4. Exit.               \n");
        printf("Choose [1 - 4] >> ");
         int menu;
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            addNewProperty();
            break;
        
        case 2:
            viewProperties();
            break;
        case 3:
            deleteProperties();
            break;

        default:
            system("clear");
            viewMenu();
            break;
        }
        
}

int main(){
    viewMenu();
 
   




    return 0;
}