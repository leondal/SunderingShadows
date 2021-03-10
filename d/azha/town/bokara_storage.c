// Vishnu Bokara Storeroom (wizards-only)
// Thorn@ShadowGate
// 970305
// Town of Azha
// bokara_storage.c

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  room::create();
   set_property("no teleport",1);
        set_light(2);
        set_indoors(1);
        set_short("Vishnu Bokara Storeroom (wizards-only)");
  set_long(
@AZHA
%^BOLD%^Vishnu Bokara Storeroom (wizards-only)%^RESET%^
  This room stores the things sold by Vishnu Bokara Storeroom in Azha
Market.
AZHA
    );
        set_exits(([
        "out" : "/d/azha/town/wroad",
  ] ));
}

reset()
{
	::reset();
  AOVER->add_object(TO,"/d/azha/obj/mr_ring", 1);
   AOVER->cheap_imitation(TO,"/d/azha/obj/mr_ring", 3, 25);
  AOVER->cheap_imitation(TO,"/d/azha/obj/gemsee", 3, 35);
  AOVER->cheap_imitation(TO,"/d/azha/obj/gmr_ring", 2, 5);
  AOVER->cheap_imitation(TO,"/d/deku/armours/ring_p", 3, 35);
  AOVER->cheap_imitation(TO,"/d/azha/obj/rift_key", 3, 30);
  AOVER->add_object(TO,"/d/azha/obj/crescent",1);
  AOVER->cheap_imitation(TO,"/d/azha/obj/crescent",2,5);
}
