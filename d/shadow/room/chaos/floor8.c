#include "chaos.h"

inherit VAULT;

int step, inc;
mapping levers;
string melnmarn;
int source;

void show_levers();
void reset_levers();

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("A Staircase, first floor");
    set_long(
@MELNMARN
%^BOLD%^Your on the eighth floor of the Chaos Tower.%^RESET%^
You can see four doors, one in each direction. 
There doesn't appear to be locks on the doors. 
In the center of the room, is a spiral staircase, 
that leads up and down. 
MELNMARN
    );
    set_exits( ([
	"down"  : CHAOSDIR+"floor7.c",
	"east"  : CHAOSDIR+"east8.c",
	"west"  : CHAOSDIR+"west8.c",
	"south" : CHAOSDIR+"south8.c",
	"north" : CHAOSDIR+"north8.c"
        ]) );
    set_door("north door",CHAOSDIR+"north8","north",0);
    set_door("south door",CHAOSDIR+"south8","south",0);
    set_door("east door",CHAOSDIR+"east8","east",0);
    set_door("west door",CHAOSDIR+"west8","west",0);
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sound of dead silence, numbs your ears.");
    set_search("default","You notice the stairs look odd.");
    set_search("door",(: TO,"Search_it" :));
    set_search("stairs",(: TO,"Search_it" :));
    set_search("walls",(: TO,"Search_it" :));
    set_search("stone",(: TO,"Search_it" :));
    set_search("opening",(: TO,"Search_it" :));
    set_search("levers",(: TO,"Search_it" :)); 
    step = 0;
    inc = 0;
    levers = ([1:"%^RED%^open",2:"%^RED%^open",3:"%^RED%^open",4:"%^RED%^open"]); 
    source = 0;
}

int Search_it(string str){
    string temp;
	if(!str) return 0;
	if(!sscanf(str,"%s",temp)) return 0;

	if((temp == "stairs") && (step == 0)){
		step = 1;
    		write("You search the stairs, and find a door.");
		return 1;
	}
	if((temp == "door") && (step == 1)){
		step = 2;
        	write("You can see the outline of the door, but there is no");
		write("visible means of opening the door. No handles, no knobs.");
		write("The stone walls catch your attention, though.");
		return 1;
	}
	if((temp == "walls") && (step == 2)){
		step = 3;
    		write("You search the walls. On the south wall, you find a loose stone.");
		return 1;
	}
	if((temp == "stone") && (step == 3)){
		step = 4;
    		write("The stone appears to be loose enough to move.");
		write("Perhaps you could try to pull the stone.");
		add_action("move_stone","pull");
		return 1;
	}
	if((temp == "opening") && (step == 5)){
		step = 6;
    		write("You find 4 levers in the opening.");  
		return 1;
	}
	if((temp == "levers") && (step == 6)){
		step = 0;
    		write("There are 4 of them. They all appear to move back and"); 
		write("forth. All of them are pulled toward the opening.");
		write("You could push the levers.");
		add_action("move_lever","push");
		show_levers();
		return 1;
	}
	write("You don't notice that here.");
	return 0;
}
int move_stone(string str){
	if(!str) return notify_fail("Pull what?\n");
	write("You reach out and pull the stone. You hear a noise behind you.");
	write("There is an opening on the north wall.");
	remove_action("move_stone","pull");
	step = 5;
	return 1;
}
int move_lever(string str){

   string lever;
   int which, *order;
        switch(source){
		case 0: order = ({4,2,3,1});break;
		case 1: order = ({4,3,1,2});break;
		case 2: order = ({2,4,3,1});break;
		default: order = ({3,4,2,1});break;
	}
	if(!str) {
		write("Push what?\n");
		return 1;
	}
	if(sscanf(str,"%s %d",lever,which) != 2){ 
		write("Try <push lever #>.\n");
		return 1;
	}
	if(lever != "lever"){ 
		write("Try <push lever #>.\n");
		return 1;
	}
	if((which < 0) ||( which > 4)){ 
		write("No such lever! Try <push lever #> where # is between 1 and 4.\n");
		return 1;
	}
	if(levers[which] == "%^GREEN%^closed       "){
		write("Lever #"+which+" has already been pushed!");
		return 1;
	}
	if(member_array("up",query_exits()) != -1){
		write("The levers won't move!");
		return 1;
	}
	else {
		write("You moved lever #"+which+"!");
		levers[which] = "%^GREEN%^closed       ";
		if(which == order[inc]) inc ++;
	}
	show_levers();
	if((inc != 4) 
	&& (levers[1] == "%^GREEN%^closed       ")
	&& (levers[2] == "%^GREEN%^closed       ")
	&& (levers[3] == "%^GREEN%^closed       ")
	&& (levers[4] == "%^GREEN%^closed       ")) 
	{
		inc = 0;
		write("Nothing seems to have happened!");
		call_out("reset_levers",4);
		call_out("show_levers",5);
	}
	if(inc == 4) {
		inc = 0;
		reset_levers();
		remove_action("move_lever","push");
		add_exit(CHAOSDIR+"floor9","up");
		call_out("close_door",60);
		write("You hear a loud rumbling above you.");
		write("You look up to see the door has opened.");
		write("The stone returns to it's place in the wall.");
	}
	return 1;
}
void show_levers(){

	melnmarn = sprintf("%-20s %-20s %-20s %-20s",levers[1],levers[2],levers[3],levers[4]);
	write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");
	write("%^CYAN%^Lever #1      Lever #2      Lever #3      Lever #4");
	write(melnmarn);
	write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");

}
void reset_levers(){
	levers[1] = "%^RED%^open";
	levers[2] = "%^RED%^open";
	levers[3] = "%^RED%^open";
	levers[4] = "%^RED%^open";
	write("The levers all release back to their original places.");
}
void close_door(){
	remove_exit("up");
}
reset(){
	source = random(4);

}
