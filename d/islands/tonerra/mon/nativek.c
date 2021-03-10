//Added set_max_level to retard cycling - Octothorpe 6/4/09
// Native king of tonerra

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit MONSTER;

int count;
object *stuff;

void create(){
      ::create();

      set_name("Native king");
      set_id(({"king","King","native","Native","native king"}));
      set_short("Native King");
      set_long(
@OLI
   This is a very small man. He has a round, bulging tummy.
He wears a scruffy beard and his head is shaved. From his short
legs hang rolls of fat. the king waddles when he walks. But he
is the king, he commands the natives and they obey.
OLI
   );
      set_wielding_limbs(({"right hand","left hand"}));
      set_hd(35,12);
      set_hp(450);
      set_race("human");
      set_gender("male");
      set_body_type("human");
      set_scrambling(1);
      set_thief_skill("move silently",95);
      set_thief_skill("hide in shadows",95);
      set_overall_ac(-1);
set_property("magic", 1);
      set_property("swarm",1);
      set_property("full attacks",1);
      set_class("fighter");
      set_class("thief");
      set_class("mage");
      set_mlevel("fighter",25);
      set_mlevel("thief",28);
      set_mlevel("mage",21);
      set_guild_level("mage",21);
      set_exp(45000);
      set_new_exp(35,"boss");
set_max_level(25);
      add_search_path("/cmds/thief");
      add_search_path("/cmds/fighter");
      set_size(1);
    new(OBJ+"gem")->move(TO);
       new(OBJ+"gem")->move(TO); 
   new(OBJ+"gem")->move(TO); 
   new(OBJ+"gpouch")->move(TO);
    command("put gem in pouch");
    command("put gem in pouch");
    command("put gem in pouch");
   command("wear pouch");
      new(OBJ+"forgedShort")->move(TO);
      command("wield sword");
      new(OBJ+"hide")->move(TO);
      command("wear armor");
      new(OBJ+"Lcloak")->move(TO);
      command("wear cloak");
      set_mob_magic_resistance("average");
      set_spells(({"magic missile","lightning bolt","fireball","vampiric touch"}));
      set_spell_chance(65);
      //set_wimpy(30);
      call_out("doit",1);
      stuff = ({});

}

void doit(){
   if(objectp(ETO))
   new("/cmds/spells/s/_stoneskin")->use_spell(TO,"native king",45,100,"mage");
}

void run_away(){
   ETO->init();
   ::run_away();
}

int query_watched(){
     return 80;
}

int kill_ob(object victim,int which){
   int hold;

   if(member_array(victim, query_attackers()) == -1 && member_array(victim, stuff) == -1)
      call_out("script",1,victim, 1);
   hold = ::kill_ob(victim,which);
   return hold;
}

void script(object targ,int stage){

// Code added to prevent more bugs showing up in debug.log. :P
  if (!objectp(targ)) return;

   switch (stage) {
   case 1:
      stuff += ({targ});
//      cease_all_attacks();
//      targ->cease_all_attacks();
//      command("stab "+targ->query_name());
    "/cmds/mortal/_stab"->do_stab(TO,targ);
      break;
   case 2:
      command("rush "+targ->query_name());
      break;
   case	3:
      new("/cmds/spells/p/_prismatic_spray")->use_spell(TO, targ->query_name(),30,100,"mage");
      break;
   case 4:
      new("/cmds/spells/m/_monster_summoning_vii")->use_spell(TO,0,30,100,"mage");
      break;
   }
   if(stage < 4)
      call_out("script",5,targ,++stage);

}


void heart_beat(){
   ::heart_beat();
   if(objectp(TO) && !count){
   	 count = 5;
   	 add_hp(2);
   }
   count--;
}

