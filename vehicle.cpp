//16520373 - Farrel Ahmad
//Vehicle OOP Program
//Program Name : Digital Transportation System
//main file (vehicle.cpp)

#include <iostream>
#include <string>
#include "vehicle.hpp"
#include <vector>

void menu()
{
    std::cout<<"--- Digital Transportation System ---"<<std::endl;
    std::cout<<"(1). Transportation List\t"<<"(2). Add Vehicle"<<std::endl;
    std::cout<<"(3). Add Car\t\t\t"<<"(4). Add Airplane"<<std::endl;
    std::cout<<"(5). Status\t\t\t(6). Control\n(20). Exit Program" << std::endl;
    std::cout<<"Insert Command : ";
}

void transportationList (std::vector <vehicle> V, std::vector <car> C, std::vector <airplane> A)
{
    int i;
    std::cout<<"\nVehicle : "<<std::endl;
    if ((V).size()==0) {std::cout<<"Vehicle List is Empty"<<std::endl;}
    else {for (i=0;i<((V).size());i++){std::cout <<"("<<(i+1)<<")"<<". ";(V).at(i).getBrand();}}

    std::cout<<"\nCar : " << std::endl;
    if((C).size()==0){std::cout<<"Car List is Empty"<<std::endl;}
    else {for (i=0;i<((C).size());i++){std::cout<<"("<<(i+1)<<")"<<". "; (C).at(i).getBrand();}}

    std::cout<<"\nAirplane : "<<std::endl;
    if((A).size()==0){std::cout<<"Airplane List is Empty\n"<<std::endl;}
    else {for (i=0;i<((A).size());i++){std::cout<<"("<<(i+1)<<")"<<". "; (A).at(i).getBrand();}}
}

void addVehicle(std::vector <vehicle> *v)
{
    int fl; std::string trnstyp; std::string brnd; int wl;
    std::cin.ignore(256, '\n');
    std::cout<<"Vehicle Brand : "; std::getline(std::cin, brnd);
    std::cout<<"Initial Fuel (L) : "; std::cin>>fl;
    std::cin.ignore(256, '\n');
    std::cout<<"Transportation Type : "; std::getline(std::cin, trnstyp);
    std::cout<<"Number of Wheels : "; std::cin>>wl;
    vehicle New(fl, trnstyp, brnd, wl);
    (*v).push_back(New);
}

void addCar(std::vector <car> *c)
{
    int fuel; int typress; std::string brand; int MaxP;
    std::cin.ignore(256, '\n');
    std::cout<<"Car Brand : "; std::getline(std::cin, brand);
    std::cout<<"Initial Fuel (L) : "; std::cin>>fuel;
    std::cout<<"Initial Tyre Pressure (psi) : "; std::cin>>typress;
    std::cout<<"Max Passengers (excluding driver) : "; std::cin>>MaxP;
    std::cout<<std::endl;
    car New(fuel,typress, brand, MaxP);
    (*c).push_back(New);
}

void addAirplane(std::vector <airplane> *a)
{
    std::string brand; int fuel;
    std::cin.ignore(256, '\n');
    std::cout<<"Airplane Brand : "; std::getline(std::cin, brand);
    std::cout<<"Initial Fuel (L) : "; std::cin>>fuel;
    std::cout<<std::endl;
    airplane New(brand, fuel);
    (*a).push_back(New);
}

void status(std::vector <vehicle> *v, std::vector <car> *c, std::vector <airplane> *a)
{
        char ci; int n;
        if ((*v).size()!=0 || (*c).size() != 0 || (*a).size() != 0)
        {
            transportationList(*v, *c, *a);
            std::cout<<"\nSelect Vehicle (EX : v1, c2, a2) : ";std::cin >> ci >> n;
            if ((ci=='v')||(ci=='V')||(ci=='c')||(ci=='C')||(ci=='a')||(ci=='A'))
            {
                if ((ci=='v')||(ci=='V')) //vehicle
                {
                    if ((*v).size()==0) {std::cout<<"Unable to select, Vehicle List is empty"<<std::endl;}
                    else
                    {
                        if ((1<=n)&&(n<=((*v).size())))
                        {
                            (*v).at(n-1).status();
                        }
                        else{std::cout<<"Invalid Input"<<std::endl;}
                    }
                }
                else if ((ci=='c')||(ci=='C')) //car
                {
                    if ((*c).size()==0) {std::cout<<"Unable to select, Car List is empty"<<std::endl;}
                    else
                    {
                        if ((1<=n)&&(n<=((*c).size())))
                        {
                            (*c).at(n-1).showStatus();
                        }
                        else{std::cout<<"Invalid Input"<<std::endl;}
                    }
                }
                else if ((ci=='a')||(ci=='A')) //airplane
                {
                    if ((*a).size()==0) {std::cout<<"Unable to select, Airplane List is empty"<<std::endl;}
                    else
                    {
                        if ((1<=n)&&(n<=((*a).size())))
                        {
                            (*a).at(n-1).showStatus();
                        }
                        else{std::cout<<"Invalid Input"<<std::endl;}
                    }
                }
            }
            else{std::cout<<"Invalid Input"<<std::endl;}
        }
        else{std::cout<<"\nTransportation List is Empty"<<std::endl;}
}

