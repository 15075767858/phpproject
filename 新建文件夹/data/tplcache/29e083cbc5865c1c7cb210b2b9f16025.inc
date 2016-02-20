{dede:listconfig}
{dede:noteinfo notename="99½¡¿µÒûÊ³" channelid="1" macthtype="string"
refurl="http://" sourcelang="gb2312" cosort="asc" isref="no" exptime="10" usemore="0" /}

{dede:listrule sourcetype="hand" rssurl="http://" regxurl="http://"
startid="1" endid="" addv="1" urlrule="area"
 musthas=".html" nothas="yyxw" listpic="1" usemore="0"}
	{dede:addurls}http://www.99-jk.cn/html/ys/yyxw.html{/dede:addurls}
	{dede:batchrule}{/dede:batchrule}
	{dede:regxrule}{/dede:regxrule}
	{dede:areastart}<table width="100%" border="0">{/dede:areastart}
	{dede:areaend}</table>{/dede:areaend}
{/dede:listrule}

{/dede:listconfig}

{dede:itemconfig}
{dede:sppage sptype='full'}{/dede:sppage}
{dede:previewurl}http://www.99-jk.cn/html/ys/2009092175046.html{/dede:previewurl}
{dede:keywordtrim}{/dede:keywordtrim}
{dede:descriptiontrim}{/dede:descriptiontrim}
{dede:item field='title' value='' isunit='' isdown=''}
   {dede:match}<h1 class="font_17">[ÄÚÈÝ]</h1>{/dede:match}
   
   {dede:function}{/dede:function}
{/dede:item}
{dede:item field='writer' value='' isunit='' isdown=''}
   {dede:match}{/dede:match}
   
   {dede:function}{/dede:function}
{/dede:item}
{dede:item field='source' value='' isunit='' isdown=''}
   {dede:match}{/dede:match}
   
   {dede:function}{/dede:function}
{/dede:item}
{dede:item field='pubdate' value='' isunit='' isdown=''}
   {dede:match}{/dede:match}
   
   {dede:function}@me=GetMkTime(@me);{/dede:function}
{/dede:item}
{dede:item field='body' value='' isunit='1' isdown='1'}
   {dede:match}<td width="660" style=" padding-top:10px" class="td_24">[ÄÚÈÝ]</td>{/dede:match}
   {dede:trim replace=''}<!--(.*)-->{/dede:trim}
   {dede:function}{/dede:function}
{/dede:item}

{/dede:itemconfig}