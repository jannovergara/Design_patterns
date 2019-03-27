#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Person
{
  int id;
  string name;
};

class PersonFactory
{
  int id{ 0 };
public:
  Person create_person(const string& name)
  {
    return { id++, name };
  }
};

int main()
{
    PersonFactory pf;
    Person p;
    p = pf.create_person("Paul");
    cout << p.id << " " << p.name << endl;
    p = pf.create_person("John");
    cout << p.id << " " << p.name << endl;

    return 0;
}