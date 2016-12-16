/**-------------------------------------------------------------------
*  Include mysql.h file local header file(declaration of class)
*------------------------------------------------------------------*/

#include "database.h"
using namespace std;

/**
*--------------------------------------------------------------------
*       Class:  MySQL
*      Method:  MySQL :: MySQL()
* Description:  Constructor to initialize database conectivity
*--------------------------------------------------------------------
*/

MySQL::MySQL()
{
	connect = mysql_init(NULL);
	MYSQL* output;
	if (!connect)
	{
		cout << "MySQL Initialization Failed" << endl;
	}
	else {
		cout << "MySQL Initialization Sucesfull" << endl;
	}

	output = mysql_real_connect(connect, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0);

	if (output)
	{
		cout << "Database: " << DATABASE << " Loaded" << endl;
	}

	else
	{
		cout << "Connection Failed (" << mysql_error(connect) << ")" << endl;
	}
}

/**
*--------------------------------------------------------------------
*       Class:  MySQL
*      Method:  MySQL :: ShowTables()
* Description:  Show tables in database
*--------------------------------------------------------------------
*/

void MySQL::ShowTables()
{
	/** Add MySQL Query */
	mysql_query(connect, "show tables");

	i = 0;

	res_set = mysql_store_result(connect);

	unsigned int numrows = mysql_num_rows(res_set);

	cout << " Tables in " << DATABASE << " database " << endl;

	while (((row = mysql_fetch_row(res_set)) != NULL))
	{
		cout << row[i] << endl;
	}
}

string MySQL::getUserPassword(string username) {
	char query [MAX_USERNAME_LENGTH*2+46] = "SELECT password FROM users WHERE username = '";
	char *part = &(query[strlen(query)]);
	mysql_real_escape_string(connect, part, username.c_str() , username.length());
	query[strlen(query)] = '\'';
	res_set = mysql_store_result(connect);
	mysql_query(connect, query);
	if (row = mysql_fetch_row(res_set)) {
		return row[0];
	}
}

/**
*--------------------------------------------------------------------
*       Class:  MySQL
*      Method:  MySQL :: ~MySQL()
* Description:  Destructor of MySQL class for closing mysql
*               connection
*--------------------------------------------------------------------
*/

MySQL :: ~MySQL()
{
	mysql_close(connect);
}