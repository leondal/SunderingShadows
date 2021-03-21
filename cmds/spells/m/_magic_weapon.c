#include <std.h>
#include <spell.h>
inherit SPELL;

object fob,tob;

void create() {
    ::create();
    set_spell_name("magic weapon");
    set_spell_level(([ "mage" : 1, "cleric" : 1, "inquisitor" : 1, "oracle" : 1, "paladin":1, "magus" : 1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS magic weapon on OBJECT");
    set_description("With this spell you can make any non-cursed, non-enchanted weapon +1.

This spell uses 1 414 gp as a material component.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
	set_helpful_spell(1);
}

string query_casting_string()
{
    return "%^BOLD%^%^MAGENTA%^"+caster->QCN+" utters a short %^GREEN%^r%^CYAN%^h%^GREEN%^ym%^CYAN%^e %^MAGENTA%^under "+caster->QP+" breath.";
}

int preSpell()
{
    string sfob, stob;
    if(sscanf(arg,"%s",sfob)!=1)
    {
        tell_object(caster, "You must specify object you are going to empower.");
        return 0;
    }
    fob = present(sfob,caster);
    if(!caster->query_funds("gold", 1414))
    {
        tell_object(caster, "You don't have enough money.");
        return 0;
    }
    if (!objectp(fob))
    {
        tell_object(caster,"The object is not present.");
        return 0;
    }
    if(!(fob->is_weapon()))
    {
        tell_object(caster,"The object is not a weapon.");
        return 0;
    }
    if(strsrch(base_name(fob),"/d/magic/") != -1 ||
       fob->query_property("monsterweapon"))
    {
        tell_object(TP,"You cannot alter a conjured item!");
        return 1;
    }
    if(fob->query_weight() > 200)
    {
        tell_object(TP,"This is too large to empower!");
        return 1;
    }
    if(fob->query_property("no repair"))
    {
        tell_object(TP,"This object can't accept magic!");
        return 1;
    }
    if(fob->query_property("enchantment") > 0)
    {
        tell_object(caster,"The object must not be enchanted.");
        return 0;
    }
    if(fob->query_property("enchantment")<0)
    {
        tell_object(caster,"The object must not be cursed.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int enchantment;

    if (!objectp(fob))
    {
        tell_object(caster,"That object is no longer present.");
        dest_effect();
        return;
    }
    if(!caster->query_funds("gold", 1414))
    {
        tell_object(caster, "You don't have enough money.");
        return;
    }

    caster->use_funds("gold",1414);

    fob->remove_property("enchantment");
    fob->set_property("enchantment",1);
    tell_object(caster,"%^BOLD%^%^MAGENTA%^As the metal vapor rises it carries away the magic into "+fob->query_short()+"%^BOLD%^%^MAGENTA%^.%^RESET%^");
    tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" voices a few syllables and evaporates a pile of gold under "+fob->query_short()+".%^RESET%^");
    dest_effect();
}
