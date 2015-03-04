<?php 
function redirect($title, $url) {
?>

	<!DOCTYPE html>
	<html>
		<head>
			<meta charset="UTF-8">
			<meta name="viewport" content="width=device-width, initial-scale=1.0">
			<link rel="SHORTCUT ICON" href="/favicon.ico" />
			<link href="//maxcdn.bootstrapcdn.com/bootstrap/3.3.2/css/bootstrap.min.css" rel="stylesheet">
			<title>Redirecting...</title>
		
			<meta http-equiv="refresh" content="0;URL='<?= $url ?>'" />
		
		</head>
		<body>
			<div class="container">
				<div class="well">
					<a href="<?= $url ?>"><?= $title ?> Redirecting...</a>
				</div>
			</div>
		</body>
	</html>
	
<?php
}
