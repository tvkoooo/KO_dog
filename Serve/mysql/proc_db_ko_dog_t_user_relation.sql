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
    101 = 模块号/relation
    {
		400101011,           	 //(400101011)申请账号不存在
		400101012,   			 //(400101012)操作好友账号不存在
		400101013,            	 //(400101013)添加好友账号已经在好友列表
		400101014,               //(400101014)操作好友账号不在好友列表
        
		400101015,               //(400101015)用户增加组名已经存
		400101016,               //(400101016)用户操作组名不存在
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

/*!50003 DROP PROCEDURE IF EXISTS `p_user_relation_add_friend`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_user_relation_add_friend`(
	OUT `_code` int(11),
	IN `_myself_id` bigint(20),
	IN `_friend_id` bigint(20),
	IN `_friend_group_id` bigint(20),
 	IN `_friend_remark` char(50)   
    )
BEGIN
	/*设置用户数据*/
	/* 传入
		_myself_id,
		_friend_id,
		_friend_group_id,
		_friend_remark,
		*/
	/* 返回
		错误码 
				 0( 0)成功 
		*/	    
	declare _flag int(11) default 0;
    
    cond_process: begin
		SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_myself_id`);
		if 0 = _flag THEN
			/*(400101011)申请账号不存在 */
			set _code = 400101011;
			leave cond_process;
		end if;
		SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_friend_id`);
		if 0 = _flag THEN
			/*(400101012)操作好友账号不存在 */
			set _code = 400101012;
			leave cond_process;
		end if;
		SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_relation WHERE (`user_id` = `_myself_id` and `friend_id` = `_friend_id`);
		if 0 != _flag THEN
			/*(400101013)添加好友账号已经在好友列表 */
			set _code = 400101013;
			leave cond_process;
		end if;
        IF 0 != `_friend_group_id` THEN        
			SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_relation_assist WHERE (`id` = `_friend_group_id`);
			if 0 = _flag THEN
				/*(400101016)用户操作组名不存在 */
				set _code = 400101016;
				leave cond_process;
			end if;
		END IF;	
 		INSERT INTO db_ko_dog.t_user_relation(`user_id`,`friend_group_id`,`friend_id`,`friend_remark`) 
		VALUE (`_myself_id` ,`_friend_group_id` ,`_friend_id` , `_friend_remark` );
        if 0 = row_count() THEN
			/*200000001(1)插入数据失败 */
			set _code = 200000001;
            select 0 as user_id,0 as friend_group_id,0 as friend_id,"" as friend_remark,0 as build_friend_time;
        else        
			/*0( 0)成功  */
			set _code = 0;
            select `user_id`,`friend_group_id`,`friend_id`,`friend_remark`,`build_friend_time` 
            from db_ko_dog.t_user_relation where `user_id`=`_myself_id` and `friend_id` = `_friend_id`;
        end if;       
    end;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

/*!50003 DROP PROCEDURE IF EXISTS `p_user_relation_delete_friend`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_user_relation_delete_friend`(
	OUT `_code` int(11),	
	IN `_myself_id` bigint(20),
	IN `_friend_id` bigint(20)
    )
BEGIN
	/*设置用户数据*/
	/* 传入
		_myself_id,
		_friend_id,
		*/
	/* 返回
		错误码 
			0( 0)成功 
		*/

	declare _flag int(11) default 0;
    
    cond_process: begin
		SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_myself_id`);
		if 0 = _flag THEN
			/*(400101011)申请账号不存在 */
			set _code = 400101011;
			leave cond_process;
		end if;
		SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_friend_id`);
		if 0 = _flag THEN
			/*(400101012)操作好友账号不存在 */
			set _code = 400101012;
			leave cond_process;
		end if;
		SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_relation WHERE (`user_id` = `_myself_id` and `friend_id` = `_friend_id`);
		if 0 = _flag THEN
			/*(400101014)操作好友账号不在好友列表 */
			set _code = 400101014;
			leave cond_process;
		end if;
        
		DELETE FROM db_ko_dog.t_user_relation
		where `user_id`=`_myself_id` and `friend_id`=`_friend_id`;		
		if 0 = row_count() THEN
			/*200000004(4)删除数据失败 */
			set _code = 200000004;
		else
			/*0( 0)成功  */
			set _code = 0;
		end if;
    end;
    
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;


