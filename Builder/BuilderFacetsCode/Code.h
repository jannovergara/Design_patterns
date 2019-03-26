#pragma once
#include <string>
#include <iostream>
#include <vector>

struct Fields
{
    string type,
    string name

};

class CodeBuilder;

class Code
{
protected: // can be accessed in derived classes
    string class_name;
    vector<Fields> fields;
public:
    Code() {}
    Code()
}