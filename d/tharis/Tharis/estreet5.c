#include <std.h>
inherit VAULT;

void create(){
        ::create();
        set_terrain(CITY);
        set_travel(PAVED_ROAD);
        set_property("light",2);
        set_property("indoors",0);
        set("short","Just west of the Gate to the elven quarter");
        set("long",
		"%^BOLD%^%^YELLOW%^Just inside the Elven quarter gates%^RESET%^\n\n"+
		"You are just east of the gates that seperate the main portion of "+
		"Tharis and the elven quarter.  It looks like there was some "+
		"desperate fighting here.  However, the elves prevailed and "+
		"several posts that were once managed by humans have been "+
		"abandoned.  %^CYAN%^The guards have abandoned the elven quarter.%^RESET%^"
/*@OLI
        %^BOLD%^%^YELLOW%^Just inside the Elven quarter gates%^RESET%^
You are just east of the gates that separate the main portion of 
Tharis and the elven quarter. Inside the elven quarter you see a
desolate landscape. You look around and see that under the dirty
and sometimes blacken exterior of the buildings their curves and 
arches and decore are beautiful. Nothing could manage to hide this 
overwhelming beauty. Again you are forced to wonder about why this
city pushes the elves aside. The guards watch vigilantly over their 
post although it is obvious that they don't appreciate being on this 
side of the gate.
OLI
*/        );
        set_exits(([
                "east":"/d/tharis/Tharis/estreet6",
                "west":"/d/tharis/Tharis/estreet4"      
                ]));
	//changed the room after the free tharis plot -hades
        set_door("gate","/d/tharis/Tharis/estreet4","west","key");
   //     set_door_description("gate","The gate is hardwood.  The door is locked from the inside.");
		set_locked("gate",1);
		//set_lock_description("gate","lock","This is a huge bar across the door.");
		//lock_difficulty("gate",-20,"lock");
       /* set_items(([
                "gate":"The gate is hard wood. A lock is evident."
                ]));
        */
		set_smell("default","Strangely you smell sweetnesses of nature.");
        set_listen("default","The world around you is deathly silent.");
 //  set_pre_exit_functions(({"west"}),({"GoThroughDoor"}));
}
/*
void reset(){
        ::reset();
        
        if(!present("guard")){
                new("/d/tharis/monsters/egguards")->move(TO);
                new("/d/tharis/monsters/egguards")->move(TO);
        }
        
}

int GoThroughDoor() {
        
   if((string)TP->query_race() == "elf" ||(string)TP->query_race() ==
"drow"){
                if(present("guard")){
                        write("%^BOLD%^The guard roughly grabs you by the arm and throws you to the
ground.");
                        tell_room(TO,"%^BOLD%^As "+TPQCN+" attempts to go through the gates
"+TP->query_subjective()+" is "
                        +"roughly thrown to the ground by the guard.",TP);
                        tell_room(TO,"The guard %^RED%^shouts: %^RESET%^%^BOLD%^ You dirty elf! You will not"
                                +" be allowed to enter the city with civilized people to hunt babies
and kill women!");
                return 0;
                }
        }
   return ::GoThroughDoor();
}*/
