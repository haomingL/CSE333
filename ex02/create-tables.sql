-- A
Create Table CARRIERS(cid int PRIMARY KEY, name varchar);
Create Table MONTHS(mid int PRIMARY KEY, month varchar);
Create Table WEEKDAYS(did int PRIMARY KEY, day_of_week varchar);
Create Table FLIGHTS(year int, month_id int REFERENCES MONTH, day_of_month int, day_of_week_id int REFERENCES WEEKDAYS,
					 carrier_id REFERENCES CARRIERS, flight_num int, origin_city varchar, origin_state varchar,
					 dest_city varchar, dest_state varchar, departure_delay int, taxi_out int, cancelled int,
					 actual_time int, distance int); 