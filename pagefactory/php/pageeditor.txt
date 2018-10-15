 <!doctype html>
<html>
<head>
 <!-- 
PUBLIC DOMAIN, NO COPYRIGHTS, NO PATENTS.

EVERYTHING IS PHYSICAL
EVERYTHING IS FRACTAL
EVERYTHING IS RECURSIVE
NO MONEY
NO PROPERTY
NO MINING
EGO DEATH:
    LOOK TO THE INSECTS
    LOOK TO THE FUNGI
    LANGUAGE IS HOW THE MIND PARSES REALITY
-->
<!--Stop Google:-->
<META NAME="robots" CONTENT="noindex,nofollow">
<!-- links to MathJax JavaScript library, un-comment to use math-->
<!--

<script src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.0/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script>
	MathJax.Hub.Config({
		tex2jax: {
		inlineMath: [['$','$'], ['\\(','\\)']],
		processEscapes: true,
		processClass: "mathjax",
        ignoreClass: "no-mathjax"
		}
	});//			MathJax.Hub.Typeset();//tell Mathjax to update the math
</script>

-->
<script src="https://cdnjs.cloudflare.com/ajax/libs/ace/1.2.6/ace.js" type="text/javascript" charset="utf-8"></script>
<title>Page Editor</title>
</head>
<body  class="no-mathjax">
    
<a href = "index.php" id = "indexlink">
    <img style = "width:80px" src = "../factory_symbols/page.svg"/>    
</a>
<a href = "../" id = "uplink">
    <img src = "../factory_symbols/factory.svg" style = "width:80px"/>    
</a>

<div id="maineditor" contenteditable="true" spellcheck="false"></div>
<div id = "scroll" class = "mathjax">
</div>
<script>

editor = ace.edit("maineditor");
editor.setTheme("ace/theme/cobalt");
editor.getSession().setMode("ace/mode/html");
editor.getSession().setUseWrapMode(true);
editor.$blockScrolling = Infinity;

document.getElementById("maineditor").onkeyup = function(){
    document.getElementById("scroll").innerHTML = editor.getSession().getValue();
    data = encodeURIComponent(editor.getSession().getValue());
    var httpc = new XMLHttpRequest();
    var url = "filesaver.php";        
    httpc.open("POST", url, true);
    httpc.setRequestHeader("Content-Type", "application/x-www-form-urlencoded;charset=utf-8");
    httpc.send("data="+data+"&filename="+currentFile);//send text to filesaver.php

    //un-comment this for math:
    //MathJax.Hub.Typeset();//tell Mathjax to update the math
}


currentFile = "html/page.txt";
var httpc = new XMLHttpRequest();
httpc.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
        filedata = this.responseText;
        editor.setValue(filedata);
        document.getElementById("scroll").innerHTML = filedata;
    }
};
httpc.open("GET", "fileloader.php?filename=" + currentFile, true);
httpc.send();

</script>
<style>
body{
    background-color:#404040;
    font-family:Helvetica;
}
#maineditor{
    position:absolute;
    top:100px;
    bottom:50%;
    right:5px;
    left:5px;
    font-size:22px;
}
#scroll{
    position:absolute;
    bottom:5px;
    top:52%;
    right:5px;
    left:5px;
    background-color:white;
    overflow:scroll;
    padding:1em 1em 1em 1em;
    
}
#scroll h1,h2,h3,h4,h5{
    width:100%;
    text-align:center;
}
#indexlink{
    position:absolute;
    top:0px;
    left:0px;
    background-color:white;
}
#uplink{
    position:absolute;
    right:0px;
    top:0px;
    background-color:white;
}


</style>

</body>
</html>