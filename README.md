php-murmurhash
==============

test
----
```php

$output = murmurhashint64a("foo",0x1234ABCD);

echo $output;
echo "\n";
echo abs($output)%4;
echo "\n";
var_dump($output);

```