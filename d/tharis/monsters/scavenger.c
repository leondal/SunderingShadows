//minor changes by Circe 1/11/04 to lower XP and money as they spawn in a 
//room consistently 3 seconds after they die.
//scavenger.c

#include <std.h>

inherit "/d/tharis/monsters/fwander";

object room_from;

void create(){
	::create();
	set_name("scavenger");
	set_id(({"scavenger","Scavenger"}));
	set_short("Battle field scavenger");
	set_long(
@OLI
	This rough hewn little man is the only person who seems to benefit
from the horrors of war.  Collecting weapons to sell back to the various 
parties, he looks for valuables among the dead.  This lower form of life
is just too sickening to really comprehend.
OLI
	);
	set_race("human");
	set_body_type("human");
	set_gender("male");
	set_hd(64,10);
	set_exp(5000); //changed because they were spawning one after another
//they're meant to keep the forest clean, not provide easy XP.  Circe 1/11/04
	set_alignment(8);
	set_hp(1000);
	set_stats("strength",25);
	set_stats("intelligence",25);
	set_stats("dexterity",25);
      set_guild_level("cleric",25);
	set_property("no bow",1);
      set_spells(({"call lightning"}));
      set_spell_chance(30);
	set_overall_ac(-15);
	new("/d/common/obj/weapon/longsword")->move(TO);
	command("wield sword in right hand");
	new("/d/common/obj/weapon/longsword")->move(TO);
	command("wield sword in left hand");	
//	add_money("gold",random5000); //taken out by Circe 1/11/04 on recommendation of Styx
	set_emotes(1,({"%^MAGENTA%^The scavenger says%^RESET%^: I'm going to collect all this stuff!"}),0);
      set_property("full attacks",1);
      set_property("no death",1);
}

void init(){
	object *livings;
	::init();
     if(!objectp(TP) || !objectp(TO)) return;  //was just a check for objectp(TP)
	if(objectp(room_from) && (ETO != room_from))
		room_from->remove();
  if (!objectp(TP->query_rider())) return ; // Fix for riding animals.
  // 3/9/2003 - garrett
// changing to a callout to see if that prevents the other mobs bugging
// in their init  *Styx*  8/17/02
//     if(TP->is_monster() && !random(5))   destall(TP);
       if(TP->is_monster() && !random(5))   call_out("destem", 1, TP);
	call_out("cleanem",1);
	livings = all_living(ETO);
	livings -= ({TO});
	if(livings == ({}))
		room_from = ETO;
	add_action("stop_steal","pp");
	add_action("stop_steal","steal");
    if(!objectp(TP)) return;
}

destem(object targ) {
   if(!objectp(targ))  return 1;
   destall(targ);
   return 1;
}

cleanem(){
	object *inven, *livings;
	int i, j;
        if(!objectp(ETO) || !objectp(TO))  return 1;	
	inven = all_inventory(ETO);
	livings = all_living(ETO);
	
	inven -= ({livings});
        tell_room(ETO,"%^MAGENTA%^The scavenger says%^RESET%^:  I'm going to collect all this stuff!", TO);
	j = sizeof(inven);
	for(i = 0;i < j;i++) {
	    if(inven[i]->query_property("riding") == 1)
	        continue;
 	    if(objectp(inven[i]) && !living(inven[i]))
		inven[i]->remove();
	}
	return 1;
}
	
void set_paralyzed(int time,string message) { return 1;}


int stop_steal(string str){
	if(str && id(str)) {
		write("The scavenger has been alive far too long to be picked by the likes of you!");
		kill_ob(TP,1);
		return 1;
	}
	return 0;
}
