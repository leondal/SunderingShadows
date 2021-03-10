#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("RangedCombat");
    feat_name("deadeye");
    feat_prereq("Manyshot");
    feat_desc("Deadeye represents the extended training of a skilled archer, allowing them tomake more telling shots on targets at close range.");
    permanent(1);
    set_required_for(({"preciseshot","shot on the run"}));
}

int allow_shifted() { return 0; }

int prerequisites(object ob) {
    if(!objectp(ob)) return 0;
    if(!FEATS_D->has_feat(ob,"manyshot")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

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
