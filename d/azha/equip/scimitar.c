//  A scimitar made for the Imperial Army of Tsarven
//  Thorn@ShadowGate
//  11/24/95
//  Southern Realms Equipment - Tsarven
//  iscimitar.c

#include <std.h>

inherit "/d/common/obj/weapon/scimitar.c";

create() {
    ::create();
   set_id(({ "sword", "tsarvani scimitar", "scimitar" }));
   set_name("scimitar");
   set_short("A Tsarvani scimitar");
   set_long(
@TSARVEN
	This is a scimitar, a distinctive weapon of the Southern Realms.
Looking at either the workmanship or the style of the sword instantly
gives away its place of origin as Tsarven. This weapon seems to be
well kept and serviced.  Probably a military weapon.
TSARVEN
	   );
}

