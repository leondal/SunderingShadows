#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

void create()
{
        ::create();
	set_long(::query_long()+
		" %^RESET%^%^ORANGE%^In the earth here is a large hole in the foothills, with large marks in the"+
		" earth around it, as if a lot of traffic has been going in and out.");
	 set_exits(([
		"north"	: FOOTHILLS"foothills36",
		"south"	: FOOTHILLS"foothills38",
		"west"	: GRASSLAND"grassland45",
		"east"	: FOOTHILLS"foothills24",
		"mound"	: MOUND"mound1",
]));
    set_pre_exit_functions(({"mound"}),({"GoThroughDoor"}));
}
int GoThroughDoor() {
object room;
  if(member_array("The Missing Wife",TP->query_mini_quests())!=-1)  {
   if(TP->query_paralyzed() || TP->query_bound() ||
TP->query_unconscious()){
    return 0;
    }
  return 1;
  } else {
	write("%^BOLD%^%^BLACK%^As you enter this massive hole in the foothills here you get a strange sense of danger that passes through your bones. You now wonder what may have happened to the woman that obviously got drug this way.");
	room = find_object_or_load(MOUND"mound6");
		new(MON"grolin.c")->move(room);
  return 1;
  }
}
