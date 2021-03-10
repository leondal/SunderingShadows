#include "../../undead.h"

inherit VAULT;

void create() 
{
    ::create();

    set_name("Inside Castle de Boquillas");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);

    set_short("%^BOLD%^You are inside Castle de Boquillas%^RESET%^");
 
    set_long("%^BOLD%^You step into Castle de Boquillas.%^RESET%^\n"
        "%^BLUE%^The first thing that strikes you is the incredible serenity "
        "of this great castle. In fact it appears to be only a castle by name "
        "but in fact a cathedral at heart. Stained glass windows allow many "
        "colors of light to shine down upon you. Despite the war that is raging "
        "outside, there is only peace and a holy peace inside these castle "
        "walls.");
 
    set_exits(([
        "north"     :TOWN+"cast2",
        "east"      :TOWN+"guard4",
        "west"      :TOWN+"guard3",
        "gate"      :TOWN+"room12"
             ]));

    set_smell("default","The faint smell of incense hangs in the air.");
    set_listen("default","You can hear nothing within these walls.");

    set_door("gate",TOWN+"room12","gate","open_gate");
    set_open("gate",0);
    set_string("gate","open", "The giant metal gates lift up allowing you to pass!");
    set_door_description("gate","These massive metal gates are easily twice the "
        "height of an average man and almost that wide.  They are built of solid "
        "slabs of iron with a steel mesh crisscrossing over the front in a latice "
        "design.");

}
