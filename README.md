Video Game Online Store Project
*Video Demo: <URL here> 
*Description: This project is a simple C++ program that simulates an online video game store. It lets users look at video game products, add games to a shopping cart, and make purchases. The main goal is to build a program that feels like a real online shopping platform, where multiple users can interact with the store at the same time. To make it more realistic, the project uses multithreading, which allows different users to shop and check out at the same time without interfering with each other. This means while one user is buying games, another user can still be adding items to their cart.

The project is built using object-oriented programming, or OOP, which helps organize the code in a clean and reusable way. The main components of the system are divided into different classes, and each class has its own job. This makes the code easier to manage, understand, and update. Each class is written in its own pair of files, one header file (.h) and one implementation file (.cpp).

The Product class is responsible for storing information about each video game in the store. It includes details such as the game’s name, description, price, and how many copies are in stock. This class also has functions to display product information, update stock when items are purchased, and check if the requested quantity is available. The Product.h and Product.cpp files contain this class.

Next, there is the ShoppingCart class. This class manages the items that each user adds to their cart. It stores the list of products and their quantities, and it provides functions to add or remove items, update quantities, and calculate the total cost. The ShoppingCart class is written in ShoppingCart.h and ShoppingCart.cpp.

The User class handles general user details, such as the user’s name, email address, and shipping address. It also includes a shopping cart object, allowing each user to have their own cart. On top of that, the project includes three types of users: RegularUser, PremiumUser, and VIPUser. These are created using inheritance, which means they all share the basic features of the User class but have some added features. For example, PremiumUser gets a 10 percent discount, and VIPUser gets a 20 percent discount. Each of these user types is stored in its own set of files like PremiumUser.h, VIPUser.cpp, and so on.

The heart of the program is in Main.cpp. This is where all the classes are used together to simulate the shopping process. First, the video game products are added to the catalog. Then, different user objects are created, and products are added to their shopping carts. Each user runs their checkout process in a separate thread, which allows them to act at the same time without waiting for others to finish. This part of the project uses multithreading to simulate real-world concurrency.

To make sure the program runs safely when multiple users are checking out at the same time, a special tool called std::mutex is used. A mutex locks access to shared resources like product stock so that only one user can make changes at a time. This prevents problems like overselling or stock being updated incorrectly. Without this, two users might try to buy the same item at the same time, which could lead to errors.

Overall, this project was designed to show how a basic online shopping system can be created using C++ while demonstrating key programming concepts like OOP, inheritance, and multithreading. It keeps data safe and organized and lays the foundation for building a more complex and realistic e-commerce application.

*TODO Fix compiler issue in vscode
