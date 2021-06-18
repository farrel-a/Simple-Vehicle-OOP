# Vehicle OOP Program in C++

## 16520373 - Farrel Ahmad
### 2 June 2021
<br />

## Introduction
OOP or Object Oriented Programming is a programming paradigm that utilizes objects in the program. An object is defined in the program and has its' own attributes/characteristics. Usually an object in program is defined within the `class`. 

Suppose we want to define an object of a vehicle. A vehicle has charactersitics, such as it has wheels, it can be refueled, the engine can be turned on, it has tyre pressure, etc. From this idea, we can define `class vehicle` with variables such as `int wheel`, `int fuel`, `int tyre_pressure`, and so on. This is similar to what we often hear as custom data type. A data type of vehicle that consists of primitive data types (`int wheel`, `int fuel`, `int tyre_pressure`,etc).

A defined class (base class) can also be derived to several child class. This method is called inheritance. For example, let `class airplane` be the definition of an object airplane. An airplane is also a vehicle but it has another characteristics/attributes. We can derive the definition of a `class vehicle` to a `class airplane` so that the `class airplane` has some of the basic vehicle functionality. Then, we can add another characteristics that is unique to the `class airplane` such as heading and altitude.

The idea of this OOP paradigm is to create objects based on the definition and use it within the program to solve problems. Usually a defined `class` or object also has built-in functions like refueling, setting tyre pressure, or anything that can be used within the program.

In this program, there are 3 object definitons. These are `class vehicle`, `class car`, and `class airplane`. Car and Airplane are derived from Vehicle. The usage of `class vehicle` is to define any type of vehicle that is different from car and airplane. For example, autonomous cargo robot, motorbike, or cargo ship. Thus, any type of transportation that is not a car and not an airplane can be defined using `class vehicle`.
<br/>

## Compiling The Program
1. Clone this repository to your local computer by running this command in terminal.
```
git clone https://gitlab.com/dagozilla/academy/2021-internship1/16520373/day-3.git
```
2. Change directory to the folder `/day-3`
3. Change branch to `development`
```
git checkout development
```
4. Change directory to the folder `/16520373`
5. By using `ls` command there should be `vehicle.cpp` and `vehicle.hpp`. These are files of the program
6. Compile these files using terminal by running this command
```
g++ vehicle.cpp vehicle.hpp -o vehicle
```
7. After sucessfully compiled, run the program by running this command
```
./vehicle
```
<br/>

## Using The Program
1. After the program successfully runs, there should me a main menu interface like this.
```
--- Digital Transportation System ---
(1). Transportation List        (2). Add Vehicle
(3). Add Car                    (4). Add Airplane
(5). Status                     (6). Control
(20). Exit Program
Insert Command : 
```
2. Use Transportation List (1) by entering the number to see the list of transportation that has been created. Initially, the program does not have any objects. Thus, when we type (1) it will prompt the message like this.
```
Insert Command : 1

Vehicle : 
Vehicle List is Empty

Car : 
Car List is Empty

Airplane : 
Airplane List is Empty
```
2. Vehicle, Car, and Airplane are stored in different arrays. The array that is used in this program is dynamic array using vector. An array of `class vehicle` is stored in the variable `arr_v`, an array of `class car` is stored in the variable `arr_c`, and an array of `class airplane` is store in the variable `arr_a`. When the program starts, these arrays are still empty. Thus we need to add elements to these arrays.  

3. Use Add Vehicle (2) to create a vehicle and define a custom type vehicle that is neither a car nor an airplane. For example,
```
Insert Command : 2
Vehicle Brand : Robotype X
Initial Fuel (L) : 5
Transportation Type : Military Cargo                 
Number of Wheels : 5
```
3. This newly created object will be stored in `arr_v` variable. If we create another one then it will be added as a new element in the array `arr_v`. We can now see the vehicle list using transportation list in no. (1)
```
Insert Command : 1

Vehicle : 
(1). Robotype X

Car : 
Car List is Empty

Airplane : 
Airplane List is Empty
```

4. Use Add Car (3) to create and define a new object of car.
```
Insert Command : 3
Car Brand : Honda NSX
Initial Fuel (L) : 8 
Initial Tyre Pressure (psi) : 27
Max Passengers (excluding driver) : 1
```
4. The Transportation List now should be updated
```
Insert Command : 1

Vehicle : 
(1). Robotype X

Car : 
(1). Honda NSX

Airplane : 
Airplane List is Empty
```

5. Use Add Airplane (4) to create and define a new object of airplane
```
Insert Command : 4
Airplane Brand : Airbus A320
Initial Fuel (L) : 15 
```
5. The Transportation List now should be updated
```
Insert Command : 1

Vehicle : 
(1). Robotype X

Car : 
(1). Honda NSX

Airplane : 
(1). Airbus A320
```

