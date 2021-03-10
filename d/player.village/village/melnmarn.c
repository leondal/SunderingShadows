#include "/d/player.village/pvillage.h"
inherit "/d/player.village/phouse.c";
void create(){
	::create();
	set_property("light",1);
	set_property("indoors",1);
	seteuid("Player.village");
}
void init(){
     restoreit(); ::init();
}
