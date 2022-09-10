Builder Pattern

- structural design pattern
- aims to connect components through an abstraction
- prevent cartesion product complexity

Say we want to have a thread scheduler class and the scheduler can be preemtive or cooperative. Also the scheduler can run on Unix or on Windows. Instead of creating the full inhertance relationship we can combine it with aggregation.
