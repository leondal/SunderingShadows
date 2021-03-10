#include <std.h>
#include "../yntala.h"
inherit WEAPONLESS;
void create (){
   object ob;
::create ();
   set_name("Dire Bear");
   set_id(({"Dire Bear","dire bear","bear"}));
   set_short("%^BOLD%^%^BLACK%^A giant bear%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This is a very large and mean"
" version of its normal counterpart.  One of the things that set"
" this creature apart from a regular bear are of course its size,"
" reaching as much as twelve feet long and weighing close to"
" eight thousand pounds, but an unusual bony ridge runs across"
" its brow, and its claws are absolutely huge, giving it an"
" almost prehistoric appearance.%^RESET%^");
   set_race("bear");
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
   set_nogo(({INRMS+"forest33","/d/darkwood/tabor/road/road6"}));
   set_exp(2500);
   set_max_level(14);
   set_alignment(3);
   set_damage(2,8);
   set_hp(random(100)+100);
   set_max_hp(query_hp());  
   set_property("full attacks",1);
   set("aggressive",19);
   add_limb("left claws","left forepaw",0,0,0);
   add_limb(" right claws","right forepaw",0,0,0);
   set_attack_limbs(({"right claws", "left claws"}));
   set_base_damage_type("slashing");
   set_achats(2, ({"%^BOLD%^%^BLACK%^The bear stands up to its full height and lunges for you again!%^RESET%^",
"%^BOLD%^%^BLACK%^The bear growls ferociously before attacking you!%^RESET%^"}) );
    if(!random(5)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}

