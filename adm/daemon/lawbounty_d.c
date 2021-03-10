#include <std.h>
#include <security.h>
#include <daemons.h>
#include <lawbounty.h>
inherit DAEMON;

mapping bounties, dates;

mapping good, neutral, evil;
string *jgood, *jneut, *jevil;

void RESTORE();
void SAVE();
mapping query_all();
mapping query_dates();
int has_bounty(string nme);
int has_appeal(string cse);
int case_exists(string cse);
int has_jurors(string cse);
int is_appeal(string cse);
int case_juror(string cse, string who);
string *list_appeals();
int new_request(string who, string requester, string rsn, string rce, string alias);
int answer_request(string who, string rsn, string rce);
int new_appeal(string who, string rsn, string rce, string alias);
int assign_juror(string nme, string cse);
int unassign_juror(string nme, string cse);
int kill_case(string cse);
int cast_vote(string who, string cse, string vote);
int secret_vote(string who, string cse, string vote);
int get_racism_value(string rce, string val);
int can_be_bribed(object tp);
void add_hm_info(object who);
void remove_juror(string nme);
void timecheck_juror_lists();
void check_verdict(string who, int flag);
void guilty(string cse, string what);
void not_guilty(string cse);
void appeal_guilty(string cse, string what);
void appeal_not_guilty(string cse);
void log_votes(string cse);
void send_mail(string *to, string msg);
void timecheck_bounties();
void send_accused_mail(string who);
void send_juror_mail(string who);
void send_appeal_mail(string who);
void assign_jurors(string cse);
string select_juror_by_race();
string select_juror_by_alignment();

void run_test(string msg){
    object ob;

    ob = find_player("grendel");
    if(!objectp(ob))
        return;

    tell_object(ob, msg);
}

void create(){
    bounties = ([]);
    dates = ([]);
    good = ([]);
    neutral = ([]);
    evil = ([]);
    jgood = ({});
    jneut = ({});
    jevil = ({});
    RESTORE();
    call_out("timecheck_juror_lists", 300);
    call_out("timecheck_bounties", 200);
}

void RESTORE() {
    seteuid(UID_SECURE_DAEMONSAVE);
    restore_object(SAVE_FILE);
    seteuid(getuid());
}

void SAVE() {
    seteuid(UID_SECURE_DAEMONSAVE);
    save_object(SAVE_FILE);
    seteuid(getuid());
}




mapping query_all(){
    return bounties;
}

mapping query_dates(){
    return dates;
}


//These are the basic functions for the Bounties mapping

//Returns 1 if person has a bounty or is waiting for one.
int has_bounty(string nme){
    if (member_array(nme, KILLING_D->query_bounties()) != -1)
        return 1;
    if (member_array(nme, keys(bounties)) != -1)
        return 1;

    return 0;
}

int has_appeal(string cse){
    if(member_array(cse, keys(bounties)) == -1)
        return 0;
    if(!is_appeal(cse))
        return 0;
    return 1;
}

//returns 1 if the specified bounty case exists
int case_exists(string cse){
    if (member_array(cse, keys(bounties)) == -1)
        return 0;
    return 1;
}

//returns 1 if jurors have been assigned
int has_jurors(string cse){
    if(bounties[cse]["status"] == WAIT_JURORS)
        return 1;
    return 0;
}

int is_appeal(string cse){
    if(bounties[cse]["status"] == APPEAL)
        return 1;
    return 0;
}

//returns 1 if person who is a juror assigned to case cse
int case_juror(string cse, string who){
    if (member_array(who, keys(bounties[cse]["votes"])) != -1)
        return 1;
    return 0;
}

string *list_appeals(){
    string *tmp, *tmp2;
    int i;

    tmp = keys(bounties);
    tmp = ({});

    for(i=0;i<sizeof(tmp);i++){
        if(is_appeal(tmp[i]))
            tmp2 += ({tmp[i]});
    }

    return tmp2;
}

//Adds a request to the daemon.
int new_request(string who, string requester, string rsn, string rce,string alias){
    if (!bounties)
        bounties = ([]);

    dates[who] = time();

    bounties[who] = ([ ]);
    bounties[who]["request"] = requester;
    bounties[who]["reqRace"] = rce;
    bounties[who]["defendRace"] = "";
    bounties[who]["reason"] = rsn;
    bounties[who]["reply"] = "";
    bounties[who]["votes"] = ([ ]);
    bounties[who]["status"] = NO_REPLY;

    bounties[who]["alias"] = alias;
    send_accused_mail(who);
    log_file("bounties","Law bounty requested for "+capitalize(who)+" by "+capitalize(requester)+" on "+ctime(time())+".\n");
    SAVE();
    return 1;
}

