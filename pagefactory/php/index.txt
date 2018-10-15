<!doctype html>
<html>
<head>
<title>Page</title>
<!-- 
PUBLIC DOMAIN, NO COPYRIGHTS, NO PATENTS.

EVERYTHING IS PHYSICAL
EVERYTHING IS FRACTAL
EVERYTHING IS RECURSIVE

NO MONEY
NO PROPERTY
NO MINING

LOOK AT THE INSECTS
LOOK AT THE FUNGI
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

</head>
<body>

<a id = "editlink" href = "editor.php">
    <img src = "factory_symbols/editor.svg" style = "width:80px"/>
</a>
<a id = "copylink" href = "copy.php">
    <img src = "factory_symbols/copy.svg" style = "height:80px"/>
</a>
<h1>Page Factory</h1>
        <p>Enter name of new page:
        <input id = "pageinput"/></p>
        
<ul id = "filelist">
<?php

$files = scandir(getcwd());
foreach($files as $value){
    if($value != "." && $value != ".." && is_dir($value) && $value != "json" &&  $value != "php" && $value != ".git" && $value != "factory_symbols"){
        echo "<li><a href = \"".$value."/\">".$value."/</a></li>\n";
    }
}


?>
</ul>
<script>
document.getElementById("pageinput").onchange = function(){
    filename = this.value;
    var httpc = new XMLHttpRequest();
    var url = "makenewpage.php";        
    httpc.open("POST", url, true);
    httpc.setRequestHeader("Content-Type", "application/x-www-form-urlencoded;charset=utf-8");
    httpc.send("filename=" + filename);//send text to makenewpage.php
    
    var newa = document.createElement("A");
    newa.innerHTML = filename + "/";
    newa.href = filename + "/";
    var newli = document.createElement("LI");
    newli.appendChild(newa);
    document.getElementById("filelist").appendChild(newli);
}

</script>
<style>
body{
    font-family:Helvetica;
    font-size:1.5em;
}
h1,h2,h3,h4,h5{
    width:100%;
    text-align:center;
}
#editlink{
    position:absolute;
    top:0px;
    left:0px;
}
#copylink{
    position:absolute;
    right:0px;
    top:0px;
}
input{
    width:10em;
}
</style>

</body>
</html>