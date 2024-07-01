#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 1024

float calculate(float num1, float num2, char* operation) {
    if (strcmp(operation, "add") == 0)
        return num1 + num2;
    else if (strcmp(operation, "subtract") == 0)
        return num1 - num2;
    else if (strcmp(operation, "multiply") == 0)
        return num1 * num2;
    else if (strcmp(operation, "divide") == 0) {
        if (num2 == 0)
            return -1; // Cannot divide by zero
        return num1 / num2;
    }
    else if (strcmp(operation, "modulus") == 0)
        return (int)num1 % (int)num2;
    else
        return -2; // Invalid operation
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;
    char buffer[BUFFER_SIZE];
    float num1, num2, result;
    char operation[20];

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        len = sizeof(cliaddr);
        int n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0';
        
        sscanf(buffer, "%f,%f,%s", &num1, &num2, operation);

        result = calculate(num1, num2, operation);
        sprintf(buffer, "%.2f", result);

        sendto(sockfd, (const char *)buffer, strlen(buffer), 0, (const struct sockaddr *)&cliaddr, len);
    }

    close(sockfd);
    return 0;
}
