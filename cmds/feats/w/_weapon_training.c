#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("WeaponMastery");
    feat_name("weapon training");
    feat_prereq("Fighter L5"); // weapon training
    feat_desc("This feat, available only as a class skill to trained fighters, increases the accuracy of all attacks with weapons. It provides +1 to attack and damage bonuses for every ten levels in the fighter class.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob) {
    if(!objectp(ob)) { return 0; }
    if(ob->query_class_level("fighter") < 5) {
        dest_effect();
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
