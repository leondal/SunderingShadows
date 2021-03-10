#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/std/monster";
create(){
::create();
  set_name("sahuagin");
  set_id(({
  "sahuagin","strange man","fish man","man"
  }));
  set_property("swarm",1);
  setenv("MIN", "$N's feet slap wettly onto the ground as it enters.");
   setenv("MOUT", "$N leaves $D with an evil gleam from the eyes under its hood.");
  set_short(
  "Strange man"
  );
  set_long(
   "  Under the slimy robe's hood you catch the glimpse of a fearsome fishlike face."
"  Great lidless eyes stare about at the surface world with nothing but hate shining through."
   "  This creature's gaping mouth is lined with dozens of razor sharp teeth."
  );
  set_race("sahuagin");
  set_gender("male");
set_body_type("human");
  set_hd(4,4);
  set_overall_ac(5);
set_size(2);
  set_stats("strength",17);
set_stats("intelligence",7);
set_stats("dexterity",9);
set_stats("charisma",7);
set_stats("constitution",11);
set_stats("wisdom",8);
set_money("silver",random(100));
  set_exp(200);
set_wielding_limbs( ({"left hand", "right hand"}) );
  new(OBJ+"trident.c")->move(TO);
   new("/d/common/obj/weapon/dagger.c")->move(TO);
  command("wield dagger");
  command("wield trident");
  new(OBJ+"damprobe.c")->move(TO);
  command("wearall");
}
void heart_beat(){
  ::heart_beat();
  if(!objectp(TO) || !objectp(ETO)) return;
  if(!(query_night())){
  if((int)ETO->query_property("indoors")==1) return 1;
  force_me("emote cowers before the approaching sun.");
  TO->run_away();
  TO->move("/realms/amidon/waste.c");
  TO->force_me("offerall");
  TO->remove();
  }
}
void init(){
  ::init();
  if((string)TP->query_name()=="sahuagin") return 1;
  if((int)TP->query_highest_level()<10){
  TO->force_me("emote looks at you and makes a strange laughing noise, almost like flaping gills..");
  return 1;
  }
  if(!avatarp(TP)){
  TO->force_me("emote makes a low hissing noise and attacks!");
  TO->kill_ob(TP);
  if(TO->query_hd()>6) return 1;
  TO->set_hd((int)TP->query_highest_level());
  TO->set_ac((int)TP->query_ac()+3);
  if(TO->query_hd()>30){
  TO->set_hd(30);
  TO->set_ac(-15);
  }
  TO->set_property("magic resistance",query_hd()*2);
  TO->set_stats("strength",18);
  TO->set_stats("dexterity",18);
  TO->set_max_hp(query_hd()*9);
  TO->set_hp(query_max_hp());
  TO->set_property("full attacks",1);
  TO->set_exp(query_hp()*20);
  if(TO->query_hd()>20) TO->set_exp(query_exp()*1.5);
  if(TO->query_hd()>25) TO->set_exp(query_exp()*2);
  }
}
