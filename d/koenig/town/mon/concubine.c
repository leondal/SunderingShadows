//added random weapons with chance of being magical  Styx 7/29/01

#include <std.h>
#include "/d/common/common.h"

inherit MONSTER;

// void ecstasy(object targ);

void create() {
  ::create();
  set_name("concubine");
  set_id( ({"concubine"}) );
  set_short("%^RESET%^%^CYAN%^A concubine of the snakeman");
   set_long("Upon entering, the concubine whirls about to meet you. Her eyes are slitted, %^BOLD%^%^GREEN%^green%^RESET%^ and hypnotic. Her %^RED%^tongue%^RESET%^ slithers between her lips to reveal that it's forked, like that of a snake. Her body appears to be otherwise human and very beautiful! In a soft %^BOLD%^hissing voice%^RESET%^ she tells you: %^RESET%^%^CYAN%^You were foolish to come here, stranger. Now my lover and I shall feast upon your flesh and drink your blood!%^RESET%^");
  new("/d/common/obj/potion/paralyze.c")->move(TO);
  set_race("concubine");
  set_body_type("human");
  add_limb("mouth", "head", 20, 20, 10);
  set_wielding_limbs( ({"mouth", "right hand", "left hand"}) );
  set_gender("female");
  set_hd(10,2);
  set_max_hp(86);
  set_hp(86);
  set_overall_ac(4);
  set_size(2);
  set_stats("strength", 16);
  set_stats("constitution", 14);
  set_stats("dexterity", 18);
  set_stats("wisdom", 15);
  set_stats("intelligence", 16);
  set_stats("charisma", 20);
  new("/d/koenig/town/mon/weapons/fangs2.c")->move(TO);
  command("wield fangs in mouth");
  add_money("gold", random(200)+50);
  set_new_exp(12, "normal");
  RANDGEAR->arm_me(TO, "edgedm", 40, random(3));
  RANDGEAR->armor_me(TO, "shield", 20, 1, 30);
  set_funcs( ({"ecstasy"}) );
  set_func_chance(50);
  set("aggressive",19);
}

void ecstasy(object targ) {
  if(!targ) return 0;
  tell_room(environment(targ), "%^CYAN%^The Concubine gives "+targ->query_cap_name()+" a taste of ecstasy through her kiss! They are now paralyzed!!\n", targ);
  targ->set_paralyzed(random(10),"%^BOLD%^%^RED%^The Concubine gives you a kiss of ecstasy and you find yourself paralyzed!");
  return 1;
}
