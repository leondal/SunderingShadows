#include <std.h>
#include <arena.h>

inherit ARENA;

void create(){
   ::create();
   set_short("Arena of honour and combat");
set_property("no teleport",1);
set_property("light",2);
   set_property("indoors",1);
   set_long(
@ORDER
   This is the arena of honour and glory. Let all
come and test their power and strength so that they
may better judge themselves and their weaknesses. All
who enter handle yourself well. Show not fear for fear
you must fear nothing. Let the games begin for later
this will be real.
ORDER
   );
   set_exits(([
      "north":"/d/guilds/order/hall/main",
      "south":"/d/guilds/order/hall/arena5",
      "east":"/d/guilds/order/hall/arena2",
      "west":"/d/guilds/order/hall/arena3"
      ]));
   set_property("arena",1);
   set_property("deathmove","/d/guilds/order/hall/arena14");
}

