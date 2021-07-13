//
//added the checks for mage armor from armor code -Tsera 11/5/04
#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("gaseous form");
    set_spell_level(([ "monk" : 9, "assassin" : 1, "magus" : 3, "bard" : 3, "psion" : 3, "mage" : 3 ]));
    set_spell_sphere("alteration");
    set_monk_way("way of the elements");
    set_syntax("cast CLASS gaseous form");
    set_damage_desc("15% evasion chance");
    set_description("This spell allows the caster to take on a translucent, almost gaseous form. "+
    "While active it allows the caster to have a higher chance of avoiding physical attacks as "+
    "well as providing some protection from non physical attacks.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "CYAN%^"+caster->QCN+" closes "+caster->QP+" eyes and focuses deeply!%^RESET%^";
}

int preSpell()
{
    if (caster->query_property("amorpha") || caster->query_property("timeless body"))
    {
        tell_object(caster, "You are already protected by such a spell.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int bonus = prof/10 - 10;
    if (!caster->is_ok_armour("barbarian"))
    {
        if(!FEATS_D->usable_feat(caster,"armored caster") && !FEATS_D->usable_feat(caster,"armored manifester") && !FEATS_D->usable_feat(caster,"eldritch conditioning"))
        {
            tell_object(caster,"The spell can not offer protection to those wearing armor.");
            TO->remove();
            return;
        }
    }
    tell_room(place, caster->QCN+"%^BOLD%^%^CYAN%^ snaps "+caster->QP+" eyes open as "+caster->QP+" body shimmers and "+
    "becomes translucent!%^RESET%^", caster);

    tell_object(caster, "%^BOLD%^%^CYAN%^You focus your inner self, heightening your senses and allowing "+
    "your body to become translucent!%^RESET%^");

    caster->set_property("spelled", ({TO}) );
    caster->set_property("amorpha",1);
    caster->set_missChance(caster->query_missChance()+ 15); // 15% evasion
    spell_successful();
    caster->set_property("spell damage resistance", 10);
    caster->set_property("gaseous form", 1);
    addSpellToCaster();
    call_out("test", 2);
    caster->set_property("added short",({" %^BOLD%^%^CYAN%^(translucent)%^RESET%^"}));
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 7;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void test()
{
// added to avoid errors when the spell has already dested *Styx* 11/14/04
    if (!objectp(TO) || !objectp(caster))
        return;
    if (!caster->is_ok_armour("barbarian"))
    {
        if(!FEATS_D->usable_feat(caster,"armored caster") && !FEATS_D->usable_feat(caster,"armored manifester") && !FEATS_D->usable_feat(caster,"eldritch conditioning"))
        {
            tell_object(caster,"The spell can not offer protection to those wearing armor.");
            TO->dest_effect();
            return;
        }
    }
    call_out("test", 5);  // added to keep it checking periodically *Styx* 11/14/04
}

void dest_effect()
{
    int chance;
    remove_call_out("test");  // clean up open call_out
    if (!objectp(caster))
    {
        TO->remove();
        return;
    }
    if((int)caster->query_property("gaseous form"))
    {
        tell_object(caster, "%^CYAN%^You feel your body return to normal as your heightened focus fades.%^RESET%^");
        tell_room(environment(caster), caster->QCN+"%^CYAN%^'s body suddenly returns to normal.",caster);
        chance = (int)caster->query_missChance()-15;
        caster->set_missChance(chance);
        caster->remove_property("amorpha");
        caster->set_property("spell damage resistance", -10);
        caster->remove_property_value("spelled", ({TO}) );
        caster->remove_property_value("added short",({" %^BOLD%^%^CYAN%^(translucent)%^RESET%^"}));
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
