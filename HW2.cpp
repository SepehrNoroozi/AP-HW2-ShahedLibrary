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
			this->id =publisherId++;
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
	string returnType()
	{
		return type;
	}
	void setBookName(string name )
	{
		this->name = name;
	}
	string getBookName()
	{
		return name;	
	}
	int returnBookId()
	{
		return id;
	}
	string returnBookPublisher()
	{
		return publisher;
	}
	bool returnIsBorrowed()
	{
		return borrowed;
	}
};

class Member()
{
	private:
		string id; //identification id
		string name; 
		vector<Book> borrowedBooks; 
		
	public:
		Member(string id, string name)
		{
    	//TODO
    	this->id = id;
    	this->name =name;
    	books.max_size(5)
    	//what should i do with vector?
		}
		string returnId()
		{
			return id;
		}
		
};

class Library()
{
	private:
		int id ;
		string name;
		vector<Book> books;
		int position;
	Library(string name, int position)
	{
	this->id = libraryId++;
    this->name = name;
    this->position = position;
	}
	void searchBookByName()
	{
		cout << "enter the name of book: ";
		cin >> string bookName ;
		if (bookName == name) cout << getBookName();
		
	}
	void returnAvailableBooks()
	{
		cout << "Available books are as follows: \n" << books[] << endl;
	}
	void addBook(int id, string name, BookType type, Publisher publisher)
	{
		Book newBook(id , name, type, publisher)
		books.push_back(bookInfo);
	}
	void returnBookByType()
	{
	vector<Book> booksByType(booksByType type )
	{
		vector<Book> books;
		for(int i=0 ; i<this->books ; i++)
		{
			if(this->books[i].showType()==type)
			{
				books.push_back(this->books[i]);
			}
		}
	}
		}
	string returnName()
	{
		return name;
	}
	int returnPosition()
	{
		return position;
	}
	void addBook(Book book)
	{
		books.push_back(book)
	}
	string returnLibID()
	{
		return id;
	}
	//define more methods if needed
	};

class LibrariesHandler()
{
	private:
		vector<Book> books;
		vector<Member> members;
		vector<Library> libraries;
	public:
	void createLibrary(string name, int position)
	{
		Library library(name , position);
    	bool isSameName = false;
    	bool isSamePose = false;
    	for (int i =0 ;i< libraries.size();i++ )
    	{
    		if (name == libraries[i].returnName()) isSameName=true;
    		if (position == libraries[i].returnPosition()) isSamePose=true;
		}
		if (isSameName) throw "A library with this name already exists";
		else if (isSamePose) throw "There is now a library in this place";
		else libraries.push_back(library);
	}
	void addBook(int libId, string name, Publisher publisher, BookType type)
	{
    	Book book(name , publisher , type);
    	libraries[libId].addbook(book);
	}
	void addBook(int libId, Book book)
	{
    	libraries[libId].addbook(book);
	}
	void addMember(string name, string id)
	{
		Member member(name , id);
    	bool isSameId = false;
    	Member member(name , id);
    	for (int i=0 ; i < members.size(); i++)
    	{
    		if (id == members[i].returnId()) isSameId = true;
		}
		if (isSameId) throw "there is member with mutual id!";
		else members.push_back(member);

	}
	vector<Book> getAllBooks(int libId)
	{
		for (int i = 0 ; i < library.size() ; i++)
		{
			cout << books << endl;
		}
	}
	string getAllBooksInfo(int libId)
	{
		bool libExist = false;
		for (int i = 0 ; i < library.size() ; i++)
		{
			int x = 1
			if (libId == library.returnLibId()) libExist = true;
			else throw "no library with that id exists!"
			if (libExist) cout << x << "." << library[i] << endl;
			x++;
		}
	}
	vector<Book> filterByType(int libId, BookType type)
	{
    	Book book(id, name, type, publisher, borrowed)
    	bool isThatType = false;
    	for (i = 0 ; i < library.size() ; i++)
    	{
    		if ( books.returnType() == type) isThatType =true;
    		if (isThatType) cout << books[i] << endl;
    		else throw "[]";
		}
		
	}
	string filterByTypeAndShowInfo(int libId, BookType type)
	{
    	Book book(id, name, type, publisher, borrowed)
    	bool isThatType = false;
    	for (i = 0 ; i < library.size() ; i++)
    	{
    		int x = 1;
    		if ( books.returnType() == type) isThatType =true;
    		if (isThatType) 
    		{
    			cout << x <<books[i].getBookName() << endl;
			}
			else throw " " ;
		}
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