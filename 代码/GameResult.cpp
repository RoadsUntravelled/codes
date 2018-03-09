/*************************************************************************
	> File Name: GameResult.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年01月10日 星期三 21时52分48秒
 ************************************************************************/

#include<iostream>
using namespace std;
enum GameResult{WIN,LOSE,TIE,CANCEL};
int main(){
    GameResult result;
    GameResult omit=CANCEL;
    cout<<result<<endl;
    for(int count=WIN;count<=CANCEL;count++){
        result=GameResult(count);
        cout<<result;
        if(result==omit)
            cout<<"The game was cancelled"<<endl;
        else{
            cout<<"The game was played";
            if(result==WIN)
                cout<<"and we won!";
            if(result==LOSE)
                cout<<"and we lost";
            cout<<endl;
        }
    }
    return 0;
}
