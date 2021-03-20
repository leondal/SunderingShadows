#include <spell.h>
#include <magic.h>
#include <daemons.h>

#define SCRY_D "/daemon/ic_scry_locate_d"

inherit SPELL;

object blocker, temp, temp2;
int FLAG;

void create()
{
    ::create();
    set_spell_name("mind blank");
    set_spell_level(([ "psywarrior" : 6, "psion" : 7, "mage" : 8, "cleric" : 8]));
    set_domains("mentalism");
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS mind blank");
    set_description("This power shields the character's mind. The mental fortress provides the same benefits as the Escape Detection or Protection from scrying power as well as offering additional protection against mind-affecting spells and powers.");
    set_helpful_spell(1);
}


int preSpell()
{
    if(temp2 = caster->query_property("mind blank"))
    {
        if(!objectp(temp))
        {
            caster->remove_property("mind blank");
        }
        else
        {
            tell_object(caster,"%^BOLD%^%^MAGENTA%^You are already "
                "protected by mind blank!%^RESET%^");
        }
        return 0;
    }

    if(temp = caster->query_property("block scrying"))
    {
        if(!objectp(temp))
        {
            caster->remove_property("block scrying");
        }
        else
        {
            tell_object(caster,"%^BOLD%^%^MAGENTA%^You are already "
                "protected by blocking magic!%^RESET%^");
        }
        return 0;
    }
    return 1;
}


string query_cast_string()
{
    tell_room(environment(caster),"%^BOLD%^%^BLACK%^"+caster->QCN+" lifts a hand, and "
        "c%^RESET%^%^CYAN%^r%^BOLD%^y%^GREEN%^st%^CYAN%^a%^RESET%^"
        "%^CYAN%^l%^BOLD%^%^BLACK%^s s%^RESET%^w%^BOLD%^i%^RESET%^r"
        "%^BOLD%^%^BLACK%^l over "+caster->QP+" palm, growing and "
        "multiplying into a miniature u%^RESET%^%^CYAN%^n%^BOLD%^i"
        "%^GREEN%^ve%^CYAN%^r%^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^e.%^RESET%^", caster);
    tell_object(caster,"%^BOLD%^%^BLACK%^You lift a hand, and "
        "c%^RESET%^%^CYAN%^r%^BOLD%^y%^GREEN%^st%^CYAN%^a%^RESET%^"
        "%^CYAN%^l%^BOLD%^%^BLACK%^s s%^RESET%^w%^BOLD%^i%^RESET%^r"
        "%^BOLD%^%^BLACK%^l over your palm, growing and "
        "multiplying into a miniature u%^RESET%^%^CYAN%^n%^BOLD%^i"
        "%^GREEN%^ve%^CYAN%^r%^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^e.%^RESET%^");
    return "display";
}


void spell_effect(int prof)
{
    int num, int_bonus,power, mylevel;
    int duration;
    object temp;
    string *TmpFeats;
    ::spell_effect();

    if(temp = caster->query_property("block scrying"))
    {
        if(!objectp(temp))
        {
            caster->remove_property("block scrying");
        }
        else
        {
            tell_object(caster,"%^BOLD%^%^MAGENTA%^There is already blocking "
                "magic working for that target!%^RESET%^");
            dest_effect();
            return;
        }
    }

    mylevel = clevel;

    tell_room(place,"%^RESET%^%^MAGENTA%^The %^RESET%^s%^BOLD%^w%^CYAN%^i%^RESET%^"
        "%^CYAN%^rl%^BOLD%^i%^WHITE%^n%^RESET%^g %^MAGENTA%^crystals blossom into a "
        "brilliant expanse of %^BOLD%^%^BLACK%^n%^RESET%^i%^CYAN%^g%^BOLD%^ht %^RESET%^"
        "%^CYAN%^s%^RESET%^k%^BOLD%^%^BLACK%^y %^RESET%^%^MAGENTA%^before coalescing "
        "around "+caster->QCN+", bathing "+caster->QO+" in %^CYAN%^i%^BOLD%^%^CYAN%^r%^RESET%^"
        "%^CYAN%^id%^RESET%^e%^CYAN%^s%^BOLD%^c%^BLACK%^e%^RESET%^%^CYAN%^n%^RESET%^c"
        "%^CYAN%^e %^MAGENTA%^before winking out of existence.%^RESET%^",caster);
    tell_object(caster,"%^RESET%^%^MAGENTA%^The %^RESET%^s%^BOLD%^w%^CYAN%^i%^RESET%^"
        "%^CYAN%^rl%^BOLD%^i%^WHITE%^n%^RESET%^g %^MAGENTA%^crystals blossom into a "
        "brilliant expanse of %^BOLD%^%^BLACK%^n%^RESET%^i%^CYAN%^g%^BOLD%^ht %^RESET%^"
        "%^CYAN%^s%^RESET%^k%^BOLD%^%^BLACK%^y %^RESET%^%^MAGENTA%^before coalescing "
        "around you, bathing you in %^CYAN%^i%^BOLD%^%^CYAN%^r%^RESET%^"
        "%^CYAN%^id%^RESET%^e%^CYAN%^s%^BOLD%^c%^BLACK%^e%^RESET%^%^CYAN%^n%^RESET%^c"
        "%^CYAN%^e %^MAGENTA%^before winking out of existence.%^RESET%^");

    TmpFeats = caster->query_temporary_feats();
    if(!sizeof(TmpFeats)) TmpFeats = ({});

    if(member_array("unyielding soul",TmpFeats) != -1 || FEATS_D->usable_feat(caster,"unyielding soul") ||
    member_array("presence of mind",TmpFeats) != -1 || FEATS_D->usable_feat(caster,"presence of mind") ||
    member_array("mind partition",TmpFeats) != -1 || FEATS_D->usable_feat(caster,"mind partition"))
    {
        FLAG = 0;
    }
    else
    {
        tell_object(caster,"%^BOLD%^%^CYAN%^You feel the fortification of your mind "
            "slide into place.%^RESET%^");
        caster->add_temporary_feat("unyielding soul");
        FLAG = 1;
    }

    caster->set_property("spelled",({TO}));
    caster->set_property("mind blank",1);
    blocker = SCRY_D->add_block_scrying(caster);

    if(!objectp(blocker))
    {
        tell_object(caster,"%^BOLD%^RED%^Something is wrong that "
            "a wiz might want to look at!%^RESET%^");
        dest_effect();
        return;
    }

    int_bonus = caster->query_stats(casting_stat);
    int_bonus = int_bonus-8; //bonus of +2 because this is much higher level than other scry blocks, including the other one for psywarriors
    power = mylevel + int_bonus + random(6);
    blocker->set_block_power(power);
    duration = 5 * mylevel * ROUND_LENGTH;
    spell_successful();
    addSpellToCaster();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    return;
}

void dest_effect() {
    if(objectp(blocker)) blocker->self_destruct();
    if(objectp(caster))
    {
        caster->remove_property_value("spelled", ({TO}) );
        if(FLAG)
        {
           caster->remove_temporary_feat("unyielding soul");
        }
        caster->remove_property("mind blank");
        tell_object(caster,"%^RESET%^%^MAGENTA%^Your mind blank fades away, "
        "leaving you vulnerable to prying eyes.%^RESET%^");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
