#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/d/dagger/Torm/mon/dayperson.c";
create(){
::create();
  set_name("native");
  set_id(({ "dayperson", "native","painted native","native visitor" }));
  set_short( "Native Visitor"  );
  set_long(
  "  This short angry looking native doesn't seem well at ease in the market place here in Torm."
   "  You wonder what would bring him so far from his jungle island but seeing him snarl at you as he sees you watching makes it doubtful he'd care to tell."
  );
  set_race("human");
  set_gender("male");
set_body_type("human");
   set_hd(20,14);
   set_hp(200+random(280));
  set_overall_ac(0);
set_size(2);
  set_stats("strength",18);
set_stats("intelligence",7);
set_stats("dexterity",9);
set_stats("charisma",7);
set_stats("constitution",11);
set_stats("wisdom",8);
  set_money("gold",random(100));
  set_exp(1000);
set("aggressive",5);
set_wielding_limbs( ({"left hand", "right hand"}) );
  new("/d/islands/tonerra/obj/spear1.c")->move(TO);
  command("wield spear");
  new("/d/islands/tonerra/obj/spear1.c")->move(TO);
  command("wield spear");
  new("/d/islands/tonerra/obj/hide.c")->move(TO);
  present("woven",TO)->remove_property("enchantment");
  command("wear woven");
}
