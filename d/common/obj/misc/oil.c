// added reg_oil id to distinguish from dark oil addition, *Styx* 12/31/03, last chg. 10/29/02

#include <std.h>

inherit OBJECT;

void create() {
  ::create();
    set_name("oil");
    set_id( ({ "oil","flask","flask of oil", "reg_oil" }) );
    set_short("A flask of lantern oil");
    set_long("A flask of lantern oil.  You may <fill lantern with "+
    "oil>.");
    set_weight(1);
    set_value(6);
    set_cointype("gold");
}
 
void init() {
    ::init();
    add_action("fill","fill");
}
 
int fill(string str) {
    object ob;
//    int fuel_left;
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
      if( ob->query_fuel() < 500 ){  
         ob->set_fuel(); 
         remove();
         return 1;
    }
    else {
        write("Your lantern still has quite a bit of fuel left.");
    }
	return 1 ;
}
 
