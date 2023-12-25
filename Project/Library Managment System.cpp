#include <iostream>
#include <cstring>
#include <fstream>
#include <conio.h>
using namespace std;
struct BST{
	int bookID;
	string bookName;
	double bookPrice;
	int quantity;
	int serial;
	string bookAuthor;
	BST* right; 
	BST* left;
};

struct user {
	string userName;
	string pass;
	bool isAdmin;
	user *next;
};
struct person{
	string name;
	int age;
	string issue_date;
	int issue_id;
	int BookID;
};

const int arraySize = 7;
BST *hashArray[arraySize];
const char *fileName = "data.dat";
const char *userFile = "users.dat";
const char *rentfile = "rent.dat";
const char *issuefile = "issue.dat";
user *firstUser = NULL;
FILE * pFileTXT;
person *queue[arraySize];
int li=-1;
int graph[7][7];
int city;
/////////////////////////////////prototypes//////////////////////////////////////////////////////
void insertInHash(BST *);
BST * getBook(int,string,string,double,int);
void findInHash(BST *);
BST * getBook();
void insert(BST *, BST *);
void search(BST *, BST *);
void preorder(BST *);
void inorder(BST *);
double TotalBooks(BST *);
double DisplayBookTotal();
double TotalPrice(BST *);
double DisplayPriceTotal();
void postorder(BST *);
void displayAll();
void deleteBook(BST *,int);
void deleteInHash(int);
string convertToString(char *);
void saveFile();
void saveNodeOrder(BST*,FILE *);
void insertUser(user*);
user * authenticate(string,string);
void loadBooks();
void loadUsers();
void login();
void mainMenu(user *);
void issuebook();
void DisplayIssued();
void deleteInHash(int);
void deleteMenu();



//////////////////////////////////////main menu/////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

void mainMenu(user *currentUser) {
	
	char choice;
	while (choice != '0') {
		system("cls");
	
	cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t    Current User:  " << currentUser->userName<<endl;
	cout << "\t\t\t\t\t~========================================================================~" << endl;
	cout	<< "\t\t\t\t\t||" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "||" << endl
		<< "\t\t\t\t\t||" << "  " << "1: " << "View Books " << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t"<< "||" << endl
		<< "\t\t\t\t\t||" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "||" << endl
		<< "\t\t\t\t\t||" << "  " << "2: Issue A Book            " << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "||" << endl
		<< "\t\t\t\t\t||" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "||" << endl
		<< "\t\t\t\t\t||" << "  " << "3: search a book " << "\t" << "\t" << "\t" << "\t" << "\t" << "\t\t" << "||" << endl
		<< "\t\t\t\t\t||" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "||" << endl;
		if (currentUser->isAdmin)	{
	cout<< "\t\t\t\t\t||" << "  " << "4: Total Number of Books " << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "||" << endl
		<< "\t\t\t\t\t||" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "||" << endl
		<< "\t\t\t\t\t||" << "  " << "5: Total Price of All Books " << "\t" << "\t" << "\t" << "\t" << "\t" << "||" << endl
		<< "\t\t\t\t\t||" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "||" << endl
		<< "\t\t\t\t\t||" << "  " << "6: Add Book " << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "||" << endl
		<< "\t\t\t\t\t||" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t"  << "||" << endl
		<< "\t\t\t\t\t||" << "  " << "7: Details of Issued Books " << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "||" << endl
		<< "\t\t\t\t\t||" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "||" << endl; 
	cout<< "\t\t\t\t\t||" << "  " << "8: Delete Book " << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "||" << endl
		<< "\t\t\t\t\t||" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "||" << endl;
}
	
	cout<< "\t\t\t\t\t||" << "  " << "0: back " << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" <<"\t"<< "||" << endl
				<< "\t\t\t\t\t||" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "||" << endl
		 << "\t\t\t\t\t~========================================================================~" << endl;
	

		
		 choice=getch();
		
		switch (choice) {
			case '0':
			
				break;
			case '1':
				displayAll();
				break;
			case '2':
				issuebook();
				
				break;
			case '3':{
				system("cls");
				BST *fbook=new BST;
				cout<<"Enter book id you want to search ";
				cin>>fbook->bookID;
					findInHash(fbook);  
				break;}
			case '4':
				if(!currentUser->isAdmin){
				cout << "\nExiting\nEntered Wrong Choice..\n";
				break;
		}
				double dbt;
				dbt=DisplayBookTotal();
				cout << "||======================================================================||" << endl;
				cout << "  The Total Number of Books are: " << dbt ;
				cout << "\n||======================================================================||" << endl;	
				break;
			case '5':
					if(!currentUser->isAdmin){
				cout << "\nExiting\nEntered Wrong Choice..\n";
				break;
		}
				double dpt;
				dpt=DisplayPriceTotal();
				cout << "||======================================================================||" << endl;
				cout << "  The Total Price of Books is: Rs." << dpt ;
				cout << "\n||======================================================================||" << endl;	
				break;
			case '6':
					if(!currentUser->isAdmin){
				cout << "\nExiting\nEntered Wrong Choice..\n";
				break;
		}
		system("cls");
				insertInHash(getBook());
				break;
			case '7':
					if(!currentUser->isAdmin){
				cout << "\nExiting\nEntered Wrong Choice..\n";
				break;
		}
		system("cls");
				DisplayIssued();
				break;
	
			case '8':
					if(!currentUser->isAdmin){
				cout << "\nExiting\nEntered Wrong Choice..\n";
				break;
		}
		system("cls");
				deleteMenu();
			
				 break;
			default:
				cout << "\nExiting\nEntered Wrong Choice..\n";
				break;
			
		}
		cout<<"\n\n\n\tPress Enter to Return back...\n";
getch();
	}
}

