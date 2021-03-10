//      /bin/dev/_invis.c
//      from the Nightmare mudlib
//      created by Descartes of Borg october 1992

#include <std.h>

inherit DAEMON;

int cmd_invis(string str)
{
   if((int)TP->query_true_invis()) {
	notify_fail("You are already REALLY invisible.\n");
	return 0;
    }
   if (TP->query_magic_hidden())
     write("You're already invisible. Improving that.");
   if (TP->query_hidden())
     write("You're hidden in the shadows. Improving that.");
   this_player()->set_true_invis();
   write("Done.");
   return 1;
}

void help()
{
    write("Syntax: <invis>\n\nMakes you invisible to players of lower levels in all circumstances.\n");
}
