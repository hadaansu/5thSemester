<?php

$conn = mysqli_connect("localhost", "root", "", "labassignment1");

if($conn->connect_error)
    {
        die("Connection failed:".$conn->connect_error);
    }

for ($i = 1; $i <= 10; $i++) {

    $id = $i;
    $name = "Student" . $i;
    $address = "Kathmandu Area " . $i;
    $contact = "980000000" . $i;

    $sql = "INSERT INTO student (id, name, address, contact)
            VALUES ($id, '$name', '$address', '$contact')";

    $conn->query($sql);        
}

echo "10 student records inserted successfully";


?>