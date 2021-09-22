#include <std.h>
#include <daemons.h>
inherit FEAT;

int help();

void create() {
    ::create();
    feat_type("instant");
    feat_category("ArcaneTrickster");
    feat_name("invisible thief");
    feat_prereq("Arcane Trickster L4");
    feat_syntax("invisible_thief, step");
    feat_desc("An arcane trickster continues to merge her understanding of stealthy and arcane arts. She learns to become invisible like under greater invisibility spell as a free action.

To become visible again she must use the %^ORANGE%^<step>%^RESET%^ command.");
    set_target_required(0);
}

int allow_shifted() { return 1; }

int prerequisites(object ob) {
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("arcane_trickster") < 4) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_invisible_thief(string str) {
    object feat;
    if(!objectp(TP)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,"");
    return 1;
}

void execute_feat()
{
    object invisob, *attackers;
    int total;
    ::execute_feat();
    
    if(this_player()->cooldown("invisible thief"))
    {
        tell_object(this_player(), "You need to wait to use invisible thief.");
        dest_effect();
        return;
    }
    
    tell_object(caster,"%^CYAN%^You simply disappear from plain sight!%^RESET%^");
    total = caster->query_skill("spellcraft") + caster->query_skill("stealth");
    
    attackers = this_player()->query_attackers();
    attackers->remove_attacker(this_player());
    
    foreach(object attacker in attackers)
        this_player()->remove_attacker(attacker);

    invisob=new("/d/magic/obj/invisobgreater.c");
    invisob->set_player_name(caster->query_name());
    invisob->set_mychance(total);
    invisob->move(caster);
    this_player()->add_cooldown("invisible thief", 30);
    dest_effect();
    return;
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}
