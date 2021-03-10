// Special Storeroom (wizards-only)
// Thorn@ShadowGate
// 4/13/95
// Town of Azha
// special_storage.c

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  room::create();
   set_property("no teleport",1);
	set_light(2);
	set_indoors(1);  
	set_short("Special Storeroom (wizards-only)");
  set_long(
@AZHA
%^BOLD%^Special Storeroom (wizards-only)%^RESET%^
  This room stores the special items sold by merchants in Azha Market.
AZHA
    );
	set_exits(([
	"out" : "/d/azha/town/wroad",
  ] ));     
}

reset() {
	::reset();
	AOVER->cheap_imitation(TO, "/d/laerad/obj/net", 3, 15);
	AOVER->cheap_imitation(TO, "/d/azha/obj/poison", 8, 20);
}
