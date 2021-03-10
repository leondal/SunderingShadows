//Added set_max_level to retard cycling - Octothorpe 6/4/09
//native.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit MONSTER;

int blah;
void create()
{
object ob;
  ::create();
  set_name("Jungle native");
  set_id(({"native","Native","doctor","witch"}));
  set_short("Jungle native witch doctor");
  set_long(
@OLI
    This smallish man stands before. An occasional screach of anger 
eminate from his mishapened mouth. Distrust and fear cross his face.
This is quite obviously his home and his place to live. He will defend
it from intruders with his life. He wears a form of cloth decorated with
varius colored leaves. A dim fire burns in his eyes magic practiced often
from primitve sources have turned him to a partially magic being.
OLI
          );
  
  set_class("mage");
  set_race("human");
  set_body_type("human");
  set_gender("male");
  set_hd(15+random(10),8);
  set_mlevel("mage",query_hd());
  set_guild_level("mage",query_hd());
  set_hp(roll_dice(query_hd(),10));
  set_overall_ac(4);
  set_exp(400*query_hd());
  set_new_exp(25,"boss");
set_max_level(25);
  set_wielding_limbs(({"right hand","left hand"}));
 
  set_property("full attacks",1);
  set_scrambling(1);
  set_property("swarm",1);
  set_spell_chance(99);
  set_spells(({"magic missile","lightning bolt","prismatic spray","dispel magic"}));
  set_property("add kits",25);
      ob = new("/d/common/obj/potion/legendary_heal");
       ob->move(TO);
       ob->set_uses(random(20)+10);
       ob->set_property("monsterweapon",1);

}

void heart_beat(){
	::heart_beat();
	
	if(!blah){
//     tell_room(ETO,"%^BOLD%^%^BLUE%^Debugging message: specialty dispel cast by heartbeat.%^RESET%^");
                new("/cmds/spells/d/_dispel_magic")->use_spell(TO,0,28,100,"mage");
		blah = 21;
	}
	blah--;
}

