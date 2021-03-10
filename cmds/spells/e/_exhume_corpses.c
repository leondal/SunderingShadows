#include <spell.h>
#include <objects.h>
#include <magic.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("exhume corpses");
    set_spell_level(([ "mage" : 6, "cleric" : 5, "inquisitor":5]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS exhume corpses");
    set_description("With this art the necromancer taps onto the natural flow of negative energies and uses them to track and summon corpses, from various places in the world to the place he is in. The corpses summoned are that of common folk and thus are weak. This spell by itself does nothing to the souls of the deceased, yet the reason why necromancer calls to it is obvious, and thus only evil caster will ever call to it. Using this spell in civilized lands attracts unneeded attention.");
    set_helpful_spell(1);
}

string query_cast_string()
{
    tell_object(caster,"%^CYAN%^Y%^BOLD%^%^BLACK%^o%^RESET%^%^CYAN%^u%^CYAN%^ close your eyes and turn around slowly, chanting a low song and dusting the ground with %^BOLD%^%^BLACK%^b%^BLACK%^o%^WHITE%^n%^BLACK%^e %^WHITE%^m%^BLACK%^e%^WHITE%^a%^BLACK%^l%^RESET%^%^CYAN%^ and %^CYAN%^c%^CYAN%^a%^BOLD%^%^BLACK%^r%^RESET%^%^CYAN%^b%^CYAN%^o%^BOLD%^%^BLACK%^n%^RESET%^%^CYAN%^.");
    tell_room(place,"%^CYAN%^"+caster->QCN+" closes "+caster->QP+" eyes and turns around slowly, chanting a low song and dusting the ground with %^BOLD%^%^BLACK%^b%^BLACK%^o%^WHITE%^n%^BLACK%^e %^WHITE%^m%^BLACK%^e%^WHITE%^a%^BLACK%^l%^RESET%^%^CYAN%^ and %^CYAN%^c%^CYAN%^a%^BOLD%^%^BLACK%^r%^RESET%^%^CYAN%^b%^CYAN%^o%^BOLD%^%^BLACK%^n%^RESET%^%^CYAN%^.",caster);
    return "display";
}

void spell_effect()
{
    int i;

    tell_room(place,"%^CYAN%^A low continuous thunder rolls over the place, and %^BOLD%^%^BLACK%^co%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^p%^RESET%^%^CYAN%^s%^CYAN%^e%^BOLD%^%^BLACK%^s%^RESET%^%^CYAN%^ begin to materialize everywhere.");
    for (i=0; i<clevel/10 + 1; i++)
    {
        object corpse;
        corpse = new(OB_CORPSE);
        corpse->set_name("human");
        corpse->copy_body(caster);
        corpse->set_gender(({"male","female"})[random(2)]);
        corpse->set_long("%^CYAN%^Before you is an %^CYAN%^o%^CYAN%^l%^CYAN%^d %^CYAN%^c%^BOLD%^%^BLACK%^o%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^p%^RESET%^%^CYAN%^s%^CYAN%^e%^CYAN%^ of a human being in tattered clothes. Its features are %^CYAN%^r%^BOLD%^%^BLACK%^ott%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^n %^BLACK%^aw%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^y%^RESET%^%^CYAN%^ and are hard to discern. It smells as disgustingly as it looks, %^BOLD%^%^WHITE%^bi%^BLACK%^t%^WHITE%^s %^BLACK%^o%^WHITE%^f %^BLACK%^b%^WHITE%^o%^BLACK%^n%^BLACK%^e%^RESET%^%^CYAN%^ peer through decayed pieces. Who it was in life is impossible to tell at this point.");
        corpse->set_short("%^CYAN%^A human corpse%^RESET%^");
        corpse->set_level(1);
        corpse->move(place);
    }
}
