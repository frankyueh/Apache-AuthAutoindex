# Apache-AuthAutoindex

Using apache autoindex with basic authentication and bootstrap. It implement with PHP for supporting logout feature of basic authentication. (**Only work for Apache version 2.4+**)

Visit: [demo site](http://apache-auth-autoindex.dem0.hopto.me/ "apache-auth-autoindex Demo")
(user:admin/pw:admin or user:user/pw:user).

# Getting Started

###Quick startup

Copy the following into your root directory

 * **.autoindex** folder
 * **.htaccess** file
 * **.login.php** file

Make sure enable the flollowing Apche modules

* auth_basic_module
* authz_user_module
* authn_file_module
* autoindex_module

### Edit root ".htaccess" file

* Change **AuthName** by your favor
* Create ".htpasswd" file and setup **AuthUserFile**
```
#
# Basic authentication setup
#

AuthType Basic
AuthName "Apache-auth-autoindex Demo"
AuthUserFile "/path/to/.htpasswd"
Require valid-user
```

### Edit root "header.inc" file

* Change **ROOT_NAME** by your favor
* Modify **AUTOINDEX_PATH** to change path name of ".autoindex"
```
//
// Configurations
//

define('ROOT_NAME', 'Apache-auth-autoindex Demo');

define('AUTOINDEX_PATH', '/.autoindex/');

define('LOGOUT_USER_NAME', 'logout');
define('LOGOUT_PASSWORD', 'logout');
define('LOGOUT_PATH', AUTOINDEX_PATH . 'logout.php');

define('LOGIN_PATH', '/' . '.login.php');
```

### How to use redirect.inc

redirect.inc let you create a page or folder to redirect other URL.
First, you may create an empty folder and also create a "index.php" file inside the folder.

index.php may look like this:
```
<?php require_once 'path/to/.autoindex/redirect.inc';

redirect('Target site title', 'http://target.redirect.site/');
```

* set absolute path to **redirect.inc** file
* use redirect(*title*, *url*) to setup the redirect page
