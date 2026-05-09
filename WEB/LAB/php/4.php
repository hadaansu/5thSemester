<?php
    $conn=new mysqli("localhost","root","","");
    if($conn->connect_error)
            {
                die("Connection error".$conn->connect_error);
            }
            $sql="CREATE DATABASE IF NOT EXISTS labassignment1";
            
            if(!$conn->query($sql))
                {
                    echo "Error creating database: ".$conn->error;
                }
                else{
                    echo "Database created successfully";
                }
?>