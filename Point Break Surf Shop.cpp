// Point Break Surf Shop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//FAWZIYAH AHMED

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

//Defining the three sizes of surfboards that Johnny sells
#define costOfXXXSmallSurf 50.00;
#define costOfSmallSurf 175.00;
#define costOfMediumSurf 190.00;
#define costOfLargeSurf 200.00;

//Declaring the variables
char choice;
char size;
int quantity;
int totalXXXSmall = 0;
int totalSmall = 0; 
int totalMedium = 0;
int totalLarge = 0;

//ShowUsage() function will show the user how to use the program.
void ShowUsage()
{
    //Displaying the choices that the user can use
    cout << "To show program usage 'S'" << endl;
    cout << "To purchase a surfboard press 'P'" << endl;
    cout << "To display current purchase press 'C'" << endl;
    cout << "To display total amount due press 'T'" << endl;
    cout << "To quit the program press 'Q'" << endl;

}

//MakePurchase() function will ask the user to enter the quantity and size they want to purchase
void MakePurchase(int& iTotalXXXSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)
{
    //Declaring the variables.
    int quantity = 0;
    char size = '\0';

    //Prompting the user to enter the quantity and size of the surfboard
    cout << "Please enter the quantity and type (X=squirrel surfing, S=small, M=medium, L=large) of surfboard you would like to purchase:";
    cin >> quantity >> size;

    //here the if statement will add the quantity to the selected surfboards total
    if (tolower(size) == 'x')
    {
        iTotalXXXSmall = iTotalXXXSmall + quantity;
    }
    else if (tolower(size) == 's')
    {
        iTotalSmall = iTotalSmall + quantity;
    }
    else if (tolower(size) == 'm')
    {
        iTotalMedium = iTotalMedium + quantity;
    }
    else if (tolower(size) == 'l')
    {
        iTotalLarge = iTotalLarge + quantity;
    }
}

//DisplayPurchase() function will collect data from the MakePurchase() function and output the result
void DisplayPurchase(const int iTotalXXXSmall, const int iTotalSmall, const int
    iTotalMedium, const int iTotalLarge)
{

    //the if statement will output the total quantity by the sizes
    if (iTotalXXXSmall > 0)
    {
        cout << "The total number of xxxsmall surfboards is " << iTotalXXXSmall << endl;
    }
    if (iTotalSmall > 0)
    {
        cout << "The total number of small surfboards is " << iTotalSmall << endl;
    }
    if (iTotalMedium > 0)
    {
        cout << "The total number of medium surfboards is " << iTotalMedium << endl;
    }
    if (iTotalLarge > 0)
    {
        cout << "The total number of large surfboards is " << iTotalLarge << endl;
    }
}
//DisplayTotal() function will display the quantity and the total to the user
void DisplayTotal(const int iTotalXXXSmall, const int iTotalSmall, const int
    iTotalMedium, const int iTotalLarge)

{
    //declaring the variables
    double xxxsmall_amount = 0; 
    double small_amount = 0;
    double medium_amount = 0;
    double large_amount = 0;
    double totalAmtDue = 0;

    //display the value upto 2 decimal places
    cout << fixed << setprecision(2);

    //I set the setfill to displays empty spaces
    cout << setfill(' ');
    
    //the if statement will calculate the total based on the sizes, by multiplying the quantity with the given cost 
    if (iTotalXXXSmall > 0)

    {
        xxxsmall_amount = iTotalXXXSmall * costOfXXXSmallSurf;
        cout << "The total number of xxxsmall surfboards is" << (' ') << iTotalXXXSmall << (' ') << "at a total of $";
        cout << xxxsmall_amount << endl;
        totalAmtDue = totalAmtDue + xxxsmall_amount;
    }
    if (iTotalSmall > 0)

    {
        small_amount = iTotalSmall * costOfSmallSurf;
        cout << "The total number of small surfboards is" << (' ') << iTotalSmall << (' ') << "at a total of $";
        cout << small_amount << endl;
        totalAmtDue = totalAmtDue + small_amount;
    }

    if (iTotalMedium > 0)
    {
        medium_amount = iTotalMedium * costOfMediumSurf;
        cout << "The total number of medium surfboards is" << (' ') << iTotalMedium << (' ') << "at a total of $";
        cout << medium_amount << endl;
        totalAmtDue = totalAmtDue + medium_amount;
    }

    if (iTotalLarge > 0)
    {
        large_amount = iTotalLarge * costOfLargeSurf;

        cout << "The total number of large surfboards is" << (' ') << iTotalLarge << (' ') << "at a total of $";
        cout << large_amount << endl;
        totalAmtDue = totalAmtDue + large_amount;
    }
    //Displaying the total due amount
    cout << "Amount due: $" << totalAmtDue << endl;
}

//here goes the main function
int main()
{
    //I used string here to display the welcome message
    const string welcome = "***** Welcome to my Johnny Utah's PointBreak Surf Shop *****";
    //using I/O manipulators
    cout << setw(61) << setfill('*');
    cout << "\n";
    cout << welcome << "\n";
    cout << setw(61);
    cout << "\n";
    cout << endl;

    //Displaying ShowUsage() function to show the user how to use the program
    ShowUsage();

    //Prompting the user to enter the selection.
    cout << "\nPlease enter selection: ";
    cin >> choice;

    //the while loop will ask the user to enter selection untill they press q
    while (tolower(choice) != 'q')
    {
        //If the user enter s, then the program will call ShowUsage().
        if (tolower(choice) == 's')
        {
            ShowUsage();
        }
        //If the user enter p, then the program will call MakePurchase()
        else if (tolower(choice) == 'p')
        {
            MakePurchase(totalXXXSmall, totalSmall,
                totalMedium, totalLarge);
            cout << endl;
        }

        //If the user enter c, then the program will call DisplayPurchase()
        else if (tolower(choice) == 'c')

        {
            //If the user enter 'c' without purchasing any surf then it will display no purchase made yet,
              //else, it will output the quantity that they have entered
            if (totalXXXSmall == 0 &&
                totalSmall == 0 &&
                totalMedium == 0 &&
                totalLarge == 0)
            {
                cout << "No purchase made yet." << endl;
            }

            else
            {
                DisplayPurchase(totalXXXSmall, totalSmall, totalMedium, totalLarge);
            }
        }

        //If the user enter t, then the program will call DisplayTotal()
        else if (tolower(choice) == 't')
        {
            //If the user enter 't' without purchasing any surf then it will display no purchase made yet,
              //else, it will output the quantity that they have entered
            if (totalXXXSmall == 0 &&
                totalSmall == 0 &&
                totalMedium == 0 &&
                totalLarge == 0)
            {
                cout << "No purchase made yet." << endl;
            }

            else
            {
                DisplayTotal(totalXXXSmall,totalSmall,totalMedium,totalLarge);
            }
        }

        //if the user enter other than the given choices, then display Invalid choice
        else
        {
            cout << "Invalid choice!" << endl;
        }

        //then prompt the user to enter the selection again
        cout << "\nPlease enter selection: ";
        cin >> choice;
    }
    cout << "Thank you" << endl;

}