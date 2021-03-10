//  Con command give you the monsters hp percentage
//  Created by Grayhawk@ShadowGate
//  June 16, 1995
//  Updated by Firedragon@ShadowGate
//  October 8, 1995
//  Changed to show general description instead of % for better RP feel.
//  Used the long describe info. from /std/living and added for negatives & above 100
//  *Styx*  11/26/02

#include <std.h>
#include <daemons.h>

#pragma strict_types

inherit DAEMON;

int lightblind;

int cmd_con(string str)
{
    object ob;
    int i, x, y, z = 0;
    string sub, check, pre;
    string output = "";

    if (TP->query_blind()) {
        return notify_fail("You are blind you can't inspect your opponents condition.\n");
    }

    if (str == "party" || str == "all") {
        string partyname = "";
        object * theparty = ({}), * presentparty = ({});

        partyname += (string)TP->query_party();

        if (partyname != "") {
            theparty = PARTY_D->query_party_members(partyname);
            if (sizeof(theparty)) {
                presentparty = filter_array(theparty, (: environment($1) == $2:), ETP);
            }
        } else {
            presentparty = ({ TP });
        }

        if (sizeof(presentparty)) {
            output += "%^BOLD%^Present party:\n";
            for (i = 0; i < sizeof(presentparty); i++) {
                output += "%^BOLD%^%^RED%^" + sprintf("%2d", i + 1) + ":%^RESET%^ " + obj_cond(presentparty[i]) + "\n";
            }
        }
        z = 1;
    }

    if (!str || regexp(str, "[0-9]+") || str == "all") {
        object* attackers = TP->query_attackers();
        int param;

        param = atoi(str);

        if (!param || param > sizeof(attackers)) {
            param = sizeof(attackers);
        }

        if (sizeof(attackers)) {
            output += "%^BOLD%^%^WHITE%^Attackers (" + param + " of " + sizeof(attackers) + "):\n";
            for (i = 0; i < sizeof(attackers) && i < param; ++i) {
                if (objectp(attackers[i])) {
                    output += "%^BOLD%^%^RED%^" + sprintf("%2d", i + 1) + ":%^RESET%^ " + obj_cond(attackers[i]) + "\n";
                }
            }
        }
        z = 1;
    }

    if (z) {
        if (output != "") {
            write(output);
        } else {
            write("%^BOLD%^%^WHITE%^Nothing to report.");
        }
        return 1;
    }

    if (lightblind = TP->light_blind(0)) {
        return notify_fail(TP->light_blind_fail_message(lightblind) + "\n");
    }

    //added by Circe 1/8/05 in response to bug reports that you could con while you couldn't see

    if ((ob = present(lower_case(str), ETP)) || (ob = present(capitalize(str), ETP))) {
        if (environment(ob) != ETP) {
            write("Couldn't find \"" + str + "\" here.");
            return 1;
        }

        if (!avatarp(TP) && (int)ob->query_invis() == 1 && ob != TP) {
            write("Couldn't find \"" + str + "\" here.");
            return 1;
        }

        if (ob->query_invis() || ob == TP) {
            if (!TP->detecting_invis() && ob != TP) {
                write("Couldn't find \"" + str + "\" here.");
                return 1;
            }
        }

        if (ob->is_monster() || ob->is_player()) {
            write(obj_cond(ob));
            return 1;
        }
    }

    write("Couldn't find \""+ str +"\" here.");
    return 1;
}

string obj_cond(object ob)
{
    int x;
    string sub, pre, check;

    sub = ob->query_cap_name();
    pre = "%^RED%^"+sub+" is unconscious";
    x = ((ob->query_hp() * 100) / (ob->query_max_hp() + 1));

    if (x > 100) {
        check = "%^BOLD%^%^GREEN%^" + sub + " looks unusually healthy.";
    }else if (x > 90) {
        check = "%^YELLOW%^" + sub + " is in top shape.";
    }else if (x > 75) {
        check = "%^WHITE%^%^BOLD%^" + sub + " is in decent shape.";
    }else if (x > 60) {
        check = "%^WHITE%^" + sub + " is slightly injured.";
    }else if (x > 45) {
        check = "%^MAGENTA%^" + sub + " is hurting.";
    }else if (x > 30) {
        check = "%^ORANGE%^" + sub + " is badly injured.";
    }else if (x > 15) {
        check = "%^RED%^%^BOLD%^" + sub + " is terribly injured.";
    }else if (x > -1) {
        check = "%^RED%^" + sub + " is near death.";
    }else if (ob->is_monster()) {
        if (x > -10) {
            check = pre + " and probably should be dead.";
        }else if (x > -200) {
            check = pre + " and should be dying from horrible wounds.";
        }else {
            check = pre + " and at " + x + "%. Gross.";
        }
        return check;
        return 1;
    }else if (x > -20) {
        check = pre + " from numerous wounds.";
    }else if (x > -50) {
        check = pre + " from serious wounds.";
    }else if (x > -100) {
        check = pre + " and bleeding from critical wounds.";
    }else if (x > -150) {
        check = pre + " and bleeding profusely from grievous wounds.";
    }else if (x > -180) {
        check = pre + " and dying from horrific wounds.";
    }else if (x > -202) {
        check = pre + " from imminently fatal wounds.";
    }else {
        check = pre + " and at " + x + "%. Gross.";
    }

    return check;

}


void help()
{
    write("
%^CYAN%^NAME%^RESET%^

con - check out condition of a being

%^CYAN%^SYNOPSIS%^RESET%^

con [%^ORANGE%^%^ULINE%^BEING%^RESET%^|party|all]

%^CYAN%^DESCRIPTION%^RESET%^

This command will give you a general indication of a monster or PC's health, or lack thereof in human readable form.

Use %^ORANGE%^<con party>%^RESET%^ to check your allies.

Without an argument it will give you condition of all attackers and party members.

To see both allies and attackers use %^ORANGE%^<con all>%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

hp, score

");
}
