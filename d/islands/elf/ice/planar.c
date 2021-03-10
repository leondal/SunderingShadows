#include <std.h>
#include "../elf.h"
inherit VAULT;
string place;
void create(){
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(GAME_TRACK);
    set_climate("mountain");
    set_name("planar pathway");
    set_short("planar pathway");
    set_long("A planar pathway.");
   set_listen("default",
   "There is a static buzz of magic.");
   set_smell("default",
   "There is a strange smell here one cannot discribe.");
   set_property("no teleport",1);
}
void set_place(string str){
place = str;
}
void send_place(){
TP->move(place);
TP->set_paralyzed(5,"You feel like puking");
}
void play_scene(int cnt){
string *msg;
msg = ({"You touch the stone and it resonates with the flower.",
"There is a bright %^RESET%^flash of magic%^MAGENTA%^ and you find yourself floating through some strange plane of %^CYAN%^sparking mist.",
"%^BOLD%^%^RED%^Suddenly you start to fall.",
"You pick up speed an can see no end in sight, your stomach feels like it is doing flips making you feel nauseous.",
"                %^YELLOW%^AHHHHHHH",
"				    %^RESET%^%^BOLD%^NOOO!",					
"%^BOLD%^You're gonna die!!!!!",
"           Your imagination runs wild with %^RED%^images of your broken body hitting the ground%^MAGENTA%^ and leaving a rather %^BOLD%^%^RED%^gross heap of flesh. ",
"                               %^RESET%^ AHHHHH!!!!!",
"								  %^RESET%^%^BOLD%^STOOOOOOP!!!",
" You scream---are you really screaming?  This strange fall has no up, down or anything.  It is extremely %^BOLD%^disconcerting.  ",
"Just when you are about to give up there is a %^RESET%^flash%^MAGENTA%^ and you find yourself standing somewhere else feelingly like you are going to %^RED%^puke."});

 write("%^MAGENTA%^"+msg[cnt]+"\n");
 if (cnt == sizeof(msg)-1){ 
   send_place();
   return;
   }
 call_out("play_scene",4,cnt+1); 
 return;
}
void init(){
::init();
play_scene(0);
TP->set_disable(40);
}
