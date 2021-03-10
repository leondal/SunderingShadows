#include <std.h>
#include "../../gantioch.h"

inherit FOOTHILLSINH;

string roomlong, a_long;

void create()
{
        ::create();
      set_long((: TO, "thislong" :));
	  set_exits(([
	    "north"	: FOOTHILLS"foothills11",
		"south"	: FOOTHILLS"foothills13",
		//"west"	: FOOTHILLS"foothills24",
		"east"	: FOOTHILLS"foothills10",
		"mound" : MOUND"mound1",
]));
roomlong = FOOTHILLSINH->query_long();
   a_long = "\n\n%^BOLD%^%^CYAN%^The terrain continues to the west, however the"+
            " terrain is too steep to continue.";
    set_pre_exit_functions(({"mound"}),({"GoThroughDoor"}));
    set_items(([
      "mound"    : "%^RESET%^%^RED%^The hole in the ground here is obviously an entrance to some sort of lair.",
        "mountains" : "%^RESET%^%^BLUE%^The mountains rise high into the air to the east, giving"+
		" a majestic view of the %^BOLD%^%^WHITE%^snow-capped %^RESET%^%^BLUE%^peaks.",
        "brush" : "%^RESET%^%^GREEN%^The brush is sparse and made up of a variety of short grasses and shrubs.",
        "keep" : "%^BOLD%^%^WHITE%^Off a distance to the east-southeast, you see large stone keep. Cresting over the"+
		" %^RESET%^%^BLUE%^mountain, %^BOLD%^%^WHITE%^and is likely the most prominant structure save the %^RESET%^%^BLUE%^"+
		" mountains %^BOLD%^%^WHITE%^to the east.",
        "forest" : "%^BOLD%^%^GREEN%^To the west tall trees rise up out of the grassland. The forests spread"+
		" for miles and miles and are quite majestic.",
		"grasslands"	: "%^RESET%^%^GREEN%^The grasslands span out off the foothills, encompassing all of"+
		" the area up until the massive forest. A small %^RESET%^%^CYAN%^hamlet %^RESET%^%^GREEN%^is located to"+
		" the west.",
		"hamlet" : "%^BOLD%^%^CYAN%^The hamlet is to the west, comprising of a few buildings that seem to be mostly"+
		" under construction.",
    ]) );

}
int GoThroughDoor() {
object room;
  if(member_array("%^BOLD%^%^CYAN%^A Revis Encounter%^RESET%^",TP->query_mini_quests())!=-1)  {
   if(TP->query_paralyzed() || TP->query_bound() ||
TP->query_unconscious()){
    return 0;
    }
  return 1;}
    else {
  write("%^BOLD%^%^BLACK%^As you enter this massive hole in the foothills here you get a strange sense of danger that passes through your bones. You now wonder what may have happened to the woman that obviously got drug this way.");
	room = find_object_or_load(MOUND"mound6");
    if (present("grolin",room)){
        return 1;}
         else {
        new(MON"grolin.c")->move(room);}
  return 1;}
}


string thislong(){
   return roomlong+a_long;
}




