//	/adm/daemon/voting_d.c
//	from the Nightmare mudlib
//	a daemon to handle mud democracy
//	created by Descartes of Borg 27 february 1993
// Multiple character coping added by Pallando (93-06-04)

#include <security.h>
#include <voting.h>
#include <daemons.h>

nosave string current_class;
int elir;
mapping votes;
string *candidates;

void create() {
    seteuid(getuid());
    candidates = ({});
    votes = ([]);
    elir = 0;
    current_class = ELECTIONS[0];
    seteuid(UID_VOTESAVE);
    restore_object(DIR_VOTES+"/"+ELECTIONS[0]);
    seteuid(getuid());
}

int register_vote(string who, string whom, string myclass) {
    if(!elir) return NOT_ELECTION_DAY;
    if(!who || !whom || !myclass) return VOTE_ERROR;
    if(member_array(myclass, ELECTIONS) == -1) return VOTE_ERROR;
    if(current_class != myclass) {
	current_class = myclass;
        seteuid(UID_VOTESAVE);
	restore_object(DIR_VOTES+"/"+current_class);
        seteuid(getuid());
    }
    if(member_array(whom, candidates) == -1) return NOT_RUNNING;
    if(votes[who] && sizeof(votes[who]) > 1) return ALREADY_VOTED;
    if(MULTI_D-> non_voter(who)) return ALREADY_VOTED;
    // 'who' is a second character and should use his main one to vote
    if(votes[who] && member_array(whom, votes[who]) != -1) return BAD_VOTE;
    if(!votes[who]) votes[who] = ({ whom });
    else votes[who] += ({ whom });
    seteuid(UID_VOTESAVE);
    save_object(DIR_VOTES+"/"+current_class);
    write_file(DIR_VOTES+"/"+current_class+"_votes", whom+"\n");
    seteuid(getuid());
    return VOTE_OK;
}

int register_candidate(string who, string myclass) {
    if(!elir) return NOT_ELECTION_DAY;
    if(!who || !myclass) return VOTE_ERROR;
    if(member_array(myclass, ELECTIONS) == -1) return VOTE_ERROR;
    if(current_class != myclass) {
	current_class = myclass;
        seteuid(UID_VOTESAVE);
	restore_object(DIR_VOTES+"/"+current_class);
        seteuid(getuid());
    }
    if(member_array(who, candidates) != -1) return ALREADY_RUNNING;
    candidates += ({ who });
    seteuid(UID_VOTESAVE);
    save_object(DIR_VOTES+"/"+current_class);
    seteuid(getuid());
    return VOTE_OK;
}

string *query_candidates(string myclass) {
    if(!elir) return ({});
    if(member_array(myclass, ELECTIONS) == -1) return ({});
    if(current_class != myclass) {
	current_class = myclass;
        seteuid(UID_VOTESAVE);
	restore_object(DIR_VOTES+"/"+current_class);
        seteuid(getuid());
    }
    return candidates;
}

int election_day() { return elir; }

void start_elections() {
    int i;

    if(geteuid(previous_object()) != UID_LAW) return;
    i = sizeof(ELECTIONS);
    while(i--) {
        seteuid(UID_VOTESAVE);
        restore_object(DIR_VOTES+"/"+ELECTIONS[i]);
        seteuid(getuid());
        current_class = ELECTIONS[i];
        elir = 1;
        seteuid(UID_VOTESAVE);
        save_object(DIR_VOTES+"/"+ELECTIONS[i]);
        seteuid(getuid());
    }
}

void end_elections() {
    string tmp;
    int i;

    if(geteuid(previous_object()) != UID_LAW) return;
    i = sizeof(ELECTIONS);
    while(i--) {
        seteuid(UID_VOTESAVE);
        tmp = read_file(DIR_VOTES+"/"+ELECTIONS[i]+"_votes");
        seteuid(UID_LOG);
        write_file("/log/archive/"+ELECTIONS[i], tmp);
        seteuid(getuid());
        elir = 0;
        current_class = ELECTIONS[i];
        votes = ([]);
        candidates = ({});
        seteuid(UID_VOTESAVE);
        save_object(DIR_VOTES+"/"+ELECTIONS[i]);
        seteuid(getuid());
    }
}
