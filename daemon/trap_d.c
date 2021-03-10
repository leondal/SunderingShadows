#include <std.h>
#include <daemons.h>
#define TRAP_DIRS "/d/common/obj/traps/base/"
#define VALID_TRAP_LEVELS ({"low", "mid", "high", "epic"})
inherit DAEMON;

int find_func(mapping set_trap, object to, object tp, string what){
    int score, percent;
    if(!tp->is_class("thief") && !tp->is_class("assassin")){
      	tell_object(tp,"%^BOLD%^You can't do that!");
      	return 1;
  	}
	if(!set_trap[what]) {
      	notify_fail("You do not find a trap there.\n");
      	return 0;
 	}
  	if(tp->query_armour("torso"))
     	score = tp->query_thief_skill("find/remove traps") +(-10);
   	else
      	score = tp->query_thief_skill("find/remove traps");
   	percent = random(99);
   	if(score >= percent){
      	tell_object(tp,"%^BOLD%^%^YELLOW%^You find a trap!!\n");
      	if(to->query_trap_status(what)==0)
       		tell_object(tp,"%^BOLD%^The trap is already deactivated!!\n");
      	return 1;
  	}
   	else {
      	tell_player(tp,"You do not find a trap there.\n");
       	return 1;
   }
}

int remove_trap(mapping set_trap, object to, object tp, string what){
    int score, percent;
    if(!tp->is_class("thief") && !tp->is_class("assassin")){
      	tell_player(tp,"You can't do that!!\n");
       	return 1;
  	}

	if(!set_trap[what]) {
      	notify_fail("You do not find a trap there.\n");
      	return 0;
 	}
  	if(to->query_trap_status(what)==0){
       	tell_player(tp,"The trap is already deactivated!!\n");
       	return 1;
    }	
 	if(tp->query_armour("torso"))
     	score = tp->query_thief_skill("find/remove traps") +(-10);
   	else
       	score = tp->query_thief_skill("find/remove traps");
 	percent = random(99);
	if(score >= percent){
       	to->toggle_trap(what);
      	tell_object(tp,"%^BOLD%^You remove the trap successfully!!\n");
     	tell_room(environment(tp),"%^BOLD%^You see the trap succssfully removed!!\n",tp);
     	return 1;
  	} else {
   		tell_object(tp, "%^BOLD%^Apparently, You failed!!\n");
       	call_other(to,set_trap[what]);
      	 return 1;
	}
}

mixed get_trap_object(string level, string type)
{
	int x, TrapDc;
	string MyDir, MyType, MyFile, *Files;
	object TrapOb;
	if(level == "random") level = VALID_TRAP_LEVELS[random(sizeof(VALID_TRAP_LEVELS))];
	switch(level)
	{
		case "low":
			TrapDc = 10 + random(6);
			break;
		case "mid":
			TrapDc = 16 + random(10);
			break;
		case "high":
			TrapDc = 26 + random(10);
			break;
		case "epic":
			TrapDc = 36 + random(15);
			break;
		default:
			TrapDc = 10 + random(6);
			break;
	}
	//tell_object(find_player("saide"), "level = "+level +" DC = "+TrapDc);
	if(type != "random")
	{
		if(file_exists(TRAP_DIRS+type+"_base.c")) 
		{
			MyFile = TRAP_DIRS+type+"_base.c";
		}
		else type = "random";
	}
	if(type == "random")
	{
		Files = get_dir(TRAP_DIRS+"*_base.c");
		MyFile = TRAP_DIRS+Files[random(sizeof(Files))];
	}
	if(!file_exists(MyFile)) return 0;
	TrapOb = new(MyFile);
	TrapOb->set_my_dc(TrapDc);
	return TrapOb;
}
		