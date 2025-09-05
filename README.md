The Student Management System is a C program designed to manage student records efficiently using linked lists.
It allows the user to perform operations such as adding, displaying, searching, updating, deleting, and calculating statistics on student data.

This project demonstrates the use of C programming fundamentals (conditions, loops, strings, pointers, structs) combined with data structures (linked lists) to build a real-world style management system.

✨ Features

➕ Add a Student – Insert a new student into the system (with duplicate ID check).

📋 Display All Students – Show all students’ details.

🔎 Search Student by ID – Find and display a student’s details.

✏️ Update Student Information – Modify an existing student’s name, age, or GPA.

❌ Delete a Student – Remove a student record by ID.

📊 Calculate Average GPA – Compute the average GPA across all students.

🏆 Find Student with Highest GPA – Identify and display the top-performing student.

🚪 Exit – Quit the program safely.

🛠️ Data Structure & Design

All student data is stored in a singly linked list.

Each node contains:

Student ID

Name

Age

GPA

Pointer to the next node

Dynamic memory allocation ensures efficient memory usage.

Menu-driven interface provides an easy-to-use CLI system.

📂 Functionality Breakdown

addStudent() – Adds new student details to the linked list.

displayStudents() – Displays all stored students.

searchStudentByID(int id) – Searches and shows student details by ID.

updateStudent(int id) – Updates details for an existing student.

deleteStudent(int id) – Removes a student record from the system.

calculateAverageGPA() – Computes and returns the average GPA.

searchHighestGPA() – Finds and displays the student with the highest GPA.

🖥️ Program Flow

Program starts and displays the menu options.

User chooses an operation (Add, Display, Search, Update, Delete, etc.).

The program executes the corresponding function.

Menu is displayed again until the user selects Exit.
