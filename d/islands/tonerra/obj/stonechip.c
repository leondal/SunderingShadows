//stonechip.c

#include <std.h>

inherit OBJECT;

int blah;

void create(){
	::create();
	
	set_name("stone chip");
	set_id(({"chipformastonedagger","chip"}));
	set("short","Stone Chip");
	set("long",
@OLI
	This stone chip seems to have flaked off a stone weapon
The white flakes have sharp edges. They are infecting the wound 
and causing a great deal of pain. Extracting it would be better
than leaving it in the wound, you think.
OLI
	);
	set_value(0);
	set_weight(0);
	
	blah = 0;
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
        if(!userp(ETO)) TO->remove();
	}

int extract(){
	write("%^BOLD%^%^GREEN%^You slowly extract the stone chip from your wound.");
	write("%^BOLD%^%^YELLOW%^ YOU SCREAM IN AGONY!");
	tell_room(environment(TP),"You see "+TPQCN+" pull a stone chip from "+TP->query_possessive()+" wound!",TP);
	tell_room(environment(TP),"%^BOLD%^%^YELLOW%^"+capitalize(TP->query_subjective())+" screams in pain.",TP);
	TO->remove();
	return 1;
}

void hurt(object tp){
	if(!objectp(tp)){
		remove();
		return;
	}
if(tp->query_ghost()){
    remove();
      return;
  }
	tell_object(tp,"%^BOLD%^Seering pain from the chip of stone in your wound races through your body!\n");
	tp->do_damage("torso",roll_dice(2,5));
	call_out("hurt",20,tp);
	if(blah >4 && !interactive(tp)){
		tp->force_me("extract chip");
	}
	blah++;
}

int my_give(string str){
	if(id(str)) return 1;
	}
	
