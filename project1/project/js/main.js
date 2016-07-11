/**
 * Created by liuzhencai on 16/7/11.
 */

function globalClick() {

    var IPCombo = Ext.create("Ext.form.field.ComboBox", {
        fieldLabel: "IP",
        store: ['127.0.0.1', window.location.hostname, "192.168.253.253"],
        labelWidth: 40,
        value: location.hostname
    });
    var PortCombo = Ext.create("Ext.form.field.ComboBox", {
        fieldLabel: "port number",
        store: ["6379"],
        value: "6379"
    });
    var formPanel = Ext.create("Ext.form.Panel", {
        region: "north",
        items: {
            xtype: "fieldset",
            title: "link option",
            layout: "hbox",
            defaults: {
                margin: 10
            },
            items: [
                IPCombo, PortCombo,
                {
                    xtype: "button",
                    text: "link",
                    handler: function () {
                        var treeStore = Ext.create("Ext.data.TreeStore", {
                            fields: ["text"],
                            proxy: {
                                type: "ajax",
                                autoLoad: true,
                                url: "php/test4.php?ip=" + IPCombo.value + "&port=" + PortCombo.value,
                                reader: {
                                    type: "json"
                                }
                            },
                            root: {
                                text: "root"
                            }
                        })
                        treePanel.setStore(treeStore);

                    }
                }
            ]
        }
    })
    var treePanel = Ext.create("Ext.tree.Panel", {
        region: "center",
        useArrows: true,
        animate: true,
        checkPropagation: "both",
        rootVisible: false,
        bufferedRenderer: false,
        tbar: [{
            text: 'Expand All',
            scope: this,
            handler: function (th) {
                treePanel.expandAll()
            }
        }, {
            text: 'Collapse All',
            scope: this,
            handler: function (th) {
                treePanel.collapseAll()
            }
        }, "->", {
            text: "config read time", handler: function () {
                //var xml =   loadXML("/mnt/nandflash/bac_config.xml")
                var xmlFile="../../bac_config.xml";
                showXml(xmlFile, function (res) {
                  var   xml = loadXML(res)
                    var readtime = xml.querySelector("read_time")
                    if (readtime) {
                        var value = readtime.innerHTML;
                    }
                    var win = Ext.create("Ext.window.Window", {
                        width: 300,
                        bodyPadding:10,
                        title:"Config Read Time",
                        layout:"auto",
                        modal: true,
                        autoShow: true,
                        items: {
                            xtype: "textfield",
                            fieldLabel: "Read Time",
                            value: value||""
                        },
                        buttons: [{
                            text: "Ok",
                            handler: function () {
                                if (readtime) {
                                    readtime.innerHTML = win.items.items[0].value
                                    var content = formatXml(xmlToStr(xml))
                                    saveXml(xmlFile, function () {
                                        Ext.Msg.alert("Massage", "Ok!")
                                    }, content)

                                }else{
                                    var root = document.createElement("root");
                                    var rootChildren = xml.querySelector("root").querySelectorAll("*")
                                    readtime = document.createElement("read_time")
                                    readtime.innerHTML=win.items.items[0].value
                                    root.appendChild(readtime);
                                    for(var i=0;i<rootChildren.length;i++){
                                        var tag = document.createElement(rootChildren[i].tagName);
                                        tag.innerHTML=rootChildren[i].innerHTML
                                        root.appendChild(tag)
                                    }
                                    var content = '<?xml version="1.0" encoding="UTF-8" standalone="no"?>\r\n' + formatXml(root.outerHTML)
                                    saveXml(xmlFile, function () {
                                        Ext.Msg.alert("Massage", "Ok!")
                                    }, content)
                                }

                                win.close();
                            }
                        }]
                    })
                    console.log(xmlToStr(loadXML(res)))
                })
            }
        }]
    })

    Ext.create("Ext.window.Window", {
        height: 500,
        width: 600,
        title: "Export Global.xml",
        autoShow: true,
        renderTo: Ext.getBody(),
        layout: "border",
        items: [formPanel, treePanel],
        buttons: [
            {
                text: "Export Checked Point", handler: function () {
                var checkeds = treePanel.getChecked();
                var root = document.createElement("root");
                var device = document.createElement("device");
                device.setAttribute("address", "25")
                device.setAttribute("ip", IPCombo.value);
                device.setAttribute("name", "");
                device.setAttribute("port", PortCombo.value);
                device.setAttribute("timeout", "1000");
                root.appendChild(device)
                checkeds.sort(function (a, b) {
                    return a.data.text - b.data.text
                })
                for (var i = 0; i < checkeds.length; i++) {
                    if (checkeds[i].data.leaf) {
                        console.log(checkeds[i])
                        var point = document.createElement("point");
                        point.setAttribute("key", checkeds[i].data.text)
                        point.setAttribute("type", checkeds[i].data.text.substr(4, 1))
                        device.appendChild(point)
                    }
                }
                var content = '<?xml version="1.0" encoding="UTF-8" standalone="no"?>\r\n' + formatXml(root.outerHTML)
                saveXml("../../global.xml", function () {
                    Ext.Msg.alert("Massage", "Ok!")
                }, content)
            }
            }
        ]

    })

}
