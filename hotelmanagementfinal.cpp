#include <iostream>
#include <fstream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

// Function declarations
void feedback();
void viewfeedback();
void clientProfile();
void clearScreen();
void viewclientProfile();
void clientUpdate();
void addRoom();
void viewRooms();
void bookRoom(); 
void deactivateUser();
void viewMenu();
void orderFood();
void rateFood();


// Global variables
string uname, password, noti, complaintText;
int option, h = 0, problemCount = 0, rating, i = 0;

int main() {
    while (true) {
        system("cls");
        // header
        cout << "";
        cout << "***********************************************************************\n";
        cout << "*                                                                     *\n";
        cout << "*                        HOTEL MANAGEMENT SYSTEM                      *\n";
        cout << "*                                                                     *\n";
        cout << "***********************************************************************\n\n";

        cout << "Enter the username: ";
        cin >> uname;
        cout << "Enter the password: ";
        cin >> password;

        if (!((uname == "Manager" || uname == "Client") && password == "password")) {
            cout << "\nUnknown identity...\n";
            system("pause"); // keep console window open
            continue;
        }
            // manager menu
            
        if (uname == "Manager") {
            while (true) {
                system("cls");
                cout << "\n----- Manager Menu -----\n";
                cout << "1. Add Room\n";
                cout << "2. View All Rooms\n";
                cout << "3. Check Problems or Complaints\n";
                cout << "4. View Applying Client's Profile\n";
                cout << "5. Check Online Booking Requests\n";
                cout << "6. View Current Bookings\n";
                cout << "7. View Feedback\n";
                cout << "8. Generate Report/Notification\n";
                cout << "9. Deactivate Users Who Violate Rules\n";
                cout << "10. Check Platform Health\n";
                cout << "0. Logout\n";
                cout << "\nEnter your choice: ";
                cin >> option;
                cin.ignore();
            // call function
                if (option == 1) addRoom();
                else if (option == 2) viewRooms();
                else if (option == 3) {
                    if (problemCount > i) cout << complaintText << endl;
                    else cout << "There are no complaints.\n";
                }
                else if (option == 4) viewclientProfile();
                else if (option == 5) cout << "Check the requests for online bookings\n";
                else if (option == 6) cout << "View Current Bookings\n";
                else if (option == 7) viewfeedback();
                else if (option == 8) {
                    cout << "Write a report or notification: ";
                    getline(cin, noti);
                    cout << "Report Saved.\n";
                }
                else if (option == 9) deactivateUser();
                else if (option == 10) {
                    if (problemCount > i) 
                    cout << complaintText << endl;
                    else cout << "Platform is working smoothly.\n";
                }
                else if (option == 0) break;
                else cout << "Invalid option.\n";

                cout << "\nPress Enter to continue...";
                cin.get();
            }
            // client menu
        } else if (uname == "Client") {
            while (true) {
                system("cls");
                cout << "\n----- Client Menu -----\n";
                cout << "1. Register\n";
                cout << "2. View Profile\n";
                cout << "3. Update Profile\n";
                cout << "4. View Room Availability\n";
                cout << "5. Book Room\n";
                cout << "6. Rate the Hotel (out of 10)\n";
                cout << "7. Give Feedback\n";
                cout << "8. View Report/Notification\n";
                cout << "9. Submit Complaint\n";
                cout << "10. view menu\n";
                cout << "11. order food\n";
                cout << "12. rate food\n";
                cout << "0. Logout\n";
                cout << "\nEnter your choice: ";
                cin >> option;
                cin.ignore();
                        //call function
                if (option == 1) clientProfile();
                else if (option == 2) viewclientProfile();
                else if (option == 3) clientUpdate();
                else if (option == 4) viewRooms();
                else if (option == 5) bookRoom();
                else if (option == 6) {
                    cout << "Rate the hotel out of 10: ";
                    cin >> rating;
                    cout << "Thanks for rating us " << rating << "/10.\n";
                    cin.ignore();
                }
                else if (option == 7) feedback();
                else if (option == 8) cout << "Manager's Notification: " << noti << endl;
                else if (option == 9) {
                    cout << "Write your complaint: ";
                    getline(cin, complaintText);
                    problemCount++;
           
                    cout << "Complaint submitted.\n";
                }
                 else if (option == 10){
                     viewMenu();
                 }
                  else if (option == 11){
                  
                                   orderFood();
                  }
                   else if (option == 12){
                                rateFood();
                   }
                else if (option == 0) break;
                else cout << "Invalid option.\n";

                cout << "\nPress Enter to continue...";
                cin.get();
            }
        }
    }
    return 0;
}

// ------------------------ Function Definitions ------------------------

void feedback() {
    string feedback;
    fstream feed("client_feedback.txt", ios::app);
    cout << "Kindly, add your feedback: ";
    getline(cin, feedback);
    feed << feedback << endl;
    feed.close();
}

