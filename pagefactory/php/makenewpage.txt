<?php
/* javascript this pairs with:

document.getElementById("pageinput").onchange = function(){
    filename = this.value;
    var httpc = new XMLHttpRequest();
    var url = "makenewpage.php";        
    httpc.open("POST", url, true);
    httpc.setRequestHeader("Content-Type", "application/x-www-form-urlencoded;charset=utf-8");
    httpc.send("filename=" + filename);//send text to makenewpage.php
}

        
*/

    $filename = $_POST["filename"];//name of new directory

    mkdir($filename);
        mkdir($filename."/html");   

    copy("php/pageindextemplate.txt",$filename."/index.php");
    copy("php/pageeditor.txt",$filename."/pageeditor.php");
    copy("php/filesaver.txt",$filename."/filesaver.php");
    copy("php/fileloader.txt",$filename."/fileloader.php");


?>