
#include <std.h>
#include "items.h"
#include <move.h>


inherit OBJECT;

string FILE;
string type;
string name;

void finish();

void exit() {
    	rm(FILE);
	if(TEMP(TPQN)) 
	{
		TEMP_REMOVE(TPQN);
	}
    	remove();
}


void set_file_name(string f) {
    FILE = f;
}

void set_object_type(string t) {
    type=t;
}

void set_name(string n) {
    name = n;
}

void init() {
    ::init();
    write("Please enter the maximum weight allowable by the pocket.");
    write("Note: these numbers should be kept small, with specific items in mind.");
    write("Bags, especially those that can be worn, are especially balance effecting.");
    input_to("encumbrance");

}

void encumbrance(string str){
    object ob;
    if(!str){

        write("Please enter the maximum weight allowable by the pocket.");
        write("Note: these numbers should be kept small, with specific items in mind.");
        write("Bags, especially those that can be worn, are especially balance effecting.");
        input_to("encumbrance");
        return 1;
    }
    if(str == "**") return exit();
    WF(MAX_ENC(str));

    ob = new("/cmds/avatar/armor2");
    ob->set_object_type(type);
    ob->set_file_name(FILE);
    ob->set_name(name);

    ob->move(TP);
    remove();
}
