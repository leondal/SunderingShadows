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

    set_long("%^MAGENTA%^You rise to one of Graez's many archer's towers.%^RESET%^\n"
        "%^BLUE%^Here you stand well above the rest of the town, able to "
        "observe its occupants as well as the land around the castle. As "
        "Kartakass's evil hordes approach archers stand ready, bows in hand, "
        "to enter combat, against almost sure odds of defeat.");
 
    set_exits(([
        "down"      :TOWN+"guard3"
             ]));

    set_smell("default","The fresh scent of the ocean assails you.");
    set_listen("default","You hear the sounds of battle in the distance.");

}

void reset() 
{
    ::reset();

    if(!present("archer"))
    {
        new(MON"archer")->move(TO);
        new(MON"archer")->move(TO);
    }
}
