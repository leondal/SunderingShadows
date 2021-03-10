//	/obj/port_castle.c
//	from the Nightmare mudlib
//	the portable castle dropped by high mortals to create their home
//	created by Descartes of Borg 30 january 1993

#include <daemons.h>

inherit "/d/standard/hm_hall.c";

string castle_name, long, short;
string nom, location;

void get_name(string str);
void get_short(string str);
void get_long(string str);
void complete_build();

void init() {
    ::init();
    add_action("build", "build");
}

void create() {
    seteuid(getuid());
    set_name("deed");
    set_id( ({ "deed" }) );
    set_short("An empty deed");
    set_long(
	"This is your deed which will allow you to freely choose a site\n"+
	"anywhere in our reality that does not have any special zoning\n"+
	"restrictions to build your home.  You must pick carefully, as\n"+
	"the site where you begin to build your castle becomes its\n"+
	"permanent site.  Once you have chosen a site, simply go to that\n"+
	"site and type <build castle>.  You will be prompted to give\n"+
	"some specifications, which will include the following:\n"+
	"name: the id that follows \"look at\" that allows people look at and enter it.\n"+
	"     The name should be no more than one or two lower case words!\n"+
	"short: A short description people will see when entering the room. (one line).\n"+
	"long: What people see when they look at it. Can be any number of lines.\n"
    );
    castle_name = 0;
    short = 0;
    long = 0;
}

int get() { return 0; }

int drop() {
    write("You do not want to drop your deed!\n");
    return 1;
}

int build(string str) {
    string a,b;
    object ob;

    if(!str || str != "castle") return 0;
    if(in_edit(this_player())) {
	notify_fail("You cannot build while in edit.\n");
	return 0;
    }
    if(castle_name) {
	notify_fail("You are already building a castle!\n");
	return 0;
    }
    ob = environment(this_player());
    if(!ob) {
	notify_fail("You are not anywhere!\n");
	return 0;
    }
    notify_fail("You cannot build anything in this location.\n");
    if(ob->query_property("no castle")) return 0;
    location = file_name(ob);
    if(location != base_name(ob)) return 0;
    if(sscanf(location, "%s,%s", a, b) == 2) return 0;
    if(sscanf(location, "%sworkroo%s", a, b) == 2) return 0;
    nom = (string)this_player()->query_name();
    write("In order to enter the hoe you are building here, people will need\n"+
	"to type <enter (something)>.  You therefore need to give your place\n"+
	"a simple name.  Is is a castle? Is it a house?  Is it a monolith?\n"+
	"At the prompt name: enter a name for it.  It needs to be unique to\n"+
	"this room, so if there is a house here, and you must have it called\n"+
	"a house, at name: type my_name's house, where my_name is your name.\n"+
	"DO NOT MAKE THE NAME MORE THAN 2 WORDS!!!!!\n"+
	"DO NOT ENTER QUOTATION MARKS IN THE NAME!!!!!\n"+
	"MAKE THIS MISTAKE AFTER HAVING BEEN WARNED AND YOU WILL LOSE THE HOME\n"
    );
    write("name: ");
    input_to("get_name");
    return 1;
}

void get_name(string str) {
    if(!str || str == "") {
	write("Invalid name.\n");
	return;
    }
    str = lower_case(str);
    if(present(str, environment(this_player()))) {
	write("A "+str+" already exists here.  Try another time.\n");
	return;
    }
    castle_name = str;
    write("You have a "+castle_name+".\n");
    write("Next you need to give a description of how people will notice.\n"+
	"the "+castle_name+" when they enter the room.  For instace, I\n"+
	"have a castle which I gave castle as name for, at the prompt short:\n"+
	"I would enter \"Descartes' castle stands at the side of the road.\"\n"+
	"so that short description would appear in the description of\n"+
	"this room when it is entered. Enter your short, keep it to one line.\n"+
	"DO NOT ENTER QUOTATION MARKS!!!!!!!\n"+
	"DO NOT MAKE THE SHORT OVER ONE LINE LONG!!!!!\n");
    write("short: ");
    input_to("get_short");
}

void get_short(string str) {
    if(!str || str == "") {
	write("Invalid entry.\n");
	castle_name = 0;
	return;
    }
    short = capitalize(str) + "\\n";
    write("The short for "+castle_name+" is "+short+".\n");
    write("Next you will need to enter a long description.\n"+
	"This is what people will see when they type \"look at "+castle_name+"\".\n");
    write("Use this like mail.  Enter in a description until done.  When\n"+
	"done, type a period alone on a line \".\"\n");
    write("DO NOT ENTER QUOTATION MARKS!!!!!!\n");
    input_to("get_long");
}

void get_long(string str) {
    if(!str || str == "") input_to("get_long");
    if(str != ".") {
	if(!long) long = str + "\\n";
  	else long += str + "\\n";
	input_to("get_long");
    }
    else {
	if(!long) {
	    write("Invalid entry.\n");
	    castle_name = 0;
	    short = 0;
	    return;
	}
	else complete_build();
    }
}

void complete_build() {
    write("name: "+castle_name+"\n");
    write("short: "+short+"\n");
    write("long: "+long);
    write("\n");
    write("The \\n symbol represents the end of a line.\n");
    write("Enter \"YES\" (everything between the \"\") to confirm: ");
    input_to("confirm");
}

void confirm(string str) {
    if(str != "YES") {
	castle_name = 0;
	short = 0;
	long = 0;
	return;
    }
    CASTLE_D->drop_castle(nom, location, castle_name, short, long);
    shout((string)this_player()->query_cap_name()+" has now opened a castle at "+(string)environment(this_player())->query_short()+"\n");
    remove();
}

string query_auto_load() { return "/d/standard/obj/misc/deed:"; }
