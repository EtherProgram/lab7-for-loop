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
    int deviceCount;                                     // Stores the known number of devices in the batch
    int passingDeviceCount = 0;                          // Counts devices with a passing quality score
    double qualityScore;                                 // Stores one device score per iteration
    double totalScore = 0.0;                             // Accumulates all quality scores

    cout << "Enter number of devices from 1 to 10: ";  // Prompts for the batch size
    cin >> deviceCount;                                  // Reads the first batch-size candidate

    while (deviceCount < 1 || deviceCount > 10) {        // Repeats while the batch size is outside the allowed range
        cout << "Invalid device count. Try again: ";    // Explains why another batch size is required
        cin >> deviceCount;                              // Reads a replacement batch size
    }                                                     // Ends after a valid batch size is entered
    for (int device = 1; device <= deviceCount; device++) { // Repeats once for each device in the batch
        cout << "Enter quality score for device " << device << ": "; // Identifies the current device in the prompt
        cin >> qualityScore;                              // Reads one quality score for this iteration
        totalScore += qualityScore;                       // Accumulates the total score

        if (qualityScore >= 70.0) {                       // Checks whether the score meets the passing threshold
            passingDeviceCount++;                         // Counts one passing device
            cout << "Device passes inspection." << endl;  // Reports the passing result
        } else {                                          // Handles a score below the passing threshold
            cout << "Device fails inspection." << endl;   // Reports the failing result
        }                                                 // Ends the selection structure
    }                                                   // Ends the for loop
    cout << fixed << setprecision(2);                    // Formats displayed decimal values with two places
    cout << "Total quality score: " << totalScore << endl; // Displays the accumulated quality score
    cout << "Average quality score: " << totalScore / deviceCount << endl; // Displays the calculated average
    cout << "Passing devices: " << passingDeviceCount << endl; // Displays the count of passing devices

    return 0;                                            // Ends the program successfully
}                                                         // Ends the main function

/*
 * Analysis:
 * 1. [The totalScore starts at 0.0. because it is initialized to 0.0, and each quality score entered by the user is added to it during the for loop. This allows the program to accumulate the total score of all devices.]
 * 2. [The passingDeviceCount increments when a device's quality score is greater than or equal to 70.0, but not when it's less than 70.0.]
 * 3. [The averageScore is calculated after the for loop because it requires the total score and the number of devices to compute the average.]
 */