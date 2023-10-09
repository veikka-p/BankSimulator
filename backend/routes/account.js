const db = require('../db');
const express = require('express');
const app = express.Router();

// CREATE
app.post('/', async (req, res) => {
  try {
    const { trans_id, account_id, amount, timeStamp } = req.body;
    const [result] = await db.query('INSERT INTO transaction (trans_id, account_id, amount, timeStamp) VALUES (?, ?, ?, ?)', [trans_id , account_id, amount, timeStamp]);
    res.status(200).json({ id: result.insertId });
  } catch (err) {
    console.error(err);
    res.sendStatus(500);
  }
});


// READ ALL ACCOUNTS
app.get('/', async (req, res) => {
  try {
    const [rows] = await db.query('SELECT * FROM account');
    res.json(rows);
  } catch (err) {
    console.error(err);
    res.sendStatus(500);
  }
});

// READ ONE ACCOUNT BY ACCOUNT ID 
app.get('/:account_id', async (req, res) => {
  try {
    const { account_id } = req.params;
    const [rows] = await db.query('SELECT * FROM account WHERE account_id = ?', [account_id]);
    res.json(rows[0]);
  } catch (err) {
    console.error(err);
    res.sendStatus(500);
  }
});

// READ ONE ACCOUNT BY USER ID 
app.get('/user/:user_id', async (req, res) => {
  try {
    const { user_id } = req.params;
    const [rows] = await db.query('SELECT * FROM account WHERE user_id = ?', [user_id]);
    res.json(rows[0]);
  } catch (err) {
    console.error(err);
    res.sendStatus(500);
  }
});

// ACCOUNT BALANCE
app.get('/:account_id', async (req, res) => {
  try {
    const { account_id } = req.params;
    const [rows] = await db.query('SELECT * FROM balance WHERE account_id = ?', [account_id]);
    res.json(rows);
  } catch (err) {
    console.error(err);
    res.sendStatus(500);
  }
});

// UPDATE
app.put('/:account_id', async (req, res) => {
  try {
    const { balance, user_id, credit } = req.body;
    const { account_id } = req.params;
    await db.query('UPDATE account SET balance = ?, user_id = ?, credit = ? WHERE account_id = ?', [balance, user_id, credit, account_id]);
    res.sendStatus(200);
  } catch (err) {
    console.error(err);
    res.sendStatus(500);
  }
});

// DELETE
app.delete('/:account_id', async (req, res) => {
  try {
    const { account_id } = req.params;
    await db.query('DELETE FROM account WHERE account_id = ?', [account_id]);
    res.sendStatus(200);
  } catch (err) {
    console.error(err);
    res.sendStatus(500);
  }
});

module.exports = app;