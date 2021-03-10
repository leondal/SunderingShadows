#include <std.h>
inherit "/std/flying_mount.c";

void create(){
   ::create();
   set_name("nightmare");
   set_vehicle_short("nightmare");
   set_short("%^BOLD%^%^RED%^fie%^YELLOW%^r%^RED%^y %^BLACK%^black nightmare%^RESET%^");
   set_id(({"mount","nightmare","fiery nightmare","black nightmare"}));
   set_race("nightmare");
   set_long("%^BLACK%^%^BOLD%^This gaunt, almost %^RESET%^%^WHITE%^skeletal%^BLACK%^%^BOLD%^ stallion is "
"nearly six feet tall at the shoulder, with a hide of black fur the colour of darkest coal.%^RED%^  "
"Bu%^YELLOW%^r%^RED%^ning ey%^YELLOW%^e%^RED%^s%^BLACK%^ peer forth from its equine face like %^RED%^red-hot "
"embers%^BLACK%^, matched by its %^RED%^bla%^YELLOW%^z%^RED%^ing%^BLACK%^ nostrils, and a "
"%^YELLOW%^f%^RED%^lami%^YELLOW%^n%^RED%^g%^BLACK%^ mane and tail that writhe with an inner intensity.  Its "
"hooves look as though they are made from glossy obsidian, and trail their own lines of %^RED%^fire%^BLACK%^ "
"through the air, striking the ground with %^YELLOW%^s%^WHITE%^pa%^YELLOW%^rk%^WHITE%^s%^BLACK%^ as they "
"travel.  The creature is what is known as a Nightmare, a fearsome sight to behold.%^RESET%^");
   if(random(2)) set_gender("male");
   else set_gender("female");  
   set_exit_room("leaves riding a fiery nightmare.");
   set_funcs(({"special"}));
   set_func_chance(15);
   TO->force_me("message in trots in, breathing whisps of flame from its nostrils.");
   TO->force_me("message out trots out $D.");
   set_race("nightmare");
   set_level(10);
   set_value(2000);
   set_riding_level(10);
   add_limb("right foreleg","torso",0,0,0);
   add_limb("left foreleg","torso",0,0,0);
   add_limb("right rear leg","torso",0,0,0);
   add_limb("left rear leg","torso",0,0,0);	
   add_limb("torso","torso",0,0,0);
   add_limb("head","torso",0,0,0);
   set_attack_limbs( ({"right leg","left leg"}) );
   set_damage(1,6);
   set_body_type("equine");
   set_max_hp(200);
   set_hp(200);
   set_hd(10,4);
   set_overall_ac(5);
   set_exp(10);
   set_max_distance(200);
   set_flight_delay(900);
   set_flying_prof(30);
   set_ward_pass(25);   
}

void special(object target) {
   tell_room(ETO,"%^RED%^%^BOLD%^The nightmare unleashes a breath of burning flames through the air at "
+target->QCN+"!%^RESET%^",target);
   tell_object(target,"%^RED%^%^BOLD%^The nightmare unleashes a breath of burning flames through the air at "
"you!%^RESET%^");
   TO->set_property("magic",1);
   target->do_damage(target->return_target_limb(),(roll_dice(3,6))+6);
   TO->remove_property("magic");
}
