#include <std.h>
#include <spell.h>
#include <daemons.h>
inherit SPELL;

#define DELAY 120

void create()
{
    ::create();
    set_author("nienne");
    set_spell_name("flee the scene"); // Mislead
    set_spell_level(([ "warlock" : 2, "bard" : 5, "mage" : 6, "magus" : 5 ]));
    set_domains("trickery");
    set_spell_sphere("illusion");
    set_syntax("cast CLASS flee the scene on DIRECTION");
    set_description("This spell allows the caster to craft an illusion about themselves, "
                    "before slipping out of it a short distance away. The illusion remains behind for a round, "
                    "hopefully fooling those who might try to come after. The invocation can be used in combat "
                    "and will ignore mundane impediments, such as caltrops or closed doors, but will be barred "
                    "by magically sealed doors. Given the very careful and draining spellcraft this invocation "
                    "requires, it will take a few moments before the warlock can cast it again after the first.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

int preSpell()
{
    if (((int)caster->query_property("slide time") + DELAY) > time()) { // same var as slide; let's not let kids stack them
        tell_object(caster, "You need to take a moment's rest before you can try that again.");
        return 0;
    }
    if (!arg) {
        tell_object(caster, "%^BOLD%^%^WHITE%^You must specify a direction for this spell!%^RESET%^");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    string* exits, dest_name, pt2, shortdesc, long2;
    int i;
    object dest, ob, * attackers;

    exits = (string*)place->query_exits();
    if ((member_array(arg, exits) == -1)) {
        tell_object(caster, "%^BOLD%^%^WHITE%^You can't flee in that direction!%^RESET%^");
        dest_effect();
        return;
    }

    spell_successful();
    if (place->query_property("no phase")) {
        tell_object(caster, "This place seems to be enchanted against such things!\n");
        dest_effect();
        return;
    }
    dest_name = place->query_exit(arg);
    dest = find_object_or_load(dest_name);
    if (dest->query_property("no phase")) {
        tell_object(caster, "This place seems to be enchanted against such things!\n");
        dest_effect();
        return;
    }
    tell_object(caster, "%^CYAN%^Crafting an illusion around yourself, you then "
                "abandon the image to slip unnoticed (hopefully!) towards the " + arg + " exit.%^RESET%^");
    if (!caster->query_invis()) {
        tell_room(place, "%^CYAN%^" + caster->QCN + " glances towards the " + arg + " exit, "
                  "and wavers momentarily!%^RESET%^", caster);
    }
    ob = new("/d/magic/obj/flee-image.c");
    ob->set_caster(caster);
    pt2 = USERCALL->user_call((string)caster->query_name(), "getWholeDescriptivePhrase");
    pt2 = replace_string(pt2, "A", "a", 1);
    shortdesc = "A wavering image of " + pt2;
    pt2 = replace_string(pt2, "a", "A", 1);
    ob->set_short(shortdesc);
    ob->set_name("wavering image");
    ob->set_id(({ "summoned monster", "image", "shadow", "illusion", (string)caster->query_race() }));
    ob->set_race((string)caster->query_race());
    ob->set_gender((string)caster->query_gender());
    long2 = pt2 + " " + (string)USERCALL->user_call((string)caster->query_name(), "query_description");
    ob->set_long(long2);
    ob->move(environment(caster));

    attackers = ({});
    attackers += caster->query_attackers();
    if (sizeof(attackers)) {
        for (i = 0; i < sizeof(attackers); i++) {
            ob->add_attacker(attackers[i]);
            attackers[i]->add_attacker(ob);
        }
    }
    caster->clear_followers();
    caster->move_player(dest);
    caster->remove_property("slide time");
    caster->set_property("slide time", time());
    if (!caster->query_invis()) {
        tell_room(dest, "%^CYAN%^" + caster->QCN + " steps quite suddenly as if from nowhere!%^RESET%^", caster);
    }
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