/*!50003 DROP PROCEDURE IF EXISTS `p_user_relation_query_friends`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_user_relation_query_friends`(
	OUT `_code` int(11),	
    IN `_myself_id` bigint(20)
    )
BEGIN
	/*设置用户数据*/
	/* 传入
		_myself_id,
		*/
	/* 返回
		错误码 
			0( 0)成功 
            申请用户朋友编号记录( *)
		*/   
	declare _flag_myself int(11) default 0;     
    SELECT COUNT(*) into _flag_myself FROM db_ko_dog.t_user_basic WHERE (`id` = `_myself_id`);	
    IF(_flag_myself = 0) THEN
		/*(400101011)申请账号不存在 */
		set _code = 400101011;	
        SELECT 0 as id,0 as user_id,"" as friend_grop;
        
        SELECT 0 as user_id,0 as friend_group_id,0 as friend_id,"" as friend_remark,0 as build_friend_time;
    ELSE	    
		/*0( 0)成功  */
		set _code = 0;
		SELECT `id`,`user_id`,`friend_group`
        FROM db_ko_dog.t_user_relation_assist where `user_id`=`_myself_id`;
        
		SELECT `user_id`,`friend_group_id`,`friend_id`,`friend_remark`,UNIX_TIMESTAMP(`build_friend_time`) as build_friend_time
        FROM db_ko_dog.t_user_relation where `user_id`=`_myself_id`;
		
	END IF;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;


/*!50003 DROP PROCEDURE IF EXISTS `p_user_relation_add_group`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_user_relation_add_group`(
	OUT `_code` int(11),
	IN `_myself_id` bigint(20),
    IN `_friend_group` char(50)
    )
BEGIN
	/*设置用户数据*/
	/* 传入
		_myself_id,
        _friend_group,
		*/
	/* 返回
		错误码 
			0( 0)成功    
            用户新增组编号( id)
		*/   
        
	declare _flag int(11) default 0;
    
    cond_process: begin
		SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_myself_id`);
		if 0 = _flag THEN
			/*(400101011)申请账号不存在 */
			set _code = 400101011;
            select 0;
			leave cond_process;
		end if;
		SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_relation_assist WHERE (`user_id` = `_myself_id` and `friend_group` = `_friend_group`);
		if 0 != _flag THEN
			/*(400101015)用户增加组名已经存 */
			set _code = 400101015;
            select 0;
			leave cond_process;
		end if;
        
		INSERT INTO db_ko_dog.t_user_relation_assist(`user_id`,`friend_group`) 
		VALUE ( `_myself_id` ,`_friend_group`);        
        if 0 = row_count() THEN
			/*200000001(1)插入数据失败 */
			set _code = 200000001;
            select 0;
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


/*!50003 DROP PROCEDURE IF EXISTS `p_user_relation_rename_group`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_user_relation_rename_group`(
	OUT `_code` int(11),
	IN `_user_id` bigint(20),
    IN `_friend_group_id` bigint(20),
    IN `_friend_group` char(50)
    )
BEGIN
	/*设置用户数据*/
	/* 传入
		_myself_id,
        _friend_group_old,
        _friend_group_new,
		*/
	/* 返回
		错误码 
			0( 0)成功    
		*/   
        
	declare _flag int(11) default 0;
    
    cond_process: begin
		SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_user_id`);
		if 0 = _flag THEN
			/*(400101011)申请账号不存在 */
			set _code = 400101011;
			leave cond_process;
		end if;
		SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_relation_assist WHERE (`id` = `_friend_group_id`);
		if 0 = _flag THEN
			/*(400101016)用户操作组名不存在 */
			set _code = 400101016;
			leave cond_process;
		end if;
        
		UPDATE db_ko_dog.t_user_relation_assist
		SET `friend_group`= `_friend_group_new`
		where `id` = `_friend_group_id`;  
        if 0 = row_count() THEN
			/*200000001(1)插入数据失败 */
			set _code = 200000001;
        else
			/*0( 0)成功  */
			set _code = 0;
        end if;
    end;
   
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;


/*!50003 DROP PROCEDURE IF EXISTS `p_user_relation_delete_group`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_user_relation_delete_group`(
	OUT `_code` int(11),
	IN `_myself_id` bigint(20),
	IN `_friend_id` bigint(20),
    IN `_friend_group_id` bigint(20)
    )
