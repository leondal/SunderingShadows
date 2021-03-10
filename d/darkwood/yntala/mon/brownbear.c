#include <std.h>
#include "../yntala.h"
inherit WEAPONLESS;
void create (){
   object ob;
::create ();
   set_name("Brown Bear");
   set_id(({"Brown Bear","brown bear","bear"}));
   set_short("%^RESET%^%^ORANGE%^A shaggy brown bear%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This is a large brown bear with long, shaggy fur and large, muscular legs and shoulders.  His muscles ripple as he lumbers around and he looks to be quite cranky.%^RESET%^");
   set_race("bear");
   set_gender("male");
   set_body_type("quadruped");
   set_hd(12,2);
   set_overall_ac(-2);
   set_size(2);
   set_stats("intelligence",2);
   set_stats("strength",18);
   set_stats("wisdom",12);
   set_stats("dexterity",13);
   set_stats("constitution",18);
   set_stats("charisma",6);
   set_class("fighter");
   set_moving(1);
   set_speed(60);
   set_exp(1000);
   set_max_level(12);
   set_alignment(5);
   set_damage(1,8);
   set_hp(random(50)+100);
   set_max_hp(query_hp());  
   set_property("full attacks",1);
   set("aggressive","aggfunc");
   add_limb("claws","left forepaw",0,0,0);
   set_attack_limbs(({"claws"}));
   set_base_damage_type("slashing");
   set_achats(2, ({"%^BOLD%^%^BLACK%^The bear roars ferociously.%^RESET%^","%^BOLD%^%^BLACK%^The bear readies to attack you again!%^RESET%^."}) );
    if(!random(4)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}
int aggfunc() {
        command("emote roars.");
        if(!TP->query_invis()){
           command("kill "+TPQN);
        }
}
