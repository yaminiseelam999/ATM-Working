
#include <iostream>
#include <string>
using namespace std;
/* project -ATM 
   1.Cash withdrawl
   2.Checking Balance
   3.Updation of mobile number
   4.User datails
   */
class atm{
private:
    long int account_no;
    string name;
    int PIN;
    double balance;
    string mobile_no;
public:
    void setdata(long int account_no_a,string name_a,int PIN_a, double balance_a,string mobile_no_a){
        account_no=account_no_a;
        name=name_a;
        PIN=PIN_a;
        balance=balance_a;
        mobile_no=mobile_no_a;
        
    }
    // getaccount funtion for getting account number
    long int getaccount(){
        return account_no;
    }
    string getname(){
        return name;
    }
    int getpin(){
        return PIN;
    }
    double getbalance(){
        return balance;
    }
    string getmobile(){
        return mobile_no;
    }
    // stemobile function is for updating mobile number
    void setmobile(string mobile_new, string mobile_old)
    {
        if(mobile_old==mobile_no){
            mobile_no=mobile_new;
            cout<<endl<<"successfully updated mobile number";
            
        }
    }
    void cashwithdraw(int amount_a){
        if(amount_a>0 && amount_a< balance){
            balance-=amount_a;
            cout<<endl<<"please collect your cash";
            cout<<endl<<"Your available balance is:"<<balance;
            
        }
        else{
            cout<<endl<<"Invalid details or insufficient balance";
        }
    }
       
};
int main()
{
    int choice=0, enterpin;
    long int enteraccount_no; /// enter pin and enter account_no are for user authentication
    system("cls"); // it is used to get screen clean
    atm user1;
    user1.setdata(123456, "Yamini", 1111, 45000.00 , "6300840275");// it adds values to private numbers
    do
    {
        system("cls"); 
        cout<<endl<<"***welcome to the atm machile***";
        cout<<endl<<"enter your account number";//asking user to enter their account number
        cin>>enteraccount_no;
        cout<<endl<<"enter your pin"; //Asking user to enter their pin
        cin>>enterpin;
        //checking whether details match with user details or not
        if(enteraccount_no==user1.getaccount() && enterpin==user1.getpin())
        {
            do
            {
                int amount=0;
                string oldmobile, newmobile;
                system("cls");
                //user interface
                cout<<endl<<"Welcome to atm";
                cout<<endl<<"select options";
                cout<<endl<<"1.check balance";
                cout<<endl<<"2.cash withdraw";
                cout<<endl<<"3.Show user details";
                cout<<endl<<"4.update mobile_no";
                cout<<endl<<"5.exit"<<endl;
                cin>>choice;
                switch(choice){
                    case 1:
                      cout<<endl<<"Your balance"<<user1.getbalance();
                      
                      break;
                    case 2:
                      cout<<endl<<"Enter amount";
                      cin>>amount;
                      user1.cashwithdraw(amount);// we are calling withdraw function and giving amount
                      break;
                    case 3:
                      cout<<endl<<"user details";
                      cout<<endl<<"Your account no:"<<user1.getaccount();
                      cout<<endl<<"Name"<<user1.getname();
                      cout<<endl<<"Your balance"<<user1.getbalance();
                      cout<<endl<<"Mobile no"<<user1.getmobile();
                      
                      break;
                    case 4:
                      cout<<endl<<"Enter old mobile no:";
                      cin>> oldmobile;
                      cout<<endl<<"Enter new mobile no:";
                      cin>> newmobile;
                      break;
                    case 5:
                      exit(0);
                    default:
                      cout<<"enter valid data";
                      
                      
                }
            }while (1);
        }
        
    }while (1);// condition will always be true and loop will run infinite times
                
    return 0;
}
