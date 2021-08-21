#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char FirstNum[100];
    scanf("%s", FirstNum);
    char Plus[20];
    scanf("%s", Plus);
    char SecondNum[100];
    scanf("%s", SecondNum);
    char Equal[20];
    scanf("%s", Equal);
    char Output[100];
    scanf("%s", Output);

    int Result;
    char CastedResult[20];
    int Inx1;
    int Inx2 = 20;

    if(strstr(FirstNum, "#") != NULL){
        Result = atoi(Output) - atoi(SecondNum);
        snprintf(CastedResult, sizeof(CastedResult), "%d", Result);
        //Check Suffix
        for(int i = 0; FirstNum[i] != '#' && i < strlen(CastedResult); i++){
            if(CastedResult[i] != FirstNum[i])
                {
                    printf("%s", "-1");
                    return -1;
                }
            Inx1 = i;
        }
        //Check Prefix
        for(int i = 0; FirstNum[strlen(FirstNum) - i - 1] != '#' && i < strlen(CastedResult); i++){
            if(CastedResult[strlen(CastedResult) - i - 1] != FirstNum[strlen(FirstNum) - i - 1])
                {
                    printf("%s", "-1");
                    return -1;
                }
            Inx2 = strlen(CastedResult) - i - 1;
        }
        if(Inx1 >= Inx2)
            {
                    printf("%s", "-1");
                    return -1;
                }
        printf("%s ", CastedResult);
        printf("%s ", Plus);
        printf("%s ", SecondNum);
        printf("%s ", Equal);
        printf("%s \n", Output);
    }
    else if(strstr(SecondNum, "#") != NULL){
        Result = atoi(Output) - atoi(FirstNum);
        snprintf(CastedResult, sizeof(CastedResult), "%d", Result);
        //Check Suffix
        for(int i = 0; SecondNum[i] != '#' && i < strlen(CastedResult); i++){
            if(CastedResult[i] != SecondNum[i])
                {
                    printf("%s", "-1");
                    return -1;
                }
            Inx1 = i;
        }
        //Check Prefix
        for(int i = 0; SecondNum[strlen(SecondNum) - i - 1] != '#' && i < strlen(CastedResult); i++){
            if(CastedResult[strlen(CastedResult) - i - 1] != SecondNum[strlen(SecondNum) - i - 1])
                {
                    printf("%s", "-1");
                    return -1;
                }
            Inx2 = strlen(CastedResult) - i - 1;
        }
        if(Inx1 >= Inx2)
            {
                    printf("%s", "-1");
                    return -1;
                }
        printf("%s ", FirstNum);
        printf("%s ", Plus);
        printf("%s ", CastedResult);
        printf("%s ", Equal);
        printf("%s \n", Output);
    }
    else if(strstr(Output, "#") != NULL){
        Result = atoi(FirstNum) + atoi(SecondNum);
        snprintf(CastedResult, sizeof(CastedResult), "%d", Result);
        //Check Suffix
        for(int i = 0; Output[i] != '#' && i < strlen(CastedResult); i++){
            if(CastedResult[i] != Output[i])
                {
                    printf("%s", "-1");
                    return -1;
                }
            Inx1 = i;
        }
        //Check Prefix
        for(int i = 0; Output[strlen(Output) - i - 1] != '#' && i < strlen(CastedResult); i++){
            if(CastedResult[strlen(CastedResult) - i - 1] != Output[strlen(Output) - i - 1])
                {
                    printf("%s", "-1");
                    return -1;
                }
            Inx2 = strlen(CastedResult) - i - 1;
        }
        if(Inx1 >= Inx2)
            {
                    printf("%s", "-1");
                    return -1;
                }
        printf("%s ", FirstNum);
        printf("%s ", Plus);
        printf("%s ", SecondNum);
        printf("%s ", Equal);
        printf("%s \n", CastedResult);
    }

   

    return 0;
}