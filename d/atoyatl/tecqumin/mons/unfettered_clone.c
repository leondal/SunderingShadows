#include <std.h>
#include "../tecqumin.h"

inherit MOB + "unfettered_base.c";

object master;


void set_master(object m){
  master = m;
  set_hp(master->query_hp());
  set_max_hp(master->query_max_hp());
}

object query_master(){
  return master;
}

int query_hp(){
  if (!objectp(master)){
//    call_out("remove", 1);
    return 0;
  }
  return master->query_hp();
}

int query_max_hp(){
  if (!objectp(master)){
//    call_out("remove", 1);
    return 0;
  }
  return master->query_max_hp();
}

void really_cause_typed_damage(object victim,string limb, int damage,string damage_type){
  ::cause_typed_damage(victim, limb, damage, damage_type);
}

void cause_typed_damage(object victim,string limb, int damage,string damage_type){
  if (!objectp(master)){
//    call_out("remove", 1);
    return 0;
  }
  tell_room(ETO, "About to relay damage");
  master->relay_typed_damage(victim, limb, damage, damage_type, ETO);    
}

int query_mucus(){
  if (!objectp(master)){
//    call_out("remove", 1);
    return 0;
  }
  return master->query_mucus();
}

void set_mucus(int m){
  if (!objectp(master)){
//    call_out("remove", 1);
    return 0;
  }
  master->set_mucus(m);
}

int query_frozen_mucus(){
  if (!objectp(master)){
//    call_out("remove", 1);
    return 0;
  }
  return master->query_frozen_mucus();
}

void set_frozen_mucus(int m){
  if (!objectp(master)){
//    call_out("remove", 1);
    return 0;
  }
  master->set_frozen_mucus(m);
}

int query_skin(){
  if (!objectp(master)){
//    call_out("remove", 1);
    return 0;
  }
  return master->query_skin();
}

void set_skin(int s){
  if (!objectp(master)){
//    call_out("remove", 1);
    return 0;
  }
  master->set_skin(s);
}

int query_tentacles_withdrawn(){
   if (!objectp(master)){
//    call_out("remove", 1);
    return 0;
  }
  return master->query_tentacles_withdrawn();
}

void set_tentacles_withdrawn(int t){
   if (!objectp(master)){
//    call_out("remove", 1);
    return 0;
  }
  return master->set_tentacles_withdrawn(t);
}

void init(){
  if (objectp(master)){
    set_max_hp(master->query_max_hp());
    set_hp(master->query_hp());
  }
  ::init();
}

void add_seized(object seizee){
  if (!objectp(master)){
    move("/d/shadowgate/void");
  }
  master->really_add_seized(seizee);
}

mapping query_seized(){
  if (!objectp(master)){
    tell_room(ETO, "Master not valid. Returning empty list of seized objects");
    return seized;
  }  else {
    return master->query_seized();
  } 
}

void release_seized(object seizee){
  if (!objectp(master)){
    move("/d/shadowgate/void");
  }
  master->really_release_seized(seizee);
}
