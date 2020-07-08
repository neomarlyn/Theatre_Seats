#include<iostream>//Jonathan Shepard Chapter 8 Extra Credit
#include<iomanip>//header files
#include<string>

using namespace std;
const int ROW = 12;//constants for the arrays
const int SEAT = 10;
int main() {
	char ticketType = ' ';//character for the switch statement
	int desiredRow; //used to manipulate array and accept input from user
	int desiredSeat;
	bool vacancy = true;//used to see if all seats are taken
	bool exitMenu; //used to exit dowhiles
	bool exitMenuAgain = false; //also used to exit the big dowhile


	cout << setw(1) << left << "              A   B   C   D   E   F   G   H   I   J" << endl << right << endl;//this makes the chart of seats look pretty

	static char seating[ROW][SEAT] = { //2D array for seats, manipulated later to indicate which seats are taken
	{ 'O','O','O','O','O','O','O','O','O','O'},
	{ 'O','O','O','O','O','O','O','O','O','O'},
	{ 'O','O','O','O','O','O','O','O','O','O'},
	{ 'O','O','O','O','O','O','O','O','O','O'},
	{ 'O','O','O','O','O','O','O','O','O','O'},
	{ 'O','O','O','O','O','O','O','O','O','O'},
	{ 'O','O','O','O','O','O','O','O','O','O'},
	{ 'O','O','O','O','O','O','O','O','O','O'},
	{ 'O','O','O','O','O','O','O','O','O','O'},
	{ 'O','O','O','O','O','O','O','O','O','O'},
	{ 'O','O','O','O','O','O','O','O','O','O'},
	{ 'O','O','O','O','O','O','O','O','O','O'}

	};
	for (int i = 0; i < 12; i++) {//displays the seats, rows first...
		cout << setw(8) << "Row " << setw(2) << i + 1 << ":   ";
		for (int j = 0; j < 10; j++) //...then seats
		{
			cout << setw(1) << left << seating[i][j] << setw(3) << setfill(' ') << right << " | "; //manip to make pretty
		}
		cout << endl;
	}
	do {
		
		exitMenu = false;//resets variables every time going through the loop
		desiredRow = 0;
		desiredSeat = 0;
		vacancy = true;

		cout << "What is your ticket type? VIP is V, Prime is P, or Discount is D:" << endl; //prompts for ticket type
		cin >> ticketType;// char variable input accepted here, used in switch statement
		

		switch (ticketType) {//switches on V, P, or D
		case 'V': // if V, then...
			for (int i = 0; i < 4; i++) {//checks if sold out for this section
				for (int j = 0; j < 12; j++) {
					if (seating[i][j] != 'O') {
						cout << "Sorry, all sold out!";
						break;
					}
				}
			}
		


						cout << setw(1) << left << "              A   B   C   D   E   F   G   H   I   J" << endl << right << endl;
						for (int i = 0; i < 4; i++) {//displays only VIP section
							cout << setw(8) << "Row " << setw(2) << i + 1 << ":   ";
							for (int j = 0; j < 10; j++)

							{
								cout << setw(1) << left << seating[i][j] << setw(3) << setfill(' ') << right << " | ";
							}
							cout << endl;
						}
						do {
							cout << "These are the available seats.  Which row would you like?" << endl;
							cin >> desiredRow; //rows displayed, user picks
							cout << "Which seat? 1-10 corresponds to A-J" << endl;
							cin >> desiredSeat;//seats displayed, user picks
							desiredSeat -= 1;//making it accurate to the array since everything is offset by 1 starting at zero
							desiredRow -= 1;
							if (seating[desiredRow][desiredSeat] == 'X') {//checks if user selected a seat that is already occupied
								cout << "Sorry, that seat's taken! Try again..." << endl;
									break; // exits switch and starts over
								}
							seating[desiredRow][desiredSeat] = 'X';//if available, marks as occupied
							cout << setw(1) << left << "              A   B   C   D   E   F   G   H   I   J" << endl << right << endl;
							for (int i = 0; i < 4; i++) {//displays the section after the seat chosen is marked X
								cout << setw(8) << "Row " << setw(2) << i + 1 << ":   ";
								for (int j = 0; j < 10; j++)

								{
									cout << setw(1) << left << seating[i][j] << setw(3) << setfill(' ') << right << " | ";
								}
								cout << endl;
							}
							cout << "Would you like to purchase another ticket in this section? 1 to exit, 0 for yes" << endl; //boolean whether to keep picking seats or exit
							cin >> exitMenu;
						}while (exitMenu == false);
			break;
		case 'P':
			for (int i = 4; i > 3 && i < 8; i++) {//all exactly the same as for VIP, except only for the Prime section
				for (int j = 0; j < 12; j++) {
					if (seating[i][j] != 'O') {
						cout << "Sorry, all sold out!";
						break;
					}
				}
			}
			cout << setw(1) << left << "              A   B   C   D   E   F   G   H   I   J" << endl << right << endl;
			for (int i = 4; i > 3 && i < 8; i++) {
				cout << setw(8) << "Row " << setw(2) << i + 1 << ":   ";
				for (int j = 0; j < 10; j++)
				{
					cout << setw(1) << left << seating[i][j] << setw(3) << setfill(' ') << right << " | ";
				}
				cout << endl;
			}
			do {
				cout << "These are the available seats.  Which row would you like?" << endl;
				cin >> desiredRow;
				cout << "Which seat? 1-10 corresponds to A-J" << endl;
				cin >> desiredSeat;
				desiredSeat -= 1;
				desiredRow -= 1;// again, all of this is the same as VIP, only applied to just the P section
				if (seating[desiredRow][desiredSeat] == 'X') {
					cout << "Sorry, that seat's taken! Try again..." << endl;
					break;
				}
				seating[desiredRow][desiredSeat] = 'X';
				cout << setw(1) << left << "              A   B   C   D   E   F   G   H   I   J" << endl << right << endl;
				for (int i = 4; i > 3 && i < 8; i++) {
					cout << setw(8) << "Row " << setw(2) << i + 1 << ":   ";
					for (int j = 0; j < 10; j++)

					{
						cout << setw(1) << left << seating[i][j] << setw(3) << setfill(' ') << right << " | ";
					}
					cout << endl;
				}
				cout << "Would you like to purchase another ticket in this section? 1 to exit, 0 for yes" << endl;
				cin >> exitMenu;//option to continue selecting seats in this section or pick a new section by returning to main menu
			} while (exitMenu == false);

			break;
		case 'D': // all the same as above, only for the Discount section
			for (int i = 9; i > 8 && i < 12; i++) {//discount section
				for (int j = 0; j < 12; j++) {
					if (seating[i][j] != 'O') {
						cout << "Sorry, all sold out!";
						break;
					}
				}
			}
			cout << setw(1) << left << "              A   B   C   D   E   F   G   H   I   J" << endl << right << endl;
			for (int i = 9; i > 8 && i < 12; i++) {
				cout << setw(8) << "Row " << setw(2) << i + 1 << ":   ";
				for (int j = 0; j < 10; j++)
				{
					cout << setw(1) << left << seating[i][j] << setw(3) << setfill(' ') << right << " | ";
				}
				cout << endl;
			}
			do {
				cout << "These are the available seats.  Which row would you like?" << endl;
				cin >> desiredRow;
				cout << "Which seat? 1-10 corresponds to A-J" << endl;
				cin >> desiredSeat;
				desiredSeat -= 1;
				desiredRow -= 1;
				if (seating[desiredRow][desiredSeat] == 'X') {
					cout << "Sorry, that seat's taken! Try again..." << endl;
					break;
				}
				seating[desiredRow][desiredSeat] = 'X';
				cout << setw(1) << left << "              A   B   C   D   E   F   G   H   I   J" << endl << right << endl;
				for (int i = 9; i > 8 && i < 12; i++) {
					cout << setw(8) << "Row " << setw(2) << i + 1 << ":   ";
					for (int j = 0; j < 10; j++)

					{
						cout << setw(1) << left << seating[i][j] << setw(3) << setfill(' ') << right << " | ";
					}
					cout << endl;
				}
				cout << "Would you like to purchase another ticket in this section? 1 to exit 0 for yes" << endl;
				cin >> exitMenu;
			} while (exitMenu == false);

			break;

		default: cout << "Invalid option!"; //if user enters something other than V, P, or D, spits user out and starts over
			break;
		}
		for (int i = 0; i < 12; i++) {//final display of seating
			cout << setw(8) << "Row " << setw(2) << i + 1 << ":   ";
			for (int j = 0; j < 10; j++)
			{
				cout << setw(1) << left << seating[i][j] << setw(3) << setfill(' ') << right << " | ";
			}
			cout << endl;
		}
		cout << "Would you like to purchase another ticket? 1 to exit, 0 for yes" << endl;//here is where the user may be taken if purchasing from multiple sections
		cin >> exitMenuAgain;
	}while (exitMenuAgain == false);//finally exits program if user exits by entering 1
	
	system("pause");
	return 0;//conclusion
}