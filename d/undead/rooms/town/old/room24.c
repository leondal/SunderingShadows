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
    
    set_long("%^GREEN%^You are inside the castle gates of Graez.%^RESET%^\n"
        "%^BOLD%^You are traveling upon St.Paul's Street, which twists "
        "around the entire market place, in what's left of Graez. All around "
        "you soldiers shuffle off to battle, most of them will not return.  "
        "Over the centuries the great empire that was once centered in the "
        "city of Graez has dwindled down to these few besieged streets, kept "
        "alive only by their sole remaining dock. The your east lies one of the "
        "two main gates to the city of Graez.");

    set_exits(([
        "gate"      :BF+"room5",
        "west"      :TOWN+"room16",
        "south"     :TOWN+"room25"
             ]));

    set_smell("default", "The fresh scent of the ocean assails you.");
    set_listen("default", "You hear the sounds of battle in the distance.");

    set_door("gate",BF+"room5","gate","open_gate");
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

    if(query_exit("ditch")) { remove_exit("ditch"); }

    if(!present("guard"))
    {
        new(MON"ogre_gate_guard")->move(TO);
        new(MON"ogre_gate_guard")->move(TO);
    }

}

void init()
{
    ::init();
    add_action("pay","pay");
}

int pay(string str)
{
    if(!present("ogre guard")) return 0;
    
    if ((str=="20 gold") || (str=="guard 20 gold") || (str=="ogre 20 gold") || (str=="gate guard 20 gold"))
    {
        if(TP->query_money("gold") < 20) { return notify_fail("You haven't the money!\n"); }
	    TP->add_money("gold",-20);
        tell_object(this_player(),"You pay the guard and he lifts a small mat revealing "
            "an underground tunnel.");
        tell_room(ETO,""+TPQCN+" pays the guard and the guard lifts a mat revealing a "
            "small tunnel.",TP);
        add_exit(TOWN"ditch", "ditch");
    }
    return 1;
}
