#include <std.h>

inherit OBJECT;

void create() {
  ::create();
    set_name("oil");
    set_id( ({ "oil","flask","flask of oil" }) );
    set_short("A flask of lantern oil");
    set_long("A flask of lantern oil. Fill your lantern with it.\n");
    set_weight(1);
    set_value(6);
    set_cointype("copper");
}
 
void init() {
    ::init();
    add_action("fill","fill");
}
 
int fill(string str)
{
    object ob;
    int fuel_left;
    string oil,lantern;
    
    if(!str) return 0;
    if((sscanf(str, "%s with %s", lantern, oil)) !=2) return 0;
    if(lantern != "lantern") return 0;
    if(!(ob = present(lantern,this_player()))) {
        write("You do not have any "+lantern+" to fill!\n");
        return 1;
    }
    if(!(present(lantern,this_player())->id("lantern"))) {
        write("You can't put oil in that!\n");
        return 1;
    }
      if(!(ob->query_fuel())){  
 	ob->set_fuel(); 
	remove();
        return 1;
    }
    else {
        write("You already have oil in your lantern!");
    }
	return 1 ;
}
 