BEGIN
	/*设置用户数据*/
	/* 传入
		_myself_id,
        _friend_group,
		*/
	/* 返回
		错误码 
			0( 0)成功             
		*/ 
        
	declare _flag int(11) default 0;
   
   IF (`_friend_id` = 0) THEN
		cond_process: begin
			SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_myself_id`);
			if 0 = _flag THEN
				/*(400101011)申请账号不存在 */
				set _code = 400101011;
				leave cond_process;
			end if;
			SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_friend_id`);
			if 0 = _flag THEN
				/*(400101012)操作好友账号不存在 */
				set _code = 400101012;
				leave cond_process;
			end if;
			SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_relation_assist WHERE (`id` = `_friend_group_id`);
			if 0 = _flag THEN
				/*(400101016)用户操作组名不存在 */
				set _code = 400101016;
				leave cond_process;
			end if;			
			
			UPDATE db_ko_dog.t_user_relation
			SET `friend_group_id`= 0
			where `user_id`=`_myself_id` and `friend_group_id`=`_friend_group_id`;  
            
			DELETE FROM db_ko_dog.t_user_relation_assist
			where `id` = `_friend_group_id`;
			
			if 0 = row_count() THEN
				/*200000004(4)删除数据失败 */
				set _code = 200000004;
			else
				/*0( 0)成功  */
				set _code = 0;
			end if;
		end;        
	ELSE
		cond_process_1: begin
			SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_myself_id`);
			if 0 = _flag THEN
				/*(400101011)申请账号不存在 */
				set _code = 400101011;
				leave cond_process_1;
			end if;
			SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_friend_id`);
			if 0 = _flag THEN
				/*(400101012)操作好友账号不存在 */
				set _code = 400101012;
				leave cond_process_1;
			end if;
			SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_relation_assist WHERE (`id` = `_friend_group_id`);
			if 0 = _flag THEN
				/*(400101016)用户操作组名不存在 */
				set _code = 400101016;
				leave cond_process_1;
			end if;	
            
			UPDATE db_ko_dog.t_user_relation
			SET `friend_group_id`= 0
			where `user_id` = `_myself_id` and `friend_id` = `_friend_id` and `friend_group_id` = `_friend_group_id`;
			
			if 0 = row_count() THEN
				/*200000003(3)数据更新失败 */
				set _code = 200000003;
			else
				/*0( 0)成功  */
				set _code = 0;
			end if;
		end;
	END IF;


END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;


