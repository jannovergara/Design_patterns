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
  - To make a builder fluent, return **this**
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

"A component responsible solely for the wholesale (not piecewise) creation of objects."

##### PersonFactory


### Prototype
When it's easier to copy an existing object to fully initialize a new one
Deep-copy
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

### Composite
Treating individual and aggreagate objects uniformly.
- Motivation
  - Objects use other objects' field/properties/members through inheritance and composition
  - Composition lets us make compound objects
    - E.g. a mathermatical expression composed of simple expressions; or
    - A grouping of shapes that consists of several shapes
  - Composite design pattern is used to treat both single (scalar) and composite objects uniformly
    - I.e. Foo and Collection<Foo> have common APIs

"A mechanism for treating individual (scalar) objects and compositions of objects in a uniform manner."

### Decorator
Adding behavior without altering the class itself.
- Motivation
  - Want to augment an object with additional functionality
  - Do not want to rewrite or alter existing code (OCP)
  - Want to keep new functionality separate (SRP)
  - Need to be able to interact with existing structures
  - Two options:
    - Aggregate the decorated object
    - inherit from the decorated object

"Facilitates the addition of behaviors to individual objects."

### Façade
Exposing several components through a single interface
- Motivation
  - Balancing complexity and presentation/usability
  - Typical home
    - Many subsystems (electrical, sanitation)
    - Complex internal structure (e.g. floor layers)
    - Ens user is not exposed to internals
  - Same with software
    - many systems working to provide flexibility, but...
    - API consumers want it to 'just work'

"Provides a simple, easy to understand/user interface over a large and sophisticated body of code."

### Flyweight
Space optimization!
- Motivation
  - Avoid redundancy when storing data
  - E.g. MMORPG
    - Plenty of users with identical first/last names
    - No sense in storing same first/last name over and over again
    - Store a list of names and pointers to them
  - E.g. bold or italic text in the console
    - Don't want each character to have a formatting character
    - Operate on ranges (e.g. line number, start/end positions)

"A space optimization technique that lets us use less memory by storing externally the data associated with similar objects."

### Proxy
An interface for accessing a particular resource.
- Motivation
  - You are calling foo.bar()
  - This assumes that foo is in the same process as bar()
  - What if, later on, you want to put all Foo-related operations into a separate process
    - Can you avoid changing you code?
  - Proxy to the rescue!
    - Same interface, entirely different behavior
  - This is called a communication proxy
    - Other types: logging, virtual, guarding, ...

"A class that functions as an interface to a particular resource. That resource may be remote, expensive to construct, or may require logging or some other added functionality."

### Chain of responsibility
Sequence of handlers processing an event one after another.
- Motivation
  - Unethical behavior by an employee; who takes the blame?
    - Employee
    - Manager
    - CEO
  - You click a graphical element on a form
    - Button handles it, stops further processing
    - Underlying group box
    - Underlying window
  - CCG computer game
    - Creature has attack and defense values
    - Those can be boosted by other cards

"A chain of components who all get a chance to process a command or a query, optionally having default processing implementation and an ability to terminate the processing chain."

### Command
YOU SHALL NOT PASS!
- Motivation
  - Ordinary C++ statements are perishable
    - Cannot undo a field/property assignment
    - Cannot directly serialize a sequence of actions (calls)
  - Want an object that represents an operation
    - X should change its field Y to the value Z
    - X should do W()
  - Uses: GUI commands, multi-level undo/redo, macro recording and more!

"An object which represents an instruction to perform a particular action. Contains all the information necessary for the action to be taken."

##### Command Query Separation
- Command = asking for an action or change (e.g. please set your attack to 2).
- Query = asking for information (e.g. please give me your attack value).
- CQS = having separate means of sending commands and queries
- In GoF context, both commands and queries are represented with the Command design pattern.

### Interpreter
Interpreters are all around us. Even now, in this very room.

- Textual input needs to be processed
  - E.g. turned into an OOP structure
