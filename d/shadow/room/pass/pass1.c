// open gates *Styx* 2/10/06

#include <std.h>
#include <daemons.h>
#include "../pass.h"

inherit VAULT;

void create(){
    ::create();
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("On Dragon Pass Road");
    set_long(
@MELNMARN
%^BOLD%^You are walking on the Dragon Pass Road.%^RESET%^
%^ORANGE%^To the north of you lie the Charu Mountains. They are very intimidating, looming high in the sky. South of you is the NorthGate to Shadow.
MELNMARN
);

    set_smell("default","You can smell the fresh mountain air.");
    set_listen("default","You can hear the wind blowing through the valleys.");


    set_items(([
    "road":"A new road through the mountains.",
    "mountains":"They are impressive, even from here.",
    ]));

    set_exits(([
        "south" : "/d/shadow/city/room/northgate",
    "north" : PASSDIR+"pass2"
    ]));

    set_door("gate", "/d/shadow/city/room/northgate","south",0);

    set_lock_description("gate","lock","This is a huge bar across the giant door.");
     lock_difficulty("gate",-2000,"lock");

    set_open("gate",((string)EVENTS_D->query_time_of_day() != "night"));
}

void reset(){
    ::reset();
    set_open("gate",((string)EVENTS_D->query_time_of_day() != "night"));
    set_locked("gate", 0);
    if(!present("law sign")){
       new("/d/shadow/obj/lawsign")->move(TO);
    }
}
