--TEST--
Testing function murmurhash3
--SKIPIF--
<?php if (!extension_loaded("murmurhash")) print "skip"; ?>
--FILE--
<?php 

$seed = 0x12345678;
$input = "foo";

$output = murmurhash3_x86_32($input, $seed);
echo $output."\n";

$output = murmurhash3_x86_128($input, $seed);
echo bin2hex($output)."\n";

$output = murmurhash3_x64_128($input, $seed);
echo bin2hex($output)."\n";

?>
--EXPECT--
4084948345
8c985d72e5760d9be5760d9be5760d9b
dc67e2cad63ac5d06894e2702e8a8a13