//  Outside of The South Gate
//  9/28/94
//  Darkwood forest
//  road1
/*updated 10/4/03 by Circe.  Added room name and updated code to current standards.  Changed road to use inherits*/

#include <std.h>
#include <daemons.h>

inherit VAULT;

void create() {
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_light(2);
    set_indoors(0);
    set_name("Outside of Shadow's South Gate");
    set_short("Outside of Shadow's South Gate");
    set_long(
@THORN
You have found yourself just outside the South Gate of the City of
Shadow.  To the south of you stretches the Royal Southern Road that
passes through a dark forest to the town of Tharis far to the south of
here.  Looking to the east and west of you you notice the campground of
a band of barbarians and a few guard posts, where the guards keep a wary
eye on the visitors.
THORN
);
   set_listen("default","The din of the city makes its way through the gates.");
   set_smell("default","The clean air of the southern forest is masked by the smells of the city.");
    set_exits(
              (["north" : "/d/shadow/city/room/southgate",
                "south" : "/d/darkwood/room/road2",
                "west" : "/d/shadow/room/village/path16",
           ]));
    set_door("gate", "/d/shadow/room/city/southgate","north","xxxyyy");
    set_lock_description("gate","lock","This is a huge bar across the giant door.");
    set_door_description("gate","These are two huge solid wooden doors that come together in the middle. They are bound together with giant dwarven forged iron bands.");
    lock_difficulty("gate",-2000,"lock");
    set_open("gate",((string)EVENTS_D->query_time_of_day() != "night"));
//    set_locked("gate",((string)EVENTS_D->query_time_of_day() == "night"));
}

void reset(){
    ::reset();
    set_open("gate",((string)EVENTS_D->query_time_of_day() != "night"));
    set_locked("gate", 0);
//    set_locked("gate",((string)EVENTS_D->query_time_of_day() == "night"));
    if(!present("law sign")){
       new("/d/shadow/obj/lawsign")->move(TO);
    }
}
