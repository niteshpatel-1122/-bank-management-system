
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
using namespace std;

class banking {
    int completed;

    struct customer {
        string id, name, fname, add;
        long long mobileno;
        int cash;
    };

    customer customers[100];

public:
    banking() { completed = 0; }

    void option();
    void newaccount();
    void display();
    void update();
    void searchcustomer();
    void transactions();

};

// OPTION MENU
void banking::option() {
    char select;
    while (true) {
        cout << "\n==== BANK MENU ====\n";
        cout << "1. Create New Account\n";
        cout << "2. Display All Customers\n";
        cout << "3. Update Customer\n";
        cout << "4. Search Customer\n";
        cout << "5. Transactions\n";
        cout << "6. Logout\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> select;

        switch (select) {
            case '1': newaccount(); break;
            case '2': display(); break;
            case '3': update(); break;
            case '4': searchcustomer(); break;
            case '5': transactions(); break;
            case '6': return;  // logout
            case '7': exit(0); // exit program
            default: cout << "\nInvalid option!\n";
        }
    }
}

// NEW ACCOUNT
void banking::newaccount() {
    cout << "\nCreating new account...\n";
    cout << "Enter details for customer " << completed + 1 << ":\n";

    cout << "\nID: ";
    cin >> customers[completed].id;

    cout << "\nName: ";
    cin >> customers[completed].name;

    cout << "\nFather's Name: ";
    cin.ignore(); // required before getline
    getline(cin,customers[completed].fname);

    cout << "\nAddress: ";
    getline(cin, customers[completed].add);

    cout << "\nMobile No: ";
while (!(cin >> customers[completed].mobileno)) {
    cin.clear();  
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid number! Enter again: ";
}


    cout << "\nCash Amount: ";
    cin >> customers[completed].cash;

    completed++;
    cout << "\nAccount created successfully!\n";
}

// DISPLAY ALL CUSTOMERS
void banking::display() {
    if (completed == 0) {
        cout << "\nNo customer records found.\n";
        return;
    }

    cout << "\n==== CUSTOMER LIST ====\n";
    for (int i = 0; i < completed; i++) {
        cout << "\nCustomer " << i + 1 << ":\n";
        cout << "ID: " << customers[i].id << endl;
        cout << "Name: " << customers[i].name << endl;
        cout << "Father's Name: " << customers[i].fname << endl;
        cout << "Address: " << customers[i].add << endl;
        cout << "Mobile No: " << customers[i].mobileno << endl;
        cout << "Cash: " << customers[i].cash << endl;
    }
}

// UPDATE CUSTOMER
void banking::update() {
    if (completed == 0) {
        cout << "\nNo customer records found.\n";
        return;
    }

    string searchid;
    cout << "\nEnter ID to update: ";
    cin >> searchid;

    bool found = false;

    for (int i = 0; i < completed; i++) {
        if (customers[i].id == searchid) {
            found = true;

            cout << "\nCustomer found! What do you want to update?\n";
            cout << "1. Name\n";
            cout << "2. Father's Name\n";
            cout << "3. Address\n";
            cout << "4. Mobile No\n";
            cout << "5. Cash\n";
            cout << "Enter choice: ";

            int choice;
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    cout << "Enter new name: ";
                    cin >> customers[i].name;
                    break;
                case 2:
                    cout << "Enter new father's name: ";
                    cin >> customers[i].fname;
                    break;
                case 3:
                 cin.ignore(); // required before getline
                    cout << "Enter new address: ";
                    getline(cin, customers[i].add);
                    break;
                case 4:
                    cout << "Enter new mobile no: ";
                    cin >> customers[i].mobileno;
                    break;
                case 5:
                    cout << "Enter new cash amount: ";
                    cin >> customers[i].cash;
                    break;
                default:
                    cout << "Invalid choice!";
            }

            cout << "\nCustomer updated successfully!\n";
            return; // stop after updating
        }
    }

    if (!found) {
        cout << "\nCustomer ID not found!\n";
    }
}
void banking::searchcustomer(){
    if(completed==0){
        cout<<"\nrecord not found";
        return;
    }

    string searchid;
    cout<<"\nenter customer id ";
    cin>>searchid;

    bool found=false;

    for(int i=0; i<completed; i++){
        if(customers[i].id==searchid){
            found=true;

            
            cout<<"\n1. id "<<customers[i].id <<endl;
            cout<<"\n2. name "<<customers[i].name <<endl;
            cout<<"\n3. fname "<<customers[i].fname <<endl;
            cout<<"\n4. add "<<customers[i].add <<endl;
            cout<<"\n5. mobileno "<<customers[i].mobileno <<endl;
            cout<<"\n6. cash "<<customers[i].cash <<endl;
            return;
        }
    }

    if(!found){
        cout<<"\ncustomer id not found";
    }

}
void banking::transactions(){
    if(completed==0){
        cout<<"\nrecored not found\n";
        return;
    }

    string searchid;
    cout<<"\nenter the customer id to search\n";
    cin>>searchid;

    bool found=false;


    for(int i=0; i<completed; i++){
        if(customers[i].id==searchid){
            cout<<"\ncustomers recored found\n";
            found=true;

          cout<<"\ncustomers found\n";
          cout<<"\n1. deposit money\n";
          cout<<"\n2. widraw money\n";
          cout<<"\nenter the choice";

          int choice;
          cin>>choice;
          int amount;

          switch (choice)
          {
          case 1:
         cout<<"\nenter your amount to deposite";
         cin>>amount;
         customers[i].cash+=amount;
         cout<<"\ndeposite successfully\n";
         cout<<"\nupdated balance= "<<customers[i].cash<<endl;
            break;
            case 2:
            cout<<"\nenter your amount to withdraw";
            cin>>amount;
            if(amount>customers[i].cash){
                cout<<"\nnot enough balance";
            }
            else{
                customers[i].cash-=amount;
                cout<<"\nwithdral successfull";
                cout<<"\nupdated balance= "<<customers[i].cash<<endl;
            }
            break;
             default:
             cout<<"\ninvalide choice";
          }
          return;
        }
    }
    if(!found){
        cout<<"\ninvalide choice";
    }

}

int main() {
    string id, id1;
    int password, password1;

    cout << "\n==== Bank Management System ====\n";

    cout << "\nSign Up\n";
    cout << "Enter new ID: ";
    cin >> id;
    cout << "Enter new Password: ";
    cin >> password;

    cout << "\nCreating account";
    for (int i = 0; i < 4; i++) {
        cout << "." << flush;
        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << "\nAccount created successfully!\n";

    system("clear"); // or use system("cls") on Windows

    bool loggedin = false;

    while (!loggedin) {
        cout << "\nLogin Page\n";
        cout << "Enter ID: ";
        cin >> id1;
        cout << "Enter Password: ";
        cin >> password1;

        if (id1 == id && password1 == password) {
            cout << "\nLogin Successful!\n";
            loggedin = true;
            system("clear");

            banking obj;
            obj.option();
        } else {
            cout << "\nInvalid ID or Password. Try again.\n";
        }
    }

    return 0;
}
