/*
#include "Apph.h"

int menu();
int RegisterLicense(string name, string gender,string id, string dob);
int RegisterVehicle(string brand, string model, string owner);
int RenewLicense();
int RenewVehicle();
int Show_Records_Vehicle();
int Show_Records_License();
int SearchDriverByName();
int SearchVehicleByNumber();
int ChangeDate();

int RegisterLicense(string name,string gender,string id, string dob)
{
    ofstream fout;
    fout.open("License.txt",ios::out|ios::app);
    l.set_details(name,gender,id,dob);
    fout.write(reinterpret_cast<char*>(&l),sizeof(l));
    fout.close();
    cout<<"\nRecord Saved to File......\n";
}

int RegisterVehicle(string brand,string model,string owner)
{
    ofstream fout;
    fout.open("Vehicle.dat",ios::out|ios::app|ios::binary);
    v.set_details(brand,model,owner);
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
    cout<<"Enter plate number vehicle to renew: ";
    cin>>number;
    fin.read((char*)&v,sizeof(v));
    if(number==v.get_number())
    {
        v.generate_date();
        flag++;
        cout<<"\n\n...Renewed successful...\n";
        v.show_details();
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
    string name;
    int flag = 0;
    fin.open("License.dat",ios::out|ios::binary);
    cout<<"Enter name of Driver to renew license: ";
    getline(cin, name);
    fin.read((char*)&l,sizeof(l));
    if(name==l.get_name())
    {
        l.generate_date();
        flag++;
        cout<<"\n\n...Renewed successful...\n";
        l.show_details();
    }
    fin.close();
    if(flag==0)
    {
        cout<<"\nDriver "<<name<<" not found...\n";
    }
}
/*
int ChangeDate()
{
    ifstream fin;
    string number;
    int flag = 0;
    fin.open("Vehicle.dat",ios::out|ios::binary);
    cout<<"Enter vehicle number to change date: ";
    cin>>number;
    fin.read((char*)&v,sizeof(v));
    if(number==v.get_number())
    {
        //v.show_details();
        v.change();
        flag++;
        cout<<"\n\n...Renewed successful...\n";
        v.show_details();
    }
    fin.close();
    if(flag==0)
    {
        cout<<"\nThe vehicle with number "<<v.get_number()<<" not found...\n";
    }
}


int SearchDriverByName()
{
    ifstream fin;
    int flag=0;
    string name;
    fin.open("License.dat",ios::out|ios::binary|ios::app);
    cout<<"Enter Name of Driver to search: ";
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
        cout<<"\nThe Record of Driver "<<l.get_name()<<" is not in file....\n";
    cout<<"\nReading of Data File Completed......\n";
}


int SearchVehicleByNumber()
{
    ifstream fin;
    int flag=0;
    string number;
    fin.open("Vehicle.dat",ios::out|ios::binary|ios::app);
    cout<<"Enter Plate Number of Vehicle to search: ";
    getline(cin,number);
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
        cout<<"\nThe Record of Vehicle with Registration number "<<v.get_number()<<" is not in file....\n";
    cout<<"\nReading of Data File Completed......\n";
}


int  Show_Records_Vehicle()
{
    ifstream fin;
    fin.open("Vehicle.dat",ios::out|ios::binary);
    while(fin.read(reinterpret_cast<char*>(&v),sizeof(v)))
    {
        v.show_details();
    }
    fin.close();
    cout<<"\nReading of Data File Completed......\n";
}

int  Show_Records_License()
{
    ifstream fin;
    fin.open("License.txt",ios::out|ios::app);
    while(fin.read(reinterpret_cast<char*>(&l),sizeof(l)))
    {
        l.show_details();
    }
    fin.close();
    cout<<"\nReading of Data File Completed......\n";
}



int menu()
{
    string name,gender,model,brand,owner,id,dob;
    do
    {
        char choice;
        cout<<"\t\t\tDVLA REGISTRATION SYSTEM\n"
                "\t\t\t[1] Register New Driver license\n"
                "\t\t\t[2] Register New Vehicle\n"
                "\t\t\t[3] Renew Driver License\n"
                "\t\t\t[4] Renew Vehicle Registration\n"
                "\t\t\t[5] Quit\n";

        cout<<"\t\t\tOption: "; cin>>choice;

        switch(choice)
        {
            case '1': RegisterLicense(name,gender,id,dob);
                    break;
            case '2': RegisterVehicle(brand,model,owner);
                    break;
            case '3': RenewLicense();
                    break;
            case '4': RenewVehicle();
                    break;
            case '5': cout<<"\n\t\t\tShutting down......";
                exit(0);
            default: cout<<"\n\t\t\tBOOM!!!\n"
                        "\t\t\tError occurred.\n";
                        exit(0);
        }

    }
    while(1);
}
*/
