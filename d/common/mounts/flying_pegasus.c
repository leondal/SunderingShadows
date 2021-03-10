//Adapted from /d/common/mounts/pegasus.c as a normal flying
//mount - Octothorpe 7/6/11
#include <std.h>

inherit "/std/flying_mount.c";

void create(){
    ::create();
    set_name("pegasus");
    set_short("%^BOLD%^%^WHITE%^beautiful winged pegasus%^RESET%^");
    set_id(({"mount","pegasus","winged pegasus"}));
    set_long("%^BOLD%^%^WHITE%^This breathtaking mount seems to be a "+
       "fine horse with delicate, feathery wings.  The pegasus's "+
       "mane is a %^YELLOW%^golden blonde %^WHITE%^that shimmers "+
       "in a light all its own, and its %^BLUE%^sapphire eyes "+
       "%^WHITE%^sparkle with an intelligence unmatched by any "+
       "mere beast.");
   if(random(2)) set_gender("male");
   else set_gender("female");
   set_race("pegasus");
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
   set_flight_delay(300);
   set_flying_prof(25);
   set_ward_pass(25);
   set_enter_room("rides in.");
   set_exit_room("leaves riding a pegasus.");
   set_funcs(({"special"}));
   set_func_chance(15);
}

void special(object target) {
   tell_room(ETO,"%^BOLD%^%^WHITE%^The pegasus rears up with a flap of its massive wings, and lashes out with "
"both forehooves at "+target->QCN+"!%^RESET%^",target);
   tell_object(target,"%^BOLD%^%^WHITE%^The pegasus rears up with a flap of its massive wings, and lashes out "
"with both forehooves at you!%^RESET%^");
   TO->set_property("magic",1);
   target->do_damage(target->return_target_limb(),(roll_dice(3,6))+6);
   TO->remove_property("magic");
}
