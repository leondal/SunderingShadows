#include "/d/player.village/pvillage.h"
inherit ROOM;

void create(){
  ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Player Village Road");
    set_long(
		"This is the Player Village Road. \n"
	     	"It is the only road to and from the player village.\n"
	     	"South is the village. You are in a lightly wooded forest. ");
    set_exits(([
	"northwest" : VILLAGE+"pvroad4",
	"south" : VILLAGE+"pvroad2",
    ]));
   set_smell("default","You smell fresh air and the odor of wildflowers.");
   set_listen("default","You can hear birds singing.");
}
