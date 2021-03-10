//     /wizards/kalinash/bin/_fear.c
//     A spell for those evil little kataans... ;)
//     By Kalinash@Nightmare on 1 Jan 94
 
#include <std.h>
 
inherit DAEMON;
 
int cmd_fear() {
    object who, me;
    int x, mw, hw, mma, hmd, amt, tot;
 
    me = this_player();
    if((string)me->query_class() != "kataan")
        return notify_fail("You mumble in confusion.\n");
    if(me->query_ghost())
        return notify_fail("You are not fearfull in your etherial state.\n");
    if(environment(me)->query_property("no magic") ||
      environment(me)->query_property("no attack"))
        return notify_fail("A supernatural force stops your spell.\n");
    if((int)me->query_skill("faith") < 25)
        return notify_fail("You are not yet ready for this spell.\n");
    if(me->query_casting())
        return 1;
    if((int)me->query_mp() < 0)
        return notify_fail("You're mind is too fatigued for that.\n");
    if(!who=me->query_current_attacker())
        return notify_fail("You are not fighting anyone!\n");
    if(who->query_property("no fear"))
	return notify_fail(sprintf("You will ever strike fear into %s.",
          who->query_objective()));
    mma = (int)me->query_skill("faith");
    mw = (int)me->query_stats("wisdom");
    message("my_action", "You call upon your powers to strike fear into "
      "the hearts of you enemies!", me);
    message("their_action", sprintf("%s casts a spell of fear!",
      me->query_cap_name()), environment(me), me);
    hw = (int)who->query_stats("wisdom");
    hmd = (int)who->query_skill("magic defense");
    amt = (mma - hmd) / 10;
    amt = amt + ((mw - hw) / 5);
    if(amt > 0) {
        tot += amt;
        amt = random(amt + (int)who->query_level());
    }
    if(amt >= 30) {
        who->set_paralyzed(amt, "You are too scared to move!");
        message("their_action", sprintf("%s strikes fear into your heart!",
          me), who);
        message("my_action", sprintf("You paralyze %s with fear!",
          who->query_cap_name()), me);
    }
    if(amt < 30 && amt >= 10) {
        string *going, des, home;
 
        message("my_action", "You run away, screaming in terror!", who);
        message("their_action", sprintf("%s runs away, screaming in terror.",
              who->query_cap_name()), environment(who), who);
            home = file_name(environment(who));
            going = environment(me)->query_destinations();
            who->move(going[random(sizeof(going))]);
            if(!who->is_player())
                call_out("go_home", 30, ({ who, home}) );
    }
    if(amt > 0 && amt < 10) {
        message("their_action", "You shiver in fear, but hold your ground.",
          who);
        message("my_action", sprintf("%s holds %s ground.",
          who->query_cap_name(), who->query_possessive()), me);
        }
    if(amt < 1) {
        message("my_action", "You failed to scare a single thing.", me);
        return 1;
    }
    me->add_mp(-(tot * 10));
    me->add_skill_points("magic attack", tot);
    return 1;
}
 
void go_home(mixed *drow) {
    drow[0]->move_player(drow[1], "timidly");
}
 
void help() {
    message("help", "Usage : <fear>\n\nThis spell causes your enemy "
      "to see you as his deepest, darkest fear.",
      this_player());
    return;
}
