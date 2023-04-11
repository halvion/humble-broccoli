#include <stdio.h>
#include <string.h>

#define SIZE 10

int hashKey(char id[]) {
    if (strlen(id) < 4) {
        return -1; // or some other error code
    }
    int sum = id[2] + id[3] + id[4];
    return sum % SIZE;
}

int main() {
    char id[] = "ABCDE";
    int key = hashKey(id);
    printf("Hash key for %s is %d\n", id, key);
    return 0;
}