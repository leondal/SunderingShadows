#include <std.h>

inherit OBJECT;

string spell, args;
object myweapon;
int prof;

void set_myweapon(object obj);
void query_myweapon();


void create() {
    ::create();
    set_name("exigency");
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
    add_action("release","release");
}

set_prof(int i) {
    prof = i;
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

int release() {
    object spellobj,weapon;
    string *myids;
    int level;
    if(!spell) return 0;
    if(flag) return 0;
    flag = 1;

//leaving this for now
    if(TP->is_class("psion")) {
        if(!TP->is_ok_armour("mage")) {
            write("The spell conflicts with your armor and dies");
            call_out("remove",1);
            return 1;
        }

    }
    weapon = TO->query_myweapon();
    if(!objectp(weapon)){
       tell_object(TP,"The weapon you empowered is missing, and the power fails.");
       tell_object(TP,"Error in objectp check.");
       remove();
       return 1; 
    }
/*
    if(!deep_present(weapon,TP)){
       tell_object(TP,"The weapon you empowered is missing, and the power fails.");
       tell_object(TP,"Error in present check.");
       remove();
       return 1;
    }
*/
    if(!weapon->query_property("empowered_weapon")){
       tell_object(TP,"For some reason, your weapon is no longer empowered.");
       remove();
       return 1;
    }

    if(TP->is_class("psywarrior")){
       level = TP->query_guild_level("psywarrior");
    }else{
       level = TP->query_guild_level("psion");
    }
    spellobj = new(spell);
    if(prof >= 100) {
        if(!stringp(args)) {
            spellobj->use_spell(TP,TP->query_name(),level, prof);
        }
        else {
            spellobj->use_spell(TP,args,level, prof);
        }
    }
    else if(prof < random(100)) {
        if(!stringp(args)) {
            spellobj->use_spell(TP,TP->query_name(),level, prof);
        }
        else {
            spellobj->use_spell(TP,args,level, prof);
        }
    }
    else {
        if(!stringp(args)) {
            spellobj->use_spell(TP,TP->query_name(),level, prof);
        }
        else {
            spellobj->use_spell(TP,args,level, prof);
        }
    }

    call_out("remove",1);
    return 1;
}

int drop() {
   return 1;
}

void set_myweapon(object obj){
   myweapon = obj;
   return;
}

void query_myweapon(){
   return myweapon;
}

int is_detectable() { return 0; }
int query_invis() { return 1; }

