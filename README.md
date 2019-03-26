# design_patterns
Design patterns in modern C++

1. Builder
- Motivation
  - Some objects are simple and can be created in a single constructor call
  - Other objects require a lot of ceremony to create
  - Having an object with 10 constructor arguments is not productive
  - Instead, opt for piecewise construction
  - Builder provides API for constructing an object step-by-step

"When piecewise object construction is complicated, provide an API for doing it succinctly"

  - builder
  - fluent builder
  - groovy builder
  - builder facet

### BuilderFacetsCode

You are asked to implement the Builder design pattern for rendering simple chunks of code.
Sample use of the builder you are asked to create:

```sh
auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
cout  << cb;
```

The expected output of the code is:

```sh
class Person
{
    string name;
    int age;
};
```
  - A builder is a separate component for building an object
  - Can either give a builder a constructor or return it via a static function
  - To make a builder fluent, return [this]
  - Different facets of an object can be built with different builders working in tandem via a base class

2. Factory
- Motivation
  - Object creation logic becomes too convoluted
  - Constructor is not descriptive
    - Name mandated by name of containing type
    - Cannot overload with same sets of arguments with different names
    - Can turn into 'optional parameter hell'
  - Object creation (non-piecewise, unlike Builder) can be outsourced to 
    - A separate function (Factory Method)
    - That may exist in a separate class (Factory)
    - Can create heirarchy of factories with Abstract Factory

"A component responsible solely for the wholesale (not piecewise) creationof objects."