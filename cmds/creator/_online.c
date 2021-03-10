//      Online RoomMaker for ShadowGate v0.9g
//      Thorn@ShadowGate
//      4/4/95
//      Builder Tools
//      _online.c

#include <std.h>
#include <security.h>

#define HELPDIR "/realms/thorn/help/"

inherit DAEMON;

string filename, short, hear_desc;
string long_desc, smell_desc;
string light;
string *exit_names, *exit_paths;
string *item_names, *item_descs;
string help_file, function_name;
int x, smell, hear, indoors;
int lastexit, lastitem, start;
int count, default_dir;
int prompt_before_saving, admin_privs;
int view_room;

void filename(string str);
void help(string str);
void menu();
void set_options();
void capture_options(string str);
void preview_room(string fname);
void prompt_for_save(string str);
void run_program();
void short(string str);
void long(string str);
void exit_names(string str);
void exit_paths(string str);
void item_names(string str);
void item_descs(string str);
void smell(string str);
void smell_desc(string str);
void hear(string str);
void hear_desc(string str);
void write_room(string fname);
void filename_help();



void cmd_online() {
//  Option switch variables set to default values here.  -- Thorn 4/10/95
//  -----------------------------
	default_dir = 0;
	prompt_before_saving = 0;
	view_room = 0;
	admin_privs = 0;
//  -----------------------------
	menu();
}

void run_program() {
//  If Admin Privs is enabled, then access is granted to make rooms anywhere.
//   -- Thorn 4/10/95
//  ----------------------------------------------
		if(!admin_privs) seteuid("RoomMakerSave");
		else seteuid(UID_ROOT);
//  ----------------------------------------------
        indoors = 0;
        x = 0;
        exit_names = ({});
        exit_paths = ({});
        item_names = ({});
        item_descs = ({});
        long_desc = "";

        if(start) write(
@ONLINE09G

Ready for next room.
_________________________________

ONLINE09G
		);
		if(!start) count = 1;
        if(!start) write("Enter the filename: \n");
		else write("Enter the filename: \n");
        start = 1;
        input_to("filename");
}

void filename(string str) {
		int clean;
		string tmp;
		
        function_name = "filename";
        if(str == "") input_to("filename");
        else if(str == "?") {
        	help("filename");
        	return;
        }
        else if(str == "~q") {
        	start = 0;
        	return;
        }
        else {
                filename = str;
                clean = sizeof(filename);
                if(sscanf(filename, "~%s", tmp) == 1) {
                	filename = "/realms/"+TPQN+"/"+tmp;
                	write(filename+"\n");
                }
//  If the default directory option is enabled then the filename is altered by
//  this bit of code. -- Thorn 4/10/95
//  ------------------------------------------------------
        if(default_dir) {
        	filename = "/realms/"+TPQN+"/room/"+str;
        	write(filename+": Default directory used.\n");
        }
//  ------------------------------------------------------
        write("How much light is there in the room?");
        write("NOTE: 2 is normal.  Less is darker (even\n negative numbers), more is brighter.\n");
        input_to("light");
        }
}

void light(string str) {
		function_name = "light";
        if(str == "") input_to("light");
        else if(str == "?") {
        	help("light");
        	return;
        }
        else if(str == "~q") {
        	start = 0;
        	return;
        }
        else {
                light = str;
                write("Enter the short description.");
                input_to("short");
        }
}

void short(string str) {
		function_name = "short";
        if(str == "") input_to("short");
        else if(str == "?") {
        	help("short");
        	return;
        }
        else if(str == "~q") {
        	start = 0;
        	return;
        }
        else {
                short = str;
                write("Enter the long description.\n");
                input_to("long");
        }
}

void long(string str) {
		function_name = "long";
        if(str == "") input_to("long");
        else if(str == "?") {
        	help("long");
        	return;
        } 
        else if(str == "~q") {
        	start = 0;
        	return;
        }
        else {
                if(str == "**") {
                        write("Enter the exit names.");
                        input_to("exit_names");
                        x = 0;
                }
                else {
                        if(!long_desc) long_desc = str+"\n";
                        else long_desc = long_desc+str+"\n";
                        input_to("long");
                }
        }
}

