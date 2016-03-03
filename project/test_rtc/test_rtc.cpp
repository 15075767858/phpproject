/*
 * test_rtc.cpp
 *
 *  Created on: 2012-11-16
 *      Author: Owner
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/ioctl.h>
#include <linux/rtc.h>
#include <linux/ioctl.h>


int main( int argc,char* argv[] )
{
	time_t 				t1;
   	int 				ret;
	struct rtc_time 	rtc_tm,rtc;
	int  				rtc_fd;

	printf("====== RTC Test  ====\n");

	// 解析命令行参数：串口号   波特率
	if( argc > 1 )
	{
		sscanf( argv[1], "%d-%d-%d", &rtc_tm.tm_year, &rtc_tm.tm_mon, &rtc_tm.tm_mday );
	}
	else
	{
		rtc_tm.tm_mday = 7;
		rtc_tm.tm_mon = 11;
		rtc_tm.tm_year = 2012;
	}
	if( argc > 2 )
	{
		sscanf( argv[2], "%d:%d:%d", &rtc_tm.tm_hour, &rtc_tm.tm_min, &rtc_tm.tm_sec );
	}
	else
	{
		rtc_tm.tm_hour = 15;
		rtc_tm.tm_min = 20;
		rtc_tm.tm_sec = 0;
		rtc_tm.tm_wday = 3;
		rtc_tm.tm_yday = 10;
	}

	rtc_fd = open("/dev/rtc0", O_RDWR, 0);
	if (rtc_fd == -1)
	{
		printf("/dev/rtc0 open error\n");
		return -1;
	}

	rtc_tm.tm_mon = rtc_tm.tm_mon - 1;
	rtc_tm.tm_year = rtc_tm.tm_year - 1900;

	/* Set the system time/date */
	t1 = timelocal( (tm*)&rtc_tm );
    stime( &t1 );
    rtc_tm.tm_wday = 3;
	/* Set the RTC time/date */
    ret = ioctl(rtc_fd, RTC_SET_TIME, &rtc_tm);

	if (ret == -1)
	{
		printf("rtc ioctl RTC_SET_TIME error\r\n");
	}

	sleep(1);
	ret = ioctl(rtc_fd, RTC_RD_TIME, &rtc);

	printf("rtc:%d-%d-%d %d:%d:%d %d %d\n",rtc.tm_year+1900, rtc.tm_mon+1, rtc.tm_mday, rtc.tm_hour, rtc.tm_min, rtc.tm_sec, rtc.tm_wday, rtc.tm_yday);

	close(rtc_fd);

	return 0;
}


