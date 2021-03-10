#include <std.h>
#include "../lothwaite.h"
inherit WEAPONLESS;

void create()
{
	::create();
	set_name("firbolg skeleton");
	set_id(({"skeleton","monster","undead","firbolg skeleton","firbolg"}));
	set_short("A firbolg skeleton");
	set_long(
         "%^BOLD%^%^WHITE%^This stark white figure is made of nothing but "+
         "bones.  Though once a firbolg, no skin or sinew remains "+
         "on its frame.  The hair from its head has long since "+
         "faded away, leaving nothing but ivory-colored bone.  "+
         "No eyes remain in the sockets, yet the skeleton seems "+
         "to stare at you, and you sense a cold malice in this "+
         "once-gentle giant."
	);
	set_gender("male");
	set_race("skeleton");
	set_body_type("human");
	set_size(3);
	set_property("undead",1);
	set_hd(20,3);
	set_max_level(25);
	set_level(17);
	set_class("fighter");
	set_mlevel("fighter",17);
	set_stats("dexterity",6);
	set_stats("charisma",1);
	set_stats("strength",16);
	set_max_hp(random(25)+100);
	set_hp(query_max_hp());
	set_overall_ac(-8);
	set_exp(3500);
	set("aggressive","aggfunc");
	set_property("swarm",1);
      set_damage(1,8);
      set_attacks_num(2);
      set_base_damage_type("bludgeoning");
      set_attack_limbs(({"left hand","right hand"}));
      set_moving(1);
      set_speed(60);
      set_nogo(({"/d/barriermnts/lothwaite/rooms/b1", "/d/barriermnts/lothwaite/rooms/stones2"}));
      force_me("message in rattles in");
      force_me("message out rattles $D");
}

int aggfunc(){
   call_out("check_vis",1,TP);
   return 1;
}

int check_vis(){
   if(TP->query_invis()){
      if(!random(3)){
         tell_object(TP,"%^RED%^The skeleton's lifeless face turns "+
            "straight toward you!");
         force_me("kill "+TPQN+"");
      }
      return 1;
   }else{
      force_me("kill "+TPQN+"");
      return 1;
   }
}

void die(mixed ob){
   tell_room(ETO,"The skeleton crumbles to dust.");
   ::die(ob);
}