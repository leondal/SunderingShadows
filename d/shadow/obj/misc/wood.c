#include <std.h>
inherit OBJECT;

object ob;
int lit,fuel,indoor;

void init(){
	::init(); 
	add_action("make_fire","make");
	add_action("douse_fire","douse");
	add_action("fuel_fire","fuel");
}

void create() {
    ::create();
    set_id( ({"wood"}) );
    set_name("wood");
    set("short", "Some firewood");
    set_weight(1);
   set_long("A bundle of firewood.\n");
    set_value(0);
    lit=0;
    fuel=500;
}

int make_fire(string str)
{
    indoor=environment(this_player())->query_property("indoors" );

	if(indoor == 1){
	write("You need to be outdoors to build a fire!");
	return(1);
	}
    
        if(present("fire",environment(this_player()))){
	    write("You already have a fire lit!");
	    return(1);
	}

	if(ob=present("flint",this_player())){
		
		write("You start a fire with the wood.");
		lit=1;
		set_id(({"fire"}));
		set_name("fire");
		set_short("a campfire");
		set_long("a lit campfire");
		call_out("go_out",fuel);
        	return(1);
	}	
	
	write("You have no flint and steel.");
	return(1);


}

void go_out() {

	write("A campfire goes out.");
    lit = 0;
    remove();
}

int fuel_fire(string str){

        if(present("wood",environment(this_player()))){
	        if(present("fire",environment(this_player()))){
	    		write(" You add the wood to the fire.");
			fuel += 500;		
			present("wood",environment(this_player()))->remove();
		return(1);
		}

		write("There is no fire! You need to make one first!");
		return 1;
	}
	write("You need wood to fuel the fire. Try gathering some!");
	return 1;

}

