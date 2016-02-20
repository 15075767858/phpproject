<?php 
$fp = fopen("mnt/nandfalsh/userinfo.txt", "r"); 
echo "<div id='data' style='display:none'>";
while(! feof($fp)) 
{ 
echo fgets($fp); 
} 
	echo "</div>";
fclose($fp); 
?> 
