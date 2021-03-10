#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Stonelord");
    feat_name("command the stone");
    feat_prereq("Stonelord L7, Mighty Resilience");
    feat_desc("So strong becomes the Stonelord's bond with the earth, that he or she can command
it by magical means. Several new spells are learned as innate abilities:

  strength of stone,
  meld into stone,
  earth reaver,
  conjure elemental (earth only),
  wall of stone,
  statue,
  stone body,
  earthquake,
  shapechange (golem only)");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("stonelord") < 7) {
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
