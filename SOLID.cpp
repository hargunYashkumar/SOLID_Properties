#include<iostream>
#include<string>
#include<vector>
using namespace std;


// // Exapmle for Single Risponsiblity Principle (SRP) as each risponsiblity for printing inbox or saving to database was done separityly
// //   
// class product{
//     public:
//     int price;
//     string name;
//     product(int price,string name){
//         this->price=price;
//         this->name=name;
//     }
// };

// class productCart{
//     private:
//     vector<product*> productList;
//     public:
//     void addProduct(product *p){
//         productList.push_back(p);
//     }
//     vector<product*> getProducts(){
//         return productList;
//     }
//     double calculateTotal(){
//         double result=0;
//         for(int i=0;i<productList.size();i++){
//             result+=productList[i]->price;
//         }
//         return result;
//     }
// };

// class downloadInBox{
//     private:
//     productCart *pc;
//     public:
//     downloadInBox(productCart *p){
//         this->pc=p;
//     }
//     void downloadInText(){
//         cout<<"Downloaded In Text\n";
//     }
// };

// // To follow the open - close princlipe (OCP) we seperate these funtion as thy violate again the SRP 
// // --- Following is having BUG
// // class saveToDB{
// //     private:
// //     productCart *pc;
// //     public:
// //     saveToDB(productCart *p){
// //         this->pc=p;
// //     }
// //     void saveToMongoDB(){
// //         cout<<"Saved to MongoDB\n";
// //     }
// //     void saveToMySQL(){
// //         cout<<"Saved to MySQL\n";
// //     }
// // };

// // Corrent OCP
// class saveToDB{
//     private:
//     productCart *pc;
//     public:
//     virtual void save(productCart *p)=0;
// };

// class saveToMongoDB : public saveToDB{
//     public:
//     void save(productCart *p) override{
//         cout<<"Saved to MongoDB\n";
//     }
    
// };

// class saveToMySQL: public saveToDB{
//     public:
//     void save(productCart *p) override{
//         cout<<"Saved to MySQL\n";
//     }
// };


// int main(){
//     product *p1=new product(100,"Apple");
//     product *p2=new product(200,"Mango");
//     product *p3=new product(300,"Banana");
    
//     productCart *pc=new productCart();
//     pc->addProduct(p1);
//     pc->addProduct(p2);
//     pc->addProduct(p3);
    
//     downloadInBox *d=new downloadInBox(pc);
//     d->downloadInText();

    
//     saveToMongoDB *s1=new saveToMongoDB();
//     saveToMySQL *s2=new saveToMySQL();
//     s1->save(pc);
//     s2->save(pc);
    
//     cout<<"Total Price: "<<pc->calculateTotal();

//     return 0;
// }


// L: Liskov Substitution Principle (LSP) tells use to not modify the curr classes just to abstract from it and make new class 
// class nonWithdrwableAcc{
//     public:
//     virtual void deposit(double amount)=0;
//     virtual void chekBalance()=0;
// };
// class WithdrwableAcc : public nonWithdrwableAcc{
//     virtual void withdraw(double amount)=0;
// };
// class savingAcc : public WithdrwableAcc{
//     double balance;
//     public:
//     savingAcc(){
//         balance=0;
//     }
//     savingAcc(double balance){
//         this->balance=balance;
//     }
//     void deposit(double amount) override{
//         balance+=amount;
//         cout<<"Amount {"<<amount<<"} Deposited to your Savings Account.\n";
//     }
//     void withdraw(double amount) override{
//         if(balance-amount<0){
//             cout<<"Insufficient Balance\n";
//         }
//         else{
//             balance-=amount;
//             cout<<"Amount {"<<amount<<"} Withdrawed from your Savings Account.\n";
//         }
//     }
//     void chekBalance() override{
//         cout<<"Balance: "<<balance<<endl;
//     }
// };
// class currentAcc : public WithdrwableAcc{
//     double balance;
//     public:
//     currentAcc(){
//         balance=0;
//     }
//     currentAcc(double balance){
//         this->balance=balance;
//     }
//     void deposit(double amount) override{
//         balance+=amount;
//         cout<<"Amount {"<<amount<<"} Deposited to your Current Account.\n";
//     }
//     void withdraw(double amount) override{
//         if(balance-amount<0){
//             cout<<"Insufficient Balance\n";
//         }
//         else{
//             balance-=amount;
//             cout<<"Amount {"<<amount<<"} Withdrawed from your Current Account.\n";
//         }
//     }
//     void chekBalance() override{
//         cout<<"Balance: "<<balance<<endl;
//     }
// };
// class fixedDepositAcc : public nonWithdrwableAcc{
//     double balance;
//     public:
//     fixedDepositAcc(){
//         balance=0;
//     }
//     fixedDepositAcc(double balance){
//         this->balance=balance;
//     }
//     void deposit(double amount) override{
//         balance+=amount;
//         cout<<"Amount {"<<amount<<"} Deposited to your Finex Deposit Account.\n";
//     }
//     void chekBalance() override{
//         cout<<"Balance: "<<balance<<endl;
//     }
// };
// class client{
//     public:
//     vector<nonWithdrwableAcc*> accListNonWithdrawable;
//     vector<WithdrwableAcc*> accListWithdrawable;
    
