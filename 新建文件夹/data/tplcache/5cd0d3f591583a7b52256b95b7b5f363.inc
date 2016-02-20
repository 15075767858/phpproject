{dede:noteinfo notename="仪器仪表行业新闻" channelid="1" macthtype="string"
refurl="http://news.machine365.com/newslist-dust-65.shtml" sourcelang="gb2312" cosort="asc" isref="no" exptime="10" usemore="0" /}

{dede:listrule sourcetype="batch" rssurl="http://" regxurl="http://news.machine365.com/newslist-dust-65-(*).shtml"
startid="2" endid="10" addv="1" urlrule="area"
 musthas="" nothas="" listpic="0" usemore="0"}
    {dede:addurls}{/dede:addurls}
    {dede:batchrule}{/dede:batchrule}
    {dede:regxrule}{/dede:regxrule}
    {dede:areastart}<!--文章详细模块开始-->{/dede:areastart}
    {dede:areaend}<!--文章详细模块结束-->{/dede:areaend}
{/dede:listrule}
{dede:sppage sptype='full' sptype='full' srul='1' erul='5'}{/dede:sppage}
{dede:previewurl}http://news.machine365.com/newslist-dust-65.shtml{/dede:previewurl}
{dede:keywordtrim}{/dede:keywordtrim}
{dede:descriptiontrim}{/dede:descriptiontrim}
{dede:item field='title' value='' isunit='' isdown=''}
   {dede:match}<div class="newliIn_ti">[内容]</div>{/dede:match}
   
   {dede:function}{/dede:function}
{/dede:item}
{dede:item field='writer' value='' isunit='' isdown=''}
   {dede:match}{/dede:match}
   
   {dede:function}{/dede:function}
{/dede:item}
{dede:item field='source' value='' isunit='' isdown=''}
   {dede:match}<div class="ArticleCnt" id="ArticleCnt">[内容]</div>{/dede:match}
   
   {dede:function}{/dede:function}
{/dede:item}
{dede:item field='pubdate' value='' isunit='' isdown=''}
   {dede:match}{/dede:match}
   
   {dede:function}@me=GetMkTime(@me);{/dede:function}
{/dede:item}
{dede:item field='body' value='' isunit='1' isdown='1'}
   {dede:match}<div class="ArticleCnt" id="ArticleCnt">{/dede:match}
   
   {dede:function}{/dede:function}
{/dede:item}
