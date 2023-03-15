#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>

using namespace std;

// declare an employee function
void funct_emp();

// declare customer function
void customer();

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
};



// main function
int main(){
    // shop management system
    int option;
    sleep(1);
    cout<<"\n\n\t\t\t\tWelcome to shop management system"<<endl;
    sleep(1);
    cout<<"\t\t\t\t--------------------------------"<<endl;
    sleep(1);
    cout<<"\t\t\t\t\t1. Staff"<<endl;
    sleep(1);
    cout<<"\t\t\t\t\t2. Customer"<<endl;
    sleep(1);
    cout<<"\n\t\t\t\t\tEnter an option: ";

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

    sleep(1);
    cout<<"\n\t\t\t\t\t1. Register new employee"<<endl;
    sleep(1);
    cout<<"\t\t\t\t\t2. Check products"<<endl;
    sleep(1);
    cout<<"\t\t\t\t\t3. Add Product"<<endl;
    sleep(1);
    cout<<"\t\t\t\t\t4. Sales"<<endl;
    sleep(1);
    cout<<"\n\t\t\t\t\tEnter an option: ";

    // take input from user
    cin>>response;
    system("clear");
    if(response==1){
        // register new employee
        string emp_firstname,emp_lastname, emp_id, pass, emp_pos;
        sleep(1);
        cout<<"First Name: ";
        cin>>emp_firstname;
        sleep(1);
        cout<<"Last Name: ";
        cin>>emp_lastname;
        sleep(1);
        cout<<"Id: ";
        cin>>emp_id;
        sleep(1);
        cout<<"Password: ";
        cin>>pass;
        sleep(1);
        cout<<"Position/Occupation: ";
        cin>>emp_pos;
        emp.register_employee(emp_firstname,emp_lastname, emp_id, pass, emp_pos);
        
    }else if(response==2){
        // check products
        emp.check_products();
    }else if(response==3){
        // buy from dealer
        string product_id, product_name, product_price, product_quantity;
        
        sleep(1);
        cout<<"Enter product details to add to the list"<<endl;
        sleep(1);
        cout<<"Product Id: ";
        cin>>product_id;
        sleep(1);
        cout<<"Product Name: ";
        cin>>product_name;
        sleep(1);
        cout<<"Product Price: ";
        cin>>product_price;
        sleep(1);
        cout<<"Product Quantity: ";
        cin>>product_quantity;
        emp.add_product(product_id, product_name, product_price, product_quantity);
    } else if(response==4){
        // sales
    }else{
        cout<<"\n\t\t\t\t\tInvalid option"<<endl;
    }
}

void customer(){
    // customer can buy from the show 
    // customer can view products to make a purchase 
    // customer can search a product
    int response;
    cout<<"\t\t\t\tCustomer"<<endl;
    cout<<"\t\t\t\t----------"<<endl;
    cout<<"\t\t\t\t1. View product list"<<endl;
    cout<<"\t\t\t\t2.Search product"<<endl;

    //take response from user
    cin>>response;
    system("clear");

    if(response==1){
        // view product list
        cout<<"\t\t\t\tProduct List"<<endl;
    }
    else if(response==2){
        // search product
        cout<<"\t\t\t\tSearch Product"<<endl;
    }
    else{
        cout<<"\n\t\t\t\t\tInvalid option"<<endl;
    }
}
