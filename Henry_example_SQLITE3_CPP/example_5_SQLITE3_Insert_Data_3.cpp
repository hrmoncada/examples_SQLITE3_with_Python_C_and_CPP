/*  https://www.geeksforgeeks.org/sql-using-c-c-and-sqlite/
Compile:
$ g++ example_SQLITE3_program_name.c -o out -l sqlite3

Execute:
$ ./out
*/

#include <iostream> 
#include <sqlite3.h> 
using namespace std;

int main(void) {
    sqlite3 *DB;
    char *messaggeError = 0; // created error message

/************************************************************/
/* sqlite3_libversion(): Returns the SQLite library version */
/************************************************************/
    cout << "sqlite version = " << sqlite3_libversion() << endl; 

/************************************************************/
/*                     Open Database File                   */
/************************************************************/
    int exit = sqlite3_open("example.db", &DB);

// If exit is an integer, exit is equal to 0, it succeeded. If exit is equal to 1, database doesn’t exist yet. The database is going to be created in the same directory where the process was executed.
    if (exit) { 
        cout << "Error open DB " << sqlite3_errmsg(DB) << endl; // sqlite3_errmsg() function returns a description of the error.
        sqlite3_close(DB);
        return (1); 
    } else {
        cout << "Opened Database Successfully! "<< sqlite3_errmsg(DB) << endl; 
    }

/************************************************************/
/*             Insert Data - Create SQL statement           */
/************************************************************/
    string sql = "INSERT INTO COMPANY VALUES (1, 'Paul', 32, 'California', 20000.00 );"
                 "INSERT INTO COMPANY VALUES (2, 'Allen', 25, 'Texas', 15000.00 );"    
                 "INSERT INTO COMPANY VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" 
                 "INSERT INTO COMPANY VALUES (4, 'Mark', 25, 'Rich-Mond', 65000.00 );";

// sqlite3_exec() : This routine provides a quick, easy way to execute SQL commands provided by sql argument which can consist of more than one SQL command. 
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError); 

// If exit is an integer equal to 0, it succeeded (SQLITE_OK=0). If exit is equal to 1 (SQLITE_OK=1), the database doesn’t exist yet. 
    if (exit != SQLITE_OK) { 
        cout << "Error Insert" << endl; 
        sqlite3_free(messaggeError); 
    }  else {
        cout << "Records created Successfully!" << endl; 
    } 

// closes the database connection.
   sqlite3_close(DB);
   return 0;
}  
