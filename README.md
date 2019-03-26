# design_patterns
Design patterns in modern C++

1. Builder
Motivation
- Some objects are simple and can be created in a single constructor call
- Other objects require a lot of ceremony to create
- Having an object with 10 constructor arguments is not productive
- Instead, opt for piecewise construction
- Builder provides API for constructing an object step-by-step

"When piecewise object construction is complicated, provide an API for doing it succinctly"

* builder
* fluent builder
* groovy builder
* builder facet

///
BuilderFacetsCode
///
You are asked to 