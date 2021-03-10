#include "/d/player.village/pvillage.h"

#define FILENAME "/d/player.village/data/sroad3"

inherit "/d/player.village/road.c";

void create(){
  ::create();
    set_short("North Road");
    set_long(" ");
    set_exits(([
	"west"  : VILLAGE+"sroad4",
	"east"  : VILLAGE+"sroad2"
    ]));
}
void restoreit(){
        restore_object(FILENAME,1);
	adjust_doors();
}
void saveit(){
        save_object(FILENAME,1);
}
