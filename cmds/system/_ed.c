/*
// The "ed" command.
// Written by Buddha (2-19-92)
// Part of the TMI mudlib.
*/

#include <std.h>

inherit DAEMON;

int cmd_ed(string file) {
   string tmp;
   int i;
   
    if(!file) {
        notify_fail("Syntax: <ed [filename]>\n");
	return 0;
    }
    if(this_player()->query_forced()) {
        write("Someone tried to force you to ed "+file);
        return 1;
    }
   seteuid(geteuid(this_player()));
   tmp = (string)this_player()->get_path();
   file = resolv_path(tmp, file);
    if(file_size(file) == -2) {
	notify_fail("You cannot edit a directory!\n");
	return 0;
    }
    if((i=file_size(file)) > -1)
      message("write", sprintf("%s , %d bytes:", file, i), this_player());
    if(!master()->valid_write(file,TP,"jump")) return 0;
    else ed(file);
    return 1;
}

int help()
{
  write( @EndText
Syntax: ed [filename]
Effect: edits the file named <filename>
See doc: /doc/immortals/ed
See man: ed
EndText
  );
  return 1;
}
