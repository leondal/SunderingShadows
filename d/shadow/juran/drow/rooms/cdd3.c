//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit DHALL;

void create(){
   ::create();
   set_exits(([
		"west" : DROOMS+"cdd2",
		"east" : DROOMS+"cbed4",
		"north" : DROOMS+"cbed3"
   ]));

   set_door("north room door",DROOMS+"cbed3","north","obsidian key");
   set_locked("north room door",1,"lock");
   	(DROOMS+"cbed3")->set_locked("north room door",1,"lock");
   set_door_description("north room door","The door is a normal looking door made "+
   	"from oak with a simple lock.");
   lock_difficulty("north room door",-25,"lock");
   set_string("north room door","open","You open the door into a dark room.\n");

   set_door("east room door",DROOMS+"cbed4","east","obsidian key");
   set_locked("east room door",1,"lock");
   	(DROOMS+"cbed4")->set_locked("east room door",1,"lock");
   set_door_description("east room door","The door is heavily made and is "+
   	"reinforced with iron bands.");
   lock_difficulty("north room door",-25,"lock");
   set_string("east room door","open","You open the door into a dark room.\n");

	set_trap_functions(({"east room door"}),({"stick_em"}),({"pick"}));
}
int stick_em(string str){
	int poison;
	if(str != "lock"){
		return 0;
	}
	toggle_trap("east room door","pick","lock");
	tell_object(TP,"As you work on the lock with your tools you feel a sudden hitch "+
		"and then a louder click.");
	TP->force_me("emote gulps");
	tell_room((DROOMS+"lab1"),"%^BOLD%^%^RED%^A bell rings three times.",TP);
	tell_room(TO,"%^BOLD%^%^RED%^Four small holes appears on the south wall.");
	tell_room(TO,"%^BOLD%^%^RED%^Four arrows shoot out with great velocity!");
	tell_object(TP,"The arrows fly directly at you with deadly accuracy!");
	if((int)TP->query_stats("dexterity")>random(25)){
		tell_room(TO,"%^BOLD%^%^RED%^The arrows fly past you into the far wall "+
			"and shatter into splinters!");
		return 0;
	}
	tell_room(TO,"%^BOLD%^%^RED%^The arrows fly into "+TPQCN+" and stick with a "+
		"sickly thud!",TP);
	tell_object(TP,"%^BOLD%^%^RED%^The arrows fly into you and pierce your flesh deeply!");
	TP->do_damage("torso",roll_dice(1,8));
	TP->do_damage("torso",roll_dice(1,8));
	TP->do_damage("torso",roll_dice(1,8));
	TP->do_damage("torso",roll_dice(1,8));
	TP->add_attacker(TO);
	TP->continue_attack();
   if((int)TP->query_stats("constitution")>random(25)){
     	tell_object(TP,"You feel the arrows burn as they pierce your flesh.");
     	return 0;
   }
   poison = roll_dice(30,10);
	TP->setPoisoner(TO);
   TP->force_me("emote %^BOLD%^%^GREEN%^coughs and chokes as the poison from the "+
      	"arrows works its way to "+ETO->query_possessive()+" system.%^RESET%^\n");
	TP->add_poisoning(poison);
	return 0;
}