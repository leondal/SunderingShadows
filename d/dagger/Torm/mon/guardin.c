#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>

inherit MONSTER;
create (){
  ::create ();
  set_name("Injured patrolman");
  set_id(({"private","guard","torm guard","soldier","Torm regular","infantry",
  "torm city guard",
  "injured patrolman","patrolman",
  }));
  set_short("Injured Patrolman");
  set_long(
  "  This guardsman wanders about the city of Torm making sure everything goes smoothly in the markets and watching for thieves."
  "  His mithril armor and weapons shine brightly though and he looks proficient in his duties."
   "  He's a bit battered by his travels and bandages speak of his efforts to keep the trade routes free to the city of bandits."
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
  set_max_hp(200);
  set_hp(random(75)+50);
  set_exp(400);
set("aggressive", 0);
  set_emotes(1,({"%^BOLD%^There is no where for a criminal to hide in Torm!!"}),1);
add_money("gold", 50 + random(100));
  set_overall_ac(8);
  if(!random(2)){
  new(OPATH"Mlong+1.c")->move(TO);
  command("wield sword");
  } else {
new(OBJ"Mspear+1.c")->move(TO);
  command("wield spear in left hand");
  }
  new(OBJ"torm_scalemail.c")->move(TO);
 command("wearall");
  present("scalemail",TO)->set_property("monsterweapon",1);
set_funcs( ({"slice"}) );
  set_func_chance(15);
}

void slice(object targ){
     if(!targ) return 0;
     if(random(25) > targ->query_stats("dexterity")){
  tell_room(environment(targ), "%^RED%^The city guard's sword slips past "+targ->query_cap_name()+"'s guard and slices them in the arm!",targ);
  tell_object(targ, "%^RED%^The city guards sword slips past your guard and slices you deeply in the arm!");
    targ->do_damage(return_target_limb(),random(10)+9);
     return 1;

     } else {

  tell_object(targ, "%^BOLD%^%^BLUE%^The city guard attempts to slip past your guard with his sword.... but you avoid the blow!");
  tell_room(environment(targ), "%^BOLD%^%^BLUE%^The city guard attempts to slip past "+targ->query_cap_name()+"'s guard with his sword.... but the blow is avoided!",targ);
}
}
