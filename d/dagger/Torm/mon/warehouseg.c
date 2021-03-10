#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/d/dagger/Torm/mon/dayperson.c";
create(){
::create();
  set_name("warehouse guard");
  set_id(({ "guard","warehouse guard" }));
  set_short( "Warehouse guard"  );
  set_long(
  "  This large burly man looks you over with suspicion evident in his eyes."
  "  He stands ready with his sword but doesn't make any move to attack, still determining if you are a thief or have a reason to be here."
  );
  set_race("human");
  set_gender("male");
set_body_type("human");
  set_hd(20,1);
  set_max_hp(160);
  set_hp(160);
  set_overall_ac(2);
set_size(2);
  set_class("fighter");
  set_property("full attacks",1);
  set_mlevel("fighter",20);
  set_stats("strength",19);
set_stats("intelligence",7);
set_stats("dexterity",9);
set_stats("charisma",7);
set_stats("constitution",11);
set_stats("wisdom",8);
  set_exp(1000);
set_wielding_limbs( ({"left hand", "right hand"}) );
  new("/d/common/obj/armour/scale.c")->move(TO);
  new("/d/common/obj/armour/mshield.c")->move(TO);
  new(OBJ+"scimitar.c")->move(TO);
  command("wearall");
  command("wield scimitar");
  set_money("gold",random(50));
}
