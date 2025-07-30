# SOLID_Properties
System Design using SOLD principles in CPP Language

# SOLID Principles in C++ (OOP Practice)

This project demonstrates all **five SOLID principles** of object-oriented programming using C++. Each principle is implemented using simple, real-world analogies like products, bank accounts, and geometric shapes.

## 🔰 What are SOLID Principles?

SOLID is an acronym for five design principles intended to make software designs more understandable, flexible, and maintainable:

1. **S** – Single Responsibility Principle (SRP)
2. **O** – Open/Closed Principle (OCP)
3. **L** – Liskov Substitution Principle (LSP)
4. **I** – Interface Segregation Principle (ISP)
5. **D** – Dependency Inversion Principle (DIP)

---

## 🧠 Principles and Implementations

### 1. Single Responsibility Principle (SRP)
Each class has one reason to change:
- `product` – represents a product with name and price.
- `productCart` – manages the cart and price calculations.
- `downloadInBox` – handles downloading info.
- `saveToDB` subclasses – handle DB operations separately.

### 2. Open/Closed Principle (OCP)
Software entities should be open for extension but closed for modification:
- `saveToDB` is an abstract base class.
- `saveToMongoDB` and `saveToMySQL` extend it without modifying the original.

### 3. Liskov Substitution Principle (LSP)
Derived classes must be substitutable for base classes:
- `nonWithdrwableAcc` and `WithdrwableAcc` abstract classes.
- `savingAcc`, `currentAcc`, and `fixedDepositAcc` implement them properly.
- `client` can use any account type interchangeably.

### 4. Interface Segregation Principle (ISP)
Do not force classes to implement unnecessary interfaces:
- `twoDshape` and `threeDshape` are separate interfaces.
- `circle`, `square`, and `cube` implement only what they need (area or volume).

### 5. Dependency Inversion Principle (DIP)
High-level modules should not depend on low-level modules directly:
- `database` is an interface.
- `MySQLDB` and `MongoDB` implement it.
- `client` depends on `database` abstraction, not on concrete DB classes.

---

## 🛠️ How to Compile & Run

Ensure you have a C++ compiler like `g++`.

### Compile:
```bash
g++ -o solid_demo solid.cpp
