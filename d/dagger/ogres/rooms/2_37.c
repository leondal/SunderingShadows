#include <std.h>
#include "../ogres.h"

inherit STORAGE"2nd.c";

int mechanism;

void init() {
    ::init();
    add_action("fix_func", "fix");
    add_action("break_func", "break");

}

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^%^ORANGE%^There is some wooden mechanism here extending from holes in the cavern wall.%^RESET%^.\n");
   set_exits(([
      "southeast" : ROOMS"2_1",
   ]));

    set_items
    (([
        ({"floor", "ground", "outcroppings"}) : "%^RESET%^%^ORANGE%^The ground here is"+
"rough, uneven, and random outcroppings of rock make navigating difficult.%^RESET%^",
        ({"wall", "walls"}) : "%^RESET%^%^ORANGE%^The walls here are rough, and"+
" mostly cloaked in shadows.%^RESET%^",
        ({"mechanism", "wooden mechanism"}) : "%^RESET%^%^ORANGE%^Extending out from the wall of the "+
"carvern is a heavy wooden mechanism. This is obviously not the design or construction of the ogres, "+
"but it seems like it could operate something important. If you tried, you might be able to "+
"%^BOLD%^break%^RESET%^%^ORANGE%^ or %^YELLOW%^fix%^RESET%^%^ORANGE%^ it.%^RESET%^",
        ({"corpses"}) : "%^RESET%^%^ORANGE%^corpses of what look to be both ogres"+
" and various demons lay in varied stages of mutilation and decomposition. "+
"%^RESET%^%^YELLOW%^Rats %^RESET%^%^ORANGE%^and %^RESET%^%^BOLD%^%^WHITE%^maggots"+
" %^RESET%^%^ORANGE%^swarm over the more recent piles...%^RESET%^",
    ]));

}


int break_func(string str){
    object pow_rm; 
    int roll,smarts; 

    roll = random(20);
    smarts = TP->query_stats("intelligence");

    pow_rm =find_object_or_load( ROOMS"power");

    if(!str) {
        tell_object(TP,"Break what?\n");
        return 1;
    }
        if(str != "mechanism"){
        tell_object(TP,"Break what?\n");
        return 1;
        }
        if(mechanism != 1){
            tell_object(TP,"You can't see how you could break the mechanisms any more...");
            return 1;
        }
        if(roll > smarts) {
            tell_room(ETP,""+TPQCN+" looks over the mechanisms... They look confused. \n\n",TP);
            tell_object(TP,"You can't seem to figure out how to break the mechanism.\n");
            return 1;
        }
            tell_room(ETP,""+TPQCN+" looks over the mechanisms... Then moves one of the smaller pieces. \n\n",TP);
            tell_object(TP,"You find the perfect piece to move to break the mechanism.\n");
            mechanism = 0;
            pow_rm->remove_power();
            return 1;
}

int fix_func(string str){
    object pow_rm; 
    int roll,smarts; 

    roll = random(20);
    smarts = TP->query_stats("intelligence");
    pow_rm =find_object_or_load( ROOMS"power");

    if(!str) {
        tell_object(TP,"Fix what?\n");
        return 1;
    }
        if(str != "mechanism"){
        tell_object(TP,"Fix what?\n");
        return 1;
        }
        if(mechanism != 0){
            tell_object(TP,"The mechanism seems to be working well...");
            return 1;
        }
        if(roll > smarts) {
            tell_room(ETP,""+TPQCN+" looks over the mechanisms... They look confused. \n\n",TP);
            tell_object(TP,"You can't seem to figure out how to fix the mechanism.\n");
            return 1;
        }
            tell_room(ETP,""+TPQCN+" looks over the mechanisms... Then moves one of the smaller pieces. \n\n",TP);
            tell_object(TP,"You find the perfect piece to move to start the flow of water.\n");
            mechanism = 1;
            pow_rm->add_power();
            return 1;
}
