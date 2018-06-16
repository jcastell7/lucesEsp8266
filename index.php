<?php
require  'Medoo.php';

$valor=$_GET["id"];
$estado;
if($valor==="prendido"){
    $estado=1;
}else{
    $estado=0;
}
use Medoo\Medoo;

$database = new Medoo([
	// required
	'database_type' => 'mysql',
	'database_name' => 'id5203527_luz',
	'server' => 'localhost',
	'username' => 'id5203527_jtcp2703',
	'password' => 'jtcp2703123',
    ]);

$database->query("UPDATE `estado` SET `estado` = $estado WHERE `estado`.`id` = 1");
?>
