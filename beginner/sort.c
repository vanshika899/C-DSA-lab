#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble(int a[], int n){
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
}

void insertion(int a[], int n){
    for(int i=1; i<n; i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void quick(int a[], int l, int h){
    if(l < h){
        int pivot = a[h];
        int i = l-1;
        for(int j=l; j<h; j++){
            if(a[j] <= pivot){
                i++;
                swap(&a[i], &a[j]);
            }
        }
        swap(&a[i+1], &a[h]);
        int pi = i+1;
        quick(a, l, pi-1);
        quick(a, pi+1, h);
    }
}

void merge(int a[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    for(int i=0; i<n1; i++) L[i] = a[l+i];
    for(int i=0; i<n2; i++) R[i] = a[m+1+i];
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while(i<n1) a[k++] = L[i++];
    while(j<n2) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r){
    if(l < r){
        int m = l + (r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}

void heapify(int a[], int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && a[l]>a[largest]) largest = l;
    if(r<n && a[r]>a[largest]) largest = r;
    if(largest != i){
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void heap(int a[], int n){
    for(int i=n/2-1; i>=0; i--)
        heapify(a, n, i);
    for(int i=n-1; i>=0; i--){
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

void print(int a[], int n){
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(){
    int n, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n], b[n];
    printf("Enter elements:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    while(1){
        printf("\n--- MENU ---\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Quick Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Heap Sort\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        for(int i=0; i<n; i++) b[i] = a[i];

        switch(choice){
            case 1:
                bubble(b, n);
                printf("Sorted array: ");
                print(b, n);
                break;
            case 2:
                insertion(b, n);
                printf("Sorted array: ");
                print(b, n);
                break;
            case 3:
                quick(b, 0, n-1);
                printf("Sorted array: ");
                print(b, n);
                break;
            case 4:
                mergeSort(b, 0, n-1);
                printf("Sorted array: ");
                print(b, n);
                break;
            case 5:
                heap(b, n);
                printf("Sorted array: ");
                print(b, n);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