void exit_names(string str) {
        if(str == "") input_to("exit_names");
        else if(str == "?") {
        	help("exit_names");
        	return;
        }
        else if(str == "~q") {
        	start = 0;
        	return;
        }
        else {
                if(str == "**") {
                        write("Enter the exit paths.");
                        input_to("exit_paths");
                        x = 0;
                }
                else {
                        exit_names = exit_names + ({ str });
                        input_to("exit_names");
                        x++;
                }
        }
}

void exit_paths(string str) {
        if(str == "") input_to("exit_paths");
        else if(str == "?") {
        	help("exit_paths");
        	return;
        }
        else if(str == "~q") {
        	start = 0;
        	return;
        }
        else {
                if(str == "**") {
                        write("Enter the item names.");
                        input_to("item_names");
                        x = 0;
                }
                else {
                        exit_paths = exit_paths + ({ str });
                        input_to("exit_paths");
                        x++;
                }
        }
}

void item_names(string str) {
        if(str == "") input_to("item_names");
        else if(str == "?") {
        	help("item_names");
        	return;
        }
        else if(str == "~q") {
        	start = 0;
        	return;
        }
        else {
                if(str == "**") {
                        write("Enter the item descs.");
                        input_to("item_descs");
                        x = 0;
                }
                else {
                        item_names = item_names + ({ str });
                        input_to("item_names");
                        x++;
                }
        }
}

void item_descs(string str) {
        if(str == "") input_to("item_descs");
        else if(str == "?") {
        	help("item_descs");
        	return;
        }
        else if(str == "~q") {
        	start = 0;
        	return;
        }
        else {
                if(str == "**") {
                        write("Enter smell description.\n");
                        input_to("smell_desc");
                        x = 0;
                }
                else {
                        item_descs = item_descs + ({ str });
                        input_to("item_descs");
                        x++;
                }
        }
}

void smell_desc(string str) {
        if(str == "") input_to("smell_desc");
        else if(str == "?") {
        	help("smell_desc");
        	return;
        }
        else if(str == "~q") {
        	start = 0;
        	return;
        }
        else {
                smell_desc = str;
                 write("Enter hear description.\n");
                input_to("hear_desc");
        }
}


void hear_desc(string str) {
        if(str == "") input_to("hear_desc");
        else if(str == "~q") {
        	start = 0;
        	return;
        }
        else if(str == "?") {
        	help("hear_desc");
        	return;
        }
        else {
                hear_desc = str;
                 write("Is your room indoors? (y/n) \n");
                input_to("indoors");
        }
}

void indoors(string str) {
        if(str == "") input_to("indoors");
        else if(str == "~q") {
        	start = 0;
        	return;
        }
        else if(str == "?") {
        	help("indoors");
        	return;
        }
        else {
                if(str == "y") {
                        indoors = 1;
                }
                if(view_room) preview_room(filename);
                if(prompt_before_saving) {
                	write("Do you wish to save this file? (y/n/~q)\n");
                	input_to("prompt_for_save");
                }	
                else {
                	write_room(filename);
                	write("Room ["+filename+"] written successfully.\n");
                	write("Would you like to make another room? (y/n) \n");
                	input_to("continue_build");
                }
        }
}

void prompt_for_save(string str) {
        if(str == "") input_to("prompt_for_save");
        else if(str == "?") {
        	help("prompt_for_saving");
        	start = 0;
        	return;
        }
        else if(str == "~q") {
        	start = 0;
        	return;
        }
        else {
                if(str == "y") {
                	write_room(filename);
                	write("Room ["+filename+"] written successfully.\n");
                	write("Would you like to make another room? (y/n) \n");
                	input_to("continue_build");
                }
                else {
                 	write("Would you like to make another room? (y/n) \n");
                	input_to("continue_build");
                }
        }
}
	
