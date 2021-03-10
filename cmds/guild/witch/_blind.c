#include <std.h>

inherit DAEMON;

private object *blinded;

int cmd_blind(string str) {
    object ob;
    int tmp;

    if(!str || !(ob=present(lower_case(str), environment(this_player()))))
      return notify_fail("Blind whom?\n");
    if(environment(this_player())->query_property("no magic"))
      return notify_fail("A supernatural force prevents your magic.\n");
    if((string)ob->query_gender() == "female")
      return notify_fail("You cannot blind another female!\n");
    if((int)this_player()->query_mp() < 15)
      return notify_fail("Lasher thinks you need some spiritual rest.\n");
    this_player()->set_magic_round();
    message("my_action", "You pray for Lasher to blind "+
      (string)ob->query_cap_name()+".", this_player());
    message("other_action", (string)this_player()->query_cap_name()+
      "calls upon the powers of Lasher.", environment(this_player()),
      ({ this_player() }));
    this_player()->add_mp(-15);
    tmp = (int)ob->query_stats("wisdom");
    tmp = ((int)this_player()->query_skill("magic attack")+
      (int)this_player()->query_skill("faith"))-(2*tmp);
    if(random(101) > tmp/2) {
        message("my_action", "Lasher has not heard your request.",this_player());
        return 1;
    }
    message("my_action", (string)ob->query_cap_name()+" is now trapped in "+
      "a world of darkness.", this_player());
    message("environment", "You are suddenly trapped in a world of darkness.",
      ob);
    ob->add_sight_bonus(-10);
    if(!blinded) blinded = ({ ob });
    else blinded += ({ ob });
    call_out("remove_blindness", tmp, ob);
    return 1;
}

void remove_blindness(object ob) {
    blinded -= ({ ob });
    if(!ob) return;
    ob->add_sight_bonus(10);
    message("environment", "The cloud of darkness has lifted.", ob);
}

void help() {
    message("help", "Syntax: <blind [player]>\n\n"
      "Throws a male opponent into a world of darkness for a period "
      "of time.", this_player()
    );
}
