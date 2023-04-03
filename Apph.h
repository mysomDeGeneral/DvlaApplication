#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <cstdlib>

#ifndef APPH_H_INCLUDED
#define APPH_H_INCLUDED



#endif

using namespace std;


class DvlaRegistration
{
    protected:
        string expiring_date;
        string renewal_date;
        string Number;
        string Name;
        int Year;


    public:
        /*
        This function uses the system time to generate date for the registration
        Renewal date is set to the date on which the registration was made
        Expiring date is set to five(5) years plus the date on which registration was made
        */
        void generate_date()
        {
            int year, month, day;

            time_t now = time(0);
            tm *ltm = localtime(&now);
            year = 1900 + ltm->tm_year;
            month = 1+ ltm->tm_mon;
            day = ltm->tm_mday;
            int xyear = year + 5;

            renewal_date = to_string(year) + '-' + to_string(month) + '-' + to_string(day);
            expiring_date = to_string(xyear) + '-' + to_string(month) + '-' + to_string(day);

        }
        /*
        This function computes the registration number using a combination of three(3) strings
        First part of the number is a 2-letter word from a random selection of the 26 English alphabets
        Second part is a 4-letter word from the random selection of the digits 0-9
        Third part is the a slice of the last 2 digits of the year of registration
        All three parts are joined with a hyphen(-) to form the registration number
        */

        virtual void generate_number()
        {

            srand((unsigned) time(NULL));
            char alpha[26] = { 'A','B','C','D','E','F','G',
                                'H','I','J','K','L','M','N',
                                'O','P','Q','R','S','T','U',
                                'V','W','X','Y','Z'};

            char num[10] = {'0','1','2','3','4','5','6','7','8','9'};

            time_t now = time(0);
            tm *ltm = localtime(&now);
            Year = 1900 + ltm->tm_year;

            string one = "";
            string two = "";
            string year = to_string(Year);


            string three = year.substr(2,3);         //getting the last 2 digits of the year of registration


            for(int i = 0; i<2; i++)                //generates 2-letter word of alphabets
                one = one + alpha[rand()%26];

            for(int i = 0; i<4; i++)                //generates 4-letter word of numbers
                two = two + num[rand()%10];


            Number = one + '-' + two +'-'+ three;
        }


};

class VehicleRegistration :public DvlaRegistration
{
    private:
        string Color;
        string fName;
        string lName;
        string Brand;
        string Model;
        string Owner;


    public:
       /* VehicleRegistration(string brand, string model): Brand(brand), Model(model)
        {}
        */
        void set_details()
        {
            cout<<"Brand: "; cin>>Brand;
            cout<<"Model: "; cin>>Model;
            cout<<"Color: "; cin>>Color;
            cout<<"Owner(fName LName): "; cin>>fName>>lName;
            Name = Brand + " " + Model;
            Owner = fName + " " + lName;
            generate_date();
            generate_number();
        }

         void show_details()
         {

            cout<<"\t\t\tVehicle Name: "<<Name<<endl;
            cout<<"\t\t\tRegistration No: "<<Number<<endl;
            cout<<"\t\t\tColor: "<<Color<<endl;
            cout<<"\t\t\tOwner: "<<Owner<<endl;
            cout<<"\t\t\tDate Registered: "<<renewal_date<<endl;
            cout<<"\t\t\tExpiring Date: "<<expiring_date<<endl;
            cout<<"\n\n";
         }


        string get_number()
        {return Number;}

}v;




class LicenseRegistration : public DvlaRegistration
{
    private:
        string Gender;
        string DOB;
        string Id;
        string fName;
        string lName;




    public:
       /* LicenseRegistration(string name, string gender, int age):Name(name), Gender(gender), Age(age)
            {}

        */

        string get_name()
        {return Name;}

        void set_details()
        {
            cout<<"\t\t\tFirst Name: "; cin>>fName;
            cout<<"\t\t\tLast Name: "; cin>>lName;
            cout<<"\t\t\tGender: "; cin>>Gender;
            cout<<"\t\t\tNational ID No: "; cin>>Id;
            cout<<"\t\t\tDate of Birth(ddmmyyyy): "; cin>>DOB;
            Name = fName + " "+ lName;
            generate_date();
            generate_number();
        }

        void show_details()
        {

            string fDob = DOB.substr(0,2) + '-' + DOB.substr(2,2) + '-' + DOB.substr(4,7); //formats the input DOB input dd-mm-yyyy using slicing

            cout<<"\t\t\tName: "<<Name<<endl;
            cout<<"\t\t\tGender: "<<Gender<<endl;
            cout<<"\t\t\tId: "<<Id<<endl;
            cout<<"\t\t\tDate of Birth: "<<fDob<<endl;
            cout<<"\t\t\tIssue Date: "<<renewal_date<<endl;
            cout<<"\t\t\tExpiring Date: "<<expiring_date<<endl;
            cout<<"\t\t\tLicense No: "<<Number<<endl;
            cout<<"\n\n";
        }

/*
        void generate_date()
        {
            int year, month, day;

            time_t now = time(0);
            tm *ltm = localtime(&now);
            year = 1900 + ltm->tm_year;
            month = 1+ ltm->tm_mon;
            day = ltm->tm_mday;
            int xyear = year + 5;

            Year = year;




            renewal_date = to_string(year) + '-' + to_string(month) + '-' + to_string(day);
            expiring_date = to_string(xyear) + '-' + to_string(month) + '-' + to_string(day);

        }
*/

        /*
        This function overrides the one in the base class
        Its first part is a 2-letter word of the 26 English alphabets
        The second part is the date of birth of the driver
        The third part is a 3-letter word from the digits 0-9
        */
         void generate_number()
        {

             srand((unsigned) time(NULL));
            char alpha[26] = { 'A','B','C','D','E','F','G',
                                'H','I','J','K','L','M','N',
                                'O','P','Q','R','S','T','U',
                                'V','W','X','Y','Z'};

            char num[10] = {'0','1','2','3','4','5','6','7','8','9'};


            string one = "";
            string three = "";
            string year =to_string(Year);

            for(int i = 0; i<2; i++)                //generates 2-letter word of alphabets
                one = one + alpha[rand()%26];

            for(int i = 0; i<3; i++)                //generates 3-letter word of numbers
                three = three + num[rand()%10];


            Number = one + '-' + DOB + '-' + three;
        }




}l;

