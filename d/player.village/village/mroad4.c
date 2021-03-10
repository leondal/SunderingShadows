#include "/d/player.village/pvillage.h"

#define FILENAME "/d/player.village/data/mroad4"

inherit "/d/player.village/road.c";

void create(){
  ::create();
    set_short("North Road");
    set_long(" ");
    set_exits(([
	"west"  : VILLAGE+"mroad5",
	"east"  : VILLAGE+"mroad3"
    ]));
}
void restoreit(){
        restore_object(FILENAME,1);
	adjust_doors();
}
void saveit(){
        save_object(FILENAME,1);
}
