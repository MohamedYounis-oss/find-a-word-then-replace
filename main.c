#include <stdio.h>
#include <stdlib.h>


int find_word_in_string(char* str, char*word, int size){

    int i, j = 0;
    char flag = 0;

    for ( i=0; str[i]; i++){

        if (i==0 || str[i-1]==' ' || flag){

            if(j<size && str[i] == word[j]) {

                j++;
                flag = 1;
                if (j==size && (str[i+1]==' ' || str[i+1] == '\0')) return (i-size+1);

            } else {
                j = 0;
                flag = 0;
            }
        }
    }

    return -1;
}



char* find_replace_word(char* str, char* find, char* replace){

    int str_len = string_len(str);
    int find_len = string_len(find);
    int replace_len = string_len(replace);

    char* result;
    int result_len;

    int find_index = find_word_in_string(str, find, find_len);

    if (find_index < 0){

        return str;

    } else {

        result_len = str_len-find_len+replace_len;

        result = (char*)malloc(result_len*sizeof(char));

        char*p1, *p2, *p3;
        int x, i, j, k, n1, n2, n3;

        if (find_index==0){    // if find at the beginning of str

            p1 = replace;                     // first part of the result string
            n1 = replace_len;                // count
            i = 0;                           // start index

            p2 = str;                        // second part of the result string
            n2 = str_len - find_len + 1;
            j = find_len;

            n3 = 0;                         // there is no third part

        } else if (find_index == str_len-find_len) {  // if find at the end of str


            p1 = str;
            n1 = str_len - find_len;
            i = 0;

            p2 = replace;
            n2 = replace_len;
            j = 0;

            n3 = 0;

        } else {  // if find in the middle of str

            p1 = str ;
            n1 = find_index;
            i = 0;

            p2 = replace;
            n2 = replace_len;
            j = 0;

            p3 = str;
            n3 = str_len-(find_index+find_len);
            k = find_index + find_len;

        }

        for (x=0; x<result_len; x++){

            if (n1>0){

                result[x] = p1[i];
                i++;
                n1--;

            } else if (n2>0){

                result[x] = p2[j];
                j++;
                n2--;

            } else if (n3>0){

                result[x] = p3[k];
                k++;
                n3--;

            }

        }

        result[x] = '\0';
    }

    return result;


}


int main()
{

    char str[100];
    char find[100];
    char replace[100];



    while (1) {

        printf(">> Enter the main string : \n");
        string_scan(str);

        printf(">> find : ");
        string_scan(find);

        printf(">> replace it with : ");
        string_scan(replace);

        char* result = find_replace_word(str, find, replace);

        printf(">> ");
        string_print(result);

        printf("============================\n");

    }


    return 0;
}
