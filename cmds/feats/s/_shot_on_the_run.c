#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("RangedCombat");
    feat_name("shot on the run");
    feat_prereq("Preciseshot");
    feat_desc("The most skilled marksmen are able to master shooting at close range while continuing to move, so that at times they are able to get clear of imminent attacks before they have even landed.  Note you must be wielding a ranged weapon in your main hand for this feat to work.

%^BOLD%^N.B.%^RESET%^ This feat is not effective against ranged attackers, as the marksman does not gain sufficient distance to out-range their attacks.

%^BOLD%^N.B.%^RESET%^ This feat does not work in conjunction with ride-by attack, as it is effectively the same action, but not on horseback.");
    permanent(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob) {
    if(!objectp(ob)) return 0;
    if(!FEATS_D->has_feat(ob,"preciseshot")) {
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
