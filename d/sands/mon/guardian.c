#include <std.h>
inherit MONSTER;

void create() {
  ::create();
  set_name("guardian");
  set_id(({ "demon", "guardian" }));
  set_short("A Demonic Guardian");
  set_long(
"This monstrosity stands guard over the gateway. He looks like something\n"+
"you would not want to meet under ANY circumstances.");
  set_race("demon");
  set_class("mage");
  set_stats("strength", 18);
  set_stats("constitution", 16);
  set_stats("dexterity", 10);
  set_stats("intelligence", 18);
  set_stats("wisdom", 12);
  set_stats("charisma", 8);
  set_body_type("demon");
  set_level(30);
  set_hp(100+random(100));
  set_max_mp(query_hp());
  set_mp(query_hp());
  set_max_sp(query_hp());
  set_sp(query_hp());
  set_max_hp(query_hp());
  set_spells(({ "magic missile", "armor", "fireball", "scorcher", "lightning bolt", "burning hands" }));
  set_spell_chance(35);
  set_gender("male");
  set_wielding_limbs(({ "right hand", "left hand" }));
  set_ac(1);
  set_exp(10000+random(1000));
  add_money("platinum", random(100));
  new("/d/sands/obj/staff")->move(this_object());
  command("wield staff in left hand");
}