string name_by_alias(string alias){
    int i;
    string *stuff = keys(bounties);
    for(i = 0;i<sizeof(stuff);i++){
        if(stuff[i] == alias) {
            return stuff[i];
        }
        if(bounties[stuff[i]]["alias"] == alias) {
            return stuff[i];
        }
    }
    return 0;
}

//This is where the appeal process begins.
int new_appeal(string who, string rsn, string rce, string alias){
    dates[who] = time();

    bounties[who] = ([ ]);
    bounties[who]["status"] = APPEAL;
    bounties[who]["defendRace"] = rce;
    bounties[who]["reply"] = rsn;
    bounties[who]["votes"] = ([ ]);
    bounties[who]["alias"] = alias;
    assign_jurors(who);
    log_file("bounties", "Appeal filed by "+capitalize(who)+" on "+ctime(time())+".\n");
    send_appeal_mail(who);
    SAVE();
    return 1;
}


//Adds the answer to the mapping, assigns jurors, and changes the status
int answer_request(string who, string rsn, string rce){
    if (!bounties || !bounties[who])
        return 0;

    bounties[who]["reply"] = rsn;
    bounties[who]["defendRace"] = rce;
    dates[who] = time();

    if (bounties[who]["status"] != WAIT_JURORS){
        assign_jurors(who);
    }

    bounties[who]["status"] = WAIT_JURORS;

    send_juror_mail(who);
    SAVE();

    return 1;
}

//Primarily for internal use, but can be called by the magistrate for wiz addition
int assign_juror(string nme, string cse){
    if (!nme || !cse || !bounties)
        return 0;
    if (!bounties[cse])
        return 0;

    if (member_array(nme, keys(bounties[cse]["votes"])) != -1)
        return 0;

    if (bounties[cse]["request"] == nme)
        return 0;

    if (cse == nme)
        return 0;

    bounties[cse]["votes"][nme] = -1;
    SAVE();
    return 1;
}

//To be called by the magistrate for wiz removal
int unassign_juror(string nme, string cse){
    if (!nme || !cse || !bounties)
        return 0;
    if (!bounties[cse])
        return 0;

    if (member_array(nme, keys(bounties[cse]["votes"])) == -1)
        return 1;

    map_delete(bounties[cse]["votes"], nme);
    SAVE();
    return 1;
}

//For deleting a case
int kill_case(string cse){
    if (!bounties)
        return 0;
    if (member_array(cse, keys(bounties)) == -1)
        return 0;

    map_delete(bounties, cse);
    map_delete(dates, cse);
    SAVE();
    return 1;
}

int cast_vote(string who, string cse, string vote){
    if (!who || !cse || !vote || !bounties || !case_exists(cse))
        return 0;
    if (member_array(who, keys(bounties[cse]["votes"])) == -1)
        return 0;

    switch (vote) {
    case "yes":
        bounties[cse]["votes"][who] = 1;
        break;

    case "alive":
        bounties[cse]["votes"][who] = 2;
        break;

    default:
        bounties[cse]["votes"][who] = 0;
        break;
    }

    check_verdict(cse, 0);
    SAVE();
    return 1;
}

int secret_vote(string who, string cse, string vote){
    if (!who || !cse || !vote || !bounties || !case_exists(cse))
        return 0;

    if (!bounties[cse]["secret_votes"])
        bounties[cse]["secret_votes"] = ([]);

    switch (vote) {
    case "yes":
        bounties[cse]["secret_votes"][who] = 1;
        break;

    case "alive":
        bounties[cse]["secret_votes"][who] = 2;
        break;

    default:
        bounties[cse]["secret_votes"][who] = 0;
        break;
    }

    SAVE();
    return 1;
}

int get_racism_value(string rce, string val){
    mapping tmp;

    if(rce == "" || !mapp(tmp = RACISMS[rce])){
        if(val == "votes")
            return 4;
        if(val == "kills")
            return 0;
        if(val == "juror")
            return 100;
        if(val == "can_accuse")
            return 1;
        if(val == "acc_cost")
            return 1000;
        if(val == "bribe_cost")
            return 10000;
    } else {
        return tmp[val];
    }
}

