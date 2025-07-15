//LIB
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int size_Book = 0;
struct statues
{
    string s;
    string name;
};
struct
{
    int b_id, b_page;
    double b_price;
    string b_name, b_kind, b_author;
    statues b_statues;
} typedef Book;
Book *book;
//رؤس الدوال
void List_Book(int count);
void print_optan();
void print_Book(const Book p);
void Search_Book();
void inpot(int i);
void Used_Book();
void Add_Book(int);
void Delete_Book();
void Modify_Book();
void info();
//_____
//MAIN
int main()
{
       cout << "\t\t📚welcome to Library Book📚\n";
    cout << "Enter the number of books you want to deal with :✎";
    int count;
    cin >>count;
    book = new Book[count];
    int SW = 0;
    while (SW != -1)
    {
        print_optan();
        cin >> SW;
        switch (SW)
        {
        case 1:
            system("cls");
            List_Book(count);
            break;
        case 2:
            system("cls");
            Used_Book();
            break;
        case 3:
            system("cls");
            Delete_Book();
            break;
        case 4:
            system("cls");
            Add_Book(count);
            break;
        case 5:
            system("cls");
            Modify_Book();
            break;
        case 6:
            system("cls");
            Search_Book();
            break;
            case 7:
            system("cls");
            info();
            
        }
    }
    return 0;
}
//________
//عرض الكتب
void List_Book(int count)
{
    for (int i = 0; i < count; i++)
        print_Book(book[i]);
}
//طباعة الخيارات
void print_optan()
{
    cout << "\t\t  ====={{{\"OPTAN\"}}}=====\n";
    cout <<"\t\t##################################\n"
            "\t\t##\t1<<List_Book\t\t##\n"
            "\t\t##\t2<<Used_Book\t\t##\n"
            "\t\t##\t3<<Delete_Book\t\t##\n"
            "\t\t##\t4<<Add_Book\t\t##\n"
            "\t\t##\t5<<Modify_Book\t\t##\n"
            "\t\t##\t6<<Search_Book\t\t##\n"
            "\t\t##\t7<<Info program\t\t##\n"
            "\t\t##\t-1<<exit \t\t##\n"
            "\t\t##################################\n"
            "Enter your choice :";
}
//عرض خصائص كتاب
void print_Book(const Book p)
{
    cout << "\t\t=====\"BOOK\"=====\n";
    cout << "ID:" << p.b_id << endl;
    cout << "Name Book:" << p.b_name << endl;
    cout << "author:" << p.b_author << endl;
    cout << "Number Page:" << p.b_page << endl;
    cout << "Book Kind:" << p.b_kind << endl;
    cout << "Price Book:" << p.b_price << endl;
    cout << "Book statues:" << p.b_statues.s << endl;
}
//تابع البحث
void Search_Book()
{
    cout << "\t\t=====\"SEARCH\"=====\n";
    string search;
    cout << "enter the name of book:";
    cin >> search;
    for (int i = 0; i < size_Book; i++)
        if (search == book[i].b_name)
            print_Book(book[i]);
}
//تابع التعديل
void Modify_Book()
{
    cout << "\t\t=====\"MODIFY\"=====\n";
    cout << "enter the num of book:";
    int n;
    cin >> n;
    if (n - 1 > size_Book && n - 1 < 0)
        cout << "HHands don't exist.";
    else
        inpot(n - 1);
}
//تابع أدخال كتاب
void inpot(int i)
{
    int n;
    book[i].b_id = i + 1;
    cout << "Enter the name of book:";
    cin >> book[i].b_name;
    cout << "Enter the author book:";
    cin >> book[i].b_author;
    cout << "Enter the pages book:";
    cin >> book[i].b_page;
    cout << "Enter the kind of book:";
    cin >> book[i].b_kind;
    cout << "Enter price book:";
    cin>> book[i].b_price;
    cout << "Is the book a borrowed? enter {1-YES  /  2-NO}:";
    cin >> n;
    if (n == 1)
        book[i].b_statues.s = "borrowed";
}
//تابع عرض الكتب المستعارة
void Used_Book()
{
    cout << "\t\t=====\"borrowed\"=====\n";
    for (int i = 0; i < size_Book; i++)
        if (book[i].b_statues.s == "borrowed")
            print_Book(book[i]);
}
//تابع أضافة كتاب
void Add_Book(int count)
{
    cout << "\t\t=====\"ADD\"=====\n";
    size_Book++;
    if (size_Book > count )
        cout << "There's no empty place.";
    else
        inpot(size_Book - 1);
}
//حذف كتاب
void Delete_Book()
{
    cout << "\t\t=====\"DELETE\"=====\n";
    int n;
    cout << "Enter the book number to delete it :";
    cin >> n;
    if (n > size_Book && n < 0)
        cout << "The book doesn't exist.\n";

else
    {
        book[n - 1].b_id = size_Book + 5;
        for (int i = 0; i < size_Book - 1; i++)
            for (int j = i + 1; j < size_Book; j++)
                if (book[i].b_id > book[j].b_id)
                {
                    Book temp = book[i];
                    book[i] = book[j];
                    book[j] = temp;
                }
        for (int i = 0; i < size_Book; i++)
            book[i].b_id = i + 1;
        size_Book--;
    }
}
void info(){
	double price=0;
	int pages=0;
	for(int i=0;i<size_Book;i++)
	{
	 price =price+book[i].b_price;
	 pages=pages+book[i].b_page;
	cout << "Name Book>>>>("<<book[i].b_name<<")...Price=["<<book[i].b_price<<"].....Number pages=("<<book[i].b_page<<")"<<endl;}
	cout<<"\t\t#########################"<<endl;
	cout<<"\t\t##prices books total["<< price <<"]##"<<endl;
	cout<<"\t\t##Total Books Pages["<<pages<<"] ##"<<endl;
	cout<<"\t\t#########################"<<endl;
	
}