// rank 5 beastie
// coded by ~Circe~ 3/25/13
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"lion","dire lion","natures ally"}));
    set_short("%^RESET%^%^ORANGE%^di%^YELLOW%^r%^RESET%^%^ORANGE%^e l%^YELLOW%^i%^RESET%^%^ORANGE%^on%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^Fifteen feet in length, this dire "
       "lion is a force to be reckoned with.  Its powerful, muscular "
       "body is covered in %^BOLD%^g%^RESET%^%^ORANGE%^o%^BOLD%^l"
       "%^RESET%^%^ORANGE%^d%^BOLD%^e%^RESET%^%^ORANGE%^n fur set "
       "off by a %^RED%^russet mane %^ORANGE%^tinged with %^BOLD%^"
       "%^BLACK%^black%^RESET%^%^ORANGE%^.  A tufted tail-tip "
       "matches the russet shade of its shaggy mane, framing a "
       "predator's face with sharp eyes and a mouth of sharper "
       "fangs.  Its lip draws back in an occasional rumbled "
       "snarl, its paws flexing to reveal deadly claws "
       "sheathed within.%^RESET%^");
    set_race("dire lion");
    set_body_type("quadruped");
    add_limb("left claws","left forepaw",0,0,0);
    add_limb("right claws","right forepaw",0,0,0);
    set_attack_limbs(({"right claws","left claws"}));
    set_base_damage_type("slashing");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^RESET%^%^ORANGE%^A low growl rumbles from the dire lion's throat as it crouches down before pouncing on you!%^RESET%^");
    tell_room(ETO,"%^RESET%^%^ORANGE%^A low growl rumbles from the dire lion's throat as it crouches down before pouncing on "+target->QCN+"!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(50)+mylevel);
    TO->remove_property("magic");
}