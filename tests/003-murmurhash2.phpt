--TEST--
Testing function murmurhash2
--SKIPIF--
<?php if (!extension_loaded("murmurhash")) print "skip"; ?>
--FILE--
<?php 

$seed = 0x12345678;
$input = "foo";

$output = murmurhash2($input, $seed);
echo $output."\n";

$output = murmurhash64a($input, $seed);
echo $output."\n";

$output = murmurhash64b($input, $seed);
echo $output."\n";

$output = murmurhash2a($input, $seed);
echo $output."\n";

$output = murmurhash_neutral2($input, $seed);
echo $output."\n";

$output = murmurhash_aligned2($input, $seed);
echo $output."\n";

?>
--EXPECT--
1532637697
-3870603097106057174
7448014171559636702
2221687037
1532637697
1532637697