#include <bits/stdc++.h>
using namespace std;

class bookshop{
public:
    void controlMethods();
    void addBook();
    void updateBook();
    void delBook();
    void displayBook();
    void checkBook();

};

void bookshop::controlMethods(){
    //system("cls");
    cout<<"\n\n\t\tCONTROL METHODS";
    cout<<"\n\n1. ADD BOOKS";
    cout<<"\n2. DISPLAY BOOKS";
    cout<<"\n3. CHECK BOOKS";
    cout<<"\n4. UPDATE BOOKS";
    cout<<"\n5. DELETE BOOKS";
    cout<<"\n6. EXIT"<<"\n";
}

void bookshop::addBook(){
    //system("cls");
    //cin.ignore();
    fstream file;
    int numBooks;
    string bookID,bookName,authorName;
    cout<<"\n\n\t\tADD BOOKS";
    cout<<"\n\nBOOK ID: ";
    cin>>bookID;
    cout<<"\nBOOK NAME: ";
    cin>>bookName;
    cout<<"\nAUTHOR NAME: ";
    cin>>authorName;
    cout<<"\nNO OF BOOKS: ";
    cin>>numBooks;
    file.open("/home/ishwarya/cmp589/cppProjects/bookShop/bookrec.txt",ios::out|ios::app);
    file << bookID << "\t\t"
         << bookName << "\t\t" << authorName
         << "\t\t" << numBooks << "\n";

}



void bookshop::displayBook(){
    //system("cls");
    fstream file;
    int numBooks;
    string bookID,bookName,authorName;

    file.open("/home/ishwarya/cmp589/cppProjects/bookShop/bookrec.txt",ios::in);
    cout<<"\n\n\t\tBOOKS\n\n";

    if(!file){
        cout<<"File could'nt open! :(";
    }
    else{
        file >> bookID ;
        file >> bookName;
        file >> authorName;
        file >> numBooks;
        while(!file.eof()){

            cout<<"Book ID: "<<bookID<<"\n\n";
            cout<<"Book Name: "<<bookName<<"\n\n";
            cout<<"Author Name: "<<authorName<<"\n\n";
            cout<<"No of books available: "<<numBooks<<"\n\n";
            cout<<"------------------------------------------------------\n\n";

            file >> bookID ;
            //cout<<"\t\t";
            file >> bookName;
            //cout<<"\t\t";
            file >> authorName;
            //cout<<"\t\t";
            file >> numBooks;
            //cout<<"\t\t";
        }

        //system("pause");
        file.close();
    }


}

void bookshop::checkBook(){
    fstream file;
    //cin.ignore();

    int numBooks,count=0;
    string bookID,bookName,authorName;
    file.open("/home/ishwarya/cmp589/cppProjects/bookShop/bookrec.txt",ios::in);
    //file.open("/home/ishwarya/cmp589/cppProjects/bookShop/bookrec.txt",ios::out|ios::app);
    


    cout<<"\n\n\t\tCHECK USER BOOK\n\n";

    if(!file){
        cout<<"File could'nt open!! :(\n\n";
    }
    else{
        string userBookName;
        int reqCopies;
        cout<<"Enter Book Name: ";
        cin>>userBookName;
        cout<<"How many books do you want?!: ";
        cin>>reqCopies;

        file >> bookID ;
        file >> bookName;
        file >> authorName;
        file >> numBooks;

        while(!file.eof()){
            if(userBookName == bookName){
                cout<<"\n\n\t\tCHECKING....\n\n";
                cout<<"BookId: "<<bookID<<"\n\n";
                cout<<"BookName: "<<bookName<<"\n\n";
                cout<<"Author Name: "<<authorName<<"\n\n";
                cout<<"No.of Books available: "<<numBooks<<"\n\n";
                count++;
                if(reqCopies > numBooks){
                    cout<<"Sorry!...Required copies are not found\n\n";
                }
                else{
                    cout<<"This book have your required copies!\n\n";
                }

                break;
            }
            file >> bookID;
            file >>bookName;
            file >> authorName;
            file >> numBooks;
        }
        file.close();
        if(count == 0){
            cout<<"BOOK NOT FOUND!\n";
        }
    
    }
}

