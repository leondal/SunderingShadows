#include "../undead.h"

inherit ROOM;

void create() 
{
    ::create();

    set_name("The City of Graez");
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);

    set_short("%^GREEN%^A street in the city of Graez%^RESET%^");

    set_long("%^GREEN%^A street in the city of Graez%^RESET%^\n"
        "%^BOLD%^You are traveling upon St. Paul's Street, which twists "
        "around the entire market place, in what's left of Graez. All around "
        "you soldiers shuffle off to battle, most of them will not return.  "
        "Over the centuries the great empire that was once centered in the "
        "city of Graez has dwindled down to these few besieged streets, kept "
        "alive only by their sole remaining dock.");
    
    set_exits(([
        "north"     :TOWN+"room2",
             ]));

    set_smell("default","The fresh scent of the ocean assails you.");
    set_listen("default","You hear the sounds of battle in the distance.");

}
