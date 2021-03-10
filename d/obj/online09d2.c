//      Online RoomMaker for ShadowGate v0.9d
//      Thorn@ShadowGate
//      4/4/95
//      Builder Tools
//      online09d.c

string filename, short, hear_desc;
string long_desc, smell_desc;
string light;
string *exit_names, *exit_paths;
string *item_names, *item_descs;
string help_file;
int x, smell, hear, indoors;
int lastexit, lastitem, start;
int count;

void filename(string str);
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

#include <std.h>
#include <security.h>

inherit OBJECT;

void create() {
        ::create();
        set_name("RoomMaker for ShadowGate");
        set_id( ({ "roommaker", "room object" }) );
        set_short("A RoomMaker");
        set_long("RoomMaker for ShadowGate v0.9d.\nType <go> to begin the program.\n");
        set_weight(10);
        set_value(1);
        x = 0;
        indoors = 0;
        count = 1;
        start = 0;
        exit_names = ({});
        exit_paths = ({});
        item_names = ({});
        item_descs = ({});
}

void init() {
        ::init();
        add_action("run_program", "go");
}

void run_program() {
        indoors = 0;
        x = 0;
        exit_names = ({});
        exit_paths = ({});
        item_names = ({});
        item_descs = ({});
        long_desc = "";

        if(!start) write(
@ONLINE10

ShadowGate Online RoomMaker v0.9d
Thorn@ShadowGate
_________________________________


Test version 'D' ready.


ONLINE10
        );
        else write(
@ONLINE09D

Ready for next room.
_________________________________

ONLINE09D
		);
		if(!start) count = 1;
        start = 1;
        notify_fail("Enter the filename: \n");
        input_to("filename");
}

void filename(string str) {
		int clean;
		string tmp;
		
        if(str == "") input_to("filename");
        else if(str == "?") {
        	filename_help();
        	return;
        }
        else {
                filename = str;
                clean = sizeof(filename);
                if(sscanf(filename, "~%s", tmp) == 1) {
                	filename = "/realms/"+TPQN+"/"+tmp;
                	write(filename+"\n");
                }
                write("How much light is there in the room?");
                write("NOTE: 2 is normal.  Less is darker (even negative numbers),\nmore is brighter.\n");
                input_to("light");
        }
}

void light(string str) {
        if(str == "") input_to("light");
        else {
                light = str;
                write("Enter the short description.");
                input_to("short");
        }
}

void short(string str) {
        if(str == "") input_to("short");
        else {
                short = str;
                write("Enter the long description.\n");
                input_to("long");
        }
}

void long(string str) {
        if(str == "") input_to("long");
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
        else {
                smell_desc = str;
                 write("Enter hear description.\n");
                input_to("hear_desc");
        }
}


void hear_desc(string str) {
        if(str == "") input_to("hear_desc");
        else {
                hear_desc = str;
                 write("Is your room indoors? (y/n) \n");
                input_to("indoors");
        }
}

void indoors(string str) {
        if(str == "") input_to("indoors");
        else {
                if(str == "y") {
                        indoors = 1;
                }
                write_room(filename);
                write("Room ["+filename+"] written successfully.\n");
                write("Would you like to make another room? (y/n) \n");
                input_to("continue_build");
        }
}

void continue_build(string str) {
        if(str == "") input_to("continue_build");
        else {
                if(str == "y") {
                        start = 1;
                        run_program();
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
  seteuid("RoomMakerSave");
  write(geteuid());
  write(f);
  write_file(f,"//	"+filename+"\n//	Written with the Online RoomMaker\n");
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
  write_file(f,"@ONLINE09D\n");
  write_file(f,long_desc);
  write_file(f,"ONLINE09D\n");
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

void filename_help() {
	string tmp;
	tmp = read_file("/realms/thorn/help/filename_help");
	write(tmp);
	input_to("filename");
}
