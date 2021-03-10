#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/std/monster";
create(){
::create();
  set_name("bank guard");
  set_id(({
  "guard","bank guard",
  }));
  set_short(
  "Bank guard"
  );
  set_long(
  "  This tall thin man stands silently beside the teller a pair of gruesome looking daggers across his chest."
  "  A sense of dread unease settles on you as you watch him stand there and realize that he's probably paid VERY well to make sure nothing happens to the bank's money."
  "  You think attacking him probably wouldn't be that good an idea."
  );
  set_race("undead");
  set_gender("male");
set_body_type("human");
  set_hd(40,8);
  set_class("assassin");
  set_mlevel("assassin",40);
  set_guild_level("assassin",40);
  add_search_path("/cmds/thief/");
  add_search_path("/cmds/assassin");
  add_search_path("/cmds/mortal/");
  set_max_hp(500);
  set_hp(500);
  set_overall_ac(-18);
set_size(2);
  set_stats("strength",19);
  set_money("gold",2000);
  set_exp(1000);
set_wielding_limbs( ({"left hand", "right hand"}) );
  new("/d/attaya/obj/screamer.c")->move(TO);
  new("/d/attaya/obj/screamer.c")->move(TO);
  present("screamer",TO)->set_property("monsterweapon",1);
  present("screamer 2",TO)->set_property("monsterweapon",1);
  command("wield dagger");
  command("wield dagger 2");
  set_scrambling(1);
  set_property("swarm",1);
  set_property("no stab",1);
  set_property("no rush",1);
  set_property("no dominate",1);
  set_property("no bows",1);
  set_property("no death",1);
}
void heart_beat(){
  int x;
  object *att;
  ::heart_beat();
  if(!objectp(TO)) return;
  att=TO->query_attackers();
  if(!(sizeof(att))) return 1;
  for(x=0;x<sizeof(att);x++){
  force_me("crit "+att[x]->query_name());
  }
}
void set_paralyzed(int time,string message){return 1;}
void set_bound(int time,string message){return 1;}
void set_tripped(int time,string message){return 1;}
