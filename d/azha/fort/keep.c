#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;
int gate;

void create() {
  room::create();
	set_light(2);
        set_indoors(0);
	set_short("The Main Entrance, Azha Fort's keep ");
  set_long(
@AZHA
	You are in the main entrance of Azha Fort's keep.  This building is
crude by the standards of Tsarven, but is still the finest kept
structure in this frontier province, and it helps that the Governor
of Azha resides here in relative comfort and safety.  A long carpet,
woven by the Elves of Sindh stretches down the passageway to the
west.
AZHA
    );
	set_exits(([
	"east" : "/d/azha/fort/gate",     
	"west" : "/d/azha/fort/passage1"
  ] ));     
	set_smell("default","You smell the dust from the outside, with a hint of a"+
	" fragrance of perfume.");
	set_items(([
		"carpet" : "This carpet is fairly humble, but still exhibits the "+
		"skill of a master weaver of Sindh." ] ));
}
