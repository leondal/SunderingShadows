//inn.c

#include <std.h>
#include <move.h>
#include "../../newbie.h"

inherit ROOM;

void find_item(object who);
int flag;

void create() {
    ::create();
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain(RUINS);
    set_travel(RUBBLE);
    set_short("The ruins of a town.");
    set_indoors(1);
    set_long(
@NEWBIE
You are standing amid the rubble of a ruined two-story building. The
second floor has survived enough to provide covering here. Tables and
chairs have endured partially intact, protected from the elements. You
climb over and around the damaged items, occasionally catching a glimpse
of something as the light hits it.
NEWBIE
    );
    set_smell("default","The air brings odors from things buried in the rubble.");
    set_listen("default","The wind rattles the remains of wall decorations.");
//    set_search("rubble",(:TO,"__Search":));
    set_items(([
        "rubble":"The remains of the stone and wood once used in construction.",
    ]));
    set_exits(([
        "north":N_RUINS"eroad3",
        "south":N_RUINS"ipath1",
        "west":N_RUINS"eroad2",
    ]));
}

void reset() {
    ::reset();
    flag = 0;
}

int __Search() {
    object ob;

    write("You dig through the rubble.");
    tell_room(TO,TPQCN+" searches through the rubble.",TP);
    if(flag){
        write("You find nothing.");
        return 1;
    }
    else{
        switch(random(10)) {
        case 0..2:
            write("You pull something out of the pile!");
            tell_room(TO,TPQCN+" finds something in the rubble.",TP);
            find_item(TP);
            flag = 1;
            break;
        case 3..6:
            write("You cut yourself on some sharp debris!");
            TP->do_damage("right hand",random(3)+1);
            break;
        default:
            write("You find nothing.");
            break;
        }
    }
    if(!flag && random(2)) flag = 1;
    return 1;
}

void find_item(object who){
    object ob;

    if(!ob->move(who) == MOVE_OK) ob->move(TO);
}
