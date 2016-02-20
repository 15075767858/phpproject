<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<link rel="stylesheet" href="css/bootstrap.min.css">
<link rel="stylesheet" href="css/main.css">
<!-- TemplateParam name="class" type="URL" value="file:///F|/EM9460www/div-b" -->
<meta http-equiv="X-UA-Compatible" content="IE=edge,Chrome=1" />
<meta http-equiv="X-UA-Compatible" content="IE=9" />
<title>BACnet Router&Control</title>
<style type="text/css">
.main{
	width: 100%;

}

.div-c {
	font-family: Arial, Helvetica, sans-serif;
}
.div-bas10000{
	position:fixed;
	left:213px;
	top:326px;
	width:670px;
	height:69px;
	font-weight: bold;
	font-family: "Arial";
	font-size: 18px;
	font-color:#00F
	font-style: normal;
	line-height: 1px;
} 
.div-info{
	position:absolute;
	left:103px;
	top:505px;
	background:#000f;
	width: 960px;
	height: 780px;
 box-shadow:5px 5px 10px #909090;

} 
.div-set1{
	position:absolute;
	left:94px;
	top:260px;
	background:#000F
	width:450px;
	height:45px;
	font-size: 18px;
	width: 156px;
	background-color: #6FC;
	color: #639;
	padding-top:10px;
	border:1px solid #000;
   box-shadow:5px 5px 10px #909090;
} 

.div-set2{
	position:absolute;
	left:297px;
	top:260px;
	background:#000F
	width:450px;
	height:45px;
	font-size: 18px;
	width: 156px;
	background-color: #6FC;
	color: #639;
	padding-top:10px;
	border:1px solid #000;
 box-shadow:5px 5px 10px #909090;

} 

.div-set3{
	position:absolute;
	left:505px;
	top:260px;
	background:#000F
	width:450px;
	height:45px;
	font-size: 18px;
	width: 156px;
	background-color: #6FC;
	color: #639;
	padding-top:10px;
	border:1px solid #000;
 box-shadow:5px 5px 10px #909090;

} 
.div-set4{
	position:absolute;
	left:568px;
	top:260px;
	background:#000F
	width:450px;
	height:45px;
	font-size: 18px;
	width: 156px;
	background-color: #6FC;
	color: #639;
	padding-top:10px;
	border:1px solid #000;
	 box-shadow:5px 5px 10px #909090;


} 
.div-set5{
	position:absolute;
	left:703px;
	top:260px;
	background:#000F
	width:450px;
	height:45px;
	font-size: 18px;
	width: 156px;
	background-color: #6FC;
	color: #639;
	padding-top:10px;
	border:1px solid #000;
	 box-shadow:5px 5px 10px #909090;

} 
.div-set6{
	position:absolute;
	left:908px;
	top:260px;
	background:#000F
	width:450px;
	height:45px;
	font-size: 18px;
	width: 156px;
	background-color: #6FC;
	color: #639;
	padding-top:10px;
	border:1px solid #000;
	box-shadow:5px 5px 10px #909090;

} 



.div-c{
	position:absolute;
	left:430px;
	top:400px;
	background:#00F;
	width:auto;
	height:auto;
	font-size: 24px;
	font-family: Arial, Helvetica, sans-serif;
	background-color: #FFFFFF;

} 


</style>
</head>


<body>

<div class="main">

<img src="title.png" width="960" height="200"></img> 

<div class="div-bas10000" id="DDCname">


</div>
<div class="div-c" id="www">
<a href="http://www.10000bas.com">http://www.10000bas.com</a></div>

<div class="div-set1" id="ipconfig">

  <div align="center"><a href="javascript:;" title="IP Config" data-toggle="modal" data-target="#exampleModal" data-whatever="@mdo"> IP Config</a></div>
</div>

<div class="div-set2" id="date">
  <div align="center"><a href="driverconfig" title="Date&time">Date time</a></div>
