//      /bin/user/_aim.c
//      from the Nightmare mudlib
//      the ability to aim for an oppenent's limbs
//      created by Descartes of Borg 11 may 1993

#include <std.h>

inherit DAEMON;

int cmd_aim(string str) {
    string what, whom;
    object ob;
    if(!str) {
        notify_fail("Aim for what?\n");
        return 0;
    }
    if(this_player()->query_disable()) return 1;
    this_player()->set_disable();
    if((int)this_player()->query_sp() < 1) {
        notify_fail("You are too tired.\n");
        return 0;
    }
    if(sscanf(str, "for %s on %s", what, whom) != 2) {
      what = str;
      ob = (object)this_player()->query_current_attacker();
      if(!ob) {
        notify_fail("Aim for what on whom?\n");
        return 0;
      }
    }
    else {
      ob = present(lower_case(whom), environment(this_player()));
      if(!ob) ob = parse_objects(environment(this_player()), lower_case(whom));
      if(!ob) {
        notify_fail("No "+capitalize(whom)+" here.\n");
        return 0;
      }
    }
    if(!living(ob)) {
      notify_fail("That is not a living thing!\n");
      return 0;
    }
    if(!ob->query_is_limb(lower_case(what))) {
      notify_fail(ob->query_cap_name()+" has no "+what+".\n");
      return 0;
    }
    write("You aim for "+ob->query_cap_name()+"'s "+what+".");
    say(this_player()->query_cap_name()+" concentrates on "+ob->query_cap_name()+".");
    if(random(101) < (int)this_player()->query_skill("attack"))
      ob->set_target_limb(lower_case(what));
    this_player()->add_sp(-1);
    return 1;
}

void help() {
    write("Syntax: <aim for [limb] on [enemy]>\n\n"
      "Allows you to aim for a specific limb on an enemy before\n"
      "or during attack.  You may not always be successful.\n"
    );
}
