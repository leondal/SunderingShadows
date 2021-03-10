inherit "/std/Object";
 
int query_bait();
int query_pole_class();
int query_broken();
int break_pole();
void unbait();
int broken;
int bait;
 
void init() {
    add_action("bait_it","bait");
}
 
void create() {
    ::create();
    set_name("stick");
   set_id( ({ "stick", "fishing pole", "hook", "rod", "string" }) );
    set("value", 20);
    set("weight", 28);
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
        return ("A Strong rod, with a device near the handle, that holds string and runs through small loops up to the end of the pole. At the end of the string, is a bent piece of metal, with a shiney barbed hook attached to the end of it.");
    }
}
 
string query_short() {
    if(!broken) {
        if(!bait) return "A fancy fishing rod.";
        else return "A fancy fishing rod. (baited)";
    }
    else return "A fancy fishing rod (broken)";
}
 
int query_pole_class() {
    return 5;
}
 
int query_bait() {
    return bait;
}
 
int bait_it(string str) {
    string pole, the_bait;
    if(!str) return 0;
    if((sscanf(str, "%s with %s", pole, the_bait)) !=2) return 0;
    if(pole != "stick" && pole != "hook") return 0;
    if(!present(the_bait,this_player())) {
        write("You do not have any "+the_bait+" to bait your stick!\n");
        return 1;
    }
    if(!(present(the_bait,this_player())->id("bait"))) {
        write("You can't use that as bait!\n");
        return 1;
    }
    if(!bait) {
        bait = (100-(int)present(the_bait, this_player())->query_strength())/7;
        write("You bait your hook with "+the_bait+".\n");
  
    say(this_player()->query_cap_name()+" baits "+(string)this_player()->query_possessive()+" stick.\n");
       present(the_bait,this_player())->remove();
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
    set("value", 10);
    set_destroy();
    broken = 1;
}
 
