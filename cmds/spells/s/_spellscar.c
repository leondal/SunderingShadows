#include <spell.h>
#include <magic.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("spellscar");
    set_spell_level(([ "cleric" : 8, "mage" : 8, ]));
    set_mystery("spellscar");
    set_domains("chaos");
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS spellscar");
    set_damage_desc("triggers wild magic in the area");
    set_description("Within the area you choose to affect everything looses its hue. Periodically ripples of vibrant color wriggle through the place. Within this place, spell-like abilities will automatically trigger a wild magic effect.");
}

int preSpell()
{
    if(place->query_property("wild magic"))
    {
      tell_object(caster,"You feel your attempt to cast the spell repelled.");
      return 0;
   }
   return 1;
}

void spell_effect()
{
    tell_room(place,"%^RESET%^%^WHITE%^All colors in the area suddenly turn mute.%^RESET%^");

    place->set_property("wild magic", clevel);
    place->set_property("wild magic affect", ({"random", "random level", 0}));

    spell_successful();
    caster->set_property("spelled", ({TO}) );
    addSpellToCaster();

    spell_duration = (clevel / 5 + 5) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
    call_out("notify_effect",ROUND_LENGTH*2);
}

#define RND_COLORS ({"%^CYAN%^","%^MAGENTA%^","%^ORANGE%^","%^BLUE%^"})

void notify_effect()
{
    string color = RND_COLORS[random(sizeof(RND_COLORS))];
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if(!objectp(place))
    {
        dest_effect();
        return;
    }
    if(!place->query_property("wild magic"))
    {
        dest_effect();
        return;
    }
    if(!random(3))
        message("info", "%^RESET%^"+color+"The colors suddenly turn %^BOLD%^"+color+"v%^RESET%^"+color+"i%^BOLD%^"+color+"b%^RESET%^"+color+"r%^BOLD%^"+color+"a%^RESET%^"+color+"n%^BOLD%^"+color+"t%^RESET%^"+color+" and %^BOLD%^"+color+"saturat%^RESET%^"+color+"e%^BOLD%^"+color+"d%^RESET%^"+color+"!", nearbyRoom(place,2));
    call_out("notify_effect",ROUND_LENGTH*2);
}

void dest_effect()
{
    if(objectp(place))
    {
        tell_room(place,"%^BOLD%^%^WHITE%^The area regains its colors");
        place->remove_property("wild magic");
        place->remove_property("wild magic affect");
    }
    ::dest_effect();
    return;
}
