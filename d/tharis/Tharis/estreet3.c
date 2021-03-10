#include <std.h>

inherit CROOM;

void create(){
    if(random(3))
      set_monsters(({"/d/tharis/monsters/citizen", "/d/tharis/monsters/thief", "/d/tharis/monsters/patrol"}),({ random(3), random(2), random(2) }));
	::create();
	set_terrain(CITY);
	set_travel(PAVED_ROAD);
	set_name("estreet3");
	set_property("indoors",0);
	set_property("light",2);
	set("short","Street leading from the marketplace to the elven quarter");
	set("long",
@OLI
	%^BOLD%^%^YELLOW%^East street leading to the Elven quarter%^RESET%^
This street leads east to the Elven quarter of Tharis. To the west 
is the famed marketplace of Tharis. You see the conditions around you
drastically worsen to the east. You notice that the conditions are from
poverty but also from what look to be maybe riots or deliberate burnings.
This area, while not as likely to have thieves as the market, may still 
have plenty.
OLI
	);
	set_exits(([
		"west":"/d/tharis/Tharis/estreet2",
		"east":"/d/tharis/Tharis/estreet4"
		]));
	set_items(([]));
	set_smell("default","A minor hint of poverty reaches your nose.");
	set_listen("default","The city sounds bother your ears no longer pleasant.");
}

void reset(){
//   	int num;
//   	int number;
//   	int x;
   	::reset();
	if(!present("street light"))
   		new("/d/tharis/obj/street_light")->move(TO);
/* setting to use CROOM/CVAULT since they wander  *Styx*  8/2002        
    if(!present("citizen")){
        num = random(5);
        for(x = 1; x <= num;x++){
           	number = random(10);
            switch (number){
              	case 0:
            	case 1: break;
               	case 2:
             	case 3:
               	case 4:
                case 5:
                  	new("d/tharis/monsters/citizen")->move(TO);
                   	break;
           		case 6:
              	case 7:
                case 8:
                   	new("d/tharis/monsters/patrol")->move(TO);
                	break;
                case 9:
                   	new("d/tharis/monsters/thief")->move(TO);
                   	break;
            }
        }
	}
*/
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/