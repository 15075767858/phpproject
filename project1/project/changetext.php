
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
	<title>userinfo.txt文件修改</title>
	<link rel="stylesheet" href="http://cdn.bootcss.com/bootstrap/3.3.5/css/bootstrap.min.css">
</head>
<style type="text/css">
	*{margin: 0px;
		padding: 0px}
	.inputgroup{
		list-style: none;
	}
	.inputgroup li{
		width: 24%;
float: left;
	}
	.inputgroup input{
		width: 100%;
		text-align: right;
	}
</style>
<body>
<?php 

$fp = fopen("userinfo.txt", "r"); 
echo "<div id='data' style='display:none'>";
while(! feof($fp)) 
{ 
echo fgets($fp); 
} 
	echo "</div>";
fclose($fp);
?> 



<button type="button" class="btn btn-primary" data-toggle="modal" data-target="#exampleModal" data-whatever="@mdo">Edit userinfo.txt</button>

<div class="modal fade" id="exampleModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title" id="exampleModalLabel">修改配置文件userinfo.txt</h4>
      </div>
      <div class="modal-body">
        <form id="changeini">
          <div class="form-group">
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
            <label for="message-text" class="control-label">DefaultGateway</label>
            <ul class="inputgroup">
            	<li><input type="text"  id="DefaultGateway1"></li>
            	<li><input type="text"  id="DefaultGateway2"></li>
            	<li><input type="text"  id="DefaultGateway3"></li>
            	<li><input type="text"  id="DefaultGateway4"></li>
            	<div style="clear:both"></div>
            </ul>
          </div>
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
            <label for="message-text" class="control-label">Name</label>
            <textarea class="form-control" id="Name"></textarea>
          </div>
          <div class="form-group">
            <label for="message-text" class="control-label">Parameters</label>
            <textarea class="form-control" id="Parameters"></textarea>
          </div>
        </form>
      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-default" data-dismiss="modal">关闭</button>
        <button type="button" id="changeinisub" class="btn btn-primary">确认修改</button>
      </div>
    </div>
  </div>
</div>
</body>
</html>


<script src="http://cdn.bootcss.com/jquery/1.11.3/jquery.min.js"></script>
<script src="http://cdn.bootcss.com/bootstrap/3.3.5/js/bootstrap.min.js"></script>
	<script type="text/javascript">
	var jDate=parseINIString(document.getElementById("data").innerHTML);
	
	var DHCP=jDate["[LOCAL_MACHINE"].DHCP.replace(/\"/g, "").split(".");
	var DefaultGateway=jDate["[LOCAL_MACHINE"].DefaultGateway.replace(/\"/g, "").split(".");;
	var IPAddress=jDate["[LOCAL_MACHINE"].IPAddress.replace(/\"/g, "").split(".");;
	var SubnetMask=jDate["[LOCAL_MACHINE"].SubnetMask.replace(/\"/g, "").split(".");;
	for(var i=0;i<4;i++){
		$("#DHCP"+(i+1)).val(DHCP[i]);
		$("#DefaultGateway"+(i+1)).val(DefaultGateway[i]);
 		$("#IPAddress"+(i+1)).val(IPAddress[i]);
 		$("#SubnetMask"+(i+1)).val(SubnetMask[i]);
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
alert(uploadData)
$.ajax({
	type:"post",
	url:"iotext.php",
	dataType : 'json',
	data:"content="+uploadData,
	success : function(){
		alert("成功");
	}

})
alert("修改成功");
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


	</script>
