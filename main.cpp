#include <bits/stdc++.h>
using namespace std;

int* cr, n;

void print(){
    for(int i=0;i<n;i++)
        cout<<cr[i]<<' ';
    cout<<endl;
}

void swap_area(int m, int M){ // m,M compresi tra 0 e n
    assert(m>=0 && m<n-1);
    assert(M>=1 && m<n);
    for(int i=0;i<(M-m+1)/2;i++){
        swap(cr[m+i],cr[M-i]);
    }
}

int index_min_error(){ // return di numero compreso da 0 a n
    for(int i=0;i<n;i++)
        if (i+1!=cr[i]) return i;
    return n;
}

int index_of_num(int num){
    assert(num>0 && num<=n);
    for(int i=0;i<n;i++)
        if (cr[i]==num) return i;
    return n;
}

void test(){
    cout<<endl;
    print();
    int m=index_min_error();
    while(m!=n){
        int im=index_of_num(m+1);
        swap_area(m,im);
        print();
        m=index_min_error();
    }
}

int main(){
    cin>>n;
    cr = new int[n];
    for(int i=0;i<n;i++)
        cin>>cr[i];
    test();
    return 0;
}
