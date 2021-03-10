/*mtnroad38.c - road from Offestry toward Shadow area.  Post exit function added to allow notice of paper in next room by Circe 10/23/03*/

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_south2";

void create(){
   ::create();
   set_exits(([
       "west":ROADOUT"mtnroad37",
       "south":ROADOUT"mtnroad39",
   ]));
   set_post_exit_functions(({"south"}),({"go_south"}));
//   set_pre_exit_functions( ({"south"}), ({"GoThroughDoor"}) );
// Put this on the gate. To be more evil.
// Garrett
}

//added to allow hint.  Circe 10/23/03
void go_south(){
   if(newbiep(TP))
      tell_object(TP,"%^BOLD%^You catch a glimpse of cloth or paper in the leaves next to the gate.");
      return;
}
/*
int GoThroughDoor(string str) {
	str = TP->query_desc();
	if( !stringp(str) || strlen(str) < 240 ) {
		write("Your description is either blank or too short.\n"+
		"Please create one or add to it in order to be able to proceed"+
		" out of the newbie area.  Note that a wiz or avatar may still"+
		" review it and require changes.");
		return 0;
	}
	return 1;
}
*/
