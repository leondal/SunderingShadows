//  Governor ibn Shiraz's magical quarterstaff +2
//  Thorn@ShadowGate
//  12/9/95
//  Azha Area
//  gov_staff.c

#include <std.h>

inherit "/d/common/obj/weapon/quarter_staff.c";

create() {
    ::create();
   set_id(({ "quarterstaff", "magical quarterstaff", "staff" }));
   set_name("quarterstaff");
   set_short("An ornate quarterstaff");
   set_property("enchantment", 2);
   set_long(
@TSARVEN
	This a fairly normal looking bronzewood staff banded with iron.  You notice
some carvings in the Tsarvani style in certain places on the staff for some
decoration.  Although it seems ornamental, this staff is quite solid looking
and would serve well in a fight.
TSARVEN
		   );
   
   set("value", 100);
}

