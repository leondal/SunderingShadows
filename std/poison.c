//      /std/poison.c
//      from the Nightmare mudlib
//      a standard object for allowing things to be tainted with poison
//      necessary to make sure rogues get the bonus of it
//      created by Descartes of Borg 15 may 1993

#include <std.h>

inherit OBJECT;

int poisoning, max_poisoning;

void init() {
    add_action("poison", "poison");
}

int poison(string str) {
    object ob;
    int total, murder;

    if(environment(this_object()) != this_player()) {
        notify_fail("You must have the poison to do that.\n");
        return 0;
    }
    if(!str) {
        notify_fail("Poison what?\n");
        return 0;
    }
    if(!poisoning) return 0;
    ob = present(lower_case(str), this_player());
    if(!ob) ob = parse_objects(this_player(), lower_case(str));
    if(!ob) {
        notify_fail("You do not have that!\n");
        return 0;
    }
    murder = (int)this_player()->query_skill("murder");
    if(murder < 15) {
        write("You spill poison all over the place.\n");
        say(this_player()->query_cap_name()+" spills poison everywhere.\n");
        poisoning = 0;
    }
    total = random(poisoning +1);
    poisoning -= total;
    set("value", to_int(percent(poisoning, max_poisoning)*to_float(query("value")))+10);
    ob->add_poisoning(to_int((to_float(murder)/100.0)*to_float(total)));
    write("You place some poison on the "+str+".\n");
    say(this_player()->query_cap_name()+" dips "+this_player()->query_possessive()+" "+str+" in poison.\n");
    return 1;
}

string query_short() {
    string tmp;
    int x;

    tmp = ::query_short();
    x= to_int(percent(poisoning, max_poisoning+1));
    if(!poisoning) tmp += " (empty)";
    else if(x < 50) tmp += " (partially empty)";
    else if(x < 95) tmp += " (nearly full)";
    else tmp += " (full)";
    return tmp;
}

void set_poisoning(int x) {
    poisoning = max_poisoning = x;
}

int query_poisoning() { return poisoning; }

void add_poisoning(int x) { 
    poisoning += x;
    if(poisoning < 1) poisoning = 0;
}