6. Use Status (5) to see one of the transportation status and insert the code. For example, code `v1` means vehicle no.1, code `c1` means car no.1 and code `a1` means airplane no.1. 
```
Insert Command : 5

Vehicle : 
(1). Robotype X

Car : 
(1). Honda NSX

Airplane : 
(1). Airbus A320

Select Vehicle (EX : v1, c2, a2) : v1

Brand: Robotype X
keyLocked : 1           EngineON : 0
Fuel : 5 L              Speed : 0 km/h
Type : Military Cargo           Wheels : 5
```

```
Insert Command : 5

Vehicle : 
(1). Robotype X

Car : 
(1). Honda NSX

Airplane : 
(1). Airbus A320

Select Vehicle (EX : v1, c2, a2) : c1

Brand: Honda NSX
keyLocked : 1           EngineON : 0
Fuel : 8 L              Speed : 0 km/h
Type : Car              Wheels : 4
Tyre Pressure : 27 psi
Passengers : 0
```

```
Insert Command : 5

Vehicle : 
(1). Robotype X

Car : 
(1). Honda NSX

Airplane : 
(1). Airbus A320

Select Vehicle (EX : v1, c2, a2) : a1

Brand: Airbus A320
keyLocked : 1           EngineON : 0
Fuel : 15 L             Speed : 0 km/h
Type : Airplane         Wheels : 3
Altitude : 0 m
Heading : 0 deg
```

6. Because Car and Airplane are derived from the Vehicle, Car and Airplane also have the status of `brand`, `keyLocked`,`EngineON`, `Fuel`,`Type`,`Speed`, and `Wheels`. However, Car has unique status which is `Tyre Pressure` and `Passengers`, while Airplane also has unique status which is `Altitude` and `Heading`.

7. Use Control (6) to control one of the transportation that has been created. This is the example of controlling Airbus A320 that has been created before.
```
Insert Command : 6

Vehicle : 
(1). Robotype X

Car : 
(1). Honda NSX

Airplane : 
(1). Airbus A320

Select Vehicle (EX : v1, c2, a2) : a1

Brand: Airbus A320
keyLocked : 1           EngineON : 0
Fuel : 15 L             Speed : 0 km/h
Type : Airplane         Wheels : 3
Altitude : 0 m
Heading : 0 deg

(1). Unlock             (2). Lock
(3). Turn On Engine     (4). Turn Off Engine
(5). Refuel             (6). Apply Gas
(7). Apply Brake        (8). Ascend
(9). Descend            (10). Set Heading
(20). Exit Control
Insert Control Command : 
```
7. You can play around with this Control feature. Special for an airplane, to Ascend or Set Heading, the speed must be >=260 km/h. This is for the simulation of take off procedure. To increase the speed use Apply Gas and to reduce speed use Apply Brake. However to do this, the engine must be turned on. To Turn On Engine, the vehicle must be unlocked. If keyLocked indicator is set to 1 then it is locked (1 is true, 0 is false). This also applies to EngineON indicator. Same for the Refuel, the Airplane also must be unlocked. Use (20) Exit Control to exit control mode and go back to main menu.

7.  This Control mode actually modifies the selected element in the selected array. If we choose `v1`, then it will select arr_v and select first element (index 0). The selected element is an object that has been created before. Then, the selected element is modified through user input.

8. In the main menu, Use Exit Program (20) to exit the program.

## Conclusion 

Although this program does not have many child class, we can see the usage of the objects and how we interact with the newly created object. By using the Add function in the main menu to create an object, this shows the basic of how the user wants when the user is defining an object. Then, after the user created the objects, the user can interact with the objects by either looking at the status, or see the list of transportation, or even controlling one of the transportation using Control feature. Also, note that this implementation code might not be efficient, but probably still functional enough to demonstrate how OOP works. 

## Reference
- GeeksforGeeks. 2020. *Object Oriented Programming in C++*. https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/. Accessed on 2 June 2021.
- GeeksforGeeks. 2021. *C++ Classes and Objects*. https://www.geeksforgeeks.org/c-classes-and-objects/. Accesed on 31 May 2021.

- Dagozilla. 2021. *Dagozilla Encylopedia*. https://github.com/dagozilla/encyclopedia. Accessed on 31 May 2021.

- GeeksforGeeks. 2021. *Inheritance in C++*. https://www.geeksforgeeks.org/inheritance-in-c/. Accessed on 31 May 2021

- GeeksforGeeks. 2021. *Vector in C++ STL*. https://www.geeksforgeeks.org/vector-in-cpp-stl/. Accessed on 1 June 2021.

- cplusplus.com. *Reference Vector*. https://www.cplusplus.com/reference/vector/. Accessed on 1 June 2021.  
