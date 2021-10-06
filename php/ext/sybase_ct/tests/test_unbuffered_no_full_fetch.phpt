--TEST--
Sybase-CT unbuffered query without full fetching
--SKIPIF--
<?php require('skipif.inc'); ?>
--FILE--
<?php
/* This file is part of PHP test framework for ext/sybase_ct
 *
 * $Id: test_unbuffered_no_full_fetch.phpt,v 1.1.4.2 2008/11/08 14:28:26 thekid Exp $
 */

  require('test.inc');

  $db= sybase_connect_ex();
  var_dump($db);
  
  // Fetch #1
  $q= sybase_unbuffered_query('select name from master..systypes', $db);
  var_dump($q, key(sybase_fetch_assoc($q)));

  // Fetch #2 - without having fetched all rows from previous query
  $q= sybase_unbuffered_query('select name from master..systypes', $db);
  var_dump($q, key(sybase_fetch_assoc($q)));
  
  // Close - without having fetched all rows from previous query
  sybase_close($db);
  echo 'CLOSED';
?>
--EXPECTF--
resource(%d) of type (sybase-ct link)
resource(%d) of type (sybase-ct result)
string(4) "name"

Notice: sybase_unbuffered_query(): called without first fetching all rows from a previous unbuffered query in %s on line %d
resource(%d) of type (sybase-ct result)
string(4) "name"
CLOSED