- Some examples
  - Programming language compilers, interpreters and IDEs
  - HTML, XML and similar
  - Numeric expressions (3+4/5)
  - Regular expressions
- Turning strings into OOP based structures in a complicated process

"A component that process structured text data. Does so by turning it into separate lexing tokens (lexing) and the interpreting sequences of said tokens (parsing)."

### Iterator
How traversal of data structures happens and who makes it happen.
- Motivation
  - Iteration (traversal) is a core functionality of various data structure
  - An iterator is a class that facilitates the traversal
    - Keeps a reference to the current element
    - Knows how to move to a different element
  - Can be used implicitly
    - Range-based for
    - Coroutines

"An object that facilitates the traversal of a data structure."

### Mediator
Facilitates communication between components
- Motivation
  - Components may go in and out of a system at any time
    - Chat room aprticipants
    - PLayers in an MMORPG
  - It makes no sense for them to have direct references to one another
    - Those references may go dead
  - Solution: have then all refer to some central component that facilitates communication

"A conponent that facilitates communication between other components wihtout them necessarily being aware of each other or having direct (reference) access to each other."

### Memento
Keep a memento of an object's state to return to that state
- Motivation
  - An object or system goes through changes
    - E.g. bank account gets deposits and withdrawals
  - There are different ways of navigating those changes
  - One way is to record every change (Command) and teach a command to 'undo' itself
  - Another is to simply save snapshots of the system.

"A token/handle representing the system state. Lets us roll back to the state when the token was generated. May or may not directly expose state information."

### Observer
Getting notification when things happen
- Motivation
  - We need to be informed when certain things happen
    - Object's field changes
    - Object does something
    - Some external event occurs
  - We want to listen to events and notified when they occur
  - Terminology:
    - event and subscriber
    - signal and slot (Boost, Qt, etc)

"An observer is an object that wishes to be informed about events happening in the system. The entity generating the events is an observable."

### State
Fun with Finite State Machines
- Motivation
  - Consider an ordinary telephone
  - What you do with it depends on the state of the phone/line
    - if it's ringing or you want to make a call, you can pick up
    - Phone must be off the hook to talk/make a call
    - If you try calling someone, and it's busy, you put the handset down
  - Changes in state can be explicit or in response to event (observer pattern)

"A pattern in which the object's behavior is determined by its state. An object trasistions from one state to another (something needs to trigger a transition).

A formalized construct which manages state and transitions is called a state machine."

### Strategy
System behavior partially specified at runtime.
- Motivation
  - Many algorithms can be decomposed into higher- and lower-level parts
  - Making tea can be decomposed into
    - The process of making a hot beverage (boil water, pour into cup); and
    - Tea-specific things (put teabag into water)
  - The high-level algorithm can then be reused for making coffee or hot chocolate
    - Supported by beverage-specific strategies

"Enables the exact behavior of a system to be selected either at run-time (dynamic) or compile-time (static).

Also known as a policy (esp. in the C++ world)."

### Template Method
A high-level blueprint for an algorithm to be completed by inheritors.
- Motivation
  - Algorithms can be decomposed into common parts + specifics
  - Strategy pattern does this thorugh composition
    - High-level algorithm uses an interface
    - Concrete implementations implement the interface
  - Template Method does the same thing through inheritance
    - Overall algorithm amkes use of abstract member
    - Inheritors override the abstract members
    - Parent template method invoked

  "Allows us to define the 'skeleton' of the algorithm, with concrete implementation defined in subclasses."

### Visitor
Typically a tool for structure traversal rather than anything else.
- Motivation
  - Need to define a new operation on an entire class heirarchy
    - E.g. make a document model printable to HTML/Markdown
  - Do not want to keep modifying every class in the heirarchy
  - Need access to the non-common aspects of classes in the heirarchy
    - Cannot put everything into a single interface
  - Create an external component to hanle rendering
    - But preferable avoid type checks

"A pattern where a component (visitor) is allowed to traverse the entire inheritance to traverse the entire inheritance hierarchy. Implemented by propagating as single visit() method throughout the entire hierarchy."