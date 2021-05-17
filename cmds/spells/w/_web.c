#include <spell.h>
#include <magic.h>

inherit SPELL;

object oldenv, web, mass;
int waittime;

void dest_effect();
void waiter(int num);

create()
{
    ::create();
    set_spell_name("web");
    set_spell_level(([ "mage" : 2, "assassin" : 2, "magus" : 2, "cleric" : 2 ]));
    set_spell_sphere("conjuration_summoning");
    set_domains("law");
    set_syntax("cast CLASS web on TARGET");
    set_damage_desc("tripped for 3d4 rounds");
    set_description("When someone is unfortunate enough to be the victim of a web spell, they might as well get a new hobby. If the web is successful, the victim will be immobilized within a massive web.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
}

string query_cast_string()
{
    return caster->QCN + " steps away from " + target->QCN + " and starts a low chant.";
}

spell_effect(int prof)
{
    int save, neededroll, power;
    string strength;
    tell_object(caster, "%^YELLOW%^You jab your finger at " + target->QCN + " and strands of sticky web shoot out towards " + target->QO + "!");
    tell_object(target, "%^YELLOW%^" + caster->QCN + " jabs " + caster->QP + " finger at you, shooting out strands of sticky web!");
    tell_room(place, "%^YELLOW%^" + caster->QCN + " jabs " + caster->QP + " finger at " + target->QCN + ", shooting out strands of sticky web!", ({ caster, target }));
    if (do_save(target, -2)) {
        tell_object(caster, "%^BOLD%^%^RED%^" + target->QCN + " manages to dodge your mass of webs!");
        tell_object(target, "%^BOLD%^%^RED%^You manage to dodge the mass of webs!");
        tell_room(environment(caster), "%^BOLD%^%^RED%^" + target->QCN + " manages to dodge the mass of webs!", ({ caster, target }));
    } else {
        strength = "furiously wrap around";
        spell_successful();
        tell_object(caster, "%^BOLD%^%^RED%^Your mass of webs " + strength + " " + target->QCN + " trapping " + target->QP + " legs!");
        tell_object(target, "%^BOLD%^%^RED%^" + caster->QCN + "'s mass of webs " + strength + " you, trapping your legs!");
        tell_room(place, "%^BOLD%^%^RED%^" + caster->QCN + "'s mass of webs " + strength + " " + target->QCN + " trapping " + target->QP + " legs!", ({ caster, target }));
        target->set_tripped(roll_dice(3, 4));
    }
    spell_successful();
}
