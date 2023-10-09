-- Add two example users 


-- Insert example data into the user table
INSERT INTO BankSimul.user (user_id, email, phone, address, name)
VALUES
(1, 'johndoe@email.com', '+1-555-123-4567', '123 Main St, New York, NY', 'John Doe'),
(2, 'janedoe@email.com', '+1-555-987-6543', '456 Elm St, Los Angeles, CA', 'Jane Doe');

-- Insert example data into the bankCard table
INSERT INTO BankSimul.bankCard (card_number, user_id, pinCode)
VALUES
('0B0031E7A3', 1, '9999'),
('05009BA4AA', 2, '8888');

-- Insert example data into the account table
INSERT INTO BankSimul.account (account_id, balance, user_id, credit)
VALUES
(563, 5000.00, 1, 1000.00),
(234, 3000.00, 2, 500.00);

-- Insert example data into the transaction table
INSERT INTO BankSimul.transaction (trans_id, account_id, amount, timeStamp)
VALUES
(2001, 563, 250.00, '2023-03-29 14:35:22'),
(2002, 563, 100.00, '2023-03-29 16:12:45'),
(2003, 234, 75.00, '2023-03-30 09:22:10'),
(2004, 234, 150.00, '2023-03-30 11:04:55');


-------------------------------------------------------------------------------------

--Show all data in tables on terminal 


-- Select all data from the user table
SELECT * FROM BankSimul.user;

-- Select all data from the bankCard table
SELECT * FROM BankSimul.bankCard;

-- Select all data from the account table
SELECT * FROM BankSimul.account;

-- Select all data from the transaction table
SELECT * FROM BankSimul.transaction;


-------------------------------------------------------------------------------------

-- DELETE all data 

-- Delete all data from the `transaction` table
DELETE FROM `BankSimul`.`transaction`;

-- Delete all data from the `account` table
DELETE FROM `BankSimul`.`account`;

-- Delete all data from the `bankCard` table
DELETE FROM `BankSimul`.`bankCard`;

-- Delete all data from the `user` table
DELETE FROM `BankSimul`.`user`;




-------------------------------------------------------------------------------------
-- Bankcard info 


-- 0B0031E7A3
-- 563 loppuinen avain

-- 05009BA4AA
-- 234 loppuinen avain