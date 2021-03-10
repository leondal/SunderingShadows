//Octothorpe (4/13/10)
//Giant Eagle mount

#include <std.h>
inherit "/std/flying_mount.c";

void create(){
   ::create();
   set_name("giant eagle");
   set_id(({"giant eagle","eagle"}) );
   set_short("%^RESET%^%^ORANGE%^m%^YELLOW%^a%^RESET%^%^ORANGE%^"+
      "jestic gi%^YELLOW%^a%^RESET%^%^ORANGE%^nt e%^YELLOW%^a"+
	  "%^RESET%^%^ORANGE%^gle%^RESET%^");
   set_long("%^ORANGE%^This bird is a truly impressive sight to "+
      "behold, measuring roughly fourteen feet tall, and a wingspan "+
	  "stretching nearly thirty feet.  Its plummage is a deep brown, "+
	  "with some of its feathers darkening nearly to a %^BOLD%^%^BLACK%^"+
	  "blackish %^RESET%^%^ORANGE%^hue.");
   set_level(10);
   set_riding_level(10);
   set_value(2000);
   set_race("giant eagle");
   set_gender("male");
   set_body_type("hippogriff");
   set_size(3);
   set_max_hp(200);
   set_hp(200);
   set_hd(10,4);
   set_hp(200);
   set_overall_ac(5);
   set_exp(10);
   set_max_distance(200);
   set_enter_room("rides in.");
   set_exit_room("leaves riding a giant eagle.");
   set_vehicle_short("%^RESET%^%^ORANGE%^m%^YELLOW%^a%^RESET%^%^ORANGE%^"+
      "jestic gi%^YELLOW%^a%^RESET%^%^ORANGE%^nt e%^YELLOW%^a"+
	  "%^RESET%^%^ORANGE%^gle%^RESET%^");
   add_limb("beak","head",0,0,0);
   add_limb("right leg","torso",0,0,0);
   add_limb("left leg","torso",0,0,0);
   add_limb("torso","torso",0,0,0);
   add_limb("head","torso",0,0,0);
   set_attack_limbs( ({"beak","right leg","left leg"}) );
   set_attacks_num(3);
   set_damage(1,6);
   set_flight_delay(300);
   set_flying_prof(25);
   set_ward_pass(25);
}
