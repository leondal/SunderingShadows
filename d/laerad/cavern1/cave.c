//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
   set_terrain(NAT_CAVE);
   set_travel(FOOT_PATH);
   set_property("no teleport",1);
    set_short("Laerad caverns");
    set_long(
        "%^BOLD%^%^BLACK%^You have walked into a small cave. The tunnel leads outside to the parnelli forest or down into the depths of Laerads cavern system. The air is cold and damp, the lighting poor. The walls are very tight, as if they are trying to squeeze the life out of you. 
There is a %^RED%^sign%^BLACK%^ here."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is damp and smells weird.");
    set_listen("default","You can hear the dripping of water echoing around the cave.");
   set_items(([
   "sign" : "There is a sign here, perhaps you should read it.",
   ]));
    set_exits( ([
	"out":"/d/laerad/parnelli/forest/for087",
	"down":"/d/laerad/cavern1/cav001"
    ]) );
    set_pre_exit_functions( ({"down"}), ({"GoThroughDoor"}) );
}

void init(){
    ::init();
    add_action("read","read");
}

void read(string str){
    if(!str) return notify_fail("Read what?\n");
    if(str != "sign") return 0;
    write("%^BOLD%^BEWARE! %^RESET%^The area beneath this continent is a terrible place!");
    write("Only those of considerable power should venture there!");
    write("Ye have been warned...");
    return 1;
}

int GoThroughDoor(){  // added min level due to abuse 11/30/02 *Styx*
    if(TP->query_highest_level() < 20) {
       tell_room(TO, "A voice booms from above:  %^BOLD%^%^RED%^Did you not "
          "read the sign?  You are not yet worthy to even attempt to adventure "
	  "in such a place "+TPQCN+"!%^RESET%^", TP);
       tell_object(TP, "A voice booms from above:  %^BOLD%^%^RED%^Did you not "
          "read the sign?  You are not yet worthy to even attempt to adventure "
	  "in such a place!");
       return 0;
    }
    return 1;
}

