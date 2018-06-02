/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2015 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: quanzhao <rryqszq@gmail.com>                                 |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_MURMURHASH_H
#define PHP_MURMURHASH_H

extern zend_module_entry murmurhash_module_entry;
#define phpext_murmurhash_ptr &murmurhash_module_entry

#define PHP_MURMURHASH_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_MURMURHASH_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_MURMURHASH_API __attribute__ ((visibility("default")))
#else
#	define PHP_MURMURHASH_API
#endif

extern "C" {
#ifdef ZTS
#include "TSRM.h"
#endif
}

PHP_MINIT_FUNCTION(murmurhash);
PHP_MSHUTDOWN_FUNCTION(murmurhash);
PHP_RINIT_FUNCTION(murmurhash);
PHP_RSHUTDOWN_FUNCTION(murmurhash);
PHP_MINFO_FUNCTION(murmurhash);

PHP_FUNCTION(confirm_murmurhash_compiled);	/* For testing, remove later. */

PHP_FUNCTION(murmurhash1);
PHP_FUNCTION(murmurhash1_aligned);
PHP_FUNCTION(murmurhash2);
PHP_FUNCTION(murmurhash64a);
PHP_FUNCTION(murmurhash64b);
PHP_FUNCTION(murmurhash2a);
PHP_FUNCTION(murmurhash_neutral2);
PHP_FUNCTION(murmurhash_aligned2);
PHP_FUNCTION(murmurhash3_x86_32);
PHP_FUNCTION(murmurhash3_x86_128);
PHP_FUNCTION(murmurhash3_x64_128);

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(murmurhash)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(murmurhash)
*/

/* In every utility function you add that needs to use variables 
   in php_murmurhash_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as MURMURHASH_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define MURMURHASH_G(v) TSRMG(murmurhash_globals_id, zend_murmurhash_globals *, v)
#else
#define MURMURHASH_G(v) (murmurhash_globals.v)
#endif

#endif	/* PHP_MURMURHASH_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
