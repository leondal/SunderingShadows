//	/obj/port_castle.c
//	from the Nightmare mudlib
//	the portable castle dropped by high mortals to create their home
//	created by Descartes of Borg 30 january 1993

#include <std.h>
#include <dirs.h>
#include <security.h>
#include <daemons.h>

inherit OBJECT;

private string return_direction, dir, short, long, location, owner;

void get_return_direction(string str);
void get_short(string str);
void get_long();
void complete_build();

void init() {
    ::init();
     add_action("build", "buildroom");
}

void create() {
    ::create();
    set_name("work roder");
    set("id", ({ "order", "work order", "room maker" }));
    set("short", "a work order");
    set("long",
      "This is a work order for adding chambers to your growing castle.  "
      "To use it, go to a room in your castle and type:\n"
      "<build room [direction]>\n"
      "where <direction> is the command you will type to get from this "
      "room to the new one.  You then will be prompted to customize the "
      "new chamber a bit.  You will be prompted for the following:\n"
      "1) return direction: The command you will type from the new room "
      "to get back to the old one.  For example, if you typed <build room "
      "east>, then for return direction you will enter west.\n"
      "short description: A one line description of the room.\n"
      "long description: A *visual* description of the room that will "
      "be printed when a player types look or enters a room.  DO NOT "
      "include sounds, smells, or a list of exits in the description.  "
      "A list of exits is automatically added, and you add smells and sounds "
      "with a special item."
    );
    short = 0;
    long = 0;
}

int build(string str) {
    string a,b;
    object ob;

    if(!str || !sscanf(str, "room %s", dir)) {
        dir = 0;
        return 0;
    }
    if(in_edit(this_player()) || in_input(this_player())) 
      return notify_fail("You cannot build while editing.\n");
    if(return_direction) return notify_fail("You are already building this room.\n");
    if(!(ob = environment(this_player())))
      return notify_fail("You have serious problems.\n");
    notify_fail("You cannot build anything in this location.\n");
    if(ob->query_property("no castle")) return 0;
    if((owner = (string)ob->query_owner()) != geteuid(this_player()))
      return 0;
    if(ob->query_exit(dir)) return 0;
    location = (string)ob->query_save_file();
    message("info",
      "In order to get out of your new chamber once it is built (and thus "
      "return to the room you are now in, you will need to type some "
      "command.  If you are building a chamber to the east, you should "
      "enter west as a return direction.  Do not build trick rooms, as "
      "the approval department of the mud will get annoyed and revoke "
      "your building priveldges.  This option exists in the event you have "
      "chosen to build using a non-standard exit name (like climb).",
      this_player()
    );
    message("prompt", "return direction: ", this_player());
    input_to("get_return_direction");
    return 1;
}

void get_return_direction(string str) {
    if(!str || str == "") {
        message("info", "Invalid return direction.", this_player());
	return;
    }
    return_direction = lower_case(str);
    message("info", "The return direction for coming back from "+
      "the "+dir+" is %^RED%^"+return_direction+".", this_player());
    message("info", "Next you will need to give a short, one line "
      "description of how people will notice the room "+dir+" when they "
      "enter the room.  Perhaps something like \"A dark and frightening "
      "room.\"  Remember, just one line, "
      "and do not enter anything in all caps, as it is annoying.",
      this_player());
    message("prompt", "short: ", this_player());
    input_to("get_short");
}

void get_short(string str) {
    if(!str || str == "") {
        message("info", "Invalid entry.", this_player());
	return_direction = 0;
	return;
    }
    short = replace_string(str, "\\", "");
    short = capitalize(replace_string(str, "\"", "\\\""));
    message("info", "The short for the room "+dir+" is "+short+".  Next "
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
        return_direction = 0;
        short = 0;
        return;
    }
    text = replace_string(text, "\n", " ");
    text = replace_string(replace_string(text, "\\", ""), "\"", "\\\"");
    long = text;
    message("info", "return direction: "+return_direction, this_player());
    message("info", "short: "+short, this_player());
    message("info", "long: "+long, this_player());
    message("prompt", "\nEnter YES to accept these values: ", this_player());
    input_to("confirm");
}
void confirm(string str) {
    if(str != "YES") {
	return_direction = 0;
	short = 0;
	long = 0;
	return;
    }
    seteuid(UID_HM);
    "/daemon/mudlib/std/castle_d"->add_room(owner, long, short, ({ location, return_direction }), dir);
    seteuid(getuid());
    remove();
}

