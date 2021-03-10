#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/d/dagger/Torm/mon/dayperson.c";
  
create (){
  ::create ();
  set_moving(0);
  set_name("troll");
  set_id(({"troll", "massive troll"}));
  set_property("swarm",1);
  set_short("massive troll");
  set_long(
  "This massive creature is dressed in fullplate armor.  "
  "An ugly twisted nose juts from an open visor that allows you to see his horrid face."
   "  A great halberd sits loosely in his hands and he looks like he would be a formidable opponent on the battlefield."
  "  Oddly enough the citizens of Torm wander past him, sometimes with a friendly nod and a group of small children play around him, even running between his legs with their childish giggles."
  );
set_gender("male");
  set_race("troll");
set_body_type("human");
  set_size(3);
  set_emotes(3,({
   "The massive troll skulks around watching you warily.",
   "%^BOLD%^%^BLACK%^Shadows swirl about the halberd in the troll's hands.%^RESET%^",
   "The troll growls menacingly.",
  }),0);
  set_class("fighter");
  set_mlevel("fighter",30);
  add_search_path("/cmds/fighter");
  set_property("full attacks",1);
  set_hd(30);
  set_stabbed_func((:TO,"stabbed":));
  set_stats("strength",25);
  set_alignment(3);
  set_max_hp(300);
  set_hp(query_max_hp());
  set_exp(6000);
set("aggressive", 0);
add_money("gold", 50 + random(100));
  new(OBJ"soulcleaver.c")->move(TO);
  command("wield halberd");
  set_overall_ac(-8);

  set_property("no bows",1);
  set_property("magic resistance",50);
  set_property("no dominate",1);
  set_moving(100);
  new(OBJ+"fullplateb.c")->move(TO);
  command("wearall");
   if(random(5)) present("plate",TO)->set_property("monsterweapon",1);
   if(random(50)) present("halberd",TO)->set_property("monsterweapon",1);
}

/*  This doesn't apply now that he's moved outside the city to act like a troll.
init () {
  ::init();
  add_action("nota","stab");
  add_action("nota","rush");
  add_action("nota","crit");
  add_action("beserky","beserk");
}
  
int nota(string str){
  if(!(present("child",ETO))) return 0;
  if(str == "child" || str == "playing child"){
  tell_room(ETO,"%^RED%^The troll roars as a child is attacked and leaps in the way!");
  TO->force_me("rush "+TPQN);
  kill_ob(TP,1);
  return 1;
  }
}

int beserky(){
  if(((string)TP->query_name()) != "child") return 0;
  tell_room(ETO,"%^RED%^The troll suddenly goes beserk as the child dies at his feet!!!");
  TO->set_attack_bonus(10);
  TO->set_damage_bonus(5);
  }
*/

void stabbed(){
   tell_room(ETO,"%^BOLD%^%^YELLOW%^Dhamor's armor deflects the full force of the blow!");
  if(query_hp()<0) set_hp(100);
}