///////////////////////////////////////login/////////////////////////////////////////////////////////
//Login is loaded in main menu so this method will load in main()../////////////////////////////////

void login() {
	
	//sign is declared as user becuase it will stored value of type user
	user *sign = NULL;

	while (sign == NULL) {
		cout << "\n\n\t\t\t\t\t\tEnter 4 Digit Pin: ";
		string p;
		char ch;
	ch=_getch();
	int i=0;
for(int i=0;i<4;i++){
      p.push_back(ch);
      cout << '*';
      ch = _getch();
   }
		//sign will store user that will be available in USER TYPE varibale called firstuser..
		sign = authenticate("Librarian",p);
		if (sign == NULL ) cout << "  Invalid Pin... Enter Again...\n";
		else {
			//Enter Main Menu while passing the user 
			mainMenu(sign);
		}
	}
	}
	
///////////////////////////////////////////insert user////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
void insertUser(user *newUser) {
	user *temp = firstUser;
	if (temp == NULL) 
	firstUser = newUser;
	else {
		while (temp->next != NULL) 
		temp = temp->next;
		temp->next = newUser;
	}
}

///////////////////////////////////////////load books///////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
void loadUsers() {
	FILE *users = fopen(userFile,"r");
	char userName[256];
	char pass[256];
	int isAdmin;
	//username and pass addresses will passed thorugh array while isAdmin will not pass address so we use "&" sign//
	while (fscanf(users,"%s %s %d",userName,pass,&isAdmin) == 3) {
		user *tempUser = new user;
		tempUser->userName = userName;
		tempUser->pass = pass;
		//this will check wheather user is an admin or normal user..
		tempUser->isAdmin = isAdmin == 1;
		tempUser->next = NULL;
		//after reading user from files it will send in to insertUser() method;//
		insertUser(tempUser);
	}
}

///////////////////////////////////////get boook for loading book///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

BST * getBook(int id, string name, string auth, double price, int quantity) {
	BST * newBook = new BST;
	newBook->bookID = id;
	newBook->bookName = name;
	newBook->bookAuthor = auth;
	newBook->quantity = quantity;
	newBook->bookPrice = price;
	newBook->left = NULL;
	newBook->right = NULL;
	return newBook;
}


