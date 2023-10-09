const db = require('../db');
const express = require('express');
const app = express.Router();

// CREATE
// app.post('/', async (req, res) => {
//   try {
//     const { account_id, amount, timeStamp } = req.body;
//     await db.query('INSERT INTO transaction (account_id, amount, timeStamp) VALUES (?, ?, ?)', [account_id, amount, timeStamp]);
//     res.sendStatus(200);
//   } catch (err) {  
//     console.error(err);
//     res.sendStatus(500);
//   }
// });

//READ 5 TRANSACTIONS BASED ON USER_ID
app.get('/:account_id', async (req, res) => {
  const { account_id } = req.params;
  try {
    const [rows] = await db.query(`
      SELECT * FROM transaction
      WHERE account_id = ?
      ORDER BY timeStamp DESC
      LIMIT 5
    `, [account_id]);
    const transactions = rows.map(row => ({
      transaction_id: row.transaction_id,
      amount: row.amount,
      timeStamp: row.timeStamp,
      description: row.description
    }));
    res.json(transactions);
  } catch (err) {
    console.error(err);
    res.sendStatus(500);
  }
});

// READ ALL TRANSACTIONS
app.get('/', async (req, res) => {
  try {
    const [rows] = await db.query('SELECT * FROM transaction');
    res.json(rows);
  } catch (err) {
    console.error(err);
    res.sendStatus(500);
  }
});

// READ ONE TRANSACTION
app.get('/:trans_id', async (req, res) => {
  try {
    const { trans_id } = req.params;
    const [rows] = await db.query('SELECT * FROM transaction WHERE trans_id = ?', [trans_id]);
    res.json(rows);
  } catch (err) {
    console.error(err);
    res.sendStatus(500);
  }
});

// UPDATE
app.put('/:trans_id', async (req, res) => {
  try {
    const { account_id, amount, timeStamp } = req.body;
    const { trans_id } = req.params;
    await db.query('UPDATE transaction SET account_id = ?, amount = ?, timeStamp = ? WHERE trans_id = ?', [account_id, amount, timeStamp, trans_id]);
    res.sendStatus(200);
  } catch (err) {
    console.error(err);
    res.sendStatus(500);
  }
});

// DELETE
app.delete('/:trans_id', async (req, res) => {
  try {
    const { trans_id } = req.params;
    await db.query('DELETE FROM transaction WHERE trans_id = ?', [trans_id]);
    res.sendStatus(200);
  } catch (err) {
    console.error(err);
    res.sendStatus(500);
  }
});

app.get('/', async (req, res) => {
  try {
    const [rows] = await db.query('SELECT * FROM trasaction WHERE account_id = ? LIMIT 0,5', [account_id]);
    res.json(rows);
  } catch (err) {
    console.error(err);
    res.sendStatus(500);
  }
});

// BALANCE UPDATE AND NEW TRANSACTION
app.post('/:account_id', async (req, res) => {
  try {
    const account_id = req.params.account_id;
    const { amount } = req.body;
    const [rows] = await db.query('SELECT * FROM account WHERE account_id = ?', [account_id]);
    const currentBalance = rows[0].balance;
    const newBalance = currentBalance - amount;
    if (newBalance < 0) {
      return res.status(400).send({ error: 'Insufficient funds' });
    }
    await db.query('UPDATE account SET balance = ? WHERE account_id = ?', [newBalance, account_id]);
    const timeStamp = new Date().toISOString().slice(0, 19).replace('T', ' ');
    await db.query('INSERT INTO `BankSimul`.`transaction` (`account_id`, `amount`) VALUES (?, ?)', [account_id, amount]);
    res.status(200).json({ message: 'Withdrawal successful' });
  } catch (err) {
    console.error(err);
    res.sendStatus(500);
  }
});



module.exports = app;


// INSERT INTO `BankSimul`.`transaction` (`account_id`, `amount`) VALUES (?, ?);
// UPDATE account SET balance = ? WHERE account_id = ?'