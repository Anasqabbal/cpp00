# The Goal of Module00
- ex00 : creat a simple program that takes input as a argument and print it to the user in uppercase format

# what is OOP
objected oriented programming is approach that makes you view your program as objects instead a series of steps, it views it as a group of objects that have certain properties and can take certain actions

## New thing based on C

.<< : insertion opearator.\
.>> : extraction operator.

**<< >> :** in C you can use them to shift bits and in c++ you can use them for shift bits left and right and also this << as insertion operator to take the data from a stream and\
this operator >> to display data to a stream.

**:: scope resolution operator**

1. accesse a global var when there is a local var with the same name
2. to define a function outside a class
3. to access a class's static var.
4. in case of multiple inheritance 
5. for namespace

#### namespace 

namespace in c++ used for five main thing 
- prevent name conflict for function, ex you want to creat a function that hase a name add to do some operation with two parameters (int) and also you want to creat another function do another thing but with the same name and with the same type of parameters, here you need to creat a name spacefor each one and then use what you want using the keyword\
 `using namespace the_name_of_your_name_space`

 - organize code

 you can creat a name space of your project like `namespace MyProject` and inside this name space you can define multiple calsses and  nested namespaces and so on.

 - access methods / variables
  
  `using namespace Math`  here I want to access the entire namespace of Math. without still repeat this thing `Math::` every time I want to use some feature or function inside Math.

  `using Math::add;` use spesific function with the lib Math. if you use this line after your name space you limit the scope access to your function for only the funciton add, if you want to use substract you need the full path to call it `Math::substract` or any another function to call

- created nesteed namespace

```
namespace name1
	{
		namespace Nestedname1
		{
			
		}
	}
```

- Alias Namespaces
namespace fd = std::cout




# basic things to know in C++
**name space**: Namespaces allows you to group entities like classes objects and functions under a 
name\
## classes
**classes** is an expanded concept of a data structure, instead of holding only the data, it can hold the both data and functions\
you can declare class using the keyword `class`

**member functions**: is operators and functions that are declared as members of a class, the body of member function is analysed after the class declaration. so you can use the data or member that is inside your class in your member function.
- member functions : they have access to data members and other member functions of the class
- you can invoke the member function using the dote operator after the name of your object.
- when a member function is defined with const. it  can be called on a constant object and will not modify the object.

**const member function** is a memer function in its prototype we found the keyword *const* like this\
 `void	displayStatus( void ) const;`
that means the object that will call this function you can't modifies its content or its value.
## objects
**object**: is an instantiation of a `class`. that contains data members and member functions.


## overloaded functions

the overloaded functions reduce the number of functions names to be remembered.
with overloading you can several functions with the same name but with different parameters

## constructor 
A constructor is a member function that is executed automatically whenever an object is created. the constructor its name like the class name.

## destructor



# STDIO STREAM

### stream
out context of programming you can imagine it is like flowing of water from a side to another one, but in the contex of programming it means the flows of data also from the side to another one

**stdio streams**: is a c++ way of formating input and output to a variety of sources, including the console, files, and string buffer.

### console
the console is the manner that the user uses to interact with the system programs of the OS or with another console applications.
the interaction consist of the text input from the STDIN  usually the keyboard, or the text displayed that is in this case is STDOUT.

## formated and unformated IO in C++

### formated input/ output
write and get data in a specified format., this is useful when you want to control how data appears or is interpreted.
like printf or scanf, or cin and cout in c++.
formated IO functions transforms  the iinternal binary representation to to ASCII. characters which are written to the ouput file.

### unformated I/O
reading and writing raw data (raw data it is data in its original format, generated by the system, devide or operation, adn has not been processed or changed in any way. raw data can be monitors, sensors, surveysm logfiles online transactions...)
## initialization for variables 

there is theree types of initialisation in c++\
copy   initializations : `a = 7` \
direct initializations : `a(1)` \
default initializations : `int a`\
list initialization : `int a{90}`\
value initialization : `int e{}`\  <!-- for defaul t value like 0-->
pointer initialization : `int *ptr{NULL}` <!-- to initialize pointer with NULL or you can simple put the address instead-->
braces initialization : `int a{10}` <!--supported in c++11-->
## initialize lists in c++

I will demonstrate in thsis section how to initialize a list in c++ just and another containers I think it is easy to find and learn about.

#### define a list in c++
##### define empty list `std::list<type> list_name;`
##### define list with some values  `std::list<type> list_name = {value1, value2, ...};`
##### initialize with constructors `std::list<type> list_name(n, value)` <!-- initialize number of elemetents n with value -->

`std::list<int> lt(n, value)` <!-- n = number of elements in your list and value == the value that you want to initialize your elements with-->

#### define array in c++.

initialise to zero  : `int arr[n] = {};`
aggregate initialization  : `int arr[5] = {1, 2, 3, 4, 5};`
range based initialization : `int arr[] = {1, 2, 3}` <!-- range based initialization common in c++11-->

#### define a vector in c++

define a vector : `std::vector<int> vec;`
aggregate initialization : `std::vector<int> vec = {1, 2, 3, 4, 6};`

## static 

static with variables it is the same thing as it in c , also can restrict the visibilty of the global variables and function in teh file which they are defined. and this useful for preventing name clashes in larger projects.\
static in c++ you can also use it in classes and we call it static member variable. ant it is shared between all instances of a class (objects). it is not belong to a specific object, but it is belongs to the class itself.
### static member function
can be called without creating an instance of the class. it can access only static member variables and other static functions of the class.

you can use it when you want some function that is related to a class but doesn't need an instance to be called.



## ex00
the first exercice in this Module is about printing some output to the user in the console in different cases
- without paremeter
- with parameters
- parameters with spaces in the begin and the end and you should ignore them. 


bouth the cin and cout in c++ is objects which you can use them to get the input and also to print the output to the user.

\
  ```cout << "Hello User" << "\n";```

## ex01
in this section you will creat a program that can accept three command ADD, SEARCH and EXIT. in this program you can save until 8 contacts with the following inforamation.
firstname, lastname, nickname, phonenumber, and darkest secrets. every time you run ADD, you will add new one until reach the max that is 8, then the old one will be replaced by the new one. don't worry once you quit the program all your data will be losted forever, and you can display this information while you running the SEARCH, this command will print to you all contacts that is saved with its index. then will prompt you to enter an index to see full information for some contact.

## ex02
 this exercice goal is to implement a fucntions that products the same result that is in the logfile, this logfile is in the projects resources. and also the test.cpp that provides the main of the project. to test the requirements of the project.


## just things I try avoid to lose them

UNFORMATED AND FORMATED IO operations 
	UNFORMATED I/O operations,
		unformated input operations, 

	FORMATED I/O operation
		is read  / write from / to the stream in a specified format to control the appearance
	and interpretation of data 
	(char, int, float ...).