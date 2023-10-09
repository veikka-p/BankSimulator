const db = require('../db');
const express = require('express');
const app = express.Router();



// CREATE
app.post('/', async (req, res) => {
  try {
    const { user_id, email, phone, address, name } = req.body;
    await db.query('INSERT INTO user (user_id, email, phone, address, name) VALUES (?, ?, ?, ?, ?)', [user_id, email, phone, address, name]);
    res.sendStatus(200);
  } catch (err) { 
    console.error(err);
    res.sendStatus(500);
  }
});

// READ
app.get('/', async (req, res) => {
  try {
    const [rows] = await db.query('SELECT * FROM user');
    res.json(rows);
  } catch (err) {
    console.error(err);
    res.sendStatus(500);
  }
});


// UPDATE
app.put('/:user_id', async (req, res) => {
  try {
    const { email, phone, address, name } = req.body;
    const { user_id } = req.params;
    await db.query('UPDATE user SET email = ?, phone = ?, address = ?, name = ? WHERE user_id = ?', [email, phone, address, name, user_id]);
    res.sendStatus(200);
  } catch (err) {
    console.error(err);
    res.sendStatus(500);
  }
});

// DELETE
app.delete('/:user_id', async (req, res) => {
  try {
    const { user_id } = req.params;
    await db.query('DELETE FROM user WHERE user_id = ?', [user_id]);
    res.sendStatus(200);
  } catch (err) {
    console.error(err);
    res.sendStatus(500);
  }
});

module.exports = app;