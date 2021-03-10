#include "../../undead.h"

inherit INH+"street";


void create() 
{
    ::create();
    set_long(::query_long() +"  Within the massive wall east of you lies one of "
        "the two main city gates.\n");

    set_exits(([
        "gate":BF"room5",
        "south":TOWN"street7",
        "west":TOWN"street5"
    ]));

    set_door("gate",BF+"room5","gate","open_gate");
    set_open("gate",0);
    set_string("gate","open","The metal gates lift up, allowing you to pass!");
    set_door_description("gate","These massive metal gates are easily twice the "
        "height of an average man and almost that wide.  They are built of solid slabs "
        "of iron with steel mesh criss-crossing over the front in a lattice design.");
}

void reset() 
{
    ::reset();
    if(query_exit("ditch")) remove_exit("ditch");
    if(!present("guard"))
        new(MON"ogre_guard")->move(TO);
    if(!present("ditchguard"))
        new(MON"ogre_gate_guard")->move(TO);
}

void init() 
{
    ::init();
    add_action("pay","pay");
}

int pay(string str) 
{
    if(!present("guard")) return 0;
    if ((str=="20 gold") || (str=="guard 20 gold") || (str=="ogre 20 gold") || (str=="gate guard 20 gold")) 
    {
        if(TP->query_money("gold") < 20)
            return notify_fail("You haven't the money!\n");
        TP->add_money("gold",-20);
        tell_object(TP,"You pay the guard and he lifts a small mat revealing "
            "an underground tunnel.");
        tell_room(ETO,""+TPQCN+" pays the guard and the guard lifts a mat "
            "revealing a small tunnel.",TP);
        add_exit(TOWN"ditch", "ditch");
    }
    return 1;
}
