// Azha Town Watch Office
// Thorn@ShadowGate
// 4/6/95
// Town of Azha

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  room::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_light(2);
	set_indoors(1);  
	set_short("Azha Town Watch Office");
  set_long(
@AZHA
%^BOLD%^Azha Town Watch Office%^RESET%^
	Even in an orderly state like the Empire, there are those who 
disrupt the peace.  This goes especially for this frontier outpost,
and to counter the unseemly element of the town, the town watch
patrols the city.  This small building is the headquarters of the
watch.  It also houses the gaol, where small-time crooks and drunks
are kept until their short sentence is up.
	You can <peer jail> to look for any friends in lock-up.
AZHA
    );
	set_exits(([
	"south" : "/d/azha/town/fort3",
	"jail" : "/d/azha/town/jail"
  ] ));     
	set_smell("default","The stench of alcohol and vomit pollutes the air here.");
}

reset() {
        ::reset();
        AOVER->setup_monsters(TO, "public");
	AOVER->add_monster(TO, AMONDIR+"dubcheck", 1);
}
