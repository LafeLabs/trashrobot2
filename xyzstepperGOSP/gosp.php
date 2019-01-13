<!doctype html>
<html>
<head>
<title>TRASH ROBOT: XYZ Stepper GOSP</title>
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
<script id = "bytecodeScript">/*
<?php
echo file_get_contents("bytecode/baseshapes.txt")."\n";
echo file_get_contents("bytecode/shapetable.txt")."\n";
echo file_get_contents("bytecode/font.txt")."\n";
echo file_get_contents("bytecode/keyboard.txt")."\n";
echo file_get_contents("bytecode/symbols013xx.txt")."\n";
echo file_get_contents("bytecode/symbols010xx.txt")."\n";

?>
*/</script>
<script id = "topfunctions">
<?php
echo file_get_contents("javascript/topfunctions.txt");
?>   
</script>
<script id = "actions">
function doTheThing(localCommand){    
    if(localCommand >= 040 && localCommand <= 0176){
        currentHTML += String.fromCharCode(localCommand);
        currentWord += String.fromCharCode(localCommand);
    }
    if(localCommand >= 0200 && localCommand <= 0277){//shapes 
        if(!(localCommand == 0207 && editMode == false) ){
            drawGlyph(currentTable[localCommand]);    	    
        }
    }
    if(localCommand >= 01000 && localCommand <= 01777){//symbol glyphs
            drawGlyph(currentTable[localCommand]);    	    
    } 
    <?php
    echo file_get_contents("javascript/actions03xx.txt");
    echo "\n";
    echo file_get_contents("javascript/actions0xx.txt");
    echo "\n";
    ?>    
}
</script>

</head>
<body>
<div id = "datadiv" style = "display:none"><?php

echo file_get_contents("json/currentjson.txt");

?></div>    
<div id = "stylejsondiv" style = "display:none"><?php
    echo file_get_contents("json/stylejson.txt");
?></div>
<div id = "page">
    <table id = "toptable">
        <tr>
            <td>
                <a href = "editor.php">
                   <img src = "icons/editor.svg"/>
                </a>
            </td>
            <td class = "button" id = "stopbutton">
            </td>
            <td class = "button" id = "gobutton">
            </td>
        </tr>
    </table>
    <div id = "programbox">
        <div id = "programsubdiv">
            <canvas id = "programcanvas"></canvas>            
        </div>
    </div>
    
    <div id = "pickupbox"></div>
</div>


<script>


doTheThing(06);//import embedded hypercube in this .html doc
doTheThing(07);//initialize Geometron global variables
styleJSON = JSON.parse(document.getElementById("stylejsondiv").innerHTML);
glyphArray = JSON.parse(document.getElementById("datadiv").innerHTML);
document.getElementById("programcanvas").classList.add("runclass");

numbytes = 10;
numbits = numbytes*9;
document.getElementById("programcanvas").height = 500;
document.getElementById("programcanvas").width = (numbits + 4)*unit;
document.getElementById("programsubdiv").style.width = (numbits*unit).toString() + "px";
    
ctx = document.getElementById("programcanvas").getContext("2d");
ctx.clearRect(0,0,document.getElementById("programcanvas").width,document.getElementById("programcanvas").height);
    
unit = 125;
x0 = 0;
y0 = 500;
doTheThing(0300);

bytecode = getbytecode();
drawGlyph("0337,0337,0337,0333,0336,0336,0336,");
drawGlyph(bytecode);

function getbytecode(){
<?php
echo file_get_contents("javascript/getbytecode.txt");
?>
}

//page events

document.getElementById("gobutton").onclick = function(){
    document.getElementById("programsubdiv").removeChild(document.getElementById("programcanvas"));
    var newcan = document.createElement("CANVAS");
    newcan.id = "programcanvas";
    document.getElementById("programsubdiv").appendChild(newcan);
    newcan.style.left = "0px";
    newcan.style.top = "0px";
    newcan.style.position = "absolute";
    numbytes = 10;
    numbits = numbytes*9;
    document.getElementById("programcanvas").height = 500;
    document.getElementById("programcanvas").width = numbits*unit;
    document.getElementById("programsubdiv").style.width = (numbits*unit).toString() + "px";
    
    ctx = document.getElementById("programcanvas").getContext("2d");
    ctx.clearRect(0,0,document.getElementById("programcanvas").width,document.getElementById("programcanvas").height);
    
    unit = 125;
    x0 = 0;
    y0 = 500;
    doTheThing(0300);

    bytecode = getbytecode();
    drawGlyph("0337,0337,0337,0333,0336,0336,0336,");
    drawGlyph(bytecode);

    newcan.className = "runclass";
   
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
        width:60px;
        height:60px;
        border-radius:30px;
        border:solid;
        border-width:1px;
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
    #programbox{
        position:absolute;
        right:10px;
        left:10px;
        bottom:10px;
        border:solid;
        height:540px;
        overflow:scroll;
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
    .runclass{
        animation-name: go;
        animation-duration: 60s;
        animation-timing-function: linear;
    }
    @keyframes go {
        from {left: 0px;}
        to {left: -100%;}
    }
#programsubdiv{
    position:absolute;
    top:0px;
    overflow:scroll;
    bottom:0px;
}

</style>
</body>
</html>