// rank 5 beastie
// coded by ~Circe~ 3/27/13
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"rhinoceros","plated rhinoceros","natures ally"}));
    set_short("%^BOLD%^%^BLACK%^plated rhi%^WHITE%^n%^BLACK%^"
       "ocer%^WHITE%^o%^BLACK%^s%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This massive creature is six feet "
       "tall at the shoulder and over nine feet in length with a "
       "thin, two-foot-long tail.  Over three-thousand pounds of "
       "muscle cover its hulking frame, making this beast terrifying "
       "for more than the three-foot horn on its head.%^RESET%^");
    set_race("rhinoceros");
    set_body_type("equine");
    add_limb("horn","head",0,0,0);
    set_attack_limbs(({"right fore hoof","left fore hoof","horn"}));
    set_base_damage_type("bludgeoning");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^BOLD%^%^RED%^Lowering its head, the rhino charges, goring you!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^RED%^Lowering its head, the rhino charges, goring "+target->QCN+"!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(50)+mylevel);
    TO->remove_property("magic");
}