/*
// This file is part of the TMI mudlib distribution.
// Please include this header if you use this code.
// Written by Sulam(12-16-91)
*/

#include <std.h>
inherit DAEMON;

int
cmd_tail(string file) {
    seteuid(getuid(previous_object()));
    if (!file) {
      notify_fail("usage: tail <file>\n");
      return 0;
    }
    file = resolv_path(this_player()->get_path(), file);
    switch(file_size(file)) {
	case -2:
	    notify_fail("tail: "+file+": directory\n");
	    return 0;
	case -1:
	    notify_fail("tail: "+file+": no such file\n");
	    return 0;
    }
    tail(file);
    return 1;
}

int help()
{
  write( @EndText
Syntax: tail <file>
Effect: lists the last few lines of the file <file>
See man: tail
See also: head, cat, more, less
EndText
  );
  return 1;
}

/* EOF */
