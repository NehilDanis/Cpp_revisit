# C++ - Reviewing some content

In this repo, some basic C++ concept is implemented. This repo is for me to revisit some of the concepts from Modern C++, to design patterns. The examples in this repo are mostly from the Udemy courses [1](https://www.udemy.com/course/learn-advanced-c-programming/), and [2](https://www.udemy.com/course/patterns-cplusplus/).

# Usage
The project structure is as shown below.

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


