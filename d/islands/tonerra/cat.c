//jungle island inheritable
//lava.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit "/std/room.c";

string what;
object room;

int flag;
void create(){
   ::create();
   set_travel(BACK_ALLEY);
   set_terrain(BUILT_TUNNEL);
   set_property("used sticks",1);
}

void reset(){
	object *temp,ob;
	int i;
	string *str,dir;
	::reset();
	
	if(!pointerp(TO->query_exits()) || !sizeof(TO->query_exits())){
		flag =1;
		
		return;
	}
	if(!present("bad boy")){
		if(!random(4)){
			
		     str = (string *)TO->query_exits();
		     dir = str[random(sizeof(str))];
		     set_trap_functions(({dir}),({"monks"}),({dir}));	
		     add_item("beam","This magic beam seems to be warding the "+dir+".");			
		     what = "monks&"+dir;
		
 		}
	}
}

	


int monks(){
	string verb;
	object ob,*inven,tmp;
	int i,j,k,l;
	
	verb = query_verb();

	tell_room(TO,"%^BOLD%^As "+TPQCN+" wanders "+verb+" "+TP->query_subjective()+" is shocked and the skeletons of the dead come to life.",TP);
	tell_object(TP,"%^BOLD%^As you walk "+verb+" You are shocked by a magic beam and are attacked by the skeletons of the dead");
	inven = all_living(TO);
	l = sizeof(inven);
	ob= new(MON+"mskel");
	ob->add_id("bad boy");
	ob->move(TO);
	for(k=0;k<l;k++){
		ob->kill_ob(inven[k],1);
	}
	ob= new(MON+"mskel");
	ob->add_id("bad boy");
	ob->move(TO);
	for(k=0;k<l;k++){
		ob->kill_ob(inven[k],1);
	}
	ob= new(MON+"mskel");
	ob->add_id("bad boy");
	ob->move(TO);
	for(k=0;k<l;k++){
		ob->kill_ob(inven[k],1);
	}

	TP->set_paralyzed(random(40)+20,"The old and dead magic has shocked your system.");

	
		 	
	toggle_trap(verb);
	return 1;
}

void init(){
	if(flag){
		::reset();
		flag =0;
	}
	::init();
}

string query_long(string str){
	string hold,one,two;
	
	hold = ::query_long(str);
	
	if(!what) return hold;
	
	sscanf(what,"%s&%s",one,two);
	if(!one || !trapped(two)) return hold;
	
	switch (one){
		case "monks":
			hold += "You see a faint beam in the dust that's been kicked up.";
			return hold;
			break;
	}

	return hold;
}