///////////////////////////////////get book for adding new book/////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
BST * getBook() {
	BST * newBook = new BST;
	cout << "\nEnter Book ID: ";
	cin >> newBook -> bookID;

	cout << "\nEnter Book Name: ";
	cin >> newBook ->bookName;

	cout << "\nEnter Book Author: ";
	cin >> newBook->bookAuthor;

	cout << "\nEnter Book Price: ";
	cin >> newBook->bookPrice;

	cout << "\nEnter Quantity: ";
	cin >> newBook->quantity;

	newBook->left = NULL;
	newBook->right = NULL;
	
	return newBook;
}
///////////////////////////////////////////insert//////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
void insert(BST *curr,BST *n){
	
	if (curr->bookID<n->bookID){
		if (curr->right==NULL)
			curr->right = n;
		else
			insert(curr->right,n);
	}
	else{
		if (curr->left==NULL)
			curr->left = n;
		else
			insert(curr->left,n);
	}
}
//////////////////////////////////////////insert in hash//////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

void insertInHash(BST * node) {
	
	int index = node->bookID % arraySize;
	BST * treeIterator = hashArray[index];
	if (treeIterator == NULL) {
		hashArray[index] = node;
	}
	else {
		//if that index is not NULL then node placing at  that index will become root and coming node will follow itrator till null and place when node->next is null.//
		insert(treeIterator, node); //chaining to prevent hash collusion
	}
	
}

/////////////////////////////////////convert to string//////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
string convertToString(char * chars) {
	int i = 0;
	string toReturn = "";
	while (chars[i] != '\0') {
		toReturn += chars[i];
		i++;
	}
	return toReturn;
}

//////////////////////load users//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

void loadBooks() {
	FILE *myFile = fopen(fileName,"r");
//file will be read line by line.//
	for (int i = 0 ; i< arraySize; i++) hashArray[i] = NULL;
	char tempName[256];
	char tempAuthor[256];
	int id;
	int quantity;
	double price;
	string a,b;
//name and author is taken in character array because it's c method FSCANF so name and author will taken in array  and converted into strigng by converToString method 
	while (fscanf(myFile,"%d %s %s %lf %d",&id,tempName,tempAuthor,&price,&quantity) == 5) {
		a = convertToString(tempName);
		b = convertToString(tempAuthor);
		
		insertInHash(getBook(id,a,b,price,quantity));
	}

}

/////////////////////////////////////////////authenticate///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

user * authenticate(string user, string pass) {
	struct user *t = firstUser;
	while (t != NULL) {
		if (t->userName.compare(user) == 0) {
			if (t->pass.compare(pass) == 0) return t;
			else return NULL;
		} t = t->next;
	}
	return NULL;
}

/////////////////////////////////////////view all books for buyer/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

void displayAll() {
	system("cls");
	int order;
	for (int i = 0; i < arraySize; i++)
		if (hashArray[i] != NULL) {
				inorder(hashArray[i]);
		}
}

////////////////////////////////////// display order////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

void inorder(BST* point){
	if(point!=NULL){
		inorder(point->left);
			cout << "||======================================================================||" << endl;
		cout << "   Book ID: " << point->bookID << "\tBook Name: " << point->bookName<<"\t\t" << "\n   Book Author: " << point->bookAuthor<<"\t\t\t\t\t";
		cout << "\n   Price: " << point->bookPrice << "\tQuantity: " << point->quantity << "\t\t\t\t\t\t\n";
		cout << "||======================================================================||" << endl;
		inorder(point->right);		
	}		
}


////..................DELETE A BOOK................................................
///..........................................................................................................
void deleteInHash(int bookID) {
	int index = bookID % arraySize;
	if (hashArray[index] != NULL) deleteBook(hashArray[index],bookID);
}

void deleteMenu() {
	cout << "\nEnter Book ID";
	int bookID;
	cin >> bookID;
	deleteInHash(bookID);
}

