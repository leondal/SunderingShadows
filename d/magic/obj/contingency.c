#include <std.h>
#include <daemons.h>
inherit OBJECT;

string spell, args;
int prof;
int level;

void create() {
    ::create();
    set_name("contingency");
    set("id", ({ "remotexoli"}) );
    set("short", "");
    set("long", "");
    set_property("no animate", 1);
    set_weight(0);
}

int clean_up()
{
    if(!objectp(TO)) { return 1; }
    if(objectp(ETO)) { return 1; }
    destruct(TO);
    return 1;
}

void init() {
    ::init();
    add_action("now","now");
}

set_clevel(int i) {
    level = i;
}

int get_prof() {
    return prof;
}

set_spell(string xxx) {
    spell = xxx;
}

set_args(string arg) {
    args = arg;
}


int save_me(string str) {
    return 1;
}
int flag =0;
int now() {
    object spellobj;
    object *armor;

    if(!spell) return 0;
    if(flag) return 0;
    flag = 1;

    if(!deep_present("statue of "+capitalize(TP->query_name()),TP)){
	write("The image of yourself is missing, the contingency fails.\n");
      remove();
       return 1;
    }

    spellobj = new(spell);

    if(!stringp(args) || args == "") {
        spellobj->use_spell(TP,"",level, 100,"mage");
    }
    else {
        spellobj->use_spell(TP,args,level,100,"mage");
    }

    call_out("remove",1);
    return 1;
}

int drop() {
   return 1;
}

int is_detectable() { return 0; }
int query_invis() { return 1; }
