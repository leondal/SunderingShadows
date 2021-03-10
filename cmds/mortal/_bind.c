#include <std.h>

int cmd_bind(string str)
{
    object who;
    string race, action;
    object what;

    if (TP->query_bound()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }

    if (!str) {
        tell_object(TP, "Bind who?\n");
        //return notify_fail("Bind who??\n");
    }

    if (!who = present(str, ETP)) {
        tell_object(TP, "That is not here.\n");
        //return notify_fail("That is not here.\n");
    }
    if (!TP->ok_to_kill(who)) {
        tell_object(TP, "Supernatural forces prevent you from doing that.\n");
        //return notify_fail("Supernatural forces prevent you from doing that.\n");
    }

    if (!userp(who) && !who->is_townsman()) {
        tell_object(TP, "Binding can only be done in RP situations.\n");
        //return notify_fail("Binding can only be done in RP situations.\n");
    }

    if (sizeof(TP->query_attackers())) {
        tell_object(TP, "You're too busy right now.\n");
        //return notify_fail("You're too busy right now.\n");
    }

    if (!what = present("rope", TP)) {
        if (!what = present("rope", ETP)) {
            tell_object(TP, "You need rope to bind someone.\n");
            //return notify_fail("You need rope to bind someone.\n"); Why is this failing to work now?
        }
    }
    if (!who->query_unconscious() && !who->query_property("submit_bind", TP) &&
        !who->query_bound()) {
        return notify_fail(capitalize(str) + " is gonna fight that ya know.\n");
    }

    if (who->query_bound()) {
/* allowing them to rebind, but still require fresh rope else the person might escape while the others were loosened (which I didn't want to take time to code)  *Styx*  11/22/02
   return notify_fail(str+" is already bound.\n");
*/
        action = "more rope to tighten the bindings on";
    }  else {
        action = "some rope to bind";
    }
    what->remove();
    tell_room(ETP, "%^BOLD%^" + TPQCN + " uses " + action + " " + who->query_cap_name() + "'s hands and feet.", ({ TP, who }));
    tell_object(TP, "%^BOLD%^You use " + action + " " + who->query_cap_name() + "'s hands and feet.");
/*This should change it so that poses are automatically removed when someone is bound so we no longer have strange poses of people standing while bound.  ~Circe~ 10/3/03  Last change was Sept. 17, 2003
 */
    if (who->query_property("posed")) {
        who->remove_property("posed");
        if (!who->query_unconscious()) {
            tell_object(who, "Your pose has been cleared.");
        }
    }
    if (!who->query_unconscious()) {
        tell_object(who, "%^BOLD%^" + TPQCN + " uses " + action + " your hands and feet. You might want to <struggle>.");
    }
    if (who->query_property("submit_bind", TP)) {
        who->remove_property("submit_bind", TP);
    }
//   who->set_bound( (int)TP->query_stats("wisdom") * (int)TP->query_stats("strength") * (random(5) +1));     
    if (who->query_bound()) {
       who->set_bound(who->query_bound() + ((int)TP->query_skill("rope use") * 50));
       TP->set_paralyzed(2, "You are busy binding " + who->query_cap_name());
       return 1;
       }
    else{  
    who->set_bound(1000 + ((int)TP->query_skill("rope use") * 50));
    TP->set_paralyzed(5, "You are busy binding " + who->query_cap_name());
    return 1;
    }
}

// updated help file to mention being able to tighten just by having rope and binding again.
// last change was 5/03 *Styx* 9/17/03

int help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

bind - use ropes on someone

%^CYAN%^SYNOPSIS%^RESET%^

bind %^ORANGE%^%^ULINE%^TARGET%^RESET%^

%^CYAN%^SYNOPSIS%^RESET%^

This command will bind %^ORANGE%^%^ULINE%^TARGET%^RESET%^ with rope in your inventory. You can then %^ORANGE%^<drag>%^RESET%^ them.

The %^ORANGE%^%^ULINE%^TARGET%^RESET%^ must be either unconcious or use %^ORANGE%^<submit>%^RESET%^ to submit to your binding.

Binding will prevent them from running, but bound person can %^ORANGE%^<struggle>%^RESET%^ to get free.

%^CYAN%^SEE ALSO%^RESET%^

unbind, submit, gag, ungag, struggle, drag, drop, strip, blindfold, unblindfold, pkilling, rules, rope use
"
        );
    return 1;
}