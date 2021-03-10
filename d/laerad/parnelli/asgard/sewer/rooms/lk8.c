#include <std.h>
#include "../lizard.h"
inherit VAULT;
void create(){
::create();
set_name("Dry Caves");
set("short","Dry well lit cavern.");
set("long","%^ORANGE%^You find yourself in a small dry room of the cavern.  There is a door in the east wall.  "+
   "The walls and floor look like the stone has been worked in this area. Torches line the walls "+
   "and this area is very well lit.  %^RESET%^");
set_property("indoors",1);
set_property("no teleport",1);
set_property("light",2);
set_terrain(NAT_CAVE);
set_travel(DIRT_ROAD);
set_smell("default","The room smells dusty and dry.");
set_listen("default","It is very quiet in these rooms save for the sounds you make.");
set_items(([
   "walls":"Much like what you would expect cave walls to be like, hard, dry and cool to the touch.",
   "floor":"Smooth and flat as if from some stoneworking and much usage.",
   "torches":"Sputtering and flickering the torches on the walls illuminate the room completely.",
   "door":"Made of solid oak, it looks like it can take a hard hit.  The keyhole winks at you in the torchlight.",
   "oak door":"Made of solid oak, it looks like it can take a hard hit.  The keyhole winks at you in the torchlight.",
   "torch":"Sputtering and flickering the torches on the walls illuminate the room completely."
   ]));

set_door("oak door",LROOMS+"lk9","east","green key");
set_door_description("oak door","Made of solid oak, it looks like it can take a hard "+
	"hit.  The keyhole winks at you in the torchlight.");
set_string("oak door","open","The door swings open.  Your hear it creak louder than you like and then hear an auduble click.\n");

set_exits(([
   "north":LROOMS+"lk3",
   "east":LROOMS+"lk9",
   "west":LROOMS+"lk7",
   "southwest":LROOMS+"lk12"
 ]));
set_trap_functions(({"southwest","west"}),({"lguards","lguards2"}),({"southwest","west"}));
}

int lguards(){
    object ob;
    if(interactive(TP)){
    tell_object(TP,"As you attempt to leave the room hear an audible click!");
    tell_room(ETP,""+TPQCN+" starts to leave the room and you hear an audible click!",TP);
    tell_room(TO,"%^BOLD%^%^GREEN%^Lizardmen rush from the north to see what set off their trap!%^RESET%^");
// fixing it so the lizardmen know to block  *Styx* 6/21/03
    ob = new(LMON+"nwlman");
	ob->move(TO);
//            command("block west");  this needs to know what is being commanded, so...
    	ob->force_me("block west");
    ob = new(LMON+"nwlman");
	ob->move(TO);
    	ob->force_me("block southwest");
    ob = new(LMON+"nwlman");
	ob->move(TO);
        ob->force_me("block west");
    ob = new(LMON+"nwlman");
	ob->move(TO);
        ob->force_me("block southwest");
    ob = new(LMON+"nwlman");
	ob->move(TO);
        ob->force_me("block north");
    ob = new(LMON+"nwlman");
	ob->move(TO);
        ob->force_me("block east");
    new(LMON+"nwlman")->move(TO);
    toggle_trap("southwest");
    return 1;
    }
}

int lguards2(){
    object ob;
    if(interactive(TP)){
    tell_object(TP,"As you attempt to leave the room hear an audible click!");
    tell_room(ETP,""+TPQCN+" starts to leave the room and you hear an audible click!",TP);
    tell_room(TO,"%^BOLD%^%^GREEN%^Lizardmen rush from the west to see what set off their trap!%^RESET%^");
// fixing it so the lizardmen know to block  *Styx* 6/21/03
    ob = new(LMON+"nwlman");
	ob->move(TO);
//            command("block west");  this needs to know what is being commanded, so...
    	ob->force_me("block west");
    ob = new(LMON+"nwlman");
	ob->move(TO);
    	ob->force_me("block southwest");
    ob = new(LMON+"nwlman");
	ob->move(TO);
        ob->force_me("block west");
    ob = new(LMON+"nwlman");
	ob->move(TO);
        ob->force_me("block southwest");
    ob = new(LMON+"nwlman");
	ob->move(TO);
        ob->force_me("block north");
    ob = new(LMON+"nwlman");
	ob->move(TO);
        ob->force_me("block east");
    new(LMON+"nwlman")->move(TO);
    toggle_trap("west");
    return 1;
    }
}

void reset(){
        ::reset();
        if(!trapped("southwest"))
                toggle_trap("southwest");
        if(!trapped("west"))
                toggle_trap("west");
}