/*!50003 DROP PROCEDURE IF EXISTS `p_user_relation_change_group`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_user_relation_change_group`(
	OUT `_code` int(11),
	IN `_myself_id` bigint(20),
	IN `_friend_id` bigint(20),
    IN `_friend_group_id_old` bigint(20),
    IN `_friend_group_id_new` bigint(20)
    )
BEGIN
	/*设置用户数据*/
	/* 传入
		_myself_id,
		_friend_id,
        _friend_group_old,
        _friend_group_new,
		*/
	/* 返回
		错误码 
			0( 0)成功             
		*/  
        
	declare _flag int(11) default 0;
   
   IF (`_friend_id` = 0) THEN
		cond_process: begin
			SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_myself_id`);
			if 0 = _flag THEN
				/*(400101011)申请账号不存在 */
				set _code = 400101011;
				leave cond_process;
			end if;
			SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_relation_assist WHERE (`id` = `_friend_group_id_old`);
			if 0 = _flag THEN
				/*(400101016)用户操作组名不存在 */
				set _code = 400101016;
				leave cond_process;
			end if;
            
			UPDATE db_ko_dog.t_user_relation
			SET `friend_group_id`=`_friend_group_id_new`
			where `user_id` = `_myself_id` and `friend_group_id` = `_friend_group_id_old`;
			
			if 0 = row_count() THEN
				/*200000003(3)数据更新失败 */
				set _code = 200000003;
			else
				/*0( 0)成功  */           
				set _code = 0;
			end if;

		end; 
	ELSE
		cond_process_1: begin
			SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_myself_id`);
			if 0 = _flag THEN
				/*(400101011)申请账号不存在 */
				set _code = 400101011;
				leave cond_process_1;
			end if;
			SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_friend_id`);
			if 0 = _flag THEN
				/*(400101012)操作好友账号不存在 */
				set _code = 400101012;
				leave cond_process_1;
			end if;
			SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_relation WHERE (`user_id` = `_myself_id` and `friend_id` = `_friend_id` and `friend_group_id` = `_friend_group_id_old`);
			if 0 = _flag THEN
				/*(400101014)操作好友账号不在好友列表 */
				set _code = 400101014;
				leave cond_process_1;
			end if;	            
			SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_relation_assist WHERE (`id` = `_friend_group_id_new`);
			if 0 = _flag THEN
				/*(400101016)用户操作组名不存在 */
				set _code = 400101016;
				leave cond_process_1;
			end if;            
            
			UPDATE db_ko_dog.t_user_relation
			SET `friend_group_id`=`_friend_group_id_new`
			where `user_id` = `_myself_id` and `friend_id` = `_friend_id` and `friend_group_id` = `_friend_group_id_old`;
			
			if 0 = row_count() THEN
				/*200000003(3)数据更新失败 */
				set _code = 200000003;
			else
				/*0( 0)成功  */
				set _code = 0;
			end if;
		end;
	END IF;
  
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;


/*!50003 DROP PROCEDURE IF EXISTS `p_user_relation_change_remark`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_user_relation_change_remark`(
	OUT `_code` int(11),
	IN `_myself_id` bigint(20),
	IN `_friend_id` bigint(20),
    IN `_friend_remark` char(50)
    )
BEGIN
	/*设置用户数据*/
	/* 传入
		_myself_id,
        _friend_id,
        _friend_remark,
		*/
	/* 返回
		错误码 
			0( 0)成功             
		*/ 
        
	declare _flag int(11) default 0;
    
    cond_process: begin
		SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_myself_id`);
		if 0 = _flag THEN
			/*(400101011)申请账号不存在 */
			set _code = 400101011;
			leave cond_process;
		end if;
		SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_friend_id`);
		if 0 = _flag THEN
			/*(400101012)操作好友账号不存在 */
			set _code = 400101012;
			leave cond_process;
		end if;
		SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_relation WHERE (`user_id` = `_myself_id` and `friend_id` = `_friend_id`);
		if 0 = _flag THEN
			/*(400101014)操作好友账号不在好友列表 */
			set _code = 400101014;
			leave cond_process;
		end if;
        
		UPDATE db_ko_dog.t_user_relation
        SET `friend_remark`=`_friend_remark`
		where `user_id`=`_myself_id` and `friend_id`= `_friend_id`;
		
		if 0 = row_count() THEN
			/*200000003(3)数据更新失败 */
			set _code = 200000003;
		else
			/*0( 0)成功  */
			set _code = 0;
		end if;
    end;
       
       
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

