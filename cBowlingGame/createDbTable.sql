-- create database mydb;
-- grant all privileges on mydb.* to myuser@'%';

use mydb;
create table GameScore (
    playerName varchar(20) primary key,
    gameScore integer NOT NULL DEFAULT 0,
    gameDate date NOT NULL (current_date)
);

use mydb;
create table GameCount (
    playerName varchar(20),
    gameCount integer NOT NULL DEFAULT 0,
    gameYearMonth date,
    PRIMARY KEY (playerName, gameDate)
);

use mydb;
select * from GameScore;

use mydb;
select * from GameCount;