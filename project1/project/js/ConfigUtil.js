/**
 * Created by Administrator on 2016/2/21.
 */
function parseINIString(data) {
    var regex = {
        section: /^\s*\s*([^]*)\s*\]\s*$/,
        param: /^\s*([\w\.\-\_]+)\s*=\s*(.*?)\s*$/,
        comment: /^\s*;.*$/
    };
    var value = {};
    var lines = data.split(/\r\n|\r|\n/);
    var section = null;
    lines.forEach(function (line) {
        if (regex.comment.test(line)) {
            return;
        } else if (regex.param.test(line)) {
            var match = line.match(regex.param);
            if (section) {
                value[section][match[1]] = match[2];
            } else {
                value[match[1]] = match[2];
            }
        } else if (regex.section.test(line)) {
            var match = line.match(regex.section);
            value[match[1]] = {};
            section = match[1];
        } else if (line.length == 0 && section) {
            section = null;
        }
        ;
    });
    return value;
}
loadXML = function (xmlString) {
    var xmlDoc = null;
    if (!window.DOMParser && window.ActiveXObject) {
        var xmlDomVersions = ['MSXML.2.DOMDocument.6.0', 'MSXML.2.DOMDocument.3.0', 'Microsoft.XMLDOM'];
        for (var i = 0; i < xmlDomVersions.length; i++) {
            try {
                xmlDoc = new ActiveXObject(xmlDomVersions[i]);
                xmlDoc.async = false;
                xmlDoc.loadXML(xmlString);
            } catch (e) {
            }
        }
    } else if (window.DOMParser && document.implementation && document.implementation.createDocument) {
        try {
            domParser = new DOMParser();
            xmlDoc = domParser.parseFromString(xmlString, 'text/xml');
        } catch (e) {
        }
    } else {
        return null;
    }

    return xmlDoc;
}
function serializeXml (xmldom) {
    if (typeof XMLSerializer != "undefined") {
        if((new XMLSerializer()).serializeToString(xmldom).indexOf("xml version")){
            return (new XMLSerializer()).serializeToString(xmldom);
        }

        return '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>'+"\n"+(new XMLSerializer()).serializeToString(xmldom);
    } else if (document.implementation.hasFeature("LS", "3.0")) {
        var implementation = document.implementation;
        var serializer = implementation.createLSSerializer();
        return serializer.writeToString(xmldom);
    } else if (typeof xmldom.xml != "undefined") {
        return xmldom.xml;
    } else {

        throw new Error("Could not serialize XML DOM.");
    }
}
xmlToStr = function (xmlDom) {
    if (isIE()) {
        //console.log(xmlDom.xml);
        //xmlDoc=loadXMLDoc("modbus_config.xml");
        //return xmlDoc.xml;
        //alert("Exception:no support IE browser,plase change borwser!");
        //xmlDoc=loadXMLDoc(xmlDom.childNodes[0]);
        return xmlDom.xml;
    } else {
        //alert(new XMLSerializer().serializeToString(xmlDom));
        return new XMLSerializer().serializeToString(xmlDom);
    }
}
//请求一个XML文档
function loadXMLDoc(dname)
{
    try //Internet Explorer
    {
        xmlDoc=new ActiveXObject("Microsoft.XMLDOM");
    }
    catch(e)
    {
        try //Firefox, Mozilla, Opera, etc.
        {
            xmlDoc=document.implementation.createDocument("","",null);
        }
        catch(e) {alert(e.message)}
    }
    try
    {
        xmlDoc.async=false;
        xmlDoc.load(dname);
        return(xmlDoc);
    }
    catch(e) {alert(e.message)}
    return(null);
}
//读取一个文件
function showXml(fileName, success) {
    $.ajax({
        type: "POST",
        url: "xmlRW.php",
        async: false,
        data: "fileName=" + fileName + "&rw=r",
        success: success
    });
}
//保存一个文件
function saveXml(fileName, success, content) {
    $.ajax({
        type: "POST",
        url: "xmlRW.php",
        async: false,
        data: "fileName=" + fileName + "&content=" + content + "&rw=w",
        success: success
    });
}
function isIE() { //ie?
    if (!!window.ActiveXObject || "ActiveXObject" in window)
        return true;
    else
        return false;
}