//returns 1 if the magistrate is conducive to being bribed
int can_be_bribed(object tp){
    int lawa, cha;

    lawa = LAW_ALIGN;

    //adjust according to charisma
    cha = tp->query_stats("charisma");
    if(cha < 8) lawa--;
    if(cha < 5) lawa--;
    if(cha > 15) lawa++;
    if(cha > 18) lawa++;

    //Perfect citizen
    if(lawa < 4)
        return 0;

    if(lawa > 3 && lawa < 7){
        //depends on race, goodness of person

        //A known good person can bribe
        if(GE_ALIGN < 4 && member_array(tp->query_name(), KILLING_D->query_good_bounties()) != -1)
            return 1;
        //A known evil person can bribe
        if(GE_ALIGN > 6 && member_array(tp->query_name(), KILLING_D->query_evil_bounties()) != -1)
            return 1;

        if(random(100) < get_racism_value((string)tp->query_race(), "juror"))
            return 1;
        else
            return 0;
    }

    //This person has no scruples
    if(lawa > 6)
        return 1;

}


//This stuff records the information collected about HMs
//this is called at logout.
string * query_hms(){ return jgood+jneut+jevil;}
void add_hm_info(object who){
    string nme = who->query_name();

    if (!neutral) neutral = ([]);
    if (!good) good = ([]);
    if (!evil) evil = ([]);
    if (!jgood) jgood = ({});
    if (!jevil) jevil = ({});
    if (!jneut) jneut = ({});

    if (avatarp(who) || wizardp(who))
        return;

    if (high_mortalp(who) && member_array(nme, KILLING_D->query_bounties()) == -1) {
        if (ALIGND->is_evil(who)) {
            evil[nme] = ([]);
            evil[nme]["time"] = time();
            evil[nme]["race"] = who->query_race();
            jevil = distinct_array(jevil + ({nme}) );

            jgood -= ({nme});
            jneut -= ({nme});
            map_delete(good, nme);
            map_delete(neutral, nme);
        }

        if (ALIGND->is_neutral(who)) {
            neutral[nme] = ([]);
            neutral[nme]["time"] = time();
            neutral[nme]["race"] = who->query_race();
            jneut = distinct_array(jneut + ({nme}) );

            jgood -= ({nme});
            jevil -= ({nme});
            map_delete(good, nme);
            map_delete(evil, nme);
        }

        if (ALIGND->is_good(who)) {
            good[nme] = ([]);
            good[nme]["time"] = time();
            good[nme]["race"] = who->query_race();
            jgood = distinct_array(jgood + ({nme}) );

            jevil -= ({nme});
            jneut -= ({nme});
            map_delete(evil, nme);
            map_delete(neutral, nme);
        }
    }
    else {
        jgood -= ({nme});
        jneut -= ({nme});
        jevil -= ({nme});
        map_delete(good, nme);
        map_delete(neutral, nme);
        map_delete(evil, nme);
    }
    SAVE();
    return;
}

//Called internally or from the outside by a wiz
void remove_juror(string nme){
    int tme, i, j;
    string *tmp;

    if (member_array(nme, jneut) != -1)
        jneut -= ({nme});
    if (member_array(nme, jgood) != -1)
        jgood -= ({nme});
    if (member_array(nme, jevil) != -1)
        jevil -= ({nme});

    SAVE();
}

void timecheck_juror_lists(){
    int tme, i, j;
    string *tmp;

    if (!neutral) neutral = ([]);
    if (!good) good = ([]);
    if (!evil) evil = ([]);
    if (!jgood) jgood = ({});
    if (!jevil) jevil = ({});
    if (!jneut) jneut = ({});

    tme = time() - DELAY2;

    tmp = jneut;
    if (j = sizeof(tmp)) {
        for (i = 0;i<j;i++) {
            if (neutral[tmp[i]]["time"] < tme)
                jneut -= ({tmp[i]});
        }
    }

    tmp = jgood;
    if (j = sizeof(tmp)) {
        for (i = 0;i<j;i++) {
            if (good[tmp[i]]["time"] < tme)
                jgood -= ({tmp[i]});
        }
    }

    tmp = jevil;
    if (j = sizeof(tmp)) {
        for (i = 0;i<j;i++) {
            if (evil[tmp[i]]["time"] < tme)
                jevil -= ({tmp[i]});
        }
    }

    SAVE();
    return;
}

