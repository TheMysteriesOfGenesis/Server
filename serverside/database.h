/**-------------------------------------------------------------------
*  Include database-detail.h and other files
*------------------------------------------------------------------*/

#include "header.h"
#include "database-detail.h"
#include <string>

/**
* ===================================================================
*        Class:  MySQL
*  Description:  MySQL class for database accessability
* ===================================================================
*/

class MySQL
{
protected:
	/** MySQL connectivity Variables */
	MYSQL *connect;
	MYSQL_RES *res_set;
	MYSQL_ROW row;

	unsigned int i;

public:
	/** MySQL Constructor */
	MySQL();

	/** Function to show tables in database */
	void ShowTables();

	/** MySQL Destructor */
	~MySQL();
};