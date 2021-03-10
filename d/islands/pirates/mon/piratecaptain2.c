#include <std.h>
#include "../piratedefs.h"
inherit MONSTER;

object equip;

void create (){
   ::create();
   set_name("pirate captain");
   set_id(({"pirate","captain eyris","captain","eyris"}));
   set_short("Captain Eyris");
   set_long("This half-elven man is surprisingly slender, though he moves with obvious precision in every "
"action.  He is quite well dressed for a pirate, in a striking blue coat, and carries an ornate cutlass at "
"his side.  Despite his halfblooded heritage, he seems in quite good standing with the rest of the pirates "
"on the ship; considering the very air of command that he holds with him, it's not so surprising.");
   set_race("half-elf");
   set_gender("male");
   set_body_type("human");
   set_hd(35,5);
   set_size(2);
   set_max_hp(350);
   set_hp(350);
   set_exp(8000);
   set_stats("strength",18);
   set_stats("intelligence",10);
   set_stats("wisdom",12);
   set_stats("dexterity",17);
   set_stats("constitution",15);
   set_stats("charisma",6);
   set_overall_ac(-4);
   set_mlevel("fighter",25);
   set_guild_level("fighter",25);
   set_wielding_limbs(({"left hand","right hand"}));
   equip = new(OBJ"cutlass");
     if(random(2)) equip->set_property("monsterweapon",1);
     equip->move(TO);
     command("wield cutlass");
   equip = new(OBJ"longdagger");
     equip->set_property("monsterweapon",1);
     equip->set_property("enchantment",1);
     equip->move(TO);
     command("wield dagger");
   equip = new(OBJ"newcoat");
     if(random(3)) equip->set_property("monsterweapon",1);
     equip->move(TO);
     command("wear coat");
   set_funcs(({"slash","slash","rushem","flashem","flashem"}));
   set_func_chance(30);
   set("aggressive",3);
   set_property("swarm",1);
   add_money("silver", random(300)+100);
   add_money("copper", random(30)+10);
   set_mob_magic_resistance("average");
}

int agg_fun() {
   if (TP->query_invis() && !TP->query_true_invis()) TP->set_invis(0);
   if (sizeof(TO->query_attackers()) < 1) force_me("say Begone from me ship, ye landlubbin' invader!");
   force_me("kill "+TP->query_name());
}

void slash(object targ){
  tell_object(targ,"%^BOLD%^%^MAGENTA%^The captain leaps forward in a riposte immediately following your attack, giving you no chance to deflect the blow!%^RESET%^");
  tell_room(environment(targ),"%^BOLD%^%^BLUE%^The captain leaps forward in a riposte immediately following "
+targ->QCN+"'s attack, giving "+targ->QO+" no chance to deflect the blow!%^RESET%^",targ);
  targ->do_damage("torso",random(15)+20);
}

void rushem(object targ){
  command("rush "+targ->query_cap_name());
}

void flashem(object targ){
  command("flash "+targ->query_cap_name());
}
