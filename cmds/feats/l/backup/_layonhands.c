#include <std.h>
#include <daemons.h>
#include <magic.h>
#include <dieties.h>
inherit FEAT;

#define FEATTIMER 45

void create() {
    ::create();
    feat_type("instant");
    feat_category("Presence");
    feat_name("layonhands");
    feat_syntax("layonhands TARGET");
    feat_desc("This will heal the player you choose,increasing in power with your level and your charisma. Invokingthis kind of divine power can be wearying, so the paladin willneed to wait a few minutes before they can attempt to use such ablessing again.");
    feat_prereq("Paladin L6");
    set_target_required(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(ob->query_class_level("paladin") < 6 ) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_layonhands(string str) {
    object feat;
    if(!objectp(TP)) return 0;
    if(!stringp(str)) return 0;
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void execute_feat() {
    mapping tempmap;
    int delay;
    string mygawd, *mygawds;
    ::execute_feat();
    if(!objectp(target)) {
        dest_effect();
        return;
    }
    if((int)caster->query_property("using layonhands") > time()) {
        tell_object(caster,"You are not prepared to channel such powerful energies again so soon!");
        dest_effect();
        return;
    }
    delay = time() + FEATTIMER;
    delay_msg(FEATTIMER,"%^BOLD%^%^WHITE%^You can %^CYAN%^layonhands%^WHITE%^ again.%^RESET%^");
    caster->remove_property("using layonhands");
    caster->set_property("using layonhands",delay);
    return;
}

void execute_attack() {
    int chamod;

    if(!objectp(caster)) {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();

    if(caster->query_unconscious()) {
        dest_effect();
        return;
    }
    if(!objectp(target) || !present(target,place)) {
        tell_object(caster,"Your target has vanished!");
        dest_effect();
        return;
    }

    tell_object(caster,"%^BOLD%^%^CYAN%^You concentrate deeply and touch "+(string)target->QCN+".%^RESET%^");
    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" touches "+(string)target->QCN+" and concentrates for a moment.%^RESET%^",({target,caster}));
    if(target != caster) tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" touches you and concentrates for a moment.%^RESET%^");

    chamod = (((int)caster->query_stats("charisma") - 10)/2);
    if(chamod < 1) chamod = 1;
    target->add_hp(2 * (int)caster->query_level() * chamod);
    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}
