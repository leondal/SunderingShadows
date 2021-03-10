#include "/d/dagger/road/short.h"
inherit MONSTER;

create (){
::create ();
set_name("dwarven guard");
set_id(({"sergeant","dwarf","guard","tollbooth guard","dwarven guard","dwarven tollbooth guard"}));
set_short("A Dwarven guard");
   set("long", "This is a Dwarven Tollbooth guard wearing the stripes of a Sergeant."+
   " He looks very experienced at commanding and handling his weapon.");
set_property("swarm",1);
set_gender("male");
set("race", "dwarf");
set_body_type("human");
set_hd(14,0);
set_size(1);
set_class("fighter");
set_stats("strength", 17);
set_stats("intelligence", 10);
set_stats("dexterity", 14);
set_stats("charisma", 10);
set_stats("wisdom", 12);
set_stats("constitution", 19);
set_alignment(3);
set_max_hp(280);
set_hp(280);
set_exp(2000);
set("aggressive", 0);
set_emotes(3,({
"%^BOLD%^%^BLUE%^The Guard says, I saw a few wild animal tracks up the road today.",
"%^BOLD%^%^GREEN%^The Guard says, I hope those bullywugs stay in the marsh.",
"%^BOLD%^The Guard says, Whens our relief gonna show up...my feet hurt!"
}), 0);
set_emotes(5,({"%^BOLD%^Rally!! Rally!! Rally to me soldiers of the Light!!"}),1);
add_money("gold", 85 + random(100));
set_wielding_limbs( ({"left hand","right hand"}) );
if(!random(2)) {
new(OPATH "Maxe+1.c")->move(this_object());
   command("wield axe");
   new(OPATH "Mshield+1.c")->move(this_object());
   command("wear shield");
 }
 else {
   new(OPATH "Mhammer+1.c")->move(this_object());
   command("wield hammer");
 }
new(OPATH "Mcoif.c")->move(this_object());
command("wear coif");
new(OPATH "Mchain+1.c")->move(this_object());
command("wear chainmail");


  set_funcs( ({"kick"}) );
  set_func_chance(40);
}

void kick(object targ)
{
  if(!targ) return 0;
  if(random(25) > targ->query_stats("dexterity")){
  tell_room(environment(targ), "%^RED%^The Tollbooth Guard kicks"+targ->query_cap_name()+" in his kneecap!!",targ);
  tell_object(targ, "%^RED%^The Tollbooth Guard kicks you in your kneecap!");
  targ->do_damage("right leg", random(2)+8);
  tell_object(targ, "%^YELLOW%^The Tollbooth Guard kicks your kneecap HARD!!");
  if(random(25) > targ->query_stats("constitution"))
  targ->set_paralyzed(random(24), "%^BOLD%^You cry out and bend over to clutch your kneecap! During that time you are vunerable!");
  return 1;
}else{
  tell_object(targ, "%^BOLD%^%^BLUE%^The Tollbooth Guard attempts to kick you in the kneecap....but misses!!");
  tell_room(environment(targ), "%^BOLD%^%^BLUE%^The Tollbooth Guard attempts to kick "+targ->query_cap_name()+" in the kneecap....but misses!!",targ);
}
}

