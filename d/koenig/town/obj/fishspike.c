//fishspikes.c

#include <std.h>

inherit OBJECT;

void create(){
	::create();
	
	set_name("Spike");
	set_id(({"fishspikefromdragonfish","spike"}));
	set("short","A long spike from the dragon fish");
	set("long",
@PEG
	%^BOLD%^%^BLUE%^This spike hs lodged itself inside your foot. With every movement
You make PAIN rushes up from you foot. You can feel the poison that it holds
welling through you blood. You really should <extract> it.
PEG
	);
	set_value(0);
	set_weight(1);
}

int drop(){
	return 1;
	}

int give(){
	return 1;
	}
	
void init(){
	::init();
	
	add_action("extract","extract");
	add_action("my_give","give");
	add_action("my_give","offer");
	if(interactive(TP)) call_out("hurt",10, TP);
	}

int extract(){
	write("%^BOLD%^%^GREEN%^You slowly extract the spike from you foot.");
	write("%^BOLD%^%^YELLOW%^ YOU SCREAM IN AGONY!");
	tell_room(environment(TP),"You see "+TPQCN+" pull a spike from "+TP->query_possessive()+" foot!",TP);
	tell_room(environment(TP),"%^BOLD%^%^YELLOW%^"+capitalize(TP->query_subjective())+" screams in pain.",TP);
	TO->remove();
	return 1;
}

void hurt(object tp){
	tell_object(tp,"%^BOLD%^Seering pain from the spike in your foot races you your leg!\n");
	tp->do_damage("torso",1);
	call_out("hurt",10,tp);
}

int my_give(string str){
	if(id(str)) return 1;
	}
	
