#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/d/dagger/Torm/mon/dayperson.c";

create(){
  ::create();
  set_name("barbarian");
  set_id(({ "dayperson", "barbarian" }));
  set_emotes(3,({ "The barbarian grips his axe a little tighter and doesn't "
     "say a word as he stares you in the eye." }));
  set_short( "Northern barbarian" );
  set_long(
  "  This huge blonde burly human wanders the bazaar with an eye out for something."
   "  A huge bearskin hangs from his shoulders and a great axe is wielded like a simple twig in his hands."
   "  There are a few tatoos on his arms that you can see, but you're unable to tell what tribe he might possibly belong to."
  );
  set_race("human");
  set_gender("male");
set_body_type("human");
  set_hd(20,1);
  set_max_hp(200);
  set_hp(200);
  set_overall_ac(-2);
set_size(2);
  set_stats("strength",19);
set_stats("intelligence",7);
set_stats("dexterity",9);
set_stats("charisma",7);
set_stats("constitution",11);
set_stats("wisdom",8);
set_money("silver",random(100));
  set_exp(1000);
set_wielding_limbs( ({"left hand", "right hand"}) );
  new(OBJ+"waraxe.c")->move(TO);
  new(OBJ+"furcloak.c")->move(TO);
  command("wearall");
  command("wield axe");
}
