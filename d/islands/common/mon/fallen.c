// updated weapon resistance to 5, from 15 - was obscenely high
// Nienne, 01/07
#include <std.h>
inherit MONSTER;
#include <daemons.h>
object *attackers;
void create() {
    ::create();
    set_name("warrior");
    set_id(({"clay warrior","clay","warrior"}));
    set_short("%^BOLD%^%^BLACK%^Clay Warrior");
    set_long("
    This humanoid figure is formed from hot black clay.
");
    set_race("clayman");
    set_body_type("human");
    set_gender("male");
    set_hd(25,10);
    set_size(2);
    set_overall_ac(-6);
    set_class("fighter");
    set_guild_level("fighter",45);
    set_max_hp(query_hp());
   set_hp(75);
   set_max_hp(75);
    set_wielding_limbs(({"right hand"}));
    set_body_type("humanoid");
    set_property("swarm",1);
    set_property("full attacks",1);
    set_property("no bump",1);
    set_property("no death",1);
    set_stats("strength",25);
    set_stats("dexterity",16);
    set_stats("constitution",17);
    set("aggressive",22);
	add_search_path("/cmds/fighter");
    set_property("weapon resistance", 5);
    set_exp(90000);
    set_alignment(9);
    new("/d/attaya/obj/rusts.c")->move(TO);
    command("wear shield");
    new("/d/attaya/obj/rustb.c")->move(this_object());
    command("wield sword");
   set_monster_feats(({
      "shieldbash",
	  "shieldwall",
	  "deflection",
	  "counter",
	  "knockdown"
	  "powerattack",
	  "shatter",
	  "sunder",
	  "rush"	  
   }));
   set_func_chance(100);
   set_funcs(({"rushit","flashit","bashit","kdit"}));   
	   
}
void heart_beat(){
    ::heart_beat();
    if(!objectp(TO)) return;
   if(query_attackers() == ({})){
      ::die();
  }
}

void bashit(object targ){
   if(!objectp(TO)) return;
   if(!objectp(targ)) return;
   TO->force_me("shieldbash "+targ->query_name());
}

void kdit(object targ){
   if(!objectp(TO)) return;
   if(!objectp(targ)) return;
   TO->force_me("knockdown "+targ->query_name());
}

void rushit(object targ){
   if(!objectp(TO)) return;
   if(!objectp(targ)) return;
   TO->force_me("rush "+targ->query_name());
}

void flashit(object targ){
   if(!objectp(TO)) return;
   if(!objectp(targ)) return;
   TO->force_me("flash "+targ->query_name());
}
