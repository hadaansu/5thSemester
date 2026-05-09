<?php
$conn = mysqli_connect("localhost", "root", "", "labassignment1");  
if($conn->connect_error)
    {
        die("Connection failed:".$conn->connect_error);
    }
$sql = "DELETE FROM student WHERE address='Lalitpur'";
if($conn->query($sql))
    {
        echo "Data deleted successfully";
    }
    else{
        echo "Error deleting data: ".$conn->error;
    }
?>