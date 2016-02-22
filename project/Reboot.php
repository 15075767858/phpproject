
<?php
$last_line=system("reboot_server.sh", $retval);
$fp = fopen("reboot_server.sh", "r");
while(! feof($fp))
{
    echo fgets($fp);
}
fclose($fp);
echo  $last_line."服务器重启成功".$retval;
?>