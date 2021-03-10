// note: property is "stab_resilience" which is re-iterated each round in user, same place stab ops are done. Nienne, 4/17.
#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Stonelord");
    feat_name("mighty resilience");
    feat_prereq("Stonelord L4");
    feat_desc("The Stonelord's kinship with the earth grows, his or her body taking on more of its attributes. He will ignore all of the stabs from rogues of the same level.");
    permanent(1);
    set_required_for(({"command the stone"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob) {
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("stonelord") < 4 )
    {
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

