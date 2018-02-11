/*
    11 February 2018 || 26 Jumadil Awwal 1439H
    -------------------------------------------

    10189 - Minesweeper

    @Reyzeal
*/
#include <iostream>
#include <string.h>

using namespace std;

int normalize(char x){
    if(x>='1'&&x<='9')
        return x-'0';
    return 0;
}

char toChar(int x){
    return x+'0';
}

char filling(char x){
    return x=='*'?x:toChar(normalize(x)+1);
}

int main(){
    int x,y,iter=0;
    char z;
    bool start = false;
    while(cin>>x>>y){
        char data[x][y];
        for(int i=0;i<x;++i){
            for(int j=0;j<y;++j){
                data[i][j]='0';
            }
        }
        for(int i = 0; i < x;++i){
            for(int j = 0;j < y;++j){
                if( (cin>>z) && z=='*'){
                    data[i][j] = z;
                    if(i-1>=0){
                        data[i-1][j] = filling(data[i-1][j]);
                        if(j-1>=0)
                            data[i-1][j-1] = filling(data[i-1][j-1]);
                        if(j+1<y)
                            data[i-1][j+1] = filling(data[i-1][j+1]);
                    }
                    if(i+1<x){
                        data[i+1][j] = filling(data[i+1][j]);
                        if(j-1>=0)
                            data[i+1][j-1] = filling(data[i+1][j-1]);
                        if(j+1<y)
                            data[i+1][j+1] = filling(data[i+1][j+1]);
                    }
                    if(j-1>=0){
                        data[i][j-1] = filling(data[i][j-1]);
                    }
                    if(j+1<y){
                        data[i][j+1] = filling(data[i][j+1]);
                    }
                }
                else{
                    data[i][j] = toChar(normalize(data[i][j]));
                }
            }
        }
        if(x && y){
            if(start){
                cout<<endl;
            }
            cout<<"Field #"<<++iter<<":"<<endl;
            for(int i = 0; i < x;++i){
                for(int j = 0;j < y;++j){
                    cout<<data[i][j];
                }
                cout<<endl;
            }
        }
        start=true;
    }
}
