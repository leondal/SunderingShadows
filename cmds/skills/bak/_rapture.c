#include <std.h>

inherit DAEMON;

int cmd_rapture(string str) {
    object env;
    object *inv;
    int i, tmp;

    if(str) return 0;
    env = environment(this_player());
    if(!env) return 0;
    if(this_player()->query_ghost()) {
        notify_fail("Bah! You have already experienced rapture!\n");
        return 0;
    }
    if(env->query_property("no magic") || env->query_property("no attack")) {
        notify_fail("A holy force prevents the rapture.\n");
        return 0;
    }
    if((int)this_player()->query_mp() < 20) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    if((int)this_player()->query_skill("faith") < 65) {
        notify_fail("You do not have the faith to bring about rapture.\n");
        return 0;
    }
    if(!alignment_ok(this_player())) {
        notify_fail("You have betrayed the source of your powers.\n");
        return 0;
    }
    for(i=0, tmp =sizeof((inv=users())); i<tmp; i++) {
        if(inv[i]->query_blocked("shout")) continue;
        if(wizardp(inv[i])) continue;
        if(!inv[i]->query_ansi()) tell_object(inv[i],
          "%^RED%^The air begins to thicken and bleed red with impending death through rapture.\n%^RESET%^");
        else tell_object(inv[i], red("The air begins to thicken and bleed red with impending death through rapture.\n"));
    }
    this_player()->set_magic_round();
    call_out("do_rapture", 7, env);
    this_player()->add_mp(-(int)this_player()->query_mp()); //abuse fix 930907 blodgett
    this_player()->set_paralyzed(8);
    return 1;
}

void do_rapture(object env) {
    mapping who;
    object *inv, *chambres;
    string *sorties;
    int i, j, tmp2, tmp, tmp_al, damage;
    object tmp_ob;

    if(!present(this_player(), env)) {
      write("The force of your spell causes you to return to the place\n"
            "of rapture.");
      if(env)
        this_player()->move(env);
    }
    for(i=0, tmp = (sizeof(inv = users())); i<tmp; i++) {
        if(wizardp(inv[i])) continue;
        if(inv[i]->query_blocked("shout")) continue;
        tell_object(inv[i], "%^BLUE%^BOLD%^Rapture is here.%^RESET%^");
    }
    chambres = ({ env });
    sorties = (string *)env->query_destinations();
    if(sorties && sizeof(sorties)) {
        for(i=0, tmp = sizeof(sorties); i<tmp; i++) {
            call_other(sorties[i], "???");
            if(!(tmp_ob = find_object(sorties[i]))) continue;
            if(tmp_ob->query_property("no magic")) continue;
            chambres += ({ tmp_ob });
        }
        chambres = distinct_array(chambres);
    }

    for(i=0, tmp=sizeof(chambres), who = ([]); i<tmp; i++) {
        inv = all_inventory(chambres[i]);
        for(j=0, tmp2=sizeof(inv); j<tmp2; j++) {
            if(!living(inv[j])) continue;
            who[inv[j]] = ({
              (int)inv[j]->query_alignment(), (int)inv[j]->query_max_mp(),
              (int)inv[j]->query_hp()
            });
        }
    }
    tmp = sizeof((inv=keys(who)));
    write("Your prayers bring rapture to the world.\n");
    for(i=0; i<tmp; i++) {
        if(wizardp(inv[i])) continue;
        if(this_player() != inv[i] && !inv[i]->kill_ob(this_player(), 0))
          continue;
        tmp_al = who[inv[i]][0] + 2000;
        inv[i]->add_mp(-(who[inv[i]][1]));
        damage = (int)this_player()->query_skill("faith") - to_int(percent(tmp_al, 3000));
        if(damage < 1) damage = 1;
        damage = (damage*(who[inv[i]][2]))/100;
        damage -= (int)inv[i]->query_spiritual();
        if(damage>this_player()->query_max_hp())
          damage=3*(int)this_player()->query_max_hp();
        inv[i]->add_hp(-damage);
	if(!inv[i]->query_property("no paralyze")) {
          inv[i]->set_paralyzed(random(100-(int)inv[i]->query_level()));
	}
        if(inv[i] != this_player()) {
          if(inv[i]->query_ansi()) tell_object(inv[i], 
            bold(red((string)this_player()->query_cap_name()+" has brought rapture to our reality.\n")));
          else tell_object(inv[i],
            this_player()->query_cap_name()+" has brought rapture to our reality.\n");
        }
    }
    return;
}

void help() {
    write("Syntax: <rapture>\n\n"
        "The faithful may use this prayer to bring rapture to their\n"
        "area of reality.  This should be used with *extreme* caution.\n"
    );
}
