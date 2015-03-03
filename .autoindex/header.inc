<?php

//
// Configurations
//

define('ROOT_NAME', 'Apache-auth-autoindex Demo');

define('AUTOINDEX_PATH', '/.autoindex/');

define('LOGOUT_USER_NAME', 'logout');
define('LOGOUT_PASSWORD', 'logout');
define('LOGOUT_PATH', AUTOINDEX_PATH . 'logout.php');

//
// Functions
//

function getPath() {
	return trim(dirname($_SERVER['REQUEST_URI'] . '/.'), '/\\');
}

function getRootUrl() {
	return '//' . $_SERVER['SERVER_NAME'] . ':' . $_SERVER['SERVER_PORT'] . '/';
}

// NOTE: way to to logout .htacess basic auth.
//		http://www.ssi-developer.net/htaccess/htaccess_logout.shtml
function getLogoutUrl() {
	return '//' . LOGOUT_USER_NAME . ':' . LOGOUT_PASSWORD . '@' .
			$_SERVER['SERVER_NAME'] . ':' . $_SERVER['SERVER_PORT'] . LOGOUT_PATH;
}

function getUserName() {
	return ($_SERVER['PHP_AUTH_USER'] != LOGOUT_USER_NAME ? $_SERVER['PHP_AUTH_USER'] : '');
}

function createTitle() {
	$dir = getPath();
	if ($dir != '') {
		return rawurldecode($dir) . ' - ' . ROOT_NAME;
	}
	return ROOT_NAME;
}

function createFilePath() {
	$dir = getPath();
	$result = $current = '';
	$result = '<ol class="breadcrumb">' .
			'<li><a href="/">' . ROOT_NAME . '</a></li>';
	$folders = explode('/', $dir);
	foreach($folders as $folder) {
		if($folder != "" && $folder[0] != "?") {
			$is_last = ($current.'/'.$folder == $dir);
			$result .= '<li' .
					($is_last ? ' class="active"' : '') . '>' .
					($is_last ? rawurldecode($folder) : '<a href="' . $current.'/'.$folder .'">' .
					rawurldecode($folder) . '</a>') .
					'</li>';
			$current .= '/' . $folder;
		}
	}
	$result .= '</ol>';
	return $result;
}
