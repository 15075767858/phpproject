{!-- 节点基本信息 --}

{dede:item name='sina_日韩明星'
	imgurl='/upimg' imgdir='../upimg' language='gb2312'
	isref='no' refurl='' exptime='10'
	typeid='1' matchtype='string'}
{/dede:item}

{!-- 采集列表获取规则 --}

{dede:list source='var' sourcetype='list' 
           varstart='' varend=''}
  {dede:url value='http://ent.sina.com.cn/star/jp_kr/more.html'}{/dede:url}	
  {dede:need}ent.sina.com.cn{/dede:need}
  {dede:cannot}blog{/dede:cannot}
  {dede:linkarea}<tr><td colspan=2 class=f149>[var:区域]<tr><td colspan=2 valign=bottom background{/dede:linkarea}
{/dede:list}

{!-- 网页内容获取规则 --}

{dede:art}
{dede:sppage sptype='none'}{/dede:sppage}
  
  {dede:note field='dede_archives.title' value='[var:内容]' comment='文章标题'
   isunit='' isdown=''}
    
    {dede:match}<h1>[var:内容]</h1>{/dede:match}
        {dede:trim}<!(.*)>{/dede:trim}
    {dede:trim}<b>{/dede:trim}
    {dede:trim}</b>{/dede:trim}
    {dede:trim}</b-->{/dede:trim}
    {dede:trim}<div(.*)>{/dede:trim}
    {dede:trim}</div>{/dede:trim}
    {dede:trim}<a(.*)>{/dede:trim}
    {dede:trim}</a>{/dede:trim}

    {dede:function}{/dede:function}
    
  {/dede:note}
  
  {dede:note field='dede_addonarticle.body' value='[var:内容]' comment='文章内容'
   isunit='' isdown=''}
    
    {dede:match}<!--正文内容开始-->[var:内容]<!--正文内容结束-->{/dede:match}
        {dede:trim}<input(.*)>{/dede:trim}
    {dede:trim}<form(.*)>{/dede:trim}
    {dede:trim}</form>{/dede:trim}
    {dede:trim}<!(.*)>{/dede:trim}
    {dede:trim}<div(.*)>{/dede:trim}
    {dede:trim}</div>{/dede:trim}
    {dede:trim}<a(.*)>{/dede:trim}
    {dede:trim}</a>{/dede:trim}
    {dede:trim}<span(.*)>{/dede:trim}
    {dede:trim}</span>{/dede:trim}
    {dede:trim}(blog){/dede:trim}
    {dede:trim}<font(.*)>{/dede:trim}
    {dede:trim}</font>{/dede:trim}
    {dede:trim}(听歌,blog){/dede:trim}
    {dede:trim}新浪娱乐独家稿件(.*)>全部或部分转载。{/dede:trim}

    {dede:function}{/dede:function}
    
  {/dede:note}
  
  {dede:note field='dede_archives.writer' value='[var:内容]' comment='文章作者'
   isunit='' isdown=''}
    
    {dede:match}{/dede:match}
    
    {dede:function}{/dede:function}
    
  {/dede:note}
  
  {dede:note field='dede_archives.source' value='[var:内容]' comment='文章来源'
   isunit='' isdown=''}
    
    {dede:match}<span class="linkRed02">[var:内容]</a></span></font></div>{/dede:match}
        {dede:trim}<!(.*)>{/dede:trim}
    {dede:trim}<div(.*)>{/dede:trim}
    {dede:trim}</div>{/dede:trim}
    {dede:trim}<a(.*)>{/dede:trim}
    {dede:trim}</a>{/dede:trim}

    {dede:function}{/dede:function}
    
  {/dede:note}
  
  {dede:note field='dede_archives.pubdate' value='[var:内容]' comment='发布时间'
   isunit='' isdown=''}
    
    {dede:match}{/dede:match}
    
    {dede:function}if(@me!="") @me = GetMkTime(@me);
else @me = time();{/dede:function}
    
  {/dede:note}
  
  {dede:note field='dede_archives.sortrank' value='[var:内容]' comment='排序级别'
   isunit='' isdown=''}
    
    {dede:match}{/dede:match}
    
    {dede:function}@me = time();{/dede:function}
    
  {/dede:note}
  
  {dede:note field='dede_archives.litpic' value='[var:内容]' comment='缩略图'
   isunit='' isdown=''}
    
    {dede:match}{/dede:match}
    
    {dede:function}@me = @litpic;{/dede:function}
    
  {/dede:note}
  
  {dede:note field='dede_archives.senddate' value='[var:内容]' comment='录入时间'
   isunit='' isdown=''}
    
    {dede:match}{/dede:match}
    
    {dede:function}@me = time();{/dede:function}
    
  {/dede:note}
{/dede:art}