void deleteBook(BST * root,int bookID) {
	BST * followNode;
	BST * foundNode;

	/*
	Find the node and the node that follows it
	*/

	followNode = foundNode = root;

	while (foundNode != NULL && foundNode->bookID != bookID) {
		followNode = foundNode;
		
		if (foundNode->bookID > bookID) foundNode = foundNode -> left;
		else foundNode = foundNode -> right;


	}

	/* Check If Leaf Node...wont have any value at right or left...leaf node will be deleted by only cutting one link*/
	if (foundNode->left == NULL && foundNode->right == NULL) {
		if (followNode->right == foundNode) followNode -> right = NULL;
		else followNode -> left = NULL;
		delete foundNode;
		return;
	}

	/* Check If In Branch ........ONE CHILD*/

	if (foundNode -> left == NULL) {
		if (followNode -> right == foundNode) {
			followNode->right = foundNode->right;
		} else followNode->left = foundNode->right;
		delete foundNode;
		return;
	} else if (foundNode->right == NULL) {
		if (followNode->left == foundNode) {
			followNode->left = foundNode->left;
		} else followNode->right = foundNode->left;
		delete foundNode;
		return;
	}

	/* Node has both child */
	BST * leastIterator = foundNode->right;
	while (leastIterator->left != NULL) leastIterator = leastIterator->left;
	/* Swap value of both nodes */
	int tempQuantity, tempID;
	double tempPrice;
	string tempName, tempAuthor;
	tempQuantity = foundNode->quantity;
	tempID = foundNode->bookID;
	tempPrice = foundNode->bookPrice;
	tempName = foundNode->bookName;
	tempAuthor = foundNode->bookAuthor;

	foundNode->quantity = leastIterator->quantity;
	foundNode->bookID = leastIterator->bookID;
	foundNode->bookName = leastIterator->bookName;
	foundNode->bookPrice = leastIterator->bookPrice;
	foundNode->bookAuthor = leastIterator->bookAuthor;

	leastIterator->bookAuthor = tempAuthor;
	leastIterator->bookName = tempName;
	leastIterator->bookPrice = tempPrice;
	leastIterator->bookID = tempID;
	leastIterator->quantity = tempQuantity;

	/* Send least Iterator for deletion via recursion */
	deleteBook(root,leastIterator->bookID);
}

/////...........................TOTAL BOOKS........................................................
//.................................................................................................
double DisplayBookTotal(){
	system("cls");
	static double tb=0;
	for (int i = 0; i < arraySize; i++){
		if (hashArray[i] != NULL) {
			tb=TotalBooks(hashArray[i]);
		}
	}
	return tb;
	
}

double TotalBooks(BST* point){
	static double totalb=0;
	if(point!=NULL){
		TotalBooks(point->left);
		totalb+=point->quantity;
		//left was visted instead of right
		TotalBooks(point->right);
	}
	return totalb;
}

////......................................TOTAL PRICE..........................................,,,,,,
///..................................................................................................
double TotalPrice(BST* point){
	static double totalp=0;
	if(point!=NULL){
		TotalPrice(point->left);
		totalp+=point->bookPrice;
		TotalPrice(point->right);
	}
	return totalp;
}

double DisplayPriceTotal(){
	system("cls");
	static double tp=0;
	for (int i = 0; i < arraySize; i++){
		if (hashArray[i] != NULL) {
			tp=TotalPrice(hashArray[i]);
		}
	}
	return tp;
	
}

/////.................................ISSUE BOOK.......................................................
//....................................................................................................
void issuebook(){
	system("cls");
	 person *curr = new person();
	cout<<"\n    Enter Person Name: ";
	cin>>curr->name;
	cout<<"\n    Enter Person Age: ";
	cin>>curr->age;
	cout<<"\n    Enter Issue ID: ";
	cin>>curr->issue_id;
	cout<<"\n    Enter Issue Date: ";
	cin>>curr->issue_date;
	cout<<"\n    Enter The ID of the Book To Be Issued: ";
	cin>>curr->BookID;
	cout << "||======================================================================||" << endl;
		pFileTXT = fopen ("issue.dat","a");
				fprintf(pFileTXT,"\n");// newline
				fprintf (pFileTXT, "%s %d %d %s %d",curr->name.c_str(),curr->age,curr->issue_id,curr->issue_date.c_str(),curr->BookID);
				fclose (pFileTXT);

}

