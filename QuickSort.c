#include<stdio.h>

void quickSort(int list[], int first, int last) {
    int pivot, i, j, temp;

    if(first < last) {
        pivot = first;
        i = first;
        j = last;

        while(i < j) {
            while(list[i] <= list[pivot] && i < last){
            	i++;
			}
            while(list[j] > list[pivot]){
            	j--;	
			}
            if(i < j) {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }

        temp = list[pivot];
        list[pivot] = list[j];
        list[j] = temp;
        quickSort(list, first, j - 1);
        quickSort(list, j + 1, last);
    }
}

int main() {
    int list[20], n, i;

    printf("Enter size of the list: ");
    scanf("%d", &n);

    printf("Enter %d integer values: \n", n);
    for(i = 0; i < n; i++){
    	scanf("%d", &list[i]);	
	}

    quickSort(list, 0, n - 1);

    printf("List after sorting is: ");
    for(i = 0; i < n; i++){
    	printf(" %d", list[i]);    	
	}

    return 0;
}