#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit MONSTER;
create (){
  ::create ();
  set_moving(0);
  set_name("Sergeant");
  set_id(({"segeant","torm guard","guard","soldier","sergeant of torms guard",
  "torm city guard","sergeant","dayperson","torm guardsman"}));
  set_property("swarm",1);
  set_short("Sergeant in the Torm city guard");
  set_long(
  "  This hard bitten veteran looks chiseled from the bedrock the city of Torm rests on."
   "  His mithril armor and weapons shine brightly though and he looks proficient in his duties."
  );
set_gender("male");
  if(!random(2)){
  set_race("human"); 
  } else {
  set_race("half-elf");
  }
set_body_type("human");
  set_hd(25,1);
set_size(2);
  set_class("fighter");
  set_mlevel("fighter",25);
 set_guild_level("fighter",25);
  set_property("full attacks",1);
  add_search_path("/cmds/fighter/");
  set_stats("strength",17);
set_stats("intelligence", 13);
set_stats("dexterity", 17);
set_stats("charisma", 16);
set_stats("wisdom", 10);
set_stats("constitution", 14);
set_alignment(1);
  set_max_hp(random(40)+200);
  set_hp(query_max_hp());
  set_exp(2000);
set("aggressive", 0);
  set_emotes(1,({"%^BOLD%^There is no where for a criminal to hide in Torm!!"}),1);
add_money("gold", 50 + random(100));
  set_overall_ac(5);
  new(OBJ"torm_sword.c")->move(TO);
  command("wield sword");
  new(OBJ"torm_scalemail.c")->move(TO);
  new(OPATH"Mcoif.c")->move(TO);
  new(OBJ"torm_shield.c")->move(TO);
 command("wearall");
  present("shield",TO)->set_property("monsterweapon",1);
  present("coif",TO)->set_property("monsterweapon",1);
  present("scalemail",TO)->set_property("monsterweapon",1);
}

void heart_beat(){
   int x;
  object *att;
  ::heart_beat();
  if(!objectp(TO)) return;
  att=TO->query_attackers();
  if(!(sizeof(att))) return 1;
  for(x=0;x<sizeof(att);x++){
    force_me("rush "+att[x]->query_name());
  }
}
