//Betting stub LoKi 2011

#include <std.h>
#include "../horse.h"
inherit OBJECT;

int value, uid, check, id_set;


void init() {
   ::init();
   add_action("how_much","examine");
}


void create(){
    ::create();
    set_name("betting stub");
    set_id(({"ticket","paper","horse_ticket","stub"}));
    set_short("%^RESET%^%^ORANGE%^A betting stub%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This stub of paper is from the "+
	"horse races. It has been written out on special paper to "+
	"eliminate risks of counterfitting. You can '%^RESET%^examine%^ORANGE%^' "+
	"it closer to see how much the bet was for. You can also '%^RESET%^"+
	"claim%^ORANGE%^' at the proper place.\n%^RESET%^\n\n");
    set_weight(1);
    set_value(1);
}

void set_value(int value_requested){
    value = value_requested;
}

void set_uid(int uid_requested){
    uid = uid_requested;
}

void set_race_id(int race_id_set){
    id_set = race_id_set;
}

int check_race_id(){
    return id_set;
}

int check_uid(){
    return uid;
}

int check_value(){
    return value;
}

int how_much(string str){
    if(str != "stub"){
        return 0;
    }
	check  = uid * 10;
    tell_object(TP, "%^RESET%^%^ORANGE%^This betting stub is for "+
	"horse "+uid+" and was a bet of "+value+" gold. It has a serial number of "+id_set+". ");
    return 1;
}