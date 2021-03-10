//bar1.c

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
    set_long(
@NEWBIE
You are standing amid the rubble of a ruined building with the roof open
to the sky. Rotten wood that once served as shelving line the remains of
walls. The remains of tables and chairs cover the floor, along with a lot
of broken glass.
NEWBIE
    );
    set_smell("default","The air brings odors from things buried in the rubble.");
    set_listen("default","The wind rattles through the ruined buildings.");
//    set_search("rubble",(:TO,"__Search":));
    set_items(([
        "rubble":"The remains of the stone and wood once used in construction.",
    ]));
    set_exits(([
        "north":N_RUINS"wroad7",
        "east":N_RUINS"road7",
        "south":N_RUINS"gpath3",
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
