//darkoil.c - Adapted from oil for dark lanterns by Circe 12/31/03
#include <std.h>

inherit OBJECT;

void create() {
  ::create();
    set_name("dark oil");
    set_id(({"oil","flask","flask of oil","flask of dark oil","dark oil"}));
    set_short("A flask of dark oil");
    set_long("This round flask is filled with dark smoky liquid that "+
       "swirls continually.  It seems to emit a darkness all its own, but "+
       "it would have to be in a lantern for it to work fully.  "+
       "You can <fill dark lantern with oil>.");
    set_weight(1);
    set_value(100);
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
    if((sscanf(str, "%s with %s", lantern, oil)) != 2) return 0;
    if(strsrch(lantern, "lantern") == -1)  // if they don't mention lantern, fall thru
	return 0;
// if they do mention lantern, they need a meaningful failure message
    if(lantern != "dark lantern") {
        write("This oil will only work with dark lanterns.\n");
        return 1;
    }
    if(!(ob = present(lantern,TP))) {
        write("You do not have any "+lantern+" to fill!\n");
        return 1;
    }
    if(!(present(lantern,TP)->id("dark lantern"))) {
        write("You can't put oil in that!\n");
        return 1;
    }
      if( ob->query_fuel() < 500 ){  
         ob->set_fuel(); 
         remove();
         return 1;
    }
    else {
        write("Your dark lantern still has quite a bit of fuel left.");
    }
	return 1 ;
}
 
