//      /bin/daemon/fingerd.c
//      Nightmare Mudlib finger daemon
//      based on finger daemon from the TMI mudlib coded by
//      Sulam, Jubal, Brian, and Buddha (12.8.91 - 3.8.92)
//      written by Descartes of Borg 22 November 1992

#include <objects.h>
#include <dirs.h>
#include <daemons.h>
#include <config.h>
#include <clock.h>
#define AVA_D "/daemon/avatar_d.c"

inherit OB_USER;

string true_name, *classes;

string alig_str(string what, int x);
// string query_title();
string query_fi_last_on(object plob);
string query_hah(object ob, int verbose);

void create() {
    seteuid(getuid());
}

protected void complete_variables()
{
    if (!true_name) {
        true_name = "";
    }
    if (!real_name) {
        real_name = "???";
    }
    if (!classes) {
        classes = ({ "child" });
    }
    if (!last_on) {
        last_on = "no record";
    }
    if (!ip) {
        ip = "nowhere";
    }
    if (!level) {
        level = -1;
    }
    if (!query("race")) {
        set("race", "Unborn");
    }
    if (!player_age) {
        player_age = 0;
    }
}

string avatar_finger_display(string who) {
    mapping mail_stat;
    string tmp;
    string pos;   /* caller's position used to show email for high level
                                callers.  Added by Valodin, June 8, 1993 */
    object ob;
    string uh_oh;
    string finger, position;
    string level, *tmp9;
    int invis, quiet, castwiz, obwiz, gi;
    int birth2;

    if (!who) return "You must specify whom you wish to finger.\n";

    true_name = lower_case(who);
    ob = find_player(lower_case(who));

    if (ob) {
        finger =""+ob->query_short()+"\n";
        if (file_exists("/avatar/"+ob->query_name()+"/"+ob->query_vis_name()+".htm"))
            finger += "Background on file.\n";
        else
            finger += "No background on file.\n";
        if (pointerp(tmp9 = (string *)ob->query_shguild()) && sizeof(tmp9)) {
            finger += "Member of:\n";
            for (gi=0;gi<sizeof(tmp9);gi++) {
                finger += "  " + tmp9[gi] + "\n";
            }
        }
        uh_oh = capitalize((string)ob->query_gender()) + " ";
        uh_oh += (string)ob->query("race") + " ";
        finger += alig_str(uh_oh, 45);
        position = ob->query_position();

        if (wizardp(ob) && !ob->query_disguised()) {
            switch (position) {
            case "apprentice":
                level = "Apprentice"; break;
            case "creator":
                level = "Creator"; break;
            case "developer":
                level = "Developer"; break;
            case "Developer":
                level = "Developer"; break;
            case "overseer":
                level = "Overseer"; break;
            case "Overseer":
                level = "Overseer"; break;
            case "elder":
                level = "Elder (Admin)"; break;
            case "arch":
                level = "Arch (Admin)"; break;
            case "god":
                level = "GOD (Admin)"; break;
            default:
                level = "Immortal"; break;
            }
        }

        if (wizardp(ob) && !ob->query_disguised())
            finger += "Level: "+level+"\n";
        else
            finger += "Level: Unknown\n";

        finger += "In real life: ";
        finger += alig_str("Unknown", 31);

        if (!ob->query_married())
            finger += "Single\n";
        else
            finger += "Married to " + capitalize((string)ob->query_married()) + "\n";

        birth = (int)ob->query_birthday();
        birth2 = birth - (int)ob->query_birthday()*YEAR;
        birth -= 123456;
        finger += "Birthday: "+date(birth)+" "+capitalize(month(birth))+", "+year(birth2)+" SG\n";

        if (this_player() && archp(this_player()))
            if ((uh_oh = (string)ob->query_email()) != "")
                finger += "Email: " + uh_oh + "\n";

        invis = (int)ob->query_invis();
        quiet = (int)ob->query_quietness();
        castwiz = wizardp(this_player());
        obwiz= wizardp(ob);

        if ( invis || ( quiet && obwiz && !castwiz ) )
            finger += "Last on: ";
        else {
            uh_oh = query_hah(ob, 1);
            if (uh_oh != "")
                finger += uh_oh + "\n";
            finger += "On since: ";
        }

        finger += query_fi_last_on(ob) + " from: ";
        finger += "Anonymous\n";

        finger += capitalize(ob->query_vis_name()) + " has ";
        finger += "no unread mail.\n";

        finger += "No plan.\n";
    } else
        return "No such member of the Shadow Gate World.\n";
    return finger;
}


