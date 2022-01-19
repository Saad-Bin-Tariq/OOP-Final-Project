#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include <cstring>
#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
using namespace std;


class earn
{

public:
    double profit;
    void show()
    {
        ifstream myfile("profit.txt");
        if (!myfile)
            cout << "PROFIT = $0 ";
        else {
            myfile >> profit;
            cout << "\nTOTAL STARTING PROFIT:  $" << profit << endl;
            myfile.close();
        }
    }
    virtual ~earn()
    {

    }
};
class product :public virtual earn
{
public:
    int quantity;
    char name[20];
    char id[20];
    double productcost;
    double productsell;
    double cost;
    double sell;
    void calculate()
    {
        cost = productcost * quantity;
        sell = productsell * quantity;
        profit = profit + (sell - cost);
    }
    void file();
    void get();
    virtual ~product()
    {

    }

};
void product::get()
{
    int numprod;
    cout << "\nNumber of products produced?\n";
    cin >> numprod;
    for (int i = 0; i < numprod; i++)
    {
        cout << "Input product name: \n";
        cin >> name;
        cout << "Input product id: \n";
        cin >> id;
        cout << "Input cost price of product: \n";
        cin >> productcost;
        cout << "\ninput selling price of product: \n";
        cin >> productsell;
        cout << "\ntotal product quantity: \n";
        cin >> quantity;
        calculate();
        file();
        cout << "The product has been added to the stock.\n";
        system("cls");
    }
}


void product::file()
{
    char file[20];
    strcpy_s(file, id);
    strcat_s(file, ".txt");
    ofstream f(file);
    f << "\nProduct name: " << name << "\nProduct id: " << id << "\nCost price of product: $" << productcost << "\nSelling price of product: $" << productsell << "\nQuantity: " << quantity << "\nTotal cost: $" << cost << "\nTotal selling price: $" << sell;
    f.close();
}

class staff :public virtual earn {
protected:
    double salary;
    char empname[12];
    char employeeid[10];
    int postquantity;
    void calculate()
    {
        profit = profit - (salary * postquantity);
    }
    void getemployee();
    void file();
    virtual ~staff()
    {

    }
};


void staff::getemployee()
{
    cout << "Input salary of the employee: \n";
    cin >> salary;
    cout << "Input number of employees: \n";
    cin >> postquantity;
    for (int i = 0; i < postquantity; i++)
    {
        cout << "Enter details for Employee " << i + 1 << endl;
        cout << "Input Employee name\n";
        cin >> empname;
        cout << "Input Employee ID\n";
        cin >> employeeid;
        calculate();
        file();
        system("cls");
    }
}
void staff::file()
{
    char file[20];
    strcpy_s(file, employeeid);
    strcat_s(file, ".txt");
    ofstream f(file);
    f << "\nNumber of working employees: " << postquantity << "\nEmployee salary: $" << salary << "\nEmployee name :" << empname << "\nEmployee ID: " << employeeid;
    f.close();
}

class amount :public staff, public product
{

public:
    void add();
    void update_item();
    void update_emp();
    ~amount()
    {

    }

};
void amount::add()
{
    int opt;
    char name[20];
    while (1)
    {
        cout << "1.)Input for product\n2.)Input for employee\n3.)Exit\n";
        cout << "Enter choice: ";
        cin >> opt;
        if (opt == 1)
        {
            get();
            ofstream myfile("profit.txt");
            myfile << profit;
            myfile.close();
        }
        else if (opt == 2)
        {
            getemployee();
            ofstream myfile("profile.txt");
            myfile << profit;
            myfile.close();
        }
        else if (opt == 3)
            break;
        else
            cout << "Invaid Option. Please re-enter\n";
    }
}


