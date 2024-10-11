#include <iostream>
#include <string>
using namespace std;

class Dashboard {
protected:
    string itemName;
public:
    Dashboard(string i) : itemName(i) {}

    void display() {
        cout << itemName;
        cout << "Select the configuration.... \n";
    }
};

class Mobile : public Dashboard {
public:
    Mobile() : Dashboard("\nList of Mobiles\n") {}
};

class Laptop : public Dashboard {
public:
    Laptop() : Dashboard("\nList of Laptops\n") {}
};

class Tablets : public Dashboard {
public:
    Tablets() : Dashboard("\nList of Tablets\n") {}
};

class Items {
protected:
    string name;
    float price;
    string description; 
public:
    Items(string n, float p, string d) : name(n), price(p), description(d) {}

    void display() {
        cout << "Item: " << name << " | Price: $" << price << "\nDescription: " << description << endl << endl;
    }

    float getPrice() {
        return price;
    }
};

class Payment {
public:
    void CashPayment() {
        cout << "Processing cash payment...\n";
        cout << "Thanks for using cash!" << endl;
    }

    void UPIPayment() {
        cout << "Processing UPI payment...\n";
        cout << "Thanks for using UPI!" << endl;
    }

    void CreditCardPayment() {
        cout << "Processing credit/debit card payment...\n";
        cout << "Thanks for using credit/debit card!" << endl;
    }
};

int main() {
    Items mobiles[] = {
        Items("iPhone 13", 799.99, "Apple's latest smartphone with A15 Bionic chip."),
        Items("Samsung Galaxy S21", 749.99, "Samsung's flagship smartphone with Exynos 2100."),
        Items("OnePlus 9", 699.99, "OnePlus' flagship phone with Snapdragon 888."),
        Items("Google Pixel 6", 599.99, "Google's smartphone with Tensor chip and stock Android."),
        Items("Xiaomi Mi 11", 699.99, "Xiaomi's flagship phone with Snapdragon 888.")
    };

    Items laptops[] = {
        Items("MacBook Air", 999.99, "Apple's lightweight laptop with M1 chip."),
        Items("Dell XPS", 1199.99, "Dell's premium ultrabook with InfinityEdge display."),
        Items("HP Spectre", 1099.99, "HP's 2-in-1 laptop with powerful hardware."),
        Items("Asus ZenBook", 999.99, "Asus' slim and portable laptop with AMD Ryzen."),
        Items("Lenovo ThinkPad", 899.99, "Lenovo's durable business laptop.")
    };

    Items tablets[] = {
        Items("iPad Pro", 799.99, "Apple's high-end tablet with M1 chip."),
        Items("Samsung Galaxy Tab", 649.99, "Samsung's premium Android tablet."),
        Items("Amazon Fire HD", 149.99, "Affordable tablet for entertainment."),
        Items("Microsoft Surface Go", 499.99, "Microsoft's lightweight and portable tablet."),
        Items("Lenovo Tab M10", 199.99, "Lenovo's budget-friendly Android tablet.")
    };

    float order[100];  
    int orderCount = 0;  
    int itemChoice;
    char Choice;

    do {
        cout << "Welcome to VIVA ELECTRONICS" << endl;
        cout << "PRESS 1 For Mobile \nPRESS 2 For Laptop \nPRESS 3 For Tablets" << endl;

        int i;
        cout << "num: ";
        cin >> i;

        if (i == 1) {
            Mobile m;
            m.display();
            cout << "Press 'Y' to see configuration: ";
            string enter;
            cin >> enter;
            if (enter == "Y") {
                for (int j = 0; j < 5; j++) {
                    mobiles[j].display();
                }
            }
        } else if (i == 2) {
            Laptop l;
            l.display();
            cout << "Press 'Y' to see configuration: ";
            string enter;
            cin >> enter;
            if (enter == "Y") {
                for (int j = 0; j < 5; j++) {
                    laptops[j].display();
                }
            }
        } else if (i == 3) {
            Tablets t;
            t.display();
            cout << "Press 'Y' to see configuration: ";
            string enter;
            cin >> enter;
            if (enter == "Y") {
                for (int j = 0; j < 5; j++) {
                    tablets[j].display();
                }
            }
        } else {
            cout << "Thanks For Visiting" << endl;
        }

        cout << "Do you want to add to Cart or serve more?\nPRESS 'Y' to continue order placement \nPRESS 'N' to serve more products..." << endl;
        char chooseOrder;
        cin >> chooseOrder;

        if (chooseOrder == 'Y' || chooseOrder == 'y') {
            int orderValue;
            cout << "Choose: \n 1: Mobile\n 2: Laptop\n 3: Tablets " << endl;
            cout << "entered value: ";
            cin >> orderValue;

            cout << "How many items do you want to order?: ";
            cin >> orderCount;

            for (int i = 0; i < orderCount; i++) {
                if (orderValue == 1) {
                    cout << "Select mobile number (1-5): ";
                    cin >> itemChoice;
                    order[i] = mobiles[itemChoice - 1].getPrice();  
                    cout << "Added: " << mobiles[itemChoice - 1].getPrice() << endl;
                } else if (orderValue == 2) {
                    cout << "Select laptop number (1-5): ";
                    cin >> itemChoice;
                    order[i] = laptops[itemChoice - 1].getPrice();  
                    cout << "Added: " << laptops[itemChoice - 1].getPrice() << endl;
                } else if (orderValue == 3) {
                    cout << "Select tablet number (1-5): ";
                    cin >> itemChoice;
                    order[i] = tablets[itemChoice - 1].getPrice();
                    cout << "Added: " << tablets[itemChoice - 1].getPrice() << endl;
                }
            }

           
            float sum = 0.0;
            for (int i = 0; i < orderCount; i++) {
                sum += order[i];  
            }
            cout << "The total sum of all items in your order is: $" << sum << endl;

        } else if (chooseOrder == 'N' || chooseOrder == 'n') {
            continue;
        }

        char placeOrder;
        cout << "Do you want to place the order? (Y/N): ";
        cin >> placeOrder;

        if (placeOrder == 'Y' || placeOrder == 'y') {
            int paymentMethod;
            Payment payment;  

            cout << "Choose payment Options:\n"
                 << "Press 1 for cash\n"
                 << "Press 2 for UPI\n"
                 << "Press 3 for CREDIT/DEBIT CARDS\n";
            cin >> paymentMethod;

            switch (paymentMethod) {
                case 1:
                    payment.CashPayment();  
                    break;
                case 2:
                    payment.UPIPayment();  
                    break;
                case 3:
                    payment.CreditCardPayment();  
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    return 0;
            }
        } else {
            cout << "Order not placed" << endl;
        }

        cout << "Press X to return to the main page or any other key to exit: ";
        cin >> Choice;

    } while (Choice == 'X' || Choice == 'x');

    cout << "Exiting the application. Thanks for visiting!\n\n" << endl;

    return 0;
}
