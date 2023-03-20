//HW2
//code by sepehr noroozi
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int publisherId = 1;
int bookId = 1;
int libraryId =1;

enum BookType 
{ 
	SCIENTIFIC , 
	CRIME , 
	FANTASY , 
	HORROR , 
	CLASSICS };	//defines the book types

class Publisher 
{	//static fields
	private:
		int id;	//publishers id to find it easier
		string name; //publishers name
		string location; //publishers address
	//constructor
	public:
		Publisher(string name, string location)
		{	
			this->id =publisheId++;
			this->name = name;
			this->location = location;
		}
		void pubSetter(string name , string location)
		{
			this->name = name;
			this->location = location;
		}
		void pubShowInfo()
		{
			cout << this->name << " " << this->location ;
		}
};

class Book
{	private:
		int id;
		string name ;
		BookType type;
		Publisher publisher ;
		bool borrowed;
	public:
	Book(string name, Publisher publisher, BookType type)
		{
		this->name = name; 
		this->id = bookId++;
		this->publisher = publisher;
		this->type = type;
		}
	void showInfo()
	{
		cout << id << ". " << name << endl;
	}
};

class Member()
{
	private:
		string id; //identification id
		string name; 
		vector<Book> books; //borrowed books
		
	public:
		Member(string id, string name)
		{
    	//TODO
    	this->id = id;
    	this->name =name;
    	//what should i do with vector?
		}
};

class Library()
{
	private:
		int id = libraryId++;
		string name;
		vector<Book> books;
		int position;
	Library(string name, int position)
	{
    //TODO
	}
	void searchBookByName()
	{
		
	//TODO
	}
	void returnAvailableBooks()
	{
	//TODO
	}
	viud addBook()
	{
	//TODO
	}
	void returnBookByType()
	{
	//TODO
	}
	//if needed should define more methods
};

class LibrarieHandler()
{
	void createLibrary(string name, int position)
	{
    //TODO
	}
	void addBook(int libId, string name, Publisher publisher, BookType type)
	{
    //TODO
	}
	void addBook(int libId, Book book)
	{
    //TODO
	}
	void addMember(string name, string id)
	{
    // TODO
	}
	vector<Book> getAllBooks(int libId)
	{
    // TODO
	}
	string getAllBooksInfo(int libId)
	{
    // TODO
	}
	vector<Book> filterByType(int libId, BookType type)
	{
    // TODO
	}
	string filterByTypeAndShowInfo(int libId, BookType type)
	{
    // TODO
	}
	bool borrow(string memberId, int libraryId, string name)
	{
    //TODO
	}
	bool returnBook(string memberId, int libraryId, string name)
	{
    //TODO
	}
	public int size()
	{
    // TODO
	}
	Library findNearestLibraryByPosition(string name, int position)
	{
    // TODO
	}
	string findLibrariesHaveBook(string name, int position)
	{
    //TODO
	}
};

int main()
{
	return 0;
}