<?php
if($_REQUEST["r"]){
echo file_get_contents("../../userinfo.txt");
    //$fp = fopen("../../userinfo.txt", "r");
    //echo "<div id='data' >";
    //while (!feof($fp)) {
    //    echo fgets($fp);
    //}
   // echo "</div>";
    //fclose($fp);
}
else{
$content=$_REQUEST["content"];
echo $content;
$myfile = fopen("../../userinfo.txt", "w") or die("Unable to open file!");
fwrite($myfile, $content);
fclose($myfile);
}
?>

