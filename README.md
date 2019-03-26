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

##### BuilderFacetsCode

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