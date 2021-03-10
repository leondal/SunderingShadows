#include <std.h>
#include "../yntala.h"
inherit WEAPONLESS;

void create (){
object ob;
::create ();
   set_name("Girallon");
   set_id(({"Girillon","girallon","gorilla","Girallon"}));
   set_short("%^RESET%^A large gorilla like creature%^RESET%^");
   set_long("%^RESET%^This amazingly large beast looks much like"
" a gorilla, but has four arms instead of two.  His fur is"
" completely %^BOLD%^%^WHITE%^white, %^RESET%^giving him an almost"
" albino appearance.  His chest is broad and well muscled, leading"
" into large arms that end in clawed hands that look very much"
" like they would tear apart anything he decided to use them on."
" %^RESET%^");
   set_race("girallon");
   set_gender("male");
   set_body_type("quadruped");
   set_hd(13,1);
   set_overall_ac(-3);
   set_size(2);
   set_stats("intelligence",16);
   set_stats("strength",19);
   set_stats("wisdom",13);
   set_stats("dexterity",16);
   set_stats("constitution",12);
   set_stats("charisma",14);
   set_hp(random(200)+75);
   set_max_hp(query_hp());  
    set_exp(2500);
   set_max_level(14);
   set_moving(1);
   set_nogo(({"/d/darkwood/yntala/rooms/forest33","/d/darkwood/tabor/road/road6"}));
   set_speed(25);
   set_alignment(9);
   set_damage(1,8);
   set_property("full attacks",1);
   set("aggressive",19);
   add_limb("left claws","left arm",0,0,0);
   add_limb("right claws","right arm",0,0,0);
   add_limb("teeth","mouth",0,0,0);
   set_attack_limbs(({"left claws","right claws","teeth"}));
   set_base_damage_type("slashing");
   set_func_chance(10);
   set_funcs(({"rend"}));
   set_achats(2, ({"The girallon beats on his chest wildly before attacking again!"}) );
    if(!random(4)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}
void rend(object target) {
   if(!"daemon/saving_d"->saving_throw(target,"paralyzation_poison_death")) {
   tell_room(ETO,"%^BOLD%^%^RED%^The girallon grabs "+target->query_cap_name()+" viciously, tearing at "+target->query_possessive()+" flesh and making "+target->query_objective()+" scream out in pain!",target);
   tell_object(target, "%^BOLD%^%^RED%^You scream in agony as the girallon rips at your flesh!");
   target->set_paralyzed(10,"You are still reeling in pain.");
   return roll_dice(1,4)+12;
   return 1;
   } 
   tell_room(ETO,"%^BOLD%^%^BLACK%^"+target->query_cap_name()+" dives out of the way just as the girallon lunges for "+target->query_objective()+" !%^RESET%^",target);
   tell_object(target, "%^BOLD%^%^BLACK%^You dive out of the way as the girallon lunges for you!");
   return 1;
}


