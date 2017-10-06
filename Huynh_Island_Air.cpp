//Hue Anh Huynh
//4/19/17

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

const int maxSeat = 6;

struct seat
{
    int seats;
    int assignSeats;
    string first;
    string last;
};

void menu();
void fillSeat(seat passenger[maxSeat]);
void emptySeats(struct seat passengers[maxSeat]);
void showEmptySeats(struct seat passenger[maxSeat]);
void seatList(struct seat passenger[maxSeat], int seat);
void assignSeat(struct seat passenger[maxSeat]);
void assigned(struct seat passenger[maxSeat], int seat, string firstName, string lastName);
void unassignSeats(struct seat passenger[maxSeat]);
void showList(struct seat passenger[maxSeat]);

int main(){

    seat passenger[maxSeat];
    int choice, seatNum;
    cout << "ISLAND AIR" << endl;
    fillSeat(passenger);
    do{
        menu();
        cin >> choice;
        while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)
        {
            cout << "Invalid input" << endl;
            cin >> choice;
        }
        if(choice == 1)
        {
            emptySeats(passenger);
        }
        else if(choice == 2)
        {
            emptySeats(passenger);
            showEmptySeats(passenger);
        }
        else if(choice == 3)
        {
            emptySeats(passenger);
            showEmptySeats(passenger);
            assignSeat(passenger);
        }
        else if(choice == 4)
        {
            emptySeats(passenger);
            showEmptySeats(passenger);
            unassignSeats(passenger);
        }
        else if (choice == 5)
        {
            showList(passenger);
        }

    }while(choice >= 1 && choice < 6);
    if(choice == 6)
    {
        cout << "EXIT" << endl << endl;
    }

    return 0;
}


void menu()
{
    cout << "1. Show number of empty seats " << endl;
    cout << "2. Show list of empty seats "  << endl;
    cout << "3. Assign a seat " << endl;
    cout << "4. Delete a seat assignment " << endl;
    cout << "5. Show passenger list" << endl;
    cout << "6. Quit" << endl;
    cout << "Enter 1-6: ";
}

void fillSeat(seat passenger[maxSeat])
{
    for(int i = 0; i <= maxSeat - 1; i++)
    {
        passenger[i].seats = i + 1;
        passenger[i].assignSeats = 0;
        passenger[i].first = "_";
        passenger[i].last = "_";
    }
}

void emptySeats(struct seat passenger[maxSeat])
{
    int count = 0;
    for(int i = 0; i < maxSeat; i++)
    {
        if(passenger[i].assignSeats == 0)
        {
            count++;
        }
    }
    cout << "There are " << count << " seats available" << endl;
    cout << endl;
}

void showEmptySeats(struct seat passenger[maxSeat])
{
    bool newLine = false;
    int count = 0;
    for(int i = 0; i <= maxSeat - 1; i++)
    {
        if(count != 2)
        {
            if(passenger[i].assignSeats == 0 && count != 2)
            {
                cout << passenger[i].seats << " ";
                count++;

            }
            else
            {
                cout << "-" << " ";
                count++;
            }
        }
        if (count == 2)
        {
            count = 0;
            cout << endl;
        }
    }
}

void seatList(struct seat passenger[maxSeat], int seat)
{
        if(passenger[seat - 1].assignSeats == 0)
        {
            cout << "Seat " << seat << " is not assigned" << endl;
        }
        else if(passenger[seat - 1].assignSeats == 1)
        {
            cout << "Seat " << seat << " was assigned to " << passenger[seat - 1].first << " " << passenger[seat - 1].last << endl;
            passenger[seat - 1].assignSeats = 0;
            passenger[seat - 1].first = "_";
            passenger[seat - 1].last = "_";
            cout << "Seat " << seat << " is now available" << endl;
        }
    cout << endl;
}

void assignSeat(struct seat passenger[maxSeat])
{
    int seat;
    string first, last;
    do{
        cout << "Enter seat number: ";
        cin >> seat;

        while(seat < 1 || seat > maxSeat)
        {
            cout << "Invalid input" << endl;
            cin >> seat;
        }
        if(passenger[seat - 1].assignSeats == 0)
        {

                cout << "Passenger first name: ";
                cin >> first;
                cout << "Passenger last name: ";
                cin >> last;
                if (first == "" || last == "")
                    cout << "you need to enter the passenger's name" << endl;

        }
        else if(passenger[seat - 1].assignSeats == 1)
        {
            cout << "Seat taken" << endl;
        }
    }while((seat < 1 || seat > maxSeat || first == "" || last == "") && passenger[seat - 1].assignSeats == 0 && passenger[seat - 1].assignSeats == 1);
    assigned(passenger, seat, first, last);
    cout << endl;
}

void assigned(struct seat passenger[maxSeat], int seat, string firstName, string lastName)
{
    if (passenger[seat - 1].assignSeats == 0)
    {
        passenger[seat - 1].assignSeats = 1;
        passenger[seat - 1].first = firstName;
        passenger[seat - 1].last = lastName;
        cout << "Seat " << seat << " assigned to " << firstName << " " << lastName << endl;
    }
}

void unassignSeats(struct seat passenger[maxSeat])
{
    int seat;
    cout << "Enter seat number: ";
    cin >> seat;
    while(seat < 1 || seat > maxSeat)
    {
        cout << "Invalid input" << endl;
        cin >> seat;
    }
    seatList(passenger, seat);
    cout << endl;
}

void showList(struct seat passenger[maxSeat])
{
    cout << "Here are the list of passengers " << endl;
    cout << "Seat Number      Passenger Name " << endl;
    cout << "-----------------------------------------------" << endl;
    for(int i = 0; i < maxSeat; i++)
    {
        if(passenger[i].assignSeats != 0)
        {
            cout << passenger[i].seats << setw(20) << passenger[i].first << " " << passenger[i].last << endl;
        }
    }
    cout << endl;
}
