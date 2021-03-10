#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

#define ALIGN_D "/daemon/alignment_d.c"
#define CASTER_ALIGN "chaotic"

int align_check(object caster,object targ);

void create() {
    ::create();
    set_author("ares");
    set_spell_name("dispel law");
    set_spell_level(([ "cleric" : 5, "inquisitor":5, "paladin":4]));
    set_spell_sphere("abjuration");
    set_domains("chaos");
    set_syntax("cast CLASS dispel law on TARGET");
    set_description("Dispel Law can only be cast by users of chaotic alignment and it only effects targets of lawful "
"alignment.  When cast at a target of the correct alignment, it will disrupt the harmonics of their soul and wrack their "
"body with pain, doing a significant amount of damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

string query_cast_string()
{
    tell_object(caster,"%^BOLD%^%^GREEN%^Holding your hand out,"+
		" you begins to chant in a wild shifting tone.");
    tell_room(place,"%^BOLD%^%^GREEN%^Holding "+caster->QP+" hand out,"+
		" "+caster->QCN+" begins to chant in a wild shifting tone.",caster);
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
    tell_room(place, "%^BOLD%^%^GREEN%^The air shimmers as "+caster->QCN+" completes"+
		" "+caster->QP+" chant.", caster);
    tell_object(caster, "%^BOLD%^%^GREEN%^Your chant builds in power, causing the "+
		"very air to shimmer.");

    if(target && !present(target,PLACE))
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
    tell_object(caster,"%^BOLD%^%^MAGENTA%^"+target->QCN+" twists in pain as the"+
		" spell tears at the fiber of their being.");
    tell_object(target,"%^BOLD%^%^MAGENTA%^You can feel your very soul wracked with"+
		" an incredible pain at the chaotic tone of "+caster->QCN+"'s chant.");
    if(do_save(target,0))
    //if("/daemon/saving_d"->saving_throw(target, "spell"))
        damage = sdamage / 2;
    else
        damage = sdamage;
    damage_targ(target,target->return_target_limb(),damage,"divine");
	spell_kill(target,caster);
    spell_successful();
    dest_effect();
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
