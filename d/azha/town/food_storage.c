// Food Merchant Storeroom (wizards-only)
// Thorn@ShadowGate
// 4/13/95
// Town of Azha
// food_storage.c

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  room::create();
   set_property("no teleport",1);
	set_light(2);
	set_indoors(1);  
	set_short("Food Merchant Storeroom (wizards-only)");
  set_long(
@AZHA
%^BOLD%^Food Merchant Storeroom (wizards-only)%^RESET%^
  This room stores the things sold by food merchants in Azha Market.
AZHA
    );
	set_exits(([
	"out" : "/d/azha/town/wroad",
  ] ));     
}
