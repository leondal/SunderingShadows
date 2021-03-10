#include "/d/shadow/room/city/cguild/ranger/ranger.h"
//special thanks to Kassad for this!
//converting tripwires and caltrops
//into custom trap kit objects - Saide

inherit OBJECT;
int trap_setter;
string MyExit;

void create()
{
	::create();	
   	set_name("snare trap");
   	set_id(({"trip wire","wire","trap","tripwire"}));
   	set_short("%^BOLD%^Trip Wire%^RESET%^");
	set_long(
@TERRATO
   This is a razor sharp tripwire normally used for hunting. Simply <rig>
the wire across the exit you want to trap and the next time somebody tries
to go in that direction the wire will entwine itself around the victim's
feet, hopefully immobilizing them.
TERRATO
	);
   	set_weight(2);
	set_value(100);
}

void init()
{
	::init();	
	if(TP == ETO) 
	{
       	set_short("%^BOLD%^Trip Wire%^RESET%^");
        	add_action("rig","rig");
	}	
}


void set_origin_object(string str) { MyExit = str; }
int query_dc() { return 1; }
void set_my_dc(int x) { return; }
void set_trap_setter(int x) { trap_setter = x; }


void backfire(object who)
{
	if(!objectp(who)) return;
	if(!objectp(environment(who))) return;
	tell_object(who, "%^RED%^Oh NO!  As you're trying to rig the trip wire "+
	"you get all tangled up in it!%^RESET%^");
	
	tell_object(who, "%^ORANGE%^Struggling to get out of the "+
	"tangled mess, you end up falling flat on your face, the "+
	"wire wrapped around you!%^RESET%^");
	
	who->set_tripped(roll_dice(1,2),"%^BLUE%^You are struggling to get "+
	"untangled and back to your feet!%^RESET%^");

	tell_room(environment(who), who->QCN+"%^BLUE%^ seems to be working "+
	"with a wire... and manages to become all tangled up in it!%^RESET%^", who);

	tell_room(environment(who),who->QCN+"%^ORANGE%^ struggles to get out of the "+
	"tangled mess and ends up falling flat on "+who->QP+" face, the wire "+
	"wrapped around "+who->QO+"!%^RESET%^", who);
	return;
}
	


int rig(string str)
{
	string exit;
	if(!str) 
	{
      	write("rig trip wire <exit>");
		return 1;
	}
      if(sscanf(str,"trip wire %s",exit) != 1) 
	{
      	write("rig trip wire <exit>");
		return 1;
        }
        write("The tripwire snaps - someone must have sabotaged it!");
        TO->remove();
        return 1;
// preventing these from working anymore as they are disabled. Adding feats for the rogueish sorts for tools only, rangers don't need 'em. N, 4/15
	if(member_array(exit,  ETP->query_exits()) == -1)
	{
		write("That exit does not exist.");
		return 1;
	}

	MyExit = exit;
	if(ETP->is_trapped(exit)) 
	{
		if(ETP->execute_trap(exit, TP, 1))
		{
			backfire(TP);
			TO->remove();
			return 1;
		}
	}

	if(ETP->is_this_trapped(exit)) 
	{
		backfire(TP);
		TO->remove();
		return 1;
	}
	
	//1 is important because it tells the code that a player 
	//set this trap - other stuff dictates its your trap 
	//and you wont trigger it 
	ETP->set_trapped(({MyExit}), ({"custom"}), ({base_name(TO)}), 1);
	ETP->add_passed_check(MyExit, TPQN);
	ETP->set_trap_set_by(MyExit, TPQN, 1);
	ETP->add_known_to(MyExit, "player", TPQN);

      write("%^BLUE%^You lay the trip wire across an exit hoping to catch "+
	"prey going "+exit+".");
	
	if(!TP->query_invis())
	{
      	tell_room(ETP,"You see "+TPQCN+
		" rig something out toward the "+exit+" direction.",TP);
	}
	TO->remove();
	return 1;
}	

void trap_activated(object who)
{
	object obj;
   	if(!objectp(who)) return;
   	if(objectp(obj = who->query_in_vehicle()))
	{
      	tell_object(who, "%^BOLD%^As you ride "+MyExit+
		" your mount suddenly trips!");
      	tell_object(who, "%^BOLD%^%^You fall off balance and find yourself "+
		"flat on your face!");
      	tell_object(who, "%^ORANGE%^The shock of the landing has left you "+
		"%^RESET%^%^BOLD%^stiff%^RESET%^%^ORANGE%^ as you try to scramble "+
		"to your feet!");
      	who->set_tripped(roll_dice(1,2),"%^BLUE%^You are struggling to get "+
		"back onto your feet!");
      
		tell_room(environment(who),"%^BLUE%^%^BOLD%^As "+who->QCN+
		" rides "+MyExit+" "+who->QP+" mount suddenly trips.",who);
	
	      tell_room(environment(who),"%^BLUE%^%^BOLD%^"+who->QCN+
		" falls off and lands flat on "+who->QP+" face!",who);
		obj->do_damage("torso",roll_dice(1,10));
      	who->force_me("dismount "+((string *)obj->query_id())[0]);
	      obj->set_tripped(1,"Ouch!!!");
   	}
   	else 
	{
   		tell_object(who, "%^BOLD%^%^Your feet %^YELLOW%^fly%^RESET%^"+
		"%^BOLD%^ out from under you and you find youself flat on your face!");
	
   		tell_object(who, "%^RED%^You feel the %^BOLD%^pain%^RESET%^%^RED%^ of a wire "+
		"wrapped around your legs!");
		
		tell_object(who, "%^ORANGE%^The shock of the landing has left "+
		"you %^RESET%^%^BOLD%^stiff%^RESET%^%^ORANGE%^ as you try to scramble to "+
		"your feet!");

		who->set_tripped(roll_dice(1,2),"%^BLUE%^You are struggling to get free "+
		"and back onto your feet!");

		tell_room(environment(who),"%^BLUE%^%^BOLD%^As "+who->QCN+
		" walks "+MyExit+" "+who->QS+" suddenly slips.",who);

		tell_room(environment(who),"%^BLUE%^%^BOLD%^"+who->QCN+
		" goes flying into the air and "+who->QCN+
		" begins struggling on the ground!",who);
   	}
	return 1;
}

