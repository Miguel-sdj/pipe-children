#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define QTD_MESSAGES 1

int main() {
    int pipeFileDescriptors[2];
    int returnStatus;
    char writeMessages[QTD_MESSAGES][40] = {"Primeira mensagem"};
    char readMessages[40];
    memset(readMessages, '\0', sizeof(char) * 40);

    returnStatus = pipe(pipeFileDescriptors);

    if (returnStatus == -1) {
        printf("Error when create pipe\n");
        return 1;
    }

    int children = fork();

    if (children != 0){
        for (int i = 0; i < QTD_MESSAGES; i++) {
            printf("Pai vai enviar: %d is %s\n", i, writeMessages[i]);
            write(pipeFileDescriptors[1], writeMessages[0], sizeof(char) * 40);
        }
    }
    else {
        for (int i = 0; i < QTD_MESSAGES; i++) {
            read(pipeFileDescriptors[0], readMessages, sizeof(char) * 40);
            printf("Filho vai ler: %d is %s\n", i, readMessages);
        }
    }
    

    return 0;
}