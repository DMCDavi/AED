#include <iostream>

using namespace std;

typedef struct{
    int time;
    bool busy;
} EMPLOYEE;

typedef struct{
    int num_products;
} CLIENT;

int main(){
    int num_clients, num_employees;
    cin >> num_employees >> num_clients;
    if(num_employees >= 1 && num_employees <= 10000 && num_clients >= 1 && num_clients <= 10000){
        CLIENT clients[num_clients];
        EMPLOYEE employees[num_employees];
    }
    
    

}