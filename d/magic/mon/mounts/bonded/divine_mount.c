#include <shd.h>
#include "descs.h"

inherit "/std/flying_mount.c";

void create(){
   ::create();
   set_name("griffon");
   set_id(({"mount"}));

   set_short("%^YELLOW%^regal griffon%^RESET%^");
   set_long("%^YELLOW%^This powerfully built creature resembles a "+
      "cross between a giant eagle and a lion.  The front half of "+
	  "the griffon bears the characteristics of an eagle, raptor "+
	  "legs and head, as well as a pair of broad wings.  The latter "+
	  "half is composed of the muscular and sleek frame of a lion");
   set_vehicle_short("%^YELLOW%^regal griffon%^RESET%^");

   set_level(10);
   set_riding_level(10);
   set_value(2000);

   set_size(3);
   set_max_hp(200);
   set_hd(10,4);
   set_hp(250);
   set_overall_ac(0);
   set_exp(10);
   set_max_distance(200);

   set_attacks_num(3);
   set_damage(2,6);
   set_flight_delay(300);
   set_flying_prof(25);
   set_ward_pass(25);
}

set_deity(string mdeity, int tier){
    set_short(mountdescs[mdeity][0 + tier]);
    set_long(mountdescs[mdeity][1 + tier]);
    set_vehicle_short(query_short());
}
