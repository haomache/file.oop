#include <iostream>
using namespace std;
#include <fstream>
int main(){
    int n;
    cout<<"Nhap n: "; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cout<<"Nhap phan tu thu "<<i+1<<" : ";
        cin>>arr[i];
    }
    ofstream ofs;
    ifstream ifs;
    ofs.open("hao.txt",  ios::binary);
    ofs.write((char*)&n, sizeof(int));
    ofs.write((char*)&arr[0], n*sizeof(int));
    ofs.close();
    ifs.open("hao.txt", ios::binary);
    ifs.read((char*)&n, sizeof(int));
    int arr1[n];
    ifs.read((char*)&arr1, n*sizeof(int));
    for(int j=0; j<n-1; j++){
        for(int i=0; i<n-1; i++){
            if(arr1[i]>arr1[i+1]){
                int a=arr1[i];
                arr1[i]=arr1[i+1];
                arr1[i+1]=a;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr1[i]<<" ";
    }
    ifs.close();
    return 0;
}