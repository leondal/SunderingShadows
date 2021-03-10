#include <std.h>
#include "../../gantioch.h"

inherit FOOTHILLSINH;

string roomlong, a_long;

void create()
{
        ::create();
      set_long((: TO, "thislong" :));
	  set_exits(([
	    "north"	: FOOTHILLS"foothills14",
		"south"	: FOOTHILLS"foothills16",
		//"west"	: FOOTHILLS"foothills27",
		"east"	: FOOTHILLS"foothills1",
]));
roomlong = FOOTHILLSINH->query_long();
   a_long = "\n\n%^BOLD%^%^CYAN%^The terrain continues to the west, however the"+
            " terrain is too steep to continue.";
		set_post_exit_functions(({"east"}),({"GoThroughDoor"}));
}

int GoThroughDoor() {
object room;
  if(member_array("%^BOLD%^%^CYAN%^A Revis Encounter%^RESET%^",TP->query_mini_quests())!=-1)  {
   if(TP->query_paralyzed() || TP->query_bound() ||
TP->query_unconscious()){
    return 0;
    }
  return 1;
    } else {
	write("%^BOLD%^%^RED%^You enter the room, looking about and see a terrible sight indeed. All"+
		" around the area are %^BOLD%^%^YELLOW%^caravan wreckages %^BOLD%^%^RED%^with what looks to"+
		" be the aftermath of a vicious %^BOLD%^%^BLACK%^ambush %^BOLD%^%^RED%^that seemed obviously"+
		" one sided. %^BOLD%^%^MAGENTA%^Corpses %^BOLD%^%^RED%^are scattered about, but one man seems"+
		" to be alive, hunched next to a few pieces of wood, terribly wounded.");
	room = find_object_or_load(FOOTHILLS"foothills15");
        if (present("scraps",room)){
        return 1;}
         else {
		new(OBJ"scraptrail.c")->move(room);}
    room = find_object_or_load(FOOTHILLS"foothills14");
        if (present("scraps",room)){
        return 1;}
         else {
		new(OBJ"scraptrail.c")->move(room);}
	room = find_object_or_load(FOOTHILLS"foothills13");
        if (present("scraps",room)){
        return 1;}
         else {
		new(OBJ"scraptrail.c")->move(room);}
	room = find_object_or_load(FOOTHILLS"foothills12");
        if (present("scraps",room)){
        return 1;}
         else {
		new(OBJ"scraptrail.c")->move(room);}
	room = find_object_or_load(FOOTHILLS"foothills1");
        if (present("revis",room)){
        return 1;}
         else {
		new(MON"revis.c")->move(room);}
	room = find_object_or_load(FOOTHILLS"foothills1");
        if (present("caravan",room)){
        return 1;}
         else {
		new(OBJ"destroyedcaravan.c")->move(room);}
  return 1;
  }
}

string thislong(){
   return roomlong+a_long;
}




