{dede:listconfig}
{dede:noteinfo notename="39成人教育" channelid="1" macthtype="string"
refurl="http://" sourcelang="gb2312" cosort="asc" isref="no" exptime="10" usemore="0" /}

{dede:listrule sourcetype="hand" rssurl="http://" regxurl="http://"
startid="1" endid="" addv="1" urlrule="area"
 musthas=".html" nothas="" listpic="1" usemore="0"}
	{dede:addurls}http://sex.39.net/xjy/crxjy/index.html{/dede:addurls}
	{dede:batchrule}{/dede:batchrule}
	{dede:regxrule}{/dede:regxrule}
	{dede:areastart}<div class="newslist">{/dede:areastart}
	{dede:areaend}<div class="page">{/dede:areaend}
{/dede:listrule}

{/dede:listconfig}

{dede:itemconfig}
{dede:sppage sptype='full'}{/dede:sppage}
{dede:previewurl}http://sex.39.net/xjy/crxjy/101/4/1115968.html{/dede:previewurl}
{dede:keywordtrim}{/dede:keywordtrim}
{dede:descriptiontrim}{/dede:descriptiontrim}
{dede:item field='title' value='' isunit='' isdown=''}
   {dede:match}<h1>[内容]</h1>{/dede:match}
   
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
   {dede:match}<div class="article">[内容]<div class="page">{/dede:match}
   {dede:trim replace=''}<div style="float:left; padding-top:5px;">(.*)</div>{/dede:trim}
{dede:trim replace=''}<div style="float:left; padding-left:10px;">(.*)</div>{/dede:trim}
{dede:trim replace=''}<a([^>]*)>{/dede:trim}
{dede:trim replace=''}</a>{/dede:trim}
{dede:trim replace=''}<iframe([^>]*)>(.*)</iframe>{/dede:trim}
{dede:trim replace=''}<div([^.]*)>{/dede:trim}
{dede:trim replace=''}</div>{/dede:trim}
   {dede:function}{/dede:function}
{/dede:item}

{/dede:itemconfig}