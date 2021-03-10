// North Gate, Shadow
// Thorn@ShadowGate
// 970215
// City of Shadow 1997 revision
// northgate.c
// gates will be open again now *Styx* 2/10/06


#include <std.h>
#include <daemons.h>
#include "/d/shadow/room/shadow.h"
#define PASSDIR "/d/shadow/room/pass/"

inherit CVAULT;

void create() {
    set_monsters( ({ "/d/shadow/mon/guardnew" }), ({random(3)+2}) );
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_short("North Gates, Shadow.");
    set_long(
@SHADOW
%^BOLD%^CYAN%^North Gates of the City of Shadow%^RESET%^
  The north gates of the City of Shadow loom above your head as
you walk through here.  The thick walls and towers of the city
look quite formidable and they are manned by the city garrison.
You can see two entrances to the walls to the east and west of
where you are.
  To the south, you can see a crossroad with streets branching off
to the side and a wide road leading into what looks to be the
heart of the city.  To the north leads out of the city and into
the expanse of the northern realms.
%^BOLD%^  You notice there is no banner flying above the gate!%^RESET%^
SHADOW
);
    set_exits( ([
    "west":ROOMDIR+"nwltower",
    "east":ROOMDIR+"neltower",
   "south":"/d/shadow/room/main/northcross",
    "north":"/d/shadow/room/pass/pass1" 
        ]) );
    set_items(([
      "gates" : "Tall wooden gates. There is no visible way to move them.",
      "gate" : "Tall wooden gates. There is no visible way to move them.",
      "entrances":"High archways lead into the walls around the city.",
      "entrance":"High archways lead into the walls around the city.",
      "towers":"The towers loom high above the walls.",
      "tower":"The towers loom high above the walls.",
      "south":"The road heads south into the city."
               ]));

    set_smell("default","You smell a brisk odor of oak from the gates.");
    set_listen("default","A babble of noises and languages assaults your ears.");

    set_door("gate", "/d/shadow/room/pass/pass1","north",0);
    set_lock_description("gate","lock","This is a huge bar across the giant door.");
   set_door_description("gate","These are two huge solid wooden doors that come together in the middle. They are bound together with giant dwarven forged iron bands.");

    set_open("gate",((string)EVENTS_D->query_time_of_day() != "night"));
//    set_locked("gate",((string)EVENTS_D->query_time_of_day() == "night"));
//    "/d/shadow/room/pass/pass1"->set_open("gate",((string)EVENTS_D->query_time_of_day() != "night"));
//    "/d/shadow/room/pass/pass1"->set_locked("gate",((string)EVENTS_D->query_time_of_day() == "night"));
//    "/d/shadow/mon/guards/guard_d"->guard_party(TO);
}

void reset() {
   ::reset();
   set_open("gate",((string)EVENTS_D->query_time_of_day() != "night"));
   set_locked("gate", 0);
}

/*  all taken out of reset over time *****
//   set_open("gate",((string)EVENTS_D->query_time_of_day() != "night"));
//   set_locked("gate",((string)EVENTS_D->query_time_of_day() == "night"));
//   "/d/shadow/room/pass/pass1"->set_open("gate",((string)EVENTS_D->query_time_of_day() != "night"));
//   "/d/shadow/room/pass/pass1"->set_locked("gate",((string)EVENTS_D->query_time_of_day() == "night"));
    if(!present("archer")) {
        mon = new("/d/azha/mon/larcher");
// mon->set_id( ({"guard", "gate guard"}) );
        mon->move(this_object());
   }



    if(!present("archer 2")) {
        mon = new("/d/azha/mon/larcher");
// mon->set_id( ({"guard ", "gate guard"}) );
        mon->move(this_object());
    }
}
*/

