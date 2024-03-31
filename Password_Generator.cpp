// Password Generator in C++
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void generatepass(int n)
{ // intitializing password
    string password = "";
    // taking the sets of lowercase,uppercase,digits and special characters.
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*~()_+-={}[]|\\:;'\"<>,.?/";
    // generate random seed
    srand(time(0));
    // looping till the length entered
    for (int i = 0; i < n; i++)
    {
        int random = rand() % 4; // giving us a random number from  0 to 3
        switch (random)
        {
        case 0:
            // adding a random lowercase letter to password
            password += lowercase[rand() % (sizeof(lowercase) - 1)];
            break;
        case 1:
            // adding random uppercase letter to password
            password += uppercase[rand() % (sizeof(uppercase) - 1)];
            break;
        case 2:
            // adding a random number to password
            password += numbers[rand() % (sizeof(numbers) - 1)];
            break;
        case 3:
            // adding a random symbol to password
            password += symbols[rand() % (sizeof(symbols) - 1)];
            break;
        }
    }
    cout << "Generated Password is : " << password << endl;
}
int main()
{ // initializing a choice and a length variable
    int choice, n;
    // intitalizing a variable that will store if you want to continue or not
    char cont = '\0';
    do
    { // displaying the menu
        cout << "--------------------------------------\n";
        cout << "\t Password Generator \n";
        cout << "--------------------------------------\n";
        cout << "1.Generate Password\n";
        cout << "2.Exit\n\n";
        cout << "Enter your choice: ";
        // taking input of user
        cin >> choice;
        // using switch
        switch (choice)
        {
        case 1:
            // Taking the input of length of password
            cout << "Enter the length of the password : ";
            cin >> n;
            cout << "\n";
            cout << "--------------------------------------\n";
            // Calling generatepass function to  print the generated password
            generatepass(n);
            // Asking  for continuation
            cout << "\nDo you want to continue? (Y to continue OR Press any key to exit): ";
            cin >> cont;
            if (cont == 'Y' || cont == 'y')
                continue;
            else
                // if no exit from loop
                choice = 2;
            break;
        case 2:
            // if user opts to exit
            cout << "\nHave a nice day!" << endl;
            break;
        default:
            // for wrong choice
            cout << "Wrong Choice! Please Enter Again.\n\n";
        }
        // ends the loop when user wants to exit
    } while (choice != 2);
    return 0;
}