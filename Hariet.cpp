#include <iostream>
#include <string>

using namespace std;

// Global variables
int balance = 1000;
string pin = "0000";
int attempts = 0;

// Function prototypes
void authenticate();
void resetPin();
void checkBalance();
void sendMoney();

int main()
{
    int choice;
    
    // Loop until exit option is selected
    while (true)
    {
        cout << "Welcome to Mobile Money Service" << endl;
        cout << "1. Authenticate" << endl;
        cout << "2. Reset/Change Pin" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Send Money" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                authenticate();
                break;
            case 2:
                resetPin();
                break;
            case 3:
                checkBalance();
                break;
            case 4:
                sendMoney();
                break;
            case 5:
                cout << "Thank you for using Mobile Money Service" << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again" << endl;
                break;
        }
    }
    
    return 0;
}

// Function to authenticate the user
void authenticate()
{
    string input;
    cout << "Please enter your pin: ";
    cin >> input;
    
    if (input == pin)
    {
        cout << "Authentication successful" << endl;
        attempts = 0; // Reset attempts to 0
    }
    else
    {
        cout << "Authentication failed, wrong pin" << endl;
        attempts++;
        if (attempts >= 3)
        {
            cout << "Too many failed attempts, exiting program" << endl;
            exit(0);
        }
    }
}

// Function to reset or change the pin
void resetPin()
{
    string oldPin, newPin, confirmPin;
    cout << "Please enter your old pin: ";
    cin >> oldPin;
    
    if (oldPin == pin)
    {
        cout << "Please enter your new pin: ";
        cin >> newPin;
        cout << "Please confirm your new pin: ";
        cin >> confirmPin;
        
        if (newPin == confirmPin)
        {
            pin = newPin;
            cout << "Pin changed successfully" << endl;
        }
        else
        {
            cout << "New pin and confirm pin don't match, pin not changed" << endl;
        }
    }
    else
    {
        cout << "Wrong old pin, pin not changed" << endl;
    }
}

// Function to check the balance
void checkBalance()
{
    cout << "Your balance is: " << balance << endl;
}

// Function to send money
void sendMoney()
{
    string recipient;
    int amount;
    cout << "Please enter the recipient's phone number: ";
    cin >> recipient;
    cout << "Please enter the amount to send: ";
    cin >> amount;
    
    if (amount > balance)
    {
        cout << "Insufficient balance, transaction failed" << endl;
    }
    else
    {
        balance -= amount;
        cout<<"Transaction Succesful, "<< amount<< "sent to " << recipient<< endl;
    }
}
