#include <iostream>
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
    cout<<"\nRecord Saved to File......\n";
}

int RegisterVehicle()
{
    ofstream fout;
    fout.open("Vehicle.dat",ios::out|ios::app|ios::binary);
    v.set_details();
    fout.write((char*)&v,sizeof(v));
    fout.close();
    cout<<"\nRecord Saved to File......\n";
}

int RenewVehicle()
{
    ifstream fin;
    string number;
    int flag = 0;
    fin.open("Vehicle.dat",ios::out|ios::binary);
    cout<<"Enter registration number: ";
    cin>>number;
    fin.read((char*)&v,sizeof(v));
    if(number==v.get_number())
    {
        v.generate_date();
        flag++;
        cout<<"\n\n...Renewed successful...\n";
    }
    fin.close();
    if(flag==0)
    {
        cout<<"\nThe vehicle with number "<<number<<" not found...\n";
    }
}

int RenewLicense()
{
    ifstream fin;
    string Name,fName,lName;
    int flag = 0;
    fin.open("License.dat",ios::out|ios::binary);
    cout<<"Enter name of driver(fName lName):";
    cin>>fName>>lName;
    Name = fName + " " + lName;
    fin.read((char*)&l,sizeof(l));
    if(Name==l.get_name())
    {
        l.generate_date();
        flag++;
        cout<<"\n\n...Renewed successful...\n";
    }
    fin.close();
    if(flag==0)
    {
        cout<<"\nDriver "<<Name<<" not found...\n";
    }
}


int SearchDriverByName()
{
    ifstream fin;
    int flag=0;
    string name;
    fin.open("License.dat",ios::out|ios::binary);
    cout<<"Enter Name of Driver: ";
    getline(cin,name);
    while(fin.read((char*)&l,sizeof(l)))
    {
        if(name==l.get_name())
        {
            l.show_details();
            flag++;
            cout<<"\n\n.....Record Found and Displayed......\n";
        }
    }
    fin.close();
    if(flag==0)
        cout<<"\nThe Record of Driver "<<name<<" is not in file....\n";
    cout<<"\nReading of Data File Completed......\n";
}


int SearchVehicleByNumber()
{
    ifstream fin;
    int flag=0;
    string number;
    fin.open("Vehicle.dat",ios::out|ios::binary);
    cout<<"Enter Vehicle registration number: ";
    cin>>number;
    while(fin.read((char*)&v,sizeof(v)))
    {
        if(number==v.get_number())
        {
            v.show_details();
            flag++;
            cout<<"\n\n.....Record Found and Displayed......\n";
        }
    }
    fin.close();
    if(flag==0)
        cout<<"\nThe Record of Vehicle with Registration number "<<number<<" is not in file....\n";
        cout<<"\nReading of Data File Completed......\n";
}


int  ShowRecordsVehicle()
{
    ifstream fin;
    cout<<"Showing all registered vehicles\n"
          "-------------------------------\n";
    fin.open("Vehicle.dat",ios::out|ios::binary);
    while(fin.read(reinterpret_cast<char*>(&v),sizeof(v)))
    {
        v.show_details();
    }
    fin.close();
    cout<<"\nReading of Data File Completed......\n";
}

int  ShowRecordsLicense()
{
    ifstream fin;
    cout<<"Showing all licensed drivers\n"
          "----------------------------\n";
    fin.open("License.dat",ios::out|ios::app|ios::binary);
    while(fin.read(reinterpret_cast<char*>(&l),sizeof(l)))
    {
        l.show_details();
    }
    fin.close();
    cout<<"\nReading of Data File Completed......\n";
}



int menu()
{
    do
    {
        char choice;
        cout<<"\t\t\tDVLA REGISTRATION SYSTEM\n"
                "\t\t\t[1] Register New Driver license\n"
                "\t\t\t[2] Register New Vehicle\n"
                "\t\t\t[3] Renew Driver License\n"
                "\t\t\t[4] Renew Vehicle Registration\n"
                "\t\t\t[5] Show Driver Licenses\n"
                "\t\t\t[6] Show Vehicles Registered\n"
                "\t\t\t[7] Quit\n";

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
            case '5': ShowRecordsLicense();
                    break;
            case '6': ShowRecordsVehicle();
                    break;
            case '7': cout<<"\n\t\t\tExiting Application......";
                exit(0);
            default: cout<<"\n\t\t\tBOOM!!!\n"
                        "\t\t\tError occurred.\n";
                        exit(0);
        }

    }
    while(1);
}
