#include <std.h>
#include "../piratedefs.h"
inherit MONSTER;

object equipment;

void create(){
   ::create();
   set_name("pirate");
   set_id(({"pirate","lookout","pirate lookout"}));
   set_short("Pirate lookout");
   set_long("This wiry little man is as rough-looking as the rest of the pirates on the ship, but hardly as "
"well built.  He probably has to climb all the way up here each day, which might account for his dour "
"expression.  He seems particularly alert, constantly watching around for signs of trouble.  He carries a "
"sturdy crossbow in his hands, and he looks quite able to use it.");
   set_race("half-elf");
   set_gender("male");
   set_body_type("human");
   set_hd(20,1);
   set_size(2);
   set_wielding_limbs(({"right hand","left hand"}));
   set_max_hp(200);  
   set_hp(200);
   set_exp(5000);
   set_overall_ac(0);
   set_stats("strength",16);
   set_stats("intelligence",10);
   set_stats("wisdom",10);
   set_stats("dexterity",18);
   set_stats("constitution",16);
   set("aggressive",25);
   set_mlevel("fighter",20);
   set_class("fighter");
   set_guild_level("fighter",20);
   set_class("thief");
   set_mlevel("thief",22);
   set_guild_level("thief",22);
   set_property("full attacks",1);
   set_property("swarm",1);
   add_search_path("/cmds/thief");
   equipment = new(OBJ"crossbow");
     if(random(2)) equipment->set_property("monsterweapon",1);
     equipment->move(TO);
     command("wield crossbow");
   new("/d/common/obj/lrweapon/hquarrels")->move(TO);
   equipment = new("/d/common/obj/armour/leather");
     if(random(2)) equipment->set_property("monsterweapon",1);
     equipment->set_property("enchantment",random(2)+1);
     equipment->move(TO);
     command("wear leather");
   add_money("silver", random(400)+100);
   add_money("copper", random(50)+20);
   set_scrambling(1);
   set_mob_magic_resistance("average");
}
