# include <iostream>
# include <string>
# include <cstdlib>
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
            bool flag = false;
            while(getline(file, line)){
                if(line.find(username) != string::npos && line.find(password) != string::npos){
                    flag = true;
                    break;
                }
            }
            return flag;
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
        void add_product(string name, string product_id, float price, int quantity) {
            // Validate input
            if (name.empty() || product_id.empty()) {
                cout << "Name and product ID must not be empty" << endl;
                return;
            }

            // Check if the product id is unique
            fstream input_file;
            input_file.open("product.csv", ios::in);
            if (!input_file.is_open()) {
                cout << "Error: could not open input file" << endl;
                return;
            }
            string line;
            bool id_exists = false;
            while (getline(input_file, line)) {
                if (line.find(product_id) != string::npos) {
                    cout << "Product id already exists" << endl;
                    id_exists = true;
                    break;
                }
            }
            input_file.close();

            if (id_exists) {
                // Delete all other entries and update the product price
                fstream output_file;
                output_file.open("product.csv", ios::out | ios::trunc);
                if (!output_file.is_open()) {
                    cout << "Error: could not open output file" << endl;
                    return;
                }
                try {
                    output_file << name << "," << product_id << "," << price << "," << quantity << endl;
                    output_file.close();
                } catch (const exception& e) {
                    cout << "Error: " << e.what() << endl;
                    output_file.close();
                    return;
                }
            } else {
                // Create a csv file and save the details of the product
                fstream output_file;
                output_file.open("product.csv", ios::app);
                if (!output_file.is_open()) {
                    cout << "Error: could not open output file" << endl;
                    return;
                }
                try {
                    output_file << name << "," << product_id << "," << price << "," << quantity << endl;
                    output_file.close();
                } catch (const exception& e) {
                    cout << "Error: " << e.what() << endl;
                    output_file.close();
                    return;
                }
            }
        }





        // employee can view all products.
        void view_products() {
            fstream file;
            file.open("product.csv", ios::in);
            string line;
            if (!getline(file, line)) {
                cout << "No products found" << endl;
            } else {
                cout << line << endl;
                while (getline(file, line)) {
                    cout << line << endl;
                }
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
            bool flag = false;
            while(getline(file, line)){
                if(line.find(username) != string::npos && line.find(password) != string::npos){
                    flag = true;
                    break;
                }
            }
            return flag;
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
        void view_products() {
            fstream file;
            file.open("product.csv", ios::in);
            string line;
            if (!getline(file, line)) {
                cout << "No products found" << endl;
            } else {
                cout << line << endl;
                while (getline(file, line)) {
                    cout << line << endl;
                }
            }
            file.close();
        }


        // customer search for a product
        void search_product(string product_name){
            fstream file;
            file.open("product.csv", ios::in);
            string line;
            bool product_found = false;
            while(getline(file, line)){
                if(line.find(product_name) != string::npos){
                    cout << line << endl;
                    product_found = true;
                }
            }
            file.close();

            if(!product_found){
                cout << "Product not found" << endl;
            }
        }



        // customer can make a purchase
        void buy_product(string product_id, int quantity){
            // check if the product is available
            fstream file;
            // open file in read mode to find the product
            file.open("product.csv", ios::in);
            string line;
            bool product_found = false;
            while(getline(file, line)){
                if(line.find(product_id) != string::npos){
                    // get the quantity of the product
                    int product_quantity = stoi(line.substr(line.find_last_of(",") + 1));
                    // check if the quantity is available
                    if(product_quantity >= quantity){
                        // update the quantity
                        product_quantity -= quantity;
                        // close the file in read mode
                        file.close();

                        // open file in write mode to update the product quantity
                        fstream file;
                        file.open("product.csv", ios::in);
                        ofstream outfile;
                        outfile.open("temp.csv", ios::out);
                        while(getline(file, line)){
                            if(line.find(product_id) != string::npos){
                                line = line.substr(0, line.find_last_of(",") + 1) + to_string(product_quantity);
                            }
                            outfile << line << endl;
                        }
                        outfile.close();
                        file.close();
                        // remove the original file and rename the updated file
                        remove("product.csv");
                        rename("temp.csv", "product.csv");
                        cout << "Purchase successful" << endl;
                        product_found = true;
                        break;
                    }
                    else{
                        cout << "Product not available" << endl;
                        product_found = true;
                        break;
                    }
                }
            }
            if(!product_found){
                cout << "Product not found" << endl;
            }
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
    if(choice == 1){
        // staff login
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        sleep(0.5);
        system("clear");
        while(employee.login(username,password)){
            // create a menu for the employee
            cout<<"\n\n\t\t\t\t\t--------------------------------------------"<<endl;
            sleep(.5);
            cout<<"\t\t\t\t\tWelcome to the Supermarket Management System"<<endl;
            sleep(.5);
            cout<<"\t\t\t\t\t--------------------------------------------"<<endl;
            sleep(.5);
            cout<<"[1]Add Product"<<endl;
            sleep(.5);
            cout<<"[2]View Products"<<endl;
            sleep(.5);
            cout<<"[3]Main Menu"<<endl;
            sleep(.5);
            cout<<"Enter your choice: ";
            int choice;
            cin>>choice;
            system("clear");
            if(choice == 1){
                // add product
                string name;
                string product_id;
                int price;
                int quantity;
                cout << "Enter product name: ";
                cin >> name;
                cout << "Enter product id: ";
                cin >> product_id;
                cout << "Enter product price: ";
                cin >> price;
                cout << "Enter product quantity: ";
                cin >> quantity;
                employee.add_product(name, product_id, price, quantity);
                cout<<"Product added successfully"<<endl;
                sleep(1);
                system("clear");
            }
            else if(choice == 2){
                // view products
                employee.view_products();
                sleep(2);
                system("clear");
            }
            else if(choice == 3){
                // Return to the main menu
                cout<<"Returning to the main menu...";
                sleep(1);
                system("clear");
                main();
            }
            else{
                cout << "Invalid choice" << endl;
                sleep(1);
                system("clear");
            }
        }
    }
    else if(choice == 2){
        // customer login
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        sleep(0.5);
        system("clear");
        while(customer.login(username, password)){
            // create a menu for the customer
            cout<<"\n\n\t\t\t\t\t--------------------------------------------"<<endl;
            sleep(.5);
            cout<<"\t\t\t\t\tWelcome to the Supermarket Management System"<<endl;
            sleep(.5);
            cout<<"\t\t\t\t\t--------------------------------------------"<<endl;
            sleep(.5);
            cout<<"[1]View Products"<<endl;
            sleep(.5);
            cout<<"[2]Search Product"<<endl;
            sleep(.5);
            cout<<"[3]Main Menu"<<endl;
            sleep(.5);
            cout<<"Enter your choice: ";
            int choice;
            cin>>choice;
            system("clear");
            if(choice == 1){
                // view products
                customer.view_products();
                sleep(2);
                cout << "Proceed to buy a product? [y/n]: ";
                char choice;
                cin >> choice;
                if(choice == 'y'){
                    string product_id;
                    int quantity;
                    cout << "Enter product id: ";
                    cin >> product_id;
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    customer.buy_product(product_id, quantity);
                    cout<<"Product Bought successfully!"<<endl;
                    sleep(1);
                    system("clear");
                }else{
                    exit(0);
                }
            }else if(choice == 2){
                // search product
                string product_name;
                cout << "Enter product name: ";
                cin >> product_name;
                customer.search_product(product_name);
                sleep(2);
                cout << "Proceed to buy a product? [y/n]: ";
                char choice;
                cin >> choice;
                if(choice == 'y'){
                    string product_id;
                    int quantity;
                    cout << "Enter product id: ";
                    cin >> product_id;
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    customer.buy_product(product_id, quantity);
                    cout<<"Product Bought successfully!"<<endl;
                    sleep(1);
                    system("clear");
                }else{
                    exit(0);
                }
            }else if(choice == 3){
                // return to main menu
                cout<<"Returning to main menu...";
                sleep(1);
                system("clear");
                main();
            }else{
                cout << "Invalid choice" << endl;
                sleep(1);
                system("clear");
            }
        }
    }else if(choice == 3){
        // register
        cout<<"\n\n\t\t\t\t\t--------------------------------------------"<<endl;
        cout<<"\t\t\t\t\tRegistration"<<endl;
        cout<<"[1]]Staff"<<endl;
        cout<<"[2]Customer"<<endl;
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        system("clear");
        if(choice == 1){
            // register staff
            string firstname,lastname,phone,hireDate,position,username,password;
            float salary;
            cout << "First Name: ";
            cin >> firstname;
            cout << "Last Name: ";
            cin >> lastname;
            cout << "Phone: ";
            cin >> phone;
            cout << "Hire Date(DD/MM/YYYY): ";
            cin >> hireDate;
            cout << "Position: ";
            cin >> position;
            cout << "Salary: ";
            cin >> salary;
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;
            employee.registerEmployee(firstname,lastname,phone,hireDate,position,salary,username,password);
            cout<<"Account Registered successfully"<<endl;
            sleep(1);
            system("clear");
            cout<<"Returning to the main menu!";
            sleep(1);
            system("clear");
            main();
        }else if(choice == 2){
            // register customer
            string firstname,lastname,username,password;
            cout << "First name:";
            cin >> firstname;
            cout << "Last name:";
            cin >> lastname;
            cout << "Username:";
            cin >> username;
            cout << "Password: ";
            cin >> password;
            customer.registerCustomer(firstname,lastname,username,password);
            cout<<"Account Registered successfully"<<endl;
            sleep(1);
            system("clear");
            cout<<"Returning to the main menu!";
            sleep(1);
            system("clear");
            main();
        }else{
            cout << "Invalid choice" << endl;
            sleep(1);
            system("clear");
        }
    }else if(choice == 4){
        // exit
        exit(0);
    }else{
        cout << "Invalid choice" << endl;
        sleep(1);
        system("clear");
    }
}
   