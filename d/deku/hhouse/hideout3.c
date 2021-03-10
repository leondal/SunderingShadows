#include <std.h>
#include "/d/deku/inherits/deku.h"
inherit "/d/deku/inherits/hideout_inh.c";

void create() {
    ::create();
   set_long(TO->query_long() + "%^YELLOW%^  An open doorway leads out "+
   "of this room to the west and another to the south.  An "+
   "%^BOLD%^%^GREEN%^oak door%^YELLOW%^ is set into the center "+
   "of the north wall.%^RESET%^");
   set_exits(([
       "north" : BH_ROOMS+"leadersroom",
       "south" : BH_ROOMS+"hideout4",
       "west" : BH_ROOMS+"hideout2",
    ] ));
   set_door("oak door",BH_ROOMS+"leadersroom", "north");
   set_locked("oak door",0);
   set_door_description("oak door","%^GREEN%^This door is made "+
   "from four slabs of oak that have been tightly bound together "+
   "with a thick and coarse rope.%^RESET%^");
   set_trap_functions(({"north"}),({"zapped"}),({"north"}));
   
}

int zapped(){
	if(TP->query_true_invis()) {
      return 0;
    }
	toggle_trap("north","north");
	if("daemon/saving_d"->saving_throw(TP,"spell")) {
       tell_object(TP,"%^BOLD%^%^BLACK%^A bolt of darkness from "+
       "out of nowhere strikes you, burning into your flesh with "+
       "an unseen heat!%^RESET%^");
      
       tell_room(TO,"%^BOLD%^%^BLACK%^A bolt of darkness from out "+
       "of nowhere strikes "+TPQCN+"%^BOLD%^%^BLACK%^!%^RESET%^",TP);

       TP->do_damage("torso",roll_dice(4,8));
	   TP->add_attacker(TO);
	   TP->continue_attack();
	   if(objectp(TP)) {
	      TP->remove_attacker(TO);
	   }
       return 1;
	 }

	else {

      tell_object(TP,"%^BOLD%^%^BLACK%^A bolt of darkness from "+
      "out of nowhere strikes your chest and pain floods through "+
      "your body, dazing you!%^RESET%^");

      TP->set_paralyzed(4 + random(8),"%^RED%^You are struggling "+
      "to regain your balance!%^RESET%^");
      
      tell_room(TO,"%^BOLD%^%^BLACK%^A bolt of darkness from out "+
      "of nowhere strikes "+TPQCN+"%^BOLD%^%^BLACK%^, dazing "+
      TP->QO+"%^BOLD%^%^BLACK%^!%^RESET%^",TP);

      TP->do_damage("torso",roll_dice(8,8));
	  TP->add_attacker(TO);
	  TP->continue_attack();
	  if(objectp(TP)) {
	    TP->remove_attacker(TO);
	  }
      return 1;
	}
}