#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define nums 30
void ShellSort(int a[], int n)
{
    int h = 0;
    while(h < n){
        h = 3 * h + 1;
    }
    while(h >= 1){
        for(int i = h;i < n;i++){
            int j = i - h;
            int get = a[i];
            while(j >= 0 && a[j] > get){
                a[j + h] = a[j];
                j = j - h;
            }
            a[j + h] = get;
        }
        h = (h - 1) / 3;
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
    ShellSort(data,nums);
    printf("排序后：");
    for(int i = 0; i< nums;i++){
        printf("%d ",data[i]);
    }
    printf("\n");
    return 0;
}
