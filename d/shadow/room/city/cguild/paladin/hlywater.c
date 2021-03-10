//changed to use tell_object and tell_room rather than notify_fail.  Circe 12/24/03
//
// Holy Water
// Coded by Grazzt@Shadowgate
//
#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("holy water");
    set_id(({
	"vial","holy water","water","vial of holy water","vial of water"
    }));
    set_short("vial of holy water");
    set_long(
	"This is a vial of holy water created by a high level cleric. "
	"It is used by clerics and paladins against undead and utter "
	"evil. Syntax: throw vial at <target>."
    );
    set_value( 0 );
    set_weight( 10 );
}
void init() {
    ::init();
    add_action("throw_fun","throw");
}
int throw_fun(string str) {
    string who;
    object target;
     if(!TP->is_class("paladin") && !TP->is_class("cleric") ) {
	tell_object(ETO,"This is not for you!\n");
	return 0;
    }	
    if(!str) {
        tell_object(ETO,"Syntax: throw vial at <target>\n");
        return 0;
    }
    if(sscanf(str,"vial at %s",who) != 1) {
        tell_object(ETO,"Syntax: throw vial at <target>\n");
        return 0;
    }	
    if(!(target = present(who,environment(TP)))) {
        tell_object(ETO,"No such target present!\n");
        return 0;
    }	
    if((string)target->query_race() != "undead" &&
       (string)target->query_race() != "skeleton" &&
       (string)target->query_race() != "zombie" &&
       (string)target->query_race() != "ghoul" &&
       (string)target->query_race() != "shadow" &&
       (string)target->query_race() != "wight" &&
       (string)target->query_race() != "ghast" &&
       (string)target->query_race() != "wraith" &&
       (string)target->query_race() != "spectre" &&
       (string)target->query_race() != "vampire" &&
       (string)target->query_race() != "ghost" &&
        target->query_property("undead") == 0 &&
       (string)target->query_race() != "lich") {
	notify_fail("It would appear this creature is actually not\n"
	            "classified racially as a known undead type. Current\n"
	            "valid undead types are: Skeleton, Zombie, Ghoul,\n"
		    "Shadow, Wight, Ghast, Wraith, Spectre, Vampire,\n"
		    "Vampyre, Ghost and Lich.\n"
	);
	return 0;
    }
    TP->set_paralyzed(3,"You are busy doing something else.");
    tell_room(ETP,
        "%^BOLD%^%^YELLOW%^"+TPQCN+" hurls a vial of liquid "
        "at "+target->query_cap_name()+"!%^RESET%^"    
    ,({TP,target}));
    tell_object(TP,
        "%^BOLD%^%^YELLOW%^You hurl a vial of "
        "%^WHITE%^holy water%^YELLOW%^ at "
        +target->query_cap_name()+
        "!%^RESET%^"
    );
    tell_object(target,
        ""+TPQCN+" just threw a vial of holy water on you!"
        "Strange, this is meant to be used on undead creatures...not "
        "players...so if you see this message you are either trapped "
        "in an undead creatures body or the item is bugged."
    );
    tell_room(ETP,"%^BOLD%^%^WHITE%^The undead before you writhes in agony as the holy water "+
        "burns into its body!");
    target->do_damage("torso",roll_dice(2,6));
    if(!target->kill_ob(TP,0)) TP->kill_ob(target,0);
        target->set_parlyzed(18+random(18),"Bug report if seen!!!");
        TO->remove();
        return 1;
}