void vehicleControl(vehicle *v)
{
    int c;
    while(c!=20)
    {
        (*v).status(); std::cout<<std::endl;
        std::cout<<"(1). Unlock\t\t(2). Lock\n(3). Turn On Engine\t(4). Turn Off Engine\n(5). Refuel\t\t(6). Apply Gas\n(7). Apply Brake\n(20). Exit Control\nInsert Control Command : "; std::cin>>c;
        if (c==1){(*v).unlock();std::cout<<"\nVehicle Unlocked"<<std::endl;} //unlock
        else if (c==2){(*v).lock();std::cout<<"\nVehicle Locked"<<std::endl;}//lock
        else if (c==3){(*v).turnOnEngine();}                                 //turn on engine
        else if (c==4){(*v).turnOffEngine();(*v).setSpeed(0);}               //turn off engine
        else if (c==5)                                                       //refuel
            {int r;
            if ((*v).isLocked()){std::cout<<"\nVehicle is locked\n"<<std::endl;}
            else if (!(*v).isStopped()){std::cout<<"\nUnable to refuel, please stop the vehicle first\n"<<std::endl;}
            else{
                std::cout<<"\nAdd Fuel (L) : ";std::cin>>r;
                if(r>=0){(*v).refuel(r);std::cout<<"Added "<<r<<" L of fuel\n"<<std::endl;}
                else{std::cout<<"Invalid Input"<<std::endl;}
                }
            }
        else if (c==6) //apply gas
        {
            if((*v).isEngineOn()){
                std::cout<<"\nGas Applied (speed +5 km/h, fuel -1 L)\n"<<std::endl;
                (*v).accelerate(5);}
            else{std::cout<<"\nUnable to apply gas, please turn on the engine\n"<<std::endl;}
        }
        else if (c==7) //apply brake
        {
            if ((*v).getSpeed()>0)
            {
                (*v).decelerate(5);std::cout<<"\nBrake Applied (speed -5 km/h)\n"<<std::endl;
            }
            else{std::cout<<"\nVehicle already stopped!\n"<<std::endl;}
        }
        else if (c==20){} //exit vehicle control
        else {std::cout<<"Invalid Input"<<std::endl;}
    }
}

