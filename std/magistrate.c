#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit NPC;

mapping targ, rce;

void create(){
    ::create();
    targ = ([]);
    rce = ([]);

}

void init(){
    ::init();
    add_action("wiz_assign", "assign");
    add_action("wiz_unassign", "unassign");
    add_action("wiz_deny", "deny");

    add_action("juror_vote", "vote");

    add_action("request_law", "request");
    add_action("answer_request", "answer");
    add_action("request_appeal", "appeal");

    add_action("list_requests", "view");
    add_action("instructions", "read");

    add_action("bribe_me", "bribe");
}

//Jury tampering
int wiz_assign(string str){
    string juror, cse;

    if(!avatarp(TP))
        return 0;
    if(!str)
        return notify_fail("Incorrect syntax.\n");
    if(sscanf(str, "%s to case %s", juror, cse) != 2)
        return notify_fail("Syntax: assign <juror> to case <case name>\n");

    if(!LAWBOUNTY_D->case_exists(cse))
        return notify_fail("That case does not exist.\n");
    if(!LAWBOUNTY_D->assign_juror(juror, cse))
        return notify_fail("Unable to assign juror.  Check case name and syntax.\n");

    tell_object(TP, "Juror assigned.  Automated mail is NOT sent when assigned this way.");
    return 1;
}

int wiz_unassign(string str){
    string juror, cse;

    if(!avatarp(TP))
        return 0;
    if(!str)
        return notify_fail("Incorrect syntax.\n");
    if(sscanf(str, "%s from case %s", juror, cse) != 2)
        return notify_fail("Syntax: unassign <juror> from case <case name>\n");

    if(!LAWBOUNTY_D->case_exists(cse))
        return notify_fail("That case does not exist.\n");
    if(!LAWBOUNTY_D->unassign_juror(juror, cse))
        return notify_fail("Unable to assign juror.  Check case name and syntax.\n");

    tell_object(TP, "Juror assigned.  Juror is NOT informed automatically.");
    return 1;
}

//This will allow a wiz/avatar to simply kill a bounty request.
int wiz_deny(string str){
    string cse;

    if(!avatarp(TP))
        return 0;
    if(!str)
        return notify_fail("Incorrect syntax.\n");
    if(sscanf(str, "case %s", cse) != 1)
        return notify_fail("Syntax: deny case <case name>\n");

    cse = lower_case(cse);
    if(!LAWBOUNTY_D->case_exists(cse))
        return notify_fail("That case does not exist.\n");
    if(!LAWBOUNTY_D->kill_case(cse))
        return notify_fail("Case not killed.  Either does not exist or there was a problem.\n");

    tell_object(TP, "Case killed.  NO MAILS SENT.");
    return 1;
}

int request_appeal(string str){
    //int new_appeal(string who, string rsn, string rce)
    string who;
    int cost, cha;

    if(str)
        return notify_fail("Just type 'appeal'.  No arguments.\n");

    map_delete(rce, TPQN);
    map_delete(targ, TPQN);

    if(avatarp(TP) && TP->query_disguised())
        who = TP->query_vis_name();
    else
        who = TPQN;

    if(member_array(who, KILLING_D->query_bounties()) == -1)
        return notify_fail("You are not awaiting judgement.\n");

    if(LAWBOUNTY_D->has_appeal(who))
        return notify_fail("That person is already awaiting judgement.\n");

    if(!LAWBOUNTY_D->get_racism_value((string)TP->query_race(), "can_accuse")){
        force_me("say Get out of here, "+capitalize((string)TP->query_race())+", before I call the guard, your kind is not welcome!");
        return 1;
    }

    cost = LAWBOUNTY_D->get_racism_value((string)TP->query_race(), "acc_cost");
    cha = TP->query_stats("charisma");
    if(cha < 8) cost+=50;
    if(cha < 5) cost+=50;
    if(cha > 15) cost-=25;
    if(cha > 18) cost-=25;

    if(!TP->query_funds("gold", cost)){
        force_me("say You don't have enough money to cover the court costs.  You need "+cost+" gold.");
        return 1;
    }

    force_me("say Well, it'll cost you...  Thanks!");
    TP->use_funds("gold", cost);
    TP->force_me("save");

    force_me("say Okay buddy, lets get your story one last time, and don't forget the names!!");

    rce[TPQN] = TP->query_race();
    rm(DIR_TMP+"/"+TP->query_name()+".law");
    TP->edit(DIR_TMP+"/"+TP->query_name()+".law", "end_appeal_edit", this_object());

    return 1;
}

