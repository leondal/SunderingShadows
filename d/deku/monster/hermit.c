#include <std.h>
inherit MONSTER;

create() {
  ::create();
  set_name("Old Hermit");
  set_id(({"hermit","oldhermit","old hermit"}));
  set_race("human");
  set_gender("male");
  set_short("Old Hermit");
  set_long("This hermit is the only good within 20 miles.  He is the\n"+
  "guard of the bridge that leads to the Fortress.  He doesn't\n"+
  "let anyone venture to their death.\n");
  set_class("fighter");
  set("aggressive",0);
  set_alignment(1);
  set_size(2);
  set_hd(10,1);
  set_hp(139);
  add_money("gold",200);
  new("/d/common/obj/armour/leather")->move(TO);
  command("wear leather");
  new("/d/common/obj/weapon/shortsword")->move(TO);
  command("wield sword");
  set_overall_ac(5);
}
