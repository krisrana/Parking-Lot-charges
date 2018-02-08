/*
     Name:      Krishna rana
     Course:    CIS 160 ME1
     Date:      09/28/2016
     Program:   Parking Lot Charges
     Description:  This program will compute and print for customers, who park in the parking lot, the parking 
	 				fare based on the vehicle type and hours the vehicle was parked.
*/

#include <iostream>//Standard Input/output streams libary
#include <iomanip>// Header providing parametric manipulators

using namespace std;
// Function prototype
void getvehicleinfo(char& vehicle, string& type, char& trucktype);
void gettime(int& hourin, int& minin, int& hourout, int& minout);
void calctime(int& hourin, int& minin, int& hourout, int& minout, int& hourtotal, int& mintotal, string& amorpm, int& roundtotal);
void calcrates(char vehicle, char trucktype, int roundtotal,double& totaldue);
void output(char& vehicle, string& type, int& hourin, int& minin, int& hourout, int& minout,
			 int& hourtotal, int& mintotal, string& amorpm, int& roundtotal, double& totaldue);

//Main() Function Defination
//This function runs the whole program with step by step intruction written below.
//main() has declaration of char, string, int, float and double type of value.
//main() has calls and parameters of other function in the program.
int main()
{	//Declarlation/ Definations
	char vehicle, response, trucktype;
	string type, amorpm;
	int hourin, minin, hourout, minout, hourtotal, mintotal, roundtotal;
	double totaldue;
	float firstrate, secondrate, totalcharges;
	//heading for introduction of the program and
	//notes for user to read before proceeding
	cout<<"\t\t\t      PASSAIC COUNTY PARKING AUTHORITY\n";
	cout<<"\t\t\t\t   PARKING LOT CHARGES\n";
	cout<<"\t\t\t__________________________________________\n\n";
	cout<<"\t\t\t****Enter all the required information****";
	cout<<"\n\t\t\t****PLEASE READ THE NOTES BEFORE INPUT****\n\n\n";
	cout<<"Do you have Vehicle information to enter?";
	cout<<"\n(Type 'Y'for yes, If you have vehicle information or type 'N' for no to exit): ";
	cin>>response;
	//toupper function is used to make the input capital.
	response = toupper(response);
	//a loop to keep the function calls within while loop go forever
	//unless and untill the keyword 'N' or 'n' is entered to terminate the loop
	while(response!='N')
	{
		//Function Calls
		getvehicleinfo(vehicle, type, trucktype);
		gettime(hourin, minin, hourout, minout);
		calctime(hourin, minin, hourout, minout, hourtotal, mintotal, amorpm, roundtotal);
		calcrates(vehicle, trucktype, roundtotal, totaldue);
		output(vehicle, type, hourin, minin, hourout, minout, hourtotal, mintotal, amorpm, roundtotal, totaldue);
		cout<<"_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-";
		// response prompt from user to continue or terminate the program
		cout<<"\n\nDo you have another vehicle?";
		cout<<"\n(Type 'Y'for yes, If you have vehicle information or type 'N' for no to exit): ";
		cin>>response;
		response = toupper(response);
	} 

	return 0;
}
//getvehicleinfo() Function Defination
//This function is used to get vehicle info from the user.
//The input consist of vehicle type which is char.
//It's return type is null, but it passes the value of vehicle via reference.
void getvehicleinfo(char& vehicle, string& type, char& trucktype)
{	
	//geting vehicle info from user.
	cout<<"\n Type of vehicle: ";
	cout<<"\n ('C' for Car, 'V' for Van, 'S' for SUV, 'B' for Bus,'T' for Truck)";
	cin>>vehicle;
	vehicle = toupper(vehicle);
	//validating condition that would not accept any other data except C,V,S,B,and T.
	while ((vehicle!='C')&&(vehicle!='V')&&(vehicle!='S')&&(vehicle!='B')&&(vehicle!='T'))
			{
				cout<<"ERROR:Vehicle should be 'C' for Car, 'V' for Van, 'S' for SUV, 'B' for Bus,'T' for Truck): ";
				cin>>vehicle;
				vehicle = toupper(vehicle);
			}
	//truck has two class- if condition gets the info about truck type.
	if (vehicle == 'T')
	{
		cout<<"Truck have two classes 'S' for Small Truck and 'L' for Large Truck";
		cout<<"\nType of Truck: ";
		cin>>trucktype;
		//validating condition that would only accept s and l.
		while ((trucktype!= 's')&&(trucktype!= 'l'))
		{
			cout<<"ERROR:Truck have two classes 'S' for Small Truck and 'L' for Large Truck : ";
			cout<<"\nType of Truck: ";
			cin>>trucktype;
		}
	}
	// switch case to accsociated chareter's of vehicle to string.
	switch(vehicle)
	{
		case 'C' : type = "Car";
			break;
		case 'V' : type = "Van";
			break;
		case 'S' : type = "SUV";
			break;
		case 'B' : type = "Bus";
			break;
	}
	switch(trucktype)
	{
		case 'l' : type = "Large Truck";
			break;
		case 's' : type = "Small truck";
			break;
	}
}
//gettime() Function Defination
//This function is used to get input from the user.
//The input consist of hours entered and exited the lot.
//It's return type is null, but it passes the value of hours time via reference.
void gettime(int& hourin, int& minin, int& hourout, int& minout)
{
	// gets the time (hours) the vehicle entered the lot.
	cout<<"\n Hour vehicle entered the Lot: "; cin>> hourin;
	//validating condition to only accept integer from 0 - 24.	
	if(hourin < 0 || hourin > 24)
	{
		cout << "Invalid input!!, Enter the Hours between 0 and 24.\nHour vehicle entered the Lot: ";
		cin >> hourin;
	}
	// gets the time(minutes) the vehicle entered the lot.
	cout<<"\n Minute Vehicle entered the Lot: "; cin>> minin;
	//validating condition to only accept integer from 0 - 60.
	if(minin < 0 || minin > 60)
	{
		cout << "Invalid input!!, Enter the Minutes between 0 and 60.\n Minute Vehicle entered the Lot: ";
		cin >> minin;
	}
	// gets the time (hours) the vehicle exited the lot.
	cout<<"\n Hour vehicle exit the Lot: "; cin>> hourout;
	//validating condition to only accept integer from 0 - 24.
	if(hourout < 0 || hourout > 24)
	{
		cout << "Invalid input!!, Enter the Hours between 0 and 24.\nHour vehicle exit the Lot: ";
		cin >> hourout;
	}
	// gets the time(minutes) the vehicle exited the lot.
	cout<<"\n Minute Vehicle exit the Lot: "; cin>> minout;
	//validating condition to only accept integer from 0 - 60.
	if(minout < 0 || minout > 60)
	{
		cout << "Invalid input!!, Enter the Minutes between 0 and 60.\n Minute Vehicle exit the Lot: ";
		cin >> minout;
	}
}
//calctime() Function Defination
//This function is used to calculate time difference from the input form getvehicleinfo().
//the calculation is done with the value from getvehicleinfo() which are passed by reference.
//It's return type is null, but it passes the value of hourtotal,mintotal,amorpm and roundtotal.
void calctime(int& hourin, int& minin, int& hourout, int& minout, int& hourtotal, int& mintotal, string& amorpm, int& roundtotal)
{
	//local declaration
	int sumtotal, hourintotal, houroutotal;
	float sumtot;
	//calcuation to make hours and minutes adjustment within 60 minutes.	
	hourtotal = (hourout - hourin);	
	mintotal= (minout - minin);
	if (mintotal < 0)
	{
		mintotal = mintotal + 60;
		hourtotal= hourtotal - 1;
	}
	hourintotal = hourin*60+minin;
	houroutotal = hourout*60+minin;
	if (hourintotal > houroutotal)
	{
		sumtotal = ((houroutotal - hourintotal)* (24*60));
	}
		else
			sumtotal = houroutotal - hourintotal;
	//Am or Pm condition determined by hours(entered) input.
	if(hourin >= 12)
	{
		hourin = (hourin-12);
			if (hourin == 00)
			{
				hourin = 12;
				amorpm = "AM";
			}
				else
					amorpm = "PM";
	}
		else
			amorpm = "AM";
	//Am or Pm condition determined by hours(exited) input.			
	if(hourout >= 12)
	{
		hourout = (hourout-12);
			if (hourout == 12)
			{
				hourout = 00;
				amorpm = "AM";
			}
				else
					amorpm = "PM";
	}
		else
			amorpm = "AM";
	// sumation of total time for rounding it of to the nearest hour.	
	sumtot = sumtotal;
	// rounded time.	
	roundtotal= sumtot/60;
}
//calcrates() Function Defination
//This function is used to calculate rates of vehicles based on the number of hours parked.
//the calculation is done with the value from calctime() which are passed by reference.
//It's return type is null, but it passes the value of vehicle types and roundtotal.
void calcrates(char vehicle, char trucktype, int roundtotal,double& totaldue)
{
	//local declaration
	//constant defined for calculation
	const double car1strate = 0.00;
	const double car2ndrate = 1.50;
	const double bus1strate = 1.00;
	const double bus2ndrate = 2.50;
	const double truck1strate = 2.00;
	const double truck2ndrate = 3.50;
	//calculation for car rate based on hours the vehicle parked.
	if (vehicle == 'C' || vehicle == 'S' || vehicle == 'V')
	{
		if (roundtotal <= 3)	
		{
			totaldue = (car1strate * roundtotal);
			
		}
			else
			{
				totaldue = (car2ndrate * roundtotal) - (car1strate * roundtotal) ;
			}
	}
	//calculation for bus rate based on hours the vehicle parked.
	if (vehicle == 's' || vehicle == 'B')
	{
		if (roundtotal <= 2)
		{
			totaldue = (bus1strate * roundtotal);
		}
			else
			{
				totaldue = (bus2ndrate * roundtotal) - (bus1strate * roundtotal); 
			}
	}		
	//calculation for truck rate based on hours the vehicle parked.
	if (vehicle == 'l' || vehicle == 'T')
	{
		if (roundtotal <=1)
		{
			totaldue = (truck1strate * roundtotal);
		}
			else
			{
				totaldue = (truck2ndrate * roundtotal) - (truck1strate * roundtotal);
			}
	}
}
//output() Function Defination
//This function is used to output all the output from getvehicleinfo(),gettime(),calctime(),calcrate().
//all the output value are passed by reference from all other function.
//It's return type is null.
void output(char& vehicle, string& type, int& hourin, int& minin, int& hourout, int& minout, int& hourtotal,
			 int& mintotal, string& amorpm, int& roundtotal, double& totaldue)
{ 
	
	cout<<"\n\n"<<setw(50)<<"PASSAIC COUNTY PARKING AUTHORITY\n";
	cout<<setw(44)<<"PARKING LOT CHARGES\n\n";
	cout<<"\tType of Vehicle: "<< type << "\n" << endl;
	cout<<"\tTime-In"<<setw(40) << hourin << ":" <<setfill('0')<<setw(2)<<minin<<setfill(' ') << amorpm << endl;
	cout<<"\tTime-out"<<setw(39) << hourout << ":" <<setfill('0')<<setw(2)<<minout<<setfill(' ') << amorpm << endl;
	cout<<setw(60)<<"________________";
	cout<<"\n\tParking-Time"<<setw(30)<<hourtotal <<"Hrs:"<<mintotal<<"mins"<< endl;
	cout<<"\n\tRounded Parking Time"<<setw(27)<<roundtotal<<"hours"<<endl;
	cout<<setw(60)<<"________________";
	cout<<setiosflags(ios::fixed|ios::showpoint)<<setprecision(2);
	cout<<"\n\tTOTAL DUE"<<setw(39)<<"$"<<totaldue<<endl;
	cout<<"\n\tThank you for using passic county parking Authority"<<endl;
	
}