void carControl(car *c)
{
    int ci;
    while(ci!=20)
    {
        (*c).showStatus(); std::cout<<std::endl;
        std::cout<<"(1). Unlock\t\t(2). Lock\n(3). Turn On Engine\t(4). Turn Off Engine\n(5). Refuel\t\t(6). Apply Gas\n(7). Apply Brake\t(8). Set Tyre Pressure\n(9). Add Passengers\t(10). Remove Passengers\n(20). Exit Control\nInsert Control Command : "; std::cin>>ci;
        if (ci==1){(*c).unlock();std::cout<<"\nCar Unlocked"<<std::endl;} //unlock
        else if (ci==2){(*c).lock();std::cout<<"\nCar Locked"<<std::endl;} // lock
        else if (ci==3){(*c).turnOnEngine();} //turn on engine
        else if (ci==4){(*c).turnOffEngine();(*c).setSpeed(0);} //turn off engine
        else if (ci==5) //refuel
            {int r;
                if ((*c).isLocked()){std::cout<<"\nCar is locked\n"<<std::endl;}
                else if (!(*c).isStopped()){std::cout<<"\nUnable to refuel, please stop the car first\n"<<std::endl;}
                else
                {
                    std::cout<<"\nAdd Fuel (L) : ";std::cin>>r;
                    if(r>=0){(*c).refuel(r);std::cout<<"Added "<<r<<" L of fuel\n"<<std::endl;}
                    else{std::cout<<"Invalid Input"<<std::endl;}
                }
            }
        else if (ci==6) //apply gas
        {
            if((*c).isEngineOn()){
                std::cout<<"\nGas Applied (speed +5 km/h, fuel -1 L)\n"<<std::endl;
                (*c).accelerate(5);}
            else{std::cout<<"\nUnable to apply gas, please turn on the engine\n"<<std::endl;}
        }
        else if (ci==7) //apply brake
        {
            if ((*c).getSpeed()>0)
            {
                (*c).decelerate(5);std::cout<<"\nBrake Applied (speed -5 km/h)\n"<<std::endl;
            }
            else{std::cout<<"\nCar already stopped!\n"<<std::endl;}
        }
        else if (ci==8) //set tyre pressure
        {
            if ((*c).isLocked()){std::cout<<"\nCar is locked\n"<<std::endl;}
            else if (!(*c).isStopped()){std::cout<<"\nUnable to set Tyre Pressure, please stop the car first!\n"<<std::endl;}
            else
            {
                int tp;std::cout<<"\nSet Tyre Pressure (psi) : ";std::cin>>tp;
                if (tp>=0){(*c).setTyrePressure(tp);std::cout<<"Tyre Pressure set to "<<tp<<" psi\n"<<std::endl;}
                else{std::cout<<"Invalid Input\n"<<std::endl;}
            }
        }
        else if (ci==9) //add passenger
        {
            if ((*c).isLocked()){std::cout<<"\nCar is locked\n"<<std::endl;}
            else if (!(*c).isStopped()){std::cout<<"\nUnable to add passengers, please stop the car first\n"<<std::endl;}
            else
            {
                int p;std::cout<<"Add Passengers : ";std::cin>>p;
                if(p>=0){(*c).addPassengers(p);}
                else{std::cout<<"\nInvalid Input\n"<<std::endl;}
            }
        }
        else if (ci==10) //remove passenger
        {
            if ((*c).isLocked()){std::cout<<"\nCar is locked\n"<<std::endl;}
            else if (!(*c).isStopped()){std::cout<<"\nUnable to remove passengers, please stop the car first\n"<<std::endl;}
            else
            {
                int p;std::cout<<"Remove Passengers : ";std::cin>>p;
                if(p>=0){(*c).remPassengers(p);}
                else{std::cout<<"\nInvalid Input\n"<<std::endl;}
            }
        }
        else if (ci==20){} //exit car control
        else{std::cout<<"Invalid Input"<<std::endl;}
    }
}

void airplaneControl(airplane *a)
{
    int c;
    while (c!=20)
    {
        (*a).showStatus();std::cout<<std::endl;
        std::cout<<"(1). Unlock\t\t(2). Lock\n(3). Turn On Engine\t(4). Turn Off Engine\n(5). Refuel\t\t(6). Apply Gas\n(7). Apply Brake\t(8). Ascend\n(9). Descend\t\t(10). Set Heading\n(20). Exit Control\nInsert Control Command : "; std::cin>>c;
        if (c==1){(*a).unlock();std::cout<<"\nAirplane Unlocked"<<std::endl;} //unlock
        else if (c==2){(*a).lock();std::cout<<"\nAirplane Locked"<<std::endl;} // lock
        else if (c==3){(*a).turnOnEngine();}    //turn on engine
        else if (c==4){(*a).turnOffEngine();(*a).setSpeed(0);} //turn off engine
        else if (c==5) //refuel
            {int r;
            if ((*a).isLocked()){std::cout<<"\nAirplane is locked\n"<<std::endl;}
            else if (!(*a).isStopped()){std::cout<<"\nUnable to refuel, please stop the airplane first\n"<<std::endl;}
            else{
                std::cout<<"\nAdd Fuel (L) : ";std::cin>>r;
                if(r>=0){(*a).refuel(r);std::cout<<"Added "<<r<<" L of fuel\n"<<std::endl;}
                else{std::cout<<"Invalid Input"<<std::endl;}
                }
            }
        else if (c==6) //apply gas
        {
            if((*a).isEngineOn()){
                std::cout<<"\nGas Applied (speed +20 km/h, fuel -1 L)\n"<<std::endl;
                (*a).accelerate(20);
                if ((*a).getSpeed()==0){(*a).setAltitude(0);std::cout<<"Altitude set to 0 m"<<std::endl;}}
            else{std::cout<<"\nUnable to apply gas, please turn on the engine\n"<<std::endl;}
        }
        else if (c==7) //apply brake
        {
            if ((*a).getSpeed()>0)
            {
                (*a).decelerate(20);std::cout<<"\nBrake Applied (speed -20 km/h)\n"<<std::endl;
            }
            else{std::cout<<"\nAirplane already stopped!\n"<<std::endl;}
        }
        else if (c==8) //ascend
        {
            if ((*a).isLocked()){std::cout<<"\nUnable to climb, airplane is locked\n"<<std::endl;}
            else if ((*a).getSpeed()<260){std::cout<<"\nSpeed must be >= 260 km/h to climb\n"<<std::endl;}
            else {int alt;std::cout<<"Climb (m) : "; std::cin>>alt;
                if (alt>=0){(*a).ascend(alt);}
                else{std::cout<<"\nInvalid Input\n"<<std::endl;}}
        }
        else if (c==9) //descend
        {
            if ((*a).isLocked()){std::cout<<"\nUnable to descend, airplane is locked\n"<<std::endl;}
            else if ((*a).getAltitude()==0){std::cout<<"\nUnable to descend, airplane is already on the ground\n"<<std::endl;}
            else{int alt; std::cout<<"Descend (m) : "; std::cin>>alt;
                    if (alt>=0){(*a).descend(alt);}
                    else{std::cout<<"\nInvalid Input\n"<<std::endl;}
                }
        }
        else if (c==10) //heading
        {
            if ((*a).isLocked()){std::cout<<"\nUnable to turn, airplane is locked\n"<<std::endl;}
            else if ((*a).getSpeed()<260){std::cout<<"\nUnable to turn, airplane must be >=260 km/h\n"<<std::endl;}
            else {int head; std::cout<<"Set heading to (deg) : "; std::cin>>head;
                if (0<=head && head<=359) {(*a).setHeading(head);}
                else{std::cout<<"Invalid Input"<<std::endl;}}
        }
        else if (c==20){}
        else {std::cout<<"Invalid Input"<<std::endl;}
    }
}

