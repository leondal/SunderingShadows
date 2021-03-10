#include <std.h>

inherit "/std/trainer";

void create(){
    ::create();
    set_name("connor");
    set_short("Connor, Master-at-Arms of Tabor");
    set_long(
@TABOR
Specialized in all forms of armed and unarmed combat, Connor is the 
Master-at-Arms of Tabor, and no one disputes his title. His eyes are 
like chips of cold, hard flint as he looks over everything and everyone. 
You can tell that in every look, he is assessing offensive and defensive 
strengths and weaknesses in everyone.  Like many trainers, he trains 
without weapons, hoping to give students instructions as he shows common 
problems.
TABOR
    );
    set_hd(35,5);
    set_exp(1);
    set_property("no bows",1);
    set_stats("strength", 11);
    set_max_hp(300);
    set_attack_limbs(({"right hand","left hand"}));
    set_attacks_num(1);
    set_damage(1,1);
    set_stats("strength",15);
    set_race("human");
    set_gender("male");
    set_id(({"connor","Connor","trainer","master"}));
    set_base_damage_type("bludgeoning");
    set_overall_ac(0);
    remove_std_db();
}
