<?php
require_once '.autoindex/header.inc';

function getRedirectUrl() {
	return filter_has_var(INPUT_GET, 'redirect') ? filter_input(INPUT_GET, 'redirect') : getRootUrl();
}

?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<link rel="SHORTCUT ICON" href="/favicon.ico" />
		<link href="//maxcdn.bootstrapcdn.com/bootstrap/3.3.2/css/bootstrap.min.css" rel="stylesheet">
		<title>Re-authenticating...</title>
		
		<meta http-equiv="refresh" content="0;URL='<?= getRedirectUrl() ?>'" />
		
	</head>
	<body>
		<div class="container">
			<div class="well">
				<a href="<?= getRedirectUrl() ?>">Redirecting...</a>
			</div>
		</div>
	</body>
</html>
