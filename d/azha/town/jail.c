// Azha Town Gaol
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
	set_short("Azha Town Gaol");
  set_long(
@AZHA
%^BOLD%^Azha Town Gaol%^RESET%^
	Welcome to the Azha Town Gaol, where all of the enemies of His
Imperial Majesty's peace are kept until they see the error of their
ways!  Looking around, you will notice some drunks, some shady
looking vagrants (probably crooks) and the ever present stench of
body odor, excrement and vomit.  Not exactly where you want to end up
at the end of a weekend.  Hopefully you will get out before long or
at least before _you_ vomit.
	You can <peer out> to see if someone has arrived to bail your
sorry butt outta here.
AZHA
    );
	set_exits(([
	"out" : "/d/azha/town/police"
  ] ));     
	set_smell("default","The stench of alcohol and vomit is absolutely sickening.");
}