//Needs to be reviewed in light of the number of votes to convict stuff.
void check_verdict(string who, int flag){
    mapping map;
    string *kys;
    object ob;
    int yes, i, alive, dead, votes;

    yes = dead = alive = 0;

    //tally votes
    map = bounties[who]["votes"];
    kys = keys(map);
    for (i=0;i<sizeof(kys);i++) {
        if (map[kys[i]] == 1) {
            yes++;
            dead++;
        }
        if (map[kys[i]] == 2) {
            yes++;
            alive++;
        }

        if (map[kys[i]] == -1) {
            if (!flag) {
                return;
            }
        }
    }

    map = bounties[who]["secret_votes"];
    if (mapp(map)) {
        kys = keys(map);
        for (i=0;i<sizeof(kys);i++) {
            if (map[kys[i]] == 1) {
                yes++;
                dead++;
            }
            if (map[kys[i]] == 2) {
                yes++;
                alive++;
            }
        }
    }
    //END tally.


    //Check resutlt of tally  THIS IS THE REAL MEAT
    //The number of votes a person needs depends on how the magistrate feels about them.
    votes = get_racism_value(bounties[who]["defendRace"], "votes");
    //Dead or alive is also modified by the magistrate
    alive += get_racism_value(bounties[who]["defendRace"], "kills");


    //Well, could be an appeal, so check that first
    if(!is_appeal(who)){
        //Not an appeal
        //First see if there are enough votes to convict.
        if (yes >= votes) {
            //If there are enough votes, then its simply a majority OR TIE to execute.
            if(alive > dead)
                guilty(who, "alive");
            else
                guilty(who, "dead");
        }else {
            not_guilty(who);
        }
    } else {
        //Votes of no are to keep the bounty the same way.  Votes of yes are to overturn the bounty
        //appeals can't over turn whether you are to die or not.
        votes = NUM_JURORS - votes;
        if (yes >= votes) {
            appeal_not_guilty(who);
        } else {
            if(KILLING_D->query_bounty_dead(who))
                appeal_guilty(who, "dead");
            else
                appeal_guilty(who, "alive");
        }
    }
    return;
}

void guilty(string cse, string what){
    if(what == "alive")
        KILLING_D->add_bounty(cse, 0, bounties[cse]["alias"]);
    else
        KILLING_D->add_bounty(cse, 1,bounties[cse]["alias"]);

    message("bounty","%^BOLD%^%^YELLOW%^A standard bounty has been issued!!",users());
    message("bounty","%^BOLD%^%^YELLOW%^"+capitalize(cse)+" is to be brought to justice!",users());
    if(what == "alive"){
        message("bounty","%^BOLD%^%^YELLOW%^"+capitalize(cse)+" is to be brought in ALIVE!",users());
    } else {
        message("bounty","%^BOLD%^%^YELLOW%^"+capitalize(cse)+" is to be brought in DEAD OR ALIVE!",users());
    }
    log_file("bounties","Law bounty issued for "+capitalize(cse)+" at "+ctime(time())+".\n");
    if(!case_exists(cse))
       return;
    log_votes(cse);
    send_mail( ({cse}), "You have been found guilty of the crimes reported in the Magistrate's office!");
    kill_case(cse);
    return;
}

void not_guilty(string cse){
    log_file("bounties","Law bounty request for "+capitalize(cse)+" DENIED at "+ctime(time())+".\n");
    if(!case_exists(cse))
       return;
    log_votes(cse);
    send_mail( ({cse}), "You have been found not guilty of the accuzations against you in the Magistrate's office!");
    kill_case(cse);
    return;
}


void appeal_guilty(string cse, string what){
    if(what == "alive")
        KILLING_D->add_bounty(cse, 0);
    else
        KILLING_D->add_bounty(cse, 1);

    message("bounty","%^BOLD%^%^YELLOW%^The standard bounty on "+capitalize(cse)+" has been upheld!",users());
    if(what == "alive"){
        message("bounty","%^BOLD%^%^YELLOW%^"+capitalize(cse)+" is to be brought in ALIVE!",users());
    } else {
        message("bounty","%^BOLD%^%^YELLOW%^"+capitalize(cse)+" is to be brought in DEAD OR ALIVE!",users());
    }
    log_file("bounties","Law bounty for "+capitalize(cse)+" UPHELD at "+ctime(time())+".\n");
    if(!case_exists(cse))
       return;
    log_votes(cse);
    send_mail( ({cse}), "Your appeal has been overturned in the Magistrate's office!");
    kill_case(cse);
    return;
}

