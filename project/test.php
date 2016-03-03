<?php

//$fp = fopen("/dev/rtc0", "r");
$rtc_fd = fopen("/dev/rtc0", "w+");
//echo "<div id='data' style='display:none'>";
$tm=time();
echo $tm;

$ret = ioctl(rtc_fd, RTC_SET_TIME, $tm);

echo $ret;

/*while(! feof($fp))
{ 
echo fgets($fp); 
} */
//	echo "</div>";
fclose($fp); 
?> 
