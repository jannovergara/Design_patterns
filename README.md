# design_patterns
Design patterns in modern C++

### Builder
When construction gets a little bit too complicated
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
  - A builder is a separate component for building an object
  - Can either give a builder a constructor or return it via a static function
  - To make a builder fluent, return [this]
  - Different facets of an object can be built with different builders working in tandem via a base class

### Factories
Factory Method and Abstract Factory
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

### Prototype
When it's easier to copy an existing object to fully initialize a new one
- Motivation
  - Complicated objects (e.g. cars) aren't designed from scratch
    - They reiterate existing designs
  - An existing (partially or fully constructed) design is a Prototype
  - We make a copy (clone) the prototype and customize it
    - Requires 'deep copy' support
  - We make the cloning convenient (e.g. via a Factory)

"A partially or fully initialized object that you copy (clone) and make use of."

### Singleton
A design pattern everyone loves to hate... but is it really that bad?

"When discussing which patterns to drop, we found that we still love them all. (Not really - im in favor of dropping Singleton. Its use is almost always a design smell.)" - Erich Gamma
- Motivation
  - For some components it only makes sense to have one in the system
    - Database repository
    - Object factory
  - E.g. constructor call is expensive
    - We only do it once
    - We provide everyone with the same instance
  - Want to prevent anyone creating additional copies
  - Need to take care of lazy instantiation and thread safety

"A component which is instantiated only once."

### Adapter
Getting the interface you want from the interface you have
Power adapter
  - Electrical devices have different power (interface) requirements
    - Voltage (5V, 220V)
    - Socket/plug type (Europe, UK, USA)
  - We cannot modify our gadgets to support every possible interface
    - Some suport possible (e.g. 12/220 V)
  - Thus we use a special device (an adapter) to give us the interfacve we requrie from the interface we have

"A construct which adapts an existing interface X to conform to the required interface Y."

### Bridge
Connecting components together through abstractions
- Motivation
  - Bridge precent a 'Cartesian product' complexity explosion
  - Example:
    - Base class ThreadScheduler
    - Can be preemptive or cooperative
    - Can run on Windows or Unix
    - End up with a 2x2 scenarion: WindowsPTS, UnixPTS, WindowsCTS, UnixCTS
  - Bridge pattern avoid the entity explosion 

"A mechanism that decouples an interface (hierarchy) from an implementation (hierarchy)."
