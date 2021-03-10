//adapted from the stonechip on Tonerra

#include <std.h>

inherit OBJECT;

int count;

void create(){
	::create();
	set_name("small barb");
	set_id(({"barb","small barb","small black barb"}));
	set_short("Small black barb");
	set_long("This vicious-looking black barb seems to "+
         "have broken off and worked its way into the wound.  "+
         "It almost seems to move on its own and is causing "+
         "a great deal of pain.  You might be able to extract "+
         "it if you dare.");
	set_value(0);
	set_weight(0);
	
	count = 0;
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
	
	}

int extract(){
	tell_object(TP,"%^BOLD%^%^RED%^You slowly extract the barb "+
         "from your wound, ripping flesh and tissue.");
	tell_object(TP,"%^BOLD%^YOU SCREAM IN AGONY!");
	tell_room(ETP,"You see "+TPQCN+" pull a small black barb from "+
         ""+TP->QP+" wound!",TP);
	tell_room(ETP,"%^BOLD%^"+capitalize(TP->QS)+" screams in pain.",TP);
      tell_room(ETP,"%^BOLD%^%^BLACK%^The barb vanishes in a wisp "+
         "of black dust.");
	TP->do_damage("torso",roll_dice(2,5));
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
	tell_object(tp,"%^BOLD%^%^RED%^You feel intense pain as "+
         "the barb works its way deeper into your flesh!");
      tell_room(environment(tp),"%^BOLD%^%^RED%^"+tp->QCN+" screams "+
         "out in pain!",tp);
	tp->do_damage("torso",roll_dice(2,5));
	call_out("hurt",20,tp);
	if(count>4 && !interactive(tp)){
		tp->force_me("extract barb");
	}
	count++;
}

int my_give(string str){
	if(id(str)) return 1;
	}
	
