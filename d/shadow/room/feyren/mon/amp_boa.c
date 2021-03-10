#include <std.h>
#include "../inherits/area_stuff.h"
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("amphibious boa");
    set_id(({"snake", "boa", "amphibious boa"}));
    set_short("%^RESET%^%^GREEN%^Giant %^BOLD%^green%^RESET%^"+
    "%^GREEN%^ scaled boa");
    set_long("%^BOLD%^%^GREEN%^This green scaled boa "+
    "is massive. It stretches approximately ten feet in "+
    "length from head to tail and has streaks of "+
    "varying shades of %^RESET%^%^RED%^red%^BOLD%^"+
    "%^GREEN%^ running throughout its body. It is thick, "+
    "perhaps two feet in circumference and its "+
    "head is even larger. Its slitted eyes are "+
    "dull and lifeless, as if they do not really "+
    "serve any purpose. At the base of its head "+
    "are what appears to be gills, the apparent "+
    "mechanism that allows it to survive underwater. "+
    "It has four fangs, instead of two, and each "+
    "one is dripping an acidic %^BOLD%^%^YELLOW%^goo"+
    "%^BOLD%^%^GREEN%^.%^RESET%^");

    set_hd(14,1);
    set_hp((9*14)+random(10));
    set_body_type("snake");
    set("aggressive", 26);
    set_damage(2,6);
    set_attacks_num(2);
    set_attack_limbs(({"mouth"}));
    set_base_damage_type("piercing");
    set_base_damage_type("piercing");
    set_gender("male");
    set_race("snake");
    set_new_exp(12, "normal");
    set_alignment(5);
    set_overall_ac(3);
    set_moving(10);
    set_speed(25);
    set_nogo(({OA, FFTR"13", FFGTR"29"}));
    set_property("water breather", 1);
}

