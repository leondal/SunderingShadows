#include <std.h>
#include "../witchlair.h"
inherit CROOM;

object ob;
void pick_critters();

void create(){
   pick_critters();
   set_repop(30);
   ::create();
   set_property("light",1);
   set_property("no sticks",0);
   set_property("no teleport",0);
   set_property("no starve",0);
   set_property("no magic",0);
   set_property("no steal",0);
   set_short("%^RESET%^%^BLUE%^Edge of a %^CYAN%^misty "
"%^BLUE%^grove%^RESET%^");
   set_long("%^RESET%^%^BLUE%^Edge of a %^CYAN%^misty "
"%^BLUE%^grove\n\n"
"%^RESET%^%^BLUE%^The %^CYAN%^fog %^BLUE%^is dense here, thick "
"enough that you can barely see inches in front of your face. "
"Despite this, you still feel the presence of the trees you saw "
"through the arch...and can't help wondering just what could be "
"stalking among their branches. Whorls of the mist twist and curl"
" across the ground around your feet, almost as though directed "
"by some unseen force. A near tangible feel of %^RED%^malice "
"%^BLUE%^hangs in the air here, made only more unsettling by the "
"echoed sound of breathing from somewhere in the mist.\n"
"%^RESET%^%^BLUE%^A wall of blackened %^GREEN%^vines %^BLUE%^rises"
" from the ground here, the %^GREEN%^thorn-covered %^BLUE%^twisting"
" mass surrounding the grove in a ring.%^RESET%^");
   set_items(([
     ({"ground","leaves"}):"%^RESET%^%^BLUE%^Only by leaning down"
" can you actually see the ground here...and it's covered in a "
"thick carpet of dead, %^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^l"
"%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^k-and-b"
"%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^own %^RESET%^%^ORANGE%^l"
"%^GREEN%^e%^BOLD%^%^GREEN%^a%^RESET%^%^ORANGE%^ves%^BLUE%^. Must"
" be why you can't even hear your own footsteps.",
     ({"fog","mist","haze"}):"%^RESET%^%^CYAN%^Almost certainly"
" unnatural, the heavy mist seems to writhe and twist at times "
"like a broken puppet. Perhaps more puzzling is its tendency "
"to change at random from chilling fog to a warm, rainforest-like"
" mist.",
     ({"trees"}):"%^RESET%^%^CYAN%^You can't even see them, the "
"mist is so thick.",
     ({"wall","thorns","vines"}):"%^GREEN%^A great barrier of t"
"%^BOLD%^%^GREEN%^h%^BLACK%^o%^RESET%^%^GREEN%^rny vines grows "
"here, rising into the mist beyond your vision. You suspect if "
"you followed it, you'd find it to completely surround this "
"dark copse.",
   ]));
}

void pick_critters(){
   switch(random(5)){
     case 0: set_monsters(({MON"goblin2",MON"goblin3"}),({random(2),1}));
     break;
     case 1: set_monsters(({MON"goblin2",MON"goblin1"}),({random(2),1}));
     break;
     case 2: set_monsters(({MON"goblin3",MON"goblin1"}),({random(2)+1,random(2)}));
     break;
     case 3..4: break;
   }
}
