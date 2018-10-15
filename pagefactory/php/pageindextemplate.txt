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
    <a id = "uplink" href = "../">
        <img src = "../factory_symbols/factory.svg" style = "width:80px"/>
    </a>
    <a id = "editlink" href = "pageeditor.php">
        <img src = "../factory_symbols/editor.svg" style = "width:80px"/>
    </a>
<div id = "scroll">
<?php
echo file_get_contents("html/page.txt");
?>
    
</div>

<style>
#scroll{
    position:absolute;
    top:4em;
    left:0px;
    right:0px;
    bottom:0px;
    overflow:scroll;
    text-align:justify;
    padding-left:5em;
    padding-right:5em;
}
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
#uplink{
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