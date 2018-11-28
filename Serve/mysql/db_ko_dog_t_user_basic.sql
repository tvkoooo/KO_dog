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

/*!40101 DROP TABLE IF EXISTS `t_user_basic`*/;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `t_user_basic` (
    `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT comment '用户id',
    `name` char(50) NOT NULL  comment '用户名',
    `password` char(50) NOT NULL  comment '用户密码',
    `nick` char(50) NOT NULL DEFAULT '0' comment '昵称',
	`create_time` timestamp NOT NULL DEFAULT current_timestamp comment '创建时间',	
    PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1112220000 DEFAULT CHARSET=utf8 comment='用户配置数据表';
/*!40101 SET character_set_client = @saved_cs_client */;

/*!40101 DROP TABLE IF EXISTS `easytab_address`*/;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;

