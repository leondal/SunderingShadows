/* Cygnus@Nightmare */

#include <std.h>
inherit DAEMON;

string path;
string short;
string night_long;
string day_long;
string long;
string *destinations;
mapping item;


int check_room(object ob)
{
    int i;
    int error;
    string message;
    string *items;
    string desc;
    string func;

    error = 0;

    if (member_array("std/room.c", deep_inherit_list(ob)) == -1)
	if (path != "/std/room") {
	    write("Warning: " + path +
		" is not a subclass of /std/room.\n");
	    error = 1;
	}

    if (!stringp(geteuid(ob)))
	write("Warning: geteuid() did not return a string.\n");

    short = (string)ob->query_short();
    if (!stringp(short)) {
	write("Warning: query_short() did not return a string.\n");
	error = 1;
    }

    night_long = (string)ob->query("night long");
    day_long = (string)ob->query("day long");
    long = (string)ob->query("long");
    if (stringp(night_long) == stringp(day_long)) {
	if (!stringp(night_long) && !stringp(long)) {
	    write("Warning: query_long() did not return a string.\n");
	    error = 1;
	}
    } else
	if (stringp(night_long)) {
	    if (!stringp(long)) {
		write("Warning: query(\"day light\") did not return a" +
		    " string.\n");
		error = 1;
	    } else
		day_long = long;
	} else {
	    if (!stringp(long)) {
		write("Warning: query(\"night light\") did not return a" +
		    " string.\n");
		error = 1;
	    } else
		night_long = long;
	}

    item = ([ ]);

    items = (string *)ob->query_item_descriptions();
    if (pointerp(items))
	for (i = 0; i < sizeof(items); i++) {
	    if (!stringp(items[i])) {
		write("Warning: query_item_descriptions() array member " + i +
		    " is not a string.\n");
		error = 1;
	    } else {
		if (!mapp(item[items[i]]))
		    item[items[i]] = ([ ]);
		desc = (string)ob->query_item_description(items[i]);
		if (!stringp(desc)) {
		    write("Warning: query_item_description() for \"" +
			items[i] + "\" did not return a string.\n");
		    error = 1;
		} else
		    item[items[i]]["description"] = desc;
	    }
	}

    items = (string *)ob->query_item_functions();
    if (pointerp(items)) {
	for (i = 0; i < sizeof(items); i++) {
	    if (!stringp(items[i])) {
		write("Warning: query_item_functions() array member " + i +
		    " is not a string.\n");
		error = 1;
	    } else {
		if (!mapp(item[items[i]]))
		    item[items[i]] = ([ ]);
		func = (string)ob->query_item_function(items[i]);
		if (!stringp(func)) {
		    write("Warning: query_item_function() for item \"" +
			items[i] + "\" did not return an string.\n");
		    error = 1;
		} else {
		    if (!stringp(function_exists(func, ob))) {
			write("Warning: function " + func +
			    " does not exist in object " +
			    file_name(ob));
			error = 1;
		    } else
			item[items[i]]["function"] = func;
		}
	    }
	}
    }

    destinations = (string *)ob->query_destinations();
    if (pointerp(destinations))
	for (i = 0; i < sizeof(destinations); i++) {
	    if (!stringp(destinations[i])) {
		write("Warning: query_destinations() array member " + i +
		    " is not a string.\n");
		error = 1;
	    } else {
		message = catch(find_object_or_load(destinations[i]));
		if (stringp(message)) {
		    write("Warning: could not load " + destinations[i] +
			": " + message + "\n");
		    error = 1;
		}
	    }
	}

    return !error;
}

void
print_room(object ob)
{
    int i;
    string *items;

    write("User IDs: " + getuid(ob) + "/" + geteuid(ob) + "\n");

    write("Short:\n" + short + "\n");
    if (stringp(night_long)) {
	write("Night Long:\n" + night_long);
	write("Day Long:\n" + day_long);
    } else
	write("Long:\n" + long);

    items = keys(item);
    if (sizeof(items) != 0) {
	printf(sizeof(items) + " Item(s):\n");
	for (i = 0; i < sizeof(items); i++) {
	    write(items[i] + ":");
	    if (stringp(item[items[i]]["function"]))
		write("  " + item[items[i]]["function"] + "()");
	    write("\n");
	    if (stringp(item[items[i]]["description"]))
		write(item[items[i]]["description"]);
	}
    }
}

int
cmd_rcheck(string room)
{
    object ob;

    if (stringp(room)) {
	catch(ob = find_object_or_load(room));
	if (!objectp(ob)) {
	    notify_fail(query_verb() + ": cannot find or load \"" +
		room + "\".\n");
	    return 0;
	}
    } else
	ob = environment(this_player());

    path = base_name(ob);

    write("Room Check for: " + path + "\n");

    if (check_room(ob))
	print_room(ob);

    return 1;
}

int help()
{
  write( @EndText
Syntax: rcheck [<filename>]
Effect: Balance command to check rooms.
        Checks the basic room properties have been set in room <filename>
        If <filename> is not specified, your current environment is used.
See doc: /doc/QC/check.doc
See also: acheck, wcheck
EndText
  );
return 1;
}