string persona_finger_display(string who) {
    mapping mail_stat;
    string tmp, pos, ava, perfile, finger, position, level, *tmp9, uh_oh;
    object ob;
    int x, invis, quiet, castwiz, obwiz, gi;
    int birth2;
  string * temparray;

    if (!who) return "You must specify whom you wish to finger.\n";

    true_name = lower_case(who);
    ava = ((string *)AVA_D->query_avatar_of_persona(true_name))[0];
   temparray = (string *)AVA_D->query_persona_file(ava, true_name);
  if (pointerp(temparray)) {
   perfile = temparray[0];
  } else {
   perfile = "";
  }
    if (!file_exists(perfile))
        return "No such member of the Shadow Gate World.\n";
    x = strlen(perfile);
    perfile = perfile[0..x-3];
    restore_me(perfile);

    complete_variables();


    finger = ""+query_title()+"\n";
    //finger = ""+query_short()+"\n";
    if (file_exists("/avatar/"+query_name()+"/"+query_vis_name()+".htm"))
        finger += "Background on file.\n";
    else
        finger += "No background on file.\n";
    if (pointerp(tmp9 = query_shguild()) && sizeof(tmp9)) {
        finger += "Member of:\n";
        for (gi=0;gi<sizeof(tmp9);gi++) {
            finger += "  " + tmp9[gi] + "\n";
        }
    }
    uh_oh = capitalize(query_gender()) + " ";
    uh_oh += query("race") + " ";

    if (stringp(tmp9=query_guild_string()) && query("show guild"))
        uh_oh += "of the "+tmp9;
    finger += alig_str(uh_oh, 45);

    finger += "Level: Unknown\n";

    finger += "In real life: ";
    finger += alig_str("Unknown", 31);

    if (!query_married())
        finger += "Single\n";
    else
        finger += "Married to " + capitalize(query_married()) + "\n";

    birth = query_birthday();
    birth -= 123456;
    finger += "Birthday: "+date(birth)+" "+capitalize(month(birth))+", "+year(birth)+" SG\n";

    //if (this_player() && archp(this_player()))
    //    if ((uh_oh = query_email()) != "")
    //        finger += "Email: " + uh_oh + "\n";

    finger += "Last on: "+query_last_on()+" from Anonymous\n";

    finger += capitalize(query_vis_name()) + " has ";
    finger += "no unread mail.\n";

    finger += "No plan.\n";


    return finger;
}

string query_hah(object ob, int verbose) {
    int time, tmp;
    string line;

    if (!ob) return 0;
    if (!interactive(ob)) {
        if (verbose) return "Disconnected.";
        else return "disconnected";
    }
    line = "";
    time = query_idle(ob);
    if (time < 60) return line;
    tmp = time / 86400;
    if (tmp) {
        if (!verbose) return tmp + " d";
        else line += tmp + " day" + (tmp>1 ? "s " : " ");
    }
    tmp = (time%86400)/3600;
    if (tmp) {
        if (!verbose) {
            if (tmp>9) return tmp+" h";
            else line += tmp+":";
        } else line += tmp + " hour"+(tmp>1 ? "s " : " ");
    }
    tmp = (time%3600)/60;
    if (tmp) {
        if (!verbose) {
            if (strlen(line)>0 && tmp < 10) line += "0";
            line += tmp;
        } else line += tmp+ " minute"+(tmp>1 ? "s " : " ");
    }
    if (verbose) line += "idle time";
    else line += "idle";
    return line;
}

string query_fi_last_on(object plob) {
    if (!plob->query_invis()) return plob->query_real_last_on();
    return plob->query_last_on();
}

string query_title() {
    string pre, post;

    //if(query("short"))
    //    return query("short");

    if (!getenv("TITLE")) return capitalize(query_vis_name());
    if (sscanf(getenv("TITLE"), "%s $N %s", pre, post) != 2) {
        if (sscanf(getenv("TITLE"), "$N %s", post) != 1) return
            capitalize(query_true_name());
        else return capitalize(query_vis_name())+" "+post;
    }
    return pre+" "+capitalize(query_vis_name())+" "+post;
}


string alig_str(string what, int x) {
    int y;
    string out;

    out = "";
    if (!what) return 0;
    y = strlen(what);
    out += what;
    if (y>x) {
        out = what[0..x-1] + " ";
        return out;

    }
    x = x-y;
    if (x<1) return out;
    for (y=0; y<=x; y++) out += " ";
    return out;
}
