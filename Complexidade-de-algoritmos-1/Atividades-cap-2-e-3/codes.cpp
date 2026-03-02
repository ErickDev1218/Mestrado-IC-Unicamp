#include <iostream>
#include <vector>
using namespace std;

int linear_search(vector<int> A, int v){
    int i = 0;
    while(i < A.size()){
        int chave = A[i];
        if(chave == v){
            return i;
        }
        i += 1;
    }
    
    return -1;
}

vector<int> binary_sum(vector<int> A, vector<int> B){
    int i = A.size();
    int carry = 0;
    vector<int> C (i+1);
    
    while(i >= 0){
        int k = i + 1;
        C[k] = A[i] + B[i] + carry;
        carry = C[k] / 2;
        C[k] = C[k] % 2;
        i--;
    }
    C[0] = carry;
    return C;
}

vector<int> insertion_sort(vector<int> A){
    for(int i = 0; i < A.size() - 1; i++){
        int min = i;
        
        for(int k = i + 1; k < A.size(); k++){
            if(A[k] < A[i]){
                min = k;
            }
        }
        
        // if(A[min] < A[i]){
            int aux = A[min];
            A[min] = A[i];
            A[i] = aux;
        // }
    }
    
    return A;
}

int main(){
    vector<int> A = {5,4,3,2,1,0};
    
    vector<int> res = insertion_sort(A);
    
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
} 












