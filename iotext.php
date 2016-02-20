<?php
$content=$_REQUEST["content"];
echo $content;
$myfile = fopen("mnt/nandfalsh/userinfo.txt", "w") or die("Unable to open file!");
fwrite($myfile, $content);
fclose($myfile);
?>