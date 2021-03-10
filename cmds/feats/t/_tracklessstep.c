#include <std.h>
#include <daemons.h>
inherit FEAT;

int help();

void create() {
    ::create();
    feat_type("instant");
    feat_category("WildernessLore");
    feat_name("tracklessstep");
    feat_syntax("tracklessstep");
    feat_desc("A character with this feat leaves no trace of their passing in natural surroundings. They can, however, choose to temporarily leave tracks if they wish, by activating the feat. Using the command again will return the user to leaving no sign of passing.");
    set_target_required(0);
}

int allow_shifted() { return 1; }

int prerequisites(object ob) {
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("druid") < 3) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_tracklessstep(string str) {
    object feat;
    if(!objectp(TP)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,"");
    return 1;
}

void execute_feat() {
    object *featobs;
    int i;
    ::execute_feat();
    if(FEATS_D->is_active(caster,"tracklessstep")) {
        tell_object(caster,"%^BOLD%^You re-attune yourself with the energies of the wild, your steps becoming unnoticable again.");
        featobs = (object *)caster->query_property("active_feats");
        if(sizeof(featobs)) {
          for(i=0;i<sizeof(featobs);i++) {
            if(!objectp(featobs[i])) continue;
            if((string)featobs[i]->query_feat_name() == "tracklessstep") caster->remove_property_value("active_feats",({featobs[i]}));
          }
        }
        dest_effect();
        return;
    }
    tell_object(caster,"%^BOLD%^You forgo your attunement to the wild, deliberately leaving signs of your passing as you move.%^RESET%^");
    caster->set_property("active_feats",({TO}));
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}