void viewfeedback() {
    string d;
    fstream feed("client_feedback.txt", ios::in);
    if (!feed) {
        cout << "No feedback found.\n";
    } else {
        cout << "\n--- Feedback ---\n";
        while (getline(feed, d)) {
            cout << d << endl;
        }
    }
    feed.close();
}

void clientProfile() {
    string name, CNIC_number, city, bio;
    fstream file("client_profile.txt", ios::out);
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your CNIC number: ";
    getline(cin, CNIC_number);
    cout << "Enter the city name: ";
    getline(cin, city);
    cout << "Bio: ";
    getline(cin, bio);
    file << "Name: " << name << endl;
    file << "CNIC Number: " << CNIC_number << endl;
    file << "City: " << city << endl;
    file << "Bio: " << bio << endl;
    file.close();
    cout << "Profile saved.\n";
}

void viewclientProfile() {
    string line;
    fstream file("client_profile.txt", ios::in);
    if (!file) {
        cout << "No profile found. Please register first.\n";
    } else {
        cout << "\n--- Client Profile ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
    }
    file.close();
}

void clientUpdate() {
    string update;
    cout << "Update your profile (everything in one input): ";
    getline(cin, update);

    fstream updat("client_profile.txt", ios::out | ios::trunc);
    if (!updat) {
        cout << "Error opening profile file.\n";
        return;
    }

    updat << update << endl;
    updat.close();
    cout << "Profile updated.\n";
}

void addRoom() {
    string roomNumber, roomType;
    int price;

    cout << "Enter Room Number: ";
    getline(cin, roomNumber);
    cout << "Enter Room Type (Standard / Deluxe / Suite): ";
    getline(cin, roomType);
    cout << "Enter Price: ";
    cin >> price;
    cin.ignore();

    fstream roomFile("rooms.txt", ios::app);
    roomFile << "Room No: " << roomNumber << " | Type: " << roomType << " | Price: Rs." << price << endl;
    roomFile.close();

    cout << "Room added successfully.\n";
}

void viewRooms() {
    string line;
    fstream roomFile("rooms.txt", ios::in);

    if (!roomFile) {
        cout << "No room data found.\n";
    } else {
        cout << "\n--- Available Rooms ---\n";
        while (getline(roomFile, line)) {
            cout << line << endl;
        }
    }

    roomFile.close();
}

void bookRoom() {
    int choice;
    string type;
    int price;

    cout << "\nAvailable Room Types:\n";
    cout << "1. Standard - Rs.3000\n";
    cout << "2. Deluxe   - Rs.5000\n";
    cout << "3. Suite    - Rs.8000\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        type = "Standard";
        price = 3000;
    } else if (choice == 2) {
        type = "Deluxe";
        price = 5000;
    } else if (choice == 3) {
        type = "Suite";
        price = 8000;
    } else {
        cout << "Invalid choice.\n";
        return;
    }

    fstream file("bookings.txt", ios::app);
    if (!file) {
        cout << "Error opening bookings file.\n";
        return;
    }

    file << "Client: " << uname << " | Room Type: " << type << " | Price: Rs." << price << endl;
    file.close();


    cout << "Room of type '" << type << "' booked successfully at Rs." << price << ".\n";
    cin.get();
}


void deactivateUser() {
    string user;
    cout << "Enter username to deactivate: ";
    getline(cin, user);
    fstream file("deactivated_users.txt", ios::app);
    file << user << endl;
    file.close();
    cout << "User '" << user << "' has been deactivated.\n";
}
void viewMenu() {
    string line;
    ifstream menu("menu.txt");
    cout << "\n--- Hotel Food Menu ---\n";
    while (getline(menu, line)) {
        cout << line << endl;
    }
    menu.close();
}



void orderFood() {
    char username[50];
    int roomNo, itemNo, quantity;

    cout << "\nEnter your name: ";
    cin.getline(username, 50);

    cout << "Enter your room number: ";
    cin >> roomNo;

    cout << "Enter food item number (Sr No): ";
    cin >> itemNo;

    cout << "Enter quantity: ";
    cin >> quantity;
    cin.ignore(); // Clear input buffer

    ofstream file("orders.txt", ios::app);
    file << username << " | " << roomNo << " | " << itemNo << " | " << quantity << endl;
    file.close();

    cout << "\nOrder saved successfully.\n";
}


void rateFood() {
    int stars;
    string comment;

    cout << "\nRate the food (1-5 stars): ";
    cin >> stars;
    cin.ignore();
    cout << "Enter your comment: ";
    getline(cin, comment);

    ofstream rating("food_rating.txt", ios::app);
    rating << uname << "|" << stars << "|" << comment << endl;
    rating.close();

    cout << "Thank you for your feedback!\n";
}
