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
    feat_name("psionicweapon");
    feat_prereq("Psywarriors L5 or Psion L11");
    feat_desc("With this feat psionic character can build a charge of raw psychic energy and deliver an untyped damage to every attaker. This feat consumes 1d6 power points when used.");
    feat_syntax("psionicweapon");
    set_required_for(({ "greaterpsionicweapon" }));
    psionic(1);
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
    if (ob->query_class_level("psywarrior") < 5 && ob->query_class_level("psion") < 11) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_psionicweapon(string str)
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

    if ((int)caster->query_property("using smite") > time()) { //keeping the same variable to avoid stacking
        tell_object(caster, "You are not prepared to exert such mental force again so soon!");
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
    delay_messid_msg(FEATTIMER, "%^BOLD%^%^WHITE%^You can %^CYAN%^psionicweapon%^WHITE%^ again.%^RESET%^");
    caster->set_property("using instant feat", 1);
    caster->remove_property("using smite");
    caster->set_property("using smite", delay);
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

    die = 4;

    if (FEATS_D->usable_feat(caster, "mind wave")) {
        die = 6;
    }

    targets = caster->query_attackers();

    if (!sizeof(targets)) {
        tell_object(caster, "You are not under attack, and your mental force dissipates harmlessly!");
        dest_effect();
        return;
    }

    caster->set_property("magic", 1);
    targets += ({ caster });
    tell_object(caster, "%^RESET%^%^MAGENTA%^The power within you grows to a fever pitch, and you release a psionic tempest that slices through your enemies!");
    tell_room(place, "%^RESET%^%^MAGENTA%^A low hum resonates throughout the area before " + caster->QCN + " unleashes a psionic tempest that slices through " + caster->QP + " enemies!", targets);
    targets -= ({ caster });

    targets = shuffle(targets);

    for (i = 0; i < sizeof(targets) && i < 8; i++) {

        if (targets[i] == caster) {
            continue;
        }

        if (!objectp(targets[i])) {
            continue;
        }
        tell_object(targets[i], "%^BOLD%^%^MAGENTA%^" + caster->QCN + " releashes a psionic tempest that slices through your mind like countless blades!%^RESET%^");
        dmg = roll_dice(clevel, die);

        caster->cause_damage_to(targets[i], "head", dmg);
        caster->add_attacker(targets[i]);
        targets[i]->add_attacker(caster);
    }

    caster->add_mp(-roll_dice(1, 6));
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
