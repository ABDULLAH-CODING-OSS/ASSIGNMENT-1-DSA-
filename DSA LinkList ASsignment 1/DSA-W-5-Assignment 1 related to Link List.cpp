
#include <iostream>
using namespace std;
class Seat {
public:
    string name;
    string phoneNo;
    int seatNumber;
    bool availability;
    Seat(int seatNumber) {
        this->seatNumber = seatNumber;
        this->availability = false;
    }
    ~Seat() {

    }

};
class Node {
public:
    Seat*seat;
    Node* next;
    Node(Seat* seat) {
        this->seat = seat;
        next = nullptr;
    }
};
class SingleLinkList {
public:
    Node* head;
    SingleLinkList() {
        head = nullptr;
    }
    void addSeat(int seatNumber) {
        Seat* seat = new Seat(seatNumber);
        Node* newNode = new Node(seat);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void bookTicket(int s , const string &name,const string &ph){
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->seat->seatNumber == s) {
                if (!temp->seat->availability) {
                    temp->seat->availability = true;
                    temp->seat->name = name;
                    temp->seat->phoneNo = ph;
                    cout << "Ticket Has Been Booked " << endl;
                }
                else {
                    cout << "Seat " << s << " is Already Booked " << endl;
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Seat " << s << "  Not Found " << endl;
    
    }
    void cancelTicket(int s) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->seat->seatNumber == s) {
                if (temp->seat->availability) {
                    temp->seat->availability = false;
                    temp->seat->name = "";
                    temp->seat->phoneNo = "";
                    cout << "Ticket Has Been Canceled " << endl;
                }
                else {
                    cout << "The Seat  " << s << "  is Not Booked " << endl;
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Seat " << s << "  not Found " << endl;
    }
    void reservedSeats() {
        Node* temp = head;
        cout << "Reserved Seats Are " << endl;
        while (temp != nullptr) {
            if (temp->seat->availability) {
                cout << "Seat number " << temp->seat->seatNumber << endl;
                cout << "Passenger Name  " << temp->seat->name << endl;
                cout << "Phone number " << temp->seat->phoneNo << endl;
             }
            temp = temp->next;
        }
    }
    void searchSeat(int s) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->seat->seatNumber == s) {
                cout << "Seat number " << temp->seat->seatNumber << endl;
                cout << "Passenger Name  " << temp->seat->name << endl;
                cout << "Phone number " << temp->seat->phoneNo << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Seat  " << s << "  not Found " << endl;

    }
    void updateSeat(int s,const string &n,const string &ph) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->seat->seatNumber == s) {
                if (temp->seat->availability) {
                    temp->seat->name = n;
                    temp->seat->phoneNo = ph;
                    cout << "Seat Info Has Been Updated " << endl;

                }
                else {
                    cout << "Seat " << s << " Is Not Booked" << endl;
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Seat  " << s << "  not Found " << endl;

    }
    
};

int main()
{
    SingleLinkList list;
    for (int i = 1; i <= 10; i++) {
        list.addSeat(i);
    }
   
    list.bookTicket(1, "Abdullah Javed", "s64");
   list.reservedSeats();
   list.searchSeat(1);
   list.updateSeat(1, "Zain", "033566262");
   list.cancelTicket(1);
   list.reservedSeats();
}
