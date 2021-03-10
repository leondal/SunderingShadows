//27,17

#include <std.h>

inherit ROOM;
int is_virtual() { return 1; }



void init() {
    ::init();
    add_action("step", "step");
}


void create() {
set_indoors(0);
 ::create();
   set_terrain(BARREN);
   set_travel(FOOT_PATH);
 set_light(2);
 set_name("You're in the Desert");
 set_short("%^RESET%^%^ORANGE%^You're in the Desert%^RESET%^");
 set_long("%^RESET%^You are in a vast desert. You can see nothing"+
" but sand for miles and miles. The sun beats down on your head.\n"+
"\n%^BLACK%^%^BOLD%^There is a large rune drawn in black rock on "+
"the ground%^RESET%^\n\n");
 set_exits(([
     "west":"/d/shadow/virtual/desert/27,16.desert",
     "south":"/d/shadow/virtual/desert/28,17.desert",
     "north":"/d/shadow/virtual/desert/26,17.desert",
     "east":"/d/shadow/virtual/desert/27,18.desert"
]));
set_items
    (([
    ({"rune"}) : "%^BLACK%^%^BOLD%^Rocks have been arranged to "+
"create what looks like a rune you could step on...%^RESET%^",
]));
set_smell("default","%^RESET%^%^ORANGE%^The dry desert air fills"+
" your nostrils.%^RESET%^");
set_listen("default","%^RESET%^%^GREEN%^You can hear the breeze "+
"blowing over the sand, it is so quiet here.%^RESET%^");

}

void reset() {
   ::reset();
   if(!present("Shannon Doren"))
      new("/d/shadow/room/githyanki/mobs/shannon_doren.c")->move(TO);
   }

int step(string str){
    if(!str) {
       tell_object(TP,"%^BLACK%^%^BOLD%^Step on what?\n%^RESET%^");
    return 1;
    }
    
    if(str == "rune" || "on rune"){
        tell_object(TP,"%^RED%^you step on the rune and you feel"+
" yourself launch quickly into the air!%^RESET%^");
        tell_room(ETP,"%^RESET%^%^RED%^As "+TPQCN+"%^RESET%^%^RED%^"+
" steps on the runes, they fly quickly into the air towards the fortress!%^RESET%^",TP);
        TP->move_player("/d/shadow/room/githyanki/rooms/1_1.c");
        tell_object(TP,"%^BLACK%^%^BOLD%^You land inside the fortress with a thump!%^RESET%^");
    return 1;
    }
}
