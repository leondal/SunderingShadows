//  A scimitar made for the Imperial Army of Tsarven
//  Thorn@ShadowGate
//  11/24/95
//  Azha Area
//  iscimitar.c

#include <std.h>

//2013/12/31 Ergo: Updated to use proper inherit.
inherit "/d/common/obj/weapon/awlpike.c";

create() {
    ::create();
   set_id(({ "awl pike", "tsarvani pike", "pike" }));
   set_name("pike");
   set_short("A pike");
   set_long(
@TSARVEN
	This is a pike, a pole 16 feet long tipped with a spear head used by
foot soldiers. Looking at either the workmanship or the style of the
polearm instantly gives away its place of origin as Tsarven. This
weapon seems to be well kept and serviced.  Probably a military
weapon.
TSARVEN
		   );
}
