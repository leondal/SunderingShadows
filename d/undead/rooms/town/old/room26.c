#include "../../undead.h"

inherit VAULT;

void create() 
{
    ::create();

    set_name("The City of Graez");
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);

    set_short("%^GREEN%^A street in the city of Graez%^RESET%^");

    set_long("%^GREEN%^You are inside the castle gates of Graez%^RESET%^\n"
        "%^BOLD%^You are traveling upon St. Paul's Street, which twists "
        "around the entire market place, in what's left of Graez. All around "
        "you soldiers shuffle off to battle, most of them will not return.  "
        "Over the centuries the great empire that was once centered in the "
        "city of Graez has dwindled down to these few besieged streets, kept "
        "alive only by their sole remaining dock. To your east lies on of the "
        "two main gates to the city of Graez.");
 
    set_exits(([
        "gate"      :BF+"room8",
        "north"     :TOWN+"room25",
        "south"     :TOWN+"room27"
             ]));

    set_smell("default","The fresh scent of the ocean assails you.");
    set_listen("default","You hear the sounds of battle in the distance.");

    set_door("gate",BF+"room8","gate","open_gate");
    set_open("gate",0);
    set_string("gate","open", "The giant metal gates lift up allowing you to pass!");
    set_door_description("gate","These massive metal gates are easily twice the "
        "height of an average man and almost that wide.  They are built of solid "
        "slabs of iron with a steel mesh crisscrossing over the front in a latice "
        "design.");
}

void reset()
{
    ::reset();
    if(!present("guard"))
    {
        new(MON"ogre_guard")->move(TO);
        new(MON"ogre_guard")->move(TO);
    }
}
