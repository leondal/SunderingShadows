#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

#define CHEST "/d/magic/mon/secret_chest"
inherit SPELL;

object chest;

void create()
{
    ::create();
    set_spell_name("secret chest");
    set_spell_level(([ "mage" : 5, "cleric" : 5 ]));
    set_domains("creation");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS secret chest");
    set_description("This spell calls to a floating extraplanar chest that will follow the caster everywhere, and even defend him, although poorly. The primary function of this chest is to store caster's equipment and be dispelled. If you keep it around, be aware: it is easy to steal from it, and this chest is not designed to store money. To store items in the chest simply give them to it. To retrieve them command it to give them to you or to drop them. When it is dismissed it will save all its contents. This chest will refuse all non-empty containers. This is a greater summon and won't work with spells of such class, such as gate and conjure elemental.

To command chest, use %^ORANGE%^<command chest to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^.
To command lost chest to follow you once again, use %^ORANGE%^<command chest to follow>%^RESET%^.
To dismiss the chest use %^ORANGE%^<dismiss chest>%^RESET%^.");
	set_helpful_spell(1);
    set_components(([
                        "mage" : ([ "tiny chest":1,
                                    "onyx dust":1]),
                        ]));
}

int preSpell()
{
    if(caster->query_property("has_elemental") || caster->query_property("mages_sword"))
    {
        tell_object(caster,"You already have a powerful summoned creature under your control.");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    return "%^ORANGE%^"+caster->QCN+" throws miniature chest into the air.";
}

void spell_effect()
{
    object device;

    tell_room(place,"%^RESET%^%^ORANGE%^The %^BOLD%^%^ORANGE%^c%^BLACK%^h%^ORANGE%^e%^BLACK%^s%^BLACK%^t%^RESET%^%^ORANGE%^ floats in the air and grows in size!%^RESET%^");
    chest=new(CHEST);
    chest->setup_chest(caster);
    chest->set_property("spelled", ({TO}));
    chest->set_property("spell_creature", TO);
    chest->set_property("spell", TO);
    chest->set_property("minion", caster);
    chest->move(place);

    device = new("/d/magic/obj/holder");
    device->set_property("spell", TO);
    device->set_elemental(chest);
    device->set_caster(caster);
    device->move(caster);

    caster->add_follower(chest);
    caster->set_property("has_elemental",1);
    addSpellToCaster();
}

void dest_effect()
{
    if(objectp(caster))
    {
        caster->remove_property("has_elemental");
    }
    if(objectp(chest))
    {
        tell_room(environment(chest),"%^RESET%^%^ORANGE%^Floating %^BOLD%^%^ORANGE%^Ch%^BLACK%^e%^BLACK%^s%^ORANGE%^t%^RESET%^%^ORANGE%^ simply vanishes!%^RESET%^");
        chest->move("/d/shadowgate/void");
        chest->remove();
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
