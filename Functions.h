#include <iostream>
#include <stdlib.h>
#include "Apph.h"
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#endif // FUNCTIONS_H_INCLUDED



int RegisterLicense()
{
    ofstream fout;
    fout.open("License.dat",ios::out|ios::app|ios::binary);
    l.set_details();
    fout.write((char*)&l,sizeof(l));
    fout.close();
    cout<<"\n\t\t\tRecord Saved to File......\n";
}

int RegisterVehicle()
{
    ofstream fout;
    fout.open("Vehicle.dat",ios::out|ios::app|ios::binary);
    v.set_details();
    fout.write((char*)&v,sizeof(v));
    fout.close();
    cout<<"\n\t\t\tRecord Saved to File......\n\n";
}

int RenewVehicle()
{
    ifstream fin;
    string number;
    int flag = 0;
    fin.open("Vehicle.dat",ios::out|ios::binary);
    cin.ignore();
    cout<<"\t\t\tEnter registration number: ";
    cin>>number;
    while(fin.read((char*)&v,sizeof(v)))
    {
        if(number==v.get_number())
        {
            v.generate_date();
            flag++;
            cout<<"\n\n\t\t\t...Renewed successful...\n\n";
        }
    }
    fin.close();
    if(flag==0)
    {
        cout<<"\n\t\t\tThe vehicle with number "<<number<<" not found...\n\n";
    }
}

int RenewLicense()
{
    ifstream fin;
    string Name;
    int flag = 0;
    fin.open("License.dat",ios::out|ios::binary);
    cin.ignore();
    cout<<"\t\t\tEnter name of driver(fName lName):";
    getline(cin, Name);
    while(fin.read((char*)&l,sizeof(l)))
    {
        if(Name==l.get_name())
        {
            l.generate_date();
            flag++;
            cout<<"\n\n\t\t\t...Renewed successful...\n\n";
        }
    }
    fin.close();
    if(flag==0)
    {
        cout<<"\n\t\t\tDriver "<<Name<<" not found...\n\n";
    }
}


int SearchDriverByName()
{
    ifstream fin;
    int flag=0;
    string name;
    fin.open("License.dat",ios::out|ios::binary);
    cin.ignore();
    cout<<"\t\t\tEnter Name of Driver: ";
    getline(cin,name);
    while(fin.read((char*)&l,sizeof(l)))
    {
        if(name==l.get_name())
        {
            cout<<"\n\n";
            l.show_details();
            flag++;
        }
    }
    fin.close();
    if(flag==0)
        cout<<"\n\t\t\tThe Record of Driver "<<name<<" is not in file....\n";
}


int SearchVehicleByNumber()
{
    ifstream fin;
    int flag=0;
    string number;
    fin.open("Vehicle.dat",ios::out|ios::binary);
    cin.ignore();
    cout<<"\t\t\tEnter Vehicle registration number: ";
    cin>>number;
    while(fin.read((char*)&v,sizeof(v)))
    {
        if(number==v.get_number())
        {
            cout<<"\n\n";
            v.show_details();
            flag++;
        }
    }
    fin.close();
    if(flag==0)
        cout<<"\n\t\t\tThe Record of Vehicle with Registration number "<<number<<" is not in file....\n\n";
}


int  ShowRecordsVehicle()
{
    ifstream fin;
    cout<<"\n\t\t\tShowing all registered vehicles\n"
          "\t\t\t-------------------------------\n";
    fin.open("Vehicle.dat",ios::out|ios::binary);
    while(fin.read(reinterpret_cast<char*>(&v),sizeof(v)))
    {
        v.show_details();
    }
    fin.close();
}

int  ShowRecordsLicense()
{
    ifstream fin;
    cout<<"\n\t\t\tShowing all licensed drivers\n"
          "\t\t\t----------------------------\n";
    fin.open("License.dat",ios::out|ios::app|ios::binary);
    while(fin.read(reinterpret_cast<char*>(&l),sizeof(l)))
    {
        l.show_details();
    }
    fin.close();
}



int menu()
{
    do
    {
        char wait;
        char choice;
        system("cls");
        cout<<"\t\t\tDVLA REGISTRATION SYSTEM\n"
                "\t\t\t[1] Register New Driver license\n"
                "\t\t\t[2] Register New Vehicle\n"
                "\t\t\t[3] Renew Driver License\n"
                "\t\t\t[4] Renew Vehicle Registration\n"
                "\t\t\t[5] Search for Driver in database\n"
                "\t\t\t[6] Search for Vehicle in database\n"
                "\t\t\t[7] Show all Driver Licenses\n"
                "\t\t\t[8] Show all Vehicles Registered\n"
                "\t\t\t[9] Quit\n";

        cout<<"\t\t\tOption: "; cin>>choice;

        switch(choice)
        {
            case '1': RegisterLicense();
                    break;
            case '2': RegisterVehicle();
                    break;
            case '3': RenewLicense();
                    break;
            case '4': RenewVehicle();
                    break;
            case '5': SearchDriverByName();
                    break;
            case '6': SearchVehicleByNumber();
                    break;
            case '7': ShowRecordsLicense();
                    break;
            case '8': ShowRecordsVehicle();
                    break;
            case '9': cout<<"\n\t\t\tExiting Application......";
                exit(0);
            default: cout<<"\n\t\t\tBOOM!!!\n"
                        "\t\t\tError occurred.\n\n";
                        exit(0);

        }

        system("pause");
    }
    while(1);
}

