#include <iostream>
#include <list>
#include <queue>

using namespace std;

typedef struct
{
	int time, clock_released;
	bool free;
} EMPLOYEE;

typedef struct
{
	int num_products;
} CLIENT;

int main()
{
	CLIENT client;
	EMPLOYEE employee;
	queue<CLIENT> queueClients;
	list<EMPLOYEE> listEmployees;
	list<EMPLOYEE>::iterator it;
	int num_clients, num_employees, clock = 0, num_busy_employees = 0;
	cin >> num_employees >> num_clients;
	if (num_employees >= 1 && num_employees <= 10000 && num_clients >= 1 && num_clients <= 10000)
	{
		for (int i = 0; i < num_employees; i++)
		{
			cin >> employee.time;
			//cria uma lista de funcionarios
			if (employee.time >= 1 && employee.time <= 100)
			{
				employee.free = true;
				employee.clock_released = 0;
				listEmployees.push_back(employee);
			}
		}
		for (int i = 0; i < num_clients; i++)
		{
			cin >> client.num_products;
			//cria uma fila de clientes
			if (client.num_products >= 1 && client.num_products <= 100)
				queueClients.push(client);
		}

		//faz a verificacao a cada segundo que passa ate todos os funcionarios ficarem livres e a fila acabar
		while (true)
		{
			num_busy_employees = 0;
			for (it = listEmployees.begin(); it != listEmployees.end(); it++)
			{
				employee = *it;
				//se o funcionario tiver livre e a fila nao estiver vazia, o cliente eh atendido por ele
				if (it->free && queueClients.size() != 0)
				{
					it->free = false;
					//armazena na variavel a hora que o funcionario sera liberado
					it->clock_released = clock + (queueClients.front().num_products * it->time);
					queueClients.pop();
				}
				//libera o funcionario caso ele tenha acabado de atender o cliente
				if (clock >= it->clock_released)
				{
					it->free = true;
				}
				//caso o funcionario nao esteja livre, a quantidade de funcionarios ocupados aumenta
				if (!it->free)
					num_busy_employees++;
			}
			//continua o tempo levando em consideracao que nenhum funcionario parou de trabalhar
			if (num_busy_employees != 0)
				clock++;
			//caso nenhum funcionario esteja trabalhando e a fila tenha acabado, a verificacao termina
			if (num_busy_employees == 0 && queueClients.size() == 0)
				break;
		}
		cout << clock << endl;
	}

	return 0;
}