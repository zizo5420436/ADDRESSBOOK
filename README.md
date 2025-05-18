# 📖 Address Book Management System

### 📌 Overview
The **Address Book Management System** is a simple **C-based console application** that allows users to store, search, and retrieve contact details efficiently. It provides a user-friendly interface for managing **names**, **phone numbers**, and **email addresses** in a structured and organized manner.

---

### 🚀 Features

- 📌 **Add Contacts** – Store names, phone numbers, and email addresses  
- 🔍 **Search Contacts** – Search by name, phone number, or email  
- 📜 **List All Contacts** – Display all contacts in a structured table format  
- ☑️ **Select a Contact** – Choose a contact to view full details  
- 🖥️ **User-Friendly Interface** – Simple and intuitive navigation  

---

### 🛠️ How It Works

1. User enters a **search query** (name, phone number, or email)  
2. Program displays **all matching contacts** with serial numbers  
3. User selects a **serial number** to view the full contact details  
4. Program displays the **name, phone number, and email** in a formatted output  

---

### 📁 File Structure

```
address_book/
│
├── main.c              → Program entry point
├── add_contact.c       → Logic for adding new contacts
├── search_contact.c    → Logic for searching contacts
├── list_contacts.c     → Displays all contacts
├── select_contact.c    → View details of a selected contact
├── contact_struct.h    → Structure definitions and common headers
└── README.md           → Project documentation
```

---

### 📥 How to Compile

```bash
gcc *.c -o address_book
```

---

### ▶️ How to Run

```bash
./address_book
```

---

### 📋 Sample Interaction

```
Welcome to Address Book Management

1. Add Contact
2. Search Contact
3. List All Contacts
4. View Selected Contact
5. Exit

Enter your choice: 2
Search by (1) Name, (2) Phone, (3) Email: 1
Enter name to search: John

Matches Found:
1. John Doe
2. Johnny Appleseed

Enter serial number to view full details: 1

--- Contact Details ---
Name       : John Doe
Phone No.  : +91-9876543210
Email      : john@example.com
------------------------
```

---



