# include <iostream>
# include <string>
# include <fstream>
# include <unistd.h>


using namespace std;

// create an employee class
class Employee{
    private:
        string firstname;
        string lastname;
        string phone;
        string hireDate;
        string position;
        float salary;
        string  username;
        string password;
    public:
        // employee can login using username and password
        bool login(string username, string password){
            // check if username and password are in the csv file
            fstream file;
            file.open("employee.csv", ios::in);
            string line;
            while(getline(file, line)){
                if(line.find(username) != string::npos && line.find(password) != string::npos){
                    return true;
                    break;
                }
                else{
                    return false;
                    break;
                }
            }
        }

        void registerEmployee(string firstname,string lastname, string phone, string hireDate, string position, float salary, string username, string password){
            this->firstname = firstname;
            this->lastname = lastname;
            this->phone = phone;
            this->hireDate = hireDate;
            this->position = position;
            this->salary = salary;
            this->username = username;
            this->password = password;
            // create a csv file and save to save the details of the employee
            fstream file;
            file.open("employee.csv", ios::app);
            file << firstname<<","<<lastname<< "," << phone << "," << hireDate << "," << position << "," << salary << "," << username << "," << password << endl;
            file.close();
        }

        // create a function to generate a unique product id

        string generate_product_id(){
            string product_id;
            // generate a random number
            int random_number = rand() % 1000;
            // convert the random number to string
            product_id = to_string(random_number);
            return product_id;
        }

        // employee can add a new product
        void add_product(string name, string product_id, float price, int quantity){
           //check if the product id is unique
            fstream file;
            file.open("product.csv", ios::in);
            string line;
            while(getline(file, line)){
                if(line.find(product_id) != string::npos){
                    cout << "Product id already exists" << endl;
                    break;
                }
                else{
                    // create a csv file and save to save the details of the product
                    fstream file;
                    file.open("product.csv", ios::app);
                    file << name << "," << product_id << "," << price << "," << quantity << endl;
                    file.close();
                    break;
                }
            }
        }

        // employee can view all products.
        void view_products(){
            fstream file;
            file.open("product.csv", ios::in);
            string line;
            while(getline(file, line)){
                cout << line << endl;
            }
            file.close();
        }
};

//create a customer class
class Customer{
    private:
        string firstname;
        string lastname;
        string username;
        string password;
    public:
        // customer needs to login
        bool login(string username, string password){
            // check if username and password are in the csv file
            fstream file;
            file.open("customer.csv", ios::in);
            string line;
            while(getline(file, line)){
                if(line.find(username) != string::npos && line.find(password) != string::npos){
                    return true;
                    break;
                }
                else{
                    return false;
                    break;
                }
            }
        }

        // customer can register
        void registerCustomer(string firstname,string lastname, string username, string password){
            this->firstname = firstname;
            this->lastname = lastname;
            this->username = username;
            this->password = password;
            // create a csv file and save to save the details of the customer
            fstream file;
            file.open("customer.csv", ios::app);
            file << firstname<<","<<lastname<< "," << username << "," << password << endl;
            file.close();
        }

        // customer can view all products
        void view_products(){
            fstream file;
            file.open("product.csv", ios::in);
            string line;
            while(getline(file, line)){
                cout << line << endl;
            }
            file.close();
        }

        // customer search for a product
        void search_product(string product_id){
            fstream file;
            file.open("product.csv", ios::in);
            string line;
            while(getline(file, line)){
                if(line.find(product_id) != string::npos){
                    cout << line << endl;
                    break;
                }
                else{
                    cout << "Product not found" << endl;
                    break;
                }
            }
            file.close();
        }

        // customer can make a purchase
        void buy_product(string product_id, int quantity){
            // check if the product is available
            fstream file;
            file.open("product.csv", ios::in);
            string line;
            while(getline(file, line)){
                if(line.find(product_id) != string::npos){
                    // check if the quantity is available
                    int pos = line.find(",");
                    string product_id = line.substr(0, pos);
                    line.erase(0, pos + 1);
                    pos = line.find(",");
                    string name = line.substr(0, pos);
                    line.erase(0, pos + 1);
                    pos = line.find(",");
                    float price = stof(line.substr(0, pos));
                    line.erase(0, pos + 1);
                    pos = line.find(",");
                    int quantity_available = stoi(line.substr(0, pos));
                    line.erase(0, pos + 1);
                    if(quantity_available >= quantity){
                        // create a csv file and save to save the details of the purchase
                        fstream file;
                        file.open("purchase.csv", ios::app);
                        file << product_id << "," << name << "," << price << "," << quantity << endl;
                        file.close();
                        break;
                    }
                    else{
                        cout << "Quantity not available" << endl;
                        break;
                    }
                }
                else{
                    cout << "Product not found" << endl;
                    break;
                }
            }
            file.close();
        }
};


