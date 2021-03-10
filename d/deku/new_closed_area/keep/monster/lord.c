#include <std.h>
#include "/d/common/common.h"

inherit "/std/monster";

void create() {
  ::create();
  set_name("Lord Hawk");
  set_id(({"lord","lord hawk"}));
  set_gender("male");
  set("race","ogre-mage");
  set("short","Lord Hawk, master of Keep Blacktongue");
  set("long","Lord Hawk is the master of Keep Blacktongue.  He is a true "
      "master of darkness.  He calls upon his evil magic to destroy all who "
      "disturb him in his work.  He has light green skin, black fingernails, "
      "and small white horns on his head.");
  set_level(15);
  set_body_type("human");
  set_class("mage");
  set_mlevel("mage", 10);
  set("aggressive",20);
  set_alignment(9);
  set_size(3);
  set_hd(15,2);
  set_overall_ac(0);
  set_exp(1500);
  set_stats("intelligence",19);
  set_stats("wisdom",14);
  set_stats("strength",17);
  set_stats("charisma",10);
  set_stats("dexterity",10);
  set_stats("constitution",14);
  set_max_sp(100);
  set_sp(100);
  set_hp(82);
  set_wielding_limbs(({"right hand","left hand"}));
  switch(random(3)) {
    case 0:  RANDGEAR->arm_me(TO, "edgedl", 15, 1);
             break;
    case 1:  RANDGEAR->arm_me(TO, "bluntm", 15, 1);
             break;
    case 2:  RANDGEAR->arm_me(TO, "edgedm", 15, random(3));
             break;
  }
  if(!random(5)) {
  new("/d/deku/weapons/dagger2")->move(TO);
  command("wield dagger");
  }
  set_spell_chance(90);
  set_spells(({"magic missile","hideous laughter","monster summoning ii", "fireball"}));
  set_mp(200);
  set_guild_level("mage", 8);
  if(random(3)) new("/d/shadow/obj/clothing/silkrobe")->move(TO);
  command("wear robe");
  set_max_level(15);
}
