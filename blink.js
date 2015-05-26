#!/usr/bin/env node
var fs = require('fs');

var fds = fs.openSync("/sys/class/gpio/gpio48/value", 'r+');
var index = 0;
var int = setInterval(
	function() {
		fs.writeSync(fds, index);

		if (index==0) { index = 1 }
                else { index = 0};

	},
	1
	);
process.on('SIGTERM', function () {
	console.error('got SIGTERM, shutting down...');
 	clearInterval(int);
	closeLeds();
});
process.on('SIGINT', function () {
	console.error('got SIGINT, shutting down...');
 	clearInterval(int);
	closeLeds();
});

function closeLeds() {
		fs.closeSync(fds);

};

