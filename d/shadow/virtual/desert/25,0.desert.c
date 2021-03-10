#include <std.h>
#include <daemons.h>

inherit VAULT;

int is_virtual() { return 1; }

void create() {
set_indoors(0);
 ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(PAVED_ROAD);
 set_light(2);
 set_short("Outside the gates of Shadow");
 set_long(
@MELNMARN
%^BOLD%^You stand outside the gates of Shadow.%^RESET%^
%^GREEN%^You stand outside of Shadow, by the gate. Walls of the city loom over you. The light forest here thins as you look east. The road is well worn from the passages.
MELNMARN
 );
 set_exits(([
                "west":"/d/shadow/city/room/eastgate",
    "east":"/d/shadow/virtual/desert/25,1.desert"
]));
    set_smell("default","You smell the odors of a bustling city.");
    set_listen("default","You hear the sounds of people moving in the city.");
    set_door("gate", "/d/shadow/room/city/eastgate","west","xxxyyy");

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
    if(!present("law sign")){
       new("/d/shadow/obj/lawsign")->move(TO);
    }
}
