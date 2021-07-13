//      /bin/daemon/fingerd.c
//      Nightmare Mudlib finger daemon
//      based on finger daemon from the TMI mudlib coded by
//      Sulam, Jubal, Brian, and Buddha (12.8.91 - 3.8.92)
//      written by Descartes of Borg 22 November 1992
//  removed marriage info. and did a little other security cleanup *Styx* 11/25/06

#include <objects.h>
#include <dirs.h>
#include <daemons.h>
#include <conf.h>
#include <clock.h>
#include <std.h>
#define AVA_D "/daemon/avatar_d.c"
#define SGUILDS ({"Watcher"})

inherit OB_USER;
string true_name;
string myclass;

void create() {
    seteuid(getuid());
}

string general_finger_display() {
    string finger;
    object *who;
    int i;
    string level;

    finger = " %^BOLD%^%^CYAN%^                 Members of the "+mud_name()+" Reality\n";
    finger += "   %^CYAN%^"+mud_name()+" has been up since PDT "+ctime(time()-uptime())+"\n";
    finger += "   %^CYAN%^"+mud_name()+" runs "+version()+" driver with "+mudlib()+"\n";
    finger += "%^YELLOW%^"+alig_str("Player", 15);
    finger += "%^BOLD%^%^CYAN%^"+alig_str("Real Name", 30);
    finger += "%^BOLD%^%^MAGENTA%^"+alig_str("Idle", 5);
    finger += "\n";
    finger += "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    who = users();
    for (i=0; i<sizeof(who); i++) {
        if (who[i]->query_quietness() && wizardp(who[i])) continue;
        if (!who[i]->query_name()) continue;
        if (avatarp(who[i]) && ((string)who[i]->query_vis_name() != (string)who[i]->query_name())) {
            finger += "%^YELLOW%^"+alig_str(capitalize((string)who[i]->query_vis_name()), 15);
            finger += "%^BOLD%^%^CYAN%^"+alig_str("Unknown", 30);
            finger += "%^BOLD%^%^MAGENTA%^"+alig_str(parse_time(query_idle(who[i])), 8);
            finger += "\n";
        } else {
            finger += "%^YELLOW%^"+alig_str(capitalize((string)who[i]->query_name()), 15);
            finger += "%^BOLD%^%^CYAN%^"+alig_str((string)who[i]->query_rname(), 30);
            finger += "%^BOLD%^%^MAGENTA%^"+alig_str(parse_time(query_idle(who[i])), 8);
            finger += "\n";
        }
    }
    finger += "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    return finger;
}



