#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/d/dagger/Torm/mon/dayperson.c";

create(){
::create();
  set_name("elf traveler");
  set_id(({ "elf","traveling elf","elf scholar", "dayperson" }));
  set_short( "Elf scholar" );
  set_long(
  "  This wise looking elf is here searching out some bit of news or an update on events from the library here in Torm."
  );
  set_race("elf");
  set_gender("male");
set_body_type("human");
  set_hd(5,4);
set_max_hp(25);
set_hp(25);
set_overall_ac(10);
set_size(2);
set_stats("strength",12);
set_stats("intelligence",7);
set_stats("dexterity",9);
set_stats("charisma",7);
set_stats("constitution",11);
set_stats("wisdom",8);
set_money("silver",random(10));
set_exp(15);
set("aggressive",5);
set_wielding_limbs( ({"left hand", "right hand"}) );
}