void appeal_not_guilty(string cse){
    log_file("bounties","Law bounty for "+capitalize(cse)+" REVOKED by APPEAL at "+ctime(time())+".\n");
    message("bounty","%^BOLD%^%^YELLOW%^The standard bounty on "+capitalize(cse)+" has been revoked!  "+capitalize(cse)+" is a free person!", users());
    if(!case_exists(cse))
       return;
    log_votes(cse);
    send_mail( ({cse}), "Your appeal has been found righteous!  You are free!!");
    KILLING_D->remove_bounty(cse);
    kill_case(cse);
    return;
}

void log_votes(string cse){
    mapping map;
    string *kys;
    string blah;
    int i, flag;

    if(!case_exists(cse))
        return;

    flag = 0;
    map = bounties[cse]["votes"];
    kys = keys(map);
    if(is_appeal(cse))
        blah = "#appl "+capitalize(cse)+", ";
    else
        blah = "#case "+capitalize(cse)+", ";

    for (i=0;i<sizeof(kys);i++) {
        if(map[kys[i]] == -1) {
            flag = 1;
            blah += capitalize(kys[i])+", ";
        }
    }
    blah += "\n";

    if(flag)
        log_file("bounty_votes", blah);

    return;
}

//automailer
void send_mail(string *to, string msg){
    mapping borg = ([]);

    borg["from"] = "Magistrate";
    borg["to"] = to;
    borg["date"] = ctime(time());
    borg["subject"] = "Law Bounty";
    borg["message"] = msg;
    seteuid(UID_CRESAVE);
    LOCALPOST_D->post_letter(borg);
    return;
}

void timecheck_bounties(){
    //dates, bounties
    string *ky;
    mapping dt;
    int tme, i;

    dt = dates;
    ky = keys(dt);
    tme = time() - DELAY;

    for (i=0;i<sizeof(ky);i++) {
        if (dt[ky[i]] < tme) {

            if (bounties[ky[i]]["status"] == WAIT_JURORS) {
                check_verdict(ky[i], 1);
                continue;
            }

            if (bounties[ky[i]]["status"] == NO_REPLY) {
                answer_request(ky[i], "", "unborn");
                continue;
            }

            if (bounties[ky[i]]["status"] == APPEAL) {
                check_verdict(ky[i], 1);
                continue;
            }

        }
    }
    SAVE();
    return;
}

void send_accused_mail(string who){
    string msg;

    msg =  "Hear ye hear ye!\n";
    msg += "You have been accuzed of breaking the laws of the land of Shadow.\n\n";
    msg += "You are now allowed to place a reply to the accuzation with the\n";
    msg += "  Shadow Magistrate.\n";
    msg += "You have 72 hours to do so, after this time it will be sent to jury.\n\n";
    msg += "To learn of your accuzation, go to the Shadow Magistrate.";

    send_mail( ({who}), msg);
    return 1;
}

void send_juror_mail(string who){
    string msg, *to;

    msg =  "Hear ye hear ye!\n";
    msg += "You are to be involved in the dispute of "+capitalize(bounties[who]["request"])+" vs. "+capitalize(who)+".\n\n";
    msg += "Travel to the Magistrate's office to learn more.\n";
    msg += "You have 72 hours from the time you recieve this mail to judge.\n";;

    to = ({who});
    to += ({bounties[who]["request"]});
    to += keys(bounties[who]["votes"]);

    send_mail(to, msg);
    return 1;
}

void send_appeal_mail(string who){
    string msg, *to;

    msg =  "Hear ye hear ye!\n";
    msg += "You are to be involved in the appeal of "+capitalize(who)+".\n\n";
    msg += "Travel to the Magistrate's office to learn more.\n";
    msg += "You have 72 hours from the time you recieve this mail to judge.\n";

    to = ({who});
    to += keys(bounties[who]["votes"]);

    send_mail(to, msg);
}

