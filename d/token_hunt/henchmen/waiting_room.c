#include <std.h>

inherit CROOM;


void create()
{
    ::create();
    
    set_short("Waiting Room");
    set_name("Waiting Room");
    set_long("A waiting room for henchmen, players should never see this.");
    set_property("no teleport",1);
    set_property("indoors",1);
    set_property("light",2);
    set_property("no clean",1);
    set_terrain(RUINS);
    set_travel(PAVED_ROAD);

}

int clean_up() { return 1; }