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

        virtual void generate_number()
        {
            srand((unsigned) time(NULL));
            char alpha[26] = { 'A','B','C','D','E','F','G',
                                'H','I','J','K','L','M','N',
                                'O','P','Q','R','S','T','U',
                                'V','W','X','Y','Z'};

            char num[10] = {'0','1','2','3','4','5','6','7','8','9'};


            string one = "";
            string two = "";
            string three = "";
            string year =to_string(Year);

            for(int i = 0; i<3; i++)
                one = one + alpha[rand()%26];

            for(int i = 0; i<4; i++)
                two = two + num[rand()%10];

            for(int i = 0; i<3; i++)
                three = three + num[rand()%10];




            Number = one + '-' + two + year + '-' + three;
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
            cout<<"Vehicle Details"<<endl;
            cout<<"Vehicle Name: "<<Name<<endl;
            cout<<"Registration No: "<<Number<<endl;
            cout<<"Color: "<<Color<<endl;
            cout<<"Owner: "<<Owner<<endl;
            cout<<"Date Registered: "<<renewal_date<<endl;
            cout<<"Expiring Date: "<<expiring_date<<endl;
            cout<<"\n\n";
         }

        void generate_number()
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


            string three = year.substr(2,3);


            for(int i = 0; i<2; i++)
                one = one + alpha[rand()%26];

            for(int i = 0; i<4; i++)
                two = two + num[rand()%10];


            Number = one + '-' + two +'-'+ three;
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
            cout<<"First Name: "; cin>>fName;
            cout<<"Last Name: "; cin>>lName;
            cout<<"Gender: "; cin>>Gender;
            cout<<"National ID No: "; cin>>Id;
            cout<<"Date of Birth(ddmmyy): "; cin>>DOB;
            Name = fName + " " + lName;
            generate_date();
            generate_number();
        }

        void show_details()
        {

            string fDob = DOB.substr(0,2) + '-' + DOB.substr(2,2) + '-' + DOB.substr(4,7);
            cout<<"License details"<<endl;
            cout<<"Name: "<<Name<<endl;
            cout<<"Gender: "<<Gender<<endl;
            cout<<"Id: "<<Id<<endl;
            cout<<"Date of Birth: "<<fDob<<endl;
            cout<<"Issue Date: "<<renewal_date<<endl;
            cout<<"Expiring Date: "<<expiring_date<<endl;
            cout<<"License No: "<<Number<<endl;
            cout<<"\n\n";
        }


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


         void generate_number()
        {

             srand((unsigned) time(NULL));
            char alpha[26] = { 'A','B','C','D','E','F','G',
                                'H','I','J','K','L','M','N',
                                'O','P','Q','R','S','T','U',
                                'V','W','X','Y','Z'};

            char num[10] = {'0','1','2','3','4','5','6','7','8','9'};


            string one = "";
            string two = "";
            string three = "";
            string year =to_string(Year);

            for(int i = 0; i<2; i++)
                one = one + alpha[rand()%26];
/*
            for(int i = 0; i<4; i++)
                two = two + num[rand()%10];
*/
            for(int i = 0; i<3; i++)
                three = three + num[rand()%10];




            Number = one + '-' + DOB + '-' + three;
        }




}l;

