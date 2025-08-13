Library Management System - C++ OOP Project

Overview

This project is a Library Management System built in C++ to practice Object-Oriented Programming (OOP) concepts like encapsulation, inheritance, polymorphism, and abstraction. Since I hadn't yet learned databases, I used text files (Books.txt, Admins.txt, Members.txt) to store and manage data. The system supports two login modes: Admin and Member, each with different permissions.

Admin Features
1. Add New Member
Admins can register new members by entering details like name, ID, and membership duration. The data is stored in Members.txt, ensuring no duplicates are created.

2. Delete Member
Admins can remove a member’s record from Members.txt, keeping the database up to date when someone leaves or their account is no longer needed.

3. Renew Memberships
If a member wants to extend their access, admins can update their expiry date in Members.txt, allowing them to continue using library services.

4. Update Member Info
Admins can modify member details (e.g., name, contact info) in Members.txt to correct errors or reflect changes.

5. Add New Books
New books are stored in Books.txt, with details like title, author, category, and availability status. This keeps the library’s catalog updated.

6. Delete Books
If a book is no longer available, admins can remove its entry from Books.txt, preventing users from searching for unavailable books.

7. Update Book Info
Admins can edit book details (e.g., fixing typos, changing categories) in Books.txt to maintain accurate records.

Member Features
1. Search for Books by Author
Members can search Books.txt for all books by a specific author, helping them find relevant reads quickly.

2. Search for Books by Category
Books can be filtered by genre (e.g., Fiction, Science) in Books.txt, making it easier to browse preferred categories.

3. Search for Books by Title
Members can directly search Books.txt for a book by its title, and the system displays its details if available.

4. Borrow Books
When a member borrows a book, its status in Books.txt changes to "unavailable", preventing others from borrowing it simultaneously.

5. Return Books
Returning a book updates its status in Books.txt to "available", allowing others to borrow it.

6. Membership Validation
Before accessing features, the system checks Members.txt to verify if the member’s subscription is active. If expired, they must renew to continue.

Conclusion
This project demonstrates OOP principles while using text files (Books.txt, Admins.txt, Members.txt) for data storage instead of a database. It separates Admin and Member roles with appropriate permissions, ensuring data integrity. Future improvements could include:

Switching to a real database (e.g., SQLite) for better scalability.

Adding a simple GUI for a more user-friendly experience.

Implementing password encryption for security.
