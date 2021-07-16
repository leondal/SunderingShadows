//Hijacked March 31, 2011 by Ergo for Squire's Trial
//changes made to fix errors in call out.  Circe 9/20/03 - there was no valid target
#include <std.h>
#include "../squires_trial.h"
inherit MONSTER;

void stab_em(object targ);
object equipment;

void create(){
  ::create();
  set_name("shadow monster");
  set_id(({"shadow","monster","shadow monster","devil"}));
  set_short("%^BOLD%^%^BLACK%^Shadow Monster%^RESET%^");
  set_long("%^BOLD%^%^BLACK%^Black as "+
	"night, this large creature appears as if is is "+
	"composed of pure darkness."+
	"  Violent %^BOLD%^%^RED%^red %^BOLD%^%^BLACK%^eyes shine "+
	"from the darkness, filled with %^BOLD%^%^RED%^hatred %^BOLD%^%^BLACK%^"+
	"and %^BOLD%^%^GREEN%^malice%^BOLD%^%^BLACK%^.  A jagged"+
	" mouth glows %^BOLD%^%^RED%^red %^BOLD%^%^BLACK%^as the creature sneers. "+
	" Wearing a %^BOLD%^%^RED%^red %^BOLD%^%^BLACK%^spiked suit of leather, the"+
	" creature has a devilish appearance to it.  Shimmering %^BOLD%^%^GREEN%^" +
	"v%^BOLD%^%^BLACK%^e%^BOLD%^%^GREEN%^i" +
	"%^BOLD%^%^BLACK%^n%^BOLD%^%^GREEN%^s %^BOLD%^%^BLACK%^lace " +
	"intricately, showing through its dark form.  It's huge hands"+
	" grip the blades of two weapons as it steps forth from the "+
	"darkness, ready to inflict harm.%^RESET%^");       
  set_race("devil");
  set_gender("male");
  set_body_type("human");
  set_hd(20,1);
  set_size(2);
  set_wielding_limbs( ({ "right hand", "left hand" }) );
  set_max_hp(500);  
  set_hp(500);
//  set_exp(14000);
  set_stats("strength",16);
  set_stats("intelligence",10);
  set_stats("wisdom",10);
  set_stats("dexterity",24);
  set_stats("constitution",18);
  set_stats("charisma",10);
  set_alignment(3);
  set_hidden(1);
  set("aggressive","agg_func");
  set_class("thief");
  set_mlevel("fighter",20);
  set_guild_level("fighter",20);
  set_mlevel("thief",20);
  set_guild_level("thief",20);
  set_property("full attacks",1);
  add_search_path("/cmds/thief");
  set_thief_skill("move silently",120);
  set_thief_skill("hide in shadows",120);
  set_thief_skill("pick pockets",120);
  set_mob_magic_resistance("average");
  set_scrambling(1);
  set_parrying(1);
  set_overall_ac(-1);
  set_monster_feats(({"ambidexterity"}));
  equipment = new(SQUIREITEMS"baneblade");
  equipment->move(TO);
  command("wield sword");
  equipment = new(SQUIREITEMS"baneblade");
  equipment->move(TO);
  equipment->set_property("monsterweapon",1);
  command("wield sword");
  new(SQUIREITEMS"demonskin")->move(TO);
  command("wear demonskin");
  add_money("gold", random(200)+300);
  add_money("platinum", random(50)+150);
  set_new_exp(20, "high");
  set_property("no tripped",1);
  set_property("no paralyze",1);
}

int agg_func(){
  if(TP->query_true_invis()) return 1;
  stab_em(TP);
  return 1;
}

void stab_em(object targ){
  command("say A sacrifice comes!");
  command("say Your service is noted, mortal!");
  set_hidden(1);
  command("stab "+targ->query_name()+"");
  command("kill "+targ->query_name()+"");
}

void die(object obj){
  if(objectp(ETO)){
    all_living(ETO)->set_mini_quest("Squire's Trial", 500000, 
        "%^BOLD%^%^CYAN%^Defeated the Shadow Monster, serving a Forgotten " +
        "Order.%^RESET%^%^WHITE%^\n");
    ETO->portal_active();
    tell_object(ETO,"%^BOLD%^%^WHITE%^The portal flares to life as the creature" +
    " falls to its knees!%^RESET%^");
  }
  ::die(obj);
}

