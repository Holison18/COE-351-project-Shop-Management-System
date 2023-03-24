#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>

using namespace std;
// declare a buy product function
void buy_product();
// declare an employee function
void funct_emp();


// declare a function to generate a random employee id
string employee_id();

class employee{

    private:
    string Username = "Admin";
    string password = "admin@coe";
    string name;
    string emp_id;
    string position;

    public:
    
    // Create a login function
    bool login(string Name,string Password){
        //compare name and password with the admin name and password
        if(Name == Username && Password == password){
            return true;
        }
        else{
            return false;
        }
    }

    // a functions to register a new employee
    void register_employee(string first_name,string last_name,string Position,string emp_id){
        // open the employee.txt file to add the new employee
        fstream file;
        file.open("employee.txt", ios::out | ios::app);
        file<<first_name<<" | "<<last_name<<" | "<<Position<<" | "<<emp_id<<endl;
        file.close();
    }

    void check_products(){
        // staff can check the products
        // read from file
        fstream file;
        file.open("products.txt", ios::in);
        string line;
        while(getline(file, line)){
            cout<<line<<endl;
        }
        file.close();
    }
    

    void add_product(string product_id, string product_name, float product_price, int product_quantity){
        // staff can buy products from dealer
        // bought products need to be added to the product list

        // open file to add new product
        fstream file;
        file.open("products.txt", ios::out | ios::app);
        
        // write the product details to the file
        file << product_id << " | " << product_name << " | " << product_price << " | " << product_quantity << endl;

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
    string name;

    public:
    void login(){
        // customer can login
        // check if the username and password are in the customer.txt file
        fstream file;
        file.open("customer.txt", ios::in);
        string line;
        while(getline(file, line)){
            if(line.find(username) != string::npos && line.find(password) != string::npos){
                cout<<"Login successful"<<endl;
            }
        }
        file.close();
    }

    void register_customer(string Name,string Username,string Password){
        name = Name;
        username = Username;
        password = Password;

        fstream file;
        file.open("customer.txt", ios::out | ios::app);
        file<<name<<","<<password<<endl;
        file.close();
        cout<<"Customer registered successfully"<<endl;
    }

    void buy_product(){
        // customer can buy product from the product list   
        string product_id;
        float product_price;
        int product_quantity;

        // get the product id from the user
        cout << "Enter product id: ";
        sleep(.5);
        cin >> product_id;
        cout<<"Enter price of the product: ";
        sleep(.5);
        cin>>product_price;
        cout<<"Enter quantity of the product: ";
        sleep(.5);
        cin>>product_quantity;

        // add sales to the sales.txt file
        fstream file;
        file.open("sales.txt", ios::out | ios::app);
        file << product_id << "," << product_price << "," << product_quantity << endl;
        file.close();

        // decrease the quantity of the product in the product.txt file
        fstream file2;
        file2.open("products.txt", ios::in);
        string line;
        while(getline(file2, line)){
            if(line.find(product_id) != string::npos){
                // get the quantity of the product
                int quantity = stoi(line.substr(line.find_last_of(",") + 1));
                // decrease the quantity
                quantity -= product_quantity;
                // write the new quantity to the file
                file2 << product_id << "," << product_price << "," << quantity << endl;
            }
        }
        file2.close();

        system("clear");
        sleep(.5);
        cout << "Product bought successfully." << endl;
        system("clear");
        
        sleep(.5);
        // print receipt
        cout << "Receipt" << endl;
        cout << "-------" << endl;
        sleep(.5);
        cout << "Product id: " << product_id << endl;
        sleep(.5);
        cout << "Price: " << product_price << endl;
        sleep(.5);
        cout << "Quantity: " << product_quantity << endl;
        sleep(.5);
        cout << "Total: " << product_price * product_quantity << endl;

    }

    // create a search product function
    void search_product(string product_name){
        // open the product.txt file and search for the product
        fstream file;
        file.open("products.txt", ios::in);
        string line;
        while(getline(file, line)){
            if(line.find(product_name) != string::npos){
                // print the line of the product if it is found
                cout << line << endl;
            }
        }
        file.close();
        
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
    // instantiate the class employee
    employee emp;
    
    cout<<"\n\n\t\t\t\t\tLogin"<<endl;
    // employee can login
    string admin_username, admin_pass;
    cout<<"Username: ";
    cin>>admin_username;
    cout<<"Password: ";
    cin>>admin_pass;

    // call the login function in the employee class
    bool is_login = emp.login(admin_username, admin_pass);

    // check if the right details were provided then proceed
    while(is_login){
        cout<<"Login Successful"<<endl;
        sleep(.5);
        system("clear");
        int option;
        cout<<"\n\n\t\t\t\t\tStaff"<<endl;
        cout<<"1. Register new employee"<<endl;
        cout<<"2. Check products"<<endl;
        cout<<"3. Add Product"<<endl;
        cout<<"4. Sales"<<endl;
        cout<<"5. Logout"<<endl;
        cout<<"Enter an option: ";
        cin>>option;
        system("clear");
        if(option==1){
            // register new employee
            string first_name,last_name, position, emp_id;
            cout<<"\n\n\t\t\t\t\tRegister new employee"<<endl;
            cout<<"Enter first name: ";
            cin>>first_name;
            cout<<"Enter last name: ";
            cin>>last_name;
            cout<<"Enter position: ";
            cin>>position;
            // generate employee id
            emp_id = employee_id();
            // call the register employee function
            emp.register_employee(first_name,last_name, position, emp_id);
            cout<<"Employee Registered Successful"<<endl;
            sleep(1);
            system("clear");
        }else if(option==2){
            // check products
            cout<<"\n\n\t\t\t\t\tProducts"<<endl;
            // call the check products function
            emp.check_products();
            cout<<"Press enter to continue: ";
            cin.ignore();
            system("clear");
        }else if(option==3){
            // add product
            string product_name, product_id;
            float product_price;
            int product_quantity;
            cout<<"\n\n\t\t\t\t\tAdd Product"<<endl;
            cout<<"Enter product name: ";
            cin>>product_name;
            cout<<"Enter product id: ";
            cin>>product_id;
            cout<<"Enter product price: ";
            cin>>product_price;
            cout<<"Enter product quantity: ";
            cin>>product_quantity;
            // call the add product function
            emp.add_product(product_name, product_id, product_price, product_quantity);
            sleep(.5);
            system("clear");
        }else if(option==4){
            // sales
            cout<<"\n\n\t\t\t\t\tSales"<<endl;
            // call the sales function
            emp.sales();
            sleep(.5);
            system("clear");
        }else if(option==5){
            // logout
            cout<<"\n\n\t\t\t\t\tLogout"<<endl;
            sleep(.5);
            system("clear");
            is_login = false;
            main();
        }else{
            cout<<"Login Failed"<<endl;
            cout<<"Try again"<<endl;
            sleep(.5);
            system("clear");
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


