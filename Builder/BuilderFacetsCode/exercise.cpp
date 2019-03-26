#include <string>
#include <vector>
#include <ostream>
#include <iostream>
using namespace std;

struct Fields
{
    string name;
    string type;

    friend ostream& operator<<(ostream& os, const Fields& obj)
    {
        return os << obj.type << " " << obj.name << ";";
    }
};

struct Class
{
    string classname;
    vector<Fields> fields;

    friend ostream& operator<<(ostream& os, const Class& obj)
    {
        os  << "class " << obj.classname << "\n"
            << "{\n";
        for(auto && field : obj.fields)
        {
            os << "  " << field << "\n";
        }
        os  << "};\n";

        return os;
        
    }
};

class CodeBuilder
{
    Class classname;
public:
    CodeBuilder(const string& class_name) 
    {
        classname.classname = class_name;
    }

    CodeBuilder& add_field(const string& name, const string& type)
    {
        classname.fields.emplace_back(Fields{ name, type });
        return *this;
    }

    friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
    {
        return os << obj.classname;
    }
};

int main()
{
    auto cb = CodeBuilder{"Person"}.add_field("age", "int").add_field("name", "string");
    cout << cb;
    return 0;
}