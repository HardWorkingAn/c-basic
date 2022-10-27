#include <iostream>
#include <string>
#include <cstring>
using namespace std;



class Book {
   char* title;
   int price;
public:
   Book(const char* title, int price);
   ~Book();
   Book(const Book& b);
   void set(const char* title, int price);
   void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(const char* title, int price)
{
   this->price = price;
   int size = strlen(title) + 1;
   unsigned int size_t = size;
   this->title = (char*)malloc(size_t);
   strcpy(this->title, title);
}

Book::~Book()
{
   free(this->title);
}

Book::Book(const Book& b)
{
   int size = strlen(b.title) + 1;
   unsigned int size_t = strlen(b.title) + 1;
   this->title = (char*)malloc(size_t);
   strcpy(this->title, b.title);
   this->price = b.price;
}

void Book::set(const char* title, int price)
{
   if (this->title)
      free(this->title);
   int size = strlen(title) + 1;
   unsigned int size_t = size;
   this->title = (char*)malloc(size_t);

   cout << sizeof(char) * size;
   cout << size;


   strcpy(this->title, title);
   this->price = price;
}

int main()
{
   Book cpp("명품C++", 10000);
   Book java = cpp;
   java.set("명품자바", 12000);
   cpp.show();
   java.show();
   
   
}