void end_appeal_edit(){
    string reason, requester;

    if(avatarp(TP) && TP->query_disguised())
        requester = TP->query_vis_name();
    else
        requester = TPQN;

    reason = replace_string(read_file(DIR_TMP+"/"+TP->query_name()+".law"), "\n", " ");
    rm(DIR_TMP+"/"+TP->query_name()+".law");
    LAWBOUNTY_D->new_appeal(requester, reason, rce[requester]);
    tell_object(TP, "Your appeal has been entered.");
    map_delete(rce, TPQN);
    map_delete(targ, TPQN);
    return;
}

//Code to request a new bounty
int request_law(string str){
    string who, res, alias;
    int cost;

    map_delete(rce, TPQN);
    map_delete(targ, TPQN);

    if(!str)
        return notify_fail("Incorrect syntax.\n");

    if(sscanf(str, "bounty on %s", alias) != 1)
        return notify_fail("request bounty on <name>\n");

    alias = lower_case(alias);
    who = TP->realName(alias);
        if(!stringp(who) || who == ""){
//
        write("It is impossible to issue a bounty on someone you can't even recognize!");
        return 1;
    }
    if(LAWBOUNTY_D->has_bounty(who))
        return notify_fail("That person is already awaiting judgement.\n");

    //Check to see if the magistrate will acknowledge the existance of this player's race.
    if(!LAWBOUNTY_D->get_racism_value((string)TP->query_race(), "can_accuse")){
        force_me("say Get out of here, "+capitalize((string)TP->query_race())+", before I call the guard, SCUM!!");
        return 1;
    }

    //Take their money.
    cost = LAWBOUNTY_D->get_racism_value((string)TP->query_race(), "acc_cost");
    if(!TP->query_funds("gold", cost)){
        force_me("say You don't have enough money to cover the court costs.  You need "+cost+" gold.");
        return 1;
    }
    force_me("say thanks for the donation!");
    TP->use_funds("gold", cost);
    TP->force_me("save");

    tell_object(TP, "Enter the reason for your bounty.");

    targ[TPQN] = who;
    rce[TPQN] = TP->query_race();
    rm(DIR_TMP+"/"+TP->query_name()+".law");
    TP->edit(DIR_TMP+"/"+TP->query_name()+".law", "end_request_edit", this_object(),alias);
    return 1;
}

void end_request_edit(string alias){
    string reason, requester;

    if(avatarp(TP) && TP->query_disguised())
        requester = TP->query_vis_name();
    else
        requester = TPQN;
    reason = replace_string(read_file(DIR_TMP+"/"+TP->query_name()+".law"), "\n", " ");
    rm(DIR_TMP+"/"+TP->query_name()+".law");
    LAWBOUNTY_D->new_request(targ[TPQN], requester, reason, rce[TPQN], alias);
    tell_object(TP, "You have requested a bounty on "+capitalize(TP->knownAs(targ[TPQN]))+".");
    map_delete(rce, TPQN);
    map_delete(targ, TPQN);
    return;
}



//Code to reply to an accuzation.
int answer_request(string str){
    map_delete(rce, TPQN);
    if(!LAWBOUNTY_D->case_exists(TPQN))
        return notify_fail("There is no requested bounty on your head.\n");

    if(LAWBOUNTY_D->is_appeal(TPQN))
        return notify_fail("Uhh, you can't reply to an appeal.\n");

    tell_object(TP, "Enter your reply to the accuzation.");
    rce[TPQN] = TP->query_race();
    rm(DIR_TMP+"/"+TP->query_name()+".law");
    TP->edit(DIR_TMP+"/"+TP->query_name()+".law", "end_answer_edit", this_object());
    return 1;
}

void end_answer_edit(){
    string reason;

    reason = replace_string(read_file(DIR_TMP+"/"+TP->query_name()+".law"), "\n", " ");
    rm(DIR_TMP+"/"+TP->query_name()+".law");
    if(!LAWBOUNTY_D->answer_request(TPQN, reason, rce[TPQN]))
        return notify_fail("error answering request.  Contact a wiz.\n");
    tell_object(TP, "You have replied to the call for a bounty on your head.");
    map_delete(rce, TPQN);
    return;
}

