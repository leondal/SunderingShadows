#include <std.h>
#include "../bpeak.h"
inherit WEAPONLESS;
void create (){

::create ();
   set_name("A scraggly looking wolf");
   set_id(({"Dire Wolf","dire wolf","wolf"}));
   set_short("%^BOLD%^%^BLACK%^A scraggly looking wolf%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This is a very large and shaggy"
" wolf who constantly seems to circle and pace around the area. "
" His fur is a dull %^RESET%^grey %^BOLD%^%^BLACK%^in color with"
" darker black markings on his head, shoulders and back. "
" His head is lowered, and his %^YELLOW%^glowing %^BLACK%^eyes"
" never seem to stray away from you.  His muscles ripple as he"
" moves and %^RESET%^drool %^BOLD%^%^BLACK%^seems to constantly"
" drip from his mouth.%^RESET%^");
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
   set_nogo(({INRMS+"stwy3"}));
   set_exp(2450);
   set_alignment(3);
   set_damage(1,8);
   set_hp(random(100)+200);
   set_max_hp(query_hp());  
   set_property("full attacks",1);
   set("aggressive",19);
   add_limb("left claws","left forepaw",0,0,0);
   add_limb("right claws","right forepaw",0,0,0);
   add_limb("teeth","mouth",0,0,0);
   set_attack_limbs(({"right claws","teeth","left claws"}));
   set_base_damage_type("slashing");
   set_achats(2, ({"%^BOLD%^%^BLACK%^The wolf glares at you as he lunges at you again.%^RESET%^",
"%^BOLD%^%^BLACK%^The wolf snarls visciously as he bares his %^RESET%^teeth %^BOLD%^%^BLACK%^at you!%^RESET%^"}) );
     set_emotes(1, ({"%^BOLD%^%^BLACK%^The wolf raises its nose to the air and sniffs.",
"The wolf raises its nose high and lets out a chilling howl.",
"With a soft thud, the wolf throws itself on the ground and pants softly.",
"%^BOLD%^%^BLACK%^The wolf growls quietly.%^RESET%^",
"%^BOLD%^%^BLACK%^Pacing around slowly, the wolf eyes its surroundings.%^RESET%^",}), 0);

}
