php-murmurhash
==============
MurmurHash function for PHP.

test
----
```php
<?php

$output = murmurhash2("foo", 0x1234ABCD);
echo $output."\n";
var_dump($output);

$output = murmurhash64a("foo", 0x1234ABCD);
echo $output."\n";
var_dump($output);

$output = murmurhash64b("foo", 0x1234ABCD);
echo $output."\n";
var_dump($output);

$output = murmurhash64a("foo",0x12345678);
echo $output;
echo "\n";
echo abs($output)%4;
echo "\n";
var_dump($output);

/*
output

3046381672
int(3046381672)
-7063922479176959649
int(-7063922479176959649)
6817832694710408790
int(6817832694710408790)
-7063922479176959649
1
int(-7063922479176959649)

*/

?>
```