# Book Portal

A simple command-line **Book Management System** written in C++.

The application provides an interactive terminal-based interface for managing a collection of books. Users can view and search the catalog, add new books, borrow and return books, manage their profile, view dashboard information, and configure application settings.

---

## Features

### Book Management

* View all books in the catalog
* Search books by title or author
* Add new books
* Borrow available books
* Return borrowed books

### User Management

* User login and logout
* View user profile
* Update profile information

### Dashboard

* View useful statistics about the book catalog
* Track book availability and borrowing information

### Settings

* View application settings
* Update available settings through the command-line interface

### Input Validation

* Handles invalid menu choices
* Prevents invalid input from terminating the application unexpectedly

---

## How the System Works

The application is built around a command-line menu.

When the program starts, it loads the book catalog from the local data file and displays the available options.

Depending on whether a user is logged in, different menu options are displayed.

### Book Catalog

Book information is stored locally in:

```text
data/catalog.txt
```

The application reads the catalog when it starts and updates the file when changes are made to the books.

This means the book data is preserved between program executions without requiring a database.

### Login

Users can log in using the credentials supported by the application.

After successful login, additional features such as profile management, dashboard information, and settings become available.

### Borrowing and Returning Books

A user can borrow an available book from the catalog.

When a book is borrowed, its status is updated to indicate that it is no longer available.

When the book is returned, its status is updated again so that it becomes available for borrowing.

---

## Project Structure

```text
student-portal/
├── main.cpp
├── data/
│   └── catalog.txt
├── README.md
└── .gitignore
```

### File Description

| File / Directory   | Description                                                   |
| ------------------ | ------------------------------------------------------------- |
| `main.cpp`         | Main C++ source code containing the Book Portal functionality |
| `data/catalog.txt` | Local file containing the book catalog                        |
| `README.md`        | Project documentation                                         |
| `.gitignore`       | Specifies files that Git should ignore                        |

---

## Requirements

To build and run the application, you need:

* Linux / Ubuntu
* GNU C++ compiler (`g++`)
* Git

You can check whether the C++ compiler is installed with:

```bash
g++ --version
```

---

## Build the Application

Clone the repository and enter the project directory:

```bash
git clone https://github.com/manish0222/student-portal.git
cd student-portal
```

Compile the program using:

```bash
g++ main.cpp -o bookportal
```

If compilation is successful, an executable named `bookportal` will be created.

---

## Run the Application

Start the Book Portal with:

```bash
./bookportal
```

The application will display the Book Portal menu in the terminal.

Follow the menu options to perform different operations.

---

## Example Usage

A typical session may look like:

```text
Start Application
       │
       ▼
     Login
       │
       ▼
  Book Portal Menu
       │
       ├── View Books
       ├── Search Book
       ├── Add Book
       ├── Borrow Book
       ├── Return Book
       ├── View Profile
       ├── Update Profile
       ├── Dashboard
       └── Settings
```

The exact menu options shown depend on the current login state of the user.
Login user admin as username and book123 as default passkeys
---

## Data Storage

The application uses a simple local text file instead of a database.

The catalog is stored at:

```text
data/catalog.txt
```

This file contains the information required by the application to maintain the book collection.

Because the data is stored locally, changes to the catalog can persist after the application is closed.

---

## Git Workflow

This project was also developed as part of a Git workflow exercise.

The repository demonstrates:

* Repository initialization
* Feature branches
* Git commits
* Branch merging
* File organization
* Stashing and restoring changes
* Commit message correction
* Cherry-picking
* Reflog-based recovery
* Merge conflict resolution
* Annotated release tags

The current release is:

```text
v1.0
```

---

## Author

**Manish Godbole**

Book Portal — C++ Command-Line Application
