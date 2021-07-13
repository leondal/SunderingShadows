#include <std.h>
#include "../../gantioch.h"

inherit ROADINH;

string roomlong, a_long;

void create()
{
        ::create();
      set_long((: TO, "thislong" :));
	  set_exits(([
		"east"	: ROAD"road5",
		"west"	: ROAD"road7",
]));
roomlong = ROADINH->query_long();
   a_long = " %^BOLD%^%^BLUE%^Mountains %^RESET%^%^ORANGE%^loom to the east of here, rising high into the sky."+
            " Surrounding you are expansive, rolling foothills which slowly move out of the ranges to the valley below"+
            " To the southeast you see an outcropping in the rock as the mountains turn"+
            " to foothills and a %^BOLD%^%^WHITE%^keep %^RESET%^%^ORANGE%^sits upon it, seemingly keeping"+
            " watch on the valley below. \n\n%^BOLD%^%^CYAN%^The road here continues through the foothilils to the west and to east"+
            " as it winds its way through the mountain pass. ";

    set_post_exit_functions(({"west"}),({"GoThroughDoor"}));
}

string thislong(){
   return roomlong+a_long;
}


int GoThroughDoor()
{
    object room;
    
    if(member_array("%^BOLD%^%^CYAN%^A Revis Encounter%^RESET%^",TP->query_mini_quests()) < 0)
    {
        if(TP->query_paralyzed() || TP->query_bound() || TP->query_unconscious())
            return 0;
        
        write("%^BOLD%^%^RED%^As you proceed west you see what looks to be %^BOLD%^%^BLACK%^smoke"+
		" %^BOLD%^%^RED%^billowing a ways to the north, high into the sky. From the look of the"+
		" smoke it does not seem to be a normal cooking smoke, and is likely something...or many"+
		" things %^BOLD%^%^YELLOW%^burning%^BOLD%^%^RED%^.");
        
	    room = find_object_or_load(FOOTHILLS + "foothills1");
        
        if (!present("caravan",room))
        {
		    new(OBJ"destroyedcaravan.c")->move(room);
		    new(MON"revis.c")->move(room);
        }
    }
  return 1;
}