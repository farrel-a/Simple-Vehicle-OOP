//16520373 - Farrel Ahmad
//Vehicle OOP Program
//Program Name : Digital Transportation System
//header file (vehicle.hpp)

#include <vector>
#include <iostream>

class vehicle //base class : custom type vehicle/transportation type
{
private:
    bool keyLocked = true;  //true = locked
    bool engineON = false;
    int fuel;  //Litre
    int speed; //km/h
    int wheel=0; //num. of wheels
    std::string transtype = "Unknown"; //transportation type
    std::string brand = "Unknown";     //brand name

public:
    vehicle()
    {
        fuel = 0;
        speed = 0;
    }

    vehicle(int fl, std::string trnstyp, std::string brnd, int wl)
    {
        fuel = fl; //initial fuel value (L)
        brand = brnd; //brand name
        transtype = trnstyp;  //transportation type
        speed = 0;
        wheel = wl; //number of wheels
    }

    void setWheel(int wl){wheel = wl;}

    void lock(){keyLocked = true;}

    void unlock(){keyLocked = false;}

    void turnOnEngine()
    {
        if (!keyLocked)
        {
            if (!engineON && (fuel>0))
            {       engineON = true;
                    std::cout << "\nEngine has been turned on" << std::endl;
            }
            else if (!engineON && (fuel<=0))
            {
                std::cout<<"\nUnable to start the engine, out of fuel"<<std::endl;
            }
            else if (engineON)
            {
                std::cout << "\nEngine already been turned on!" << std::endl;
            }
        }
        else {std::cout<<"\nVehicle is locked!"<<std::endl;}

    }

    void turnOffEngine()
    {
        if (engineON)
        {
            std::cout << "\nEngine has been turned off" << std::endl;
            engineON = false;
        }
        else
        {
            std::cout << "\nEngine already been turned off!" << std::endl;
        }
    }

    void setFuel(int a){fuel = a;}

    void refuel(int a){fuel += a;}

    void setSpeed(int a){speed = a;}

    int getSpeed(){return speed;}

    void decreaseFuel(int a){if ((fuel-a)>0) {fuel -= a;} else {fuel=0; turnOffEngine(); setSpeed(0);std::cout<<"Out of fuel\nSpeed set to 0 km/h\n"<<std::endl;}}

    void status()  //vehicle status
    {
        std::cout<<"\nBrand: "; getBrand();
        std::cout<<"keyLocked : "<<keyLocked<<"\t\t";
        std::cout<<"EngineON : "<<engineON<<std::endl;
        std::cout<<"Fuel : " <<fuel<<" L" << "\t\t";
        std::cout<<"Speed : " <<speed<<" km/h" << std::endl;
        std::cout<<"Type : "<<transtype<<"\t\t";
        std::cout<<"Wheels : "<<wheel<<std::endl;
    }

    void setTransType(std::string a){transtype = a;}

    void setBrand(std::string a){brand = a;}

    void getBrand(){std::cout<<brand<<std::endl;}

    void accelerate(int a){speed += a;decreaseFuel(1);}

    void decelerate(int a){if ((speed-a)>=0){speed -= a;}else{speed = 0;}}

    bool isEngineOn(){
        if (engineON){return true;}
        else {return false;}}

    bool isLocked()
    {
        if (keyLocked){return true;}
        else {return false;}
    }
    bool isStopped()
    {
        if (speed==0){return true;} else{return false;}
    }
};

class car : public vehicle //car : child class of base class vehicle
{
private:
    int TP;  //Tyre Pressure (psi)
    int maxPassengers; //maximum passengers (driver excluded), EX: if car is 2 seater, then max passenger is 1
    int passengers = 0; //current passenger in car
public:
    car()
    {
        setFuel(0);
        setTransType("Car");
        TP = 0;
        maxPassengers = 2;
        setWheel(4);
    }
    car(int fl, int typress, std::string brnd, int MP)
    {
        setFuel(fl);  //initial fuel value (L)
        setTransType("Car"); //transtype to Car
        TP = typress; //tyre pressure
        setBrand(brnd); //brand name
        maxPassengers = MP; //max passengers
        setWheel(4); //number of wheels
    }
    void showStatus() //car status
    {
        status();
        std::cout<<"Tyre Pressure : " << TP << " psi"<< std::endl;
        std::cout<<"Passengers : " << passengers << std::endl;
    }
    void addPassengers(int p)
    {
        if ((passengers + p) <= maxPassengers){passengers+=p;std::cout<<p<<" passengers added\n"<<std::endl;} else {std::cout<<"Not enough passengers"<<std::endl;}
    }

    void remPassengers(int p) //remove passengers
    {
        if ((passengers-p)>=0){passengers-=p;std::cout<<p<<" passengers removed\n"<<std::endl;} else{passengers = 0;std::cout<<"All passengers removed\n"<<std::endl;}
    }

    void setTyrePressure(int tp) // unit in psi
    {
        TP = tp;
    }

};

class airplane : public vehicle //airplane : child class of base class vehicle
{
private:
    int altitude = 0;   // unit in meter (m)
    int heading = 0;    //direction of the aircraft (0-359 degrees)
public:
    airplane()
    {
        setTransType("Airplane");
        setWheel(3);
    }
    airplane(std::string brnd, int fl)
    {
        setTransType("Airplane");
        setFuel(fl);
        setBrand(brnd);
        setWheel(3);
    }
    void ascend (int a)  //climb
    {
        if (isEngineOn()) {altitude += a;std::cout<<"Altitude +" << a<<" m\n"<<std::endl;}
        else {std::cout<<"Unable to ascend, engine is turned off"<<std::endl;}
    }
    void descend (int d) //descend
    {
        if ((altitude-d)>=0){altitude-=d;std::cout<<"Altitude -"<<d<<" m\n"<<std::endl;}
        else{std::cout<<"Unable to descend, the airplane will strike the ground"<<std::endl;}
    }
    void setHeading (int h){heading = h;std::cout<<"Heading set to "<<h<<" degrees\n"<<std::endl;} //set airplane's heading
    void showStatus() //airplane status
    {
        status();
        std::cout<<"Altitude : "<<altitude<<" m\nHeading : "<< heading<<" deg"<<std::endl;
    }
    int getAltitude(){return altitude;}
    void setAltitude(int a){altitude = a;}


};

//interface menu
void menu();

//add new vehicle to vector dynamic array
void addVehicle(std::vector <vehicle> *v);

//add new car to vector dynamic array
void addCar(std::vector <car> *c);

//add new airplane to vector dynamic array
void addAirplane(std::vector <airplane> *a);

//main menu input
void menuCode(int c);

//status interface
void status(std::vector <vehicle> *v, std::vector <car> *c, std::vector <airplane> *a);

//vehicle, car, and airplane control interface
void control(std::vector <vehicle> *v, std::vector <car> *c, std::vector <airplane> *a);

//vehicle control procedure
void vehicleControl(vehicle *v);

//car control procedure
void carControl(car *c);

//airplane control procedure
void airplaneControl(airplane *a);
