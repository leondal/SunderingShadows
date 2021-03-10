// Government Building
// Inheritable for specific government and guild
// buildings
// Thorn@ShadowGate
// 11 December 2000
// /std/government.c

#include <std.h>
#include <government.h>
#include <daemons.h>
#include <bboard.h>

#define POWER_D "/daemon/power"
#define GOV_D "/daemon/government"

inherit ROOM;

string *offices;
string *jurisdictions;
string *posts;
string *read_by;

void set_offices(string *allowed);
string query_offices();
void set_jurisdictions(string *jurisdictions);
string *query_jurisdictions();
int bid(string str);
int resign(string str);
int oust(string str);
int list(string str);
void list_offices(object player);
void add_officer(string person, string office);
void remove_officer(string person, string office);
int post_message(string id, string poster, string title, string msg);
void send_mail(string *to, string poster, string subj, string msg);



void create() {
  room::create();
}

void reset(){
	::reset();
}

void init(){
	::init();
	add_action("bid", "bid");
	add_action("oust", "oust");
	add_action("resign", "resign");
	add_action("list", "list");
	add_action("help", "help");
}

void set_offices(string *allowed) {
	offices = allowed;
}	

void set_jurisdictions(string *allowed) {
	jurisdictions = allowed;
}	

string *query_offices() { 
	return offices;
}

string *query_jurisdictions() { 
	return jurisdictions;
}

// This is NOT yet completed.
int bid(string str) {
	int contender_pow, holder_pow, office_pow;
	string office, holder, contender;
	
	contender = TPQN;
	if(!str) {
		list_offices(TP);
		return 1;
	}
	if(sscanf(str, "for %s", office) != 1 ) {
		write("Syntax: bid for <office name>\n"
		      "Example: bid for shadow mayor.");
		return 1;
	}
	if(!GOV_D->valid_office(office)) {
		write("That office is either non-existant or unavailable at "
		      "this building.");
		list_offices(TP);
		return 1;
	}
	if(GOV_D->valid_officer(contender, office)) {
	    write("You already hold that office.");
		return 1;
	}
	if(GOV_D->query_nobid(office)) {
	    write("That office is filled by appointment only.");
		return 1;
	}
	if(GOV_D->check_conflict(office)) {
	    write("You already hold an office that would conflict with "
		      "the duties of this one.\nYou must <resign> that "
			  "position before you can try and take this one."
		);
		return 1;
	}
	
	// NOT ADDED YET
	// Check power to see if it is enough to overcome the minimum
	// amount to fulfill the requirements for this position.


	add_officer(contender, office);
	return 1;
}

int resign(string str) {
	int holder_pow;
	string office, holder, title;
	
	holder = TPQN;
	if(!str) {
		list_offices(TP);
		return 1;
	}
	if(sscanf(str, "as %s", office) != 1 ) {
		write("Syntax: resign as <office name>\n"
		      "Example: resign as shadow mayor.");
		return 1;
	}
	if(!GOV_D->valid_office(office)) {
		write("That office is either non-existant or unavailable at "
		      "this building.");
		list_offices(TP);
		return 1;
	}
	if(!GOV_D->valid_officer(holder, office)) {
	    write("You don't hold that office to resign!");
		return 1;
	}
	title = GOV_D->query_title(office);
	write("You submit your resignation as "+title+"!");
	remove_officer(holder, office);
	return 1;
}

// This is NOT yet completed.
int oust(string str) {
	int contender_pow, holder_pow, office_pow;
	string office, holder, contender;
	
	contender = TPQN;
	if(!str) {
		list_offices(TP);
		return 1;
	}
	if(sscanf(str, "%s as %s", holder, office) != 2) {
		write("Syntax: oust <player name> as <office name>\n"
		      "Example: oust george as shadow mayor.");
		return 1;
	}
	if(!GOV_D->valid_office(office)) {
		write("That office is either non-existant or unavailable at "
		      "this building.");
		list_offices(TP);
		return 1;
	}
	if(GOV_D->valid_officer(contender, office)) {
	    write("Why are you trying to oust yourself?");
		return 1;
	}
	if(GOV_D->query_nobid(office)) {
	    write("That office is filled by appointment only.");
		return 1;
	}
	if(!GOV_D->valid_officer(holder, office)) {
	    write("The person you are trying to oust does not hold that "
		      "position.  Check your spelling.");
		list_offices(TP);
		return 1;
	}
	if(GOV_D->check_conflict(office)) {
	    write("You already hold an office that would conflict with "
		      "the duties of this one.\nYou must <resign> that "
			  "position before you can try and take this one.");
		return 1;
	}
	// Check power for ousting -- not done yet
	
	write("You have successfully taken this position.  Keep in mind "
	      "that the person you ousted may not be so happy about "
		  "that.");
	remove_officer(holder, office);
	add_officer(contender, office);
	return 1;
}

int list(string str) {
	if(str != "directory") return 0;
	list_offices(TP);
	return 1;
}

void add_officer(string person, string office) {
	string title;
	object player;
	
	player = find_player(person);
	title = GOV_D->query_title(office);
	tell_player(player,
		"You are now installed in the position of "+title+" with all of "
		"the rights and duties thereof.\n"
	);
	GOV_D->add_officer(person, office);
}

void remove_officer(string person, string office) {
	string title;
	object player;

	player = find_player(person);
	if(present(player)) {
		tell_player(player,
			"You have been removed as "+title+".\n"
		);
	}
	GOV_D->remove_officer(person, office);
}

void list_offices(object player) {
	int inc;
	string *offs;
	string out;
	string this_office, holder, title;
	
	offs = offices;
	tell_player(player, 
		"The following offices and officers are based here:\n\n"
	);
	out = sprintf("%-35s %-20s %s\n", "Office Title", "Holder", "Office ID");
	out += sprintf("%-35s %-20s %s\n\n", "------------", "------", "---------");
	for(inc=0;inc<sizeof(offs);inc++) {
		this_office = offs[inc];
		if(!GOV_D->valid_office(this_office)) {
			holder = "Invalid Office";
			title = "Invalid Office";
		}
		else {
			holder = GOV_D->query_officer(this_office);
			title = GOV_D->query_title(this_office);
		}
		out += sprintf("%-35s %-20s (%s)\n", title, capitalize(holder), this_office);
	}
	tell_player(player, out);
	return 1;
}
	 
int announcement(string poster, string title, string msg) {
	int inc, num_juris;
	
	if(!jurisdictions) return 0;
	num_juris = sizeof(jurisdictions);
	if(!num_juris) return 0;
	
	for(inc=0;inc<num_juris;inc++) {
		BBOARD_D->direct_post(jurisdictions[inc], poster, title, msg);
	}
	return 1;
}
	

