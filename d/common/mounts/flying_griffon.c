//Octothorpe (4/14/10)
//Griffon flying mount

#include <std.h>
inherit "/std/flying_mount.c";

void create(){
   ::create();
   set_name("griffon");
   set_id(({"mount","griffon","grifon"}));
   set_short("%^YELLOW%^regal griffon%^RESET%^");
   set_long("%^YELLOW%^This powerfully built creature resembles a "+
      "cross between a giant eagle and a lion.  The front half of "+
	  "the griffon bears the characteristics of an eagle, raptor "+
	  "legs and head, as well as a pair of broad wings.  The latter "+
	  "half is composed of the muscular and sleek frame of a lion");
   set_level(10);
   set_riding_level(10);
   set_value(2000);
   set_race("griffon");
   set_gender("male");
   set_body_type("hippogriff");
   set_size(3);
   set_max_hp(200);
   set_hd(10,4);
   set_hp(250);
   set_overall_ac(0);
   set_exp(10);
   set_max_distance(200);
   set_enter_room("rides in.");
   set_exit_room("leaves riding a griffon.");
   set_vehicle_short("%^YELLOW%^regal griffon%^RESET%^");
   add_limb("beak","head",0,0,0);
   add_limb("right leg","torso",0,0,0);
   add_limb("left leg","torso",0,0,0);
   add_limb("torso","torso",0,0,0);
   add_limb("head","torso",0,0,0);
   set_attack_limbs( ({"beak","right leg","left leg"}) );
   set_attacks_num(3);
   set_damage(2,6);
   set_flight_delay(300);
   set_flying_prof(25);
   set_ward_pass(25);
}

void init(){
   string mrace = TP->query_race();
   ::init();
   if(mrace == "horse"){
      if(!random(4)){
	     tell_room(ETP,"%^YELLOW%^The griffon lunges towards his equine "+
		    "target, hoping to make a meal out of it!%^RESET%^");
		 command("kill horse");
      }
	  else{
	     tell_room(ETP,"%^YELLOW%^The griffon leers hungrily at the horse "+
	        "as it enters the area.%^RESET%^");
	  }
   }
}
