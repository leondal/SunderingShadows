#include <std.h>
#include "../piratedefs.h"
inherit MONSTER;

object equipment;

void create(){
   ::create();
   set_name("pirate");
   set_id(({"pirate","wizard","ship wizard","ship's wizard"}));
   set_short("Ship's wizard");
   set_long("The man before you is somewhat older than the other pirates on the ship.  Despite this, they "
"all seem to give him a wide radius, though you can't tell whether it's from respect or fear.  He carefully "
"watches the ship around him, occasionally checking the pockets of his dark robes to ensure whatever's in "
"them hasn't gone missing.");
   set_race("half-elf");
   set_gender("male");
   set_body_type("human");
   set_hd(20,1);
   set_size(2);
   set_max_hp(175);  
   set_hp(175);
   set_exp(5000);
   set_overall_ac(2);
   set_stats("intelligence",19);
   set_stats("strength",10);
   set_stats("constitution",10);
   set_stats("dexterity",16);
   set_stats("wisdom",16);
   set("aggressive","agg_fun");
   set_class("mage");
   set_mlevel("mage",18);
   set_guild_level("mage",18);
   set_property("swarm",1);
   add_search_path("/cmds/wizard");
   equipment = new(OBJ"boa");
     if(!random(3)) equipment->set_property("monsterweapon",1);
     equipment->move(TO);
     command("wear bracers");
   equipment = new("/d/tharis/obj/black_robes");
     equipment->set_property("monsterweapon",1);
     equipment->move(TO);
     command("wear robes");
   equipment = new(OBJ"goldring");
     if(!random(3)) equipment->set_property("monsterweapon",1);
     equipment->move(TO);
     command("wear ring");
   add_money("silver", random(400)+100);
   add_money("copper", random(50)+20);
   set_funcs(({"rocktheboat"}));
   set_func_chance(20);
   TO->set_blinking(1);
   set_spells(({"hideous laughter","lightning bolt","cone of cold","fireball","fireball","monster summoning iii"}));
   set_spell_chance(70);
   set_mob_magic_resistance("average");
}

int agg_fun() {
   if (TP->query_invis() && !TP->query_true_invis()) {
       force_me("emoteat "+TPQN+ " $M turns, his gaze seeing straight through $np concealment.");
       TP->set_invis(0);
   }
   if (sizeof(TO->query_attackers()) < 1) {
     force_me("say Ye've come too far, now ye' must pay!");
     new("/cmds/spells/d/_dispel_magic")->use_spell(TO,0,14,100,"mage");
     new("/cmds/spells/w/_wall_of_fire")->use_spell(TO,0,18,100,"mage");
   }
   force_me("kill "+TP->query_name());
}

void rocktheboat(object target) {
   object *inven;
   int i;
   inven = all_inventory(ETO);
   for(i = 0;i < sizeof(inven); i++) {
     if(userp(inven[i]) && !avatarp(inven[i])) {
       if((random(20)+6) < inven[i]->query_stats("dexterity")) {
         tell_object(inven[i],"%^GREEN%^%^BOLD%^The boat rocks on the waves and the deck shifts beneath your "
"feet, though you manage to keep your footing.%^RESET%^");
       }
       else {
         tell_object(inven[i],"%^GREEN%^%^BOLD%^The boat rocks on the waves and the deck shifts beneath your "
"feet.  You fail to keep your balance and stumble to the side!%^RESET%^");
         tell_room(ETO,"%^GREEN%^%^BOLD%^"+inven[i]->QCN+" stumbles and loses "+inven[i]->QP+" balance as the "
"boat rocks on the waves.%^RESET%^",inven[i]);
         inven[i]->set_paralyzed((random(4)+1)*2,"You're still trying to regain your balance.");
       }
     }
   }
}
