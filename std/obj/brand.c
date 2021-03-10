#include <std.h>

inherit OBJECT;

string owner;
void create() {
    set_name("monster brand");
    set_id( ({ "monster brand" }));
}

int drop() { return 1; }

int get() { return 0; }

string extra_look() {
    string nom;

    nom = environment(this_object())->query_cap_name();
    if(!nom) return 0;
    return nom+" has been claimed for battle by "+owner+".\n";
}
void init_brand(string str, int time) {
    if(time < 1) {
	remove();
	return;
    }
    owner = str;
    call_out("end_brand", time);
}

void end_brand() { remove(); }