//ie下节点转字符串
function NodeToStr(node){
    var sNodeAttrs="<"+node.nodeName+" ";
    var oAttr=node.attributes;
    sNodeAttrs+='feed_dog= \"'+oAttr[1].nodeValue+'\" name=\"'+oAttr[0].nodeValue+'\" ';
    /*for(var i=0;i<oAttr.length;i++){
     sNodeAttrs+=oAttr[i].nodeName+"=\'"+oAttr[i].nodeValue+"\' ";
     }*/

    if(node.nodeValue==null){
        sNodeAttrs+="/>"
    }else{
        sNodeAttrs+=">"+node.nodeValue+"</"+node.nodeName+">";
    }
    return sNodeAttrs;
}

function XmlToFrameJson(XmlDom) {

    var jsonobj = {};
    if (XmlDom.nodeType != 1) {
console.log(XmlDom.nodeType);
    }
    var oNewChildNode = [];
    for (var i = 0; i < XmlDom.childNodes.length; i++) {
        jsonobj['name'] = XmlDom.tagName;

        console.log( XmlDom.tagName)
        if(XmlDom.childNodes.length==1){
         jsonobj["value"] =XmlDom.innerHTML;
         }
        if (XmlDom.childNodes[i].nodeType == 1) {
            var childNode = XmlDom.childNodes[i];

            oNewChildNode.push(XmlDom.childNodes[i]);

            var attrs = XmlDom.attributes;
            if (attrs.length > 0) {
                for (attr in attrs) {
                    if (attr && attrs[attr].value && attrs[attr]) {
                        //console.log(attrs[attr].name + ":" + attrs[attr].value);
                        jsonobj[attrs[attr].name] = attrs[attr].value;
                    }
                }
            }
            //console.log(childNode.childNodes);
            // var aType1 = childNode.childNodes;

            if (oNewChildNode.length > 0) {

                jsonobj["children"] = [];
                for (var j = 0; j < oNewChildNode.length; j++) {

                    jsonobj["children"].push(XmlToFrameJson(oNewChildNode[j]));
                }
            }
        }
        //console.log(XmlDom.childNodes[i])
         /*if(XmlDom.childNodes[i].nodeType == 3){
            console.log(XmlDom.childNodes[i].nodeName)
                console.log(XmlDom.childNodes[i])
        }*/
    }
    console.log(jsonobj)
    return jsonobj;
}
function deleteXmlNodeByIndex(XmlDom,Index){
    var aDoms=XmlDom.querySelectorAll("*");
    console.log(aDoms);
    aDoms[Index].parentNode.removeChild(aDoms[Index]);
    return XmlDom;
}
function addXmlNodeByIndex(XmlDom,Index,oEle){
    var aDoms=XmlDom.querySelectorAll("*");
    console.log(aDoms);
    aDoms[Index].appendChild(oEle);
    return XmlDom;
};


/*
function deleteXmlNodeByIndex(XmlDom,Index){
    var indexCount=0;
    findDom(XmlDom,Index);
    function findDom(XmlDom,Index){

    for (var i = 0; i < XmlDom.childNodes.length; i++) {
        if (XmlDom.childNodes[i].nodeType == 1) {
            console.log(XmlDom.childNodes[i])
            indexCount++;

        }
    }
    }
    return XmlDom;
}*/


/*
 //var name = childNode.tagName;
 //jsonobj['name'] = XmlDom.childNodes[i].tagName;
 //console.log(name)

 var iCount=0;
 for(var k=0;k<childNode.childNodes.length;k++){
 if(childNode.childNodes[k].nodeType==1){
 oNewChildNode[iCount]=childNode.childNodes[k];
 iCount++;
 }
 }*/