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
			vector<Book> books;
		public:
			Book(string name, Publisher publisher, BookType type)
				{	
					bookId++;
					this->name = name; 
					bookId = this->id;
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
			void addBookToLib(Book book)
				{
					books.push_back(book);
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
					libraryId++;
					libraryId = this->id;
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
			void addBookToLib(Book book)
				{
					books.push_back(book);
				}
			void addBook(int id, string name, BookType type, Publisher publisher)
				{
					Book newBook(name, publisher,type);
					books.push_back(newBook);
				}
			vector<Book> booksByType(BookType type)
				{
					vector<Book> books;
					for(int i=0 ; i < (this->books).size() ; i++)
						{
							if(this->books[i].returnType() == type)
								{
									books.push_back(this->books[i]);
								}		
						}
				}
			void returnBookByType(BookType type)
				{
					
					for ( int i = 0 ; i < booksByType(type).size() ; i++)
						{
							int x = 1;
							cout << x << (books[i].getBookName()) << (books[i].returnType()) << endl;
							x++;
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
			int returnLibID()
				{
					return id;
				}
				//define more methods if needed
	};

class LibrariesHandler
	{
		private:
			vector<Member> members;
			Book book(string name, Publisher publisher,BookType type);
		public:
			vector<Book> books;
			vector<Library> libraries;
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
			    	libraries[libId].addBookToLib(book);
				}
			void addBook(int libId, Book book)
				{
			    	libraries[libId].addBookToLib(book);
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
			bool returnBook(string memberId, int libraryId, string name)
				{
			    	bool bookIsAvailable = false;

					for (int i = 0 ; i < libraries.size() ; i++)
				    	{
				    		if(libraries[i].returnLibID()==libraryId)
							{
								for(int j = 0 ; j < books.size();j++)
								{
									if(name == books[j].getBookName()) 
										{
											bookIsAvailable = true;
										}
				    				if (!bookIsAvailable) 
										{
											books[j].addBookToLib(books[j]);	
										}
								}
							}
						}
				}
			void size()
				{
					cout << "The number of libraries available is: " <<  libraries.size() << endl ;
				}
//			vector<Library> returnLibraries(string name,int position)
//				{
//					return libraries(name, position);
//				}
//			vector<Book> returnBooks(string name, Publisher publisher, BookType type)
//				{
//					return books(name, publisher, type);
//				}
	};
Library findNearestLibraryByPosition(string name, int position)
	{
   		int userPose , maxPose = 100000;
   		Library nearestLib(string name, int position);
   		bool nearLibChanges = false;
   		string newEntryBook;
		vector<Book> books;
		vector<Library> libraries; 
		      	
    	cout << "enter your position: " ; 
   		cin >> userPose ; 
 	 	cout << "enter book name: ";
   		cin >> newEntryBook;
    	for (int i = 0 ; i < libraries.size() ; i++)
    		{
    			for (int j = 0 ; i < books.size() ; j++)
    				{
    					if (newEntryBook == books[j].getBookName() && abs(userPose - libraries[i].returnPosition()) < maxPose) 
    						{ 
    							maxPose = abs(userPose - libraries[i].returnPosition());
    							nearestLib(name , position) = libraries[i];
    							nearLibChanges =true;
    						}
						else if (newEntryBook == books[j].getBookName() && abs(userPose - libraries[i].returnPosition()) == maxPose)
							{
								if (libraries[i].returnLibID() < nearestLib(name , position).returnLibID())
									{
										return nearestLib(name , position);
									}
							}
						else if (newEntryBook == books[j].getBookName() && abs(userPose - libraries[i].returnPosition()) == maxPose)
							{
								if (libraries[i].returnLibID() > nearestLib(name , position).returnLibID())
									{
										return libraries[i];
									}
							}
						//here should be a return of -1 value
					}
			}
    	
	}
string findLibrariesHaveBook(string name, int position)
	{
    	//TODO
    	int userPose ,  distance;
   		Library nearestLib(string name, int position);
   		bool nearLibChanges = false;
   		string newEntryBook;
   		vector<Book> books;
		vector<Library> libraries;
   		
    	cout << "enter your position: " ; 
   		cin >> userPose ; 
 	 	cout << "enter book name: ";
   		cin >> newEntryBook;
   		
   		for (int i = 0 ; libraries.size() ; i++)
   			{
   				for (int j = 0 ; i < books.size() ; j++)
    				{
    					if (newEntryBook == books[j].getBookName()) 
    						{
    							int x = 1 ;
    							distance =  abs(userPose - libraries[i].returnPosition());
    							cout << x <<libraries[i].returnName() << distance << endl;	
    						}
					}
			}
	}

int main()
	{
		return 0;
	}
