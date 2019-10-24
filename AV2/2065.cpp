#include <iostream>
#include <list>
#include <queue>

using namespace std;

typedef struct{
    int time, clockReleased;
    bool free;
} EMPLOYEE;

typedef struct{
    int num_products;
} CLIENT;

int main(){
	CLIENT client;
	EMPLOYEE employee;
	
	queue<CLIENT> queueClients;
	list<EMPLOYEE> listEmployees;
	list<EMPLOYEE>::iterator it;
    int num_clients, num_employees, clock = 0, num_busy_employees = 0;
    cin >> num_employees >> num_clients;
    if(num_employees >= 1 && num_employees <= num_clients && num_clients <= 10000){
        for(int i = 0; i < num_employees; i++){
			cin >> employee.time;
			if(employee.time >= 1 && employee.time <= 100){
				employee.free = true;
				employee.clockReleased = 0;
				listEmployees.push_back(employee);
			}
		}
		for(int i = 0; i < num_clients; i++){
			cin >> client.num_products;
			if(client.num_products >= 1 && client.num_products <= 100)
			queueClients.push(client);
		}
		//faz a verificacao a cada segundo que passa ate todos os funcionarios ficarem livres
		while(true){
			for(it = listEmployees.begin(); it != listEmployees.end(); it++){
				employee = listEmployees.back();
				if(it->free){
					it->free = false;
					num_busy_employees++;
					//armazena na variavel a hora que o funcionario sera liberado
					it->clockReleased = clock + (queueClients.back().num_products * it->time);
					queueClients.pop();
				}
				if(clock >= it->clockReleased){
					it->free = true;
					num_busy_employees--;
				} 
			}
			clock++;
			if(num_busy_employees == 0 && queueClients.size() == 0) break;
		}
		cout << clock << endl;
    }
    
    
	return 0;
}