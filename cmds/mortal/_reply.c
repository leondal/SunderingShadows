#include <std.h>
#include <daemons.h>
#include <udp.h>
#include <tell.h>

inherit DAEMON;

int cmd_reply(string str)
{
    string reply, a, b;
    int quiet, invis;
    string *ignored, *caster_correspond, *targ_correspond;
    string msg = str;
    object ob;

    reply = (string)this_player()->query("reply");

    if (!objectp(ob = TP->query("reply object")))
    {
        if(!reply)
        reply = "no one";
    }
    else
    {
        if(wizardp(TP))
	        reply = ob->query_true_name();
        else
	        reply = ob->getParsableName();
    }

    if (reply == "no one")
    {
        notify_fail("No current reply addressee.\n");
        return 0;
    }

    if(!objectp(ob)) { ob = find_player(TP->realNameVsProfile(reply)); }

    if(!ob && (sscanf(reply, "%s@%s", a, b) != 2))
    {
        write(reply+" is not currently in our reality.\n");
        return 1;
    }

    if(ob->query_blocked("reply") && !avatarp(TP))
    {
        notify_fail(reply+" is now blocking all tells.\n");
        return 0;
    }

    if(!avatarp(TP) && !avatarp(ob) && !(pointerp(TP->query_property("allowed tell")) && member_array(ob->query_true_name(),(string *)TP->query_property("allowed tell")) != -1))
    {
        return 0;
    }

    if(objectp(ob)) { quiet = (int) ob->query_quietness(); }

    if ( quiet && !wizardp(TP) && wizardp(ob) )
    {
        if ( (int)ob->query_invis() )
        {
            notify_fail("You have to give a replyee !\n");
        }
        else
        {
            notify_fail(ob->query_cap_name()+" doesn't accept your replies at the moment!\n");
        }
        return 0;
    }

    if(!str)
    {
        write("Current reply addressee: "+reply+"\n");
        return 1;
    }

    if(!interactive(ob) && userp(ob))
    {
        notify_fail(ob->getParsableName()+" is link-dead and cannot hear you.\n");
        return 0;
    }

    ignored = ob->query_ignored();

    if(!ignored)
    {
        TP->reset_ignored();
        ignored = TP->query_ignored();
    }

    if (ob->query_property("corresponding") || TP->query_property("corresponding")) {
        caster_correspond = TP->query_property("corresponding");
        targ_correspond = ob->query_property("corresponding");
        if (!caster_correspond) {
            caster_correspond = ({});
        }
        if (!targ_correspond) {
            targ_correspond = ({});
        }
        if (member_array(ob->query_name(), caster_correspond) != -1 && member_array(TP->query_name(), targ_correspond) != -1) {
        }
    }

    if ((member_array(TPQN, ignored) != -1) && !wizardp(TP)) {
        write(reply + " is ignoring you.");
        return 1;
    }

    if (wizardp(ob) || wizardp(TP)) {
        message("reply", "%^BOLD%^%^RED%^" + capitalize(TPQN) + " replies: %^RESET%^" + str, ob);
    } else {
        message("reply", "%^BOLD%^%^RED%^" + TP->getParsableName() + " replies: %^RESET%^" + str, ob);
    }

    if (TP->query_blocked("reply")) {
        TP->set_blocked("reply");
    }

    if (wizardp(TP)) {
            message("reply", "%^BOLD%^%^RED%^You reply to " + capitalize(ob->query_name()) + ":%^RESET%^ " + str, TP);
    }else {
        if (avatarp(TP)) {
            message("reply", "%^BOLD%^%^RED%^You reply to " + capitalize(ob->query_name()) + ":%^RESET%^ " + str, TP);
        }else {
            message("reply", "%^BOLD%^%^RED%^You reply to " + reply + ":%^RESET%^ " + str, TP);
        }
    }

    if (!wizardp(ob) && !wizardp(TP) && !ob->query_true_invis() && !TP->query_true_invis()) {
        CHAT_D->force_chat(TP, "telepathy", "tells " + ob->QCN + " " + str + " ", 1);
    }

#include <detect_thoughts.h>

    if(!TP->query_disguised() || !wizardp(TP))
    {
        ob->set("reply", TP->getParsableName());
    }

    else
    {
        ob->set("reply",TP->query_vis_name());
    }

    ob->set("reply object",TP);
    return 1;
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

reply - reply to a tell

%^CYAN%^SYNOPSIS%^RESET%^

reply %^ORANGE%^%^ULINE%^MESSAGE%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

In telepathic communication you'll be able to use this command to reply to the last person that contacted you.

%^CYAN%^SEE ALSO%^RESET%^

tell, say, whisper, communication
");
}