/*!50003 DROP PROCEDURE IF EXISTS `p_user_relation_add_apply`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_user_relation_add_apply`(
	OUT `_code` int(11),
	IN `_user_allow_id` bigint(20),
	IN `_user_apply_id` bigint(20),
	IN `_user_apply_description` TEXT
    )
BEGIN
	/*设置用户数据*/
	/* 传入
		_myself_id,
        _friend_id,
		*/
	/* 返回
		错误码 
			0( 0)成功             
		*/ 
        
	declare _flag int(11) default 0;
    cond_process: begin
		if `_user_apply_id` = `_user_allow_id` THEN
			/*200000005(5)传入参数错误 */
			set _code = 200000005;
			leave cond_process;
		end if;

		SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_user_apply_id`);
		if 0 = _flag THEN
			/*(400101011)申请账号不存在 */
			set _code = 400101011;
			leave cond_process;
		end if;
		SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_user_allow_id`);
		if 0 = _flag THEN
			/*(400101012)操作好友账号不存在 */
			set _code = 400101012;
			leave cond_process;
		end if;
        
		SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_relation_apply 
        WHERE (`user_allow_id` = `_user_allow_id` and `user_apply_id` = `_user_apply_id`);
		IF 0 = _flag THEN
			INSERT INTO db_ko_dog.t_user_relation_apply(`user_allow_id`,`user_apply_id`,`user_apply_name`,`user_apply_nick`,`user_apply_create_time`,`user_apply_description`) 
			select `_user_allow_id` , `id`, `name`, `nick`, `create_time`, `_user_apply_description`
            from db_ko_dog.t_user_basic
            where `id` = `_user_apply_id`;
			if 0 = row_count() THEN
				/*200000001(1)插入数据失败 */
				set _code = 200000001;
			else        
				/*0( 0)成功  */
				set _code = 0;
			end if; 
        ELSE
			UPDATE db_ko_dog.t_user_relation_apply
			SET `user_apply_description`=`_user_apply_description`
			where `user_allow_id` = `_user_allow_id` and `user_apply_id` = `_user_apply_id`;
			/*0( 0)成功  */
			set _code = 0;

		end IF;
    end;       
       
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

/*!50003 DROP PROCEDURE IF EXISTS `p_user_relation_respond_apply`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_user_relation_respond_apply`(
	OUT `_code` int(11),
	IN `_user_allow_id` bigint(20),
	IN `_user_apply_id` bigint(20)
    )
BEGIN
	/*设置用户数据*/
	/* 传入
		_myself_id,
        _friend_id,
		*/
	/* 返回
		错误码 
			0( 0)成功             
		*/ 
        
	declare _flag int(11) default 0;
    
    cond_process: begin
		SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_user_apply_id`);
		if 0 = _flag THEN
			/*(400101011)申请账号不存在 */
			set _code = 400101011;
			leave cond_process;
		end if;
		SELECT COUNT(*) into _flag FROM db_ko_dog.t_user_basic WHERE (`id` = `_user_allow_id`);
		if 0 = _flag THEN
			/*(400101012)操作好友账号不存在 */
			set _code = 400101012;
			leave cond_process;
		end if;
        
		DELETE FROM db_ko_dog.t_user_relation_apply
		where `user_allow_id`=`_user_allow_id` and `user_apply_id`=`_user_apply_id`;		
		if 0 = row_count() THEN
			/*200000004(4)删除数据失败 */
			set _code = 200000004;
		else
			/*0( 0)成功  */
			set _code = 0;
		end if;
    end;
       
       
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;


/*!50003 DROP PROCEDURE IF EXISTS `p_user_relation_query_friends_apply`*/;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE PROCEDURE `p_user_relation_query_friends_apply`(
	OUT `_code` int(11),	
    IN `_myself_id` bigint(20)
    )
BEGIN
	/*设置用户数据*/
	/* 传入
		_myself_id,
		*/
	/* 返回
		错误码 
			0( 0)成功 
            申请用户朋友编号记录( *)
		*/   
	declare _flag_myself int(11) default 0;     
    SELECT COUNT(*) into _flag_myself FROM db_ko_dog.t_user_basic WHERE (`id` = `_myself_id`);	
    IF(_flag_myself = 0) THEN
		/*(400101011)申请账号不存在 */
		set _code = 400101011;	
        SELECT 0 as user_apply_id,"" as user_apply_name,"" as user_apply_nick,0 as user_apply_create_time,"" as user_apply_description;
    ELSE	    
		/*0( 0)成功  */
		set _code = 0;
		SELECT `user_apply_id`,`user_apply_name`,`user_apply_nick`,`user_apply_create_time`,`user_apply_description`
        FROM db_ko_dog.t_user_relation_apply where `user_allow_id`=`_myself_id`;
		
	END IF;
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
