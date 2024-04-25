#include <cppconn/driver.h> 
#include <cppconn/exception.h> 
#include <cppconn/statement.h> 
#include <iostream> 
#include <mysql_connection.h> 
#include <mysql_driver.h> 
#include <string>
#include <vector> 
#include <format>

using namespace std;
// Show List of Restaurants
void queryRestaurants(sql::Connection *con, const string&cuisine = "") {
    try {
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res;
        if (cuisine.empty()) {
            res = stmt->executeQuery("SELECT idrestaurant,RestaurantName,RestaurantAddress FROM restaurant");
        }
        else {
            res = stmt->executeQuery("SELECT idrestaurant,RestaurantName,RestaurantAddress FROM restaurant WHERE RestaurantCuisine = '" + cuisine + "'");
        }

        cout << "Restaurants:" << endl;
        while (res->next()) {
            cout << res->getInt("idrestaurant")<<":" << res->getString("RestaurantName") << "\n" << "Address: " << res->getString("RestaurantAddress") << "\n" << endl;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl;
    }
}
//Mcdonalds Menu Display
void DisplayMcDonaldsMenu(sql::Connection* con) {

    try {
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res;
       
            res = stmt->executeQuery("SELECT idmcdonaldsmenu,item_name,item_price FROM mcdonaldsmenu");
        
  

        cout << "Menu:" << endl;
        while (res->next()) {
            cout << res->getInt("idmcdonaldsmenu") << ":" << res->getString("item_name") << "\n" << "Price: " << res->getDouble("item_price") << "\n" << endl;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl;
    }



}

//Raising Canes Menu Display
void DisplayRaisingCanesMenu(sql::Connection* con) {

    try {
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res;

        res = stmt->executeQuery("SELECT idraisingcanesmenu,item_name,item_price FROM raisingcanesmenu");



        cout << "Menu:" << endl;
        while (res->next()) {
            cout << res->getInt("idraisingcanesmenu") << ":" << res->getString("item_name") << "\n" << "Price: " << res->getDouble("item_price") << "\n" << endl;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl;
    }



}


//Taco Bell Menu Display
void DisplayTacoBellMenu(sql::Connection* con) {

    try {
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res;

        res = stmt->executeQuery("SELECT idtacobellmenu,item_name,item_price FROM tacobellmenu");



        cout << "Menu:" << endl;
        while (res->next()) {
            cout << res->getInt("idtacobellmenu") << ":" << res->getString("item_name") << "\n" << "Price: " << res->getDouble("item_price") << "\n" << endl;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl;
    }



}


//Taco Cabana Menu Display
void DisplayTacoCabanaMenu(sql::Connection* con) {

    try {
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res;

        res = stmt->executeQuery("SELECT idtacocabanamenu,item_name,item_price FROM tacocabanamenu");



        cout << "Menu:" << endl;
        while (res->next()) {
            cout << res->getInt("idtacocabanamenu") << ":" << res->getString("item_name") << "\n" << "Price: " << res->getDouble("item_price") << "\n" << endl;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl;
    }



}


//panda express menu display
void DisplayPandaExpressMenu(sql::Connection* con) {

    try {
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res;

        res = stmt->executeQuery("SELECT idpandaexpressmenu,item_name,item_price FROM pandaexpressmenu");



        cout << "Menu:" << endl;
        while (res->next()) {
            cout << res->getInt("idpandaexpressmenu") << ":" << res->getString("item_name") << "\n" << "Price: " << res->getDouble("item_price") << "\n" << endl;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl;
    }



}

//Pei Wei  menu display
void DisplayPeiWeiMenu(sql::Connection* con) {

    try {
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res;

        res = stmt->executeQuery("SELECT idpeiweimenu,item_name,item_price FROM peiweimenu");



        cout << "Menu:" << endl;
        while (res->next()) {
            cout << res->getInt("idpeiweimenu") << ":" << res->getString("item_name") << "\n" << "Price: " << res->getDouble("item_price") << "\n" << endl;
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

//filter resturants by type
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

//customize items function
std::vector<string> customizeOrder(std::vector<string> cart) {
    std::vector<std::string> customizations;
    std::string input;


    for (const std::string& str : cart) {
        cout << "Enter any Customizations for " << str << ":" << "\n";
        std::getline(std::cin, input);
        customizations.push_back(input);

    }

    return customizations;
}
//adding item to cart function
void addItemToCart(sql::Connection* con,std::vector<string>& cart, std::vector<string>foodItems, const std::string& tableName) {
    foodItems.clear();
    int choice;
    std::cout << "Enter the number of the item you want to add to your cart: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume newline character
    try {
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res;

        std::string query = "SELECT item_name FROM " + tableName;
        res = stmt->executeQuery(query);


        
        while (res->next()) {
            foodItems.push_back(res->getString("item_name"));
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl;
    }

    // Check for valid input
    if (choice > 0 && choice <= foodItems.size()) {
        cart.push_back(foodItems[choice - 1]);
        std::cout << foodItems[choice - 1] << " added to your cart.\n";
    }
    else {
        std::cout << "Invalid item number. Please try again.\n";
    }
    
    
}


int main()
{   //MySQL Connector Setup
    sql::Driver* driver = get_driver_instance();
    sql::Connection* con = driver->connect("tcp://localhost:3306", "root", "root");
    con->setSchema("hungermate");

    int choice;
    int restaurantChoice;
    string cuisine;
    
    //vectors storing the data that will be sent to database
    std::vector<std::string> foodItems;
    std::vector<string> customizations;
    std::vector<string> restaurantChoices;
    std::vector<string> cart;
    
    
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
                    cout << "Enter number of restaurant to select it:";
                    cin >> restaurantChoice;
                    cin.ignore();
                    if (restaurantChoice ==1) 
                    {
                        char continueShopping = 'y';
                        DisplayMcDonaldsMenu(con);
                        while (continueShopping == 'y' || continueShopping == 'Y') {
                            addItemToCart(con,cart, foodItems,"mcdonaldsmenu");
                            //customizeOrder(cart);
                            std::cout << "Do you want to add more items to your cart? (y/n): ";
                            std::cin >> continueShopping;
                        }
                        customizeOrder(cart);
                        cout << "Items in your cart:" << endl;
                        for (const string& item : cart) {
                            cout << item << endl;
                        }
                        
                    }

                    if (restaurantChoice == 2)
                    {
                        char continueShopping = 'y';
                        DisplayRaisingCanesMenu(con);
                        while (continueShopping == 'y' || continueShopping == 'Y') {
                            addItemToCart(con, cart, foodItems, "raisingcanesmenu");
                           
                            std::cout << "Do you want to add more items to your cart? (y/n): ";
                            std::cin >> continueShopping;
                        }
                        customizeOrder(cart);
                        cout << "Items in your cart:" << endl;
                        for (const string& item : cart) {
                            cout << item << endl;
                        }
                    }
                    break;
                case 2:
                    cuisine = "Mexican";
                    queryRestaurants(con, cuisine);
                    cout << "Enter number of restaurant to select it:";
                    cin >> restaurantChoice;
                    cin.ignore();
                    if (restaurantChoice == 3)
                    {
                        char continueShopping = 'y';
                        DisplayTacoBellMenu(con);
                        while (continueShopping == 'y' || continueShopping == 'Y') {
                            addItemToCart(con, cart, foodItems, "tacobellmenu");
                            std::cout << "Do you want to add more items to your cart? (y/n): ";
                            std::cin >> continueShopping;
                        }
                        customizeOrder(cart);
                        cout << "Items in your cart:" << endl;
                        for (const string& item : cart) {
                            cout << item << endl;
                        }

                    }
                    if (restaurantChoice == 4)
                    {
                        char continueShopping = 'y';
                        DisplayTacoCabanaMenu(con);
                        while (continueShopping == 'y' || continueShopping == 'Y') {
                            addItemToCart(con, cart, foodItems, "tacocabanamenu");
                            std::cout << "Do you want to add more items to your cart? (y/n): ";
                            std::cin >> continueShopping;
                        }
                        customizeOrder(cart);
                        cout << "Items in your cart:" << endl;
                        for (const string& item : cart) {
                            cout << item << endl;
                        }

                    }
                    break;
                case 3:
                    cuisine = "Chinese";
                    queryRestaurants(con, cuisine);
                    cout << "Enter number of restaurant to select it:";
                    cin >> restaurantChoice;
                    cin.ignore();
                    if (restaurantChoice == 5)
                    {
                        char continueShopping = 'y';
                        DisplayPandaExpressMenu(con);
                        while (continueShopping == 'y' || continueShopping == 'Y') {
                            addItemToCart(con, cart, foodItems, "pandaexpressmenu");
                            //customizeOrder(cart);
                            std::cout << "Do you want to add more items to your cart? (y/n): ";
                            std::cin >> continueShopping;
                        }
                        customizeOrder(cart);
                        cout << "Items in your cart:" << endl;
                        for (const string& item : cart) {
                            cout << item << endl;
                        }

                    }

                    if (restaurantChoice == 6)
                    {
                        char continueShopping = 'y';
                        DisplayPeiWeiMenu(con);
                        while (continueShopping == 'y' || continueShopping == 'Y') {
                            addItemToCart(con, cart, foodItems, "peiweimenu");
                            //customizeOrder(cart);
                            std::cout << "Do you want to add more items to your cart? (y/n): ";
                            std::cin >> continueShopping;
                        }
                        customizeOrder(cart);
                        cout << "Items in your cart:" << endl;
                        for (const string& item : cart) {
                            cout << item << endl;
                        }

                    }

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
