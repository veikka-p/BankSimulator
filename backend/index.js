const db = require('./db');
const express = require('express');

const usersRouter = require('./routes/user');
const transactionRouter = require('./routes/transaction');
const bankCardRouter = require('./routes/bankCard');
const accountRouter = require('./routes/account');

const app = express();
const PORT = 3000;


app.use(express.json());
app.use('/users', usersRouter);
app.use('/transaction', transactionRouter);
app.use('/bankCard', bankCardRouter);
app.use('/account', accountRouter);


app.listen(PORT, () =>console.log(`Server running on port: http://localhost:${PORT}`));