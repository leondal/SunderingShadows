//	/obj/port_castle.c
//	from the Nightmare mudlib
//	the portable castle dropped by high mortals to create their home
//	created by Descartes of Borg 30 january 1993

#include <std.h>
#include <dirs.h>
#include <daemons.h>

inherit OBJECT;

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
    ::create();
    set_name("deed");
    set("id", ({ "deed" }));
    set("short", "an empty deed");
    set("long",
	"This is your deed which will allow you to freely choose a site "
	"anywhere in our reality that does not have any special zoning "
	"restrictions to build your home.  You must pick carefully, as "
	"the site where you begin to build your castle becomes its "
	"permanent site.  Once you have chosen a site, simply go to that "
	"site and type <build castle>.  You will be prompted to give "
	"some specifications, which will include the following:\n"
	"name: the id that follows \"look at\" that allows people look at and enter it.\n"
        "     THE NAME SHOULD BE ONLY ONE OR TWO WORDS!\n"
        "short: A short description like: "A castle stands at the end of the road.\\n"
        "     "This should only be at longest one line long.\\n"
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
    if(in_edit(this_player()) || in_input(this_player())) {
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
    message("info",
      "Once your building is complete, you will need to type <enter [id]> "
      "in order to get into it from this room.  Now is the time to make "
      "up this id.  It should be no more than two words long, preferably "
      "only one word long.  For instance, if in this room you see: "
      "\"There is a brilliant castle off to the west.\", then the id for it "
      "should be \"castle\" so that you may <enter castle>.\n", this_player());
    message("prompt", "name: ", this_player());
    input_to("get_name");
    return 1;
}

void get_name(string str) {
    if(!str || str == "") {
        message("info", "Invalid name.", this_player());
	return;
    }
    str = lower_case(str);
    if(present(str, environment(this_player()))) {
	message("info", "A "+str+" already exists here.  Try another time.", this_player());
	return;
    }
    castle_name = lower_case(str);
    message("info", "The id you have is: "+castle_name, this_player());
    message("info", "Next you will need to give a short, one line "
      "description of how people will notice "+castle_name+" when they "
      "enter the room.  Perhaps something like \"A dark and frightening "
      "castle stands at the side of the road.\"  Remember, just one line, "
      "and do not enter anything in all caps, as it is annoying.",
      this_player());
    message("prompt", "short: ", this_player());
    input_to("get_short");
}

void get_short(string str) {
    if(!str || str == "") {
        message("info", "Invalid entry.", this_player());
	castle_name = 0;
	return;
    }
    short = replace_string(str, "\\", "");
    short = capitalize(replace_string(str, "\"", "\\\""));
    message("info", "The short for "+castle_name+" is "+short+".  Next "
      "you need to enter a more verbose and descriptive passage.  "
      "It can be any number of lines.  You do this just like you do the "
      "mail.", this_player());
    rm(DIR_TMP+"/"+geteuid(this_player())+".castle");
    this_player()->edit(DIR_TMP+"/"+geteuid(this_player())+".castle",
      "get_long", this_object());
}
void get_long() {
    string text;

    if(!(text=read_file(DIR_TMP+"/"+geteuid(this_player())+".castle")) ||
      text == "") { 
        castle_name = 0;
        short = 0;
        return;
    }
    text = replace_string(text, "\n", " ");
    text = replace_string(replace_string(text, "\\", ""), "\"", "\\\"");
    long = text;
    message("info", "name: "+castle_name, this_player());
    message("info", "short: "+short, this_player());
    message("info", "long: "+long, this_player());
    message("prompt", "\nEnter YES to accept these values: ", this_player());
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
    message("environment", (string)this_player()->query_cap_name()+
      " has opened a castle at "+(string)environment(this_player())->query_short()+".", users(), ({ this_player() }));
    remove();
}

string query_auto_load() { return "/obj/deed:"; }
