//HW2
//code by sepehr noroozi
#include <iostream>
using namespace std;

enum BookType {SCIENTIFIC , CRIME , FANTASY , HORROR , CLASSICS};	//defines the book types

class Publisher 
{	//static fields
	public:
		int id;	//publishers id to find it easier
		string name; //publishers name
		string location; //publishers location
	//constructor
	Publisher(string name, string location)
{
	//TODO
	for ()
}
};

class Book
{	public:
		int id;
		string name;
		BookType type;
		Publisher publisher;
		bool borrowed;
	Book(string name, Publisher publisher, BookType type)
	{
	//TODO
	}
	showInfo()
	{
		
	}
};

class Member()
{
	public:
		string id;
		string name;
		vector<Book> books;
	Member(string id, string name)
	{
    //TODO
	}
};

class Library()
{
	public:
		int id;
		string name;
		vector<Book> books;
		int position;
	Library(string name, int position)
	{
    //TODO
	}
	void searchBooks()
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

