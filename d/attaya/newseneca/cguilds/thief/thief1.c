#include "/d/attaya/newseneca/seneca.h"

inherit ROOM;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_short("%^BOLD%^%^BLUE%^This is a small closet in the daughter's bedroom.%^RESET%^ ");
    set_long(
      "   %^BOLD%^%^BLUE%^This is a small closet in the daughter's bedroom.%^RESET%^\n You see beautiful clothes hanging on hangers here. Shoes of many colours lay in a neat row on the floor. A long black coat hangs on a hook at the back of the closet. It looks strangely out of place."
    );
    set_light(2);
    set_indoors(0);
    set_smell("default","It smells musty here....of old clothes. ");
    set_listen("default","You hear nothing.");
    set_items( ([
	"clothes" : "There are many dresses, shirts, and pants hanging in this closet.",
	"shoes" : "The shoes here are many and varied. You can tell there are many uses for them such as: Walking, walking long distances, running, parties and so on.",
	"coat" : "This is a long black coat made of a strange material. It almost seems to shine even tho it is black. You somehow know that only someone with special abilites could wear it. Very strange...",
      ]) );
    set_exits( ([
	"out" : THIEF "thief8",

      ]) );
}
void init(){
    ::init();
    add_action("allow", "wear");
}


int allow(string str) {
    if(!str) {
	return notify_fail("Wear what?");
    }

    if(str != "coat") {
	return notify_fail("Wear what?");
    }

    if(TP->is_class("thief") || TP->is_class("bard")){
	tell_object(TP, "You take the coat off the hook and slip it on.");
	tell_object(TP, "You feel rather strange at first...almost light headed.");
	tell_object(TP, "%^BOLD%^You are shifted to another place.");
	tell_room(ETP, ""+TP->query_cap_name()+" wears the coat. %^RED%^Perfect fit.", TP);
	TP->move_player(THIEF "2thief9.c");
	return 1;
    } else {
	tell_object(TP, "%^BLUE%^As you wear the coat you suddenly see the room disappearing.");
	tell_object(TP, "%^BLUE%^The walls shift and all becomes dark!");
       tell_object(TP, "%^BLUE%^You throw the cloak from your neck before it can strangle you!");
	tell_room(ETP, "%^BLUE%^ "+TPQCN+" mysteriously starts being strangled by the coat.\n"+TP->query_subjective()+" quickly takes off the coat!", TP);
	return 1;
    }
}
