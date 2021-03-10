//  A scimitar made for the Imperial Army of Tsarven
//  Thorn@ShadowGate
//  11/24/95
//  Azha Area
//  iscimitar.c

#include <std.h>

inherit WEAPON;

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
   set_weight(12);
   set_size(3);
   set("value", 5);
   set_wc(1,6);
   set_large_wc(1,12);
   set_type("pierce");
   set_prof_type("polearm");
}

