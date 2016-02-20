<?php
$content=$_REQUEST["content"];
echo $content;
$myfile = fopen("userinfo.txt", "w") or die("Unable to open file!");
fwrite($myfile, $content);
fclose($myfile);
?>