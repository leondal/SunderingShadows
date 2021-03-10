#include <std.h>

inherit DAEMON;

int cmd_corrupt(string str) {
    object env;
    object *inv;
    int i, tmp_al, damage, max, faith;

    this_player()->set_magic_round();
    if(str) return 0;
    env = environment(this_player());
    if(!env) return 0;
    if(this_player()->query_ghost()) {
        write("You howl evilly.\n");
        say("You hear an evil howl.\n");
        return 1;
    }
    if(env->query_property("no magic") || env->query_property("no attack")) {
        notify_fail("A holy force prevents you from corrupting souls.\n");
        return 0;
    }
    if((int)this_player()->query_mp() < 20) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    if(faith = (int)this_player()->query_skill("faith") < 50) {
        notify_fail("You do not have the faith to bring about corruption in others.\n");
        return 0;
    }
    if((string)this_player()->query_class() == "kataan" && 
      !alignment_ok(this_player())) {
        notify_fail("You have betrayed the source of your powers.\n");
        return 0;
    }
        this_player()->set_disable();
    write("You attempt to corrupt the souls of those about you.\n");
    for(i=0, max = sizeof(inv=all_inventory(env)); i<max; i++) {
        if(!living(inv[i])) continue;
        if(wizardp(inv[i])) continue;
        if(this_player() != inv[i] && !inv[i]->kill_ob(this_player(), 0))
          continue;
        tmp_al = 2000 - (int)inv[i]->query_alignment();
        inv[i]->add_sp(-200);
        this_player()->add_mp(-20);
        damage = faith - to_int(percent(tmp_al, 3000));
        if(damage < 1) damage = 1;
        faith = (int)inv[i]->query_skill("faith");
        damage = (damage*faith*faith)/100;
        damage -= (int)inv[i]->query_spiritual();
        this_player()->add_skill_points("faith", damage/5);
        this_player()->add_alignment(-(random(9)));
        inv[i]->reduce_skill_points("faith", damage);
        if(inv[i] != this_player()) {
          if(inv[i]->query_ansi()) tell_object(inv[i], 
            bold(yellow((string)this_player()->query_cap_name()+" has corrupted your soul.\n")));
          else tell_object(inv[i],
            this_player()->query_cap_name()+" has corrupted your soul.\n");
        }
    }
    return 1;
}

void help() {
    write("Syntax: <corrupt>\n\n"
        "This spell weakens the faith of followers of good.\n"
    );
}
