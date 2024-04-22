<?php

$server = "localhost";
$dbname = "bd_personel";
$user = "root";
$pass = "";

$bd = new PDO("mysql:host=$server;dbname=$dbname",$user,$pass);

@$search = $_GET['search'];
if (isset($search) and !empty($search)) {
    @$recherche = $bd->query("SELECT * FROM personnel WHERE concat(id, nom, prenom, sexe, date, poste) LIKE('%$search%') ORDER BY id DESC");
}
else {
    @$recherche = $bd->query("SELECT * FROM personnel ORDER BY id DESC");
}


?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="index.php.css">
</head>
<body>
    <div class="s">Rechercher un membre du personnel</div>
    <table class="form">
        <form method="get">
            <tr>
                <td><input type="text" name="search"></td>
                <td><input type="submit" value="rechercher"></td>
            </tr>
        </form>
    </table>
    
    <table border="1">
        <tr>
            <td>identifiant de l'autentification</td>
            <td>Nom du personnel</td>
            <td>pernom du personnel</td>
            <td>age</td>
            <td>date du mouvement</td>
            <td>poste</td>
        </tr>
        <?php
        while ($r = $recherche->fetch()) {
            echo "
            <tr>
                <td>".$r["id"]."</td>
                <td>".$r["nom"]."</td>
                <td>".$r["prenom"]."</td>
                <td>".$r["sexe"]."</td>
                <td>".$r["date"]."</td>
                <td>".$r["poste"]."</td>
            </tr>   
            
            ";
        }
        
        ?>
    </table>
</body>
</html>