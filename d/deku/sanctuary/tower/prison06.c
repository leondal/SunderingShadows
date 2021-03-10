#include <std.h>
#include "../dragon.h";

inherit BPRISON;

void create () {
   ::create();
   set_long(
      "%^BOLD%^%^BLACK%^This is the small walkway that leads to the cells prisoners"+
      " were once held in. The bars look solid, sturdy, and capable of still holding prisoners."+
      " The cells look small and very typical of most prisons from here."
   );
   set_items( ([
      "cells" : "These are the cells prisoners were once held in. From the smell you think some may still be here.",
   ]) );
   set_exits( ([
      "east" : TOWER+"prison10",
      "west" : TOWER+"prison09",
      "stairs" : TOWER+"prison03"
   ]) );
}
