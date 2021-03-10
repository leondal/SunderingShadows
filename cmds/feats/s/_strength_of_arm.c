#include <std.h>
#include <daemons.h>
#include <dirs.h>
inherit FEAT;

int MAX;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("TwoHandedWeapons");
    feat_name("strength of arm");
    feat_prereq("Light Weapon");
    feat_desc("The Strength of Arm feat reflects the pinnacle of training for those skilled with two-handed weapons. It will increase their damage dealt from all attacks with a two-handed weapon by more than half again.");
    permanent(1);
    set_target_required(0);
}

int allow_shifted() { return 0; }

int prerequisites(object ob) {
    if(!objectp(ob)) { return 0; }
    if(!FEATS_D->has_feat(ob,"light weapon")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void execute_feat() {
    ::execute_feat();
    dest_effect();
    return;
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}

