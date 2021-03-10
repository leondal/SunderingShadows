//Coded by Lujke
#include <std.h>
#include <daemons.h>
#include <move.h>

#include "../tecqumin.h"
inherit MOB + "orog";


void create()
{
      object ob;
      string * weapons;
      int i;
      ::create();
  	set_name("orog berserker");
  	set_id(({"orog", "humanoid", "orog berserker", "berserker"}));
  	set_short( "raging orog berserker");
      switch (random(2)){
  	case 0:
        set_gender("male");
        break;
      case 1:
        set_gender("female");
      }
      set_long("%^GREEN%^This fearsome orog killing machine has the facial features of an orc; a jutting"
                +" forehead and tusk-like %^RESET%^canine teeth%^GREEN%^, with pointed, wolflike ears"
                +" and a broad snout for a nose. It's eyes glow dully %^RED%^red%^GREEN%^ in the dark."
                +"\n%^GREEN%^Unlike an orc, however, this creature stands nearly 8 feet"
                +" tall and is built like a power lifter, with treetrunk legs, thick waist and barrel"
                +" chest. Its arms, shoulders bulge with muscles, and it has almost neck. It looks"
                +" capable of tearing most foes limb from limb, and probably inclined to do so.");
 
  	set_race("orog");
      set_new_exp(49, "normal");
  	set_body_type("humanoid");
	set_class("barbarian");
	set_mlevel("barbarian",53);
	set_guild_level("barbarian",53);
   	set_hp(random(1500)+800 + random(400));
	set_max_level(49);
	set_property("swarm",1);
      set_alignment(7);
  	set_overall_ac(-67);
      set_size(2);
      add_attack_bonus(70); 
      set_property("magic",1);
      set_monster_feats(({
        "power attack",
        "rush",
        "damage resistance",
        "daze",
        "rage",
        "mighty rage", 
        "unyielding rage",
        "blade block",
        "sweeping blow",
        "impale",
        "wade through",
        "light weapon",
        "strength of arm",
        "resistance",
        "improved resistance",
        "increased resistance",
        "spell reflection",
        "death ward"
      })); 
      set_stats("strength",30);
      set_stats("intelligence",10);
      set_stats("dexterity",30);
      set_stats("charisma",6);
      set_stats("wisdom",20);
  	set_size(3);
  	set("aggressive",(:TO, "aggro_me":));
      set_skill("athletics", 55);
      set_skill("perception", 35);
  	set_alignment(4);
      set_property("full attacks",1);
      weapons =  ({ "/d/common/obj/weapon/giant_bastard.c", 
       "/d/common/obj/weapon/giant_battle_axe.c", "/d/common/obj/weapon/giant_club.c",
       "/d/common/obj/weapon/giant_hammer.c", "/d/common/obj/weapon/giant_mace.c", 
       "/d/common/obj/weapon/giant_morningstar.c" });
      ob = new(weapons[random(sizeof(weapons))]);
      ob->set_property("enchantment", 6);
      if (random(15)>0){
        ob->set_property("monsterweapon",1);
      }
      ob->move(TO);
      force_me("wield weapon");
      entry_method = "teleported magically right to the granary. WOW, that's magic!";
      set_funcs(({"impale", "impale", "sweeping_blow", "sweeping_blow",
                                           "rush", "shatter", "sunder"}));
      set_func_chance(35);
      clinging = 0;
      tell_caught = 0;
      set_skill("athletics", 45);
      set_property("no random treasure", 1);
      BEAT = 0;
      heartcount = 0;
      check_my_heart();
      force_me("rage");
}

void aggro_me(){
  if (!TP->query_true_invis() && !TP->id("orog") && !TP->id("ram")){
    force_me("kill " + TP->query_race());
  }
}

void heart_beat(){
  ::heart_beat();
  if((int)query_property("using rage") < time() && time()%10 ==0){
    force_me("rage on");
  }
}

void sweeping_blow(){
  force_me("sweepingblow");
}

void impale(){
  object * critters;
  string who;
  critters = query_attackers();
  if (sizeof(critters)<1) return;
  who = critters[random(sizeof(critters))]->query_name();
  force_me("impale " + who);
}