int main(){
    // create instances for the Employee and Customer classes
    Employee employee;
    Customer customer;

    // create a menu for the user to choose from
    cout<<"\n\n\t\t\t\t\t--------------------------------------------"<<endl;
    sleep(.5);
    cout<<"\t\t\t\t\tWelcome to the Supermarket Management System"<<endl;
    sleep(.5);
    cout<<"\t\t\t\t\t--------------------------------------------"<<endl;
    sleep(.5);
    cout<<"[1]Staff Login"<<endl;
    sleep(.5);
    cout<<"[2]Customer Login"<<endl;
    sleep(.5);
    cout<<"[3]Register"<<endl;
    sleep(.5);
    cout<<"[4[Exit"<<endl;
    sleep(.5);
    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;
    system("clear");
    switch(choice){
        case 1:{
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            sleep(.5);
            cout << "Enter password: ";
            cin >> password;
            system("clear");
            sleep(.5);
            bool is_login = employee.login(username, password);
            while(is_login){
                cout << "Login successful" << endl;
                sleep(.5);
                system("clear");
                cout << "[1] Add product" << endl;
                sleep(.5);
                cout << "[2] View products" << endl;
                sleep(.5);
                cout << "[3] Logout" << endl;
                sleep(.5);
                cout << "Enter your choice: ";
                int choice;
                cin >> choice;
                system("clear");
                switch(choice){
                    case 1:{
                        string name;
                        float price;
                        int quantity;
                        cout << "Enter product name: ";
                        cin >> name;
                        cout << "Enter product price: ";
                        cin >> price;
                        cout << "Enter product quantity: ";
                        cin >> quantity;
                        string product_id = employee.generate_product_id();
                        employee.add_product(name, product_id, price, quantity);
                        break;
                    }
                    case 2:{
                        employee.view_products();
                        break;
                    }
                    case 3:{
                        is_login = false;
                        break;
                    }
                    default:{
                        cout << "Invalid choice" << endl;
                        break;
                    }
                }
            }
            break;
        }
        case 2:{
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            bool is_login = customer.login(username, password);
            system("clear");
            while(is_login){
                cout << "Login successful" << endl;
                sleep(.5);
                system("clear");
                cout << "[1] View products" << endl;
                sleep(.5);
                cout << "[2] Search product" << endl;
                sleep(.5);
                cout << "[3] Buy product" << endl;
                sleep(.5);
                cout << "[4] Logout" << endl;
                sleep(.5);
                cout << "Enter your choice: ";
                int choice;
                cin >> choice;
                system("clear");
                switch(choice){
                    case 1:{
                        customer.view_products();
                        break;
                    }
                    case 2:{
                        string product_id;
                        cout << "Enter product id: ";
                        cin >> product_id;
                        customer.search_product(product_id);
                        break;
                    }
                    case 3:{
                        string product_id;
                        int quantity;
                        cout << "Enter product id: ";
                        cin >> product_id;
                        cout << "Enter quantity: ";
                        cin >> quantity;
                        customer.buy_product(product_id, quantity);
                        break;
                    }
                    case 4:{
                        is_login = false;
                        break;
                    }
                    default:{
                        cout << "Invalid choice" << endl;
                        break;
                    }
                }
            }
            break;
        }
        case 3:{
            cout<<"\n\n\t\t\t\t\tREGISTRATION"<<endl;
            sleep(.5);
            cout<<"[1] Register as New Employee"<<endl;
            sleep(.5);
            cout<<"[2] Register as New Customer"<<endl;
            sleep(.5);
            cout<<"[3] Back to Main Menu"<<endl;
            sleep(.5);
            cout<<"Enter your choice: ";
            int choice;
            cin>>choice;
            system("clear");
            switch(choice){
                case 1:{
                    string firstname,lastname,phone,hireDate,position,username,password;
                    float salary;
                    cout << "Enter First name: ";
                    cin>>firstname;
                    cout << "Enter Last name: ";
                    cin>>lastname;
                    cout << "Enter phone: ";
                    cin>>phone;
                    cout << "Enter hire date(DD/MM/YYYY): ";
                    cin>>hireDate;
                    cout << "Enter position: ";
                    cin>>position;
                    cout << "Enter salary: ";
                    cin >> salary;
                    cout << "Enter username: ";
                    cin >> username;
                    cout << "Enter password: ";
                    cin >> password;
                    employee.registerEmployee(firstname,lastname, phone, hireDate, position, salary, username, password);
                    cout << "Registration successful" << endl;
                    break;
                }
                case 2:{
                    string firstname,lastname,username, password;
                    cout << "Enter name: ";
                    cin>>firstname;
                    cout << "Enter Last name: ";
                    cin>>lastname;
                    cout << "Enter username: ";
                    cin >> username;
                    cout << "Enter password: ";
                    cin >> password;
                    customer.registerCustomer(firstname,lastname,username, password);
                    break;
                }
                case 3:{
                    break;
                }
                default:{
                    cout << "Invalid choice" << endl;
                    break;
                }
            }
            break;
        }
    }


}