# 🏦 Bank Management System in C

A console-based **Bank Management System** developed using the C programming language. This project allows users to manage bank accounts, perform financial transactions, and view account summaries through a menu-driven interface.

## ✨ Features

* **Account Management**

  * Create new bank accounts.
  * Display all accounts.
  * Search for accounts.
  * Update account details.
  * Delete accounts.

* **Transaction Management**

  * Deposit money.
  * Withdraw money.
  * Transfer money between accounts.
  * View transaction history.

* **Account Summary**

  * View current account balance.
  * Calculate total deposits and withdrawals.
  * View incoming and outgoing transfers.

* **Data Persistence**

  * Save account information using binary files.
  * Store transaction history.
  * Load saved data when the program starts.

* **Input Validation**

  * Validate account numbers.
  * Prevent duplicate accounts.
  * Check transaction amounts and available balances.

## 🛠️ Technologies Used

* **Language:** C
* **Compiler:** GCC
* **Version Control:** Git
* **Repository Hosting:** GitHub
* **Libraries:** `stdio.h`, `stdlib.h`, `string.h`, `time.h`

## 📂 Project Structure

```text
bank-management-system/
│
├── data/
│   ├── accounts.dat
│   └── transactions.dat
│
├── src/
│   └── main.c
│
├── .gitignore
└── README.md
```

## ⚙️ Getting Started

### Prerequisites

* GCC compiler installed.
* Git installed (optional, for cloning the repository).

### Installation

**1. Clone the repository**

```bash
git clone <your-repository-url>
```

**2. Navigate to the project directory**

```bash
cd bank-management-system
```

**3. Navigate to the source directory**

```bash
cd src
```

**4. Compile the program**

```bash
gcc main.c -o bank
```

**5. Run the program**

On Windows:

```bash
.\bank.exe
```

On Linux or macOS:

```bash
./bank
```

Make sure the `data` directory exists in the project root so the program can save and load its files.

## 🖥️ Main Menu

```text
==================================================
              BANK MANAGEMENT SYSTEM              
==================================================

  ACCOUNT MANAGEMENT
  ------------------
  1. Add Account
  2. Display Accounts
  3. Search Account
  4. Update Account
  5. Delete Account

  TRANSACTION MANAGEMENT
  ----------------------
  6. Deposit Money
  7. Withdraw Money
  8. Transfer Money
  9. Transaction History
 10. Account Summary

  0. Exit
==================================================
  Enter your choice:
```

## 💾 Data Storage

The application uses binary file handling in C to store account and transaction information.

* `accounts.dat` stores account details.
* `transactions.dat` stores transaction records.

This allows the program to retain data between executions.

## 📚 Concepts Practiced

This project helped me practice and apply:

* Structures (`struct`)
* Arrays and pointers
* Functions and modular programming
* File handling (`fopen`, `fread`, `fwrite`)
* String manipulation
* Input validation
* Loops and conditional statements
* Switch-case menus
* Date and time handling
* Git and GitHub

## ⚠️ Limitations

* This is an educational console-based project, not a real banking application.
* Account and transaction data are stored locally without encryption.
* The application uses fixed limits of 100 accounts and 500 transactions.
* It does not include a database or a graphical user interface.

## 👨‍💻 Author

**Samim Mondal Raza**

Computer Science and Technology Student

GitHub: [My Github](https://github.com/Samim0101)

---

*Built as a hands-on C programming project to strengthen problem-solving and software development skills.*
