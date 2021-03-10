//	Stronghold Room
//	Thorn@Shadowgate
//	1/26/97
//	Player Strongholds
//	strongroom.c

#include <strongholds.h>

inherit "/std/vault";

//  Global Variables
object   chest, 
         marker;
string   strongid, 
        *allowed, 
        *invited;
int      protect;

//  Function Prototypes
object   query_strongid();
object   query_marker();
int      restoreStronghold(string id);
int      saveStronghold(string id);
int      query_protection();
int      query_protect();
int      invite_fun(string str);
int      remove_invited();
int      allow_fun(string str);
int      disallow_fun();
int      info_fun();
int      protect_fun();
int      sweep_fun();
string  *query_allowed();
string  *query_invited();
void     set_marker(object ob);
void     set_strongid(int x);
void     set_protection(int x);
void     set_protect(int x);

void create() {
	::create();
	set_light(2);
	set_indoors(1);
	set_short("Blank Stronghold Room");
	set_long(
@STRONG
	This is an empty room, ownerless and very dull.  I would 
suggest changing this so that you actually have an interesting
place to live.

STRONG
	);
	set_items( ([ ]) );
	invited = ({ });
	allowed = ({ });
}

void init()
{
	::init();
	add_action("invite_fun", "invite");
	add_action("allow_fun", "allow");
	add_action("disallow_fun", "disallow");
	add_action("info_fun", "info");
	add_action("protect_fun", "addprotect");
	add_action("sweep_fun", "sweep");
}

int restoreStronghold(string id)
{
	seteuid("Stronghold");
	restore_object(RDATADIR+id);
	seteuid(getuid());
	return 1;
}

int saveStronghold(string id)
{
	seteuid("Stronghold");
	invited = ({ });
	save_object(RDATADIR+id, 0);
	seteuid(getuid());
	return 1;
}

void set_marker(object ob) { marker = ob; }

object query_marker() { return marker; }

void set_strongid(int x) { strongid = x; }

object query_strongid() { return strongid; }

void set_protection(int x) { protect = x; }

int query_protection() { return protect; }

void set_protect(int x) { protect = x; }

int query_protect() { return protect; }

string *query_allowed() { return allowed; }

string *query_invited() { return invited; }

int invite_fun(string str) 
{
	int i;
	string temp;

	if(!str) {
		for(i=0;i<sizeof(invited);i++) { temp += (invited[i]+", "); }
		write("Invited list: "+temp);
		return 1;
	}
	invited += ({ str });
	write(capitalize(str)+" has been invited to the stronghold.\n");
	tell_object(find_player(str), "You have been invited into the stronghold, <enter> within 45 seconds");
	call_out("remove_invited", 45);
	return 1;
}

int remove_invited() 
{
	invited = ({ });
	return 1;
}

int allow_fun(string str) 
{
	int i;
	string temp;

	if(!str) {
		for(i=0;i<sizeof(allowed);i++) { temp += (allowed[i]+", "); }
		write("Allowed list: "+temp);
		return 1;
	}
	allowed += ({ str });
	write(capitalize(str)+" has been invited to the stronghold.\n");
	tell_object(find_player(str), "You have been added to the allowed list for this stronghold.");
	return 1;
}

int disallow_fun() 
{
	return 1;
}

int info_fun() 
{
	int i;
	string temp;

	write("\n---Stronghold Information---\n");
	for(i=0;i<sizeof(allowed);i++) { temp += (allowed[i]+", "); }
	write(wrap("Allowed list: "+temp));
	write("\n");
	for(i=0;i<sizeof(invited);i++) { temp += (invited[i]+", "); }
	write(wrap("Invited list: "+temp));
	write("\n");
	write("Protection level: "+protect);
	return 1;
}

int protect_fun() 
{
	protect += 1;
	return 1;
}

int sweep_fun() 
{
	
	return 1;
}
