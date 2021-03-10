// Main Passageway of Azha Keep
// Thorn@ShadowGate
// 12/18/95
// Azha Fort

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  room::create();
	set_light(2);
	set_indoors(1);    
	set_short("Main Passageway of Azha Keep.");
  set_long(
@AZHA
  You have found yourself in the midst of Azha Keep's main passageway.
looking around, you notice little but an old tapestry or two and the
torches that keep the otherwise dark passageway lit.  The passage
leads to the east and west and there is an opening to the north.
AZHA
    );
	set_exits(([
	"north" : "/d/azha/fort/treasury",     
   "west" : "/d/azha/fort/passage2", 
   "east" : "/d/azha/fort/keep",
  ] ));     
	set_smell("default","The smoke from the lit torches almosts hides the "+
	"smell of perfume to the west.");
	set_items(([
		"torches" : "Fairly common torches, good for lighting.",
		"tapestry" : "You see a tapestry that tells the story of a seige around "+
		"a great citadel with 4 towers.  One of the towers is colored black.",
		] ));
}
