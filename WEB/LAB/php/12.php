<?php
setcookie("user", "Ram", time() + 3600); 

echo "Cookie is set!";

session_start();

$_SESSION["user"] = "Ram";
$_SESSION["age"] = 20;

echo "Session is set!";
?>