#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Presence");
    feat_name("indomitable");
    feat_prereq("Charisma 15");
    feat_desc("Indomitable is a passive feat that grants a small static luck bonus to armor class (+2), allowing the character to better evade blows.");
    permanent(1);
    set_required_for(({"force of personality","anger","calm","unyielding soul","leadership"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if((int)ob->query_base_stats("charisma") < 15) {
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
