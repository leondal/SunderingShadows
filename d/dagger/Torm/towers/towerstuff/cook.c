#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit MONSTER;
string TYP;
create (){
  ::create();
  set_body_type("human");
  switch(random(20)){
  case 0..10:
  set_level(15);
  TYP="prep cook";
  set_exp(2500);
  break;
  case 11..17:
  set_level(20);
  TYP="assistant cook";
  set_exp(4000);
  break;
  case 18..19:
  TYP="master cook";
  set_level(30);
  set_exp(7500);
  break;
  }
  switch(random(8)){
  case 0:set_race("human");set_size(2);break;
   case 1:set_race("elf");set_size(2);break;
   case 2:set_race("half-elf");set_size(2);break;
  case 3:set_race("drow");set_size(2);break;
  case 4:set_race("half-orc");set_size(2);break;
  case 5:set_race("ogre");set_size(3);break;
  case 6:set_race("gnoll");set_size(3);break;
  case 7:set_race("goblin");set_size(1);break;
  }
  switch(random(4)){
  case 1:
  set_class("fighter");
  set_hd(query_level());
  set_mlevel(query_level());
  set_guild_level("fighter",query_level());
  if(query_size()==3){
  new(TOWS+"meatmaul.c")->move(TO);
  command("wield maul");
  } else { 
  new(TOWS+"meataxe.c")->move(TO);
  command("wield axe");
  }
  add_search_path("/cmds/fighter/");
  break;
  case 2:
  set_class("mage");
  set_mlevel(query_level());
  set_hd(query_level());
  set_guild_level("mage",query_hd());
  new(TOWS+"knife.c")->move(TO);
  command("wield knife");
  set_spells(({"magic missile","cone of cold","fireball","acid arrow","hideous laughter",
  }));
  set_stoneSkinned(10);
  set_mob_magic_resistance("average");
  set_spell_chance(50);
  break;
  case 0:
  set_class("thief");
  set_mlevel(query_level());
  set_hd(query_level());
  set_guild_level("thief",query_hd());
  add_search_path("/cmds/thief/");
  set_scrambling(1);
  new(TOWS+"knife")->move(TO);
  new(TOWS+"knife")->move(TO);
  command("wield knife");
  command("wield knife 2");
  break;
  }
  set_name(query_race()+" "+TYP);
  set_id(({query_name(),TYP,"cook",
  }));
  set_short("An "+query_name());
  set_long(
  "  This very ugly and mean looking "+query_race()+" seems to have a glazed, crazed look to its eye."
  "  You're not sure what it's duties as a "+TYP+" are, but it's looking at you with nothing but hunger in its eye."
  "  They must reserve all their water for dishes here, because this minion of the school here hasn't seemed to have bathed anytime recently, and a sick odor acompanies the stains and poorly kept up hair."
  );
  if(!(random(2))) set_property("no rush",1);
  if(!(random(2))) set_property("no stab",1);
  set_property("no bows",1);
  set_property("swarm",1);
  set_max_hp(200);
  set_hp(200);
  set_hp(query_max_hp());
  set_property("full attacks",1);
  set_stats("strength",19);
  set_gender("male");
}
