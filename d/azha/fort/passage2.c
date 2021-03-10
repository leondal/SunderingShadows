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
  A well-worn table and stool sits to the right of you in this part of
the main passageway in front of a heavy oaken door.  This is probably
the center for tax collection in Azha.  The money, probably behind
the door, is meant for the Imperial Treasury in the great city of
Tsarven.  This passageway continues east-west through the keep, while
the door looms to the south.
AZHA
    );
	set_exits(([
	"south" : "/d/azha/fort/castellan",     
   "west" : "/d/azha/fort/passage3",
        "east" : "/d/azha/fort/passage1",
  ] ));     
	set_smell("default","The smoke from the lit torches almosts hides the "+
	"stronger smell of perfume to the west.");
	set_items(([
		"table" : "A common table with the Imperial Seal and the symbol for money "+
		"etched into the tabletop.",
		"stool" : "Not too comfortable looking, the splinters in this stool "+
		"could make tax day unpleasant for both the payers and the collectors alike.",
		] ));
}