string user_finger_display(string who) {
    mapping mail_stat;
    string tmp;
    string pos;
    object ob;
    object desc;
    string uh_oh;
    string finger, position;
    string level, *tmp9;
    int invis, quiet, castwiz, obwiz, gi;
    int birth2;

    if (!who) return "You must specify whom you wish to finger.\n";
    true_name = lower_case(who);
    ob = find_player(lower_case(who));
    tmp = true_name;
    who = sprintf("%s/%s/%s", DIR_USERS, tmp[0..0], tmp);
    if (file_size(who + ".o") < 0)
        return "No such member of Sundering Shadows.\n";
    restore_object(who);
    desc = new(DESC_D);
    desc->restore_profile_settings(TO,"default");
    desc->initialize_profile(TO);
    mail_stat = (mapping)LOCALPOST_D->mail_status(tmp);
    if (ob) {
        finger = "Name: " + query_true_name() + "\n";
        if (file_exists("/d/save/background/" + query_true_name() + ".htm")) {
            finger += "Background on file.\n";
        }else {
            finger += "No background on file.\n";
        }
        if (pointerp(tmp9 = (string*)ob->query_shguild()) && sizeof(tmp9)) {
            finger += "Member of:\n";
            for (gi = 0; gi < sizeof(tmp9); gi++) {
                finger += "  " + tmp9[gi] + "\n";
            }
        }
        position = ob->query_position();
        if (wizardp(ob)) {
            switch (position) {
            case "apprentice":
                level = "Apprentice"; break;
            case "creator":
                level = "Creator"; break;
            case "Admin":
                level = "Game Admin"; break;
            default:
                level = "Immortal"; break;
            }
        }
        if (!wizardp(ob)) {
            level = "" + (int)ob->query_level() + "";
        }
        if (wizardp(ob)) {
            finger += "Position: " + level;
        }
        finger += "\n";
        if (avatarp(TP)) {
            if (!ob->query_married()) {
                finger += "Single\n";
            }else {
                finger += "Married to " + capitalize((string)ob->query_married()) + "\n";
            }
        }
        birth = (int)ob->query_birthday();
        birth2 = birth - (int)ob->query_start_age() * YEAR;
        invis = (int)ob->query_invis();
        quiet = (int)ob->query_quietness();
        castwiz = wizardp(this_player());
        obwiz= wizardp(ob);

        finger += "Last on: ";
        finger += query_last_on() + "\n";

        if (!mail_stat["unread"]) {
            finger += "No unread mail.\n";
        }else if (mail_stat["unread"] == 1) {
            finger += "1 unread piece of mail.\n";
        }else {
            finger += mail_stat["unread"] + " unread pieces of mail.\n";
        }
        if (wizardp(ob)) {
            tmp = user_path(tmp);
            if (file_size(tmp + ".project") >= 0) {
                finger += "Project: " + read_file(tmp + ".project");
            }
            if (file_size(tmp + ".plan") >= 0) {
                finger += "Plan:\n" + read_file(tmp + ".plan");
            }else {
                finger += "No plan.\n";
            }
        }
    } else {
        complete_variables();
        finger = query_title()+ "\n";
        if (get_perma_death() > 0 && get_perma_death() > time()){
            finger += "%^BOLD%^%^YELLOW%^DECEASED%^RESET%^\n";
        }
        if (file_exists("/d/save/background/"+query_true_name()+".htm"))
            finger += "Background on file.\n";
        else
            finger += "No background on file.\n";
        if(pointerp(tmp9 = query_shguild()) && sizeof(tmp9)){
            finger += "Member of:\n";
            for(gi=0;gi<sizeof(tmp9);gi++){
                finger += "  " + tmp9[gi] + "\n";
            }
        }
        if (member_array(query_position(), MORTAL_POSITIONS)==-1) {
            position = query_position();
            switch (position) {
            case "apprentice":
                level = "Apprentice"; break;
            case "creator":
                level = "Creator"; break;
            case "elder":
                level = "Elder";break;
            case "overseer":
                level = "Overseer";break;
            case "arch":
                level = "Arch";break;
            case "Admin":
                level = "Silly"; break;
            default:
                level = "Wizard"; break;
            }
            finger += "Position: "+level+"\n";   // 1 nov 93 for offline
        } else finger += "Position: Unknown\n";
        //finger += "In real life: ";
        //finger += alig_str(query_rname(), 31);
// making marriage info. avatar only *Styx* 11/25/06
        if(avatarp(TP)) {
          if (query_married())
            finger += "Married to "+capitalize(query_married())+"\n";
          else
            finger += "Single\n";
	}
        birth = query_birthday();
        birth2 = birth - query_start_age()*YEAR;
        /* finger += "Birthday: "+date(birth)+" "+capitalize(month(birth))+", "+year(birth2)+" SG\n"; */
        /* if (this_player() && archp(this_player())) */
        /*     if ((uh_oh = query_email()) != "") */
        /*         finger += "Email: " + uh_oh + "\n"; */
        if (this_player() && archp(this_player()))
            finger += "Last on: " + query_last_on() + "\n";
        else finger += "Last on: "+query_last_on()+"\n";
        // "from "+
	// (query_property("where block") ? "Anonymous" : query_ip())+"\n";
        // ((1) ? "Anonymous" : query_ip())+"\n";
        //finger += query_cap_name() + " has ";
        if (!mail_stat["unread"])
            finger += "No unread mail.\n";
        else if (mail_stat["unread"] == 1)
            finger += "1 unread piece of mail.\n";
        else
            finger += mail_stat["unread"]+" unread pieces of mail.\n";
//        if(wizardp(ob)) {
        if((member_array(query_position(), MORTAL_POSITIONS)==-1) || wizardp(ob)) {
          tmp = user_path(tmp);
          if (file_size(tmp+".project") >= 0)
            finger += "Project: "+read_file(tmp+".project");
          if (file_size(tmp+".plan") >= 0)
            finger += "Plan:\n" + read_file(tmp + ".plan");
          else
            finger += "No plan.\n";
        }
    }
    if(query("ooc contact"))
    {
        finger += query("ooc contact");
    }
    return finger;
}


string query_last_on() {
    if (!query_invis()) return real_last_on;
    return last_on;
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

string query_cap_name() {
    return capitalize(query_true_name());
}

void restore_player_file(string file) {
    restore_object(file);
}

void save_player(string file) {
    save_object(file);
}

protected void complete_variables() {
    if (!true_name) {
        true_name = "";
    }
    if (!real_name) {
        real_name = "???";
    }
    if (!myclass) {
        myclass = "child";
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
    if (!player_age) {
        player_age = 0;
    }
}