//...............................................DISPLAY ISSUED BOOKS...................................
//......................................................................................................
void DisplayIssued(){
	person *curr = new person();
	BST *t =new BST();
	int indexfind;
	cout << "\n||======================================================================||" << endl;
			indexfind=curr->BookID%arraySize;
		char nm[20],dt[20];
		int ag,id,bd;
		FILE *users = fopen(issuefile,"r");
		while (fscanf(users, "%s %d %d %s %d",nm,&ag,&id,dt,&bd) == 5){
			curr->name=nm;
			curr->age=ag;
			curr->issue_id=id;
			curr->issue_date=dt;
			curr->BookID=bd;
		cout << "   Person Who Issued The Book is: " << curr->name << "\n   Age: " << curr->age<<"\t\t" << "\n   The Issue ID is: " << curr->issue_id<<"\t\t\t\t\t";
		    cout << "\n   The Issue Date Is: " << curr->issue_date << "\t\n   The ID of the Issued Book is: " << curr->BookID << "\n\n";
			t->bookID=bd;
		findInHash(t);
		cout<<endl<<endl<<endl;

		}
		cout << "||======================================================================||" << endl;		
}

///........................................serch book.................................................
//....................................................................................................
void findInHash(BST * node) {
	int index = node -> bookID % arraySize ;
	if (hashArray[index] == NULL) return ;
	else {
		 search(hashArray[index],node);
	}
}

void search(BST* temp, BST* point) {

if(temp == NULL ) {
     cout<<"\nNot Fount...\n";
} else if(temp->bookID == point->bookID) {
    cout<<"\n book name: "<<temp->bookName;
				 cout<<"\n book ID: "<<temp->bookID;
				 cout<<"\n author name: "<<temp->bookAuthor;
				 cout<<"\n price: "<<temp->bookPrice;	
} else if(point->bookID <= temp->bookID)  {
     return search(temp->left, point);
} else return search(temp->right,point);
}
///..............................................save file..............................................................
//........................................................................................................
void saveFile() {
	FILE *saveFile = fopen(fileName,"w");
	for (int i = 0; i < arraySize; i++)
		saveNodeOrder(hashArray[i],saveFile);
	fclose(saveFile);
}

void saveNodeOrder(BST * point,FILE *file) {
	if(point!=NULL){
		saveNodeOrder(point->left,file);
		fprintf(file,"%d %s %s %lf %d\n",point->bookID,point->bookName.c_str(),point->bookAuthor.c_str(),point->bookPrice,point->quantity);
		saveNodeOrder(point->right,file);	
	}	
}

///...........................................MAIN......................................................
///.....................................................................................................

int main() {
	
	
	system ("color 0e");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                  WELCOME TO                                           |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                          HITEC LIBRARY MANAGEMENT SYSTEM                              |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
getch();
while(true){
	system("CLS");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  HITEC LIBRARY MANAGEMENT SYSTEM \n\n";	
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> Login as Librarian                            |\n";
cout<<"\t\t\t\t\t\t|             2  >> Login as Customer                             |\n";
cout<<"\t\t\t\t\t\t|             3  >> Exit                                          |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
	char num;
	loadBooks();
	loadUsers();
	num=getch();
	
switch(num){
	case '1':{
		login();
		
		break;
	}
	case '2':{
		user *n=NULL;
	
		n = authenticate("Customer","123");
		mainMenu(n);
			break;
		
	}
	case '3':{
	system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                               THANK YOU FOR USING                                     |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                          HITEC  LIBRARY MANAGEMENT SYSTEM                             |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";



cout<<"\n";

		exit(0);
		break;
	}
	default:{

		break;
	}

}

	saveFile();
	getch();
}

}

///.........................................................................................................
//.......................................................the end.............................................
