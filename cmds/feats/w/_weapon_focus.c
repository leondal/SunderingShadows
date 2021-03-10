#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("WeaponMastery");
    feat_name("weapon focus");
    feat_prereq("None");
    feat_desc("You gain a +1 bonus on all attack rolls you make.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    return ::prerequisites(ob);
}

void execute_feat(){
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob){
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob){
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}
