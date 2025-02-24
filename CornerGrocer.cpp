// Deonya Williams
//April 16, 2023
//Corner Grocer program 

#include <iostream>
#include <fstream> //read and write files
#include <map>    // map library

using namespace std;

class Item_count { // class definition
private:
    map<string, int> itemMap; //map key and value
    string iFile = "CS210_Project_Three_Input_File.txt"; //assigns file a variable to call on later
    string oFile = "frequency.dat"; // assigns the outpul file a variable to call later 

    void read_iFile() { // reads the file
        ifstream infile(iFile); // reading into the file

        if (!infile.is_open()) { // if statement that checks if the file is open and if not prints error message
            cout << "File did not open. " << iFile << endl;
            return;
        }

        string item;
        while (infile >> item) { //loops through each item in file
            itemMap[item]++; //updates item count
        }

        infile.close(); //closes the file
    }

    void write_oFile() {
        ofstream outfile(oFile); //writes into file

        if (!outfile.is_open()) { // statement to check if the file isn't open 
            cout << "File did not open. " << oFile << endl; //error message prints if not open
            return;
        }

        for (const auto& input : itemMap) {
            outfile << input.first << " " << input.second << endl; //.first for key .second for value
        }

        outfile.close(); //closes the file
    }

public:
    void display_item_frequency(string item) { //diplays how often word appears in the file
        cout << "The frequency of " << item << " is " << itemMap[item] << endl; //displays on the screen 
    }

    void allItemFrequencies() { //displays the frequency of all the words in the file 
        for (const auto& input : itemMap) {
            cout << input.first << " " << input.second << endl;
        }
    }

    void display_Histogram() { //displays * instead of numbers for how often something appears 
        for (const auto& input : itemMap) {
            cout << input.first << " ";
            for (int i = 0; i < input.second; i++) { //for loop for printing *
                cout << "*";
            }
            cout << endl;
        }
    }

    void run_program() { //runs the program
        read_iFile(); // call to function to read file

        int option; // variable declaration
        do { //do while loop to display menu and case switch
            cout << "Select an option:" << endl;
            cout << "1. Search for an item." << endl;
            cout << "2. Display frequency of all items." << endl;
            cout << "3. Display histogram frequency of all items." << endl;
            cout << "4. Exit application." << endl;
            cin >> option; // user inputs option

            switch (option) { //switch case 
            case 1: {
                string item; //variable declaration
                cout << "Enter the word to search for:" << endl; //prompts for input of item
                cin >> item; //user inputs item
                display_item_frequency(item); //calls function to display frequency of item in file
                break;
            }
            case 2: {
                allItemFrequencies(); //calls function to show all instances of the word
                break;
            }
            case 3: {
                display_Histogram(); //calls function that displays * for all instances of the word
                break;
            }
            case 4: {
                write_oFile(); // calls function to write to the output file
                cout << "Goodbye!" << endl;
                break;
            }
            default: { //used for invalid selection, prints prompt to try again
                cout << "Invalid option selected. Please try again." << endl;
                break;
            }
            }
        } while (option != 4); //loop continues as long as option 4 has not been selected 
    }
};

int main() { //main function
    Item_count item_count; //calls the class
    item_count.run_program(); // calls run function in the class to run the program
    return 0;
}