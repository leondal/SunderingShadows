#include <std.h>

inherit OBJECT;

object ob;
int indoor,wood;

void init(){
	::init(); 
	add_action("gather_wood","gather");
	}

void create() {
  ::create();
    set_name("flint");
    set_id( ({ "flint","steel","flint and steel" }) );
    set_short("A flint and steel");
    set_long("A flint and steel for starting fires.\n");
    set_weight(1);
    set_value(5);
    set_cointype("silver");	
}

int gather_wood(string str)
{
    indoor=environment(this_player())->query_property("indoors" );
	if(indoor != 1){
 
	   if(!(present("wood",environment(this_player())))){
 		write("You gather up some wood for a fire.");
		new("/d/shadow/obj/misc/wood")->move(environment(this_player()));
		wood=1;	
		return 1;
           }
	   else{ 
		write("You already have wood gathered");
		return 1;
	   }

	}
	else{
		write(" There is no wood indoors!");
		return 1;
	}
	return 0;
}

