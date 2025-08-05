#ifndef STRING_FUNCTION_H
#define STRING_FUNCTION_H



#include<iostream>
using namespace std;

class string_function{

    public:

int my_strlen(const char* s){
int count = 0;
while(s[count]!='\0')
count++;

return count;
}

int my_strcmp(char* s1,char* s2){

    int i=0;
    while(s1[i]!='\0'){
        if(s1[i]!=s2[i])
        return -1;
        i++;
    }
    if(s1[i]=='\0' && s2[i]=='\0')
    return 1;
    else return -1;
}
char* my_strcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    cout<<"hello";
    dest[i] = '\0';  
    return dest;
}
char* my_strcat(char* dest, char* src){
    cout<<"come here";
    int i = 0, j = 0;

    while (dest[i] != '\0') {
        i++;
        cout<<dest[i];
    }
    while (src[j] != '\0') {
        dest[i++] = src[j++];
    }
    dest[i] = '\0';

    return dest;
}

int my_strchr(const char* str,char c){
    int i=0;
    while(str[i]!='\0'){
        if(str[i]==c)
        return 1;

        i++;
        }
        return -1;
    }

    char* my_removeSpaces(char* str){
        int i=0,j=0;
        while(str[i]!='\0'){
            if(str[i]!=' ' || (str[i]==' ' && str[i+1]!=' '))
            str[j++]=str[i];
            i++;
            }
            str[j] = '\0';

            return str;
    }


    int my_strstr(char* haystack,char *needle){
       
        int i=0,j=0;
        while(haystack[i]!='\0'){   

            char hay = haystack[i];
            char need = needle[j];

            if(hay>='A' && hay<='Z')  hay = hay+32;
            if(need>='A' && need<='Z')  need = need+32;

            if(hay == need){
                int k = i+1;
                j++;
                int flag = 1;
                while(needle[j] != '\0'){
                    int hays = haystack[k];
                    int needs = needle[j];
                    if(hays>='A' && hays<='Z') hays = hays+32;
                    if(needs>='A' && needs<='Z') needs = needs+32;

                    if(hays != needs ){
                        flag = 0;
                        break;
                    }
                    else{
                        k++;
                        j++;
                    }
                }
                if(flag == 1)
                    return 1;
                else
                    j=0;
            }
            i++;
        }
        return -1;
    }


    char* my_reverse(char* str){
        int i=0,j=my_strlen(str)-1;
        while(i<j){
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;
            j--;
            }
            return str;
    }

    void my_palindrome(char* str){
        int i=0;
        int j = my_strlen(str)-1;

        while(i<j){
            if(str[i]!=str[j]){
                cout<<endl<<"Not palindrome";
                return ;
            }
            i++;
            j--;
        }
        cout<<endl<<"Palindrome";
    }

    int my_words(char* str){
        int count = 0;
        int i = 0;
        if(str[i] != ' ')
        count++;
        while(str[i] != '\0'){
            if(str[i] == ' ' && str[i+1] != ' ')
            count++;

            i++;
        }

        return count;
    }

    // int mostWords(char* str)
    // {
    //     int max = 0;
    //     char* temp = str[0];
    //     for(int i=1;i<strlen(str);i++)
    //     {
    //         if(str[i] == 'and' || str[i] == 'or' || str[i] == 'is' || str[i] == 'of')
    //         continue;
    //         else if(count == 0 && str[i]!=temp){
    //             count = 1;
    //             temp = str[i];
    //         }
    //         else if(str[i] == temp)
    //         count++;
    //         else
    //         count--;
    //     }
    //     return temp;
    // }

    void my_strtok(char* str){
        int i=0;
        char temp[100];
        int j=0;
        while(str[i]!='\0'){
           while(str[i]!=','){
            temp[j++]=str[i++];
           }
           cout<<"["<<temp<<"]"<<endl;
           for(int k=0;k<=j;k++){
            temp[k] = NULL;
           }
           j=0;
           i++;
        }
    }

};

    #endif






    // int main(){

        
    //     char spaces[] = " hello         u       are great        iij kkk     djd   djnd   eklmnwk   ";

    //     char* space;

    //     space = removeSpaces(spaces);

    //     cout<<"After removing the spaces : "<<space;
    //     char src[] = "Hello World";
    //     char str[] = "Hello World";
    //     int len = my_strlen(src);
    //     cout<<endl<<"Length : "<<len;

    //     int comp = my_strcmp(src,str);
    //     if(comp == 1)
    //     cout<<endl<<"Equal";
    //     else
    //     cout<<endl<<"Not equal";
       
    //     char copy[20];
    //     char* cpy = my_strcpy(str,copy);
    //     cout<<endl<<"Copied string : "<<cpy;

    //     // char* append = strcat(src,str);
    //     // cout<<endl<<"Appended string : "<<append;
       
    //     char ch = 'x';
    //     int presence = my_strchr(str,ch);

    //     if(presence == 1)
    //     cout<<endl<<"Character found";
    //     else
    //     cout<<endl<<"Character not found";


    //   int pos =  my_strstr("HelloWorld", "world");   
    //   if(pos == 1)
    //     cout<<endl<<"Substring Found";
    //     else
    //     cout<<endl<<"substring not found";
    //    pos =  strstr("Tanveer", "TAN");      
    //   if(pos == 1)
    //     cout<<endl<<"Substring Found";
    //     else
    //     cout<<endl<<"substring not found";
    //    pos =  strstr("Code", "xyz");   
    //   if(pos == 1)
    //     cout<<endl<<"Substring Found";
    //     else
    //     cout<<endl<<"substring not found";        
    //    pos =  strstr("anything", "");       

    //     if(pos == 1)
    //     cout<<endl<<"Substring Found";
    //     else
    //     cout<<endl<<"substring not found";

    //     char* reversed;
    //     reversed = my_reverse(str);
          
    //     cout<<endl<<"Reversed String : "<<reversed;

    //     char palin[] = "mussum";
    //     my_palindrome(palin);

    //     char word[] = "hello world u are great";
    //     int total = words(word);
    //     cout<<endl<<"Total words : "<<total;

    //     char my_strtc[] = "hekko,my,name,is,tanveer,,,yeahh";
    //     strtok(strtc);


    // }

    




