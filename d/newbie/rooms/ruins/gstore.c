//gstore.c

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
walls. Various broken items litter the floor - pieces of cloth, metal,
wood, and other materials.
NEWBIE
    );
    set_smell("default","The air brings odors from things buried in the rubble.");
    set_listen("default","The wind rattles through the ruined buildings.");
    set_search("rubble",(:TO,"__Search":));
    set_items(([
        "rubble":"The remains of the stone and wood once used in construction.",
    ]));
    set_exits(([
        "north":N_RUINS"gpath1",
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

    switch(random(17)){
    case 0:
        ob = new(CMISC"chest");
        if(!ob->move(who)) ob->move(TO);
        break;
    case 1:
        ob = new(CMISC"schest");
        break;
    case 2:
        ob = new(CMISC"sack");
        break;
    case 3:
        ob = new(CMISC"ssack");
        break;
    case 4:
        ob = new(CMISC"pouch");
        break;
    case 5:
        ob = new(CMISC"spouch");
        break;
    case 6:
        ob = new(CMISC"climb_tool");
        break;
    case 7:
        ob = new(CMISC"rope");
        break;
    case 8:
        ob = new(CMISC"basket");
        break;
    case 9:
        ob = new(CMISC"sbasket");
        break;
    case 10:
        ob = new(CMISC"torch");
        break;
    case 11:
        ob = new(CMISC"lantern");
        break;
    case 12:
        ob = new(CMISC"oil");
        break;
    case 13:
        ob = new(CMISC"beacon");
        break;
    case 14:
        ob = new(CMISC"bullseye");
        break;
    case 15:
        ob = new(CMISC"flint");
        break;
    case 16:
        ob = new(CMISC"lkchest");
        break;
    }
    if(!ob->move(who) == MOVE_OK) ob->move(TO);
}
