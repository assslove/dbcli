use TEST;
drop table if exists t_user;
create table t_user (
	user_id int, 
	nick char(16),
	score int not NULL,
	attr varchar(10),
	primary key (user_id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


drop table if exists t_limit;
create table t_limit (
	user_id int, 
	`type` int,
	`value` int not NULL,
	primary key (user_id, `type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

insert into t_user values(1000, 'bin', 1000, '');
insert into t_limit values(1000, 1, 1);
insert into t_limit values(1000, 2, 10);
insert into t_limit values(1000, 3, 100);
insert into t_limit values(1000, 4, 1000);
insert into t_limit values(1000, 5, 10000);
