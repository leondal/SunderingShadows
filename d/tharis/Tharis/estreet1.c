// /d/tharis/Tharis/estreet1.c //
#include <std.h>
#include "../tharis.h"

inherit CROOM;
//int count;
void create() {
    if(random(4))
      set_monsters(({"/d/tharis/monsters/citizen", "/d/tharis/monsters/patrol"}),({ random(4), random(5) }));
 	::create();
	set_terrain(CITY);
	set_travel(PAVED_ROAD);
	set_light(2);
	 set_indoors(0);
   set_short("This is the east street");
	set_long(
@OLI
	This is the east street. To the west is the center of
 town and the marketplace. The east leads to the poor and 
middle class residential areas, the area specially sectioned 
for the elves and eventually the east gate. This road is not
particularly well traveled. Very few residents have a purpose
in the elven area. There are no shops along this street. 
Despite this you still wonder about the presence of thieves.
    To the north is the Hotel Tharis.
OLI
    );
   set_smell("default","Your senses are accosted by the normal smells of a city.");
   set_listen("default","The city bustles around you.");
	set_exits(([
//"south" : ROOMS"exchange",
"north":ROOMS"hotel",
"east":ROOMS"estreet2",
"west":ROOMS"market4",
"southwest":ROOMS"market6",
"northwest":ROOMS"market2",
]));
}

void reset(){
//           int num;
//           int number;
//           object ob;
//	int x;
//	string time;
        ::reset();
        if(!present("street_light",TO))
                new("/d/tharis/obj/street_light")->move(TO);      
/* setting to use CROOM/CVAULT since they wander  *Styx*  8/2002  	while(present("thief")){
              if(ob=present("thief",TO)){
                     ob->move("d/shadowgate/void");
                     ob->remove();
        }
        }
                 while(present("patrol")){
                if(ob=present("patrol",TO)){
                     ob->move("d/shadowgate/void");
                     ob->remove();
        }
        }
                 while(present("citizen")){
                if(ob=present("citizen",TO)){
                     ob->move("d/shadowgate/void");
                     ob->remove();
        }
        }
         
	num = random(9);
           	 for(x = 1; x <= num;x++){
                number = random(10);
                switch (number){
                        case 0:
                        case  1: 
                        case 2:
                        case 3:
                        case 4:break;
		case 5:
                        new("d/tharis/monsters/citizen")->move(TO);
                        break;
                        case 6:
                        case 7:break;
		case 8:
                        new("d/tharis/monsters/patrol")->move(TO);
		break;
		case 9:
                        new("d/tharis/monsters/thief")->move(TO);
                        break;
                }
        }
*/
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/