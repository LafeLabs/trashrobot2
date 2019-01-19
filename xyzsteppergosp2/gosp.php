<!doctype html>
<html>
<head>
<title>TRASH ROBOT: XYZ Stepper GOSP 2</title>
<!-- 

GOSP = GEOMETRON OPTICAL SERIAL PROTOCOL

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

<script id = "topfunctions">
<?php
echo file_get_contents("javascript/topfunctions.txt");
?>   
</script>
</head>
<body>
<div id = "datadiv" style = "display:none"><?php

echo file_get_contents("json/currentjson.txt");

?></div>    
<div id = "page">
    <table id = "toptable">
        <tr>
            <td>
                <a href = "editor.php">
                   <img src = "icons/editor.svg"/>
                </a>
            </td>
            <td>
                <div class = "button" id = "gobutton"></div>
            </td>
        </tr>
    </table>
    <textarea id = "textinput"></textarea>
    <div id = "programbox">
        <div id = "enablebox" class= "subbox"></div>
        <div id = "bytebox" class= "subbox"></div>
        <div id = "bitbox" class= "subbox"></div>
        <div id = "databox" class= "subbox"></div>
    </div>
</div>


<script>

document.getElementById("textinput").value = document.getElementById("datadiv").innerHTML;

currentjson = JSON.parse(document.getElementById("datadiv").innerHTML);

numbytes = currentjson2string(currentjson).length;
datastring = currentjson2string(currentjson);
bitstring = string2bits(datastring);

document.getElementById("gobutton").onclick = function(){

    numbytes = document.getElementById("textinput").value.length;
    bitstring = string2bits(document.getElementById("textinput").value);

    id = setInterval(frame, 500);
    bitindex = 0;
    byteindex = 0;
    frameindex = 0;
    function frame() {
        if(frameindex == numbytes*14) {
            document.getElementById("enablebox").style.backgroundColor = "white";            
            document.getElementById("bytebox").style.backgroundColor = "white";
            document.getElementById("bitbox").style.backgroundColor = "white";
            document.getElementById("databox").style.backgroundColor = "white";
            clearInterval(id);
        }
        else{
            document.getElementById("enablebox").style.backgroundColor = "black";
            if(frameindex%14==0){
                document.getElementById("bytebox").style.backgroundColor = "white";
            }
            else{
                document.getElementById("bytebox").style.backgroundColor = "black";
            }
            if(frameindex%2==1){
                document.getElementById("bitbox").style.backgroundColor = "black";
                if(bitstring.charAt(bitindex) == 1){
                    document.getElementById("databox").style.backgroundColor = "black";
                }
                else{
                    document.getElementById("databox").style.backgroundColor = "white";
                }
                
                bitindex++;
            }
            else{
                document.getElementById("bitbox").style.backgroundColor = "white";
                document.getElementById("databox").style.backgroundColor = "white";
            }
            frameindex++;
        }
    }
}

  

</script>
<style>
    #toptable{
        position:absolute;
        top:0px;
        left:0px;
    }
    #toptable img{
        width:60px;
    }
    .button{
        cursor:pointer;
        width:30px;
        height:30px;
        border-radius:15px;
        border:solid;
        border-width:1px;
        background-color:green;
    }
    .button:hover{
        border:solid;
        border-width:3px;
    }
    .button:active{
        border-color:yellow;
        border:solid;
        border-width:5px;
    }
    #page{
        position:absolute;
        left:0px;
        right:0px;
        top:0px;
        bottom:0px;
    }
    #gobutton{
        background-color:green;
    }
    #stopbutton{
        background-color:red;
    }
    #programbox{
        position:absolute;
        left:10px;
        bottom:10px;
        border:solid;
        height:540px;
        width:300px;
        overflow:hidden;
    }
    .subbox{
        position:absolute;
        width:100%;
        height:25%;
        left:0px;
    }
    #enablebox{
        top:0px;
    }
    #bytebox{
        top:25%;
    }
    #bitbox{
        top:50%;
    }
    #databox{
        top:75%;
    }
    #textinput{
        position:absolute;
        right:0px;
        top:2em;
        width:200px;
        height:200px;
    }
</style>
</body>
</html>