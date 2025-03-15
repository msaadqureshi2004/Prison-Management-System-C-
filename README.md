# Prison Management System

## Overview

The **Prison Management System** is a C++ application designed to manage prison operations, including prisoner records, guard details, warden information, inventory management, meal scheduling, activity logs, and more. It provides an administrative interface to handle different aspects of a prison efficiently.

## Features

- **Admin Authentication**: Secure login system for administrators.
- **Warden Management**: Store and manage warden details.
- **Guard Management**: Add and manage guard information.
- **Prisoner Records**: Maintain prisoner details, including crime and sentence years.
- **Cell & Wing Management**: Organize prisoners within cells and wings.
- **Block Management**: Manage multiple wings inside a prison block.
- **Inventory Management**: Track and manage prison resources.
- **Meal Scheduling**: Maintain and update meal plans for prisoners.
- **Activity Logs**: Record daily activities within the prison.
- **File Handling**: Save and load data from a text file (**prison\_data.txt**).
- **User-Friendly Interface**: Menu-driven console interaction.

## How to Use

### 1. Compile and Run the Program

To compile the program, use a C++ compiler such as **g++**:

```
g++ -o prison_management prison_management.cpp
```

Then, run the executable:

```
./prison_management
```

### 2. Admin Login

Upon starting, the system requires an administrator to log in using:

- **Admin ID**: `admin`
- **Password**: `password123`

### 3. Menu Options

Once logged in, the system provides the following options:

```
1. Enter Warden Information
2. Enter Guards Information
3. Enter Wings Information
4. Enter Inventory Information
5. Enter Meals Information
6. Enter Logs Information
7. Enter Activities Information
8. Save Data
9. Load Data
10. Display All Information
11. Exit
```

Users can navigate and manage prison records accordingly.

## File Handling

The system saves all data to **prison\_data.txt** to retain information between sessions. The following details are stored:

- Warden and guards' information
- Blocks, wings, and cells with prisoners
- Inventory details
- Meal schedules
- Activity logs

## Prerequisites

To run the program, you need:

- A C++ compiler (GCC, Clang, MSVC, etc.)
- Basic knowledge of C++

## Future Improvements

- Implement a **database** (e.g., MySQL) for better data management.
- Add **graphical interface (GUI)** for enhanced usability.
- Implement **role-based access** for different users.
- Improve **error handling** and data validation.

## Author

- **Muhammad Saad Qureshi**
- **ID**: F2023266479

## License

This project is open-source and free to use under the MIT License.

