#include "../shadow.h"
#include <daemons.h>

inherit VAULT;

void create(){
    ::create();
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("%^RESET%^%^BOLD%^%^ORANGE%^On %^ORANGE%^The %^ORANGE%^Quie%^GREEN%^t %^ORANGE%^For%^GREEN%^e%^ORANGE%^st %^ORANGE%^Road%^RESET%^%^RESET%^");
    set_long(
"%^RESET%^%^BOLD%^%^ORANGE%^On %^ORANGE%^The %^ORANGE%^Quie%^GREEN%^t %^ORANGE%^For%^GREEN%^e%^ORANGE%^st %^ORANGE%^Road%^RESET%^%^RESET%^
%^RESET%^%^GREEN%^The %^BOLD%^%^GREEN%^r%^ORANGE%^o%^GREEN%^a%^ORANGE%^d%^RESET%^%^GREEN%^ leads to the Quiet Forest. Around you, you can see a small %^BOLD%^%^ORANGE%^vill%^GREEN%^a%^ORANGE%^ge.%^RESET%^%^GREEN%^ There are several farms scattered around this area. The %^BOLD%^%^ORANGE%^g%^GREEN%^a%^ORANGE%^te%^RESET%^%^GREEN%^ and walls of Shadow City loom over you to the east, and you can see houses peering over them.%^RESET%^
"
        );

    set_items(([
                   "road":"A road through the village.",
                   "village":"A small village with farmers working."
                   ]));

    set_exits(([
                   "east" : "/d/shadow/city/room/westgate",
                   "west" : VILLAGEDIR+"mainroad2",
                   "south" : VILLAGEDIR+"path1"
                   ]));
    set_smell("default","You smell fresh air and the odor of baked goods mixed with manure.");
    set_listen("default","You can hear the sounds of busy farmers doing their chores.");
    set_door("gate", "/d/shadow/city/room/westgate","east","xxxyyy");

    set_lock_description("gate","lock","This is a huge bar across the giant door.");
    set_door_description("gate","These are two huge solid wooden doors that come together in the middle. They are bound together with giant dwarven forged iron bands.");
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

