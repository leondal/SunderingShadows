/* fishing pole designed by Descartes for use in rooms that are fishing
   compatible.  The pole is really nothing special except in that
   you can bait it with anything that returns an id of bait and also
   in that it has the following functions called by fishing rooms:
   query_pole_class() returns an integer, the higher the number, the
        better the pole is for fishing.
   query_bait() returns an integer which is the strength of the bait,
        the higher the number, the better the bait is for fishing
   pole class should range from 2 (a horrible pole) to 7 (an absolutely
        awesome pole)
   bait strength, which is found out by the pole by calling a function
        in items which return an id of true for bait, should be a
        number between 0 (items fish wont eat) to 4 (yummy fish food)
*/
// fixes to add ::create(), ::init() and fix baiting by *Styx* 10/4/03

#include <std.h> 

inherit "/std/Object";
 
int query_bait();
int query_pole_class();
int query_broken();
int break_pole();
void unbait();
int broken;
int bait;
 
void init() {
    ::init();
    add_action("bait_it","bait");
}
 
void create() {
   ::create();
    set_name("stick");
    set_id( ({ "stick", "pole", "fishing pole", "hook", "string" }) );
    set_value(5);
    set_weight(3);
    broken = 0;
    bait = 0;
}
 
string query_long(string str) {
    if(str == "hook") {
        if(!bait) return ("Perhaps you could bait this with something?\n");
        else return ("It has bait on it.\n");
    }
    else if(str == "string") return ("A string with a hook at the end.\n");
    else {
        return ("A bamboo stick with a piece of string connected to the end.\n"
          "At the end of the string is a hook.  What a primitive looking fishing tool!\n");
    }
}
 
string query_short() {
    if(!broken) {
        if(!bait) return "A bamboo stick";
        else return "A bamboo stick (baited)";
    }
    else return "A bamboo stick (broken)";
}
 
int query_pole_class() { return 3; }
 
int query_bait() { return bait; }
 
int bait_it(string str) {
    string pole, the_bait;
// fixed up the failure messages too *Styx* 10/4/03
    if(!str) 
	return notify_fail("Try bait [what] with [what].\n");
    if((sscanf(str, "%s with %s", pole, the_bait)) != 2) 
	return notify_fail("Try <bait [what] with [what].\n");
//    if(pole != "stick" && pole != "hook") return 0;
    if(!(present(the_bait,TP)->id("bait")))
        return notify_fail("You can't use that as bait!\n");
    if(member_array(pole, TO->query_id()) == -1)
	return notify_fail("The "+pole+" doesn't seem to be something you can bait.\n");
    if(!present(the_bait,TP)) {
        write("You do not have any "+the_bait+" to bait your "+query_short()+"!\n");
        return 1;
    }
    if(!bait) {
        bait = (100-(int)present(the_bait, TP)->query_strength())/7;
        write("You bait your hook with "+the_bait+".");
        tell_room(ETP,TPQCN+" baits "+TP->query_possessive()+" "+query_short()+".", TP);
        present(the_bait,TP)->remove();
        return 1;
    }
    else {
        write("You already have bait on your hook!");
    }
    return 1;
}
 
void unbait() { bait = 0; }
 
int query_broken() { return broken; }
 
int break_pole() {
    set_value(0);
    set_destroy();
    broken = 1;
}