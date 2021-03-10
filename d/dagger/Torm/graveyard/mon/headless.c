#include <std.h>
inherit MONSTER;
create(){
  ::create();
  set_name("headless horseman");
  set_id(({"headless","headless horseman","horseman"}));
  set_race("undead");
  set_gender("male");
  set_short("Headless horseman");
  set_long("  This horrific creature is that of a highwayman whos evil deeds forever make him haunt the roads of any kingdom he passes."
  "  He holds a fearsome black scimitar in one hand and a glowing pumpkin with a grotesque face caved in it who's eyes blaze with unholy fury!"
  );
  set_ac(0);
  set_size(2);
  set_body_type("human");
  remove_limb("head");
  set_class("thief");
  set_class("fighter");
  set_mlevel("fighter",29);
  set_mlevel("thief",20);
  set_property("no steal",1);
  set_mob_magic_resistance("average");
  set_property("no bows",1);
  set_property("no bump",1);
  set_property("full attacks",1);
  set_property("no animate",1);
  set_thief_skill("hide in shadows",120);
  set_thief_skill("move silently",120);
  add_search_path("/cmds/thief");
  add_search_path("/cmds/fighter");
  add_attack_bonus(10);
  set_moving(1);
  set_speed(20);
  set_hd(25,5);
  set_stats("strength",19);
  new("/d/dagger/Torm/graveyard/mon/nightsword.c")->move(TO);
  command("wield sword");
  if(random(5)) present("sword",TO)->set_property("monsterweapon",1);
  new("/d/dagger/Torm/graveyard/mon/nightcloak.c")->move(TO);
  command("wear cloak");
  if(random(10))present("cloak",TO)->set_property("monsterweapon",1);
  new("/d/dagger/Torm/graveyard/mon/pumpkin2.c")->move(TO);
  command("speech fill the room with a hollow voice");
  add_money("gold",1000);
  set_hp(300);
  set_mob_magic_resistance("average");
  set_exp(5000);
  call_out("do_horse",1);
}
void die(mixed ob){
message("environment","%^BOLD%^%^RED%^The headless takes a final blow and explodes into flaming cinders!%^RESET%^\n\n",environment(TO));
  new("/d/dragon/obj/misc/jack.c")->move(ETO);
  new("/d/dagger/Torm/graveyard/rustedkey.c")->move(ETO);
   ::die();
}
void do_horse(){
  object horse;
  if(!objectp(ETO)) return;
  horse=new("/d/dagger/Torm/graveyard/mon/nightmare.c");
  horse->set_owner(TO);
  horse->move(ETO);
  command("mount horse");
}
int kill_ob(object victim, int which){
  int hold;
 hold= ::kill_ob(victim, which);
  if(hold){
    command("sic "+victim->query_true_name());
  }
  return hold;
}
void heart_beat(){
  object atk;
  ::heart_beat();
  if(!objectp(TO)) return;
  if(!objectp(ETO)) return;
  if(!random(10)){
  if((atk=query_current_attacker())){
  command("hurl at "+atk->query_name());
  }
}
  if(query_property("magic resistance")<50){
  TO->set_mob_magic_resistance("average");
  }
  if(present("snake",ETO)){new("/cmds/spells/d/_dispel_magic")->use_spell(TO,0,query_level(),100,"cleric");}
  if(present("guardian",ETO)){new("/cmds/spells/d/_dispel_magic")->use_spell(TO,0,query_level(),100,"cleric");}
}
int query_watched(){
  return 75;
}
