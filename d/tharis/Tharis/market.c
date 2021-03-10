
// /market.c//
#include <std.h>
#include "../tharis.h"
#include <daemons.h>


inherit VAULT;


int count;
void create() {
        ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
}

void reset(){
           int num;
           int number;
           object ob;
        int x;
        string time;
        ::reset();


       if(!present("citizen")){
        num = random(5);
          	for(x = 1; x <= num;x++){
                number = random(10);
                switch (number){
                        case 0: break;
                        case 1: 
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
        if(!present("vendor")){
        time = EVENTS_D->query_time_of_day();
        if(time!="night"){
  	
        number = random(10);
                        switch (number){
                        case 0:
                        case 1:
                           new("/d/tharis/monsters/tb_vendor")->move(TO);
                           break;
                        case 2:
                        case 3:
                           new("/d/tharis/monsters/cl_vendor")->move(TO);
                           break;
                        case 4:
                        case 5:
                        case 6:
                           new("/d/tharis/monsters/f_vendor")->move(TO);
                           break;
                        case 7:
                           new("/d/tharis/monsters/perfume")->move(TO);
                            break;
                        case 8:
                           new("/d/tharis/monsters/ring")->move(TO);
                           break;
                        case 9:
                           new("/d/tharis/monsters/scribe")->move(TO);
                           break;
                    }
             }
                
        }
           if(!present("street_light",TO))
                new("/d/tharis/obj/street_light")->move(TO);


}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/