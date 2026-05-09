<?php
echo "<table border='1' cellpadding='20'><tr>";

for ($i = 1; $i <= 10; $i++) {
    if ($i % 2 == 0) {
        $color = "lightblue";
    } else {
        $color = "lightgreen";
    }

    echo "<td style='background-color:$color;'>Col $i</td>";
}

echo "</tr></table>";
?>