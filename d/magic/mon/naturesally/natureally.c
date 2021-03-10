#include "../summoned_monster.h"
#include <std.h>

inherit WEAPONLESS;

object cast;
int mylevel;

void create()
{
    ::create();
    set_name("natures ally");
    set_id(({"natures ally"}));
    set_short("natures ally");
    set_long("this is an animal");
    set_hd(4,1);
    set_hp(40);
    set_exp(1);
    set_stats("strength",18);
    set_stats("intelligence",7);
    set_stats("dexterity",25);
    set_damage(2,10);
    set_attacks_num(2);
    set_base_damage_type("bludgeoning");
    if(random(2)) set_gender("female");
    else set_gender("male");
    set_overall_ac(4);
    set_funcs(({"my_special"}));
    set_func_chance(20);
}

void my_special(object target) 
{
    if(!objectp(target)) return;
    tell_room(ETO,"Default function.");
}

void set_mylevel(int num) 
{ 
    mylevel = num;
    set_property("effective_enchantment",mylevel/7);
}