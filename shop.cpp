#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>

using namespace std;
// declare a buy product function
void buy_product();
// declare an employee function
void funct_emp();

// declare customer function
void customer();

// declare a function to generate a random employee id
string employee_id();

class employee{

    private:
    string first_name;
    string last_name;
    string id;
    string password;
    string position;

    public:
    void register_employee(string emp_firstname,string emp_lastname, string emp_id, string pass, string emp_pos){
        // staff can register new employee
        // assign values to private variables
        first_name = emp_firstname;
        last_name = emp_lastname;
        id = emp_id;
        password = pass;
        position = emp_pos;
        cout<<"Employee registered successfully"<<endl;

        // write to file
        fstream file;
        file.open("employee.txt", ios::out | ios::app);
        file<<first_name<<","<<last_name<<","<<id<<","<<password<<","<<position<<endl;
        file.close();
    }
    void check_products(){
        // staff can check products
        // read from file

        fstream file;
        file.open("products.txt", ios::in);
        string line;
        while(getline(file, line)){
            cout<<line<<endl;
        }
        file.close();

    }

    void add_product(string product_id, string product_name, string product_price, string product_quantity){
        // staff can buy products from dealer
        // bought products need to be added to the product list

        // open file to add new product
        fstream file;
        file.open("products.txt", ios::out | ios::app);
        
        // write the product details to the file
        file << product_id << "," << product_name << "," << product_price << "," << product_quantity << endl;

        // close the file
        file.close();

        cout << "Product added successfully." << endl;
    }

    void sales(){
        float daily_sales = 0;
        // staff can check daily sales
        // read from file
        fstream file;
        file.open("sales.txt", ios::in);
        string line;
        while(getline(file, line)){
            cout<<line<<endl;
        }
        file.close();
        
    }
};

// create a customer class
class Customer{
    private:
    string username;
    string password;

    public:

    void buy_product(){
        // customer can buy product from the product list
    }

    // create a search product function
    void search_product(string product_name){
        // open the product.txt file and search for the product
        fstream file;
        
    }

    

};


// main function
int main(){
    // shop management system
    int option;
    sleep(.5);
    cout<<"\n\n\t\t\t\tWelcome to shop management system"<<endl;
    sleep(.5);
    cout<<"\t\t\t\t--------------------------------"<<endl;
    sleep(.5);
    cout<<"\n\n1. Staff"<<endl;
    sleep(.5);
    cout<<"2. Customer"<<endl;
    sleep(.5);
    cout<<"Enter an option: ";

    //take input from user
    cin>>option;
    system("clear");
    if(option==1){
        // staff
        funct_emp();
    }else if(option==2){
        // customer
        customer();
    }else{
        cout<<"\n\t\t\t\t\tInvalid option"<<endl;
    }

}

// create an employee function
void funct_emp(){
    // staff can register new employee
    // check products
    // buy products from dealer
    // sales
    int response;
    employee emp;
    cout<<"\t\t\t\t\tStaff"<<endl;
    cout<<"\t\t\t\t\t------"<<endl;

    // employee can login
    string emp_id, emp_pass;
    cout<<"Enter employee id: ";
    cin>>emp_id;
    cout<<"Enter password: ";
    cin>>emp_pass;

    // check if the employee id and password are in the employee.txt file
    fstream file;
    file.open("employee.txt", ios::in);
    string line;
    while(getline(file, line)){
        if(line.find(emp_id) != string::npos && line.find(emp_pass) != string::npos){
            cout<<"Login successful"<<endl;
            sleep(1);
            system("clear");
            
            cout<<"1. Register new employee"<<endl;
            cout<<"2. Check products"<<endl;
            cout<<"3. Buy products"<<endl;
            cout<<"4. Sales"<<endl;
            cout<<"5. Exit"<<endl;
            cout<<"Enter an option: ";
            cin>>response;
            system("clear");
            if(response==1){
                // register new employee
                string emp_firstname, emp_lastname, emp_id, pass, emp_pos;
                cout<<"\t\t\t\tRegister new employee"<<endl;
                cout<<"\t\t\t\t---------------------"<<endl;
                cout<<"Enter first name: ";
                cin>>emp_firstname;
                cout<<"Enter last name: ";
                cin>>emp_lastname;
                cout<<"Enter position: ";
                cin>>emp_pos;
                cout<<"Enter password: ";
                cin>>pass;
                emp.register_employee(emp_firstname, emp_lastname, employee_id(), pass, emp_pos);
                cout<<"Press enter to continue";
                cin.ignore();
                cin.get();
                system("clear");
            }else if(response==2){
                // check products
                emp.check_products();
                cout<<"Press enter to continue";
                cin.ignore();
                cin.get();
                system("clear");
            }else if(response==3){
                // buy products
                string product_id, product_name, product_price, product_quantity;
                cout<<"\t\t\t\tBuy products"<<endl;
                cout<<"\t\t\t\t-------------"<<endl;
                cout<<"Enter product id: ";
                cin>>product_id;
                cout<<"Enter product name: ";
                cin>>product_name;
                cout<<"Enter product price: ";
                cin>>product_price;
                cout<<"Enter product quantity: ";
                cin>>product_quantity;
                emp.add_product(product_id, product_name, product_price, product_quantity);
                cout<<"Press enter to continue";
                cin.ignore();
                cin.get();
                system("clear");
            }else if(response==4){
                // sales
                emp.sales();
                cout<<"Press enter to continue";
                cin.ignore();
                cin.get();
                system("clear");
            }else if(response==5){
                // exit
                cout<<"Exiting..."<<endl;
                exit(0);
            }else{
                cout<<"\n\t\t\t\t\tInvalid option"<<endl;
            }
        }
    }

}

string employee_id(){
    // this function generates a random employee id to assigned to each employee
    // first employee id is 1000
    // last employee id is 9999
    string emp_id;
    int id = rand() % 9999 + 1000;
    emp_id = to_string(id);
    return emp_id;
}


