const db = require('../db');
const express = require('express');
const app = express.Router();

// CREATE
app.post('/', async (req, res) => {
    try {
      const { card_number, user_id, pinCode } = req.body;
      await db.query('INSERT INTO bankCard (card_number, user_id, pinCode) VALUES (?, ?, ?)', [card_number, user_id, pinCode]);
      res.status(201).json({ message: "Card added successfully" });
    } catch (err) {
      console.error(err);
      res.sendStatus(500);
    }
  });
  
// READ ALL
app.get('/', async (req, res) => {
    try {
    const [rows] = await db.query('SELECT * FROM bankCard');
      res.json(rows);
    } catch (err) {
      console.error(err);
      res.sendStatus(500);
    }
  });
  
// READ ONE
app.get('/:card_number', async (req, res) => {
    try {
      const { card_number } = req.params;
      const [rows] = await db.query('SELECT * FROM bankCard WHERE card_number = ?', [card_number]);
      if (rows.length === 0) {
        res.status(404).json({ message: "Card not found" });
      } else {
        res.json(rows[0]);
      }
    } catch (err) {
      console.error(err);
      res.sendStatus(500);
    }
  });
  
// UPDATE
app.put('/:card_number', async (req, res) => {
    try {
      const { user_id, pinCode } = req.body;
      const { card_number } = req.params;
      const [rows] = await db.query('UPDATE bankCard SET user_id = ?, pinCode = ? WHERE card_number = ?', [user_id, pinCode, card_number]);
      if (rows.affectedRows === 0) {
        res.status(404).json({ message: "Card not found" });
      } else {
        res.json({ message: "Card updated successfully" });
      }
    } catch (err) {
      console.error(err);
      res.sendStatus(500);
    }
  });
  
// DELETE
app.delete('/:card_number', async (req, res) => {
    try {
      const { card_number } = req.params;
      const [rows] = await db.query('DELETE FROM bankCard WHERE card_number = ?', [card_number]);
      if (rows.affectedRows === 0) {
        res.status(404).json({ message: "Card not found" });
      } else {
        res.json({ message: "Card deleted successfully" });
      }
    } catch (err) {
      console.error(err);
      res.sendStatus(500);
    }
  });
  
module.exports = app;