</div>

<div class="div-set3" id="date">
  <div align="center"><a href="cgi-bin/get_clock.cgi" title="BACnet Config">BACnet Config</a></div>
</div>
<div class="div-set5">
  <div align="center"><a href="reset.htm" title="Reboot">Reboot</a> </div>
</div>
<div class="div-set6" id="divset6">
  <div align="center"><a href="download.html" title="download">download</a> </div>
</div>

<div class="div-logo2" id="loge2"></div>


<div class="div-info" id="info">
<div align="center">

<img src="home.png" width="960" height="780" ></img> 

</div>
<p>&nbsp;</p>


<?php 
$fp = fopen("mnt/nandfalsh/userinfo.txt", "r"); 
echo "<div id='data' style='display:none'>";
while(! feof($fp)) 
{ 
echo fgets($fp); 
} 
	echo "</div>";
fclose($fp); 
?> 



<div class="modal fade" id="exampleModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title" id="exampleModalLabel">change info file userinfo.txt</h4>
      </div>
      <div class="modal-body">
        <form id="changeini">

        <div class="form-group">
            <label for="message-text" class="control-label">IPAddress</label>
            <ul class="inputgroup">
            	<li><input type="text"  id="IPAddress1"></li>
            	<li><input type="text"  id="IPAddress2"></li>
            	<li><input type="text"  id="IPAddress3"></li>
            	<li><input type="text"  id="IPAddress4"></li>
            	<div style="clear:both"></div>
            </ul>
          </div>
          <div class="form-group hidden" >
            <label for="recipient-name" class="control-label">DHCP</label>
            <ul class="inputgroup">
            	<li><input type="text"  id="DHCP1"></li>
            	<li><input type="text"  id="DHCP2"></li>
            	<li><input type="text"  id="DHCP3"></li>
            	<li><input type="text"  id="DHCP4"></li>
            	<div style="clear:both"></div>
            </ul>
          </div>
          
<div class="form-group">
            <label for="message-text" class="control-label">SubnetMask</label>
            <ul class="inputgroup">
            	<li><input type="text"  id="SubnetMask1"></li>
            	<li><input type="text"  id="SubnetMask2"></li>
            	<li><input type="text"  id="SubnetMask3"></li>
            	<li><input type="text"  id="SubnetMask4"></li>
            	<div style="clear:both"></div>
            </ul>
          </div>
          <div class="form-group">
            <label for="message-text" class="control-label">DefaultGateway</label>
            <ul class="inputgroup">
            	<li><input type="text"  id="DefaultGateway1"></li>
            	<li><input type="text"  id="DefaultGateway2"></li>
            	<li><input type="text"  id="DefaultGateway3"></li>
            	<li><input type="text"  id="DefaultGateway4"></li>
            	<div style="clear:both"></div>
            </ul>
          </div>
          
          
          <div class="form-group hidden">
            <label for="message-text" class="control-label">Name</label>
            <textarea class="form-control" id="Name"></textarea>
          </div>
          <div class="form-group hidden">
            <label for="message-text" class="control-label">Parameters</label>
            <textarea class="form-control" id="Parameters"></textarea>
          </div>
        </form>
      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
        <button type="button" id="changeinisub" class="btn btn-primary">Ok</button>
      </div>
    </div>
  </div>
</div>
</div>
</body>
<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
<!--[if lt IE 9]>
  <script src="http://apps.bdimg.com/libs/html5shiv/3.7/html5shiv.min.js"></script>
  <script src="http://apps.bdimg.com/libs/respond.js/1.4.2/respond.min.js"></script>
<![endif]-->





