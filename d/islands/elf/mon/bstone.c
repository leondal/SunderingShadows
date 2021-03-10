#include <std.h>
#include "../elf.h"
inherit WEAPONLESS;
object dude;

void create(){
  ::create();
  set_name("black ioun");
  setenv("MIN", "$N floats in");
  setenv("MOUT", "$N floats out $D ");
  set_id(({"black stone","ioun","black ioun","stone"}));
  set_short("%^BOLD%^%^BLACK%^floating black stone%^RED%^");;
  set_long("%^BOLD%^%^BLACK%^This is a strange black stone."+
  "  It floats in the air around its owner in circles."+
  " The owner of this stone could tell it to 'return' if needed.%^RESET%^");
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
  set_funcs(({"strike_func"}));
  set_func_chance(100);
  set_attacks_num(1);
  set_heart_beat(5);
  set_body_type("snake");
  remove_limb("mouth");
  remove_limb("head");
  remove_limb("tail");
  remove_limb("torso");
  add_limb("stone","stone",0,0,0);

}
void owned(object jimmy){
 if(!objectp(jimmy))return;
 dude = jimmy;
}
int strike_func( object who){
      if(!objectp(dude))return 0;
        tell_room(ETO,"%^BOLD%^%^RED%^The "+query_short()+
		" orbiting "+dude->QCN+"'s head fires a dart of "+
		"magical energy at "+who->QCN+"!",({who}));

        tell_object(who,"%^BOLD%^%^RED%^The "+query_short()+
		"  orbiting "+dude->QCN+"'s head fires a magical dart"+
		" of energy at you, zapping you!");
          
		who->cause_typed_damage(who,0,roll_dice(5,10)+20,"electricity");
				

return 1;
}
void die(object ob){
 tell_room(ETO,""+query_short()+" breaks apart, shattering into %^RESET%^%^ORANGE%^dust!");
   ::die(ob);
}
void heart_beat(){
object *foes;
::heart_beat();
if(!dude || !objectp(dude) )return;

foes=dude->query_attackers();
if (foes == ({})) return;
strike_func(foes[random(sizeof(foes))]);
return;
}
void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
   if(!msg || !objectp(who)) return;
   if (base_name(who) == base_name(TO)) return;
   if((strsrch(msg,"return") != -1) &&  dude == who){
   tell_room(ETO,"The stone stops orbiting and drops back to the ground.");
   new(OBJ"bioun")->move(ETO);
   remove();
}
}
   
