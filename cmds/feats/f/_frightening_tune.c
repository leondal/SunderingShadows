#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

#define FEATTIMER 120

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Performance");
    feat_name("frightening tune");
    feat_prereq("Bard L14");
    feat_classes("bard");
    feat_desc("Your play a melody that inspires fear in your opponens. If they fail a save, they'll become momentarely frightened.

%^BOLD%^%^WHITE%^See also:%^RESET%^ status effects.");
    feat_syntax("frightening_tune");

    set_save("will");
}

int allow_shifted()
{
    return 0;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->query_class_level("bard") < 14) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_frightening_tune(string str)
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

    if ((int)caster->query_property("using frightening tune") > time()) {
        tell_object(caster, "You are not prepared to sing the frightening tune so soon!");
        dest_effect();
        return;
    }
    if ((int)caster->query_property("using instant feat")) {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if (!sizeof(caster->query_attackers())) {
        tell_object(caster, "You're not under attack!");
        dest_effect();
        return;
    }

    delay = time() + FEATTIMER;
    delay_messid_msg(FEATTIMER, "%^BOLD%^%^WHITE%^You can sing %^CYAN%^frightening tune%^WHITE%^ again.%^RESET%^");
    caster->set_property("using instant feat", 1);
    caster->remove_property("using frightening tune");
    caster->set_property("using frightening tune", delay);

    tell_object(caster,"%^BLUE%^You muse a melody, inspiring fear in your enemies!");
    tell_room(place,"%^BLUE%^As "+caster->QCN+" muses a melody with the fear itself embedded into it.",caster);

    return;
}

void execute_attack()
{
    int die, i;
    int bonusdc;
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

    targets = caster->query_attackers();

    if (!sizeof(targets)) {
        tell_object(caster, "You are not under attack!");
        dest_effect();
        return;
    }

    targets += ({ caster });

    targets -= ({ caster });

    targets = shuffle(targets);

    bonusdc = flevel;
    bonusdc += BONUS_D->query_stat_bonus(caster, "charisma");

    for (i = 0; i < sizeof(targets) && i < 8; i++) {
        if (targets[i] == caster) {
            continue;
        }

        if (!objectp(targets[i])) {
            continue;
        }

        if (do_save(target, -bonusdc)) {
            continue;
        }

        "/std/effect/status/frightened"->apply_effect(targets[i],roll_dice(1, 4));

        caster->add_attacker(targets[i]);
        targets[i]->add_attacker(caster);
    }

    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
