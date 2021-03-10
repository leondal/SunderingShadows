#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("premanent");
    feat_category("Evasion");
    feat_name("evasion");
    feat_prereq("13 Dexterity, Dodge");
    feat_desc("This passive feat grants the character the ability to entirely avoid damage from certain spells. Any spell that allows damage to be halved by a successful reflex save, will instead cause no damage if the save is made. A failed save will still result in full damage being taken. This feat is only effective in light or no armor.");
    permanent(1);
    set_required_for(({"scramble","spring attack"}));

}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(!FEATS_D->has_feat(ob,"dodge") && !ob->is_class("ranger")) {
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
