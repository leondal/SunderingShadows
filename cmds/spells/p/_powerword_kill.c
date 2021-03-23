//Powerword Kill coded by Bane
//Revised for school spells by Nienne, 10/09.
#include <std.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

int current;
string target_limb;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("powerword kill");
    set_spell_level(([ "mage" : 9, "cleric" : 9 ]));
    set_domains(({ "war" }));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS powerword kill on TARGET");
    set_damage_desc("untyped");
    set_description("When the powerword kill spell is uttered, any creature of the mage's choice will drop dead if it has "
"fewer current hit points then the mage's power. The target may still be weakened even if this is not the case, but "
"creatures immune to death magic will be completely unaffected.");
    mental_spell();
    set_verbal_comp();
    set_silent_casting(1);
    set_target_required(1);
     // school specific mage spell
}

void spell_effect(int prof) {
    int difflevel, myoutput, mydmg;

    if (!present(target,environment(caster))) {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }
    tell_object(caster,"%^BOLD%^%^GREEN%^You take in a deep breath and scream the words, 'GRIMMUS MORRTES!!!'");
    tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" takes in a deep breath and screams the words, 'GRIMMUS MORRTES!!!'",({caster}));
    spell_successful();
    spell_kill(target, caster);

    // Ray of ending, clashing rocks and this one should share disadvantage value
    if (combat_death_save(target, 0) || mind_immunity_damage(target)) {
        tell_object(target,"%^BOLD%^You feel a tug at your life force, but shrug it off easily!");
        tell_room(place,"%^BOLD%^"+target->QCN+" seems to shrug the spell off effortlessly.",({target}));
        dest_effect();
        return;
    }
    mydmg = sdamage;
    current = target->query_hp();
    //commented out because it doesn't actually do anything at present Odin 2/23/2020
    //difflevel = clevel - (int)target->query_level();
    //if(difflevel < 0) difflevel = 0;
    target_limb = target->return_target_limb();
    if (current > mydmg) {
        tell_object(target,"%^BOLD%^You feel a tug at your life force, but with some difficulty you fight it off!");
        tell_room(place,"%^BOLD%^"+target->QCN+" staggers in pain momentarily, but soon recovers.",({target}));
        damage_targ(target, target_limb, sdamage,"untyped");
    }
    else {
        tell_object(target,"%^BOLD%^You reel backward in utter agony, and the world around you goes black!");
        tell_room(place,"%^BOLD%^"+target->QCN+" screams in agony and then falls to the ground!",({target}));
        target_limb = target->return_target_limb();
        damage_targ(target, target_limb, ((int)target->query_max_hp() + sdamage),"untyped");
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
