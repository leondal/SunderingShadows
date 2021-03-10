#include <std.h>
inherit ARMOUR;
object owner;
object plate; 
string owned;
void check_plate(object owner, object plate);
 
void create(){
	::create();
	set_wear((:this_object(),"wearit":));
}

int check_plate(object owner, object plate) {
    owned = (string)owner->query_name();
    plate->set_wear((:this_object(),"wearit":));
    return 1;
}

void wearit(){
/*
 if(interactive(TP))
        if((string)this_player()->query_name() != owned) {
         write("This armor was fitted for someone else.");
            write("It fails to fit you!");
            return 0;
        } else {
            write("The armor fits your body perfectly.");
            return 1;
        }
  owned = TP->query_name();
*/
//Removing the ownered function - it is outdated and causes more problems than it solves ~Circe~ 11/7/15
    return 1;
}

int is_plate() { return 1;}

void set_owned(object blah){
    owned = (string)blah->query_name();
}
