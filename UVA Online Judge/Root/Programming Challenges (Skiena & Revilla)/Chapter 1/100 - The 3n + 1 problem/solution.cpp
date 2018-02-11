/*
    11 February 2018 || 26 Jumadil Awwal 1439H
    -------------------------------------------

    100 - The 3n + 1 Problem
    1. Menghitung langkah fungsi 3n + 1.
    2. Menghitung banyaknya langkah maksimum dari suatu interval

    @Reyzeal
*/
#include <iostream>

using namespace std;

int count(int n){
    if(n == 1) return 1;
    if(n % 2 != 0) return count(3*n+1)+1;
    return count(n/2)+1;
}

int max(int i, int j){
    return i>j?i:j;
}

int cycle(int i,int j){
    if(j<i){
        return cycle(j,i);
    }
    if(i<j){
        return max(cycle(i+1,j),count(i));
    }
    return count(j);
}

int main(){
    int x,y;
    while(cin>>x>>y){
        cout<<x<<" "<<y<<" "<<cycle(x,y)<<endl;
    }
}
