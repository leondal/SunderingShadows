#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

#define FEATTIMER 60

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Performance");
    feat_name("soothing song");
    feat_prereq("Bard L12");
    feat_classes("bard");
    feat_desc("With this song bard heals and restores her allies, removing exhaustion, confusion and negative levels. This feat also heals wounds.");
    feat_syntax("soothing_song");
    set_target_required(0);
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
    if (ob->query_class_level("bard") < 12) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_soothing_song(string str)
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

    if ((int)caster->query_property("using soothing song") > time()) {
        tell_object(caster, "You are not prepared to sing the soothing song so soon!");
        dest_effect();
        return;
    }

    if ((int)caster->query_property("using instant feat")) {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }

    delay = time() + FEATTIMER;
    delay_messid_msg(FEATTIMER, "%^BOLD%^%^WHITE%^You can sing %^CYAN%^soothing song%^WHITE%^ again.%^RESET%^");
    caster->set_property("using instant feat", 1);
    caster->remove_property("using soothing song");
    caster->set_property("using soothing song", delay);

    tell_object(caster,"%^BOLD%^%^WHITE%^You muse a melody of tranquility.");
    tell_room(place,"%^ORANGE%^As "+caster->QCN+" muses a melody of tranquility.",caster);

    return;
}

void execute_attack()
{
    int die, i;
    int dam;
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

    targets = ob_party(caster) + (caster->query_followers() - caster->query_attackers()) + ({ caster });
    targets = filter_array(targets, (: environment($1) == $2:), environment(caster));

    targets = shuffle(targets);
    targets = ({caster}) + targets;

    targets = distinct_array(targets);
  
    die = 9 + FEATS_D->usable_feat(caster, "epic tales") * 2;
    dam = roll_dice(flevel, die);

    tell_room(place, "%^BOLD%^%^WHITE%^Tranquil melody heals wounds of " + caster->QCN + "'s allies.", caster);
    tell_room(place, "%^BOLD%^%^WHITE%^Tranquil melody heals wounds of your allies.");
    for (i = 0; i < sizeof(targets) && i < 8; i++) {
        if (!objectp(targets[i])) {
            continue;
        }

        tell_object(targets[i],"%^BOLD%^%^WHITE%^Your wounds and fatigue wash away in the melody.");
        targets[i]->cause_typed_damage(targets[i], targets[i]->return_target_limb(), -dam, "untyped");
        "/std/magic/cleanse"->restore(targets[i]);
    }

    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
