#include "/d/player.village/pvillage.h"

#define FILENAME "/d/player.village/data/nroad1"

inherit "/d/player.village/road.c";

void create(){
  ::create();
    set_short("North Road");
    set_long(" ");
    set_exits(([
	"north" : MAIN+"office",
	"west"  : VILLAGE+"nroad2",
	"south" : VILLAGE+"mroad1",
	"east"  : MAIN+"lockoffice"
    ]));
}
void restoreit(){
        restore_object(FILENAME,1);
	adjust_doors();
}
void saveit(){
        save_object(FILENAME,1);
}
