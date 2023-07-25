#include <stdio.h>
#include <stdlib.h>

// Function to find page faults using FIFO
int pageFaults(int pages[], int n, int capacity)
{
	// To represent set of current pages. We use
	// an array to quickly check if a page is present in set or not
	int* s = (int*)malloc(capacity * sizeof(int));

	// To store the pages in FIFO manner
	int* indexes = (int*)malloc(capacity * sizeof(int));

	// Start from initial page
	int page_faults = 0;
	int i, j;
	for (i = 0; i < n; i++)
	{
		// Check if the set can hold more pages
		if (page_faults < capacity)
		{
			// Insert it into set if not present
			// already which represents page fault
			int found = 0;
			for (j = 0; j < page_faults; j++)
			{
				if (s[j] == pages[i])
				{
					found = 1;
					break;
				}
			}

			if (!found)
			{
				// Insert the current page into the set
				s[page_faults] = pages[i];

				// increment page fault
				page_faults++;

				// Push the current page into the queue
				indexes[page_faults - 1] = pages[i];
			}
		}

		// If the set is full then need to perform FIFO
		// i.e. remove the first page of the queue from
		// set and queue both and insert the current page
		else
		{
			// Check if current page is not already
			// present in the set
			int found = 0;
			for (j = 0; j < capacity; j++)
			{
				if (s[j] == pages[i])
				{
					found = 1;
					break;
				}
			}

			if (!found)
			{
				// Store the first page in the
				// queue to be used to find and
				// erase the page from the set
				int val = indexes[0];

				// Shift the indexes array to the left
				for (j = 1; j < capacity; j++)
				{
					indexes[j - 1] = indexes[j];
				}

				// Remove the first page from the set
				for (j = 0; j < capacity; j++)
				{
					if (s[j] == val)
					{
						for (int k = j; k < capacity - 1; k++)
						{
							s[k] = s[k + 1];
						}
						break;
					}
				}

				// Insert the current page in the set
				s[capacity - 1] = pages[i];

				// Push the current page into the queue
				indexes[capacity - 1] = pages[i];

				// Increment page faults
				page_faults++;
			}
		}
	}

	free(s);
	free(indexes);

	return page_faults;
}

// Driver code
int main()
{
	int pages[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2 };
	int n = sizeof(pages) / sizeof(pages[0]);
	int capacity = 4;
	printf("The number of page faults is %d.\n", pageFaults(pages, n, capacity));
	return 0;
}
