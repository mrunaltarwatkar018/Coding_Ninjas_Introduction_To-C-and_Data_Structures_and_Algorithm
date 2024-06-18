#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int i=1;
    int k=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<k;
            k++;
            j++;
        }
        cout<<endl;
        i++;
        
        
    }
}





/*
        OUTPUT :
                6
                1
                23
                456
                78910
                1112131415
                161718192021

*/