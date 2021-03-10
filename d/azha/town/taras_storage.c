// Taras Beck Storeroom (wizards-only)
// Thorn@ShadowGate
// 4/13/95
// Town of Azha
// taras_storage.c

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  room::create();
   set_property("no teleport",1);
	set_light(2);
	set_indoors(0);  
	set_short("Taras Beck Storeroom (wizards-only)");
  set_long(
@AZHA
%^BOLD%^Taras Beck Storeroom (wizards-only)%^RESET%^
  This room stores the things sold by Taras Beck.
AZHA
    );
	set_exits(([
	"out" : "/d/azha/town/wroad",
  ] ));     
}
