#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("MeleeAccuracy");
    feat_name("weapon finesse");
    feat_desc("This feat represents a character's fine accuracy with melee weapons, allowing them to substitute their dexterity bonus for strength for both hit and damage modifiers. This is only functional while wielding weapons of a size category smaller than or of the same size as the character, or small weapon types only for small creatures, or when using unarmed attacks.");
    set_replaces_feat("ambidexterity");
    set_required_for(({"two weapon fighting","improved two weapon fighting","unassailable parry","whirl", "greater two weapon fighting"}));
    permanent(1);
}

int allow_shifted() { return 1; }

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

