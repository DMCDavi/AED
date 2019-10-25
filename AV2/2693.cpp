#include <iostream>
#include <cstring>
#include <list>

using namespace std;

typedef struct
{
    string name;
    char region;
    int distance;
} STUDENT;

int main()
{
    STUDENT student;
    list<STUDENT> listStudent;
    int num_students;
    cin >> num_students;
    for (int i; i < num_students; i++)
    {
        cin >> student.name >> student.region >> student.distance;
        if(listStudent.empty()) listStudent.push_back(student);
        else{
            
        }
    }
    return 0;
}