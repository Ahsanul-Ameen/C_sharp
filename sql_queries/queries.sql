# 34. Write a query to select the last N records from a table…

SELECT *
FROM EMP
MINUS
SELECT *
FROM EMP 
WHERE ROWNUM <= (
SELECT COUNT(*) - &n 
FROM EMP
);

# We all know when you execute a SQL statement, sub query is the one which is executed first.
# Step1: So if you run statement "select count(*) - &n from emp" and think EMP table has 10 rows
# and N value is 3. The output for below SQL statement will be 10 - 3, ie 7
# Step2: Now oracle takes 7 and execute the SQL statement as "select * from emp where rownum <= 7",
# which willl fetch the first 7 rows.
# Step3: Now oracle runs SQL statement "select * from emp", which willl fetch all the 10 rows
# Step4: Now oracle takes the 10 rows from step3 and subtracts the 7 rows from step2, which will
# result in last 3 rows.
# This is how you need to explain to the Interviewer….



# 35. Write a query to find 10 highest salary 

SELECT * 
FROM EMP emp1
WHERE (10 - 1) = 
(
SELECT COUNT(DISTINCT(emp2.sal))
FROM EMP emp2
WHERE emp2.sal > emp1.sal
);


SELECT *
FROM (
SELECT e.*, 
       DENSE_RANK() OVER (ORDER BY sal DESC) RN
FROM EMP e
)
WHERE RN = 10;


# 36. Select top N salaries from EMP table
## DENSE_RANK ( ) OVER ( [ <partition_by_clause> ] < order_by_clause > )  

SELECT *
FROM (
SELECT e.*,
       DENSE_RANK() OVER (ORDER BY sal DESC) RN
FROM EMP e
)
WHERE RN <= 5;


# 37. Select top N salaries from each Department of EMP table

SELECT * 
FROM (
SELECT e.*, 
	DENSE_RANK() OVER (PARTITION BY deptno ORDER BY sal DESC) RN
FROM EMP e
)
WHERE RN <= 3;


# 38. Write a query to select/delete duplicate rows from the EMP table
## We can achieve this by using the pseudo column ROWID.

SELECT *
FROM EMP 
WHERE ROWID NOT IN (
SELECT MIN(ROWID)
FROM EMP
GROUP BY empno	
);


DELETE FROM EMP
WHERE ROWID NOT IN (
SELECT MIN(ROWID)
FROM EMP
GROUP BY empno
);


# 39. Write a query to select only those employee information who are earning the same salary

## 1st way

SELECT e1.* 
FROM EMP e1, 
     EMP e2
WHERE e1.sal = e2.sal AND
      e1.name <> e2.name;
      
## 2nd way

SELECT *
FROM EMP
WHERE sal IN (
SELECT sal FROM EMP
GROUP BY sal
HAVING COUNT(sal) > 1
);


# 3rd way 

SELECT *
FROM (
SELECT e.*, 
       COUNT(*) OVER (PARTITION BY sal ORDER BY SAL) cnt
FROM EMP e
)
WHERE CNT >= 2;


# 40. Write a query to display even/odd number rows from a table.

# We can achieve this by using the ROWNUM pseudo column.

SELECT *
FROM (
SELECT empno, ename, sal, ROWNUM rn
FROM EMP
ORDER BY empno
)
WHERE MOD(rn, 2) <> 0
ORDER BY rn;


# 41. Write a query to display the employee information, who have more than 2 employees under a manager

# We can achieve this by using the COUNT analytical function.

SELECT *
FROM (
SELECT e.*, 
       COUNT(mgr) OVER (PARTITION BY mgr) AS cnt
FROM EMP e
)
WHERE cnt >= 2;


# 42. Write a query to find the maximum salary from the EMP table without using functions.

# We can achieve this by using the SELF joins.

SELECT *
FROM EMP 
WHERE sal NOT IN (
SELECT A.sal
FROM EMP A, 
     EMP B
WHERE A.sal < B.sal 
);

# 43. Write a query to find the number of rows in a table without using COUNT function.

SELECT MAX(rn)
FROM (
SELECT ROW_NUMBER() OVER (ORDER BY empno DESC) AS rn 
FROM EMP 
);


# 44. Write a query to find the LAST inserted record in a table.

# If you want the last record inserted, you need to have a timestamp or sequence number assigned to each
# record as they are inserted and then you can use the below query…

SELECT *
FROM T
WHERE TIMESTAMP_COLUMN = (SELECT MAX(TIMESTAMP_COLUMN) FROM T) AND
      ROWNUM = 1;



# 45. Write a query to find the employees who are working in the company for the past 5 years.

# We can achieve this using the ADD_MONTHS function.

SELECT *
FROM EMP
WHERE hiredate < ADD_MONTHS(SYSDATE, -60); ## 5 * 12 = 60 : Jump back sixty months






















