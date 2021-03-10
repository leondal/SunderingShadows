#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",1);
    set_short("Sandys' Boat Shop.");
    set_long(""
"%^BOLD%^WHITE%^You are in a large boat shop.\n%^RESET%^"
"As you enter the shop, you notice several blue prints for sailing ships of all "
"types.  Out of a large window you can see the ship yard where they prepare ship"
" for exploring the ocean.  A man sits behind a counter ready to take your order "
"so you can explore like the great ones.  A list it hanging on the wall with "
"the prices of ships"
""
"");

     set_listen("default","You hear ships being built out side.");
     set_smell("default","You smell fresh lumber.");
    set_exits(([

       "out" : "/d/mine2/sandy/room/sandy11",


    ] ));
    set_items(([
         "blue prints" : "There are many plans of different ships hanging on the walls.",
         "shop" : "It is filled with many things related with boats.",
         "list" : "Try reading it!",
         "plans" : "There is only on type of ship you can buy.",
    ] ));
}
void init() {
::init();
add_action("read","read");
add_action("buy","buy");
}
int read(string str){
if(str = "list"){
write("%^BOLD%^WHITE%^Attention ship buyer! %^BOLD%^CYAN%^\n\n"
"To buy a ship you must have the following.\n"
"You must be level 20 or higher.\n"
"You must have 50000 gold coins with you.\n\n"
"To buy a ship, type <%^BOLD%^GREEN%^buy ship%^BOLD%^CYAN%^>.");
return 1;
}
}
int buy(string str) {
if(str = "boat"){
if(this_player()->query_level() > 19 ){
if(this_player()->query_money("gold", > 49999)){
write("You pay 50000 gold coins for a boat!\n"
"It may take a week or so for you boat to be made");
  this_player()->add_money( "gold", -50000");
     write_file("/d/mine2/sandy/buyers", (string)this_player()->query_name()+
}
}
}
}
