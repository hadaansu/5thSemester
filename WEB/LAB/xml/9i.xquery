xquery version "1.0";

for $i in doc("9.xml")/store/item
where $i/price = 200
return $i