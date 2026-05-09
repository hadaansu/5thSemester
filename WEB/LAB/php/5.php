<?php
$conn=new mysqli("localhost","root","","labassignment1");
if($conn->connect_error)
    {
        die("Connection failed:".$conn->connect_error);
    }

if($conn->query("INSERT INTO student VALUES (1,'Suresh','Dallu','9841234567')"))
    {
        echo "Data inserted successfully";
    }
    else{
        echo "Error inserting data: ".$conn->error;
    }
?>      