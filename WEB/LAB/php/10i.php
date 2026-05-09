<!DOCTYPE html>
<html>
<body>

<form method="POST" action="">
    Name: <input type="text" name="name"><br><br>
    Age: <input type="number" name="age"><br><br>
    <input type="submit" value="Submit">
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {

    $name = $_POST['name'];
    $age = $_POST['age'];

    echo "<h3>POST Data:</h3>";
    echo "Name: $name <br>";
    echo "Age: $age <br>";
}
?>

</body>
</html>