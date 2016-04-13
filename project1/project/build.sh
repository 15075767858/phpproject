#!/bin/sh
cd /mnt/nandflash/web_arm/apr/lib
ln -s libapr-1.so.0.4.5 libapr-1.so
ln -s libapr-1.so.0.4.5 libapr-1.so.0
cd /mnt/nandflash/web_arm/apr-util/lib
ln -s libaprutil-1.so.0.3.12 libaprutil-1.so
ln -s libaprutil-1.so.0.3.12 libaprutil-1.so.0
ln -s libexpat.so.0.5.0 libexpat.so
ln -s libexpat.so.0.5.0 libexpat.so.0
cd /mnt/nandflash/web_arm/pcre/lib
ln -s libpcre.so.0.0.1 libpcre.so
ln -s libpcre.so.0.0.1 libpcre.so.0
ln -s libpcrecpp.so.0.0.0 libpcrecpp.so
ln -s libpcrecpp.so.0.0.0 libpcrecpp.so.0
ln -s libpcreposix.so.0.0.0 libpcreposix.so
ln -s libpcreposix.so.0.0.0 libpcreposix.so.0
cd /mnt/nandflash/web_arm
mv libxml2.so.2.7.4 /lib
mv libz.so.1.2.8 /lib
cd /lib
rm libz.so.1
ln -s libz.so.1.2.8 libz.so.1
ln -s libxml2.so.2.7.4 libxml2.so.2
cd /mnt/nandflash/web_arm
chmod 777 apache2.4/ -R
chmod 777 php/ -R
chmod 777 apr/ -R
chmod 777 apr-util/ -R
chmod 777 pcre/ -R

