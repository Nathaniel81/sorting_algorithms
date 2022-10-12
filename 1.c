#include <stdio.h>



void swap(int arr[], int x, int y)

{

		int tmp;

			tmp = arr[x];

				arr[x] = arr[y];

					arr[y] = tmp;

}



void main()

{

		int arr[] = {23, 29, 15, 19, 31, 7, 9, 5, 2};

			int i, j, gap, len = 9;



				for (i = 0; i < len; i++)

							printf("%d ", arr[i]);

					printf("\n");



						for (gap = len/2; gap >= 1; gap/2)

								{

											for (j = gap; j < len; j++)

														{

																		for (i = j - gap; i >= 0; i - gap)

																						{

																											if (arr[i + gap] > arr[i])

																																	break;

																															else

																																					swap(arr, i+gap, i);

																																		}

																				}

												}

							

							for (i = 0; i < len; i++)

										printf("%d ", arr[i]);

}
