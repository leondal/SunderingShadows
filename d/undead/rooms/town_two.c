#include "../undead.h"

inherit ROOM;

void create() 
{
    ::create();
    
    set_name("In a guard tower");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);

    set_short("%^BOLD%^%^BLUE%^A guard tower%^RESET%^");

    set_long("%^BOLD%^%^BLUE%^You step into the lower level of one of Graez's "
        "many guard towers. Bows and spears line the walls in preparation "
        "for Kartakass's next wave of attack. The undead never sleep on this "
        "island from hell, and the only way to survive is to stay eternally "
        "vigilant. Guards stand ready to do battle day and night, knowing "
        "that there chances of survival grow dimmer with each crashing tide "
        "of the opposition.");
 
    set_exits(([
        "west"      :TOWN+"room6"
             ]));

    set_smell("default","The fresh scent of the ocean assails you.");
    set_listen("default","You hear the sounds of battle in the distance.");

}

void reset() 
{
    ::reset();

    if(!present("ogre"))
    {
        new(MON"ogre_guard.c")->move(TO);
    }
}