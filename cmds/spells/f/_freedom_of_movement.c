//by ~Circe~ 5/15/08 with the rebalancing of domains
#include <std.h>
#include <magic.h>

inherit SPELL;

void create()
{
    ::create();
    set_author("circe");
    set_spell_name("freedom of movement");
    set_spell_level(([ "cleric" : 4, "bard" : 4, "ranger" : 4, "mage" : 4,"druid" : 4, "assassin" : 4, "psion" : 4, "psywarrior" : 4, "paladin" : 4, "inquisitor" : 4, "magus" : 4 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS freedom of movement");
    set_description("This spell will protect the caster with an aura of freedom, granting her freedom from the next "
        "paralyzation effect upon her.  The power of this spell is such that it will cause a brief delay once activated "
        "before it can be used again.  This spell can only be cast while at peace.");
    set_verbal_comp();
    set_somatic_comp();
    set_components(([
        "mage" : ([ "quicksilver" : 2, ]),
    ]));
    set_helpful_spell(1);
}


int preSpell()
{
    if(caster->query_property("freedom"))
    {
        tell_object(caster,"%^GREEN%^You are already protected by a "+
            "freedom spell.%^RESET%^");
        return 0;
    }
    return 1;
}


string query_cast_string()
{
    if(member_array(spell_type,({"mage","sorcerer","bard","magus"}))!=-1)
    {
        tell_object(caster,"%^BOLD%^%^GREEN%^You call upon the weave, "+
            "drawing upon it as you murmur the words of a spell.%^RESET%^");
        tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" whispers a "+
            "soft murmur to the winds.%^RESET%^",caster);
    }
    if(member_array(spell_type,({"cleric","ranger","paladin","inquisitor","oracle"}))!=-1)
    {
        tell_object(caster,"%^BOLD%^%^GREEN%^You call upon the power of "+
            ""+capitalize(caster->query_diety())+" to grant you a "+
            "blessing of freedom.%^RESET%^");
        tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" whispers a "+
            "quiet prayer on the winds.%^RESET%^",caster);
    }
    else
    {
    tell_object(caster,"%^BOLD%^%^GREEN%^You reach into your inner "+
                "strength, drawing upon it as you murmur the words of a spell.%^RESET%^");
    tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" whispers a "+
              "soft murmur to the winds.%^RESET%^",caster);
    }
    return "display";
}


void spell_effect(int prof)
{
    object obj;

    tell_object(caster,"%^CYAN%^Lifting your arms high overhead, you "+
        "sense a subtle change take place within you, feeling your "+
        "limbs lighten as the spell settles upon you.  \nPlease type "
        "%^RESET%^%^BOLD%^<freeme>%^RESET%^%^CYAN%^ to activate%^RESET%^");
    tell_room(place,"%^CYAN%^"+caster->QCN+" lifts "+caster->QP+" "+
        "arms high overhead, and "+caster->QP+" skin seems to "+
        "brighten momentarily.%^RESET%^",caster);
    obj = new("/d/magic/obj/freedom");
    obj->set_mycaster(caster);
    obj->set_spellob(TO);
    obj->set_mylevel(clevel/10);
    obj->move(caster);
    addSpellToCaster();
    caster->set_property("spelled",({TO}));
    caster->set_property("freedom",1);
    spell_successful();
}


void dest_effect(){

   if(objectp(caster)){
      tell_object(caster,"%^GREEN%^You feel your blessing of freedom "+
         "fade away.%^RESET%^");
      caster->remove_property("freedom",1);
   }
   ::dest_effect();
   if(objectp(TO)) TO->remove();

}
