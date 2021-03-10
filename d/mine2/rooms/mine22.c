#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";
inherit "/std/pier.c";

inherit ROOM;

void create() {
           ::create();
    set_property("light",3);
    set_property("indoors",1);
    set_short("mine shaft");
    set_long(""
"%^BOLD%^WHITE%^ "
"This mine shaft is very bright and large.  There are several things unique " 
"about this room.  One thing is the buitiful stream the runs through the room, "
"and the waterfall it makes as it leaves into a small hole.  There are several "
"large rocks, that make perfect places to sit use as you rest.  There is a small "
"frog that is sitting on the other side of the stream, staring at you.");

     set_listen("default","You hear the stream.");
     set_smell("default","You smell life.");
    set_exits(([
       "north" : "/d/mine2/rooms/mine23",
       "west" : "/d/mine2/rooms/mine19",
    ] ));
    set_items(([
         "stream" : "It runs through the shaft, and makes a waterfall before it exits through a small hole.\nThe stream would probably work well for fishing!",
         "waterfall" : "It is only about 3 feet high, but it is very buitifull.",
         "life" : "This room reminds you of how important life is, no matter who's life it is.",
         "rocks" : "The rocks are sitting by the stream, and looks like a perfect spot to fish at.",
         "shaft" : "It is accually a small cavern, that is very stuffy and cold.",
         "gold" : "You do not see any gold right off.",
         "room" : "It is very buitifull.",
         "ground" : "It is very unique.",
    ] ));
set_max_mining(2);
set_chance(2);
set_max_find(4);
set_nugget( ([ "1":1, "2":1, "3":3, ]) );

set_max_fishing(2);
set_chance(12);
set_max_catch(10);
set_fish( ([ "Brown troute":5, "Mine troute":5, "Rainbow troute":5, ]) );
}
