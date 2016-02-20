<?php
$z[0]=Array("global","",117,143);
$z[0][4]['name']="cfg_webname";
$z[1]=Array("field","",184,213);
$z[1][4]['name']="keywords";
$z[2]=Array("field","",253,311);
$z[2][4]['name']="description";
$z[2][4]['function']="html2text(@me)";
$z[3]=Array("include","",746,781);
$z[3][4]['filename']="head.htm";
$z[4]=Array("global","",1655,1710);
$z[4][4]['name']="keyword";
$z[4][4]['function']="RemoveXSS(@me)";
$z[5]=Array("list","\r\n        <li><span class='search_title'><a href='[field:arcurl/]' target='_blank'><em style=\"font-style:normal;\">[field:title/]</a></span><span class='search_content'> [field:description/]...</span><span class='search_updatetime'>[field:pubdate function=\"MyDate('Y-m-d',@me)\"/]</span></li>\r\n        ",1871,2207);
$z[5][4]['perpage']="20";
$z[6]=Array("pagelist","",2283,2361);
$z[6][4]['listitem']="info,index,end,pre,next,pageno,option";
$z[6][4]['listsize']="5";
$z[7]=Array("include","",2442,2479);
$z[7][4]['filename']="footer.htm";

?>