void assign_jurors(string cse){
    //This needs to be fleshed out to select the jurors
    int i, q;

    for(i = 0;i<NUM_JURORS;i++){
        if(align_or_race_based == 1) {
            //Race based
            q = assign_juror(select_juror_by_race(), cse);
            if(!q) i--;
        } else {
            //Alignment based
            q = assign_juror(select_juror_by_alignment(), cse);
            if(!q) i--;
        }
    }
}

//This function selects a juror weighting race as the most important thing.
//  It is also weighted by whether or not they have a mycause bounty, based
//  on the align of the magistrate.
string select_juror_by_race(){
    string *allJurors;
    string who, race;
    int chance, looper, flag;

    who = "";

    while(who == ""){
        allJurors = distinct_array(jneut + jgood + jevil);

        who = allJurors[random(sizeof(allJurors))];
        if(member_array(who, jneut) != -1)
            race = neutral[who]["race"];
        if(member_array(who, jgood) != -1)
            race = good[who]["race"];
        if(member_array(who, jevil) != -1)
            race = evil[who]["race"];

        chance = get_racism_value(race, "juror");
        if(member_array(who, KILLING_D->query_evil_bounties()) != -1)
            flag = 1;
        if(member_array(who, KILLING_D->query_good_bounties()) != -1)
            flag = 2;
        switch(GE_ALIGN){
        //goods
        case 1:
            if(flag == 1)
                chance = 1;
            else
                chance = 99;
            break;
        case 2:
            if(flag == 1)
                chance -= 50;
            else
                chance += 40;
            break;
        case 3:
            if(flag == 1)
                chance -= 25;
            else
                chance += 20;
            break;
        case 4:
            if(flag == 1)
                chance -= 10;
            else
                chance += 10;
            break;

        //evils
        case 6:
            if(flag == 2)
                chance = 1;
            else
                chance = 99;
            break;
        case 7:
            if(flag == 2)
                chance -= 50;
            else
                chance += 40;
            break;
        case 8:
            if(flag == 2)
                chance -= 25;
            else
                chance += 20;
            break;
        case 9:
            if(flag == 2)
                chance -= 10;
            else
                chance += 10;
            break;
        default:

        }

        //If they have a bounty and the magistrate is lawful, hard to be a juror,
        //  otherwise just difficult.
        if(member_array(who, KILLING_D->query_bounties()) != -1){
            if(LAW_ALIGN < 5)
                chance = 1;
            else
                chance -= 45;
        }

        if(random(100) < chance)
            return who;
        else
            looper++;

        if(looper > 10)
            return who;
    }
}

