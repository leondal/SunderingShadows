// Center Street, Azha, outside a tavern and library
// Thorn@ShadowGate
// 4/8/95
// Town of Azha

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  room::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
	set_light(2);
	set_indoors(0);  
	set_short("Center Street, Azha");
  set_long(
@AZHA
%^BOLD%^Center Street%^RESET%^

  You have found yourself at the south end of Center Street, a
short, but busy stretch of road going south from Fortress Street to
the Market Gate in the center of town.  To the west, you see herbs
drying in the windowsill, and behind, a few chairs like those
barbers seat their customers.  To the east, though, is a neat
looking building with a high roof, stone walls and great bronze
doors, which are open wide.  There is a gilded plaque on the wall
facing you, if you wish to look at it. 

  Center Street continues to the north and south.
AZHA
    );
	set_exits(([
	"north" : "/d/azha/town/center1",
	"south" : "/d/azha/town/high3",    
        "east" : "/d/azha/town/tavern",
	"west" : "/d/azha/town/healer"    
  ] ));     
	set_smell("default","The smell of perfumes and spices tickles your nose delightfully.");
	set_items(([
                "plaque" : "The plaque reads: \"Celestial Emperor Tavern\" in Common and Tsarvani.\n",
	] ));
}
