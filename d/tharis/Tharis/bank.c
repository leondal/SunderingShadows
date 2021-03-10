//bank.c

#include <std.h>
#include "../tharis.h"

inherit BANK;

void create(){ 
   ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
   set_property("light",2);
   set_property("indoors",1);

   set_short(
@JAVAMAKER
The Bank of Tharis
JAVAMAKER
   );

   set_long(
@JAVAMAKER
%^BOLD%^%^YELLOW%^       The Tharis bank, keepers of Safe coins.
A large wooden counter and a series of metal gratings offer a sense of 
imprisonment to the tellers.  You notice a sign with instructions next
to one of the tellers.  The money here is handled quickly and stored and
dealt with in a manner known only to those doing it.  You see the occasional
customer wander in and out.
JAVAMAKER
   );

   set_smell("default","The smell of money fills your nostrils.");
   set_listen("default","The sounds of rustling coins fill your ears.");
   set_items(([
      "sign":"Reading it will give you a list of commands.",
      "customer":"The occasional customer wonders in and out.",
   ]));

   set_exits(([
      "west":ROOMS"main8",
   ]));

   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));

   set_door("bank door",ROOMS"main8","west","blah");
}


