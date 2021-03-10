#include "../undead.h"

inherit ROOM;

void create() 
{
    ::create();

    set_name("Inside Castle de Boquillas");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);

    set_short("%^BOLD%^You are inside Castle de Boquillas%^RESET%^");
 
    set_long("%^BOLD%^You are inside Castle de Boquillas.%^RESET%^\n"
        "%^BLUE%^The first thing that strikes you is the incredible serenity "
        "of this great castle. In fact it appears to be only a castle by name "
        "but in fact a cathedral at heart. Stained glass windows allow many "
        "colors of light to shine down upon you. Despite the war that is raging "
        "outside, there is only peace and a holy peace inside these castle "
        "walls.");
 
    set_exits(([
        "north"     :TOWN+"cast3",
        "south"     :TOWN+"cast"
             ]));
    
    set_smell("default","The faint smell of incense hangs in the air.");
    set_listen("default","You can hear nothing within these walls.");

}
