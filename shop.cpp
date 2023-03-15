#include <iostream>
#include <string>
#include <fstream>

using namespace std;

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
        // bought products need to be add to the product list
        // read from file
        fstream file;
        // open file add new product
        file.open("products.txt", ios::out | ios::app);
    
};

// declare an employee function
void employee_funct();

// declare customer function
void customer();

// main function
int main(){
    // shop management system
    int option;
    cout<<"\n\n\t\t\t\tWelcome to shop management system"<<endl;
    cout<<"\t\t\t\t--------------------------------"<<endl;
    cout<<"\t\t\t\t\t1. Staff"<<endl;
    cout<<"\t\t\t\t\t2. Customer"<<endl;
    cout<<"\n\t\t\t\t\tEnter an option: ";

    //take input from user
    cin>>option;
    system("clear");
    if(option==1){
        // staff
        employee_funct();
    }else if(option==2){
        // customer
        // customer();
    }else{
        cout<<"\n\t\t\t\t\tInvalid option"<<endl;
    }

}

// create an employee function
void employee_funct(){
    // staff can register new employee
    // check products
    // buy products from dealer
    // sales
    int response;
    employee emp;

    cout<<"\n\t\t\t\t\t1. Register new employee"<<endl;
    cout<<"\t\t\t\t\t2. Check products"<<endl;
    cout<<"\t\t\t\t\t3. Add Product"<<endl;
    cout<<"\t\t\t\t\t4. Sales";
    cout<<"\n\t\t\t\t\tEnter an option: ";

    // take input from user
    cin>>response;
    system("clear");
    if(response==1){
        // register new employee
        string emp_firstname,emp_lastname, emp_id, pass, emp_pos;
        cout<<"First Name: ";
        cin>>emp_firstname;
        cout<<"Last Name: ";
        cin>>emp_lastname;
        cout<<"Id: ";
        cin>>emp_id;
        cout<<"Password: ";
        cin>>pass;
        cout<<"Position/Occupation: ";
        cin>>emp_pos;
        emp.register_employee(emp_firstname,emp_lastname, emp_id, pass, emp_pos);
        
    }else if(response==2){
        // check products
        emp.check_products();
    }else if(response==3){
        // buy from dealer
        string product_id, product_name, product_price, product_quantity;

        cout<<"Enter product details to add to the list"<<endl;
        cout<<"Product Id: ";
        cin>>product_id;
        cout<<"Product Name: ";
        cin>>product_name;
        cout<<"Product Price: ";
        cin>>product_price;
        cout<<"Product Quantity: ";
        cin>>product_quantity;
        emp.add_product(product_id, product_name, product_price, product_quantity);
    } else if(response==4){
        // sales
    }else{
        cout<<"\n\t\t\t\t\tInvalid option"<<endl;
    }
}

// void customer(){
//     // customer can buy from the show 
//     // customer can view products to make a purchase 
//     // customer can search a product
//     int response;
//     cout<<"\t\t\t\tCustomer"<<endl;
//     cout<<"\t\t\t\t----------"<<endl;
//     cout<<"\t\t\t\t1. View product list"<<endl;
//     cout<<"\t\t\t\t2.Search product"<<endl;

//     //take response from user
//     cin>>response;
//     system("clear");

//     // if(response==1){
//     //     // view product list
//     // }
//     // else if(response==2){
//     //     // search product
//     // }
//     // else{
//     //     cout<<"\n\t\t\t\t\tInvalid option"<<endl;
//     // }
// }
