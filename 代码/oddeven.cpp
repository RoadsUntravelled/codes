#include<iostream>
using namespace std;
int main(){
    char c;
    while(true)
    {
        char a='4';//a=0,0为奇数，a=1,1为奇数，a=3,都为奇数，a=4,都为偶数
        while((c=getchar())!='\n'){
            if(a=='4'){
                if(c=='1')
                    a='1';//
                else
                    a='0';
            }
            else if(a=='3'){
                if(c=='1')
                    a='0';
                else 
                    a='1';
            }
            else if(a=='0'){
                if(c=='1')
                    a='3';
                else 
                    a='4';
            }
            else if(a=='1'){
                if(c=='1')
                    a='4';
                else a='3';
            }
            //cout<<c<<":"<<a<<" "<<endl;
       }
       /* printf("%c",a);*/
        if(a=='3')
            printf("1\n");
        else printf("0\n");
    }
    return 0;
}
