#include <stdio.h>

int main() {
    int arr[100], n = 0, choice, pos, value;

    while(1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter position and value: ");
                scanf("%d %d", &pos, &value);
                for(int i = n; i > pos; i--)
                    arr[i] = arr[i-1];
                arr[pos] = value;
                n++;
                break;

            case 2: 
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                for(int i = pos; i < n-1; i++)
                    arr[i] = arr[i+1];
                n--;
                break;

            case 3: 
                printf("List: ");
                for(int i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                break;

            case 4:
                return 0;
        }
    }
}
