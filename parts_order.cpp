/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Adrian Mena Cruz]
 * Lab: 7 - Loops II
 * Description: [This program reads a number of parts orders from the user, checks if they meet the minimum order quantity, and provides a summary of the total and average order quantities as well as the count of orders that meet the minimum requirement.]
 * Due Date: [30/09/2026]
 */
#include <iostream>                                      // Provides cin, cout, and endl
#include <iomanip>                                       // Provides fixed and setprecision
using namespace std;                                     // Allows standard-library names without the std:: prefix

int main() {                                             // Starts the program
    int requestCount;                                    // Stores the known number of part requests
    int partChoice;                                      // Stores one menu selection
    int quantity;                                        // Stores the requested quantity for one part
    int validLineCount = 0;                              // Counts requests that have a valid part and quantity
    double unitPrice;                                    // Stores the price selected by the switch
    double lineCost;                                     // Stores the cost of one valid request
    double orderTotal = 0.0;                             // Accumulates all valid line costs
    bool isValidPartChoice;                              // Tracks whether the switch selected a real part

    cout << "Enter number of part requests from 1 to 5: ";
    cin >> requestCount;

  
    while (requestCount < 1 || requestCount > 5) {
        cout << "Invalid request count. Try again: ";
        cin >> requestCount;
    }

    for (int request = 1; request <= requestCount; request++) {

       
        isValidPartChoice = true;

    
        cout << "\nPart Menu:\n";
        cout << "1. Cable set - $3.25\n";
        cout << "2. Fuse pack - $4.50\n";
        cout << "3. Connector kit - $1.75\n";
        cout << "Enter part choice: ";
        cin >> partChoice;

        while (partChoice < 1 || partChoice > 3) {
            cout << "Invalid part choice. Try again: ";
            cin >> partChoice;
        }
        switch (partChoice) {
            case 1:
                unitPrice = 3.25;
                cout << "Selected: Cable set\n";
                break;

            case 2:
                unitPrice = 4.50;
                cout << "Selected: Fuse pack\n";
                break;

            case 3:
                unitPrice = 1.75;
                cout << "Selected: Connector kit\n";
                break;

            default:
                isValidPartChoice = false;
                break;
        }

   
        if (isValidPartChoice) {
            cout << "Enter quantity from 1 to 5: ";
            cin >> quantity;

            if (quantity >= 1 && quantity <= 5) {
                lineCost = unitPrice * quantity;
                orderTotal += lineCost;
                validLineCount++;

                cout << "Line cost: $" << fixed << setprecision(2)
                     << lineCost << endl;
            }
            else {
                cout << "Invalid quantity. Request skipped." << endl;
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nValid lines processed: " << validLineCount << endl;
    cout << "Order total: $" << orderTotal << endl;

    return 0;                                            // Ends the program successfully
}                                                         // Ends the main function

/*
 * Test analysis:
 * 1. [The orderTotal starts at 0.0 because it is initialized to 0.0, and each valid line cost is added to it during the for loop. This allows the program to accumulate the total cost of all valid part requests.]
 * 2. [An invalid part choice asks for another menu selection because the program validates the user's input and only proceeds with a valid part choice.]
 * 3. [isValidPartChoice is reset during every for iteration to ensure that each part request is evaluated independently.]
 * 4. [An invalid quantity does not change validLineCount because the program only increments this counter for valid line items, and an invalid quantity results in the line being skipped.]
 */