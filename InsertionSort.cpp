#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define nums 30
void InsertSort(int a[], int n)
{
    for(int i= 1; i<n; i++){
        int get = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > get){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = get;
    }
}
int main(){
    int data[nums];
    printf("随机数：");
    srand((unsigned)time(NULL));
    for(int i = 0; i< nums;i++){
        int t = rand() % 101;
        data[i] = t;
        printf("%d ",t);
    }
    printf("\n");
    int t = rand() % 101;
    InsertSort(data,nums);
    printf("排序后：");
    for(int i = 0; i< nums;i++){
        printf("%d ",data[i]);
    }
    printf("\n");
    return 0;
}
