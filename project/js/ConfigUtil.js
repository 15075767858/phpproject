/**
 * Created by Administrator on 2016/2/21.
 */
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
xmlToStr = function (xmlDom) {
    if (isIE()) {
        alert("Exception:no support IE browser,plase change borwser!");
        return xmlDom.xml;
    } else {
        //alert(new XMLSerializer().serializeToString(xmlDom));
        return new XMLSerializer().serializeToString(xmlDom);
    }
}
function showXml(fileName,success) {
    $.ajax({
        type: "POST",
        url: "xmlRW.php",
        data: "fileName=" + fileName + "&rw=r",
        success: success
    });
}

function saveXml(fileName,success,content){
    $.ajax({
        type: "POST",
        url: "xmlRW.php",
        data: "fileName="+fileName+"&content=" + content + "&rw=w",
        success: success
    });
}
function isIE() { //ie?
    if (!!window.ActiveXObject || "ActiveXObject" in window)
        return true;
    else
        return false;
}