#include <spell.h>
#include <magic.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("suppress wild magic");
    set_spell_level(([ "cleric" : 4, "mage" : 4 ]));
    set_spell_sphere("abjuration");
    set_domains("magic");
    set_syntax("cast CLASS supress wild magic");
    set_damage_desc("reduces wild magic effects in the area");
    set_description("You repair the weave in the area, laying own artificial framework over any wild magic effects.");
}

int preSpell()
{
    if(!place->query_property("wild magic"))
    {
      tell_object(caster,"You feel your attempt to cast the spell repelled by absence of the wild magic.");
      return 0;
   }
   return 1;
}

void spell_effect()
{
    tell_room(place,"%^BOLD%^%^CYAN%^All colors in the area suddenly turn %^MAGENTA%^vibrant%^CYAN%^.%^RESET%^");

    place->set_property("wild magic", -clevel);
    place->set_property("wild magic affect", ({"random", "random level", 0}));

    if(place->query_property("wild magic")<0)
    {
        place->remove_property("wild magic");
        place->remove_property("wild magic affect");
        tell_room(place,"%^BOLD%^%^CYAN%^The %^MAGENTA%^We%^GREEN%^a%^BLUE%^v%^RED%^e%^CYAN%^ has been completely repaired.%^RESET%^");
    }

    spell_successful();
    caster->set_property("spelled", ({TO}) );
    addSpellToCaster();
}

void dest_effect()
{
    ::dest_effect();
    return;
}
