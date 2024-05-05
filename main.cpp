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


// Function prototypes
void enterPaymentInformation(string& paymentMethod);
bool validateCardNumber(const std::string& cardNumber);
bool validateCVV(const std::string& cvv);
void printOrder(std::vector<string>, std::vector<double>);



// Show List of Restaurants
void queryRestaurants(sql::Connection *con, const string&cuisine = "") {
    try {
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res;
        if (cuisine.empty()) {
            res = stmt->executeQuery("SELECT idrestaurant,RestaurantName,RestaurantAddress,RestaurantRating FROM restaurant");
        }
        else {
            res = stmt->executeQuery("SELECT idrestaurant,RestaurantName,RestaurantAddress,RestaurantRating FROM restaurant WHERE RestaurantCuisine = '" + cuisine + "'");
        }

        cout << "Restaurants:" << endl;
        while (res->next()) {
            cout << res->getInt("idrestaurant")<<":" << res->getString("RestaurantName") << "\n" << "Address: " << res->getString("RestaurantAddress") << "\n" << "Rating: " << res->getDouble("RestaurantRating") <<"\n" << endl;
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


//main menu function
void MainMenu() {

    cout << "Welcome to Hunger Mate" << "\n";
    cout << "1: Order" << "\n";    
    cout << "2: Leave Rating" << "\n";
    cout << "3: Exit" << "\n";
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
    cout << "5:Checkout\n";
    cout << "6:Go Back" << "\n";
    cout << "Enter Choice: ";
    

}


//Payment information function
void enterPaymentInformation(string& paymentMethod) {
   // std::string paymentMethod;
    std::string cardNumber;
    std::string expiryDate;
    std::string cvv;

    std::cout << "Select Payment Method (credit_card, debit_card, paypal): ";
    std::cin >> paymentMethod;

    if (paymentMethod == "paypal") {
        std::cout << "PayPal Selected\n";
        return;
    }

    std::cout << "Enter Card Number: ";
    std::cin >> cardNumber;
    while (!validateCardNumber(cardNumber)) {
        std::cout << "Invalid Card Number, try again: ";
        std::cin >> cardNumber;
    }

    std::cout << "Enter Expiry Date (MM/YYYY): ";
    std::cin >> expiryDate;

    std::cout << "Enter CVV: ";
    std::cin >> cvv;
    while (!validateCVV(cvv)) {
        std::cout << "Invalid CVV, try again: ";
        std::cin >> cvv;
    }

    std::cout << "Payment information received successfully.\n";

}
//validate card number
bool validateCardNumber(const std::string& cardNumber) {
    // Basic validation: ensure only digits are entered and the length is between 13 and 16
    return cardNumber.length() >= 13 && cardNumber.length() <= 16 && cardNumber.find_first_not_of("0123456789") == std::string::npos;
}
//validate CVV
bool validateCVV(const std::string& cvv) {
    // CVV validation: should be exactly 3 or 4 digits
    return (cvv.length() == 3 || cvv.length() == 4) && cvv.find_first_not_of("0123456789") == std::string::npos;
}
//pickup function
void Pickup(sql::Connection* con, double& totalPrice, std::vector<string>& cart, std::vector<string>& customizations, string& pickupordelivery, std::vector<double>& itemPrices, std::vector<string>& restaurantChoices,string& paymentMethod)
{
    string customername;
    cout << "Enter Name: \n";
    std::getline(std::cin, customername);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    printOrder(cart, itemPrices);
    enterPaymentInformation(paymentMethod);


    try {
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res;
        // Insert customer information, order details, cart, and customizations into the database
        std::string cartItems;
        for (const auto& item : cart) {
            if (cartItems.length() + item.length() + 1 <= 255) { // Check if adding the item will exceed the maximum length
                cartItems += item + ",";
            }
            else {
                break; // Stop adding items if the maximum length is exceeded
            }
        }
        if (!cartItems.empty()) {
            cartItems.pop_back(); // Remove the trailing comma
        }

        std::string customizationItems;
        for (const auto& customization : customizations) {
            if (customizationItems.length() + customization.length() + 1 <= 255) { // Check if adding the customization will exceed the maximum length
                customizationItems += customization + ",";
            }
            else {
                break; // Stop adding customizations if the maximum length is exceeded
            }
        }
        if (!customizationItems.empty()) {
            customizationItems.pop_back(); // Remove the trailing comma
        }


        std::string Restaurants;
        for (const auto& restaurant : restaurantChoices) {
            if (Restaurants.length() + restaurant.length() + 1 <= 255) { // Check if adding the restaurant will exceed the maximum length
                Restaurants += restaurant + ",";
            }
            else {
                break; // Stop adding customizations if the maximum length is exceeded
            }
        }
        if (!Restaurants.empty()) {
            Restaurants.pop_back(); // Remove the trailing comma
        }

        stmt->executeUpdate("INSERT INTO `customerorders` (CustomerName,Restaurants,Items,Customizations,DeliveryChoice,TotalPrice,PaymentMethod) VALUES ('" + customername + "','" + Restaurants + "','" + cartItems + "','" + customizationItems + "','" + pickupordelivery + "','"  + to_string(totalPrice) + "','" + paymentMethod+ "');");




        delete stmt;
    }
    catch (sql::SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl;
    }
    cout << "THANK YOU FOR YOUR ORDER\n";
}
//delivery function
void Delivery(sql::Connection* con, double& totalPrice, std::vector<string>& cart, std::vector<string>& customizations,string& pickupordelivery, std::vector<double>& itemPrices,std::vector<string>& restaurantChoices, string& paymentMethod)
{
    string customername;
    string address;
    string city;
    string state;
    int zipcode;
    cout << "Enter Name: \n";
    std::getline(std::cin, customername);
    cout << "Enter Address: \n";
    std::getline(std::cin, address);
    cout << "Enter City: \n";
    std::getline(std::cin, city);
    cout << "Enter State: \n";
    std::getline(std::cin, state);
    cout << "Enter Zip Code: ";
    cin >> zipcode;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    printOrder(cart,itemPrices);
    enterPaymentInformation(paymentMethod);
    

    try {
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res;
        // Insert customer information, order details, cart, and customizations into the database
        std::string cartItems;
        for (const auto& item : cart) {
            if (cartItems.length() + item.length() + 1 <= 255) { // Check if adding the item will exceed the maximum length
                cartItems += item + ",";
            }
            else {
                break; // Stop adding items if the maximum length is exceeded
            }
        }
        if (!cartItems.empty()) {
            cartItems.pop_back(); // Remove the trailing comma
        }

        std::string customizationItems;
        for (const auto& customization : customizations) {
            if (customizationItems.length() + customization.length() + 1 <= 255) { // Check if adding the customization will exceed the maximum length
                customizationItems += customization + ",";
            }
            else {
                break; // Stop adding customizations if the maximum length is exceeded
            }
        }
        if (!customizationItems.empty()) {
            customizationItems.pop_back(); // Remove the trailing comma
        }


        std::string Restaurants;
        for (const auto& restaurant : restaurantChoices) {
            if (Restaurants.length() + restaurant.length() + 1 <= 255) { // Check if adding the restaurant will exceed the maximum length
                Restaurants += restaurant + ",";
            }
            else {
                break; // Stop adding customizations if the maximum length is exceeded
            }
        }
        if (!Restaurants.empty()) {
            Restaurants.pop_back(); // Remove the trailing comma
        }

        stmt->executeUpdate("INSERT INTO `customerorders` (CustomerName,Restaurants,Items,Customizations,DeliveryChoice,CustomerAddress,CustomerCity,CustomerState,ZipCode,TotalPrice,PaymentMethod) VALUES ('" + customername +"','"+Restaurants+ "','" + cartItems+ "','" + customizationItems +"','"+ pickupordelivery +"','" +  address + "','" + city + "','" + state + "','" + to_string(zipcode) + "','" + to_string(totalPrice) + "','" + paymentMethod+ "');");



       
        delete stmt;
    }
        catch (sql::SQLException& e) {
            cout << "SQL Exception: " << e.what() << endl;
        }
        cout << "THANK YOU FOR YOUR ORDER\n";
}

//customize items function
void customizeOrder(std::vector<string>& cart, std::vector<string>& customizations) {
    //std::vector<std::string> customizations;
    std::string input;


    for (const std::string& str : cart) {
        cout << "Enter any Customizations for " << str << ":" << "\n";
        std::cin.ignore(); // Consume the newline character
        std::getline(std::cin, input);
        customizations.push_back(input);

    }

    
}

//adding item to cart function
double addItemToCart(sql::Connection* con, std::vector<string>& cart, std::vector<string>foodItems, const std::string& tableName, double& totalPrice,std::vector<double>& itemPrices) {
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
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res;

        // Get the item price from the database
        std::string query = "SELECT item_price FROM " + tableName + " WHERE item_name = '" + foodItems[choice - 1] + "'";
        res = stmt->executeQuery(query);
        res->next();
        double itemPrice = res->getDouble("item_price");
        itemPrices.push_back(itemPrice);

        // Add the item to the cart and update the total price
        cart.push_back(foodItems[choice - 1]);
        totalPrice += itemPrice;
        std::cout << foodItems[choice - 1] << " added to your cart.\n";
        delete res;
        delete stmt;
        return itemPrice;
    }
    else {
        std::cout << "Invalid item number. Please try again.\n";
        return 0.0; // Return 0 if no item was added
    }


}


//user input rating function
double GetRatingFromUser() {
    double newRating;
    cout << "Enter a rating for this restaurant (1-5): ";
    cin >> newRating;
    // Add input validation 
    return newRating;
}
//restaurant review function
void RestaurantReview(sql::Connection* con, int restaurantId, double newRating) {
    try {
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res;

        // Get the current rating and number of ratings
        res = stmt->executeQuery("SELECT RestaurantRating, num_ratings FROM restaurant WHERE idrestaurant = " + to_string(restaurantId));
        res->next();
        double currentRating = res->getDouble("RestaurantRating");
        int numRatings = res->getInt("num_ratings");

        // Calculate the new average rating
        double updatedRating = (currentRating * numRatings + newRating) / (numRatings + 1);
        numRatings++;

        // Update the database with the new rating
        stmt->execute("UPDATE restaurant SET RestaurantRating = " + to_string(updatedRating) + ", num_ratings = " + to_string(numRatings) + " WHERE idrestaurant = " + to_string(restaurantId));

        cout << "Thank you for your review!" << endl;

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl;
    }
}
void printOrder(std::vector<string> cart, std::vector<double> itemPrice)
{
    double total = 0;

    for (int i = 0; i < cart.size(); i++)
    {
        cout << cart[i] << "\t\t" << itemPrice[i] << "\n";
        total = total + itemPrice[i];
    }
    cout << "Total: \t\t" << total << "\n\n";
}


//main function
int main()
{   //MySQL Connector Setup
    sql::Driver* driver = get_driver_instance();
    sql::Connection* con = driver->connect("tcp://localhost:3306", "root", "root");
    con->setSchema("hungermate");
    //variables
    bool mainmenu = false;
    int mainChoice;
    int choice;
    int restaurantChoice;
    int restaurantId;
    string cuisine;
    string pickupordelivery;
    string address;
    string city;
    string state;
    string zipcode;
    string paymentMethod;
    double rating;
    double totalPrice = 0.0;
    
    
    //vectors storing the data that will be sent to database
    std::vector<std::string> foodItems;
    std::vector<string> customizations;
    std::vector<string> restaurantChoices;
    std::vector<string> cart;
    std::vector<double> itemPrices;
    
    do {
        MainMenu();
        cin >> mainChoice; 
        cin.ignore(); 

        switch (mainChoice) {
        case 1:
            do {
                FilterRestaurantMenu();
                cin >> choice;
                cin.ignore(); 

                switch (choice) {
                case 1:
                    cuisine = "American";
                    
                    queryRestaurants(con, cuisine);
                    cout << "Enter number of restaurant to select it:";
                    cin >> restaurantChoice;
                    cin.ignore();
                    if (restaurantChoice ==1) 
                    {
                        restaurantChoices.push_back("McDonalds");
                        char continueShopping = 'y';
                        DisplayMcDonaldsMenu(con);
                        while (continueShopping == 'y' || continueShopping == 'Y') {
                            addItemToCart(con,cart, foodItems,"mcdonaldsmenu",totalPrice,itemPrices);
                            cout << "Items in your cart:" << endl;
                            for (const string& item : cart) {
                                cout << item << endl;
                            }
                            std::cout << "Total Price: $" << totalPrice << "\n";
                            std::cout << "Do you want to add more items to your cart? (y/n): ";
                            cin >> continueShopping;
                        }
                    
                        cout << "Items in your cart:" << endl;
                        for (const string& item : cart) {
                            cout << item << endl;
                        }
                    
                             
                    }
                    
                    if (restaurantChoice == 2)
                    {
                        restaurantChoices.push_back("Raising Canes");
                        char continueShopping = 'y';
                        DisplayRaisingCanesMenu(con);
                        while (continueShopping == 'y' || continueShopping == 'Y') {
                            addItemToCart(con, cart, foodItems, "raisingcanesmenu",totalPrice,itemPrices);
                            cout << "Items in your cart:" << endl;
                            for (const string& item : cart) {
                                cout << item << endl;
                            }
                            std::cout << "Total Price: $" << totalPrice << "\n";
                            std::cout << "Do you want to add more items to your cart? (y/n): ";
                            std::cin >> continueShopping;
                        }
                     
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
                        restaurantChoices.push_back("Taco Bell");
                        char continueShopping = 'y';
                        DisplayTacoBellMenu(con);
                        while (continueShopping == 'y' || continueShopping == 'Y') {
                            addItemToCart(con, cart, foodItems,"tacobellmenu",totalPrice,itemPrices);
                            cout << "Items in your cart:" << endl;
                            for (const string& item : cart) {
                                cout << item << endl;
                            }
                            std::cout << "Total Price: $" << totalPrice << "\n";
                            std::cout << "Do you want to add more items to your cart? (y/n): ";
                            std::cin >> continueShopping;
                        }
                   
                        cout << "Items in your cart:" << endl;
                        for (const string& item : cart) {
                            cout << item << endl;
                        }
                       


                    }
                    if (restaurantChoice == 4)
                    {
                        restaurantChoices.push_back("Taco Cabana");
                        char continueShopping = 'y';
                        DisplayTacoCabanaMenu(con);
                        while (continueShopping == 'y' || continueShopping == 'Y') {
                            cout << "Items in your cart:" << endl;
                            for (const string& item : cart) {
                                cout << item << endl;
                            }
                            addItemToCart(con, cart, foodItems,"tacocabanamenu",totalPrice,itemPrices);
                            std::cout << "Total Price: $" << totalPrice << "\n";
                            std::cout << "Do you want to add more items to your cart? (y/n): ";
                            std::cin >> continueShopping;
                        }
                   
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
                        restaurantChoices.push_back("Panda Express");
                        char continueShopping = 'y';
                        DisplayPandaExpressMenu(con);
                        while (continueShopping == 'y' || continueShopping == 'Y') {
                            addItemToCart(con, cart, foodItems,"pandaexpressmenu",totalPrice,itemPrices);
                            cout << "Items in your cart:" << endl;
                            for (const string& item : cart) {
                                cout << item << endl;
                            }
                            std::cout << "Total Price: $" << totalPrice << "\n";
                            std::cout << "Do you want to add more items to your cart? (y/n): ";
                            std::cin >> continueShopping;
                        }
                    
                        cout << "Items in your cart:" << endl;
                        for (const string& item : cart) {
                            cout << item << endl;
                        }
                       

                    }

                    if (restaurantChoice == 6)
                    {
                        restaurantChoices.push_back("Pei Wei");
                        char continueShopping = 'y';
                        DisplayPeiWeiMenu(con);
                        while (continueShopping == 'y' || continueShopping == 'Y') {
                            addItemToCart(con, cart, foodItems, "peiweimenu", totalPrice,itemPrices);
                            cout << "Items in your cart:" << endl;
                            for (const string& item : cart) {
                                cout << item << endl;
                            }
                            std::cout << "Total Price: $" << totalPrice << "\n";
                            std::cout << "Do you want to add more items to your cart? (y/n): ";
                            std::cin >> continueShopping;
                        }
                     
                        cout << "Items in your cart:" << endl;
                        for (const string& item : cart) {
                            cout << item << endl;
                        }
                        std::cout << "Total Price: $" << totalPrice << "\n";
                        

                    }

                    break;
                case 4:
                    cuisine = "";
                    queryRestaurants(con, cuisine);
                    break;
                
                case 5:
                    customizeOrder(cart, customizations);
                    cout << "Delivery or Pickup?";
                    std::getline(std::cin, pickupordelivery);
                   
                    if (pickupordelivery == "Pickup")
                        {

                            Pickup(con, totalPrice, cart, customizations, pickupordelivery, itemPrices, restaurantChoices,paymentMethod);

                        }
                        else if (pickupordelivery == "Delivery")
                        {
                            Delivery(con, totalPrice, cart, customizations, pickupordelivery,itemPrices,restaurantChoices,paymentMethod);
                        }
                        else
                        {
                            cout << "Invalid Selection\n";
                        }
                    break;
                case 6:
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n" << endl;
                    break;
                }
                if (choice == 6) {
                    break;
                }

            } while (true);
            break;
       
        case 2:
            
            cuisine = "";
            queryRestaurants(con,cuisine);
            cout << "Which restaurant do you want to leave a rating?";
            cin >> restaurantId;
            rating = GetRatingFromUser();
            RestaurantReview(con,restaurantId,rating);
            break;
        case 3:
            cout << "Exiting program..." << endl;
            break;
        
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (mainChoice != 3);

    delete con;

    return 0;
}
