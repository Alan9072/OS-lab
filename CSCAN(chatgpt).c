#include <stdio.h>
#include <stdlib.h>

void main() {
    int queue[30], n, headposition, i, j, k, seek = 0, maxrange, difference, temp;
    int queue1[20], queue2[20], temp1 = 0, temp2 = 0;
    float averageSeekTime;

    // Reading the maximum range of the disk
    printf("Enter the maximum range of Disk: ");
    scanf("%d", &maxrange);

    // Reading the number of queue requests (disk access requests)
    printf("Enter the number of queue requests: ");
    scanf("%d", &n);

    // Reading the initial head position (starting point)
    printf("Enter the initial head position: ");
    scanf("%d", &headposition);

    // Reading disk positions to be read in the order of arrival
    printf("Enter the disk positions to be read(queue): ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &temp);

        // Dividing requests into two arrays based on head position
        if (temp > headposition) {
            queue1[temp1++] = temp;
        } else {
            queue2[temp2++] = temp;
        }
    }

    // Sorting queue1 in ascending order
    for (i = 0; i < temp1 - 1; i++) {
        for (j = i + 1; j < temp1; j++) {
            if (queue1[i] > queue1[j]) {
                temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }
        }
    }

    // Sorting queue2 in ascending order
    for (i = 0; i < temp2 - 1; i++) {
        for (j = i + 1; j < temp2; j++) {
            if (queue2[i] > queue2[j]) {
                temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }
        }
    }

    // Merging the two queues into the final request queue
    for (i = 1, j = 0; j < temp1; i++, j++) {
        queue[i] = queue1[j];
    }

    queue[i++] = maxrange;  // Adding maxrange to simulate the disk end
    queue[i++] = 0;         // Adding 0 to simulate the wrap-around

    for (j = 0; j < temp2; i++, j++) {
        queue[i] = queue2[j];
    }

    queue[0] = headposition;  // Initial head position

    // Calculating seek time
    for (j = 0; j <= n + 1; j++) {
        difference = abs(queue[j + 1] - queue[j]);
        seek += difference;
        printf("Disk head moves from position %d to %d with Seek %d\n", queue[j], queue[j + 1], difference);
    }

    // Calculating and displaying average seek time
    averageSeekTime = seek / (float)n;
    printf("Total Seek Time = %d\n", seek);
    printf("Average Seek Time = %.2f\n", averageSeekTime);
}
