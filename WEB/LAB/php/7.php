<?php
$conn = mysqli_connect("localhost", "root", "", "labassignment1");

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

$sql = "SELECT * FROM student";
$result = $conn->query($sql);

if ($result->num_rows > 0) {

    echo "<table border='1' cellpadding='20'>";
    echo "<tr>
            <th>ID</th>
            <th>Name</th>
            <th>Address</th>
            <th>Phone</th>
          </tr>";

    while($row = $result->fetch_assoc()) {
        echo "<tr>
                <td>".$row["id"]."</td>
                <td>".$row["name"]."</td>
                <td>".$row["address"]."</td>
                <td>".$row["phone"]."</td>
              </tr>";
    }

    echo "</table>";

} else {
    echo "0 results";
}

$conn->close();
?>