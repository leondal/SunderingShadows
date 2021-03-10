#include <std.h>
#include "../elf.h"
inherit WEAPONLESS;
object dude;

void create(){
  ::create();
  set_name("iridescent ioun");
  setenv("MIN", "$N floats in");
  setenv("MOUT", "$N floats out $D ");
  set_id(({"iridescent stone","ioun","iridescent ioun","stone"}));
  set_short("%^RESET%^%^BOLD%^floating iridescent stone%^RESET%^");;
  set_long("%^BOLD%^This is a strange iridescent stone."+
  "  It floats in the air around its owner in circles."+
  " The owner of this stone could tell it to _return_ if needed.%^RESET%^");
  set_hd(5,5);
  set_max_hp(25);
  set_hp(25);
  set_race("ioun");
  set_ac(-10);
  set_exp(1);
  set_size(1);
  set_property("magic",1);
  set_mob_magic_resistance("average");
  set_missChance(99);  //might change this due to Hardened minions twinky
  set_func_chance(100);
  set_attacks_num(1);
  set_body_type("snake");
  remove_limb("mouth");
  remove_limb("head");
  remove_limb("tail");
  remove_limb("torso");
  add_limb("stone","stone",0,0,0);
  set_base_damage_type("bludgeoning");

}
void owned(object jimmy){
 if(!objectp(jimmy))return;
 dude = jimmy;
 dude->set_property("water breather",1);
}

void die(object ob){
 tell_room(ETO,"%^BOLD%^"+query_short()+" breaks appart shattering into %^RESET%^%^ORANGE%^dust!");
 dude->set_property("water breather",0);
   ::die(ob);
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
   if(!msg || !objectp(who)) return;
   if (base_name(who) == base_name(TO)) return;
   if((strsrch(msg,"return") != -1) &&  dude == who){
   tell_room(ETO,"The stone stops orbiting and drops back to the ground.");
   new(OBJ"iioun")->move(ETO);
   dude->set_property("water breather",0);
   remove();
}
}
   