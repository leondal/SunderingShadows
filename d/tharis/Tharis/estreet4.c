#include <std.h>

inherit VAULT;

void create(){
        string time;
        ::create();
        set_terrain(CITY);
        set_travel(PAVED_ROAD);
        
        set_property("indoors",0);
        set_property("light",2);
        set("short","Before the gates to the elven quarter");
        set("long",
@OLI
        %^BOLD%^%^YELLOW%^You stand before the gates to the Elven Quarter.
%^RESET%^
Before you stand the gates to the elven quarter. Citizens of Tharis 
are allowed to enter the quarter and leave of their will. However, the
elves do not enjoy citizenship since the duke took power. Thus standing 
vigilant guard on the gates before you. At night the gates normally
stand closed. Thieves do not usually bother along this section of the
streets, having more opportunity and less guards in other areas. Small
voices whisper in your head "What is this? Gates to keep elves out."
OLI
        );
        set_exits(([
                "east":"/d/tharis/Tharis/estreet5",
                "west":"/d/tharis/Tharis/estreet3"
                ]));
   set_door("gate","/d/tharis/Tharis/estreet5","east",0);
   set_door_description("gate","The gate is hardwood.  No lock is
evident.");
//   time = "/daemon/events_d"->query_time_of_day();
/*   if(query_night()) {
      set_open("gate",0);
      "/d/tharis/Tharis/estreet5"->set_open("gate",0);
   }
  else {
                set_open("gate",1);
                "/d/tharis/Tharis/estreet5"->set_open("gate",1);
   }
   */
// locked the elven quarter due to plot   
    set_open("gate",0);
      "/d/tharis/Tharis/estreet5"->set_open("gate",0);
	  set_locked("gate",1);
        set_smell("default","From the elven quarter you smell a small freshness");
        set_listen("default","Silence, only the wind breaks the silence");
   set_pre_exit_functions(({"east"}),({"GoThroughDoor"}));
}

int GoThroughDoor() {
        int i;
        if(present("guard")){
   if((string)TP->query_race() == "elf" || (string)TP->query_race() ==
"drow"){
                write("%^BOLD%^The guard looks at you with hate and loathing");
            write("%^BOLD%^as if you killed his first born son.");
                tell_room(TO,"%^BOLD%^The guard looks at "+TPQCN+" with "
                +"extraordinary hate!",TP);
                }
    if((string)TP->query_race() == "half-elf"){
                i = random(5);
                if(i != 0){
                        write("%^BOLD%^The guard looks at you with hate and loathing");
                    write("%^BOLD%^as if he might attack you!");
                        tell_room(TO,"%^BOLD%^The guard looks at "+TPQCN+" with "
                        +"extraordinary hate!",TP);
                }
        }
   return ::GoThroughDoor();
        
 }
   return ::GoThroughDoor();
}
void reset(){
        string time;
        ::reset();
        
        if(!present("guard")){
                new("/d/tharis/monsters/egguards")->move(TO);
                new("/d/tharis/monsters/egguards")->move(TO);
        }
        
        time = "/daemon/events_d"->query_time_of_day();
        if(time == "day"){
                set_open("gate",1);
                "/d/tharis/Tharis/estreet5"->set_open("gate",1);
        } else{
                set_open("gate",0);
                "/d/tharis/Tharis/estreet5"->set_open("gate",0);
        }
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady
downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/
