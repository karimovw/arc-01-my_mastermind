#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void fillNull(char *str, int count) {
    memset(str, '\0', count);
}

void readAndSortNumbers() {
    int fileDescriptor = open("text", O_RDONLY);
    int bufferIndex = 0;
    int arrayIndex = 0;
    int temp = 0;
    int bufferSize = 128; 
    char character;
    char *buffer = malloc(sizeof(char) * (bufferSize + 1));
    int *array = malloc(sizeof(int) * (bufferSize + 1));
    while (read(fileDescriptor, &character, 1)) {
        if (character == ',' || character == '\n') {
            array[arrayIndex++] = atoi(buffer);
            bufferIndex = 0;
            fillNull(buffer, bufferSize);
            continue;
        }
        buffer[bufferIndex++] = character;
    }

    close(fileDescriptor);

    for (int outer = 0; outer < arrayIndex - 1; outer++) {
        for (int inner = outer + 1; inner < arrayIndex; inner++) {
            if (array[outer] > array[inner]) {
                temp = array[outer];
                array[outer] = array[inner];
                array[inner] = temp;
            }
        }
    }

    fileDescriptor = open("text", O_WRONLY | O_TRUNC);

    for (bufferIndex = 0; bufferIndex < arrayIndex; bufferIndex++) {
        fillNull(buffer, bufferSize);
        sprintf(buffer, "%d", array[bufferIndex]);
        write(fileDescriptor, buffer, strlen(buffer));
        if (bufferIndex < arrayIndex - 1) {
            write(fileDescriptor, ",", 1);
        }
    }

    write(fileDescriptor, "\n", 1);

    free(buffer);
    free(array);
    close(fileDescriptor);
}

int main() {
    readAndSortNumbers();
    return 0;
}

