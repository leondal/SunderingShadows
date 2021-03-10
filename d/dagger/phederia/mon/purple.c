#include <std.h>
#include "../phedefs.h"
inherit WEAPONLESS;
int STuffed,STop;
object room;
void create(){
  ::create();
  set_name("purple worm");
  set_id(({"worm","purple worm"}));
  set_short("%^RESET%^%^MAGENTA%^Purple worm%^RESET%^");
  set_long(
  "  This massive creature shakes the dirt from its body and lunges to swallow you whole with its massive fang rimmed mouth!"
  "  The end of its 40 foot long body ends in a viscious stinger that drips venom that corrodes the rock as it lashed about."
  );
  set_hd(35,8);
  set_attacks_num(2);
  set_attack_limbs(({"gaping maw","viscious poisoned stinger"}));
  set_base_damage_type("slash");
  set_damage(2,6);
  set_hp(500);
  set_max_hp(query_hp());
  set_race("worm");
  add_limb("gaping maw","first segment",0,0,0);
  add_limb("first segment","second segment",0,0,0);
  add_limb("middle segment","second segment",0,0,0);
  add_limb("last segment","second segment",0,0,0);
  add_limb("narrowed tail end","second segment",0,0,0);
  add_limb("viscious stinger","second segment",0,0,0);
  set_ac(-15);
  set_exp(15000);
  set_property("swarm",1);
  set_mob_magic_resistance("average");
  set_func_chance(20);
  set_funcs(({"maw","stinger"}));
  room= new(MON"stomach.c");
}
void maw(object targ){
  if(STuffed){
  tell_object(targ,"%^BOLD%^The purple worm attempts to swallow you but already has something in its throat!");
  tell_room(environment(targ),"%^BOLD%^The purple worm lunges at "+targ->query_cap_name()+" but cant seem to swallow "+targ->query_objective()+"!",targ);
  return 15;
  }
  if(!random(10)){
  tell_object(targ,"%^BOLD%^The purple worm lunges for you and you try to get out of the way but it swallows you whole!");
  tell_room(environment(TO),"%^BOLD%^The purple worm lunges forward at "+targ->query_cap_name()+" who tries to jump out of the way but is swallowed whole!",({TO,targ}));
  tell_object(TO,"You grin and swallow "+targ->query_cap_name()+"!");
  if(interactive(targ)) targ->move(room);
  else room ->move_here(targ);
  targ->set_paralyzed(40,"%^BOLD%^%^GREEN%^You struggle in the acids of this worms stomach!");
  if(interactive(targ)) STuffed=1;
  } else {
  tell_object(targ,"%^BOLD%^The purple worm lunges for you but you manage to scramble out of the way of its gaping maw!");
  tell_room(environment(targ),"%^BOLD%^"+targ->query_cap_name()+" scrambles out of the way as the massive worm tries to swallow "+targ->query_objective()+"!",targ);
  }
}
int stinger(object targ){
  tell_object(targ,"%^BOLD%^%^BLUE%^The flickering stinger nicks you and the poison works into your body!");
  tell_room(environment(targ),"%^BOLD%^%^BLUE%^The purple worms flickering stinger scores a hit on "+targ->query_cap_name()+" who starts clawing at "+targ->query_possessive()+" neck!",({TO,targ}));
  tell_object(TO,"You sting "+targ->query_cap_name()+" and watch him squirm.");
  if(!random(7)){
  tell_object(targ,"%^BOLD%^The poison races through your body and you feel your heart start to race faster and FASTER till it explodes!");
  tell_room(targ,"%^BOLD%^%^RED%^"+targ->query_cap_name()+" screams and clutchs at his chest then collapes, dead!",targ);
  set_property("magic",1);
  targ->do_damage("torso",(targ->query_hp())+20);
  remove_property("magic");
  } else {
  tell_object(targ,"%^BOLD%^The poison races through your blood and your body tries to fight it off!");
  tell_room(environment(targ),"%^BOLD%^"+targ->query_cap_name()+" screams in agony and clutches at his chest, writhing around in agony!!",targ);
  targ->set_paralyzed(50,"%^BOLD%^You writhe in agony as the poison races through your body!");
  }
}
void heart_beat(){
  object *inven;
  int i,j;
  if(!objectp(room))  room=new(MON"stomach.c");
  if(query_hp()<1){
  if(room){
  inven=all_inventory(room);
  i=sizeof(inven);
  for(j=0;j<i;j++){
  if(interactive(inven[j])){
  tell_object(inven[j],"%^MAGENTA%^The purple worm splits open from the damage its taken and you spill out to the precious air again!\n");
  inven[j]->move(environment(TO));
  tell_room(environment(TO),"%^MAGENTA%^As the purple worm splits open "+inven[j]->query_short()+" falls from its guts!\n",inven[j]);
  inven[j]->add_exp(950);
  }else{ 
  inven[j]->move(environment(TO));
  tell_room(environment(TO),"%^MAGENTA%^As the purple worm splits open "+inven[j]->query_short()+" falls from its guts!\n");
    }
   }
   room->remove();
  }
  }
  ::heart_beat();
  if(objectp(TO)&&objectp(ETO)){
  inven=all_inventory(environment(TO));
  i=sizeof(inven);
  for(j=0;j<i;j++){
  if(inven[j] == TO) continue;
  else if(living(inven[j]) && !wizardp(inven[j])) kill_ob(inven[j],1);
  //else{
  //tell_room(environment(TO),"%^MAGENTA%^Something struggles in the worms body!\n");
  //room->move_here(inven[j]);
  // }
   }
  }
}
