#define MAX 0XA
#include <stdio.h>
#include <string.h>

struct Network_ID{
    int a;
    int b;
    int c;
};
struct IP_Address{
    struct Network_ID NETWORK_ID;
    int HOST_ID; 
};
struct customer_data{
    char name[20];
    char contact_number[12];
    struct IP_Address IP_ADDRESS;
};
typedef struct cell{
    int validEntry;
    struct customer_data DATA[MAX];
}CALLER_LIST;


int main()
{
    CALLER_LIST c = {5, {"Kirsty", "09112223344", 192,168,187,101,
                         "Victor", "09556667788", 192,168,187,102,
                         "Noelle", "09334445566", 192,168,187,103,
                         "Joachim","09221114422", 192,168,187,104,
                         "Euden",  "09889992244", 192,168,187,105,
                        }
                    };

        FILE *fp;
        fp = fopen("file.txt", "w+");

        if(fp == NULL){
            printf("File can't be detected");
        }else{
            int i;
            struct customer_data buffer[MAX];

            fwrite(c.DATA, sizeof(struct customer_data), c.validEntry, fp);
            rewind(fp);
            fread(buffer, sizeof(struct customer_data), c.validEntry, fp);

            for (i = 0; i < c.validEntry; i++){
                printf("%s\n", buffer[i].name);
                printf("%s\n", buffer[i].contact_number);
                printf("%d.%d.%d.%d\n\n", buffer[i].IP_ADDRESS.NETWORK_ID.a, buffer[i].IP_ADDRESS.NETWORK_ID.b, buffer[i].IP_ADDRESS.NETWORK_ID.c, buffer[i].IP_ADDRESS.HOST_ID);
            }
        }

    fclose(fp);
        }