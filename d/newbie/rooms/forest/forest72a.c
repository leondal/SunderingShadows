//forest72a.c - Near the ravine from forest72.c

#include "../../newbie.h"
#include <std.h>

inherit ROOM;

void prying(object tp, int num);

void create(){
   ::create();
   set_property("light",2);
   set_property("no teleport",1);
   set_short("%^GREEN%^Forest ridge");
   set_terrain(ROCKY);
   set_travel(GAME_TRACK);
   set_long(
@STYX
Ridges have formed here with valleys between them.  This area at the end of one of the ridges has steeply sloping hillsides littered with fist-size, sharp-edged rocks.  Little grass grows in the rocky soil here and the thick underbrush blocks you from seeing much further.  Many smaller rocks make the footing very unstable as you pick your way around the larger ones.  Near the top edge of the hill toward the west is a much larger boulder that seems to be settled into a depression in the ground.
STYX
   );
   set_smell("default","There is a dank moist smell of wet limestone.");
   set_listen("default","You hear an echo of the forest sounds from somewhere nearby.");
   set_items( ([ 
   	({"rock", "rocks"}):"Some of the rocks are large and sharp enough to hurt badly if you stumbled or fell over them.  Others are smaller and just make it difficult to keep your footing.", 
	({"hillside", "hillsides"}):"The hillsides are steep and littered with rocks that make footing uncertain.  You wouldn't want to stumble and fall on them.", 
	"boulder":"It seems to have settled into a depression in the ground.   On closer inspection, it appears water draining down the hillside has run under the boulder in one or two spots and eroded a hole under it.", 
	({"hole", "depression"}):"It looks like you might be able to pry the boulder loose to see what's under it.",
	 ]) );
    set_exits(([
        "northeast":FOREST"forest72",
    ]));
}

void init(){
    ::init();
    add_action("pry","pry");
}
int pry(string str) {
    if(str == "boulder"){
        TP->set_paralyzed(2000,"The boulder was more stuck than you expected.");
        prying(TP,0);
        return 1;
        }
        else  {tell_object(TP,"Pry what?");
           	return 1;
           	}
}

void prying(object tp,int num){
	switch(num){
       	case(0):tell_object(TP,"You scramble to keep your footing as the boulder refuses to budge.\n");
              	break;
              case(1):tell_object(TP,"Suddenly, your footing gives and you begin tumbling down the hill. \n");
                     break;
              case(2):tell_room(ETP,""+TPQCN+" pries the boulder loose a little. \n\n%^BOLD%^"+TPQCN+" begins scrambling wildly and looses footing as "+TPQCN+" rolls down the hillside through the thick bushes. \n\n%^YELLOW%^You hear "+TPQCN+"'s screams fade away and then a dull muffled thud. \n\n%^RESET%^"+TPQCN+" is nowhere to be seen! \n",TP);
                     break;
                     case(3):tell_object(TP,"           "+" %^BOLD%^%^WHITE%^EEEKKKKKK!!%^RESET%^ \n");
                     break;
              case(4):tell_object(TP,"%^RED%^OOOWWWWIIIEEEEEE!!%^RESET%^ \n \n");
               	tp->do_damage("torso",random(6)+2);
                     break;
              case(5):tell_object(TP,"       "+
				"%^ORANGE%^THHUUUDDDDD!!%^RESET%^ \n");
                     break;
                     break;
    		case(6):tell_object(TP, "The rocks scraped you up but at least the bushes slowed your fall. \n");
          		TP->move(FOREST"forest72b");
          		tell_object(TP,"As you regain your senses and look around, you realize you're in a fairly deep ravine. \n");

		case(7):tell_room(ETP,""+TPQCN+" lands next to you with a dull muffled thud.",TP); 
               TP->set_paralyzed(0);
               return;
	           break;
        }
    num++;
    call_out("prying",0,tp,num);
    return;
}
