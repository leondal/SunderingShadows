//stonechip.c

#include <std.h>

inherit OBJECT;

int blah;

void create(){
	::create();
	
  set_name("leech");
  set_id(({"%^BOLD%^%^BLACK%^a writhing black leech"}));
  set_short("%^BOLD%^%^BLACK%^a writhing black leech");
  set_long("%^BOLD%^%^BLACK%^This tiny monstrosity is a terror to behold. "+
  "Its skin is black and drips with repulsive sewage slime. "+
  "Most horrible is the ring of dozens and dozens of %^WHITE%^sharp "+
  "teeth%^BOLD%^%^BLACK%^ inside its terrible mouth. The thing writhes around, "+
  "looking for its next taste of blood and flesh. Having to %^BOLD%^%^RED%^<tear>%^BOLD%^%^BLACK%^ "+
  "this monster away from your flesh would likely cause massive "+
  "amounts of pain.%^RESET%^");
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
	
	add_action("tear","tear");
	add_action("my_give","give");
	add_action("my_give","offer");
        if(!userp(ETO)) TO->remove();
	}

int tear(){
	write("%^RESET%^%^RED%^You excruciatingly tear the squirming leech from your flesh!%^RESET%^");
	write("%^BOLD%^%^RED%^Blood spills from the throbbing wound.%^RESET%^");
	tell_room(environment(TP),"RESET%^%^ORANGE%^You see "+TPQCN+" yank a leech from "+TP->query_possessive()+" body, spilling blood everywhere!%^RESET%^",TP);
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
	tell_object(tp,"%^RESET%^%^ORANGE%^The leech painfully latches on with its rows of razor teeth! %^BOLD%^%^RED%^Tear%^RESET%^%^ORANGE%^ it away before it sucks you dry!\n");
	tp->do_damage("torso",roll_dice(1,3));
	call_out("hurt",10,tp);
	if(blah >4 && !interactive(tp)){
		tp->force_me("tear leech");
	}
	blah++;
}

int my_give(string str){
	if(id(str)) return 1;
	}
	
