#include <stdio.h>
#include <stdlib.h>

int linear(int a[], int n, int key){
    for(int i=0;i<n;i++) if(a[i]==key) return i;
    return -1;
}

int binary(int a[], int n, int key){
    int l=0, r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]==key) return m;
        else if(a[m]<key) l=m+1;
        else r=m-1;
    }
    return -1;
}

void bubbleSort(int a[], int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]){
                int t=a[j]; a[j]=a[j+1]; a[j+1]=t;
            }
}

int main(){
    int n, choice, key;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements:\n");
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    while(1){
        printf("\n1.Linear Search\n2.Binary Search\n3.Exit\nEnter choice: ");
        scanf("%d",&choice);
        if(choice==3) break;
        printf("Enter element to search: ");
        scanf("%d",&key);

        int idx=-1;
        if(choice==1){
            idx = linear(a,n,key);
        }else if(choice==2){
            bubbleSort(a,n); // Binary search needs sorted array
            idx = binary(a,n,key);
        }else{
            printf("Invalid choice\n"); continue;
        }

        if(idx==-1) printf("Element not found\n");
        else printf("Element found at index %d\n", idx);
    }
    return 0;
}
