//HW2
//code by sepehr noroozi
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

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
		CLASSICS
	};	//defines the book types

class Publisher
	{
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
			Publisher()
				{
					this->id= publisherId++;
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
	{	
		private:
			int id;
			string name;
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
			BookType returnType()
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
			Publisher returnBookPublisher()
				{
					return publisher;
				}
			bool returnIsBorrowed()
				{
					return borrowed;
				}
	};

class Member
	{
		private:
			string id; //identification id
			string name; 
			vector<Book> borrowedBooks; 
		
		public:
			Member(string id, string name)
				{
    				this->id = id;
    				this->name =name;
				}
			string returnId()
				{
					return id;
				}
			vector<Book> getBorrowedBook()
				{
					return borrowedBooks;
				}
			vector<Book> addToBorrowedBooks(Book book)
				{
					borrowedBooks.push_back(book);
				}
		
	};

class Library
	{
		private:
			int id ;
			string name;
			vector<Book> books;
			int position;
		public:
			Library(string name, int position)
				{
					this->id = libraryId++;
				    this->name = name;
				    this->position = position;
				}
			void searchBookByName()
				{
					string bookName;
					bool isValid=false;
					cout << "enter the name of book: ";
					cin >> bookName ;
					for (int i = 0 ; i < books.size() ; i++)
						{
							if (bookName == books[i].getBookName()) cout << books[i].getBookName();
						}
				}
			void returnAvailableBooks()
				{
					for (int i = 0 ; i < books.size() ; i++)
						cout << "\n"<< books[i].getBookName() << endl;
				}
			void addBook(int id, string name, BookType type, Publisher publisher)
				{
					Book newBook(name, publisher,type);
					books.push_back(newBook);
				}
			void returnBookByType()
				{
					vector<Book> booksByType(BookType type )
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
			vector<Book> returnAllBooks()
				{
					return books;
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
					books.push_back(book);
				}
			int returnLibID()
				{
					return id;
				}
				//define more methods if needed
	};

class LibrariesHandler
	{
		private:
			vector<Book> books;
			vector<Member> members;
			vector<Library> libraries;
			Book book(string name, Publisher publisher,BookType type);
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
			    	libraries[libId].addBook(book);
				}
			void addBook(int libId, Book book)
				{
			    	libraries[libId].addBook(book);
				}
			void addMember(string name, string id)
				{
					Member member(name , id);
			    	bool isSameId = false;
			    	for (int i=0 ; i < members.size(); i++)
		    			{
    						if (id == members[i].returnId()) isSameId = true;
						}
					if (isSameId) throw "there is member with mutual id!";
					else members.push_back(member);
				}
			vector<Book> getAllBooks(int libId)
				{
					return libraries[libId].returnAllBooks();
				}
			string getAllBooksInfo(int libId)
				{
					bool libExist = false;
					for (int i = 0 ; i < libraries.size() ; i++)
					{
						int x = 1;
						if (libId == libraries[i].returnLibID()) libExist = true;
						else throw "no library with that id exists!";
						if (libExist) cout << x << "." << libraries[i].returnName()<< endl;
						x++;
					}
				}
			vector<Book> filterByType(int libId, BookType type)
				{
			    	Book book(string name, Publisher publisher,BookType type);
			    	bool isThatType = false;
			    	for (int i = 0 ; i < libraries.size() ; i++)
				    	{
			    			if ( books[i].returnType() == type) isThatType =true;
    						if (isThatType) cout << books[i].getBookName() << endl;
				    		else throw "[]";
						}		
				}
			string filterByTypeAndShowInfo(int libId, BookType type)
				{
			    	Book book(string name, Publisher publisher,BookType type);
			    	bool isThatType = false;
			    	for (int i = 0 ; i < libraries.size() ; i++)
				    	{
				    		int x = 1;
				    		if ( books[i].returnType() == type) isThatType =true;
				    		if (isThatType) 
					    		{
					    			cout << x <<books[i].getBookName() << endl;
								}
					else throw " " ;
						}
				}
			bool borrow(string memberId, int libraryId, string name)
				{
			    	bool haveFiveBooks = false;	
			    	bool bookIsAvailable = false;

					for (int i = 0 ; i < libraries.size() ; i++)
				    	{
				    		if(name == books[i].getBookName()) bookIsAvailable = true;
				    		else throw "The book you are looking for is not available in any of the libraries!";
						}
					for (int i = 0 ; i < members.size() ; i++ )
						{		
							if (memberId == members[i].returnId());		
								{
									if (members[i].getBorrowedBook().size() == 5) haveFiveBooks = true;
									else if (members[i].getBorrowedBook().size() < 5) haveFiveBooks = false;
									if (haveFiveBooks) throw "You have borrowed the maximum allowed number of books!";
									else members[i].addToBorrowedBooks(books[i]);
								}
						}
				}
			void returnBook(string memberId, int libraryId, string name)
				{
			    	bool bookIsAvailable = false;

					for (int i = 0 ; i < libraries.size() ; i++)
				    	{
				    		if(name == books[i].getBookName()) 
								{
									bookIsAvailable = true;
								}
				    		if (!bookIsAvailable) 
								{
									libraries[i].addBook(Book book);	
								}
						}
				}
			void size()
				{
					cout << "The number of libraries available is: " <<  libraries.size() << endl ;
				}
Library findNearestLibraryByPosition(string name, int position)
	{
    	// TODO
   		int userPose , maxPose = 100000;
   		Library nearestLib;
   		bool nearLibChanges = false;
   		string newEntryBook;
		       	
    	cout << "enter your position: " ; 
   		cin >> position ; 
 	 	cout << "enter book name: ";
   		cin >> newEntryBook;
    	for (int i = 0 ; i < libraries.size() ; i++)
    		{
    			for (int j = 0 ; i < books.size() ; j++)
    				{
    					if (newEntryBook == books[j].getBookName() && abs(userPose - libraries[i].returnPosition()) < maxPose) 
    						{
    							abs(userPose - libraries[i].returnPosition()) = maxPose;
    							nearestLib = libraries[i];
    							nearLibChanges =true;
    						}
						else if (newEntryBook == books[j].getBookName() && abs(userPose - libraries[i].returnPosition()) == maxPose)
							{
								if (libraries[i].returnLibID() < nearestLib.returnLibID())
									{
										return nearestLib;
									}
							}
						else if (newEntryBook == books[j].getBookName() && abs(userPose - libraries[i].returnPosition()) == maxPose)
							{
								if (libraries[i].returnLibID() > nearestLib.returnLibID())
									{
										return libraries[i];
									}
							}
						else 
							{
								return -1;
							}
					}
			}
    	
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