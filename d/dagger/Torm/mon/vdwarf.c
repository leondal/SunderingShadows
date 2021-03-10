#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/d/dagger/Torm/mon/dayperson.c";

create(){
  ::create();
  set_name("Dwarven traveler");
  set_id(({ "dayperson", "dwarf","dwarven traveler","traveler" }));
  set_short( "Dwarven traveler" );
  set_long(
  "  This stout dwarf wanders the bazaar here keeping out from underfoot as much as possible."
  "  Just like all the others here he seems to be keeping his eye out for something."
  );
  set_race("dwarf");
  set_gender("male");
set_body_type("human");
  set_hd(10,1);
  set_max_hp(75);
  set_hp(75);
set_overall_ac(8);
  set_size(1);
set_stats("strength",12);
set_stats("intelligence",7);
set_stats("dexterity",9);
set_stats("charisma",7);
set_stats("constitution",11);
set_stats("wisdom",8);
  set_money("gold",random(50));
  set_exp(200);
set_wielding_limbs( ({"left hand", "right hand"}) );
}
