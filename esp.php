<?php
require  'Medoo.php';
use Medoo\Medoo;
$database = new Medoo([
	// required
	'database_type' => 'mysql',
	'database_name' => 'id5203527_luz',
	'server' => 'localhost',
	'username' => 'id5203527_jtcp2703',
	'password' => 'jtcp2703123',
    ]);

$email = $database->get("estado", "estado", ["id" => 1]);
echo "ñ".$email;
?>