<script src="js/jquery.min.js"></script>
<script src="js/bootstrap.min.js"></script>
	<script type="text/javascript">
	var jDate=parseINIString(document.getElementById("data").innerHTML);
	var DHCP=jDate["[LOCAL_MACHINE"].DHCP.replace(/\"/g, " ").split(".");
	var DefaultGateway=jDate["[LOCAL_MACHINE"].DefaultGateway.replace(/\"/g, " ").split(".");
	var IPAddress=jDate["[LOCAL_MACHINE"].IPAddress.replace(/\"/g, " ").split(".");
	var SubnetMask=jDate["[LOCAL_MACHINE"].SubnetMask.replace(/\"/g, " ").split(".");
	for(var i=0;i<4;i++){
		$("#DHCP"+(i+1)).val(DHCP[i].trim());
		$("#DefaultGateway"+(i+1)).val($.trim(DefaultGateway[i]));
 		$("#IPAddress"+(i+1)).val($.trim(IPAddress[i]));
 		$("#SubnetMask"+(i+1)).val($.trim(SubnetMask[i]));
	}
	
 	var Name=jDate["[USER_EXE"].Name.replace(/\"/g, "");
 	var Parameters=jDate["[USER_EXE"].Parameters.replace(/\"/g, "");
 	$("#Name").val(Name);
	$("#Parameters").val(Parameters);
$("#changeinisub").on("click",function(){
	var DHCP=$("#DHCP1").val()+"."+$("#DHCP2").val()+"."+$("#DHCP3").val()+"."+$("#DHCP4").val();
	var DefaultGateway=$("#DefaultGateway1").val()+"."+$("#DefaultGateway2").val()+"."+$("#DefaultGateway3").val()+"."+$("#DefaultGateway4").val();
	var IPAddress=$("#IPAddress1").val()+"."+$("#IPAddress2").val()+"."+$("#IPAddress3").val()+"."+$("#IPAddress4").val();
	var SubnetMask=$("#SubnetMask1").val()+"."+$("#SubnetMask2").val()+"."+$("#SubnetMask3").val()+"."+$("#SubnetMask4").val();
	SubnetMask=SubnetMask.trim();
	console.log(SubnetMask)
	if(SubnetMask!="255.255.255.0"&SubnetMask!="255.255.0.0"){
		alert("error SubnetMask only 255.255.255.0 or 255.255.0.0")
		return;
	}
	var Name=$("#Name").val();
	var Parameters=$("#Parameters").val();
	var uploadData='[LOCAL_MACHINE]\
\nDHCP="'+DHCP+'"\
\nDefaultGateway="'+DefaultGateway+'"\
\nIPAddress="'+IPAddress+'"\
\nSubnetMask="'+SubnetMask+'"\
\n[USER_EXE]\
\nName="'+Name+'"\
\nParameters="'+Parameters+'"';

$.ajax({
	type:"post",
	url:"iotext.php",
	dataType : 'json',
	data:"content="+uploadData,
	success : function(){
	
	}

})
alert("Ok");
		window.location.reload();
});

function parseINIString(data){  
    var regex = {  
        section: /^\s*\s*([^]*)\s*\]\s*$/,  
        param: /^\s*([\w\.\-\_]+)\s*=\s*(.*?)\s*$/,  
        comment: /^\s*;.*$/  
    }; 
    var value = {};  
    var lines = data.split(/\r\n|\r|\n/);  
    var section = null;  
    lines.forEach(function(line){  
        if(regex.comment.test(line)){  
            return;  
        }else if(regex.param.test(line)){  
            var match = line.match(regex.param);  
            if(section){  
                value[section][match[1]] = match[2];  
            }else{  
                value[match[1]] = match[2];  
            }  
        }else if(regex.section.test(line)){  
            var match = line.match(regex.section);  
            value[match[1]] = {};  
            section = match[1];  
        }else if(line.length == 0 && section){  
            section = null;  
        };
    });
    return value;
}  
$(".inputgroup input").keyup(function(e){ 
if(parseInt(this.value)>255){
alert("The number is not greater than 255")
this.value=0;
return;
}
this.value=parseInt(this.value);
});


	</script>
</html>
