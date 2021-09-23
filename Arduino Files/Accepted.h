const char Accepted[] =
R"=====(
<!DOCTYPE html>
<html>
<html>
<!------------------------------C S S--------------------------------->
<head>
    <style>
         #btn 
         { background-color: #000000; 
            border: none; 
            border-radius: 120px;
            color: #ffffff; 
            padding: 16px 40px; 
            text-decoration: none;
            font-size: 30px;
            margin: 2px;
            cursor: pointer;}
            body {font-family: "Calibri"; background-color: grey}
            h1{color: whitesmoke; text-align:center; font-size: 50px;}
            h2{color: whitesmoke; text-align:center; font-size: 50px;}
    </style>
 
</head>
<!----------------------------H T M L--------------------------------->
<body>
    <h1>
        <br> Transaction on progress <br><br>
        
        <a href="/#1" id="btn" ONCLICK='JS1()'>Next</a> <br><br>
        
        
    </h1>

    
<!---------------------------JavaScript------------------------------->
<script>
    //function displays text message
    
    
   function JS1()
    {
      alert('Payment Accepted !');
      
    }
</script>
</body>
</html>
)=====";
