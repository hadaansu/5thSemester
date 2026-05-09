<?php
$conn = mysqli_connect("localhost", "root", "", "labassignment1");  
if($conn->connect_error)
    {
        die("Connection failed:".$conn->connect_error);
    }
$sql = "UPDATE student SET address='Dallu' WHERE name='Student2'";
if($conn->query($sql))
    {
        echo "Data updated successfully";
    }
    else{
        echo "Error updating data: ".$conn->error;
    }
?>