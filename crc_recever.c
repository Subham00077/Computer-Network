#include<stdio.h>

int main() {
    int m1[20], d[10], rem1[10], i, j, k, len, divlen;

    printf("\n Enter the length of divisor\n");
    scanf("%d", &divlen);
    printf("\n Enter the divisor:\n");
    for(i = 0; i < divlen; i++) {
        scanf("%d", &d[i]);
    }

    printf("\n Enter the length of received data (data + CRC)\n");
    scanf("%d", &len);
    printf("\n Enter the received data:\n");
    for(i = 0; i < len; i++) {
        scanf("%d", &m1[i]);
    }

    for(i = 0; i < len - (divlen - 1); i++) {
        if(m1[i] == 1) {
            for(j = 0; j < divlen; j++) {
                rem1[j] = (m1[i + j] == d[j]) ? 0 : 1;
            }
            for(k = 0; k < divlen; k++) {
                m1[i + k] = rem1[k];
            }
        } else {
            for(k = 0; k < divlen; k++) {
                rem1[k] = m1[i + k];
            }
        }
    }

    printf("\n CRC = ");
    int error = 0;
    for(i = 1; i < divlen; i++) {
        printf("%d", rem1[i]);
        if(rem1[i] != 0) error = 1;
    }

    if(error == 0) {
        printf("\n No error detected.\n");
    } else {
        printf("\n Error detected in received data.\n");
    }

    return 0;
}
