-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema BankSimul
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema BankSimul
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `BankSimul` DEFAULT CHARACTER SET utf8mb3 ;
USE `BankSimul` ;

-- -----------------------------------------------------
-- Table `BankSimul`.`user`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `BankSimul`.`user` (
  `user_id` INT NOT NULL,
  `email` VARCHAR(45) NOT NULL,
  `phone` VARCHAR(45) NOT NULL,
  `address` VARCHAR(45) NULL DEFAULT NULL,
  `name` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`user_id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb3;


-- -----------------------------------------------------
-- Table `BankSimul`.`bankCard`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `BankSimul`.`bankCard` (
  `card_number` VARCHAR(20) NOT NULL,
  `user_id` INT NOT NULL,
  `pinCode` VARCHAR(255) NOT NULL,
  PRIMARY KEY (`card_number`),
  INDEX `bankCard_user` (`user_id` ASC) VISIBLE,
  CONSTRAINT `bankCard_user`
    FOREIGN KEY (`user_id`)
    REFERENCES `BankSimul`.`user` (`user_id`)
    ON DELETE RESTRICT
    ON UPDATE CASCADE)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb3;


-- -----------------------------------------------------
-- Table `BankSimul`.`account`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `BankSimul`.`account` (
  `account_id` INT NOT NULL,
  `balance` FLOAT NOT NULL,
  `user_id` INT NOT NULL,
  `credit` FLOAT NOT NULL,
  PRIMARY KEY (`account_id`),
  INDEX `account_BankCard` (`user_id` ASC) VISIBLE,
  CONSTRAINT `account_BankCard`
    FOREIGN KEY (`user_id`)
    REFERENCES `BankSimul`.`bankCard` (`user_id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb3;


-- -----------------------------------------------------
-- Table `BankSimul`.`transaction`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `BankSimul`.`transaction` (
  `trans_id` INT NOT NULL AUTO_INCREMENT,
  `account_id` INT NOT NULL,
  `amount` FLOAT NOT NULL,
  `timeStamp` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`trans_id`),
  INDEX `transaction_account` (`account_id` ASC) VISIBLE,
  CONSTRAINT `transaction_account`
    FOREIGN KEY (`account_id`)
    REFERENCES `BankSimul`.`account` (`account_id`)
    ON DELETE RESTRICT
    ON UPDATE CASCADE)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb3;



SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;

