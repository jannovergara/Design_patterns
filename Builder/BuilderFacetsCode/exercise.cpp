#include <string>
#include <ostream>
using namespace std;

class CodeBuilder
{
public:
  CodeBuilder(const string& class_name)
  {
      // todo
  }

  CodeBuilder& add_field(const string& name, const string& type)
  {
    // todo
  }

  friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
  {
    // todo
  }
};