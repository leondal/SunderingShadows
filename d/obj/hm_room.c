#include <std.h>
#include <security.h>
#include <dirs.h>

inherit ROOM;

private string *__Clones;
private string __SaveFile, __Owner;

nomask void set_save_file(string str);
nomask void do_save();

void create() {
    ::create();
    __Clones = ({});
}

void reset() {
    object ob;
    int i;

    ::reset();
    if(!__Clones || !(i=sizeof(__Clones))) return;
    while(i--) {
        catch(ob = new(__Clones[i]));
        if(ob) ob->move(this_object());
    }
}

nomask void set_save_file(string str) {
    if(geteuid(previous_object()) != UID_HM) return;
    __SaveFile = str;
    do_save();
}

nomask void set_owner(string str) {
    if(geteuid(previous_object()) != UID_HM) return;
    __Owner = str;
}

nomask void do_save() {
    save_object(__SaveFile);
}

nomask void setup(string file) {
    if(geteuid(previous_object()) != UID_HM) return;
    restore_object(file);
}

void add_clone(string file) {
    object ob;

    if(!file_exists(file) && !file_exists(file+".c")) return;
    if(catch(ob=new(file))) return;
    seteuid(UID_LOG);
    log_file("castles", file+" added to "+__Owner+"'s file: "+__SaveFile+
      " by "+file_name(previous_object())+"("+geteuid(previous_object())+")\n");
    seteuid(getuid());
    ob->move(this_object());
    __Clones += ({ file });
}

string query_owner() { return __Owner; }

string query_save_file() { return __SaveFile; }

string *query_clones() { return __Clones; }
