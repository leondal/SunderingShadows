//healer.c

#include <std.h>
#include <move.h>
#include "../../newbie.h"

inherit ROOM;

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
to the sky. Shattered glass covers the floor from jars, bottles, and
vials. Rotten wood that once served as shelving line the remains of
walls.
NEWBIE
    );
    set_smell("default","The air brings odors from things buried in the rubble.");
    set_listen("default","The wind rattles through the ruined buildings.");
    set_search("rubble",(:TO,"__Search":));
    set_items(([
        "rubble":"The remains of the stone and wood once used in construction.",
    ]));
    set_exits(([
        "west":N_RUINS"wroad2",
        "east":N_RUINS"road3",
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
            write("Miraculously, you find an unbroken bottle!");
            tell_room(TO,TPQCN+" finds something in the rubble.",TP);
            ob = new(HEALKIT);
            ob->set_uses(random(4)+1);
            if(ob->move(TP) != MOVE_OK) ob->move(TO);
            flag = 1;
            break;
        case 3..6:
            write("You cut yourself on some broken glass!");
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
