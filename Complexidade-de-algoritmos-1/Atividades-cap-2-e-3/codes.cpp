#include <iostream>
#include <vector>
#include <cmath>
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

vector<int> selection_sort(vector<int> A){
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

int binary_search(vector<int>& A, int p, int r, int value){
    if(p <= r){                                                 
        int middle = ceil(p + ((r - p) / 2));                   
        if(A[middle] == value){                                 
            return middle;
        }else if(A[middle] > value){
            return binary_search(A, p, middle - 1, value);
        }else {
            return binary_search(A, middle + 1, r, value);
        }
    }else{
        return -1;
    }
}

int binary_search_aux_insertion_sort(vector<int>& A, int p, int r, int inserting){
    if(p <= r){
        int middle = floor(((r - p) / 2) + p);
        if(A[middle] >= inserting){
            return binary_search_aux_insertion_sort(A, p, middle - 1, inserting);
        }else {
            return binary_search_aux_insertion_sort(A, middle + 1, r, inserting);
        }
    }else{
        return p;
    }
}

vector<int> insertion_with_binary(vector<int> A){
    for(int i = 1; i < A.size(); i++){
        int key = A[i]; // Carta que estou inserindo agora
        int j = i - 1; // Posição que indica até onde o arranjo já está ordernado

        int index = binary_search_aux_insertion_sort(A, 0, j, key); // Encontrar o index a ser inserido o i-ésimo elemento

        for(int k = j; k >= index; k--){ // For para fazer o shift depois de encontrar o index
            A[k+1] = A[k];
        }
        A[index] = key;
    }
    return A;
}

void merge(vector<int>& A, int p, int mid, int r){
    int n_1 = mid - p + 1;
    int n_2 = r - mid;
    vector<int> aux_1;
    vector<int> aux_2;
    for(int i = 0; i < n_1; i++){
        aux_1.push_back(A[p + i]);
    }
    for(int k = 0; k < n_2; k++){
        aux_2.push_back(A[mid + 1 + k]);
    }
    int i = 0; // Itera em aux_1
    int k = 0; // Itera em aux_2
    int a = p; // Itera em A
    while(i < n_1 && k < n_2){
        if(aux_1[i] <= aux_2[k]){
            A[a] = aux_1[i];
            i++;
        }else{
            A[a] = aux_2[k];
            k++;
        }
        a++;
    }
    while(i < n_1){
        A[a] = aux_1[i];
        i++;
        a++;
    }
    while(k < n_2){
        A[a] = aux_2[k];
        k++;
        a++;
    }
}

void merge_sort(vector<int>& A, int p, int r){
    if(p < r){
        int middle = p + ((r - p) / 2);
        merge_sort(A, p, middle);
        merge_sort(A, middle + 1, r);
        merge(A, p, middle, r);
    }
}

bool find_pair(vector<int> A, int value){
    merge_sort(A, 0, A.size() - 1); // Ordena em O(n lg n)

    // a + b = x
    int i = 0; // Iterador para o inicio
    int k = A.size() - 1; // Iterador para o final

    while(i < k){
        if(A[i] + A[k] == value){
            return true;
        }else if(A[i] + A[k] < value){
            i = i + 1;
        }else if(A[i] + A[k] > value){
            k = k - 1;
        }
    }

    return false;
}


int main(){
    vector<int> A = {5,4,3,2,1,0};
    string res = find_pair(A, 9) == true ? "True" : "False";
    cout << res << endl;
} 












