#include <std.h>
#include <daemons.h>
#include <tell.h>

inherit DAEMON;

int imm_filter(object obj, string* targ)
{
    string* listening = ({});

    if (!objectp(obj)) {
        return 0;
    }
    if (!avatarp(obj)) {
        return 0;
    }
    if (!pointerp(obj->query("listen_tells"))) {
        obj->set("listen_tells", ({}));
    }
    listening = (string*)obj->query("listen_tells");
    if (member_array(targ[0], listening) == -1 && member_array(targ[1], listening) == -1) {
        return 0;
    }
    return 1;
}

void tell_listening_immortals(string mess, object teller, object listener)
{
}

object resolve_tell_playerob(string whom)
{
    object ob;
    string real_whom, whom2;

    ob = find_player(whom2 = lower_case(whom));

    if (objectp(ob) && (avatarp(ob) || avatarp(TP))) {
        return ob;
    }
    real_whom = TP->realNameVsProfile(whom2);
    if (objectp(ob = find_player(real_whom))) {
        return ob;
    }
}

object resolve_tell_living(string whom, string verbiage)
{
    string whom2, mess2;
    object ob;

    if (sscanf(verbiage, "%s %s", whom2, mess2) != 2) {
        whom2 = verbiage;
    }
    if (objectp(ob = find_living(capitalize(whom)))) {
        return ob;
    }
    if (objectp(ob = find_living(capitalize(whom) + " " + capitalize(whom2)))) {
        return ob;
    }
    return 0;
}

int cmd_tell(string str)
{
    string tell_msg, who, target, msg;
    string namestr;
    string* ignored;
    object ob, *telepaths;

    if (!str || sscanf(str, "%s %s", who, msg) != 2) {
        notify_fail("usage: tell <player> <message>\n");
        return 0;
    }

    if (!objectp(ob = resolve_tell_playerob(who))) {
        if (!objectp(ob = resolve_tell_living(who, msg))) {
            notify_fail(capitalize(who) + NOT_HERE + "\n");

            return 0;
        } else {
            if (!ob->is_npc_psychic()) {
                return notify_fail(capitalize(who) + NOT_HERE + "\n");
            }
        }
    }
    if (ob->is_npc_psychic()) {
        sscanf(str, lower_case(ob->query_true_name()) + " %s", msg);
    }

    if (!avatarp(TP) && !avatarp(ob)
        && !(pointerp(TP->query_property("allowed tell"))
             && member_array(ob->query_true_name(), (string*)TP->query_property("allowed tell")) != -1)) {
        notify_fail("What?");
        return 0;
    }

    ignored = ob->query_ignored();
    if (!ignored) {
        TP->reset_ignored();
        ignored = TP->query_ignored();
    }

    if (wizardp(ob) || wizardp(TP)) {
        namestr = capitalize(TPQN);
    } else {
        namestr = capitalize(TP->getParsableName());
    }

    if ((int)ob->query_quietness() && wizardp(ob) && !wizardp(TP)) {
        message("info", sprintf("%s%s", capitalize(who), NOT_HERE),
                this_player());
        return 1;
    }

    if (ob->query_quietness() && !avatarp(TP)) {
        message("info", sprintf("%s%s", capitalize(who), NOT_HERE), this_player());

        if (member_array(TPQN, ignored) == -1 || wizardp(TP)) {
            message("reply", sprintf("%^CYAN%^%s is unaware of telling you: %s", namestr, msg), ob);
            if (!TP->query_disguised() || !wizardp(TP)) {
                ob->set("reply", TP->getParsableName(ob));
            } else {
                ob->set("reply", this_player()->query_vis_name());
            }
            ob->set("reply object", TP);
        }
        return 1;
    }

    if (ob->query_blocked("reply") && !avatarp(TP)) {
        write(ob->query_cap_name() + " is currently blocking all tells.");
        return 1;
    }

    if (ob->is_player() && !interactive(ob)) {
        notify_fail(ob->query_cap_name() + " is link-dead and cannot hear you.\n");
        return 0;
    }

    if ((member_array(TPQN, ignored) != -1) && !wizardp(TP)) {
        write(capitalize(ob->query_name()) + " is ignoring you.");
        return 1;
    }

    message("reply", "%^BOLD%^%^RED%^" + namestr + " tells you: %^RESET%^" + msg, ob);
    if (!TP->query_disguised() || !wizardp(TP)) {
        ob->set("reply", TP->getParsableName(ob));
    } else {
        ob->set("reply", this_player()->query_vis_name());
    }
    ob->set("reply object", TP);

    if (TP->query_blocked("reply")) {
        TP->set_blocked("reply");
    }
    if (ob->is_npc_psychic()) {
        message("reply", "%^BOLD%^%^RED%^You tell " + ob->getParsableName() + "%^RESET%^: " + msg, TP);
    } else {
        message("reply", "%^BOLD%^%^RED%^You tell " + capitalize(who) + "%^RESET%^: " + msg, TP);
    }

    if (!wizardp(ob) && !wizardp(TP) && !ob->query_true_invis() && !TP->query_true_invis()) {
        CHAT_D->force_chat(TP, "telepathy", "tells " + ob->QCN + " ( " + msg + " )", 1);
    }
    
    //Telepath passive tell detection. Should pick up bits of he conversation, not the whole thing.
    telepaths = all_inventory(environment(this_player()));
    telepaths = filter_array(telepaths, (: userp($1) :));
   
    
    foreach(object obj in telepaths)
    {
        int DC;
        
        if(this_player()->query_level() > obj->query_level() + 5)
            continue;
            
        if(obj->query_property("read thoughts") != this_player())
            continue;
        
        if(this_player()->query_discipline() == "telepath")
            continue;
        
        DC = obj->query_stats("intelligence") - this_player()->query_stats("wisdom");
        DC += 10;
        
        if(roll_dice(1, 20) < DC)
            continue;
        
        tell_object(obj, "%^BOLD%^CYAN%^You pick up a fleeting thought . o 0 %^WHITE%^(" + msg + ")%^RESET%^");
    }

#include <detect_thoughts.h>

    if (!ob->is_player()) {
        return 1;
    }
    if (query_idle(ob) > IDLE_TIME) {
        write(capitalize(who) +
              " is idle, and may not have been paying attention.");
    }
    if (in_edit(ob) || in_input(ob)) {
        message("info", capitalize(who) + " is daydreaming and may not be in a position to respond.", this_player());
    }
    return 1;
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

tell - tell something someone

%^CYAN%^SYNOPSIS%^RESET%^

tell %^ORANGE%^%^ULINE%^PLAYER%^RESET%^ %^ORANGE%^%^ULINE%^MESSAGE%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

In telepathic communication you will be able to use %^ORANGE%^<tell>%^RESET%^ to privately tell someone something.

%^CYAN%^SEE ALSO%^RESET%^

reply, say, emote, yell, mail, communication
");
}
