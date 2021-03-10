#include <std.h>
#include <move.h>
#include "../../defs.h"
inherit WEAPONLESS;

object myroom;

void create(){
    ::create();
    set_name("gelatinous cube");
    set_id(({"cube","gelatinous cube"}));
    set_short("%^BOLD%^%^BLACK%^An oozing gelatinous cube%^RESET%^");
    set_long("%^RESET%^This creature seems to be a perfect cube, slithering across the ground with some unseen "
"form of locomotion. The gel that forms the body is %^BOLD%^%^BLACK%^tr%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^n"
"%^RESET%^%^WHITE%^slu%^BOLD%^%^BLACK%^ce%^RESET%^%^WHITE%^nt, and you can catch glimmers of %^BOLD%^%^WHITE%^"
"light %^RESET%^through it. However, instead of making this beast seem more understandable, the light only "
"illuminates a hundred scraps of things within the cube. You can catch a glimpse of %^BOLD%^%^BLACK%^armor"
"%^RESET%^, %^YELLOW%^weapons%^RESET%^, even the %^ORANGE%^spinal column %^RESET%^of some beast captured and "
"suspended in the cube. It slides around almost mindlessly.");
    set_race("cube");
    add_limb("body","body",80,0,3);
    set_hd(28,3);
    set_hp(600);
    set_gender("neuter");
    set_funcs(({"my_hit"}));
    set_func_chance(102);
    set_overall_ac(-8);
    set_exp(5000);
    add_money("gold",random(25)+350);
    add_money("silver",random(25)+300);
    add_money("electrum",random(25)+100);
    add_money("copper",random(35)+300);
    set("aggressive",25);
    set_speed(150);
    set_moving(1);
    set_nogo(({MID+"tunnel09","/d/dagger/kinaro/mines/lower2q"}));
    set_property("swarm",1);
    set_attack_limbs(({"body"}));
    set_attacks_num(2);
    set_damage(4,4);
    set_base_damage_type("bludgeoning");
    myroom = find_object_or_load(MIDMON"cuberoom");
}

void my_hit(object targ){
    if(!interactive(targ)) return;
    if(random(20)+1 > (int)("daemon/bonus_d"->monster_thaco( TO->query_hd())) - (int)(targ->query_ac())){
      tell_room(ETO,"%^GREEN%^The gelatinous cube touches "+targ->QCN+"!%^RESET%^",targ);
      tell_object(targ,"%^GREEN%^The cube touches you! Its acidic touch eats away at your skin!%^RESET%^");
      targ->do_damage("torso",random(8)+18);
      if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death",-5)){
        targ->set_paralyzed(20,"%^GREEN%^You are paralyzed by the gelatinous cube!%^RESET%^");
        tell_object(targ,"%^GREEN%^You are paralyzed by the cube's touch!%^RESET%^");
        tell_room(ETO,"%^GREEN%^"+targ->QCN+" goes rigid at the touch of the cube!%^RESET%^",targ);
        if(!random(4)) {
          tell_object(targ,"%^GREEN%^The cube overwhelms you and start digesting you!%^RESET%^");
          tell_room(ETO,"%^GREEN%^"+targ->QCN+" is overwhelmed by the cube!%^RESET%^",targ);
          targ->move_player(myroom);
        }
      }
    }
    else {
      tell_room(ETO,"%^GREEN%^The gelatinous cube misses "+targ->QCN+"!%^RESET%^",targ);
      tell_object(targ,"%^GREEN%^The cube misses you!%^RESET%^");
    }
}

void heart_beat(){
    object *inven;
    int i,j;
    ::heart_beat();
    if(!objectp(myroom)) myroom = find_object_or_load(MIDMON"cuberoom");      
    if(objectp(TO) && objectp(ETO)){
      inven = all_inventory(ETO);
      i = sizeof(inven);
      for(j = 0; j<i;j++){
        if(inven[j] == TO) continue;
        if(living(inven[j])) {
          if(interactive(inven[j]) && !inven[j]->query_true_invis()) kill_ob(inven[j],1);
        }
        else {
          if((int)inven[j]->move(myroom) == MOVE_OK) {
            tell_room(ETO,"The cube consumes "+inven[j]->query_short()+"!");
            myroom->move_here(inven[j]);
          }
        }
      }
    }
}

void clean_up() {return;}

void set_paralyzed(int time, string message){ return; }

void die(object ob) {
    object *inven;
    int i,j;
    if(myroom){
      inven = all_inventory(myroom);
      i = sizeof(inven);
      for(j = 0; j < i;j ++){
        if(interactive(inven[j])){
          tell_object(inven[j],"%^GREEN%^As the cube dies you fall to the ground, free!%^RESET%^");
          tell_room(ETO,"%^GREEN%^"+ETO->QCN+" falls free of the dying cube!%^RESET%^",inven[j]);
          inven[j]->move_player(ETO);
        }
        else {
          inven[j]->move(ETO);
          tell_room(ETO,"%^RESET%^"+inven[j]->query_name()+"%^RESET%^ falls from the dying cube!%^RESET%^");
        }
      }
      myroom->remove();
    }
    :: die(TO);
}
