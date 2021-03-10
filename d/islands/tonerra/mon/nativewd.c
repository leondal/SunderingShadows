//Added set_max_level to retard cycling - Octothorpe 6/4/09
//The true native Witch doctor

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"
inherit MONSTER;

void hurtthem();

void create(){
   ::create();

   set_name("Witch Doctor Leader");
   set_id(({"native","witch","witch doctor","doctor","supreme"}));
   set_short("Witch Doctor Supreme");
   set_long(
@OLI
   This strange looking person is in fact the spiritual leader
of the natives. Second only to the king he leads them in their
worship of the fires that fall from the sky. His painted skin
shines from where his miriad of burns have scared over. This
one loves to play with fire.
OLI
   );
   set_mob_magic_resistance("average");
   set_monster_feats(({
      "toughness",
      "improved toughness",
      "damage resistance",
      "improved damage resistance",
      "regeneration",
      "rush",
      "sweepingblow",
      "blade block",
      "impale",
      "light weapon",
      "strength of arm",
      "knockdown",
      "powerattack",
      "expertise",
   }));
   set_hd(35,8);
   set_wielding_limbs(({"right hand","left hand"}));
   set_hp(350);
   set_race("human");
   set_body_type("human");
   set_class("mage");
   set_class("cleric");
   set_mlevel("mage",35);
   set_mlevel("cleric",35);
   set_guild_level("mage",35);
   set_guild_level("cleric",35);
   set_spells(({"limb attack","magic missile","power word stun","scorcher","fireball","firestorm"}));
   set_spell_chance(65);
   set_exp(15000);
   set_new_exp(25,"boss");
set_max_level(25);
   set_gender("male");
   set_race("human");
   new(OBJ+"wstaff")->move(TO);
   command("wield staff");
  new(OBJ+"Lcloak.c")->move(TO);
  command("wear cloak");
   set_overall_ac(-5);
   set_property("swarm",1);
//   new(OBJ+"wmask")->move(TO);
//   command("wear mask");
     remove_class("fighter");
   set_property("add kits",15);
/*
      ob = new("/d/common/obj/potion/legendary_heal");
       ob->move(TO);
   ob->set_uses(2);
       ob->set_property("monsterweapon",1);
*/
}


int kill_ob(object victim, int which){
   int hold;

   hold = ::kill_ob(victim,which);

   if(!present("devicex999"))
        hurtthem();
   return hold;
}

void hurtthem(){

   int i= 10;

   if(!present("guard",ETO)){
      tell_room(ETO,"The witch doctor summons a guard.");
      new(MON+"nativeG")->move(ETO);
   }
   while(!present("spear "+i,TO)){
      i--;
new("/d/common/obj/weapon/mspear.c")->move(TO);

   }
   for(i=0;i<10;i++){

   command("give spear to guard");
   }
   new("/cmds/spells/a/_animate_object")->use_spell(TO,"guard",45,100,"cleric");
}

void heart_beat(){
   object *stuff;
   int i,j;
   ::heart_beat();
   if(!objectp(TO)) return;
   stuff = TO->query_attackers();
   j = sizeof(stuff);
   for(i=0;i<j;i++){
      if(objectp(stuff)){
	 command("command objects to kill "+stuff[i]->query_name());
      }
   }
}

int query_watched(){return 80;}
