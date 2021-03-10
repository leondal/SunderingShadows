//added random weapons with chance of being magical  Styx 7/29/01
//the command to put stone in sack/pouch is causing illegal index, no idea
//why atm, so commenting it out for now.  

#include <std.h>
#include "/d/common/common.h"

inherit MONSTER;

void create() {
  ::create();
  set_name("vexia");
  set_id(({"vexia","hag","seahag","sister"}));
  set("race","human");
  set_gender("female");
  set("short","Vexia, the worst seahag");
  set("long","Like her sisters, Vexia is so ghastly looking, when\n"+
               "looked upon by her, any creature weakens with fright.");
  set_level(11);
  set_body_type("human");
  set_class("mage");
  set_guild_level("mage",11);
  set("aggressive", 30);
  set_alignment(8);
  set_size(2);
  set_hd(14,1);
  set_stats("intelligence",18);
  set_stats("wisdom",13);
  set_stats("strength",9);
  set_stats("charisma",1);
  set_stats("dexterity",9);
  set_stats("constitution",10);
  set_hp(114);
  set_exp(1500);
  set_wielding_limbs(({"right hand", "left hand"}));
  new("/d/common/obj/misc/pouch")->move(TO);
  new("/d/deku/misc/black")->move(TO);
  if(!random(5))  new("/d/deku/armours/ring_p.c")->move(TO);
  command("wear ring");
//  command("put stone in pouch");
  set_emotes(3,({"Vexia screeches: %^RED%^You will pay foolish mortal!"}), 1);
  add_money("gold",random(300)+50);
  set_spells(({"acid arrow","hideous laughter","lightning bolt", "blink",
  "magic missile"}));
  set_spell_chance(70);
  RANDGEAR->arm_me(TO, "edgeds", 20, random(3));
}
