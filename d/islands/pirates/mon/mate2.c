#include <std.h>
#include "../piratedefs.h"
inherit MONSTER;

object equipment;

void create(){
   ::create();
   set_name("pirate");
   set_id(({"pirate","ships mate","ship's mate","mate"}));
   set_short("Ship's mate");
   set_long("This man has a hard, emotionless expression as he surveys the ship, obviously keeping a "
"vigilant guard.  He is better dressed than most of the pirates on this ship, probably due to his higher "
"station.  In both of his hands are well-kept weapons, and he looks quite ready to use them at the slightest "
"notice.");
   set_race("human");
   set_gender("male");
   set_body_type("human");
   set_hd(20,1);
   set_size(2);
   set_wielding_limbs(({"right hand","left hand"}));
   set_max_hp(250);  
   set_hp(250);
   set_exp(5000);
   set_overall_ac(2);
   set_stats("strength",19);
   set_stats("intelligence",10);
   set_stats("wisdom",10);
   set_stats("dexterity",16);
   set_stats("constitution",16);
   set("aggressive",25);
   set_mlevel("fighter",22);
   set_class("fighter");
   set_guild_level("fighter",22);
   set_class("thief");
   set_mlevel("thief",23);
   set_guild_level("thief",23);
   set_property("full attacks",1);
   set_property("swarm",1);
   add_search_path("/cmds/thief");
   equipment = new("/d/common/obj/armour/studded");
     equipment->set_property("monsterweapon",1);
     equipment->set_property("enchantment",2);
     equipment->move(TO);
     command("wear studded");
   equipment = new("/d/deku/sanctuary/obj/armguard");
     if(random(2)) equipment->set_property("monsterweapon",1);
     equipment->move(TO);
     command("wear armguard");
   equipment = new(OBJ"cutlass");
     if(!random(3)) equipment->set_property("monsterweapon",1);
     equipment->move(TO);
     command("wield cutlass");
   add_money("silver", random(400)+100);
   add_money("copper", random(50)+20);
   set_scrambling(1);
   set_mob_magic_resistance("average");
}
