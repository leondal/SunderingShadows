#include "/d/player.village/pvillage.h"

#define FILENAME "/d/player.village/data/nroad5"

inherit "/d/player.village/road.c";

void create(){
  ::create();
    set_short("North Road");
    set_long(" ");
    set_exits(([
	"north" : VILLAGE+"pvroad1",
	"west"  : VILLAGE+"nroad6",
	"east"  : VILLAGE+"nroad4"
    ]));
}
void restoreit(){
        restore_object(FILENAME,1);
	adjust_doors();

}
void saveit(){
        save_object(FILENAME,1);
}
