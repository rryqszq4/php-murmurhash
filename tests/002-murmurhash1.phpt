--TEST--
Testing function murmurhash1
--SKIPIF--
<?php if (!extension_loaded("murmurhash")) print "skip"; ?>
--FILE--
<?php 

$input = "foo";
$seed = 0x12345678;

$output = murmurhash1($input, $seed);
echo $output;
echo "\n";

$output = murmurhash1_aligned($input, $seed);
echo $output;

?>
--EXPECT--
2077645772
2077645772