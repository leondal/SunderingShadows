#include <std.h>

inherit ROOM;

void create()
{
   ::create();
   set_properties((["light":2,"indoors":1,"no teleport":1]));
   set_short("High Level Token Equipment Storage");
   set_long("You shouldn't be here.  Report to a wiz if you are.");
}

void reset() { return 1; }

int clean_up() { return 1; }

