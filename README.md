<h1 align="center">🎓 University Examination Management System</h1>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>
  <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Course-Programming%20Fundamentals-blue?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/UCP-Spring%202025-red?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/IDE-Visual%20Studio-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white"/>
</p>

<p align="center">
A <b>C++ console-based University Examination Management System</b> for managing student records, subjects, marks, grades, and result generation with file handling support.
</p>

---

# 📌 Overview

The **University Examination Management System** is a menu-driven console application developed using **C++** for the **Programming Fundamentals** course.

The system allows administrators to register students, add subjects, enter marks, calculate grades, generate result cards, search student records, edit marks, delete student information, display class statistics, and save or load all data using text files.

---

# ✨ Features

| Feature | Description |
|---------|-------------|
| 👨‍🎓 Student Registration | Register up to 30 students |
| 📚 Subject Management | Add up to 6 subjects |
| 📝 Marks Entry | Enter subject-wise marks |
| 📊 Grade Calculation | Calculate percentages and grades automatically |
| 📄 Result Cards | Generate detailed student result cards |
| 🔍 Search Student | Search results using Roll Number |
| ✏️ Edit Marks | Update marks of registered students |
| ❌ Delete Student | Remove student records |
| 📈 Class Statistics | Display highest scorer and class average |
| 💾 File Handling | Save and load records using text files |

---

# 🧠 Concepts Used

<p>

<img src="https://img.shields.io/badge/Functions-blueviolet?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Arrays-blue?style=for-the-badge"/>
<img src="https://img.shields.io/badge/2D%20Arrays-success?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Pointers-orange?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Dynamic%20Memory-red?style=for-the-badge"/>
<img src="https://img.shields.io/badge/File%20Handling-lightgrey?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Character%20Arrays-green?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Menu%20Driven-purple?style=for-the-badge"/>

</p>

---

# ⚙️ Functionalities

| Functionality | Description |
|--------------|-------------|
| 👨‍🎓 Register Students | Store student information |
| 📚 Add Subjects | Register course subjects |
| 📝 Enter Marks | Enter subject marks |
| 📊 Calculate Grades | Calculate percentage and grades |
| 📄 Generate Result Cards | Display student results |
| 💾 Save Data | Save records into text files |
| 📂 Load Data | Load saved records |
| 🔍 Search Student | Search by Roll Number |
| ✏️ Edit Marks | Modify student marks |
| ❌ Delete Student | Remove student information |
| 📈 Class Statistics | Display highest and average percentages |
| 📋 Show Registered Students | Display complete student information |

---

# 🎯 Grading Scale

| Percentage | Grade |
|------------|-------|
| 90 – 100 | A+ |
| 80 – 89 | A |
| 70 – 79 | B |
| 60 – 69 | C |
| 50 – 59 | D |
| Below 50 | F |

---

# 📋 Main Menu

```text
============ University Examination Management Menu ============

1. Register Students
2. Add Subjects
3. Enter Marks
4. Calculate Grades
5. Generate Result Cards
6. Save to File
7. Load from File
8. Search Student Result
9. Delete Student
10. Edit Marks
11. Show Registered Students Detail
12. Show Class Statistics
0. Exit
```

---

# 🔧 Functions Used

| Function | Description |
|----------|-------------|
| `compare()` | Compare two character arrays |
| `copy()` | Copy one character array to another |
| `addStudentDetails()` | Register students |
| `addSubjects()` | Add subjects |
| `enterMarks()` | Enter marks for students |
| `calculatePercentageAndGrade()` | Calculate grades |
| `generateResultCard()` | Display student result cards |
| `saveToFile()` | Save records into files |
| `loadFromFile()` | Load saved records |
| `searchStudentResult()` | Search student by Roll Number |
| `deleteStudent()` | Delete student record |
| `editMarks()` | Update student marks |
| `showRegisteredStudentDetails()` | Display all students |
| `showClassStatistics()` | Show class statistics |

---

# 📂 Files Used

| File | Purpose |
|------|---------|
| `students.txt` | Student records |
| `marks.txt` | Subject-wise marks |
| `results.txt` | Final grades and percentages |

---

# 📁 Project Structure

```text
University-Examination-Management-System/
│
├── University Exam System and Grading Management.cpp
├── README.md
├── LICENSE
├── .gitignore
├── students.txt
├── marks.txt
├── results.txt
└── screenshots/
```

---

# ▶️ How to Run

## 🖥️ Visual Studio

1. Open **Visual Studio**
2. Create a new **Empty C++ Project**
3. Add the source file
4. Build the project
5. Press **Ctrl + F5** to run

---

## 💻 VS Code

```bash
g++ "University Exam System and Grading Management.cpp" -o ExamSystem
./ExamSystem
```

---

## 🖱️ Dev C++

1. Open the source file
2. Compile the project
3. Run the program

---

# 📸 Sample Output

```text
============ University Examination Management Menu ============

1. Register Students
2. Add Subjects
3. Enter Marks
4. Calculate Grades
5. Generate Result Cards
6. Save to File
7. Load from File
8. Search Student Result
9. Delete Student
10. Edit Marks
11. Show Registered Students Detail
12. Show Class Statistics
0. Exit
```

---

# 📊 Program Workflow

```text
Start
   │
   ▼
Register Students
   │
   ▼
Add Subjects
   │
   ▼
Enter Marks
   │
   ▼
Calculate Grades
   │
   ▼
Generate Result Cards
   │
   ▼
Save Records
   │
   ▼
Search / Edit / Delete Students
   │
   ▼
Show Statistics
   │
   ▼
Exit
```

---

# 🚀 Future Improvements

- 🔐 User Login System
- 👨‍🏫 Teacher Portal
- 👨‍🎓 Student Portal
- 📊 GPA & CGPA Calculation
- 🗄️ MySQL Database Integration
- 📄 PDF Result Cards
- 🌐 Online Result Portal
- 🖥️ GUI Version
- 📧 Email Notifications
- 📈 Performance Analytics

---

# ⚠️ Limitations

- Maximum 30 students
- Maximum 6 subjects
- Console-based application
- File-based storage only
- No database integration
- Single-user application

---

# 📚 Learning Outcomes

This project helped me understand:

- Functions
- Arrays
- 2D Arrays
- Character Arrays
- Pointers
- Dynamic Memory Allocation
- File Handling
- Menu-Driven Programming
- Searching Techniques
- Data Validation

---

# 🛠️ Technologies Used

| Technology | Purpose |
|------------|---------|
| C++ | Programming Language |
| Visual Studio | IDE |
| File Handling | Data Storage |
| Console | User Interface |

---

# 🎓 Academic Information

| Field | Details |
|-------|---------|
| **University** | University of Central Punjab (UCP) |
| **Course** | Programming Fundamentals |
| **Project Type** | Semester Project |

---

# 👨‍💻 Developer

**Irfan**  
**L1F24BSCS0580**

---

# 📄 License

This project is licensed under the **MIT License**.

See the **LICENSE** file for more details.

---

<h3 align="center">⭐ If you found this project useful, don't forget to star the repository! ⭐</h3>

---

<h2 align="center">👨‍💻 Author</h2>

<p align="center">
<b>Irfan</b><br>
BS Computer Science Student<br>
University of Central Punjab (UCP)<br>
Roll No: <b>L1F24BSCS0580</b>
</p>