string select_juror_by_alignment(){
    int x, looper;
    string *gtmp, *ntmp, *etmp, who;

    gtmp = jgood;
    ntmp = jneut;
    etmp = jevil;

    if ((sizeof(gtmp) + sizeof(ntmp) + sizeof(etmp)) < NUM_JURORS){
        ntmp = ntmp + gtmp + etmp;
        return ntmp[0];
    }

    who = "";

    //This mess of code handles the weighting system of if good or evil
    //  is put on the jury.  The outter switch is the weight, the inner
    //  switch randomizes good or evil, and the ifs make sure that
    //  we aren't trying to pull a name from an empty list.
    //  May the gods help you (or me) if this needs debugged.
    while(who == ""){
        switch (GE_ALIGN) {

        case 1:
            x = random(4);
            if (!sizeof(gtmp) && x<7)
                x=7;
            if (!sizeof(ntmp) && x>6)
                x=9;
            switch (x) {
            case 0..6:
                who = gtmp[random(sizeof(gtmp))];
                gtmp -= ({who});
                break;
            case 7..8:
                who = ntmp[random(sizeof(ntmp))];
                ntmp -= ({who});
                break;
            case 9:
                who = etmp[random(sizeof(etmp))];
                etmp -= ({who});
                break;
            }
            break;

        case 2:
            x = random(9);
            if (!sizeof(gtmp) && x<6)
                x=6;
            if (!sizeof(ntmp) && x>5)
                x=9;
            switch (x) {
            case 0..5:
                who = gtmp[random(sizeof(gtmp))];
                gtmp -= ({who});
                break;
            case 6..8:
                who = ntmp[random(sizeof(ntmp))];
                ntmp -= ({who});
                break;
            case 9:
                who = etmp[random(sizeof(etmp))];
                etmp -= ({who});
                break;
            }
            break;

        case 3:
            x = random(9);
            if (!sizeof(gtmp) && x<5)
                x=5;
            if (!sizeof(ntmp) && (x>4 && x<8))
                x=8;
            switch (x) {
            case 0..4:
                who = gtmp[random(sizeof(gtmp))];
                gtmp -= ({who});
                break;
            case 5..7:
                who = ntmp[random(sizeof(ntmp))];
                ntmp -= ({who});
                break;
            case 8:
                who = etmp[random(sizeof(etmp))];
                etmp -= ({who});
                break;
            }
            break;

        case 4:
            x = random(9);
            if (!sizeof(gtmp) && x<4)
                x=4;
            if (!sizeof(ntmp) && (x>3 && x<7))
                x=4;
            switch (x) {
            case 0..3:
                who = gtmp[random(sizeof(gtmp))];
                gtmp -= ({who});
                break;
            case 4..6:
                who = ntmp[random(sizeof(ntmp))];
                ntmp -= ({who});
                break;
            case 7..8:
                who = etmp[random(sizeof(etmp))];
                etmp -= ({who});
                break;
            }
            break;

        case 5:
            x = random(3);
            if (!sizeof(gtmp) && x==0)
                x=1;
            if (!sizeof(ntmp) && x==1)
                x=2;
            switch (x) {
            case 0:
                who = gtmp[random(sizeof(gtmp))];
                gtmp -= ({who});
                break;
            case 1:
                who = ntmp[random(sizeof(ntmp))];
                ntmp -= ({who});
                break;
            case 2:
                who = etmp[random(sizeof(etmp))];
                etmp -= ({who});
                break;
            }
            break;

        case 6:
            x = random(9);
            if (!sizeof(etmp) && x>4)
                x=2;
            if (!sizeof(ntmp) && (x>1 && x<5))
                x=0;
            switch (x) {
            case 0..1:
                who = gtmp[random(sizeof(gtmp))];
                gtmp -= ({who});
                break;
            case 2..4:
                who = ntmp[random(sizeof(ntmp))];
                ntmp -= ({who});
                break;
            case 5..8:
                who = etmp[random(sizeof(etmp))];
                etmp -= ({who});
                break;
            }
            break;

        case 7:
            x = random(9);
            if (!sizeof(etmp) && x>3)
                x=1;
            if (!sizeof(ntmp) && (x>0 && x<4))
                x=0;
            switch (x) {
            case 0:
                who = gtmp[random(sizeof(gtmp))];
                gtmp -= ({who});
                break;
            case 1..3:
                who = ntmp[random(sizeof(ntmp))];
                ntmp -= ({who});
                break;
            case 4..8:
                who = etmp[random(sizeof(etmp))];
                etmp -= ({who});
                break;
            }
            break;

        case 8:
            x = random(9);
            if (!sizeof(etmp) && x>2)
                x=2;
            if (!sizeof(ntmp) && (x>0 && x<3))
                x=-1;
            switch (x) {
            case -1:
                who = gtmp[random(sizeof(gtmp))];
                gtmp -= ({who});
                break;
            case 0..2:
                who = ntmp[random(sizeof(ntmp))];
                ntmp -= ({who});
                break;
            case 3..8:
                who = etmp[random(sizeof(etmp))];
                etmp -= ({who});
                break;
            }
            break;

        case 9:
            x = random(9);
            if (!sizeof(etmp) && x>1)
                x=1;
            if (!sizeof(ntmp) && (x==0 || x == 1))
                x=-1;
            switch (x) {
            case -1:
                who = gtmp[random(sizeof(gtmp))];
                gtmp -= ({who});
                break;
            case 0..1:
                who = ntmp[random(sizeof(ntmp))];
                ntmp -= ({who});
                break;
            case 2..8:
                who = etmp[random(sizeof(etmp))];
                etmp -= ({who});
                break;
            }
            break;
        }


        //If they have a bounty and the magistrate is lawful, hard to be a juror,
        //  otherwise just difficult.
        if(member_array(who, KILLING_D->query_bounties()) != -1){
            if(LAW_ALIGN < 5)
                who = "";
            else if (random(10))
                who = "";
        }

        looper++;
        if(looper > 10)
            return who;

        if(who != "")
            return who;
    }
    return who;
}
