// rank 5 beastie
// coded by ~Circe~ 3/25/13
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"arrowhawk","adult arrowhawk","natures ally"}));
    set_short("%^RESET%^%^ORANGE%^adu%^CYAN%^l%^ORANGE%^t arro%^CYAN%^w%^ORANGE%^hawk%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^An unusual avian from the plane "
       "of %^CYAN%^air%^ORANGE%^, the arrowhawk is a strange-looking "
       "creature that is almost perfectly symmetrical along the "
       "horizontal plane.  It possesses two sets of eyes - one above "
       "and one below its beak - two pairs of wings, and even two "
       "tongues.  Its wings are tan tinged with %^CYAN%^blue%^ORANGE%^, "
       "as is its vicious-looking %^CYAN%^beak%^ORANGE%^.  The arrowhawk "
       "is a fierce defender of its territory and is known for its "
       "insatiable hunger - a deadly combination.%^RESET%^");
    set_race("arrowhawk");
    set_body_type("fowl");
    set_attack_limbs(({"right claw","left claw","beak"}));
    set_base_damage_type("piercing");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^YELLOW%^Lightning shoots from the arrowhawk's beak, zapping you!%^RESET%^");
    tell_room(ETO,"%^YELLOW%^Lightning shoots from the arrowhawk's beak, zapping "+target->QCN+"!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(50)+mylevel);
    TO->remove_property("magic");
}