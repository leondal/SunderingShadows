#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	  set_exits(([
		"north"	: FOOTHILLS"foothills26",
	    "south"	: FOOTHILLS"foothills28",
		"west"	: FOOTHILLS"foothills40",
		"east"	: FOOTHILLS"foothills15",
]));
		set_pre_exit_functions(({"east"}),({"GoThroughDoor"}));
		set_pre_exit_functions(({"east"}),({"GoThroughDoor2"}));
}

int GoThroughDoor() {
object room;
  if(member_array("Let Revis Die",TP->query_mini_quests())!=-1)  {
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
	room = find_object_or_load(FOOTHILLS"foothills25");
        if (present("scraps",room)){
        return 1;}
         else {
		new(OBJ"scraptrail.c")->move(room);}
	room = find_object_or_load(FOOTHILLS"foothills38");
        if (present("scraps",room)){
        return 1;}
         else {
		new(OBJ"scraptrail.c")->move(room);}
	room = find_object_or_load(FOOTHILLS"foothills37");
        if (present("scraps",room)){
        return 1;}
         else {
		new(OBJ"scraptrail.c")->move(room);}
}
	room = find_object_or_load(FOOTHILLS"foothills14");
        if (present("scraps",room)){
        return 1;}
         else {
		new(OBJ"scraptrail.c")->move(room);
  return 1;
  }
}

int GoThroughDoor2() {
object room;
  if(member_array("Saved Revis",TP->query_mini_quests())!=-1)  {
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
	room = find_object_or_load(FOOTHILLS"foothills25");
        if (present("scraps",room)){
        return 1;}
         else {
		new(OBJ"scraptrail.c")->move(room);}
	room = find_object_or_load(FOOTHILLS"foothills38");
        if (present("scraps",room)){
        return 1;}
         else {
		new(OBJ"scraptrail.c")->move(room);}
	room = find_object_or_load(FOOTHILLS"foothills37");
        if (present("scraps",room)){
        return 1;}
         else {
		new(OBJ"scraptrail.c")->move(room);}
}
	room = find_object_or_load(FOOTHILLS"foothills14");
        if (present("scraps",room)){
        return 1;}
         else {
		new(OBJ"scraptrail.c")->move(room);
  return 1;
  }
}





