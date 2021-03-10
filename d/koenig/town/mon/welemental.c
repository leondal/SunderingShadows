//welemental.c

#include <std.h>

inherit MONSTER;

void create(){
  ::create();

    set_name("water elemental");
    set_id(({"elemental","water elemental","welemental"}));

    set_short("%^BOLD%^%^CYAN%^A Water Elemental%^RESET%^");
    set_property("water breather",1);
    set_long("%^BOLD%^%^BLUE%^This large creature appears as a large wave with a vaguely "+
"humanoid shape. The arms are merely smaller waves. From deep inside the "+
"wavelike body you see two %^GREEN%^green orbs%^BLUE%^ that serve as eyes. You can see "+
"the %^RESET%^ebbing%^BOLD%^%^BLUE%^ and %^RESET%^flowing%^BOLD%^%^BLUE%^ in the monster.%^RESET%^");
    set_hd(4 + (4 *(random(3)+1)),1);
    set_hp(query_hd()*8);
    set_exp((query_hd()-6)* 1000);
    set_stats("strength",18);
    set_stats("intelligence",7);
    set_stats("dexterity",10);
    set_funcs(({"attack"}));
    set_func_chance(102);
    add_limb("torso","torso",50,0,2);
    add_limb("right crest","right crest",50,0,2);
    add_limb("left crest","left crest",50,0,2);
    add_limb("upper crest","upper crest",50,0,2);
    add_limb("base","base",50,0,2);
    set_race("elemental");
    set_gender("sexless");
    set_wielding_limbs(({"right crest","left crest"}));
    set_overall_ac(2);
	set_new_exp(12, "high");
    set("aggressive",0);
   set_property("magic",1);
  }


void attack(object targ){
  int damage;

  tell_room(environment(TO),"%^BOLD%^%^BLUE%^The elemental throws a watery attack at "+targ->query_name()+"!",targ);
  tell_object(targ,"%^BOLD%^%^BLUE%^The elemental throws a watery attack at you.");
  if(random(20)+3 > (int)("daemon/bonus_d"->monster_thaco( TO->query_hd() ) )-(int)(targ->query_ac())){

    damage = roll_dice(5,6);
    TO->send_messages(0,0,targ->return_target_limb(),damage,targ);
    targ->do_damage(targ->return_target_limb(),damage);
  } else {
    say("The water elemental misses "+targ->query_cap_name(),targ);
    tell_object(targ,"The water elemental misses you!\n");
  }

}

int kill_ob(object victim,int which){
  int hold;
  hold = ::kill_ob(victim,which);
  call_out("hide_me",10);
  return hold;
}

void hide_me(){
  if(random(20) < 4){
    tell_room(environment(TO),"%^BOLD%^%^BLUE%^The water elemental becomes part of the water again.");
    tell_room(environment(TO),"%^BOLD%^%^BLUE%^You are extremely worried now that your oponent is almost untouchable.");
    TO->set_invis();
    TO->set_overall_ac(-2);
    call_out("come_back",5);
  }
  else
    call_out("hide_me",10);
}

void come_back(){
  tell_room(environment(TO),"%^BOLD%^%^BLUE%^The elemental comes together again and ATTACKS!");

  if(TO->query_invis())
    TO->set_invis();
  TO->set_overall_ac(2);
  call_out("hide_me",10);
}
