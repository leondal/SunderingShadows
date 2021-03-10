#include <std.h>
#include "../ogres.h"

inherit STORAGE"1st.c";
object *trig_trap;

void create(){
   ::create();
   set_exits(([
      "down" : ROOMS"2_1",
   ]));

}
void init() {
    ::init();
    add_action("dig", "dig");
    if(!pointerp(trig_trap)) return;
    if(member_array(TP, trig_trap) != -1) return;
    if(!objectp(TP) || !interactive(TP) || wizardp(TP)) return;
    trig_trap += ({TP});
    tell_object(TP, "As you enter this room, your foot catches on somthing
and the walls all around you collapse violently, blocking the exit to the
north!");

}

void reset() {
    ::reset();
}

int dig(string str){
    if(str != "north") return 0;
    tell_object(TP, "There is simply too much rubble to dig out of the way.");
    return 1;
}

string query_long(string str){
    string tmp;
    tmp = ::query_long(str);
    tmp += "%^RESET%^%^ORANGE%^\nRubble is blocking the north exit.\n";
    return tmp;
}