//And now the jurors get to vote.
int juror_vote(string str){
    string vote, cse;

    if(!str)
        return notify_fail("Be more specific.\n");
    if(sscanf(str, "%s on case %s", vote, cse) != 2)
        return notify_fail("Syntax: vote <yes/no/alive> on case <case name>\n");

    cse = lower_case(cse);
    if(vote != "yes" && vote != "no" && vote != "alive")
        return notify_fail("You can only vote yes, no, or alive.\n");
    if(!LAWBOUNTY_D->case_exists(cse))
        return notify_fail("That case does not exist.\n");
    if(!LAWBOUNTY_D->case_juror(cse, TPQN))
        return notify_fail("You are not a juror on this case.\n");

    if(!avatarp(TP)){
        if(!LAWBOUNTY_D->cast_vote(TPQN, cse, vote))
            return notify_fail("There has been a problem casting your vote.\n");
    } else {
        if(!LAWBOUNTY_D->secret_vote(TPQN, cse, vote))
            return notify_fail("Your secret vote was NOT cast.\n");
    }
    tell_object(TP, "Your vote has been cast!");
    return 1;
}

string display_request(string nme){
    string blah, *key, alias;
    mapping info;
    int i, tme;

    blah = "";
    info = ((mapping)LAWBOUNTY_D->query_all())[nme];
    alias = info["alias"];
    alias = alias?alias:nme;
    tme = ((mapping)LAWBOUNTY_D->query_dates())[nme];
    blah += "%^BLUE%^%^BOLD%^The request against "+capitalize(alias)+" has been presented by "+capitalize(info["request"])+" on "+ctime(tme)+"\n";
    blah += "%^YELLOW%^The reason given is%^RESET%^:\n"+info["reason"]+"\n";

    if(info["reply"] != "")
        blah += "\n%^YELLOW%^The reply to the reason is%^RESET%^:\n"+info["reply"]+"\n";
    else
        blah += "%^BOLD%^%^RED%^There is no reply to the accusation yet.%^RESET%^\n";

    if(sizeof(keys(info["votes"]))){
        blah += "%^BOLD%^%^CYAN%^The jury members are%^RESET%^:  ";
        for(i=0, key = keys(info["votes"]);i<sizeof(key);i++){
            blah += capitalize(key[i])+" ";
        }
    }

    return blah;
}

string display_appeal_request(string nme){
    string blah, *key;
    mapping info;
    int i, tme;

    blah = "";
    info = ((mapping)LAWBOUNTY_D->query_all())[nme];
    tme = ((mapping)LAWBOUNTY_D->query_dates())[nme];
    blah += "%^BLUE%^%^BOLD%^The appeal by "+capitalize(nme)+" has been presented on "+ctime(tme)+"\n";
    blah += "%^YELLOW%^The reason given is%^RESET%^:\n"+info["reply"]+"\n";

    blah += "%^BOLD%^%^CYAN%^The jury members are%^RESET%^:  ";
    for(i=0, key = keys(info["votes"]);i<sizeof(key);i++){
        blah += capitalize(key[i])+" ";
    }

    return blah;
}

int list_requests(string str){
    mapping bo, da;
    string *ke, blah, name, type;
    int i;

    if(!str)
        return notify_fail("What?\n");


    if(str != "board"){
        if(sscanf(str, "%s on %s", type, name) != 2)
            return notify_fail("That is not here.\n");

        if(type != "appeal" && type != "bounty")
            return notify_fail("view what?\n");

        name = lower_case(name);
        name = LAWBOUNTY_D->name_by_alias(name);
        if(!LAWBOUNTY_D->case_exists(name)){
            tell_object(TP, "That person does not have anything pending.");
            return 1;
        } else {
            if(type == "appeal" && !LAWBOUNTY_D->is_appeal(name))
                return notify_fail("That person is not appealing.\n");
            if(type == "bounty" && LAWBOUNTY_D->is_appeal(name))
                return notify_fail("You want to 'view appeal on <name>\n");
        }

        if(LAWBOUNTY_D->is_appeal(name))
            TP->more(explode(display_appeal_request(name), "\n"));
        else
            TP->more(explode(display_request(name), "\n"));

        return 1;

    } else {
        bo = LAWBOUNTY_D->query_all();
        da = LAWBOUNTY_D->query_dates();
        ke = keys(bo);

        blah = "";
        for(i = 0;i<sizeof(ke);i++){
            if(!LAWBOUNTY_D->is_appeal(ke[i])){
//write("blah = "+ke[i]);
// Taking out the blah.
// Garrett.
                blah += "%^BOLD%^%^YELLOW%^"+capitalize((bo[ke[i]]["alias"]?bo[ke[i]]["alias"]:ke[i]));
                blah += ", described as "+USERCALL->user_call(ke[i], "getWholeDescriptivePhrase");
                blah += ", was accused by "+capitalize(bo[ke[i]]["request"]);
                blah += " on "+ctime(da[ke[i]])+"\n";
            } else {
                blah += "%^BOLD%^%^YELLOW%^"+capitalize(ke[i]);
                blah += " requested a review of his case";
                blah += " on "+ctime(da[ke[i]])+"\n";
            }
        }
        tell_object(TP, "These are the outstanding bounties in Shadow as\n  of %^RESET%^"+ctime(time())+".");
        TP->more(explode(blah, "\n"));
    }
    return 1;
}

