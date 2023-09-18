#include <iostream>
#include<string>
using namespace std;

class Book {
	string name;
	bool bor;
	bool res;
public:
	Book(string n) {
		setName(n);
		borrowed(false);
		reserved(false);
	}
	void setName(string n) {
		name = n;
	}
	void borrowed(bool b) {
		bor = b;
	}
	void reserved(bool b) {
		res = b;
	}
	string getName() {
		return name;
	}
	bool isBorrowed() {
		return bor;
	}
	bool isReserved() {
		return res;
	}
};

class User {
	int input;
public: 
	void borrowBook(Book b[]) {
		display(b, 10);
		input = check();	
		bool meow = b[input].isBorrowed();
		system("cls");
		if (meow == false && input != 10)  {
			b[input].borrowed(true);
			cout << "\nYou have borrowed the book " << b[input].getName() <<"\n\n";
		}
		else if (input == 10) {
			cout << "\nGoing Back!\n" << endl;
		} 
		else {
			cout << "\nYou already borrowed this book!\n" << endl;
		} 	
	}
	void returnBook(Book b[]) {
		display(b, 10);
		input = check();	
		bool meow = b[input].isBorrowed();
		system("cls");
		if (meow == true && input != 10) {
			b[input].borrowed(false);
			cout << "\nYou have returned the book " << b[input].getName() <<"\n\n";
		}
		else if (input == 10) {
			cout << "\nGoing Back!\n" << endl;
		}
		else {
			cout << "\nYou dont have this book!\n" << endl;
		}
	}
	void reserveBook(Book b[]) {
		display(b, 10);
		input = check();	
		system("cls");
		bool woof = b[input].isReserved();
		if (woof == false && input != 10) {
			b[input].reserved(true);
			cout << "\nYou have reserved the book " << b[input].getName() <<"\n\n";
		}
		else if (input == 10) {
			cout << "\nGoing Back!\n" << endl;
		}
		else {
			cout << "\nYou already reserved this book!\n" << endl;
		}
	}
	int check() {
		int in;
		while (!(cin >> in) || in < 0 || in > 10) {
			cout << "\nPlease input a valid Integer!\nYour Choice: ";
		}
		return in;
	}
	void display(Book b[], int n) {
		int i;
		system("cls");
		cout << "------------------------------------------\nBOOKS IN THE LIBRARY"<< endl;
		for (i = 0; i < n; i++) {
			cout << "[" << i << "] " << b[i].getName() << endl;
		}
		cout << "[" << i << "] " << "Back\n" << endl;
		cout << "Your Choice: ";
	}
};

int main () {
	int input;
	User user;
	Book library[10] = { Book("Klara and the Sun"), Book("The Fourth Child"),
					     Book("Libertie"), Book("Harry Potter"),
					     Book("Art of War"), Book("Infinite Country"),
					     Book("Detransition"), Book("The Book of Difficult Fruit"),
					     Book("Aftershocks"), Book("Under a White SKy") };		
		     
	while (input != 3) {
		cout<< "------------------------------------------\nWelcome to the Library! What would you like to do?" << endl;
		cout<< "[0] Borrow a Book\n[1] Return a Book\n[2] Reserve a Book\n[3] END PROGRAM\n\nYour Choice: ";
	
		if (!(cin >> input) || input < 0 || input > 3) {
			cout << "\n\nPlease input a valid Integer!\n" << endl;
		}				     
		else {
			switch (input) {
				case 0:
					user.borrowBook(library);
					break;
				case 1:
					user.returnBook(library);
					break;
				case 2:
					user.reserveBook(library);
					break;
			}
		}
	}
	return 0;
}