void continue_build(string str) {
        if(str == "") input_to("continue_build");
        else if(str == "?") {
        	help("continue_build");
        	start = 0;
        	return;
        }
        else if(str == "~q") {
        	start = 0;
        	return;
        }
        else {
                if(str == "y") {
                        start = 1;
                        menu();
                        seteuid(getuid());
                        count++;
                        return;
                }
                else start = 0;
                write("\n"+count+" rooms created in this session.");
                write("\nQuitting....\n_________________________________\n");
                count = 0;
        }
}

void write_room(string fname) {
  string f;
  int x,last;

  lastexit = sizeof(exit_names);
  lastitem = sizeof(item_names);
  f = fname;
  seteuid("Root");
  write(f);
  if(!write_file(f,"//	"+filename+"\n//	Written with the Online RoomMaker v0.9g\n")) {
  	write("Error writing file to disk, make sure that it is a valid\nfilename and not a directory.\n");
  	return;
  }
  write_file(f,"//	"+ctime(time())+"\n\n");
  write_file(f,"#include <std.h>\n");
  write_file(f,"#include <objects.h>\n\n");
  write_file(f,"inherit ROOM;\n\n");
  write_file(f,"void create() {\n");
  write_file(f,"    room::create();\n");
  write_file(f,"    set_light("+light+");\n");
  if(indoors == 1) write_file(f, "    set_indoors(1);\n");
  write_file(f,"    set_short(\""+short+"\");\n");
  write_file(f,"    set_long(\n");
  write_file(f,"@ONLINE09G\n");
  write_file(f,long_desc);
  write_file(f,"ONLINE09G\n");
  write_file(f,"    );\n");

  write_file(f,"set_smell(\"default\",\""+smell_desc+"\");\n");
  write_file(f,"set_listen(\"default\",\""+hear_desc+"\");\n");
  write_file(f,"    set_exits(([\n");
  for(x=0; x<lastexit; x++) {
    write_file(f,"       \""+exit_names[x]+"\" : \""+exit_paths[x]+"\"");
    if(lastexit-1==x) write_file(f,"\n");
      else write_file(f,",\n");
  }
  write_file(f,"    ] ));\n");
  write_file(f,"    set_items(([\n");
  for(x=0; x<lastitem; x++) {
    write_file(f,"       \""+item_names[x]+"\" : \""+item_descs[x]+"\"");
    if(lastitem-1==x) write_file(f,"\n");
      else write_file(f,",\n");
  }
  write_file(f,"    ] ));\n");

  write_file(f,"}\n");
  seteuid(getuid());
}

void help(string str) {
   string tmp;
    if(!str) return;
	switch(str) {
	  case "filename":
		tmp = read_file(HELPDIR+"filename_help");
		break;
	  case "short":
		tmp = read_file(HELPDIR+"short_help");
		break;
	  case "long":
		tmp = read_file(HELPDIR+"long_help");
		break;
	  case "exit_names":
		tmp = read_file(HELPDIR+"exitname_help");
		break;
	  case "exit_paths":
		tmp = read_file(HELPDIR+"exitpath_help");
		break;
	  case "item_names":
		tmp = read_file(HELPDIR+"itemname_help");
		break;
	  case "item_descs":
		tmp = read_file(HELPDIR+"itempath_help");
		break;
	  case "smell_desc":
		tmp = read_file(HELPDIR+"smell_help");
		break;
	  case "hear_desc":
		tmp = read_file(HELPDIR+"hear_help");
		break;
	  case "indoors":
		tmp = read_file(HELPDIR+"indoors_help");
		break;
	  case "light":
		tmp = read_file(HELPDIR+"light_help");
		break;
	  case "continue_build":
		tmp = read_file(HELPDIR+"continue_help");
		break;
	  default:
		str = "run_program";
		tmp = "There is no help screen for this option.\n";
		break;
	}
	write(tmp);
	input_to(str);
}
	
