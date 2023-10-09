// Import the 'mysql2/promise' library
const mysql = require('mysql2/promise');

// Create a database connection pool using the 'createPool' method of the 'mysql2/promise' library
const db = mysql.createPool({
    host: 'localhost', // The hostname of the MySQL server
    user: 'root', // The username used to authenticate with the MySQL server
    password: 'rootuser', // The password used to authenticate with the MySQL server
    database: 'BankSimul' // The name of the MySQL database to use
});

// Export the database connection pool so it can be used in other modules
module.exports = db;
