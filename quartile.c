#include<stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    getchar();

    for(int i = 0; i < t; i++){
        
        int blue;
        scanf("%d", &blue);
        const int size = blue;
        getchar();
        int numArr[size];
        for(int j = 0; j < size ; j++){
            scanf("%d", &numArr[j]);
        }
        if(size % 2 == 1){
            float q1index, q2index, q3index;
            q1index = (size+1)/4;
            q2index = size;
            q2index = (3*(size+1))/4;
            printf("Case #%d:\n", i+1);
            printf("q1 : %.f\n", q1index-1);
            printf("q2 : %d\n", size);
            printf("q3 : %.f\n", q3index);

        }
    }


    return 0;
}