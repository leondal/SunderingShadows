/*
// This file is part of the TMI Mudlib distribution.
// Please include this header if you use this code.
// Written by Sulam(1-8-92)
// Help added by Brian (1/28/92)
*/

#include <std.h>
inherit DAEMON;

void do_clean_up() {
    return;
}
int help();

int cmd_cleanup(string str) {
	seteuid(geteuid(previous_object()));
	if( !str )
	{
                return help();
	}
	str = resolv_path(this_player()->get_path(), str);
	if( file_size("inactive_clean") != -1 )
	{
                write( "Inactive Clean directory already exists.");
	}
	if( (int)master()->valid_write(str, previous_object(), "rmdir") == 0 )
	{
		notify_fail(str+": Permission denied.\n");
		return 0;
	}
	write(mkdir("inactive_clean") ? "Ok.\n" : str+": couldn't make directory.\n");
        if( file_size("inactive_clean") != -1 ) 
	return 1;
        else {
          do_clean_up();
          return 1;
        }
}

int
help() {
  write("Command: mkdir\nSyntax: mkdidr <directory>\n");
  write("This command makes a new directory with the name specified.\n"+
        "If no path information is supplied, th new directory will be\n"+
        "a sub directory of the present working directory.  For more\n"+
        "on specifying paths see help cd.\n");
  return 1;
}
/* EOF */
