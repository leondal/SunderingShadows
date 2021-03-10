#include <std.h>

/*
// file: _popd.c
// author: Truilkan@TMI
// last modified: 1992/03/08
*/

#include <std.h>

inherit DAEMON;

int
cmd_popd(string str) {
	object pobj;

	if (!(pobj = previous_object()))
		return 0;
	
	return (int)pobj->popd(str);
}

int
help() {
  write("Command: popd\nSyntax: popd\n"+
	"Changes the current directory to be the one last switched to\n" +
	"via pushd.\n");
  return 1;
}
