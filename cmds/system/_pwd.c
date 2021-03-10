/*
// This file is part of the TMI Mudlib distribution.
// You can use this code, I couldn't care less.
// Written by Sulam(12-21-91)
// Just for tradition this files help was added by me too (Brian)
// and the date was...You guessed it! (1/28/92)
*/

#include <std.h>

inherit DAEMON;

int
cmd_pwd()
{
   message("system", (string)this_player()->get_path() + ":", this_player());
	return 1;
}

int
help() {
  message("system", "Command: pwd\nSyntax: pwd\n"
	  "This command returns the directory that you are currently "
	  "working in.", this_player());
  return 1;
}
