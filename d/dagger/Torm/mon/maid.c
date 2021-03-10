#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/std/monster";

create(){
  ::create();
  set_name("maid");
  set_id(({ "maid","servant" }));
  set_long(
  "  This tall human lass appears to be hard at work avoiding work."
   "  She's got definite redeeming qualities to whoever must have employed her though and she's quite happy to be flaunting them in her less than modest outfit."
   "  Thick black hair spills down her back and she has unusual %^YELLOW%^yellow%^RESET%^%^CYAN%^ eyes that twinkle with mischief."
  );
  set_short("maid" );
  set_race("human");
  set_gender("female");
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
set("aggressive",5);
set_wielding_limbs( ({"left hand", "right hand"}) );
  new("/d/dagger/Torm/obj/duster.c")->move(TO);
  new("/d/dagger/Torm/obj/maids.c")->move(TO);
   present("maids uniform",TO)->set_property("monsterweapon",1);
  command("wearall");
  command("wield duster");
}
