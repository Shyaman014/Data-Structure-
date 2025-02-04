
#include<stdio.h>

int arr[50];

void merge(int arr[], int start, int mid, int end){
	int i, j, k;
	
	int len1 = mid - start + 1;
	int len2 = end - mid;
	
	int leftArr[len1], rightArr[len2];
	
	for(i=0;i<len1;i++){
		leftArr[i] = arr[start + i];
	}
	for(j=0;j<len2;j++){
		rightArr[j] = arr[mid + 1 + j];
	}
	
	i=0;
	j=0;
	k = start;
	
	while(i<len1 && j<len2){
		if(leftArr[i] <= rightArr[j]){
			arr[k] = leftArr[i];
			i++;
		} else {
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}
	while(i<len1){
		arr[k] = leftArr[i];
		i++;
		k++;
	}
	while(j<len2){
		arr[k] = rightArr[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int start, int end){
	if(start < end){
		int mid = start + (end - start)/2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}
void display(int arr[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t", arr[i]);
	}
}

int main(){
	int n, i;
	printf("Enter the number of elements: \n");
	scanf("%d", &n);
	printf("Enter %d integers: \n", n);
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	
	printf("Original array: \n");
	display(arr, n);
	mergeSort(arr, 0, n - 1);
	printf("\nSorted array: \n");
	display(arr, n);
	return 0;
}
