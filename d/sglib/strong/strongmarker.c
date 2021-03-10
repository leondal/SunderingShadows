//  Stronghold Marker, for access to player strongholds
//  Thorn@ShadowGate
//  970127
//  strongmarker.c

#include <strongholds.h>

//  Global Variables
string   strongid, strongowner, strongpath;
object   stronghold;

//  Function Prototypes
int      enter_fun();
int      help_fun();
int      refresh_fun();
int      restoreMarker(string id);
int      saveMarker(string id);
string   query_strongid();
string   query_owner();
string   query_cap_owner();
string   setupMarker(string playername, string short, string long);
void     set_strongid(string id);
void     set_owner(string owner);

inherit OBJECT;

void create() 
{
	::create();
	set_name("road sign");
	set_id( ({ MARKERID, "marker", "sign", "stronghold" }) );
	set_short("A road sign");
	set_long(
@STRONG
	This is a marker that allows you to enter the stronghold of
one of the players of ShadowGate.  If you are reading this 
particular description, you are probably either looking at a
blank marker or the marker of a player with little imagination.
STRONG
	);
	set_value(0);
	set_weight(10001);
}

void init() 
{
	::init();
	add_action("enter_fun", "enter");
	add_action("help_fun", "help");
	add_action("refresh_fun", "refresh");
}

int enter_fun()
{
	object room, strong, player;
	string roompath, *invited, *allowed;
	
	player = TP;
	room = ETO;
	
	strongpath = base_name(room);
	if(!stronghold) {
		strong = new(SROOM);
                strong->restoreStronghold(strongid);
		strong->set_marker(TO);
            strong->add_exit(strongpath,"out");
		stronghold = strong;
	}
	else strong = stronghold;
       strong->add_exit(strongpath,"out");
	allowed = stronghold->query_allowed();
	invited = stronghold->query_invited();
	
	if(strongowner == (string)TPQN) {
		tell_room(room, TPQCN+" takes a turn down a path off to the side.", TP);
		tell_object(player, "You turn down a path leading to your stronghold");
		player->move_player(stronghold);
		return 1;
	}
	else if(member_array(TPQN, allowed) != -1) {
		tell_room(room, TPQCN+" takes a turn down a path off to the side.", TP);
		tell_object(player, "You turn down a path leading to the stronghold of "+query_cap_owner());
		player->move_player(stronghold);
		return 1;
	}
	else if(member_array(TPQN, invited) != -1) {
		tell_room(room, TPQCN+" takes a turn down a path off to the side.", TP);
		tell_object(player, "You turn down a path leading to the stronghold of "+query_cap_owner());
		player->move_player(stronghold);
		return 1;
	}
	else write("The guards bar you from entering the stronghold, sorry.\n");
	return 1;
}

void set_strongid(string id) { strongid = id; }

string query_strongid() { return strongid; }

void set_owner(string owner) { strongowner = owner; }

string query_owner() { return strongowner; }

string query_cap_owner() { return strongowner; }

string setupMarker(string playername, string short, string long) 
{
	object daemon;
	
	strongid = playername+time()+random(10);
	strongowner = playername;
	stronghold = new(SROOM);
	stronghold->set_marker(TO);
	stronghold->set_strongid(strongid);
	stronghold->set_short(short);
	stronghold->set_long(long);
        stronghold->saveStronghold(strongid);
	saveMarker(strongid);
	daemon = find_object_or_load(SDAEMON);
	daemon->addNewMarker(strongid, ETO);
	return strongid;
}
	
int help_fun()
{
	return 1;
}

int refresh_fun()
{
	return 1;
}

int restoreMarker(string id)
{
	seteuid("Stronghold");
	restore_object(RMARKERDIR+id, 1);
	seteuid(getuid());
	return 1;
}

int saveMarker(string id)
{
	seteuid("Stronghold");
	save_object(RMARKERDIR+id, 1);
	seteuid(getuid());
	return 1;
}


string removeRoom() 
{
	if(!stronghold) return "Room remove failed or no room present";
	if(!stronghold->remove()) destruct(stronghold);
	return "Room remove completed successfully";
}

