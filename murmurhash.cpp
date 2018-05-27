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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

//#include <stdint.h>

extern "C" {
#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_murmurhash.h"
}

#include "MurmurHash1.h"
#include "MurmurHash2.h"
#include "MurmurHash3.h"

/* If you declare any globals in php_murmurhash.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(murmurhash)
*/

/* True global resources - no need for thread safety here */
static int le_murmurhash;

ZEND_BEGIN_ARG_INFO_EX(arginfo_murmurhash1, 0, 0, 2)
    ZEND_ARG_INFO(0, key)
    ZEND_ARG_INFO(0, seed)
ZEND_END_ARG_INFO()
ZEND_BEGIN_ARG_INFO_EX(arginfo_murmurhash2, 0, 0, 2)
    ZEND_ARG_INFO(0, key)
    ZEND_ARG_INFO(0, seed)
ZEND_END_ARG_INFO()
ZEND_BEGIN_ARG_INFO_EX(arginfo_murmurhash64a, 0, 0, 2)
    ZEND_ARG_INFO(0, key)
    ZEND_ARG_INFO(0, seed)
ZEND_END_ARG_INFO()
ZEND_BEGIN_ARG_INFO_EX(arginfo_murmurhash64b, 0, 0, 2)
    ZEND_ARG_INFO(0, key)
    ZEND_ARG_INFO(0, seed)
ZEND_END_ARG_INFO()
ZEND_BEGIN_ARG_INFO_EX(arginfo_murmurhash3_x86_32, 0, 0, 2)
    ZEND_ARG_INFO(0, key)
    ZEND_ARG_INFO(0, seed)
ZEND_END_ARG_INFO()
ZEND_BEGIN_ARG_INFO_EX(arginfo_murmurhash3_x86_128, 0, 0, 2)
    ZEND_ARG_INFO(0, key)
    ZEND_ARG_INFO(0, seed)
ZEND_END_ARG_INFO()
ZEND_BEGIN_ARG_INFO_EX(arginfo_murmurhash3_x64_128, 0, 0, 2)
    ZEND_ARG_INFO(0, key)
    ZEND_ARG_INFO(0, seed)
ZEND_END_ARG_INFO()

/* {{{ murmurhash_functions[]
 *
 * Every user visible function must have an entry in murmurhash_functions[].
 */
const zend_function_entry murmurhash_functions[] = {
    //PHP_FE(confirm_murmurhash_compiled,	NULL)		/* For testing, remove later. */
    PHP_FE(murmurhash1, arginfo_murmurhash1)
    PHP_FE(murmurhash2, arginfo_murmurhash2)
    PHP_FE(murmurhash64a, arginfo_murmurhash64a)
    PHP_FE(murmurhash64b, arginfo_murmurhash64b)
    PHP_FE(murmurhash3_x86_32, arginfo_murmurhash3_x86_32)
    PHP_FE(murmurhash3_x86_128, arginfo_murmurhash3_x86_128)
    PHP_FE(murmurhash3_x64_128, arginfo_murmurhash3_x64_128)
    PHP_FE_END	/* Must be the last line in murmurhash_functions[] */
};
/* }}} */

/* {{{ murmurhash_module_entry
 */
zend_module_entry murmurhash_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"murmurhash",
	murmurhash_functions,
	PHP_MINIT(murmurhash),
	PHP_MSHUTDOWN(murmurhash),
	PHP_RINIT(murmurhash),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(murmurhash),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(murmurhash),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_MURMURHASH_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_MURMURHASH
ZEND_GET_MODULE(murmurhash)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("murmurhash.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_murmurhash_globals, murmurhash_globals)
    STD_PHP_INI_ENTRY("murmurhash.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_murmurhash_globals, murmurhash_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_murmurhash_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_murmurhash_init_globals(zend_murmurhash_globals *murmurhash_globals)
{
	murmurhash_globals->global_value = 0;
	murmurhash_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(murmurhash)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(murmurhash)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(murmurhash)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(murmurhash)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(murmurhash)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "murmurhash support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_murmurhash_compiled(string arg)
   Return a string to confirm that the module is compiled in */
/*PHP_FUNCTION(confirm_murmurhash_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}
    php_printf("%s, %d\n", arg, arg_len);
	len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "murmurhash", arg);
	RETURN_STRINGL(strg, len, 0);
}*/
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/

PHP_FUNCTION(murmurhash1)
{
    char *key = NULL;
    size_t key_len = 0;
    long seed = 0;
    uint32_t output;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|l", &key, &key_len, &seed) == FAILURE) {
        RETURN_NULL();
    }

    output = MurmurHash1(key, key_len, seed);
    //printf("%s, %d, %d, %lu\n", key, key_len, seed, (uint32_t)output);

    RETURN_LONG(output); 
}

PHP_FUNCTION(murmurhash2)
{
    char *key = NULL;
    size_t key_len = 0;
    long seed = 0;
    uint32_t output;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|l", &key, &key_len, &seed) == FAILURE) {
        RETURN_NULL();
    }

    output = MurmurHash2(key, key_len, seed);
    //printf("%s, %d, %d, %lu\n", key, key_len, seed, (uint32_t)output);

    RETURN_LONG(output); 
}

PHP_FUNCTION(murmurhash64a)
{
    char *key = NULL;
    size_t key_len = 0;
    long seed = 0;
    uint64_t output;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|l", &key, &key_len, &seed) == FAILURE) {
        RETURN_NULL();
    }

    output = MurmurHash64A(key, key_len, seed);
    //printf("%s, %d, %d, %llu\n", key, key_len, seed, (uint64_t)output);

    RETURN_LONG(output); 
}

PHP_FUNCTION(murmurhash64b)
{
    char *key = NULL;
    size_t key_len = 0;
    long seed = 0;
    uint64_t output;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|l", &key, &key_len, &seed) == FAILURE) {
        RETURN_NULL();
    }

    output = MurmurHash64B(key, key_len, seed);
    //printf("%s, %d, %d, %llu\n", key, key_len, seed, (uint64_t)output);

    RETURN_LONG(output); 
}

PHP_FUNCTION(murmurhash3_x86_32)
{
    char *key = NULL;
    size_t key_len = 0;
    long seed = 0;
    uint32_t output;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|l", &key, &key_len, &seed) == FAILURE) {
        RETURN_NULL();
    }

    MurmurHash3_x86_32(key, key_len, seed, &output);
    //printf("%s, %d, %d, %lu\n", key, key_len, seed, output);

    RETURN_LONG(output);
}

PHP_FUNCTION(murmurhash3_x86_128)
{
    char *key = NULL;
    size_t key_len = 0;
    long seed = 0;
    char output[16];

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|l", &key, &key_len, &seed) == FAILURE) {
        RETURN_NULL();
    }

    MurmurHash3_x86_128(key, key_len, seed, &output);

#if PHP_MAJOR_VERSION > 7 || PHP_MAJOR_VERSION == 7
    RETURN_STRINGL(output, 16);
#else
    RETURN_STRINGL(output, 16, 1);
#endif
}

PHP_FUNCTION(murmurhash3_x64_128)
{
    char *key = NULL;
    size_t key_len = 0;
    long seed = 0;
    char output[16];

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|l", &key, &key_len, &seed) == FAILURE) {
        RETURN_NULL();
    }

    MurmurHash3_x64_128(key, key_len, seed, &output);

#if PHP_MAJOR_VERSION > 7 || PHP_MAJOR_VERSION == 7
    RETURN_STRINGL(output, 16);
#else
    RETURN_STRINGL(output, 16, 1);
#endif
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
