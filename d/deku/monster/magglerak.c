//added random weapons w/chance of being magical & fixed her spells Styx 7/29/01

#include <std.h>
#include "/d/common/common.h"

inherit MONSTER;

void create() {
  ::create();
  set_name("magglerak");
  set_id(({"magglerak","hag","seahag","sister"}));
  set("race","human");
  set_gender("female");
  set("short","Magglerak, the seahag");
  set("long","Like her sisters, Magglerak is so ghastly looking, when\n"+
                 "looked upon by her, any creature becomes weak with fright.");
  set_hd(8,1);
  set_level(8);
  set_body_type("human");
  set_class("mage");
  set_mlevel("mage", 10);
  set_guild_level("mage",10);
  set("aggressive", 30);
  set_alignment(8);
  set_size(2);
  set_stats("intelligence",18);
  set_stats("wisdom",13);
  set_stats("strength",9);
  set_stats("charisma",1);
  set_stats("dexterity",9);
  set_stats("constitution",10);
  set_overall_ac(4);
  set_hp(87);
  set_max_hp(query_hp());  
  set_wielding_limbs(({"left hand", "right hand"}));
  new("/d/common/obj/misc/sack")->move(TO);
  set_wimpy(5);
  set_wimpydir("dive");
  set_emotes(2,({"Magglerak screeches: %^RED%^You will pay foolish mortal!"}), 1);
  add_money("gold",random(200));
  set_exp(1000);
  set_spells(({"magic missile","acid arrow","magic missile","lightning bolt"}));
  set_spell_chance(65);
  RANDGEAR->arm_me(TO, "edgeds", 10, random(3));
}
