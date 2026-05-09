<?php
$num = array(10, 20, 30);
$num[1] = 50;
echo "Numeric Array:<br>";
print_r($num);
echo "<br><br>";

$assoc = array("name" => "Ram", "age" => 20);
$assoc["age"] = 25;
echo "Associative Array:<br>";
print_r($assoc);
echo "<br><br>";

$multi = array(
    array(1, 2),
    array(3, 4)
);
$multi[1][0] = 99;
echo "Multidimensional Array:<br>";
print_r($multi);
?>