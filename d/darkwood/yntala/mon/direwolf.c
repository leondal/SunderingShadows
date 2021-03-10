#include <std.h>
#include "../yntala.h"
inherit WEAPONLESS;
void create (){
   object ob;
::create ();
   set_name("Dire Wolf");
   set_id(({"Dire Wolf","dire wolf","wolf"}));
   set_short("%^BOLD%^%^BLACK%^A shaggy wolf%^RESET%^");
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
   set_hd(9,2);
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
   set_nogo(({"/d/darkwood/tabor/road/road6","/d/darkwood/yntala/rooms/forest33","/d/darkwood/yntala/rooms/forestpath"}));
   set_exp(2300);
   set_max_level(13);
   set_alignment(3);
   set_damage(1,5);
     set_hp(random(200)+75);
   set_max_hp(query_hp());  
   set_property("full attacks",1);
   set("aggressive",19);
   add_limb("left claws","left forepaw",0,0,0);
   add_limb("right claws","right forepaw",0,0,0);
   add_limb("teeth","mouth",0,0,0);
   set_attack_limbs(({"right claws","teeth","left claws"}));
   set_base_damage_type("slashing");
   set_achats(2, ({"%^BOLD%^%^BLACK%^The wolf glares at you as he lunges at you again.%^RESET%^",
"%^BOLD%^%^BLACK%^The wolf snarls viciously as he bares his %^RESET%^teeth %^BOLD%^%^BLACK%^at you!%^RESET%^"}) );
    if(!random(8)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}
