#include <stdio.h>

void main()
{
//	int arr[] = {9, 7, 5, 6, 4};
//	int i, j, tmp;
//
//	for (i = 1; i < 5; i++)
//	{
//		tmp = arr[i];
//		j = i - 1;
//		while (j >= 0 && tmp < arr[j])
//		{
//			arr[j + 1] = arr[j];
//			j -= 1;
//		}
//		arr[j + 1] = tmp;
//
//	}
//
//	for (i = 0; i < 5; i++)
//		printf("%d ", arr[i]);
int arr[] = {9, 7, 5, 6, 4};
int i, j, tmp;

for (i = 0; i < 4; i++)
{
	int mp = i;
	for (j = i + 1; j < 5; j++)
		if (arr[j] < arr[mp]) mp = j;
	if (mp != i)
	{
		int tmp = arr[mp];
		arr[mp] = arr[i];
		arr[i] = tmp;
	}
}
for (i = 0; i < 5; i++)
{
	printf("%d ", arr[i]);
}

}