void bookshop::updateBook(){
    fstream file,file1;
    file.open("/home/ishwarya/cmp589/cppProjects/bookShop/bookrec.txt",ios::in);
    file1.open("/home/ishwarya/cmp589/cppProjects/bookShop/bookrec1.txt",ios::out|ios::app);


    int numBooks,count=0;
    string bookID,bookName,authorName;    

    string bName,aName;
    int noBooks;
    cout<<"\n\n\t\tUPDATE BOOK DETAILS\n\n";

    if(!file){
        cout<<"File could'nt open!! :(";
    }
    else{
        string userBookId;
        cout<<"Enter Book Id: ";
        cin>>userBookId;
        file >> bookID ;
        file >> bookName;
        file >> authorName;
        file >> numBooks;


        while(!file.eof()){
            if(userBookId == bookID){
                cout<<"\n\n\t\tUpdating...\n\n";
                cout<<"Enter new Book Name: ";
                cin>>bName;
                cout<<"\n\nEnter Author Name: ";
                cin>>aName;
                cout<<"\n\nEnter no of Books: ";
                cin>>noBooks;
                file1 << userBookId << "\t\t"
                    << bName << "\t\t" << aName
                    << "\t\t" << noBooks << "\n";
                count++;

            }
            else{
                file1 << bookID <<"\t\t"
                    << bookName << "\t\t" << authorName
                    << "\t\t" << numBooks << "\n";
            }
            file >> bookID ;
            file >> bookName;
            file >> authorName;
            file >> numBooks;

        }

        if(count == 0){
            cout<<"Book ID NOT FOUND!"<<"\n\n";
        }


        file.close();
        file1.close();

        remove("/home/ishwarya/cmp589/cppProjects/bookShop/bookrec.txt");
        rename("/home/ishwarya/cmp589/cppProjects/bookShop/bookrec1.txt",
                "/home/ishwarya/cmp589/cppProjects/bookShop/bookrec.txt");
    }


}

void bookshop::delBook(){
    fstream file,file1;
    file.open("/home/ishwarya/cmp589/cppProjects/bookShop/bookrec.txt",ios::in);
    file1.open("/home/ishwarya/cmp589/cppProjects/bookShop/bookrec1.txt",ios::out|ios::app);


    int numBooks,count=0;
    string bookID,bookName,authorName;    

    string bName,aName;
    int noBooks;
    cout<<"\n\n\t\tDELETE BOOK DETAIL\n\n";

    if(!file){
        cout<<"File could'nt open!! :(";
    }
    else{
        string userBookId;
        cout<<"Enter Book Id: ";
        cin>>userBookId;
        file >> bookID ;
        file >> bookName;
        file >> authorName;
        file >> numBooks;


        while(!file.eof()){
            if(userBookId == bookID){
                cout<<"\n\n\t\tDELETING...\n\n";
                cout<<"Successfully Deleted!\n";
                count++;

            }
            else{
                file1 << bookID << "\t\t"
                    << bookName << "\t\t" << authorName
                    << "\t\t" << numBooks << "\n";
            }
            file >> bookID ;
            file >> bookName;
            file >> authorName;
            file >> numBooks;

        }

        if(count == 0){
            cout<<"Book ID NOT FOUND!"<<"\n\n";
        }


        file.close();
        file1.close();
        remove("/home/ishwarya/cmp589/cppProjects/bookShop/bookrec.txt");
        rename("/home/ishwarya/cmp589/cppProjects/bookShop/bookrec1.txt",
                "/home/ishwarya/cmp589/cppProjects/bookShop/bookrec.txt");


}
}



int bookshopDatas(){
    bookshop b;
    b.controlMethods();
    int choice;
    cout<<"Enter your choice: ";
    cin>>choice;
    char x;
    switch (choice)
    {
        case 1:
        do{
            b.addBook();
            cout<<"\n\nWant to add another book (y/n) : "<<"  ";
            cin>>x;
        }while(x == 'y');
        break;

        case 2:
            b.displayBook();
            break;
        case 3:
            b.checkBook();
            break;
        case 4:
            b.updateBook();
            break;
        case 5:
            b.delBook();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"\n\nInvalid Choice\n";

    }
    return 0;
}

int main(){
    bookshopDatas();
    return 0;
}