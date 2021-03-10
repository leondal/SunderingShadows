#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Horsemanship");
    feat_name("mounted combat");
    feat_desc("A character with this feat substitutes a roll on their athletics skill for their mount's armor class, serving as an indication that they can steer their mount skillfully enough to avoid the blow. If the mount's armor class exceeds the rider's athletics skill, this feat has no effect.");
    permanent(1);
    set_required_for(({"ride-by attack","charge","trample"}));
}

int allow_shifted() { return 0; }

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

