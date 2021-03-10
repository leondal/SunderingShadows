//  A halberd made for the Imperial Army of Tsarven
//  Thorn@ShadowGate
//  961012
//  Azha Area
//  ihalberd.c

#include <std.h>

inherit "/d/common/obj/weapon/halberd.c";

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

}
