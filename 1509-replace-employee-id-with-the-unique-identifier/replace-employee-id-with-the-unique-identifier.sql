# Write your MySQL query statement below
select Employees.name, EmployeeUNI.unique_id from Employees left join EmployeeUNI on 
EmployeeUNI.id = Employees.id; 