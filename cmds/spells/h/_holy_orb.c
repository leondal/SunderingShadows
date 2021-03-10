//Holy Orb
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;


string query_cast_string() { return caster->QCN+" holds "+caster->QP+" hands out in front of "+caster->QO+" and calls for aid."; }


void create()
{
   ::create();
    set_spell_name("holy orb");
    set_spell_level(([ "cleric" : 6 ]));
    set_spell_sphere("combat");
    set_domains("good");
    set_syntax("cast CLASS holy orb");
    set_description("The orb is a spell normally prepared by a priest who expects to encounter enemies whose alignment "
        "opposes her own.  When cast, the spell streaks from the caster's hand to the desired point of effect, where a sphere "
        "forms.  The sphere drains the essence of life from the targets in the area of effect.  The sphere does damage based on "
        "the alignment of the caster with respect to the target.\n\nNOTE: This spell will damage all attackers regardless of "
        "alignment, but the damage will very if the attackers are players based on each individual's alignment.  The damage done "
        "to mobs is consistent no matter the mob's alignment.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(2);
    set_save("reflex");
}


void spell_effect(int prof)
{
    int damage;
    int i,j;
    object limb;
    object *foes;
    object *party;

    foes = target_selector();
    party = ob_party(caster);

    tell_room(place,"%^BOLD%^A sphere of power radiates out from "+
        ""+caster->QCN+"'s hands!%^RESET%^",caster);
    tell_object(caster,"%^BOLD%^A sphere of power radiates out "+
        "from your hands.%^RESET%^");
    //tell_object(find_player("saide"), "j = "+j);
    j = sizeof(foes);

    for(i=0;i<j;i++)
    {
        if(!objectp(foes[i])) continue;
        if(foes[i] == caster) continue;
        if(interactive(foes[i]) && foes[i]->query_level() < 6) continue;
        limb = foes[i]->return_target_limb();
        define_base_damage(0);
        damage = sdamage;
        if(!interactive(foes[i]))
        {
            tell_object(caster,"%^BOLD%^%^CYAN%^The power from your sphere glows brightly as it engulfs "+foes[i]->QCN+".%^RESET%^");
            tell_room(place,"%^BOLD%^%^CYAN%^The power from "+caster->QCN+"'s sphere glows brightly as it engulfs "+foes[i]->QCN+"."+"%^RESET%^",({foes[i],caster}));
            if(!do_save(foes[i],-2)) { damage_targ(foes[i],limb,damage,"divine"); }
            else { damage_targ(foes[i],limb,damage/2,"divine"); }
        }
        else
        {
            if(ALIGN->is_evil(foes[i]))
            {
                tell_object(foes[i],"%^BOLD%^%^CYAN%^The power from "+
                    ""+caster->QCN+"'s sphere glows brightly as it "+
                    "engulfs you.%^RESET%^");
                tell_object(caster,"%^BOLD%^%^CYAN%^The power from "+
                    "your sphere glows brightly as it engulfs "+
                    ""+foes[i]->QCN+".%^RESET%^");
                tell_room(place,"%^BOLD%^%^CYAN%^The power from "+
                    ""+caster->QCN+"'s sphere glows brightly as it "+
                    "engulfs "+foes[i]->QCN+".%^RESET%^",({foes[i],caster}));
                if(!do_save(foes[i],-2)) { damage_targ(foes[i],limb,damage,"divine"); }
                else { damage_targ(foes[i],limb,damage/2,"divine"); }
            }
            else if (ALIGN->is_neutral(foes[i]))
            {
                tell_object(foes[i],"%^BOLD%^The power from "+caster->QCN+"'s "+
                    "sphere glows as it engulfs you.%^RESET%^");
                tell_object(caster,"%^BOLD%^The power from your sphere glows "+
                    "as it engulfs "+foes[i]->QCN+".%^RESET%^");
                tell_room(place,"%^BOLD%^The power from "+caster->QCN+"'s "+
                    "sphere glows as it engulfs "+foes[i]->QCN+"."+
                    "%^RESET%^",({foes[i],caster}));
                if(!do_save(foes[i]))
                {
                    damage_targ(foes[i],limb,damage,"divine");
                }
                else
                {
                    damage_targ(foes[i],limb,damage/2,"divine");
                }
            }
            else if(ALIGN->is_good(foes[i]))
            {
                tell_object(foes[i],"%^CYAN%^The power from "+
                    ""+caster->QCN+"'s sphere flickers fitfully "+
                    "as it strikes you.%^RESET%^");
                tell_object(caster,"%^CYAN%^The power from your sphere "+
                    "flickers fitfully as it strikes "+
                    ""+foes[i]->QCN+".%^RESET%^");
                tell_room(place,"%^CYAN%^The power from "+caster->QCN+"'s "+
                    "sphere flickers fitfully as it strikes "+
                    ""+foes[i]->QCN+".%^RESET%^",({foes[i],caster}));
                damage -= (int)clevel;
                if(damage>0)
                {
                    if(!do_save(foes[i],2)) { damage_targ(foes[i],limb,damage,"divine"); }
                    else { damage_targ(foes[i],limb,damage/2,"divine"); }
                }
            }
        }
    }
    dest_effect();
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
