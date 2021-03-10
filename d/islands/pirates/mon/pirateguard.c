#include <std.h>
#include "../piratedefs.h"
inherit MONSTER;

object equip;

void create(){
   ::create();
   set_name("pirate");
   set_id(({"pirate","buccaneer","guard"}));
   set_short("A Pirate guard");
   set_long("The pirate guard is a rough-looking sort, pacing back and forth as though waiting for a fight.  "
"He's wearing a heavy leather cloak and tough leather leggings that extend to his boots.  The way he holds "
"his weapons suggests he knows quite well how to use them.");
   switch(random(10)) {
     case 0..4:
     set_race("human");
     set_size(2);
     break;
     case 5..7:
     set_race("half-elf");
     set_size(2);
     break;
     case 8:
     set_race("halfling");
     set_size(1);
     break;
     case 9:
     set_race("half-orc");
     set_size(2);
     break;
   }
   set_gender("male");
   set_body_type("human");
   set_hd(15,1);
   set_wielding_limbs(({"right hand", "left hand"}));
   set_stats("strength",17);
   set_stats("intelligence",10);
   set_stats("wisdom",10);
   set_stats("dexterity",18);
   set_stats("constitution",15);
   set_stats("charisma",10);
   set("aggressive",3);
   set_class("thief");
   set_mlevel("thief",18);
   set_guild_level("thief",18);
   set_hp(140);
   set_max_hp(140);
   set_property("full attacks",1);
   add_search_path("/cmds/thief");
   set_thief_skill("move silently",100);
   set_thief_skill("hide in shadows",100);
   set_thief_skill("pick pockets",100);
   set_scrambling(1);
   set_overall_ac(-1);
   set_property("swarm",1);
   add_money("silver", random(100)+50);
   equip = new(OBJ"longdagger");
   equip->move(TO);
   equip->set_property("enchantment",random(3));
   if(random(3)) equip->set_property("monsterweapon",1);
   command("wield dagger");
   equip = new("/d/common/obj/weapon/shortsword");
   equip->move(TO);
   equip->set_property("enchantment",random(3));
   if(random(3)) equip->set_property("monsterweapon",1);
   command("wield sword");
   set_funcs(({"stabit"}));
   set_func_chance(50);
   set_exp(1500);
   toggle_steal();
}

void stabit(object target) {
   force_me("stab "+target->query_name());
}
