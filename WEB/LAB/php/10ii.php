<!DOCTYPE html>
<html>
<body>

<form method="GET" action="">
    Name: <input type="text" name="name"><br><br>
    Age: <input type="number" name="age"><br><br>
    <input type="submit" value="Submit">
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "GET" && isset($_GET['name']) && isset($_GET['age'])) {

    $name = $_GET['name'];
    $age = $_GET['age'];

    echo "<h3>GET Data:</h3>";
    echo "Name: $name <br>";
    echo "Age: $age <br>";
}
?>

</body>
</html>