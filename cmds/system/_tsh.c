/*
// _tsh.c: This file is part of the TMI Mudlib distribution.
// Please include this header if you use this code.
// Originally written by Truilkan (1992/03/11)
*/

#include <std.h>

inherit DAEMON;

int
cmd_tsh(string str)
{
        object pobj;

    if(!(pobj = previous_object())) return 0;
    if((string)pobj->query_position() == "ambassador") return 0;
    if(pobj->query_forced()) {
        notify_fail("Someone tried to force you to: tsh "+str+"\n");
        return 0;
    }
        seteuid( geteuid( pobj ) );
        return (int)pobj->tsh(str);
}

int
help()
{
  write("Command: tsh\nSyntax: tsh script\n"+
        "Tsh calls the command() efun on each line in the script.  The\n"+
        "effect of typing 'tsh script' is as if you had manually\n" +
                "typed each command in the script.\n");
  return 1;
}

/* EOF */
