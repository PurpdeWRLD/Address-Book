# 📘 Address Book Project

A simple **command-line Address Book** application built in C. This project allows users to add, view, edit, search, and delete contact entries. It uses file handling to store data persistently and is ideal for learning the basics of C programming and data structures.

---

## 📚 Table of Contents

- [Features](#features)
- [Usage](#usage)
- [Code Overview](#code-overview)
- [Screenshots](#screenshots)
- [Limitations](#limitations)
- [License](#license)

---

## 🚀 Features

- ➕ Add new contacts (name, phone number, email, address)
- 🔍 Search contacts by name
- ✏️ Edit existing contact details
- ❌ Delete contacts
- 📜 View all saved contacts
- 💾 Data persistence using file storage

---

## 💻 Usage

The app runs in the terminal. You’ll see a menu with options like:
- Add Contact
-View Contacts
-Search Contact
-Edit Contact
-Delete Contact
-Exit
You can just enter the number corresponding to your choice and follow the prompts.

---

## 🧠 Code Overview

main.c: Main source file.
contacts.csv: File used to store contact records.
Uses file handling (fopen, fwrite, fread) for data persistence.
Basic structures (struct) for managing contact data.

---

## ⚠️ Limitations
-Stores up to 100 
-Limited user interface (CLI only)
-No encryption (contact info stored in plain text)

---

## 📄 License
This project is licensed under the MIT License.

👤 Author
  Jaya Karuensh. S
