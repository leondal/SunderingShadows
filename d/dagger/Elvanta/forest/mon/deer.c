//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
set_id(({"deer"}));
set_name("deer");
set_short("grazing deer");
    set_long(
"Deer stroll around the green park like area, stopping to graze upon the verdent green.");
    set_body_type("quadruped");
set_race("deer");
set_gender("female");
    set_size(2);
set_hd(15,10);
    set_hp(50);
set_exp(100);
    set_overall_ac(5);
set("agressive",12);
    set_attack_limbs(({"head"}));
    set_attacks_num(1);
    set_base_damage_type("piercing");
    set_damage(3,4);
}
