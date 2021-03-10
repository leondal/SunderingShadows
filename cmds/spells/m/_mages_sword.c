#include <magic.h>
#include <std.h>
#include <spell.h>
inherit SPELL;

object* animated, * monsters, control;
int amount;

void make_sword();

void create()
{
    ::create();
    set_author("nienne");
    set_spell_name("mages sword");
    set_spell_level(([ "mage" : 7, "magus" : 6 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS mages sword");
    set_description("This spell will create a floating and controllable sword for you that you can use to attack your "
                    "enemies.  The sword will automatically follow and protect you.  Should you lose it, though, simply go into the room with "
                    "it and <command sword to follow>. This is a greater summons, and cannot be used simultaneously with other greater summons.");
    set_verbal_comp();
    set_somatic_comp();
    set_components(([
                        "mage" : ([ "mini platinum sword" : 1, ]),
                    ]));
    set_helpful_spell(1);
}

int preSpell()
{
    if (caster->query_property("mages_sword") || caster->query_property("has_elemental")) {
        tell_object(caster, "%^CYAN%^You are incapable of controling two such powerful summonings.%^RESET%^");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    tell_object(caster, "%^CYAN%^Extending both hands before you, you begin to cast.%^RESET%^");
    tell_room(place, "%^CYAN%^Extending both hands before " + caster->QO + ", " + caster->QCN + " begins to cast.%^RESET%^", caster);
    return "display";
}

void spell_effect(int prof)
{
    if (!objectp(environment(caster))) {
        dest_effect();
        return;
    }
    place = environment(caster);
    make_sword();
}

void make_sword()
{
    object ob, thing;

    tell_object(caster, "%^CYAN%^A sword appears floating in front of you.%^RESET%^");
    tell_room(place, "%^CYAN%^You see a sword appear in the air before " + caster->QCN + ".%^RESET%^", caster);
    thing = new("/d/shadow/obj/weapon/broad.c");
    thing->move("/d/magic/obj/place");
    control = new("/d/magic/obj/swordremote");
    control->set_caster(caster);
    control->move(caster);
    control->set_property("spell", TO);
    control->set_property("spelled", ({ TO }));
    ob = new("/d/magic/obj/aobject.c");
    control->set_sword(ob);
    caster->add_follower(ob);
    ob->set_size(2);
    ob->set_long(thing->query_long());
    ob->set_short("%^RESET%^%^RED%^A %^RED%^f%^BOLD%^%^RED%^l%^RESET%^%^RED%^a%^BOLD%^%^RED%^mi%^RESET%^%^RED%^n%^BOLD%^%^RED%^g%^RESET%^%^RED%^ sword%^RESET%^");
    ob->set_name(thing->query_name());
    ob->set_id(thing->query_id());
    ob->add_id("summoned monster");
    ob->set_heart(1);
    ob->set_stats("intelligence", 1);
    ob->add_limb("blade", "blade", 0, 0, 0);
    ob->add_limb("hilt", "hilt", 0, 0, 0);
    ob->set_attack_limbs(({ "blade" }));
    ob->set_base_damage_type("slashing");
    ob->set_attacks_num(clevel / 12 + 1);
    ob->set_damage(4, (clevel / 4)); //changed to tighten up the damage range for more consistency 8/28/19
    ob->set_overall_ac(-clevel);
    ob->set_hd(clevel);
    ob->set_max_hp(clevel * 10);
    ob->set_hp(clevel * 10);
    ob->set_stats("strength", 15);
    ob->set_caster(caster);
    ob->set_property("spell", TO);
    ob->set_property("spell", ({ TO }));
    ob->set_property("spell_creature", TO);
    ob->set_property("minion", caster);
    ob->set_property("effective_enchantment", ((int)CLEVEL / 7));
    caster->set_property("mages_sword", ob);
    ob->move(environment(caster));
    addSpellToCaster();
    return;
}

void dest_effect()
{
    object sword;

    if (objectp(caster)) {
        tell_room(environment(caster), "%^BOLD%^%^CYAN%^The sword in front of " + caster->QCN + " fades away.%^RESET%^", caster);
        tell_object(caster, "%^BOLD%^%^CYAN%^The sword fades away.%^RESET%^");
    }

    if (objectp(control)) {
        if (objectp(sword = control->query_sword())) {
            sword->remove();
            destruct(control);
        }
    }
    if (objectp(caster)) {
        caster->remove_property("mages_sword");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
