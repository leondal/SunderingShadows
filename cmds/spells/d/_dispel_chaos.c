#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

#define ALIGN_D "/daemon/alignment_d.c"
#define CASTER_ALIGN "lawful"

int align_check(object caster,object targ);

void create() {
    ::create();
    set_author("ares");
    set_spell_name("dispel chaos");
    set_spell_level(([ "cleric" : 6, "paladin" : 4, "inquisitor" : 4 ]));
    set_spell_sphere("combat");
    set_syntax("cast CLASS dispel chaos on TARGET");
    set_description("Dispel Chaos can only be cast by users of lawful alignment and it only effects targets of chaotic "
"alignment.  When cast at a target of the correct alignment, it will disrupt the harmonics of their soul and wrack their "
"body with pain, doing a significant amount of damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

string query_cast_string()
{
    tell_object(caster,"%^BOLD%^%^BLUE%^Holding your hand out,"+
		" you begins to chant in a rigid even tone.");
    tell_room(place,"%^BOLD%^%^BLUE%^Holding "+caster->QP+" hand out,"+
		" "+caster->QCN+" begins to chant in a rigid even tone.",({ caster }) );
    return"display";
}

int preSpell()
{
    if (!target)
    {
        tell_object(caster, "That is not here.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int damage;
    tell_room(place, "%^BOLD%^The air shimmers as "+caster->QCN+" "+
		"completes "+caster->QCN+" chant.", caster);
    tell_object(caster, "%^BOLD%^Your chant builds in power, causing the very air to shimmer.");

    if(target && !present(target,place))
    {
        dest_effect();
        return;
    }
    if(target && !caster->ok_to_kill(target))
    {
        dest_effect();
        return;
    }
    if(!align_check(caster,target))
    {
        dest_effect();
        return;
    }
    tell_object(caster,"%^BOLD%^%^BLUE%^"+target->QCN+" twists in pain as the "+
		"spell tears at the fiber of their being.");
    tell_object(target,"%^BOLD%^%^CYAN%^You can feel your very soul wracked with"+
		" an incredible pain from the ridig nature of "+caster->QCN+"'s chant.");
    if(do_save(target,0))
    //if("/daemon/saving_d"->saving_throw(target, "spell"))
        damage = roll_dice(clevel,6) / 2;
    else
        damage = roll_dice(clevel,6);
    damage_targ(target,target->return_target_limb(),damage,"divine");
	spell_kill(target,caster);
    dest_effect();
    spell_successful();
    return;
}

// for ease of use, since there are 4 similar spells -Ares
int align_check(object caster,object targ)
{
    if(!objectp(caster)) { return 0; }
    if(!objectp(targ))   { return 0; }

    switch(CASTER_ALIGN)
    {
    case "good":
//        if(!ALIGN_D->is_good(caster)) {
        if((int)caster->query_true_align()%3 != 1) {
            tell_object(caster,"Only people of good alignment may cast this spell.");
            return 0;
        }
        if(ALIGN_D->is_evil(targ)) { return 1; }
        return 0;
    case "evil":
//        if(!ALIGN_D->is_evil(caster)) {
        if((int)caster->query_true_align()%3 != 0) {
            tell_object(caster,"Only people of evil alignment may cast this spell.");
            return 0;
        }
        if(ALIGN_D->is_good(targ)) { return 1; }
        return 0;
    case "lawful":
//        if(!ALIGN_D->is_lawful(caster)) {
        if((int)caster->query_true_align() < 1 || (int)caster->query_true_align() > 3) {
            tell_object(caster,"Only people of lawful alignment may cast this spell.");
            return 0;
        }
        if(ALIGN_D->is_chaotic(targ)) { return 1; }
        return 0;
    case "chaotic":
//        if(!ALIGN_D->is_chaotic(caster)) {
        if((int)caster->query_true_align() < 7 || (int)caster->query_true_align() > 9) {
            tell_object(caster,"Only people of chaotic alignment may cast this spell.");
            return 0;
        }
        if(ALIGN_D->is_lawful(targ)) { return 1; }
        return 0;
    default:
        tell_object(caster,"Something is broken, tell a wiz.");
        return 0;
    }
    return 0;
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
