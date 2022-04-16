# C++ - Reviewing some content

In this repo, some basic C++ concept is implemented. This repo is for me to revisit some of the concepts from Modern C++, to design patterns with C++. The examples in this repo is mostly from the Udemy courses [1](https://www.udemy.com/course/learn-advanced-c-programming/), [2](https://www.udemy.com/course/patterns-cplusplus/) that I have watched. I am also planning to add some example from day to day coding challanges.

# Usage
The project structure is as shown below. There are multiple sub projects and each have their own CMakeLists. Each subproject will have their own executable.

```
Project
│   README.md
│   CMakeLists.txt
|   .gitignore
│
└───SubProject1
│    │
│    └───src
│    └───includes
|    CMakeLists.txt
└─── SubProject2 
│    │
│    └───src
│    └───includes
|    CMakeLists.txt
.
.
.
```
To be able to compile and use the project go to the project directory from your terminal and follow the instructructions below:
<br />
<br />
	`
  mkdir build && cd build
  `\
  `
  cmake .. -DCMAKE_INSTALL_PREFIX=..
  `\
  `
  make
  `\
  `
  make install
  `
<br />
<br />
The executables for each subproject will be generated in the bin folder in the project director. To run the executable go to bin directory and run the following command:
<br />
<br />
  `./<EXECUTABLE_NAME> 
  `



