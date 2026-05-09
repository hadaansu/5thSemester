<!DOCTYPE html>
<html>
<body>

<?php

$name = $email = $age = "";
$nameErr = $emailErr = $ageErr = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {

    if (empty($_POST["name"])) {
        $nameErr = "Name is required";
    } else {
        $name = $_POST["name"];
    }

    if (empty($_POST["email"])) {
        $emailErr = "Email is required";
    } else {
        $email = $_POST["email"];
        if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
            $emailErr = "Invalid email format";
        }
    }

    if (empty($_POST["age"])) {
        $ageErr = "Age is required";
    } else {
        $age = $_POST["age"];
        if (!is_numeric($age)) {
            $ageErr = "Age must be a number";
        }
    }
}

?>

<h2>Student Form</h2>

<form method="POST" action="">
    Name: <input type="text" name="name">
    <span style="color:red;"><?php echo $nameErr; ?></span>
    <br><br>

    Email: <input type="text" name="email">
    <span style="color:red;"><?php echo $emailErr; ?></span>
    <br><br>

    Age: <input type="text" name="age">
    <span style="color:red;"><?php echo $ageErr; ?></span>
    <br><br>

    <input type="submit" value="Submit">
</form>

<?php
if ($name && $email && $age && !$nameErr && !$emailErr && !$ageErr) {
    echo "<h3>Form Submitted Successfully!</h3>";
    echo "Name: $name <br>";
    echo "Email: $email <br>";
    echo "Age: $age <br>";
}
?>

</body>
</html>