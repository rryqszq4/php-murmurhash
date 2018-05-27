php-murmurhash
==============
[![Build Status](https://travis-ci.org/rryqszq4/php-murmurhash.svg?branch=master)](https://travis-ci.org/rryqszq4/php-murmurhash)

MurmurHash function for PHP extension.

Requirement
-----------
- PHP 5.5.* ~ PHP 5.6.*
- PHP 7.0.* ~ PHP 7.2.*

Install
-------
```sh
$ /path/to/phpize
$ ./configure --with-php-config=/path/to/php-config
$ make && make install
```

PHP function
------------
* [murmurhash1](#murmurhash1)
* [murmurhash2](#murmurhash2)
* [murmurhash64a](#murmurhash64a)
* [murmurhash64b](#murmurhash64b)
* [murmurhash3_x86_32](#murmurhash3_x86_32)
* [murmurhash3_x86_128](#murmurhash3_x86_128)
* [murmurhash3_x64_128](#murmurhash3_x64_128)

murmurhash1
-----------
* **function** `int murmurhash1(string name, int seed)`

murmurhash2
-----------
* **function** `int murmurhash2(string name, int seed)`

murmurhash64a
-----------
* **function** `int murmurhash64a(string name, int seed)`

murmurhash64b
-----------
* **function** `int murmurhash64b(string name, int seed)`

murmurhash3_x86_32
-----------
* **function** `int murmurhash3_x86_32(string name, int seed)`

murmurhash3_x86_128
-----------
* **function** `byte murmurhash3_x86_128(string name, int seed)`

murmurhash3_x64_128
-----------
* **function** `byte murmurhash3_x64_128(string name, int seed)`

Test
----
```sh
=====================================================================
PHP         : /home/travis/.phpenv/versions/7.2.5/bin/php 
PHP_SAPI    : cli
PHP_VERSION : 7.2.5
ZEND_VERSION: 3.2.0
PHP_OS      : Linux - Linux travis-job-rryqszq4-php-murmurhash-384257378.travisci.net 4.14.12-041412-generic #201801051649 SMP Fri Jan 5 16:50:54 UTC 2018 x86_64
INI actual  : /home/travis/build/rryqszq4/php-murmurhash/tmp-php.ini
More .INIs  :   
---------------------------------------------------------------------
PHP         : /home/travis/.phpenv/versions/7.2.5/bin/phpdbg 
PHP_SAPI    : phpdbg
PHP_VERSION : 7.2.5
ZEND_VERSION: 3.2.0
PHP_OS      : Linux - Linux travis-job-rryqszq4-php-murmurhash-384257378.travisci.net 4.14.12-041412-generic #201801051649 SMP Fri Jan 5 16:50:54 UTC 2018 x86_64
INI actual  : /home/travis/build/rryqszq4/php-murmurhash/tmp-php.ini
More .INIs  : 
---------------------------------------------------------------------
CWD         : /home/travis/build/rryqszq4/php-murmurhash
Extra dirs  : 
VALGRIND    : Not used
=====================================================================
TIME START 2018-05-27 02:33:16
=====================================================================
PASS Check for murmurhash presence [tests/001.phpt] 
PASS Testing function murmurhash1 [tests/002-murmurhash1.phpt] 
PASS Testing function murmurhash2 [tests/003-murmurhash2.phpt] 
PASS Testing function murmurhash3 [tests/004-murmurhash3.phpt] 
=====================================================================
TIME END 2018-05-27 02:33:17
=====================================================================
TEST RESULT SUMMARY
---------------------------------------------------------------------
Exts skipped    :    0
Exts tested     :   59
---------------------------------------------------------------------
Number of tests :    4                 4
Tests skipped   :    0 (  0.0%) --------
Tests warned    :    0 (  0.0%) (  0.0%)
Tests failed    :    0 (  0.0%) (  0.0%)
Expected fail   :    0 (  0.0%) (  0.0%)
Tests passed    :    4 (100.0%) (100.0%)
---------------------------------------------------------------------
Time taken      :    1 seconds
=====================================================================
```

Copyright and License
---------------------
```
Copyright (c) 2017-2018, Quan Zhao
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
```


