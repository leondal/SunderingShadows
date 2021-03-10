#include "chaos.h"

inherit VAULT;
int step;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("The West Room");
    set_long( "This is the West room. \n"
		"This is a strange room. There are mirrors on all of the walls."
		"In the center of the room, there is a small display case."	
    );
    set_exits( ([
	"east" : CHAOSDIR+"floor9"
        ]) );
    set_door("west door",CHAOSDIR+"floor9","east",0);
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sounds of silence fills your ears.");

    set_items(( [
	"mirror":"They are on all of the walls. Almost like wall-paper.",
	"glass case":"It is a glass display case. There is a helmut inside of it.",
        "helmut":"A Black helmut. It seems to call out to you.",
	"glow":"A magical glow."
    ] ));
    step = 0;
    set_search("default","You see a mirror that looks out of line.");
    set_search("mirror",(:TO,"search_latch":));
    set_search("notch",(:TO,"search_latch":));
    set_search("latch",(:TO,"search_latch":));
    set_search("opening",(:TO,"search_latch":));
}
void init(){
    ::init();
}
void reset(){
    ::reset();
	if(!present("glass case"))
	    new(MISCDIR+"helmut_case")->move(TO);
	if(!present("mage"))
		new(MONDIR+"blackmage")->move(TO);
		step = 0;

}
int search_latch(string str){
    string temp;
	if(!str) return 0;
	if(!sscanf(str,"%s",temp)) return 0;

	if(temp == "mirror"){
		step = 1;
        	write("The mirror sees to stick out from the wall, more"+ 
        	" then the others. There appears to be a notch on one side of the mirror.");
		return 1;
	}
	if((temp == "notch") && (step <= 1)){
		step = 2;
    		write("The notch is worn from use. There is a latch here.");
		return 1;
	}
	if((temp == "latch") && (step <= 2)){
		step = 3;
		add_action("press_latch","press");
    		write("Have you tried to <press the latch> yet?.");
		return 1;
	}
	if((temp == "opening") && (step <= 4)){
		
    		write("You find a lever in the opening. It can be moved left or right.");
			write("You get the feeling that if you were to move the lever in the wrong ");
			write("direction, things wouldn't work out as you might want. So be sure to ");
			write("move the lever in the right direction.");
		add_action("move_lever","move");
		return 1;
	}
	write("You don't notice that here.");
	return 0;
}
int press_latch(string str){
    string is_latch;
	if(!str) return notify_fail("Press what?\n");
	if(!sscanf(str,"the %s",is_latch)) return notify_fail("try 'press the latch'!\n");
	step = 4;
	write("There is an opening behind the mirror.");
	remove_action("press_latch","press");
	return 1;
}
int move_lever(string str){
   string lever,dir;
   int temp,test;
	if(!str) return 0;
	if(sscanf(str,"%s %s",lever,dir) != 2) return 0;
	if(lever != "lever") return 0;
	if(( dir != "left") && ( dir != "right")) return 0;
 	write("You move the "+lever+" to the "+dir+"!");
	if(dir == "left"){
		write("A bright light engulfs you. When the light dims, your in a different place.");
		TP->move(ROOMDIR+"adventure");
	}
	else{
			write("The Case opens!");	
		    present("case")->open_case();

	}	
	remove_action("move_lever","move");
	step = 0;
	return 1;
}