void amount::update_item()
{
    char id[20];
    char pid[20];
    char c;
    cout << "\nInput product ID to modify the item:\n";
    cin >> id;
    char file[20];
    char file2[20];
    strcpy_s(file, id);
    strcat_s(file, ".txt");
    fstream fout(file, ios::in | ios::out);
    if (!fout)
    {
        cout << "File couldn't be opened. product ID not found. \n";
    }
    else {
        cout << "Product has been found! \n";
        cout << "\nUpdate product name: \n";
        cin >> name;
        cout << "\nUpdate per product cost: $\n";
        cin >> productcost;
        cout << "\nUpdate per product sellinf price: $\n";
        cin >> productsell;
        cout << "\nUpdate total product quantity: \n";
        cin >> quantity;
        cost = productcost * quantity;
        sell = productsell * quantity;
        profit = profit + (sell - cost);
        fout << "\nProduct name: " << name << "\nProduct id: " << id << "\nPer prodcut cost: $" << productcost << "\nPer product selling price: $" << productsell << "\nQuantity of product: " << quantity << "\nTotal cost: $" << cost << "\nTotal selling price: $" << sell;
        fout.close();
        system("cls");
    }
}
void amount::update_emp()
{
    char id[20];
    char c;
    cout << "\nInput employee ID to modify employee details: ";
    cin >> id;
    char file[20];
    strcpy_s(file, id);
    strcat_s(file, ".txt");
    fstream fout(file, ios::in | ios::out);
    if (!fout)
    {
        cout << "File couldn't be opened. Product ID not found. \n";
        system("cls");
    }
    cout << "Modify employee name: \n";
    cin >> empname;
    fout << "\nNumber of working employees: " << postquantity << "\nEmployee salary: " << salary << "\nEmployee name :" << empname << "\nEmployee id: " << employeeid;
    fout.close();
    system("cls");
}

void admin()
{
    while (1)
    {
        int option;
        cout << "\n\t\t\t____\n";
        cout << "\n\t\t\tADMIN MENU OF SALES MANAGEMENT SYSTEM \n";
        cout << "\n\t\t\t____\n\n";
        cout << "\n\t\t\t                               \n";
        cout << "\n\t\t\t1- Add Product Entries\n\n\t\t\t2- Show profit\n\n\t\t\t3- Search Product Details\n\n\t\t\t4- Search Employee Details\n\n\t\t\t5- Modify Product Details\n\n\t\t\t6- Modify Employee Details\n\n\t\t\t7- Exit\n";
        cout << "\n\n\t\t\tSelect your choice\n";
        cin >> option;
        system("cls");

        if (option == 1)
        {
            amount* ptr1 = new amount;
            ptr1->show();
            ptr1->add();
            delete ptr1;
            system("cls");

        }
        else if (option == 2)
        {
            amount* ptr2 = new amount;
            ptr2->show();
            delete ptr2;
            system("cls");

        }
        else if (option == 3)
        {
            char id[20];
            char c;
            cout << "\nInput ID to search\n";
            cin >> id;
            char file[20];
            strcpy_s(file, id);
            strcat_s(file, ".txt");
            ifstream myfile(file);
            if (!myfile)
            {
                cout << "File couldn't be opened. product ID not found. \n";
            }
            while (myfile)
            {
                myfile.get(c);
                cout << c;

            }
            myfile.close();
        }
        else if (option == 4)
        {
            char eid[20];
            char d;
            cout << "\nInput employee ID to search\n";
            cin >> eid;
            char file[20];
            strcpy_s(file, eid);
            strcat_s(file, ".txt");
            ifstream myfile2(file);
            if (!myfile2)
            {
                cout << "File couldn't be opened. Employee ID not found. \n";

            }
            while (myfile2)
            {
                myfile2.get(d);
                cout << d;

            }

            myfile2.close();

        }
        else if (option == 5)
        {
            amount* ptr3 = new amount;
            ptr3->update_item();
            delete ptr3;

        }
        else if (option == 6)
        {
            amount* ptr4 = new amount;
            ptr4->update_emp();
            delete ptr4;
        }
        else if (option == 7)
        {
            break;

        }
        else cout << "Invalid option. Please select one of the available options\n";

    }

}

int main()
{
    int choice;
    char  username[20];
    char password[20];
    char pwd[20];
    while (1) {
        cout << "\n \t\t\t ___\n";
        cout << "\n\t\t\    WELCOME TO SALES MANAGEMENT SYSTEM \n";
        cout << "\n \t\t\t ___\n\n";
        cout << "\n \t\t\t                          ";
        cout << "\n\t\t\t  1. ENTER SYSTEM";
        cout << "\n\t\t\t  2. EXIT";
        cout << "\n\t\t\t                            \n";
        cout << "\n\t\t\t Enter Your choice: ";
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            try
            {
                cout << "Enter the password: ";
                for (int z = 0; z < 6; z++)
                {
                    password[z] = _getch();
                    system("cls");
                    cout << "\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
                    for (int i = 1; i <= (z + 1); i++)
                    {
                        cout << "*";
                    }
                }
                if (strcmp(password, "dealer") == 1)
                {
                    system("cls");
                    admin();
                    break;
                }
                else
                {
                    throw "Error: Incorrect Password.";
                }
            }
            catch (string error)
            {
                cout << error;
            }

        case 2:
            exit(0);
            break;
            system("cls");
        default:
            cout << "Enter valid choice\n";
            break;
            system("cls");
        }
    }
    return 0;
}