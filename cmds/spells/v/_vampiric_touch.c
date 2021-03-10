//Vampiric touch coded by Bane//

#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

int thac0, AC, roll, hp_before, hp_after;
int num;
string target_limb;
object env;
void dest_effect();

create() {
    ::create();
    set_spell_name("vampiric touch");
    set_spell_level(([ "mage" : 3, "paladin" : 3, "inquisitor" : 3, "magus" : 3 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS vampiric touch on TARGET");
    set_damage_desc("negative energy on TARGET, untyped on self");
    set_description("This spell, when cast, will allow the mage to drain a certain amount of hit points from an opponent and add them to his own, if he makes a successful touch attack against the victim. The spell will only heal the caster up to his maximum hit points. Using negative energy, this spell is ineffective against the undead, it heals caster with untyped damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

spell_effect(int prof) {

    spell_successful();
    target_limb = target->return_target_limb();
    if (interactive(caster)) {
        tell_object(caster,"%^BOLD%^%^BLUE%^You reach your glowing red hand out towards "+target->QCN+" attempting to absorb "+target->QP+" life energy!");
        tell_object(target,"%^BOLD%^%^BLUE%^"+caster->QCN+" reaches out with a glowing red hand attempting to touch you!");
        tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+" reaches out with a glowing red hand and attempts to touch "+target->QCN+"!",({caster, target}));
    } else {
        tell_object(target,"%^BOLD%^%^BLUE%^"+caster->QCN+" cackles evilly and attempts to touch you!");
        tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+" cackles evilly and attempts to touch "+target->QCN+"!", target);
    }
    env = environment(caster);
    if (!present(target,env)) {
        tell_object(caster,"%^BOLD%^%^CYAN%^Your target has escaped before you could touch "+target->QO+"!");
        TO->remove();
        return;
    }
    if(!caster->ok_to_kill(target)) {
        dest_effect();
        return 0;
    }

    roll = random(20)+1;
    if (caster->Thaco(1,target,0) <= roll||caster->query_property("spectral_hand")) {
//        if(){
        if (target->query_race()=="undead"||(int)target->query_property("undead")) {
            tell_object(caster,"%^BOLD%^%^MAGENTA%^You touch "+target->QCN+", but "+target->QS+" is unaffected.");
            tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" touches "+target->QCN+", but "+ target->QS+" appears to be unaffected.",({target, caster}));
            spell_kill(target, caster);
        } else {
            tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" reaches out and touches your "+target_limb+" draining the very essence of your life from your veins!");
            tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" reaches out and touches "+target->QCN+" on the "+target_limb+" draining the very essence of "+target->QP+" life away!", ({target, caster}));
            tell_object(caster,"%^BOLD%^%^CYAN%^You touch "+target->QCN+"'s "+target_limb+" draining the very life essence from "+target->QP+" veins!");
            damage_targ(target, target_limb, sdamage, "negative energy");
            sdamage = sdamage*3/2;
            damage_targ(caster, target_limb, -sdamage, "untyped");
        }
    } else {
        tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" fails to touch you!");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" fails to touch "+target->QCN+"!", ({target, caster}));
        tell_object(caster,"%^BOLD%^%^CYAN%^You fail to touch "+target->QCN+"!");
        spell_kill(target, caster);
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

string query_cast_string() {
    return caster->QCN+" mutters a few words and "+caster->QP+" right hand begins to glow a blood red.";
}
