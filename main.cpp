#include <cppconn/driver.h> 
#include <cppconn/exception.h> 
#include <cppconn/statement.h> 
#include <iostream> 
#include <mysql_connection.h> 
#include <mysql_driver.h> 

using namespace std;

void queryRestaurants(sql::Connection *con, const string&cuisine = "") {
    try {
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res;
        if (cuisine.empty()) {
            res = stmt->executeQuery("SELECT RestaurantName,RestaurantAddress FROM restaurant");
        }
        else {
            res = stmt->executeQuery("SELECT RestaurantName,RestaurantAddress FROM restaurant WHERE RestaurantCuisine = '" + cuisine + "'");
        }

        cout << "Restaurants:" << endl;
        while (res->next()) {
            cout << res->getString("RestaurantName") << "\n" << "Address: " << res->getString("RestaurantAddress") << "\n" << endl;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl;
    }
}



void MainMenu() {

    cout << "Welcome to Hunger Mate" << "\n";
    cout << "1: Order" << "\n";    
    cout << "2: Exit" << "\n";
    cout << "Enter Choice: ";

}

void FilterRestaurantMenu()
{
    cout << "Restaurant Types" << "\n";
    cout << "1:American" << "\n";
    cout << "2:Mexican" << "\n";
    cout << "3:Chinese" << "\n";
    cout << "4:View all" << "\n";
    cout << "5:Go Back" << "\n";
    cout << "Enter Choice: ";
    

}




int main()
{
    sql::Driver* driver = get_driver_instance();
    sql::Connection* con = driver->connect("tcp://sql5.freesqldatabase.com:3306", "sql5698648", "xIHLDpP9hF");
    con->setSchema("sql5698648");

    int choice;
    string cuisine;

    do {
        MainMenu();
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        switch (choice) {
        case 1:
            do {
                FilterRestaurantMenu();
                cin >> choice;
                cin.ignore(); // Clear the input buffer

                switch (choice) {
                case 1:
                    cuisine = "American";
                    queryRestaurants(con, cuisine);
                    break;
                case 2:
                    cuisine = "Mexican";
                    queryRestaurants(con, cuisine);
                    break;
                case 3:
                    cuisine = "Chinese";
                    queryRestaurants(con, cuisine);
                    break;
                case 4:
                    cuisine = "";
                    queryRestaurants(con, cuisine);
                    break;
              
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            } while (choice != 5);
            break;
       
        case 2:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 2);

    delete con;

    return 0;
}