//  A halberd made for the Imperial Army of Tsarven
//  Thorn@ShadowGate
//  961012
//  Azha Area
//  ihalberd.c

#include <std.h>

inherit WEAPON;

create() {
    ::create();
   set_id(({ "halberd", "tsarvani halberd" }));
   set_name("halberd");
   set_short("A Tsarvani halberd");
   set_long(
@TSARVEN
	This is a halberd, it has a hook on one side, and an axe blade on the 
other side.  Looking at either the workmanship or the style of the
polearm instantly gives away its place of origin as Tsarven. This
weapon seems to be well kept and serviced.  Probably a military
weapon.
TSARVEN
		   );
   set_weight(15);
   set_size(3);
   set("value", 10);
   set_wc(1,10);
   set_large_wc(2,6);
   set_type("slash");
   set_prof_type("polearm");
}

