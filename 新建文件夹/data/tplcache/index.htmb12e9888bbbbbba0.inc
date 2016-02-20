<?php
$z[0]=Array("global","",433,459);
$z[0][4]['name']="cfg_webname";
$z[1]=Array("global","",503,533);
$z[1][4]['name']="cfg_description";
$z[2]=Array("global","",570,597);
$z[2][4]['name']="cfg_keywords";
$z[3]=Array("global","",1795,1821);
$z[3][4]['name']="cfg_webname";
$z[4]=Array("global","",1891,1917);
$z[4][4]['name']="cfg_webname";
$z[5]=Array("global","",1926,1952);
$z[5][4]['name']="cfg_webname";
$z[6]=Array("global","",2077,2102);
$z[6][4]['name']="cfg_cmsurl";
$z[7]=Array("global","",2633,2659);
$z[7][4]['name']="cfg_webname";
$z[8]=Array("channelartlist","\r\n <li class=\"nav-line\"></li>\r\n        <li id='nav_[field:global name=autoindex runphp=\"yes\"]@me=@me+1;[/field:global]' style='width:134px;' ><a href='{dede:field name='typeurl'/}' 0 title='{dede:field name='typename'/}' class='hover-none nav'><span>{dede:field name='typename'/}</span></a>\r\n          <dl>\r\n            {dede:channel type='son' row='8' currentstyle=\"\r\n            <dd><a href='~typelink~' ~rel~><span>~typename~</span></a></dd>\r\n            \"}\r\n            <dd><a href='[field:typeurl/]' title='[field:typename/]' >[field:typename/]</a></dd>\r\n            {/dede:channel}\r\n          </dl>\r\n        </li>\r\n        ",2720,3405);
$z[8][4]['typeid']="top";
$z[9]=Array("type","\r\n        <li id='nav_10' style='width:133px;' ><a href='[field:typelink/]'  title='[field:typename/]' class='hover-none nav'><span>[field:typename/]</span></a></li>\r\n        ",3451,3660);
$z[9][4]['typeid']="5";
$z[10]=Array("sql"," \r\n      [field:content  function='cn_substr(html2text(@me),790)'/]...\r\n      ",5110,5259);
$z[10][4]['sql']="Select content from dede_arctype where id=1";
$z[11]=Array("arclist","\r\n        <li class=\"CON--top-rs\" style=\"width:310px;\">\r\n          <dt class=\"fl\" style=\"width:120px;\"> <a href=\"[field:arcurl/]\" title=\"[field:title/]\"> <img src=\"[field:picname/]\" alt=\"[field:title/]\" title=\"[field:title/]\" width=\"120\" height=\"80\"/></a> </dt>\r\n          <dd class=\"fr\" style=\"width:175px;\">\r\n            <h2 style=\"width:175px;\"><a href=\"[field:arcurl/]\" title=\"[field:title/]\">[field:title/]</a></h2>\r\n            <p style=\"height:45px;\">[field:info/]...</p>\r\n          </dd>\r\n          <div class=\"clear\"></div>\r\n        </li>\r\n        ",5644,6265);
$z[11][4]['flag']="c";
$z[11][4]['typeid']="11";
$z[11][4]['infolen']="100";
$z[12]=Array("arclist","\r\n        <li class=\"CON--top-rx\"><a href=\"[field:arcurl/]\" title=\"[field:title/]\">[field:title/]</a></li>\r\n        ",6285,6463);
$z[12][4]['row']="2";
$z[12][4]['typeid']="11";
$z[12][4]['titlelen']="60";
$z[13]=Array("arclist","\r\n        <li class='list'><a href='[field:arcurl/]' title='[field:title/]' target='_self' class='img'><img src='[field:picname/]' alt='[field:title/]' title='[field:title/]' width='203' height='150' /></a>\r\n          <h3 style='width:203px;'><a href='[field:arcurl/]' title='[field:title/]' target='_self'>[field:title/]</a></h3>\r\n        </li>\r\n        ",7235,7637);
$z[13][4]['row']="8";
$z[13][4]['typeid']="36";
$z[14]=Array("include","",7745,7782);
$z[14][4]['filename']="footer.htm";

?>