void control(std::vector <vehicle> *v, std::vector <car> *c, std::vector <airplane> *a)
{
        char ci; int n;
        if ((*v).size()!=0 || (*c).size() != 0 || (*a).size() != 0)
        {
            transportationList(*v, *c, *a);
            std::cout<<"\nSelect Vehicle (EX : v1, c2, a2) : ";std::cin >> ci >> n;
            if ((ci=='v')||(ci=='V')||(ci=='c')||(ci=='C')||(ci=='a')||(ci=='A'))
            {
                if ((ci=='v')||(ci=='V')) //vehicle
                {
                    if ((*v).size()==0) {std::cout<<"Unable to select, Vehicle List is empty"<<std::endl;}
                    else
                    {
                        if ((1<=n)&&(n<=((*v).size())))
                        {
                            vehicleControl(&((*v).at(n-1)));
                        }
                        else{std::cout<<"Invalid Input"<<std::endl;}
                    }
                }
                else if ((ci=='c')||(ci=='C')) //car
                {
                    if ((*c).size()==0) {std::cout<<"Unable to select, Car List is empty"<<std::endl;}
                    else
                    {
                        if ((1<=n)&&(n<=((*c).size())))
                        {
                            carControl(&((*c).at(n-1)));
                        }
                        else{std::cout<<"Invalid Input"<<std::endl;}
                    }
                }
                else if ((ci=='a')||(ci=='A')) //airplane
                {
                    if ((*a).size()==0) {std::cout<<"Unable to select, Airplane List is empty"<<std::endl;}
                    else
                    {
                        if ((1<=n)&&(n<=((*a).size())))
                        {
                            airplaneControl(&((*a).at(n-1)));
                        }
                        else{std::cout<<"Invalid Input"<<std::endl;}
                    }
                }
            }
            else{std::cout<<"Invalid Input"<<std::endl;}
        }
        else{std::cout<<"\nTransportation List is Empty"<<std::endl;}
}
void menuCode(int code, std::vector <vehicle> *v, std::vector <car> *c, std::vector <airplane> *a)
{
    if (code==1){transportationList(*v, *c, *a);} //transportation list
    else if (code==2){addVehicle(v);}   //add vehicle
    else if (code==3){addCar(c);}       //add car
    else if (code==4){addAirplane(a);}  //add airplane
    else if (code==5){status(v, c, a);} //vehicle/car/airplane status
    else if (code==6){control(v, c, a);}//vehicle/car/airplane control
    std::cout<<std::endl;
}

int main()  //main program
{
    int c;
    std::vector <vehicle> arr_v; std::vector <car> arr_c; std::vector <airplane> arr_a;
    while (c!=20)
    {
        menu(); //interface menu
        std::cin>>c; //command input
        menuCode(c, &arr_v, &arr_c, &arr_a); //menu input process
    }
    return 0;
}
