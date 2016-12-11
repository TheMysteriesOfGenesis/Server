/**-------------------------------------------------------------------
*  Include mysql.h file local header file(declaration of class)
*------------------------------------------------------------------*/

#include "database.h"

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