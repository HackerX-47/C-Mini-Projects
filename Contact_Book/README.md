# 📇 Contact Book in C

A simple **Contact Book program** written in C that demonstrates the use of **structures, file handling, and modular programming**.  
It allows users to add, search, delete, and display contacts — all through a clean console interface.

---

## 🧠 Overview

This project is a console-based implementation of a **contact management system**.  
It helps understand how data can be stored, searched, and updated using files in C — without using databases.

Contacts are stored in a file named **`contacts.txt`** during program execution.  
When the program restarts, the file is overwritten (ensuring no permanent data storage — privacy safe).

---

## ⚙️ Features

✅ **Add a new contact** — enter details such as first name, last name, country code, contact number, and email.  
✅ **Search for a contact** — search by first name to find and display matching contact details.  
✅ **Delete a contact** — remove a contact by first name (updates the file automatically).  
✅ **Display all contacts** — view all stored contacts in a neat table format.  
✅ **Privacy-safe** — file resets each time the program starts, ensuring no personal data is saved permanently.

---

## 🧩 Concepts Used

- **Structures (`struct`)** for organized data storage  
- **File handling** (`fopen`, `fprintf`, `fscanf`, `rewind`, `remove`, `rename`)  
- **Enumerations (`enum`)** for clean menu handling  
- **Modular programming** — each feature implemented in a separate function  
- **Formatted console output** for a professional look

---

## 💻 Program Flow

1. The program starts with a short introduction and instructions menu.  
2. The user chooses one of the options:
   - `0` → Exit  
   - `1` → Search Contact  
   - `2` → Add Contact  
   - `3` → Delete Contact  
3. Based on the choice, the program performs the selected operation.  
4. After every action, the updated contact book is displayed.  
5. On exit, all data is cleared (file is overwritten when the program restarts).

---

## 🧾 File Information

- **File Name:** `contact_book.c`  
- **Generated File:** `contacts.txt`  
- **File Mode Used:** `"w+"` (write and read — resets file on each run)

---

## 🏃‍♂️ How to Run

1. **Compile the program**
   ```bash
   gcc contact_book.c -o contact_book
   ```
2. **Run the program**
   ```bash
   ./contact_book
   ```
3. **Follow the on-screen prompts to add, search, or delete contacts.**

---

## 📁 Output File Example

After adding contacts, contacts.txt (during runtime) will look like this:

```bash
John     Doe     +91   9876543210   john.doe@email.com
Mary     Smith   +1    1234567890   mary.smith@email.com
```
After deleting one, the file automatically updates.

---

## ⚠️ Notes

1. The contact list resets each time the program is restarted.
2. File storage is temporary — ensures privacy when sharing the code publicly.
3. Designed for clarity and simplicity — ideal for students learning C file handling and structs.

---

## 👤 Author

This project was created by **Omkar**.

Omkar<br>
**📧 Email:** [omkar121207@gmail.com](mailto:omkar121207@gmail.com)  
**🐙 GitHub:** [HackerX-47](https://github.com/HackerX-47)  
**📸 Instagram:** [okms.ra](https://www.instagram.com/okms.ra/)  
**🔗 LinkedIn:** [Omkar Singh](https://www.linkedin.com/in/omkar-singh-ba2653381/)  
**💻 LeetCode:** [HackerX_47](https://leetcode.com/u/HackerX_47/)
* **Repository Location:** `C-Mini-Projects/Contact_Book`

---
