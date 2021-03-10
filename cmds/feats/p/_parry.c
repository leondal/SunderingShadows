#include <std.h>
#include <daemons.h>
#include <dirs.h>
inherit FEAT;

int MAX;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("WeaponMastery");
    feat_name("parry");
    feat_desc("The Parry feat will give you a chance based on your athletics skill to parry all attacks that are directed your way. This feat is only available to fighters and cavaliers as a class skill, and can substitute for blade block and unassailable parry  Note you must be wielding a melee weapon in your main hand for this feat to work.

%^BOLD%^N.B.%^RESET%^ Parry, unassailable parry, unarmed parry and blade block feats do not stack. Just one will work at a time.");
    feat_prereq("Fighter or Paladin");
    permanent(1);
    set_required_for(({"weapon focus","weapon specialization","greater weapon focus","greater weapon specialization"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob) {
    if(!objectp(ob)) { return 0; }
    if(!ob->is_class("fighter") &&
        !ob->is_class("cavalier") &&
        !ob->is_class("paladin") &&
        !ob->is_class("antipaladin") &&
        !FEATS_D->has_feat(ob, "fighter training")) {
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
