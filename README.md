# Apache-AuthAutoindex

Using apache autoindex with basic authentication and bootstrap. It implement with PHP for supporting logout feature of basic authentication. 

Visit: [demo site](http://apache-auth-autoindex.dem0.hopto.me/ "apache-auth-autoindex Demo")
(user:admin/pw:admin or user:user/pw:user).

# Getting Started

Quick setup by just copy ".autoindex" folder and root ".htaccess" file into your root directory.

#### Edit root ".htaccess" file

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

#### Edit root "header.inc" file

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
```

