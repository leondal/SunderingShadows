#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/std/monster";
create(){
::create();
  set_name("bather");
  if(!random(2)){set_gender("male");} else { set_gender("female");}
  set_id(({
  "bather","torm bather","citizen",
  }));
  set_short(
    "Bather"
  );
  set_long(
  "  This is a very naked and comfortable looking citizen of Torm."
   "  "+capitalize(TP->query_subjective())+" sighs and relaxes a little lower into the pool of warm water, seeming not to have a care in the world."
  );
  if(!random(2)){set_race("half-elf");} else { set_race("human");}
set_body_type("human");
  set_hd(1,1);
set_max_hp(5);
set_hp(5);
set_overall_ac(10);
set_size(2);
set_stats("strength",12);
set_stats("intelligence",7);
set_stats("dexterity",9);
set_stats("charisma",7);
set_stats("constitution",11);
set_stats("wisdom",8);
set_money("silver",random(100));
set_exp(15);
  set_property("swarm",1);
set_wielding_limbs( ({"left hand", "right hand"}) );
  set_emotes(3,({
    "%^MAGENTA%^Bather says: %^RESET%^Sure is relaxing to come to the baths.",
   "%^MAGENTA%^Bather says: %^RESET%^Soaks the care of the world away don't it?",
  "Bather sinks down deeper in the water and seems completely carefree.",
    "Bather glances your way but avoids staring.",
  }));
}
