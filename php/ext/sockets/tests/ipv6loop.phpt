--TEST--
IPv6 Loopback test
--SKIPIF--
<?php
	if (!extension_loaded('sockets')) {
		die('skip sockets extenion not available.');
	}
	if (!defined("AF_INET6")) {
		die('skip no IPv6 support');
	}
?>
--FILE--
<?php
	/* Setup socket server */
	$server = socket_create(AF_INET6, SOCK_STREAM, getprotobyname('tcp'));
	if (!$server) {
		die('Unable to create AF_INET6 socket [server]');
	}
	if (!socket_bind($server, '::1', 31337)) {
		die('Unable to bind to [::1]:31337');
	}
	if (!socket_listen($server, 2)) {
		die('Unable to listen on socket');
	}
	
	/* Connect to it */
	$client = socket_create(AF_INET6, SOCK_STREAM, getprotobyname('tcp'));
	if (!$client) {
		die('Unable to create AF_INET6 socket [client]');
	}
	if (!socket_connect($client, '::1', 31337)) {
		die('Unable to connect to server socket');
	}

	/* Accept that connection */
	$socket = socket_accept($server);
	if (!$socket) {
		die('Unable to accept connection');
	}

	socket_write($client, "ABCdef123\n");

	$data = socket_read($socket, 10, PHP_BINARY_READ);
	var_dump($data);

	socket_close($client);
	socket_close($socket);
	socket_close($server);
?>
--EXPECT--
string(10) "ABCdef123
"