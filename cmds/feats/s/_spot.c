//fixed typos in the description ~Circe~ 8-16-2020
#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("GeneralCombat");
    feat_name("spot");
    feat_desc("The spot skill is used primarily to detect characters or creatures who are hiding. Typically, your spot check is opposed by the stealth check of the creature trying not to be seen. Spot increases your ability to passively perceive, removing the penalty to perception when making passive rolls.

A spot check might allow you to become aware of hidden creatures around you. Unlike other spot checks, this one is rolled against the target's stealth.

Spot, like passive perception, is entirely deterministic in this game and offers no chances. It either works or does not.

%^BOLD%^See also:%^RESET%^ status effects");
    permanent(1);
    allow_blind(1);
}

int allow_shifted() { return 1; }

void execute_feat() {
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob) {
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob) {
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}
