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

/*!50003 DROP PROCEDURE IF EXISTS `p_nt_message_add`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_nt_message_add`(
	OUT `_code` int(11),
	IN `_user_id` bigint(20),
	IN `_to_user_id` bigint(20),
	IN `_message_mid` int(11),
 	IN `_nt_message` BLOB   
    )
BEGIN
	/*设置用户数据*/
	/* 传入
	/* 传入
		_user_id,
		_to_user_id,
		_message_mid,
		_nt_message,
		*/
	/* 返回
		错误码 
				 0( 0)成功 
				消息记录编号( id)
		*/	    
	declare _flag int(11) default 0;
    
    cond_process: begin
		SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_user_id`);
		if 0 = _flag THEN
			/*(400100011)登陆账号不存在 */
			set _code = 400101011;
            SELECT 0;
			leave cond_process;
		end if;
		SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_to_user_id`);
		if 0 = _flag THEN
			/*(400100011)登陆账号不存在 */
			set _code = 400101012;
            SELECT 0;
			leave cond_process;
		end if;        
        
 		INSERT INTO db_ko_dog.t_user_nt_message(`to_user_id`,`user_id`,`message_mid`,`nt_message`) 
		VALUE (`_to_user_id` ,`_user_id` ,`_message_mid` , `_nt_message` );
        if 0 = row_count() THEN
			/*200000001(1)插入数据失败 */
			set _code = 200000001;
            SELECT 0;
        else        
			/*0( 0)成功  */
			set _code = 0;
            select LAST_INSERT_ID();
        end if;       
    end;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

/*!50003 DROP PROCEDURE IF EXISTS `p_nt_message_delete_by_id`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_nt_message_delete_by_id`(
	OUT `_code` int(11),	
	IN `_note_id` bigint(20)
    )
BEGIN
	/*设置用户数据*/
	/* 传入
		_note_id,
		*/
	/* 返回
		错误码 
			0( 0)成功 
		*/

		DELETE FROM db_ko_dog.t_user_nt_message
		where `note_id` = `_note_id`;		
		if 0 = row_count() THEN
			/*200000004(4)删除数据失败 */
			set _code = 200000004;
		else
			/*0( 0)成功  */
			set _code = 0;
		end if;
    
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;


/*!50003 DROP PROCEDURE IF EXISTS `p_nt_message_read_by_note_id`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_nt_message_read_by_note_id`(
	OUT `_code` int(11),
	IN `_note_id` bigint(20)
    )
BEGIN
	/*设置用户数据*/
	/* 传入
		_note_id,
		*/
	/* 返回
		错误码 
			0( 0)成功   
            消息记录数据
		*/         
		select `note_id`,`read_state`, `to_user_id`,`user_id`,`message_mid`,UNIX_TIMESTAMP(`create_time`) as create_time,`nt_message`
		from db_ko_dog.t_user_nt_message
		where `note_id` = `_note_id`;		

		/*0( 0)成功  */
		set _code = 0;

        
 
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;


/*!50003 DROP PROCEDURE IF EXISTS `p_nt_message_read_by_to_user_id`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_nt_message_read_by_to_user_id`(
	OUT `_code` int(11),
	IN `_to_user_id` bigint(20)
    )
BEGIN
	/*设置用户数据*/
	/* 传入
		_to_user_id,
		*/
	/* 返回
		错误码 
			0( 0)成功             
		*/         
       
		select `note_id`,`read_state`, `to_user_id`,`user_id`,`message_mid`,UNIX_TIMESTAMP(`create_time`) as create_time,`nt_message`
		from db_ko_dog.t_user_nt_message
		where `to_user_id` = `_to_user_id` and `read_state`= 0;		
        
		/*0( 0)成功  */
		set _code = 0;

END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;


/*!50003 DROP PROCEDURE IF EXISTS `p_nt_message_consume_by_note_id`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_nt_message_consume_by_note_id`(
	OUT `_code` int(11),
	IN `_to_user_id` bigint(20),
	IN `_note_id` bigint(20)
    )
BEGIN
	/*设置用户数据*/
	/* 传入    
		_to_user_id,
		_note_id,
		*/
	/* 返回
		错误码 
			0( 0)成功             
		*/ 
		UPDATE db_ko_dog.t_user_nt_message
		SET `read_state`= 1
		where `to_user_id` = `_to_user_id` and `note_id` = `_note_id`;		
		if 0 = row_count() THEN
			/*200000003(3)数据更新失败 */
			set _code = 200000003;
		else
			/*0( 0)成功  */
			set _code = 0;
		end if;

END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;


/*!50003 DROP PROCEDURE IF EXISTS `p_nt_message_consume_by_max_note_id`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_nt_message_consume_by_max_note_id`(
	OUT `_code` int(11),
	IN `_to_user_id` bigint(20),
	IN `_note_id` bigint(20)
    )
BEGIN
	/*设置用户数据*/
	/* 传入
		_to_user_id,
		_note_id,
		*/
	/* 返回
		错误码 
			0( 0)成功             
		*/ 
        
		UPDATE db_ko_dog.t_user_nt_message
        SET `read_state`= 1
		where `to_user_id` = `_to_user_id` and `read_state`= 0 and `note_id` <= `_note_id`;		
		if 0 = row_count() THEN
			/*200000003(3)数据更新失败 */
			set _code = 200000003;
		else
			/*0( 0)成功  */
			set _code = 0;
		end if;

       
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;


/*!50003 DROP PROCEDURE IF EXISTS `p_nt_message_regular_clean`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_nt_message_regular_clean`(
	IN `_unread_day` int(11),
	IN `_read_day` int(11)
    )
BEGIN
	/*设置用户数据*/
	/* 传入
		_note_id,
		*/
	/* 返回
		*/

		DELETE FROM db_ko_dog.t_user_nt_message
		where (`read_state` = 0 and `create_time` < DATE_ADD(now(), Interval -`_unread_day` day)) 
        or (`read_state` = 1 and `create_time` < DATE_ADD(now(), Interval -`_read_day` day)) limit 100000;

END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;


/*!50003 DROP EVENT IF EXISTS `e_nt_message_regular_clean`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
/*创建事件 event:event_name*/
DELIMITER ;;
CREATE EVENT e_nt_message_regular_clean
	/*declare _event_clear_verify_time int(10);*/
	/*SELECT cfgval into _event_clear_verify_time from t_config_int WHERE cfgkey = "event_clear_verify_time";*/
    /*该事件从现在开始_event_clear_verify_time秒执行一次*/
    /*ON SCHEDULE EVERY 10 second STARTS NOW()*/
    ON SCHEDULE EVERY 14400 second STARTS NOW()
	ON COMPLETION PRESERVE
	DO BEGIN
		CALL p_nt_message_regular_clean(7,3);
	END;;
DELIMITER ;

SET GLOBAL event_scheduler = 1;

alter event e_nt_message_regular_clean ON 
COMPLETION PRESERVE ENABLE; 
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;


/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
