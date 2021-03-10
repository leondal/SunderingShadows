#include <std.h>
#include "../tecqumin.h"

inherit MOB + "unfettered_base.c";

object * clones;

void create(){
  ::create();
  clones = ({});
}

void add_clone(object clone){
  clones += ({clone});
}

object * query_clones(){
  return clones;
}

object query_master(){
  return TO;
}

void set_clones(object * cl){
  clones = cl;
}

void really_cause_typed_damage(object victim,string limb,int damage,string damage_type){
  ::cause_typed_damage(victim, limb, damage, damage_type);
}

void relay_typed_damage(object victim,string limb,int damage,string damage_type, object r_room){
  relay_room = r_room;
  relaying = 1;
  cause_typed_damage(victim, limb, damage, damage_type);
}
