#include <std.h>
#include "../derrodefs.h"
  object funnel;
  object ob;
inherit MONSTER;
init(){
  ::init();
  if(TP->query_invis()  && !avatarp(TP)){
  tell_room(ETO,"%^BOLD%^%^YELLOW%^Lightning %^BLACK%^streaks from the funnel cloud to "+TPQCN);
  TP->set_invis();
  kill_ob(TP,1);
  }
  add_action("chain","chain");
}
void create(){
  ::create();
  set_name("Funnel cloud");
  set_id(({"cloud","funnel","funnel cloud","elemental"}));
  set_short("A raging funnel cloud!");
  set_gender("neuter");
  set_long("  This funnel cloud reaches to the ceiling and moves about with purpose; to destory any life it meets!"
  "  Its black whirling mass is lit by lightning and hail and sleet shower anyone nearby."
  );
  set_hd(20,5);
  set_hp(500);
  set_race("funnelcloud");
  add_limb("Funnel","funnel",80,0,3);
  set_funcs(({
  "hail",
  "lightning",
  "buffet",
  }));
  set_func_chance(110);
  new(OBJ"star.c")->move(TO);
  set_overall_ac(-13);
  set("aggressive",20);
  set_exp(15000);
  set_mob_magic_resistance("average");
//  set_property("weapon resistance",4);
// lowered to 3 following new enchant restrictions - L20 players certainly have no chance at +4 weapons
  set_property("weapon resistance",3);
  set_property("no bump",1);
  set_property("do dominate",1);
}
void lightning(object targ){
  tell_object(targ,"%^BOLD%^%^YELLOW%^Lightning streaks towards you from the cloud!%^RESET%^");
  tell_room(environment(targ),"%^BOLD%^%^YELLOW%^Lightning steaks from the %^BLACK%^funnel cloud%^YELLOW%^ and "+targ->query_cap_name()+" seems to dance as it races through "+targ->query_possessive()+" body!",targ);
  targ->do_damage("torso",random(50)+25);
}
void hail(object targ){
  object *hail;
  int i, j;
  hail=all_living(ETO);
  funnel=TO;
  hail-=({funnel});
  j=sizeof(hail);
  for(i=0;i<j;i++){
  tell_object(hail[i],"%^CYAN%^Hail pelts the room from the whirling cloud!");
  hail[i]->do_damage(hail[i]->return_target_limb(),17);
 }
}
void buffet(object targ){
    tell_object(targ,"%^BOLD%^%^CYAN%^The raging winds throw you against the wall!");
  tell_room(environment(targ),"%^BOLD%^%^CYAN%^"+targ->query_cap_name()+" is thrown against a wall by a wave of wind!",targ);
  targ->do_damage("torso",random(10)+1);
  targ->set_paralyzed(random(20),"You struggle to regain your breath!");
}
void die(mixed ob){
  message("environment","%^CYAN%^The storm clouds wan and fade away as the essence of the funnel cloud is destroyed.%^RESET%^\n"
  ,environment(TO));
   switch(random(2)){
   case 0:
  new(OBJ"star.c")->move(ETO);
   break;
   case 1:
   new(OBJ"blacksapphire.c")->move(ETO);
   break;
   }
  TO->move("/d/shadowgate/void.c");
  ::die(ob);
}
void chain(string str){
  ob=present("blackened chains",TP);
  if(ob){
  if (TP->query_bound() || TP->query_unconciscious()){
 say(""+TPQCN+" squirms about");
  write("You squirm around.");
  return 0;
  }
  write("You pull out the chains and the funnelcloud suddenly looks like its trying to fit back in its box.");
  write("%^BOLD%^%^BLACK%^  Before you can even think about what the chains could do they leap from your hands to snare the writhing cloud!");
  write("%^BOLD%^%^CYAN%^The chains weave through the winds and trap it in other form!");
  say("%^BOLD%^%^CYAN%^"+TPQCN+" throws chains at the funnel cloud who tries in vain to move out of the way!");
  say("%^CYAN%^The chains writhe through the funnel, wrapping around it and trapping it in other form!");
  ob->remove();
  ob=new(OBJ"Stormrobe.c");
  ob->move(TO);
  remove();
  return 1;
  }
}