//     client(vector<nonWithdrwableAcc*> accListNonWithdrawable,vector<WithdrwableAcc*> accListWithdrawable){
//         this->accListNonWithdrawable=accListNonWithdrawable;
//         this->accListWithdrawable=accListWithdrawable;
//     }
//     void transection(){
//         accListWithdrawable[0]->deposit(1000);
//         accListWithdrawable[1]->deposit(2000);
//     }
//     void chekBalance(){
//         accListNonWithdrawable[0]->chekBalance();
//         accListNonWithdrawable[0]->chekBalance();
//     }
// };
// int main(){
//     vector<nonWithdrwableAcc*> accListNonWithdrawable;
//     accListNonWithdrawable.push_back(new fixedDepositAcc(1000));
//     vector<WithdrwableAcc*> accListWithdrawable;
//     accListWithdrawable.push_back(new savingAcc(1000));
//     accListWithdrawable.push_back(new currentAcc(1000));

//     client *c=new client(accListNonWithdrawable,accListWithdrawable);
//     c->transection();
//     c->chekBalance();
//     return 0;
// }

// // I: interface Segrigation Proerty -> tells us not to buid one general pupose interface , but we can intoduce saveral samll interface
// class twoDshape{
//     virtual double area()=0;
// };
// class threeDshape{
//     virtual double area()=0;
//     virtual double volume()=0;
// };
// class circle: public twoDshape{
//     double radius;
//     public:
//     circle(double radius){
//         this->radius=radius;
//     }
//     double area(){
//         return 3.14*radius*radius;
//     }
// };
// class square: public twoDshape{
//     double length;
//     public:
//     square(double len){
//         this->length=len;
//     }
//     double area(){
//         return length*length;
//     }
// };
// class cube: public threeDshape{ 
//     double side;
//     public:
//     cube(double side){
//         this->side=side;
//     }
//     double area(){
//         return 6*side*side;
//     }
//     double volume(){
//         return side*side*side;
//     }
// };

// int main(){
//     circle *c=new circle(10);
//     square *s=new square(10);
//     cube *cu=new cube(10);    
//     cout<<"Circle Area: "<<c->area()<<endl;
//     cout<<"Square Area: "<<s->area()<<endl;
//     cout<<"Cube Volume: "<<cu->volume()<<endl;
//     return 0;
// }

// D : Dependancy Inversion Property --> tells us to intoduce an interface between a high-level and a low-level module
// class database{
//     public:
//     virtual void save(string st)=0;
// };
// class MySQLDB : public database{
//     public:
//     void save(string st) override{
//         cout<<"Saved "<<st<<" to MySQL\n";
//     }
// };
// class MongoDB : public database{
//     public:
//     void save(string st) override{
//         cout<<"Saved {"<<st<<"} to MySQL\n";
//     }
// };
// class client{
//     private:
//     database *db;
//     public:
//     client(database *db){
//         this->db=db;
//     }
//     void StoreUser(string st){
//         db->save(st);
//     }
// };

// int main(){
//     MySQLDB *m=new MySQLDB();
//     MongoDB *mo=new MongoDB();
    
//     client *c=new client(m);
//     client *c2=new client(mo);

//     c->StoreUser("yash");
//     c2->StoreUser("Hargun");
//     return 0;
// }