//cemetery.c - inherited room for cemetery w/undead, rats, snakes, & bats
#include <std.h>
#include "graveyard.h"
inherit CROOM;

object ob;
void pick_critters();

void create(){
   pick_critters();
   set_repop(60);
   ::create();
   set_name("Rundown cemetary");
   set_property("light",2);
   set_property("no teleport",1);
   set_short("%^ORANGE%^Rundown cemetery%^RESET%^");
   set_terrain(CEMETERY);
   set_travel(FOOT_PATH);
   set_long((:TO,"ldesc":));
   set("night long",(:TO,"ndesc":));
   set_smell("default","You smell the damp soil where the graves have been disturbed.");
   set_listen("default","You hear groaning sounds around the trees you hope is just the wind.");
   set_items( ([
     "trees":"%^ORANGE%^The gnarled trees cast eerie shadows of their own.%^RESET%^", 
     "grass":"%^ORANGE%^Meagre patches of grass struggle to grow in a few places.%^RESET%^", 
     ({"headstones", "headstone"}):"%^ORANGE%^The writing on most of the headstones is only partially legible. "
" In most cases the soft stone has been damaged or simply worn and crumbled away.%^RESET%^", 
     "fence":"%^ORANGE%^The fence looks much like a series of rusty polearms standing on end a foot or so "
"apart with horizontal bars holding them together.%^RESET%^",
   ]) );
}

string ldesc(string str) {
   return("%^BOLD%^%^BLACK%^Rundown Cemetary%^RESET%^\n%^ORANGE%^You've entered an overgrown and rundown "
"cemetery.  Crumbling %^BOLD%^%^BLACK%^headstones %^RESET%^%^ORANGE%^have been knocked over and a few of the "
"graves look like they've been dug up or disturbed in some fashion.  Gnarled %^GREEN%^trees %^ORANGE%^grow "
"along the %^BOLD%^%^BLACK%^fence%^RESET%^%^ORANGE%^ marking the edges of the graveyard.  The %^GREEN%^grass "
"%^ORANGE%^is thin and looks trampled over where it's managed to grow very tall.%^RESET%^\n");
}

string ndesc(string str) {
   return("%^BOLD%^%^BLACK%^Rundown Cemetary%^RESET%^\n%^BLUE%^You've entered an overgrown and rundown "
"cemetery.  Crumbling %^BOLD%^%^BLACK%^headstones %^RESET%^%^BLUE%^have been knocked over and a few of the "
"graves look like they've been dug up or disturbed in some fashion.  Gnarled %^GREEN%^trees %^BLUE%^grow along "
"the %^BOLD%^%^BLACK%^fence%^RESET%^%^BLUE%^ marking the edge of the graveyard.  The shadows from the "
"moonlight and lanterns dance eerily across the ground.%^RESET%^\n");
}

void reset() {
   int active;
   active = has_mobs();
   if(!active) {
     if(mons) mons = ([]);
     pick_critters();
   }
   ::reset();
   switch(random(10)){
     case 0..2: break;
     case 3: tell_room(TO,"%^ORANGE%^A small breath of wind stirs the scraggly grass."); break;
     case 4: tell_room(TO,"%^CYAN%^A low moan echoes around the graveyard... hopefully just the wind?"); break;
     case 5: tell_room(TO,"%^GREEN%^The smell of decay and death tickles unpleasantly at your nose."); break;
     case 6: tell_room(TO,"%^BOLD%^%^BLACK%^You hear a faint scuffling from behind you."); break;
     case 7: tell_room(TO,"%^BOLD%^%^CYAN%^A brief, cold wind brushes past you, making you shiver."); break;
     case 8: tell_room(TO,"%^MAGENTA%^The hairs on the back of your neck tingle, sending chills down your spine."); break;
     case 9: tell_room(TO,"%^RED%^You realise you can hear your own heartbeat in the near-silence of the graveyard."); break;
     default: break;
   }
}

void pick_critters() {
   if(query_night() == 1) {
     switch(random(9)){
       case 0: set_monsters(({MONS"skeleton"}),({1}) ); break;
       case 1: set_monsters(({MONS"zombie"}),({1}) ); break;
       case 2: set_monsters(({MONS"zombiem"}),({1}) ); break;
       case 3: set_monsters(({MON"rat",MONS"zombie"}),({1,1}) ); break;
       case 4: set_monsters(({MON"skeleton",MONS"zombie"}),({1,1}) ); break;
       case 5: set_monsters(({MON"rat",MON"bat",MONS"zombiem"}),({1,1,1}) ); break;
       case 6: set_monsters(({MON"bat",MONS"skeleton"}),({1,1}) ); break;
       case 7..8: break;
     }
   }
   else {
     switch(random(9)){
       case 0: set_monsters(({MON"rat"}),({1}) ); break;
       case 1: set_monsters(({MON"rat"}),({2}) ); break;
       case 2: set_monsters(({MON"snake"}),({1}) ); break;
       case 3: set_monsters(({MON"snake"}),({2}) ); break;
       case 4: set_monsters(({MON"rat",MON"snake"}),({1,1}) ); break;
       case 5: set_monsters(({MON"rat",MON"snake"}),({2,1}) ); break;
       case 6..8: break;
     }
   }
}
