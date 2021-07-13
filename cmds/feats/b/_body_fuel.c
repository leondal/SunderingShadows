#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

#define FEATTIMER 35

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Psionics");
    feat_name("body fuel");
    feat_prereq("Psywarrior L1 or Psion L1");
    feat_desc("You convert some of d12 points of your health per psionic guild level into ten times less power points.");
    feat_syntax("body_fuel");
    psionic(1);
}

int allow_shifted()
{
    return 1;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!(ob->is_class("psywarrior") ||
          ob->is_class("psion"))) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_body_fuel(string str)
{
    object feat;

    if (!objectp(TP)) {
        return 0;
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP, "");
    return 1;
}

void execute_feat()
{
    mapping tempmap;
    int delay;
    ::execute_feat();

    if ((int)caster->query_property("using instant feat")) {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }

    clevel = max(({ caster->query_class_level("psion"),
                    caster->query_class_level("psywarrior") }));
    // Fix for using full caster level instead of class level 06/21/2020 -- garrett

    caster->set_property("using instant feat", 1);
    return;
}

void execute_attack()
{
    int die, i, dmg, myint, yourint, extra;
    object* targets;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }

    caster->remove_property("using instant feat");
    ::execute_attack();

    if (caster->query_unconscious()) {
        dest_effect();
        return;
    }

    die = 12;

    dmg = roll_dice(clevel, die);

    tell_object(caster,"%^BOLD%^%^WHITE%^A wave of pain pierces through your body as you extend your focus.");
    caster->cause_typed_damage(caster, 0, dmg, "untyped");
    caster->add_mp(dmg / 10);

    caster->set_property("magic", -1);
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
