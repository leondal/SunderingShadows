#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;
int hit, max;

void create() {
    ::create();
    set_spell_name("gale fist");
    set_spell_level(([ "monk" : 11, "oracle" : 6 ]));
    set_spell_sphere("conjuration_summoning");
    set_mystery("godclaw");
    set_monk_way("way of the elements");
    set_syntax("cast CLASS gale fist on TARGET");
    set_description("This spell creates an enormous fist of tangible air above the target. The fist will rapidly smash the target after a short delay, sometimes more than once, on the first attempt the target rolls a will saving throw, if successful the target will take only half damage. If the target fails the saving throw, however, they will be momentarily stunned. The higher the level of the caster the longer the period of time. Each additionl strike by the fist will allow for a save to half damage, but the stun effect will not apply beyond the first hit.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
    set_components(([
    ]));
}

string query_cast_string()
{
    return caster->QCN+"%^BOLD%^%^CYAN%^ extends "+caster->QP+" hands in "+
    "front of "+caster->QO+ "!%^RESET%^";
}

void remove_fist()
{
    if(!objectp(TO)) return;
    if(!objectp(caster)) return;
    if(!objectp(place)) place = environment(caster);
    tell_room(place, "%^BOLD%^%^WHITE%^With a strange %^BOLD%^%^GREEN%^sucking%^BOLD%^"+
    "%^WHITE%^ noise the fist vanishes!%^RESET%^");
    caster->remove_property("gale fist");
    return;
}

void do_hits()
{
    int dam;
    if(!objectp(TO)) return;
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if(!objectp(target))
    {
        remove_fist();
        dest_effect();
        return;
    }
    if(!objectp(place)) place = environment(caster);
    if(!present(target, place))
    {
        remove_fist();
        dest_effect();
        return;
    }
    tell_room(place, "%^BOLD%^%^CYAN%^The fist slams down rapidly into "+
    target->QCN+"%^BOLD%^%^CYAN%^!%^RESET%^");

    tell_object(target, "%^BOLD%^%^CYAN%^The enormous fist slams down rapidly "+
    "into you!%^RESET%^");

    dam = sdamage;
    if(!do_save(target))
    {
        if(!hit)
        {
            tell_object(target, "%^BOLD%^%^CYAN%^You crumple to the ground from the impact of the fist!%^RESET%^");
            //may need tweaked - Saide
            target->set_paralyzed(roll_dice(1,clevel), "%^BOLD%^%^RED%^You are still recovering from the impact!%^RESET%^");
            tell_room(place, target->QCN+"%^BOLD%^%^CYAN%^ crumples to the ground from the impact of the fist!%^RESET%^", target);
        }
    }
    else dam /= 2;
    hit++;
    damage_targ(target,target->return_target_limb(),dam,"force");
    if(hit >= max || !random(3))
    {
        remove_fist();
        dest_effect();
        return;
    }
    else
    {
        call_out("do_hits", ROUND_LENGTH);
        return;
    }
}

void spell_effect(int prof)
{

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if(!objectp(target))
    {
        dest_effect();
        return;
    }
    if(!present(target,caster->is_room()?caster:environment(caster)))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }
    if(caster->query_property("gale fist"))
    {
        tell_object(caster, "%^BOLD%^%^CYAN%^You are already using gale fist!%^RESET%^");
        dest_effect();
        return;
    }
    if(spell_type == "monk") { MAGIC_D->elemental_opportunist(caster, target); }
    tell_object(caster, "%^BOLD%^%^WHITE%^You focus your inner ki and "+
    "release it with a %^BOLD%^%^BLACK%^DEAFENING%^BOLD%^%^WHITE%^ "+
    "%^BOLD%^%^CYAN%^whoosh%^BOLD%^%^WHITE%^!%^RESET%^");

    tell_room(place, caster->QCN+"%^BOLD%^%^WHITE%^'s hands snap backwards "+
    "creating a %^BOLD%^%^BLACK%^DEAFENING%^BOLD%^%^WHITE%^ "+
    "%^BOLD%^%^CYAN%^whoosh%^BOLD%^%^WHITE%^!%^BOLD%^%^BLACK%^", caster);

    tell_room(place, "%^BOLD%^%^CYAN%^An enormous fist of tangible "+
    "%^BOLD%^%^WHITE%^air%^BOLD%^%^CYAN%^ appears above "+target->QCN+"%^BOLD%^%^CYAN%^!%^RESET%^", target);

    tell_object(target, "%^BOLD%^%^CYAN%^An enormous fist of tangible "+
    "%^BOLD%^%^WHITE%^air%^BOLD%^%^CYAN%^ appears above you!%^RESET%^");
    caster->set_property("gale fist", 1);
    max = (clevel / 10) + 1;
    call_out("do_hits", ROUND_LENGTH);
    return;
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
