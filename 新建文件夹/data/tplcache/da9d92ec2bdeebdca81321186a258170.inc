{!-- 节点基本信息 --}

{dede:item name='妹妹爽图 55619.com'
    imgurl='/upimg' imgdir='../upimg' language='gb2312'
    isref='no' refurl='' exptime='10'
    typeid='1' matchtype='string'}
{/dede:item}

{!-- 采集列表获取规则 --}

{dede:list source='var' sourcetype='list' 
          varstart='' varend=''}
  {dede:url value='http://'}{/dede:url}    
  {dede:need}{/dede:need}
  {dede:cannot}{/dede:cannot}
  {dede:linkarea}http://www.55619.com/'>主页[var:区域]<a href='#'>首页</a>{/dede:linkarea}
{/dede:list}

{!-- 网页内容获取规则 --}

{dede:art}
{dede:sppage sptype='none'}<TITLE>[var:分页区域]- 妹妹爽图</TITLE>{/dede:sppage}
  
  {dede:note field='dede_archives.sortrank' value='[var:内容]' comment='排序级别'
  isunit='' isdown=''}
    
    {dede:match}{/dede:match}
    
    {dede:function}@me = time();{/dede:function}
    
  {/dede:note}
  
  {dede:note field='dede_archives.pubdate' value='[var:内容]' comment='发布时间'
  isunit='' isdown=''}
    
    {dede:match}{/dede:match}
    
    {dede:function}@me = ( @me!="" ? GetMkTime(@me) : time());{/dede:function}
    
  {/dede:note}
  
  {dede:note field='dede_archives.litpic' value='[var:内容]' comment='缩略图'
  isunit='' isdown=''}
    
    {dede:match}{/dede:match}
    
    {dede:function}@me = @litpic;{/dede:function}
    
  {/dede:note}
  
  {dede:note field='dede_archives.title' value='[var:内容]' comment='文章标题'
  isunit='' isdown=''}
    
    {dede:match}{/dede:match}
    
    {dede:function}{/dede:function}
    
  {/dede:note}
  
  {dede:note field='dede_archives.writer' value='[var:内容]' comment='文章作者'
  isunit='' isdown=''}
    
    {dede:match}{/dede:match}
    
    {dede:function}{/dede:function}
    
  {/dede:note}
  
  {dede:note field='dede_addonarticle.body' value='[var:内容]' comment='文章内容'
  isunit='' isdown=''}
    
    {dede:match}<script src='/plus/ad_js.php?aid=2' language='javascript'></script>[var:内容]<DIV class=tool>上一篇：{/dede:match}
    
    {dede:function}{/dede:function}
    
  {/dede:note}
{/dede:art}