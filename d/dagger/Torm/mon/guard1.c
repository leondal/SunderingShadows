#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>

inherit MONSTER;
create (){
  ::create ();
  set_name("Torm city guard");
  set_id(({"private","guard","torm guard","soldier","Torm regular","infantry",
  "torm city guard","torm guardsman"}));
  set_short("Torm city guard");
  set_long(
  "  This guardsman holds his post but looks with fear to the dark forest to the west and south."
  "  His mithril armor and weapons shine brightly though and he looks proficient in his duties."
  );
set_property("swarm",1);
set_gender("male");
  if(!random(2)){
  set_race("human"); 
  } else {
  set_race("half-elf");
  }
set_body_type("human");
set_hd(18,1);
set_size(2);
  set_class("fighter");
  set_mlevel("fighter",18);
  set_property("full attacks",1);
  set_stats("strength",17);
set_stats("intelligence", 13);
set_stats("dexterity", 17);
set_stats("charisma", 16);
set_stats("wisdom", 10);
set_stats("constitution", 14);
set_alignment(1);
  set_max_hp(random(100)+200);
  set_hp(query_max_hp());
set_exp(3500);
set("aggressive", 0);
set_emotes(1, ({"%^BOLD%^You shall never defeat the Forces of Good!!"}), 1);
add_money("gold", 50 + random(100));

  if(!random(2)){
new(OBJ"torm_sword.c")->move(TO);
  command("wield sword");
  } else {
new(OBJ"Mspear+1.c")->move(TO);
  command("wield spear in left hand");
  }
  set_overall_ac(8);
  new(OBJ"torm_shield.c")->move(TO);
  new(OBJ"torm_scalemail.c")->move(TO);
 command("wearall");
  if(!random(2)){
  present("scalemail",TO)->set_property("monsterweapon",1);
  present("shield",TO)->set_property("monsterweapon",1);
  }
set_funcs( ({"slice"}) );
  set_func_chance(15);
}

void slice(object targ){
     if(!targ) return 0;
     if(random(25) > targ->query_stats("dexterity")){
  tell_room(environment(targ), "%^RED%^The city guard's sword slips past "+targ->query_cap_name()+"'s guard and slices them in the arm!",targ);
  tell_object(targ, "%^RED%^The city guards sword slips past your guard and slices you deeply in the arm!");
     targ->do_damage("left arm", random(2)+9);
     return 1;

     } else {

  tell_object(targ, "%^BOLD%^%^BLUE%^The city guard attempts to slip past your guard with his sword.... but you avoid the blow!");
  tell_room(environment(targ), "%^BOLD%^%^BLUE%^The city guard attempts slip past "+targ->query_cap_name()+"'s guard with his sword.... but the blow is avoided!",targ);
}
}
