// Azha Town Mosque
// Thorn@ShadowGate
// 961013
// Town of Azha

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit "/std/church";

void create() {
  church::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_light(2);
	set_indoors(1);  
	set_short("Mosque of Azha");
  set_long(
@AZHA
%^BOLD%^Mosque of Azha%^RESET%^
	Looking around you notice that you are in a small building with
many, many columns and arches inside.  This has a distinctly southern
feeling, as opposed to the rest of the town.  The building is very 
quiet, except for some murmurs from the faithful who appear to be
praying.  The ceilings are ornamented with stylized script in many
colors, probably readings from the Tsarvani holy books, but there are
no images anywhere in the building.
AZHA
    );
	set_exits(([
	"south" : "/d/azha/town/fort4"
  ] ));     
	set_listen("default","You hear the murmurs of the faithful at prayer.");
}

reset() {
	::reset();
	AOVER->setup_monsters(TO, "public");
	AOVER->add_monster(TO, AMONDIR+"alsura", 1);
	AOVER->add_monster(TO, AMONDIR+"alshabazz", 1);
}

	
