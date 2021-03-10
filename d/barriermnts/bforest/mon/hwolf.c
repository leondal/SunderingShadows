#include <std.h>
#include "../bforest.h"
inherit WEAPONLESS;
void create (){

::create ();
   set_name("A scraggly looking wolf");
   set_id(({"Dire Wolf","dire wolf","wolf"}));
   set_short("%^BOLD%^%^BLACK%^A scraggly looking wolf%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This is a very large wolf who has obviously been"
" taught to hunt.  Larger than most wolves by quite alot, he has scraggly"
" black hair with a a grey back.  Two %^YELLOW%^glowing yellow eyes %^BLACK%^set within his head,"
" above a strong jaw lined with sharp %^WHITE%^canines.  %^BLACK%^A spiked collar lines his neck, marking"
" him as somebody's property.%^RESET%^");
   set_race("wolf");
   set_gender("male");
   set_body_type("quadruped");
   set_hd(13,2);
   set_overall_ac(-2);
   set_size(2);
   set_stats("intelligence",2);
   set_stats("strength",18);
   set_stats("wisdom",12);
   set_stats("dexterity",15);
   set_stats("constitution",18);
   set_stats("charisma",6);
   set_class("fighter");
   set_moving(1);
   set_speed(60);
   set_exp(2450);
   set_alignment(3);
   set_damage(1,8);
   set_hp(random(100)+200);
   set_max_hp(query_hp());  
   set_property("full attacks",1);
   set("aggressive",19);
   set("aggressive","aggfunc");
   add_limb("left claws","left forepaw",0,0,0);
   add_limb("right claws","right forepaw",0,0,0);
   add_limb("teeth","mouth",0,0,0);
   set_attack_limbs(({"right claws","teeth","left claws"}));
   set_base_damage_type("slashing");
   set_achats(2, ({"%^BOLD%^%^BLACK%^The wolf glares at you as he lunges at you again.%^RESET%^",
"%^BOLD%^%^BLACK%^The wolf snarls visciously as he bares his %^RESET%^teeth %^BOLD%^%^BLACK%^at you!%^RESET%^"}) );
}
int aggfunc() {
   force_me("emote tilts its head back and howls for the hunt.");
   message("info","%^BOLD%^%^BLACK%^A loud howl echoes throughout the area...  The hunt is on!",nearbyRoom(ETP,2));
   call_out("follower",1); //added this to get them to follow
   force_me("kill "+TPQN+ "");
}
int follower(){
   TP->add_follower(TO);
}

