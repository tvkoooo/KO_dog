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

/*!40101 DROP TABLE IF EXISTS `t_user_relation`*/;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `t_user_relation` (
    `user_id` bigint(20) unsigned NOT NULL DEFAULT 0 comment '用户id',
    `friend_group_id` bigint(20) unsigned NOT NULL DEFAULT 0 comment '朋友组id',
    `friend_id` bigint(20) unsigned NOT NULL DEFAULT 0 comment '朋友id',
    `friend_remark` char(50) NOT NULL DEFAULT '0' comment '朋友备注',
	`build_friend_time` timestamp NOT NULL DEFAULT current_timestamp comment '建立朋友关系时间',	
    PRIMARY KEY (`user_id`,`friend_id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 comment='用户朋友数据表';
/*!40101 SET character_set_client = @saved_cs_client */;

/*!40101 DROP TABLE IF EXISTS `t_user_relation_assist`*/;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `t_user_relation_assist` (
    `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT comment '记录id',
    `user_id` bigint(20) unsigned NOT NULL DEFAULT 0 comment '用户id',
    `friend_group` char(50) NOT NULL DEFAULT 'friend' comment '朋友组名',
    PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 comment='用户朋友组数据辅助表';
/*!40101 SET character_set_client = @saved_cs_client */;

/*!40101 DROP TABLE IF EXISTS `t_user_relation_apply`*/;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `t_user_relation_apply` (
    `user_allow_id` bigint(20) unsigned NOT NULL DEFAULT 0 comment '决定是否允许添加好友用户id',
    `user_apply_id` bigint(20) unsigned NOT NULL DEFAULT 0 comment '申请用户id',
    `user_apply_name` char(50) NOT NULL DEFAULT '0' comment '申请用户名',
    `user_apply_nick` char(50) NOT NULL DEFAULT '0' comment '申请用户昵称',
    `user_apply_create_time` timestamp NOT NULL DEFAULT 0 comment '申请用户创建时间',
    `user_apply_description` TEXT NOT NULL DEFAULT "" comment '申请用户申请理由描述',
    PRIMARY KEY (`user_allow_id`,`user_apply_id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 comment='用户处理好友申请组数据表';
/*!40101 SET character_set_client = @saved_cs_client */;


/*!40101 DROP TABLE IF EXISTS `easytab_address`*/;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;

