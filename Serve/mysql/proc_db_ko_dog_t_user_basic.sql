CREATE DATABASE  IF NOT EXISTS `db_ko_dog` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `db_ko_dog`;
-- MySQL dump 10.13  Distrib 5.7.9, for Win32 (AMD64)
--
-- Host: localhost    Database: db_ko_dog
-- ------------------------------------------------------
/*
error code
	/////////////////
	0 = 核心,
	{
		     -1(-1)未知错误
		      0( 0)成功 
	}
	/////////////////
	0 = 普通,
	{
		200000001(1)插入数据失败
		200000002(2)获取数据失败
		200000003(3)数据更新失败
		200000004(4)删除数据失败
		200000005(5)传入参数错误
        
	}
    100 = 账号
    {
		400100011,           	 //(400100011)登陆账号不存在
		400100012,   			 //(400100012)账号与密码不匹配
		400100013,            	 //(400100013)注册账号已经存在
		400100014,               //(400100014)注册账号或者密码非法
    }
*/
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

/*!50003 DROP PROCEDURE IF EXISTS `p_userinfo_add`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_userinfo_add`(
	OUT `_code` int(11),
	IN `_name` char(50),
	IN `_password` char(50),
	IN `_nick` char(50)
    )
BEGIN
	/*设置用户数据*/
	/* 传入
		_name,
		_password,
		_nick,
		*/
	/* 返回
		错误码 
				 0( 0)成功 
				用户编号( id)
		*/
	declare _flag int(11) default 0;     
    SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`name` = _name);
    
    IF(_flag = 0) THEN
    
		INSERT INTO db_ko_dog.t_user_basic(`name`,`password`,`nick`) 
		VALUES                                   (_name ,PASSWORD(_password) ,_nick);
		if 0 = row_count() then
			/*200000001(1)插入数据失败 */
			set _code = 200000001;
			select 0;		
		else
			/*成功*/ 
			set _code = 0;
			select LAST_INSERT_ID();
		end if;
	ELSE
		/*(400100013)注册账号已经存在 */
		set _code = 400100013;
		select 0;
	END IF;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

/*!50003 DROP PROCEDURE IF EXISTS `p_userinfo_check`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_userinfo_check`(
	OUT `_code` int(11),	
	IN `_name` char(50),
	IN `_password` char(50)
    )
BEGIN
	/*设置用户数据*/
	/* 传入
		_name,
		_password,
		*/
	/* 返回
		错误码 
			0( 0)成功 
		*/
    declare _id bigint(20) default 0;    
	select id into _id from db_ko_dog.t_user_basic where `name`=_name and `password`=PASSWORD(_password);
	if 0 = row_count() then
		/*(400100012)账号与密码不匹配*/
		set _code = 400100012;
		select _id;
	else
		/*成功*/ 
		set _code = 0;
		select _id;
	end if;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;


/*!50003 DROP PROCEDURE IF EXISTS `p_userinfo_search`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_userinfo_search`(
	OUT `_code` int(11),	
    IN `_limit` int(11),
	IN `_search` char(50)    
    )
BEGIN
	/*设置用户数据*/
	/* 传入
		_search,
		*/
	/* 返回
		错误码 
			0( 0)成功 
		*/   
	declare _character  char(64) default "";   
	set _character = CONCAT("%",`_search`,"%");
	select `id`	,`name` , `nick` , unix_timestamp(`create_time`) as create_time from db_ko_dog.t_user_basic 
    where `name` LIKE _character  or `id` LIKE _character or `nick` LIKE _character limit `_limit`;
    /*成功*/ 
	set _code = 0;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
