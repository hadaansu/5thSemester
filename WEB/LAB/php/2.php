<?php
echo "<table border='1' cellpadding='20'>";
$k=1;
for($i=1; $i<=8; $i++) {
    echo "<tr>";
    for($j=1; $j<=8; $j++) {
         if(($i+$j)%2==0) {
             $color = "white";
         } else {
             $color = "black";
         }
         echo "<td style='background-color:$color; color:red;'>$k</td>";
         $k++;
    }
    echo "</tr>";
}
?>