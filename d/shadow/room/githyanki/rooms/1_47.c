#include <std.h>
#include "../githyanki.h"

inherit STORAGE"1floor.c";

void init() {
    ::init();
    add_action("light", "light");
}

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^%^ORANGE%^The hall continues north and south%^RESET%^\n");
   set_exits(([
   "south" : ROOMS"1_48",
   "north" : ROOMS"1_46",
]));  
    
    set_door("ornate door",ROOMS"1_38","west",1);
    set_door_description("ornate door","%^RESET%^%^ORANGE%^Formed from stone, this door"+
" has been carved with a stunning array of glyphs and symbols, most of them obviously alien in origin.%^RESET%^");
    set_string("ornate door", "open", "%^RESET%^%^BOLD%^You push against the heavy door and it opens slowly.%^RESET%^");
    set_string("ornate door", "close", "%^RESET%^%^BOLD%^You close the heavy stone door slowly%^RESET%^%^BOLD%^.");
    remove_exit("west");
    lit = 0;

}

int light(string str){
    if(!str) {
       tell_object(TP,"%^BLACK%^%^BOLD%^Light what?\n%^RESET%^");
       return 1;
    }
    if(str != "torch"){
       tell_object(TP,"%^BLACK%^%^BOLD%^Light what?\n%^RESET%^");
       return 1;
    }
       tell_room(TP,"%^YELLOW%^As the torch sputters to life, a door appears%^RESET%^\n");
       lit = 1;
       add_exit("1_38", "west");
    return 1;
}
