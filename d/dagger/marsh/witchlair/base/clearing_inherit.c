#include <std.h>
#include "../witchlair.h"
inherit CROOM;

object ob;
void pick_critters();

void create() {
  pick_critters();
  set_repop(30);
  set_property("light",2);
  set_property("no sticks",0);
  set_property("no teleport",0);
  set_property("no starve",0);
  set_property("no magic",0);
  set_property("no steal",0);
  set_short("%^RESET%^%^GREEN%^Gr%^BOLD%^%^GREEN%^as"
"%^RESET%^%^GREEN%^sy clearing%^RESET%^");
  set_long("%^RESET%^%^GREEN%^Gr%^BOLD%^%^GREEN%^as"
"%^RESET%^%^GREEN%^sy clearing%^RESET%^\n\n"
"%^RESET%^%^GREEN%^You find yourself in a large glade in some "
"unknown wood. The clearing is beset on all sides by twisted, "
"blackened trees, beyond which is perpetual "
"%^BOLD%^%^BLACK%^darkness %^RESET%^%^GREEN%^that seems almost"
" to be reaching out for you...\n"
"In spite of the surrounding area, the clearing itself is "
"almost serene in its unbroken silence, %^YELLOW%^s%^WHITE%^u"
"%^YELLOW%^n%^RESET%^%^ORANGE%^l%^WHITE%^i%^YELLOW%^g"
"%^BOLD%^%^WHITE%^h%^YELLOW%^t %^RESET%^%^GREEN%^shining "
"through the light %^CYAN%^mi%^BOLD%^%^CYAN%^s"
"%^RESET%^%^CYAN%^t %^GREEN%^onto lush %^BOLD%^%^GREEN%^grass "
"%^RESET%^%^GREEN%^that sways in the breeze. It's almost too good to "
"be true.");
  set("night long","%^RESET%^%^GREEN%^Gr%^BOLD%^%^GREEN%^as"
"%^RESET%^%^GREEN%^sy clearing%^RESET%^\n\n"
"%^RESET%^%^GREEN%^You find yourself in a large glade in some "
"unknown wood. The clearing is beset on all sides by twisted, "
"blackened trees, beyond which is perpetual "
"%^BOLD%^%^BLACK%^darkness %^RESET%^%^GREEN%^that seems almost"
" to be reaching out for you...\n"
"In spite of the surrounding area, the clearing itself is "
"almost serene in its unbroken silence, %^BOLD%^%^WHITE%^mo"
"%^CYAN%^o%^BLACK%^n%^WHITE%^li%^CYAN%^g%^WHITE%^ht "
"%^RESET%^%^GREEN%^penetrating the %^CYAN%^mi%^BOLD%^%^CYAN%^s"
"%^RESET%^%^CYAN%^t %^GREEN%^in beams that cast a blessed "
"brightness onto the lush %^BOLD%^%^GREEN%^grass "
"%^RESET%^%^GREEN%^that covers the entirety of the clearing. "
"It's almost too good to be true.");
  set_smell("default","Ah, fresh air! Smells like it's rained "
"here recently, though.");
  set_listen("default","Peaceful as this place may appear, not "
"a sound can be heard...");
  set_items(([
    ({"trees","tree","wood","woods"}) : "%^BOLD%^%^BLACK%^The "
"trees almost seem to be in pain, writhing and twisting as if "
"something beyond your senses is tormenting them. An "
"impenetrable darkness lies beneath and between them, blocking "
"any and all sight past the closest trunks.",
    ({"fog","mist"}) : "%^RESET%^%^CYAN%^Though assuredly "
"thinner here, the presence of the sinister haze from the grove "
"is undeniable. It seems to be weakened here, struggling to "
"remain corporeal in this clearing.",
    "grass" : "%^RESET%^%^GREEN%^It covers the entire clearing "
"in a soft, verdant carpet.",
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
