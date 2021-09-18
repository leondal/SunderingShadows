//NOT ACTIVELY USED
//But could be potentially useful

// Government Daemon
// Keeps track of positions that are occupied by players
// with power over certain areas.
// Thorn@ShadowGate
// 11 December 2000
// /daemon/government.c

#include <std.h>
#include <security.h>
#include <government.h>

// DEBUG mode enabled on 1, 0 is off.  Make sure and set DEBUGGER
// to yourself if you are testing this.
#define DEBUG 1
#define DEBUGGER "thorn"

#define SAVE_FILE "/daemon/save/government"

inherit DAEMON;

mapping positions;
mapping office_holders;
string *officers;
mapping juris_props;

private void SAVE();
private void LOG(string msg);

// DONE
int add_officer(string person, string office);
int remove_officer(string person, string office);
int valid_office(string office);
string query_officer(string office);
private int holds_office(string person, string office);
string query_title(string office);
int query_nobid(string office);
int query_minpower(string office);
string query_jurisdiction(string office);
int valid_jurisdiction(string jurisdiction);
int set_jurisdiction_property(string jurisdiction, string property, mixed data);
int remove_jurisdiction_property(string jurisdiction, string property);
mixed query_jurisdiction_property(string jurisdiction, string property);
int check_conflict(string person, string jurisdiction);
int valid_officer(string person, string office);

// NOT DONE
string *dump_officers();
int update_daemon();

void create() {
    ::create();

  positions = VALID_OFFICES;
  office_holders = ([]);
  juris_props = ([]);
  officers = ({});
  seteuid(UID_DAEMONSAVE);
  restore_object(SAVE_FILE);
  seteuid(getuid());
  update_daemon();
}

void SAVE() {
  seteuid(UID_DAEMONSAVE);
  save_object(SAVE_FILE);
  seteuid(getuid());
}

void LOG(string msg) {
  seteuid(UID_LOG);
  seteuid(getuid());
}

int add_officer(string person, string office) {
    string juris;
    object dude;

    if(!valid_office(office)) return 0;
    office_holders[office] = person;
    juris = positions[office][JURISDICTION];
    set_jurisdiction_property(juris, person, office);
    dude = find_player(person);
    dude->set_property(office, 1);
    SAVE();
    return 1;
}

int remove_officer(string person, string office) {
    string juris;
    object dude;

    if(!valid_office(office)) return 0;
    juris = positions[office][JURISDICTION];
    map_delete(office_holders, office);
    remove_jurisdiction_property(juris, person);
    dude = find_player(person);
    dude->remove_property(office);
    SAVE();
    return 1;
}

int valid_office(string office) {
    if(!positions[office]) return 0;
    return 1;
}

string query_officer(string office) {
    if(!office_holders[office]) return "Empty";
    return office_holders[office];
}

private int holds_office(string person, string office) {
    if(office_holders[office] == person) {
		if(!query_jurisdiction_property(query_jurisdiction(office), person)) {
		    map_delete(office_holders, office);
			return 0;
		}
		return 1;
	}
    return 0;
}

string query_title(string office) {
    mixed *tmp;

    tmp = positions[office];
    return tmp[TITLE];
}

int query_nobid(string office) {
    mixed *tmp;

    tmp = positions[office];
    return tmp[NOBID];
}

int query_minpower(string office) {
    mixed *tmp;

    tmp = positions[office];
    return tmp[MINPOWER];
}

string query_jurisdiction(string office) {
    mixed *tmp;

	if(!valid_office(office)) return 0;
    tmp = positions[office];
    return tmp[JURISDICTION];
}

int valid_jurisdiction(string jurisdiction) {
    if(member_array(jurisdiction, VALID_JURISDICTIONS) != -1) return 1;
    return 0;
}

int set_jurisdiction_property (
        string jurisdiction,
        string property,
        mixed data
    ) {

    if(!juris_props[jurisdiction]) juris_props[jurisdiction] = ([]);
    juris_props[jurisdiction][property] = data;
    SAVE();
    return 1;
}

int remove_jurisdiction_property (string jurisdiction, string property) {
    if(!juris_props[jurisdiction]) return -1;
    map_delete(juris_props[jurisdiction], property);
    SAVE();
    return 1;
}

mixed query_jurisdiction_property(string jurisdiction, string property) {
    if(!juris_props[jurisdiction]) {
        if(valid_jurisdiction(jurisdiction))
            juris_props[jurisdiction] = ([ ]);
        return 0;
    }
    return juris_props[jurisdiction][property];
}

int check_conflict(string person, string jurisdiction) {
    if(query_jurisdiction_property(jurisdiction, person)) return 1;
    return 0;
}

int valid_officer(string person, string office) {
    object poser;

    poser = find_player(person);
	if(!valid_office(office)) return 0;
    if(!holds_office(person, office)) return 0;
    if(!poser->query_property(office)) {
        remove_officer(person, office);
        return 0;
    }
    return 1;
}

// Goes through the all of the positions and expires the term
// of the officers where their position account has reached less than
// the position minimum required.  Also removes officers who are
// no longer in the game (rid, suicide, etc.) and opens their positions
// to the public.
int update_daemon() {
  int inc;
  string *ikeys = keys(office_holders);
  int numkeys = sizeof(ikeys);
  mixed *value;
  string owner;
  string *name;
  string initial;
  int now = time();
  string office;

  for(inc=0;inc<numkeys;inc++) {
    office = ikeys[inc];
    owner = office_holders[office];

    name = explode(owner, "");
    initial = name[0];
    if(!file_exists("/adm/save/users/"+initial+"/"+owner+".o")) {
      LOG("The player, "+owner+", no longer exists.  Removing from office.");
      remove_officer(owner, office);
      continue;
    }
  }
  SAVE();
}
