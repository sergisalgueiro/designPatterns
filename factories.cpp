#include <string>
using namespace std;

struct Person
{
  int id;
  string name;
};

class PersonFactory
{
    int index = 0;
public:
  Person create_person(const string& name)
  {
    Person person{index, name};
    index++;
    return person;
  }
};
