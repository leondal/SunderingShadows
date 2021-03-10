#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Stonelord");
    feat_name("earthen blood");
    feat_prereq("Stonelord L1");
    feat_desc("This feat represents the initial infusion of the Stonelord with the raw power of the earth. It affords an immunity to venoms and poisons of all kinds. They also gain immunity against death effects.");
    permanent(1);
    set_required_for(({"mighty resilience", "command the stone"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob) {
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("stonelord") < 1) {
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
