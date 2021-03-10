//   written by Plura@Nightmare in January 93
//
//   Modified by Zandar 21-Sept-94

// -------------------------------------------------------
// Support modules

#include <std.h>

inherit DAEMON;

// -------------------------------------------------------
// Internal variables etc.

#define DEFAULT_LINES 25

// -------------------------------------------------------
// Support functions

int help();

// -------------------------------------------------------
// Actual command

int cmd_head( string file ) {

  int lines;

  sscanf(file, "%s %d",file, lines);
  seteuid(getuid(previous_object()));
  if(!file) {
    notify_fail("usage: head <file>\n");
    return 0;
  }
  else {
    file = resolv_path(this_player()->get_path(), file);
    switch(file_size(file)) {
    case -2:
      notify_fail("head: "+file+": directory\n");
      return 0;
    case -1:
      notify_fail("head: "+file+": no such file\n");
      return 0;
    }
    if (lines < 1)
      lines = DEFAULT_LINES;
    write(read_file(file,1,lines));
    return 1;
  }
}


int help()
{
  write( @EndText
Syntax: head <file [lines]>
Effect: lists the first lines of the file <file>
        You may override the default 25 lines by
	providing an optional argument.
See also: tail, cat, more, less
EndText
  );
  return 1;
}
