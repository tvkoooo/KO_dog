CREATE DATABASE  IF NOT EXISTS `db_ko_dog` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `db_ko_dog`;
-- MySQL dump 10.13  Distrib 5.7.9, for Win32 (AMD64)
--
-- Host: localhost    Database: db_ko_dog
-- ------------------------------------------------------
-- Server version	5.7.11-log
/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

/*!40101 DROP TABLE IF EXISTS `t_user_nt_message`*/;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `t_user_nt_message` (
    `note_id` bigint(20) unsigned NOT NULL AUTO_INCREMENT comment 'nt消息记录id',
    `read_state` TINYINT(3) NOT NULL DEFAULT '0' comment 'nt消息阅读状态: 0未阅读 1：已阅读',
    `to_user_id` bigint(20) unsigned NOT NULL comment 'nt消息发给的用户id',
    `user_id` bigint(20) unsigned NOT NULL comment '发出nt消息的用户id',
    `message_mid` int(11) NOT NULL DEFAULT '0' comment '消息号mid，用来了解记录属于什么业务',
	`create_time` timestamp NOT NULL DEFAULT current_timestamp comment 'nt消息创建时间',	
    `nt_message` BLOB NOT NULL DEFAULT '' comment 'nt消息二进制流',
    PRIMARY KEY (`note_id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 comment='nt消息记录数据表';
/*!40101 SET character_set_client = @saved_cs_client */;

/*!40101 DROP TABLE IF EXISTS `easytab_address`*/;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;

