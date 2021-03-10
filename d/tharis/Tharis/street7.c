// /d/tharis/Tharis/street7.c //
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
   set_property("no teleport",1);
    set_light(2);
    set_indoors(0);
    set_short("The street from the center of the city into the administrative
district.");
    set_long(
@OLI
        This is the street from the center of the city into the
administrative district. To the south, the street leads to
various buildings of governmental importance and eventually
to the palace of the Duke of Tharis. You remember the fact
that the buildings become more important as you head south.
        You note the presence of a recruiter's office to the east
and the Merchant's Guild to the west.
OLI
    );
	set_smell("default","Your senses are accosted by the normal smells of a city.");
	set_listen("default"," The city bustles around you");
    set_exits(([
		"north":"/d/tharis/Tharis/market8",
 		"south":"/d/tharis/road/street8",
		"west":"/d/tharis/Tharis/guild2",
		"east":"/d/tharis/Tharis/recruiter2",
 	] ));
    set_pre_exit_functions(({"south"}),({"GoThroughDoor"}));
}
void reset(){
	int num;
  	int number;
   	int x;
	::reset();

  	num = random(5);
 	for(x = 1; x <= num;x++){

        number = random(10);
 		switch (number){
         	case 0:
         	case  1:
      		case 2:break;
         	case 3:
         	case 4:{
              	new("d/tharis/monsters/citizen")->move(TO);
               	break;
             	}
       		case 5:
        	case 6:
   			case 7:
         	case 8:{
               	new("d/tharis/monsters/patrol")->move(TO);
               	break ;
            	}
          	case 9: {
                new("d/tharis/monsters/thief")->move(TO);
              	break;
          	}

        }
  	}
}
int GoThroughDoor(){
        write("Due to a budget impass the government has temporarily shut down!"
);
   return 0;
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/