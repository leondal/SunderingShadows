#include <std.h>
#include <daemons.h>

inherit OBJECT;
int trap_setter;
string MyExit;

void create()
{
    ::create();

    set_name("caltrops");
    set_id(({ "caltrops", "caltrop", "Caltrop", "mess", "handful" }));
    set_short("Hand full of caltrops");
    set_long("These are a collection of small spheroids. Some have small spikes on them others have simple smooth shiny solid shells. They are obviously made to trip and/or hurt people.");
    set_weight(2);
    set_value(100);
}

void init()
{
    ::init();
    if (TP == ETO) {
        set_short("Hand full of caltrops");
        add_action("spread", "spread");
    }
}

void set_origin_object(string str)
{
    MyExit = str;
}

int query_dc()
{
    return 1;
}

void set_my_dc(int x)
{
    return;
}

void set_trap_setter(int x)
{
    trap_setter = x;
}

void backfire(object who)
{
    object env;
    if (!objectp(who)) {
        return;
    }
    if (!objectp(env = environment(who))) {
        return;
    }
    tell_object(who, "%^RED%^Oh NO!  As you spread the caltrops around " +
                "toward " + MyExit + " direction you drop most of them and....%^RESET%^");

    tell_room(env, who->QCN + "%^RED%^ seems to be spreading something around " +
              "toward the " + MyExit + " direction and drops a handful of sharp " +
              "balls.... %^RESET%^", who);

    tell_object(who, "%^BLUE%^... you stumble around on the caltrops and " +
                "feel your footing give out!%^RESET%^");

    tell_room(env, who->QCN + "%^BLUE%^ stumbles around on the sharp balls " +
              "before falling flat on " + who->QP + " back!%^RESET%^", who);

    tell_object(who, "%^BOLD%^You fall flat on your back and the shock of " +
                "fall has left you stiff as you try to scramble to your feet!%^RESET%^");

    who->set_tripped(2, "The caltrops have tripped you up.");
}

int spread(string str)
{
    string exit;
    if (!str) {
        write("spread caltrops <exit>");
        return 1;
    }

    if (sscanf(str, "caltrops %s", exit) != 1) {
        write("spread caltrops <exit>");
        return 1;
    }

    if (userp(TP) && !FEATS_D->usable_feat(TP, "tools of the trade")) {
        tell_object(TP, "You wouldn't know how to use those!");
        return 1;
    }
    if ((int)TP->is_retinue()) {
        tell_object(TP, "You wouldn't know how to use those!");
        return 1;
    }

    if (TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }

    if (member_array(exit, ETP->query_exits()) == -1) {
        write("That exit does not exist.");
        return 1;
    }
    MyExit = exit;
    if (ETP->is_trapped(exit)) {
        if (ETP->execute_trap(exit, TP, 1)) {
            backfire(TP);
            TO->remove();
            return 1;
        }
    }

    if (ETP->is_this_trapped(exit)) {
        backfire(TP);
        TO->remove();
        return 1;
    }

    MyExit = exit;
    //1 is important because it tells the code that a player
    //set this trap - other stuff dictates its your trap
    //and you wont trigger it
    ETP->set_trapped(({ MyExit }), ({ "custom" }), ({ base_name(TO) }), 1);
    ETP->add_passed_check(MyExit, TPQN);
    ETP->set_trap_set_by(MyExit, TPQN, 1);
    ETP->add_known_to(MyExit, "player", TPQN);

    tell_object(TP, "You spread the caltrops around the room hoping " +
                "to catch anyone going " + exit + ".");

    if (!TP->query_invis()) {
        tell_room(ETP, "You see " + TPQCN + " spread something out toward the " +
                  exit + " direction.", TP);
    }

    TO->remove();
    return 1;
}

void trap_activated(object who)
{
    if (!objectp(who)) {
        return;
    }
    if (!objectp(environment(who))) {
        return;
    }
    if (who->query_property("flying")) {
        return;
    }

    tell_object(who, "As you walk " + MyExit + " you suddenly feel your footing slip.");

    tell_room(environment(who), "As " + who->QCN + " walks " +
              MyExit + " " + TP->QS + " suddenly slips,", who);

    tell_object(who, "Your feet fly out in front of you and you find yourself " +
                "falling flat on your back.");

    tell_room(environment(who), who->QP + "'s feet go flying up in the air and " +
              who->QS + " lands hard on the ground.", who);

    tell_object(who, "You feel the pain of a few of the sharp balls sticking " +
                "in your back.");
    tell_object(who, "The shock of the landing has left you stiff as you try " +
                "to scramble to your feet.");

    if (trap_setter == 1) {
        TO->set_property("knock unconscious", 1);
    }
    who->do_damage(who->return_target_limb(), roll_dice(2, 4));
    if (trap_setter == 1) {
        TO->remove_property("knock unconscious");
    }
    who->set_tripped(2, "The caltrops have tripped you up.");
}
