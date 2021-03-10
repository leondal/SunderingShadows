#include "/d/common/common.h"
#include <std.h>
inherit WEAPONLESS;

void create() {
   ::create();
   set_name("wraith");
   set_id(({"wraith","Wraith","undead","ghastly wraith"}));
   set_gender("neuter");
   set_race("wraith");
   set_short("%^RESET%^%^BLUE%^A ghastly wraith%^RESET%^");
   set_long("%^GREEN%^This undead creature is hard to make out, and all the more terrifying for its constant "
"disappearing and reappearing.  It seems more like a %^RESET%^shadow %^GREEN%^or a whisp of fog than a true "
"being.  The only feature you're able to fix upon is the glowing %^RED%^crimson %^GREEN%^eyes that glare forth "
"with a supernatural hatred.  It drifts forwards, uttering an earsplitting shriek!%^RESET%^");
   set_hd(4,1);
   set_property("undead",1);
   set_property("swarm",1);
   set_body_type("humanoid");
   set_class("fighter");
   set_level(4);
   set_size(2);
   set_alignment(9);
   set_stats("intelligence",16);
   set_stats("wisdom",8);
   set_stats("strength",12);
   set_stats("charisma",3);
   set_stats("dexterity",9);
   set_stats("constitution",10);
   set_base_damage_type("slashing");
   add_limb("right claw","right hand",0,0,0);
   add_limb("left claw","left hand",0,0,0);
   set_attack_limbs(({"mouth","left claw","right claw"}));
   set_hp(random(15)+35);
   set_max_hp(query_hp());
   set("aggressive",25);
   add_money("gold",random(25)+25);
   set_overall_ac(8);
   set_exp(60);
   set_achats(1, 
     ({ "%^RED%^The wraith's eyes seem to glow red.%^RESET%^", 
        "%^ORANGE%^The wraith shrieks and rushes at you!%^RESET%^"
     }) );
   set_new_exp(1, "very low");
}