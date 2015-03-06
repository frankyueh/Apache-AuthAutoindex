<?php

require_once 'config.inc';

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
	if ($dir != '') {
		$result = $current = '';
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
		return '<ol class="breadcrumb">' . $result . '</ol>';
	}
	return '';
}