int instructions(string str){
    if(!str || str != "sign")
        return notify_fail("read what?\n");

    tell_object(TP, "Using the Jury System.  A case is named by the ACCUSED PERSON.\n");
    if(avatarp(TP)){
        tell_object(TP, "These are your commands:\n");
        tell_object(TP, "assign <juror> to case <case name>:  assigns juror to specified case.");
        tell_object(TP, "unassign <juror> from case <case name>:  removes juror from specified case.");
        tell_object(TP, "deny case <case name>:  Deletes case.  simple.  Final.");
    }
    tell_object(TP, "\n\nThese are the player commands:");
    tell_object(TP, "request bounty on <name>:  Post a request for a bounty on named person");
    tell_object(TP, "appeal:  Requests that your case be reviewed again.");
    tell_object(TP, "answer:  reply to a bounty request against you");
    tell_object(TP, "  Enter info for both in the mail-like format.");
    tell_object(TP, "vote <yes/no/alive> on case <case name>:  If you are a juror, this is what you use to vote.  You still vote if they have not replied to the accuzation.  If they don't reply, they have no refute to it.  A vote of 'yes' is a vote for death.  A vote of 'alive' is a vote for jail time.");
    tell_object(TP, "  votes on appeals are different.  vote 'yes' to overturn the conviction and make them a free person.  vote no if the bounty is to stand.");
    tell_object(TP, "  An appeal cannot change a dead bounty to a jail time bounty.");
    tell_object(TP, "view board: To see all the bounties and appeals");
    tell_object(TP, "view bounty on <case name>: to view the specifics on a case");
    tell_object(TP, "view appeal on <case name>: to view the specifics on an appeal");

    return 1;
}

int bribe_me(string str){
    int amt, cost, cha;
    string type;
    string *types;

    types = ({"gold", "platinum", "silver", "electrum", "copper"});

    if(!str)
        return 0;
    if(sscanf(str, "magistrate with %d %s", amt, type) != 2)
        return notify_fail("Bribe magistrate with what?\n");
    if(member_array(type, types) == -1)
        return notify_fail("That only works with real money.\n");

    if(!LAWBOUNTY_D->case_exists(TPQN))
        return notify_fail("Uhhhh, you don't have a bounty request against you.\n");
    //check the status, make sure that jurors haven't already been selected
    if(LAWBOUNTY_D->has_jurors(TPQN))
        return notify_fail("Sorry buddy, its too late.  There's already a jury.\n");

    if(!LAWBOUNTY_D->can_be_bribed(TP)) {
        force_me("say You dare try bribe me??!!");
        force_me("say I declare you OUTLAW!!!");
        LAWBOUNTY_D->guilty(TPQN, "dead");
        return 1;
    }

    if(type != "gold"){
        force_me("whisper "+TPQN+" Work with me, grace my palm with a real coin, gold.");
        return 1;
    }

    if(!TP->query_funds("gold", amt)){
        force_me("say You don't even have that much!");
        force_me("say You try to fool me?!?!  I DECLARE THEE OUTLAW!!");
        LAWBOUNTY_D->guilty(TPQN, "dead");
        return 1;
    }

    //This should get us a random value close to the main one, hopefully
    cost = LAWBOUNTY_D->get_racism_value((string)TP->query_race(), "bribe_cost");
    cost = 5000 + random(cost);

    cha = TP->query_stats("charisma");
    if(cha < 8) cost+=2000;
    if(cha < 5) cost+=2000;
    if(cha > 15) cost-=1000;
    if(cha > 18) cost-=1000;

    /*
    if(random(3)) {
        cost += to_int(cost * (random(10)+1)/5.0);
    } else {
        cost -= to_int(cost * (random(6)+1)/3.0);
    }
    */

    if(amt < cost){
        if(amt < cost/2){
            force_me("say You dare attempt bribe me!!");
            force_me("yell GUARDS!  COME QUICK!  We have an outlaw in my office!!");
            LAWBOUNTY_D->guilty(TPQN, "dead");
            return 1;
        } else {
            force_me("whisper "+TPQN+" come my friend, you can do better than that.");
            return 1;
        }
    } else {
        force_me("whisper "+TPQN+" ahh, this shall do nicely.");
        TP->use_funds("gold", amt);
        TP->force_me("save");
        LAWBOUNTY_D->kill_case(TPQN);

        return 1;
    }

}


// Several functions need to be expanded for appeals here.