void menu() {
        if(!start) write(
@ONLINE10

ShadowGate Online RoomMaker v0.9g
Thorn@ShadowGate
_________________________________

ONLINE10
        );

	notify_fail(
@MAINMENU

mwmwmwmwmwmwmwmwmwmwmwmwmwm

Start a room..............s
Set Options...............o
General Help..............?

mwmwmwmwmwmwmwmwmwmwmwmwmwm

Version "G" ready.

MAINMENU
	);
	input_to("capture");
}

void capture(string str) {
	if(str == "") input_to("capture");
	switch(str) {
	  case "s":
		run_program();
		break;
	  case "o":
		set_options();
		break;
	  case "?":
		help("menu");
		break;
	  default:
	  	write("Invalid option.  Type \"?\" for help.\n\n");
	    input_to("capture");
	    break;
	}
}

void set_options() {
	write(
@OPTIONS

Options Menu
_____________________________

OPTIONS
	);
	write("Save rooms to ~/room dir....r    <"+default_dir+">");
	write("Prompt before saving........p    <"+prompt_before_saving+">");
	write("Admin privleges.............a    <"+admin_privs+">");
	write("Preview code before saving..v    <"+view_room+">");
	write("Main Menu...................m\n\n");


	input_to("capture_options");
}

void capture_options(string str) {
	if(str == "") input_to("capture_options");
	switch(str) {
	  case "r":
		if(default_dir) {
			write("Default directory disabled.\n");
			default_dir = 0;
		}
		else {
			write("Default directory enabled: [/realms/"+TPQN+"/room/]\n");
			default_dir = 1;
		}
		set_options();
		break;
	  case "p":
		if(prompt_before_saving) {
			write("Prompt before saving room option disabled.\n");
			prompt_before_saving = 0;
		}
		else {
			write("Prompt before saving room option enabled.\n");
			prompt_before_saving = 1;
		}
		set_options();
		break;
	  case "v":
		if(view_room) {
			write("View room in editor disabled.\n");
			view_room = 0;
		}
		else {
			write("View room in editor enabled.\n");
			view_room = 1;
		}
		set_options();
		break;
	  case "a":
		write("Command disabled for regular version.\n");
		set_options();
		break;
	  case "m":
		write(
@MAINMENU

mwmwmwmwmwmwmwmwmwmwmwmwmwm

Start a room..............s
Set Options...............o
General Help..............?

mwmwmwmwmwmwmwmwmwmwmwmwmwm

Version "G" ready.

MAINMENU
		);
		start = 1;
		menu();
		break;
	  case "?":
		help("set_options");
		break;
	  default:
	  	write("Invalid option.  Type \"?\" for help.\n\n");
	    input_to("capture_options");
	    break;
	}
}
	
void preview_room(string fname) {
  string f;
  int x,last;

  lastexit = sizeof(exit_names);
  lastitem = sizeof(item_names);
  f = fname;
  write("Previewing.... "+f+".\n\n\n");
  write("//	Preview of "+filename+"\n//	Written with the Online RoomMaker v0.9g");
  write("//	"+ctime(time())+"\n");
  write("#include <std.h>");
  write("#include <objects.h>\n");
  write("inherit ROOM;\n");
  write("void create() {");
  write("    room::create();");
  write("    set_light("+light+");");
  if(indoors == 1) write( "    set_indoors(1);");
  write("    set_short(\""+short+"\");");
  write("    set_long(");
  write("@ONLINE09G");
  write(long_desc);
  write("ONLINE09G");
  write("    );");

  write("set_smell(\"default\",\""+smell_desc+"\");");
  write("set_listen(\"default\",\""+hear_desc+"\");");
  write("    set_exits(([");
  for(x=0; x<lastexit; x++) {
    write("       \""+exit_names[x]+"\" : \""+exit_paths[x]+"\"");
    if(lastexit-1==x) write("");
      else write(",");
  }
  write("    ] ));");
  write("    set_items(([");
  for(x=0; x<lastitem; x++) {
    write("       \""+item_names[x]+"\" : \""+item_descs[x]+"\"");
    if(lastitem-1==x) write("");
      else write(",");
  }
  write("    ] ));\n");
  write("}\n\n\nPreview completed.\n_________________________\n");
}
