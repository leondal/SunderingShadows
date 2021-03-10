// grease - modified from caltrops.
#include <std.h>
#include <daemons.h>
inherit OBJECT;

string exit;
object spell;
int castlevel, set;

void create(){
	::create();
	set_name("grease");
	set_id(({"grease","patch","patch of grease","spellgrease999"}));
	set_short("%^BOLD%^%^BLACK%^patch of grease%^RESET%^");
	set_long("This puddle of grease is slick and shiney.  It obscures no exit.  Likely it would take good footing to "
"avoid slipping on it.");
      set_weight(99999);
	set_value(0);
      set_property("no offer",1);
}

void init(){
	::init();
      if(!set) {
		if(query_trap_status("grease")) toggle_trap("grease");
		clear_all_traps(({}));
            set = 1;
	}
}

int spread(string str, int clevel, object spellob, object location){
	if(!objectp(location)){
		TO->remove();
		return 1;
	}
	if(member_array(str,  location->query_exits()) == -1){
		TO->remove();
		return 1;
	}
	set_trap_functions(({"grease"}),({"tripUm"}),({str}));
      exit = str;
      spell = spellob;
      castlevel = clevel;
	set_long("This puddle of grease is slick and shiney.  It obscures the "+str+" exit.  Likely it would take good "
"footing to avoid slipping on it.");
	return 1;
}

string query_exit() { return exit; }

int tripUm(){
    if(!objectp(TP)) return 1;
    if(TP->query_tripped()) return 0;
    if(SAVING_D->reflex_save(TP,(-1)*castlevel)) {
      write("You walk carefully over the patch of grease, maintaining your balance enough to move on.");
      tell_room(ETP,TP->QCN+" walks carefully over the patch of grease and continues on.");
    }
    else {
      write("As you walk "+query_verb()+" your feet suddenly slip on a patch of grease.");
      write("Your feet fly out in front of you and you find yourself falling flat on your back.");
      write("The shock of the landing has left you stiff as you try to scramble to your feet.");
      TP->do_damage(TP->return_target_limb(),roll_dice(2,4));
      TP->set_tripped(2,"The grease has tripped you up.",2);
      tell_room(ETP,"As "+TPQCN+" walks "+query_verb()+" "+TP->QS+" suddenly slips on a patch of grease,",TP);
      tell_room(ETP,TP->QP+" feet go flying up in the air and "+TP->QS+" lands hard on the ground.",TP);
    }
    if(!trapped(query_verb())) toggle_trap(query_verb());
    add_hidden_seen(TP);
    if(objectp(spell)) spell->dest_effect();
    if(objectp(TO)) TO->remove();
    return 1;
}

int detrigger(){
    if(!objectp(TO)) return 1;
    if(!trapped(query_verb())) toggle_trap(query_verb());
    tell_room(ETO,"The patch of grease shimmers and disappears.");
    TO->remove();
    return 1;
}