// inherit "/std/Object";
// changing to inherit the fishing pole for easier maintenance while bug fixing *Styx* 10/4/03
 
inherit "/d/common/obj/misc/fishing_pole.c";

/* ******* all handled by inherit now *Styx*  *************
int query_bait();
int query_pole_class();
int query_broken();
int break_pole();
void unbait();
int broken;
int bait;
 
void init() {
    add_action("bait_it","bait");
}  ******* all handled by inherit now *Styx*  *************
*/
 
void create() {
    ::create();
    set_name("fishing rod");
    set_id( ({ "stick", "fishing pole", "fishing rod", "hook", "rod", "string" }) );
    set_value(20);
    set_weight(5);
    broken = 0;
    bait = 4;
}
 
string query_long(string str) {
    if(str == "hook") {
        if(!bait) return ("Perhaps you could bait this with something?\n");
        else return ("It has bait on it.\n");
    }
    else if(str == "string") return ("A string with a hook at the end.\n");
    else {
        return ("A strong rod about four ft. long with a device near the handle that holds wound string.   The string runs through small loops along the length of the pole up to the end of the pole.  Attached to the end of the string is a bent piece of shiny metal that is shaped into a barbed hook.");
    }
}
 
string query_short() {
    if(!broken) {
        if(!bait) return "A fancy fishing rod";
        else return "A fancy fishing rod (baited)";
    }
    else return "A fancy fishing rod (broken)";
}
 
int query_pole_class() {
    return 5;
}

/* ******* all handled by inherit now *Styx*  *************
int query_bait() {
    return bait;
}
 
int bait_it(string str) {
    string pole, the_bait;
    object baitobj;
    if(!str) return 0;
    if((sscanf(str, "%s with %s", pole, the_bait)) !=2) return 0;
    if(pole != "stick" && pole != "hook" && pole != "rod") return 0;
    if(!present(the_bait,TP)) {
        write("You do not have any "+the_bait+" to bait your fishing rod!\n");
        return 1;
    }
    if(!(present(the_bait,TP)->id("bait"))) {
        write("You can't use that as bait!\n");
        return 1;
    }
    if(!bait) {
        bait = (100-(int)present(the_bait, TP)->query_strength())/7;
        write("You bait your hook with "+the_bait+".\n");
  
    say(TPQCN+" baits "+(string)this_player()->query_possessive()+" stick.\n");
        find_object(the_bait)->remove();
        return 1;
    }
    else {
        write("You already have bait on your hook!");
    }
    return 1;
}
 
void unbait() {
    bait = 0;
}
 
int query_broken(){
    return broken;
}
 
int break_pole() {
    set_value(0);
    set_destroy();
    broken = 1;
}
******* all handled by inherit now *Styx*  *************
*/
