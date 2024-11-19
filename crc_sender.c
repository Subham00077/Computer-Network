#include<stdio.h>

int main() {
    int m[20], p[20], d[10], i, j, k, len, rem[10], divlen;

    printf("\n Enter the length of divisor\n");
    scanf("%d", &divlen);
    printf("\n Enter the divisor:\n");
    for(i = 0; i < divlen; i++) {
        scanf("%d", &d[i]);
    }

    printf("\n Enter the length of data\n");
    scanf("%d", &len);
    printf("\n Enter the data:\n");
    for(i = 0; i < len; i++) {
        scanf("%d", &m[i]);
        p[i] = m[i];
    }

    for(i = len; i < len + (divlen - 1); i++) {
        m[i] = 0;
    }

    printf("\n The appended data is: ");
    for(i = 0; i < len + (divlen - 1); i++) {
        printf("%d", m[i]);
    }

    for(i = 0; i < len; i++) {
        if(m[i] == 1) {
            for(j = 0; j < divlen; j++) {
                rem[j] = (m[i + j] == d[j]) ? 0 : 1;
            }
            for(k = 0; k < divlen; k++) {
                m[i + k] = rem[k];
            }
        } else {
            for(k = 0; k < divlen; k++) {
                rem[k] = m[i + k];
            }
        }
    }

    printf("\n CRC = ");
    for(i = 1; i < divlen; i++) {
        printf("%d", rem[i]);
    }
    
	printf("\n The complete data + CRC is :");
	for(i=0;i<len;i++){
	printf("%d",p[i]);
	
	}
	
	for(i=0;i<divlen-1;i++){
	printf("%d",rem[i]);
	
	}

    return 0;
}
