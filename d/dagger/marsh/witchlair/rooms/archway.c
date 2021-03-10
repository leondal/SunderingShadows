#include <std.h>
inherit ROOM;
#include "../witchlair.h"
void init() {
  ::init();
  add_action("insert_func","insert");
}
void create() {
 ::create();
 set_property("light",1);
 set_property("no sticks",0);
 set_property("no teleport",0);
 set_property("no starve",0);
 set_property("no magic",0);
 set_property("no steal",0);
 set_name("archway");
 set_short("%^RESET%^%^GREEN%^A %^CYAN%^clearing %^GREEN%^in"
" the marsh%^RESET%^");
 set_long("%^RESET%^%^GREEN%^A %^RED%^ru%^WHITE%^i"
"%^BOLD%^%^BLACK%^n%^RESET%^%^RED%^ed %^ORANGE%^archway\n\n"
"%^RESET%^%^GREEN%^Upon crossing the gap in the marsh growth, "
"you find yourself in a small, tree-flanked clearing. Little "
"of note is here, save for a large %^ORANGE%^stone archway "
"%^GREEN%^in the middle of the clearing. Only after pausing "
"to observe the monument do you notice...the sounds of the "
"marsh have faded away. Now that you notice, the trees around "
"you all but block off the sky, casting a %^BLUE%^gloom "
"%^GREEN%^over the clearing.");
 set_smell("default","It smells of dead leaves here.");
 set_listen("default","It is deathly quiet here...");
 set_items(([
  ({"ground", "leaves"}) : "%^RESET%^%^BLUE%^Only by leaning "
"down can you actually see the ground here, and it's covered "
"in a thick carpet of dead, %^BOLD%^%^BLACK%^b"
"%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^c"
"%^BOLD%^%^BLACK%^k-a%^RESET%^%^ORANGE%^%^BOLD%^%^BLACK%^nd-b"
"%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^own %^RESET%^%^ORANGE%^l"
"%^GREEN%^e%^BOLD%^%^GREEN%^a%^RESET%^%^ORANGE%^ves%^BLUE%^. "
"Must be why you can't even hear your own footsteps.",
 ({"arch", "archway"}) : "%^BOLD%^%^BLACK%^Carved from dark "
"gray stone, it is perhaps ten feet in heigh, and a bit over "
"half that in width. The stone is rather simple, with little "
"decoration beyond a series of strange, clawmark-like runes "
"carved into the apex of the arch, and a small depression "
"near one of its bases. Peering through the arch yields a "
"very strange sight: instead of the other side of the clearing"
", a dense grove of leafless trees clutched by a dark "
"%^RESET%^%^CYAN%^haze%^BOLD%^%^BLACK%^.",
  ({"fog", "mist", "haze"}) : "%^RESET%^%^CYAN%^Strangely enough, it "
"can only be seen through the odd, solitary archway here. "
"The thick haze does not seem a natural force, moving about "
"as it is...",
  ({"depression","hole"}) : "%^BOLD%^%^BLACK%^At the base of the arch's "
"left end is a small hole, with inscriptions that you hadn't noticed "
"before, only visible if one kneels and takes a closer look at the "
"depression. Unfortunately, the runes are in a tongue that you can't "
"seem to identify, but you get the feeling that you could "
"%^CYAN%^insert %^BLACK%^something here.",
  ]));
 set_exits(([
   "archway":ROOMS"grove1",
   "southwest":"/d/dagger/marsh/swamp/rooms/m_p003_p003",
 ]));
   set_search("default","%^RESET%^%^BLUE%^That %^ORANGE%^archway"
" %^BLUE%^is pretty conspicuous...");
   set_search("arch",(:TO,"arch_search":));
   set_search("archway",(:TO,"arch_search":));
}

int arch_search(string str){
   tell_object(TP,"%^BOLD%^%^BLACK%^You kneel down and begin"
" to examine the strange %^RESET%^%^BLUE%^hole "
"%^BOLD%^%^BLACK%^at the base of the %^RESET%^%^ORANGE%^sto"
"%^WHITE%^n%^ORANGE%^e ar%^WHITE%^ch%^ORANGE%^way"
"%^BOLD%^%^BLACK%^.\n"
"%^BOLD%^%^BLACK%^You realize that you could probably "
"%^CYAN%^insert %^BLACK%^something here!");
   tell_room(ETO,"%^RESET%^%^BLUE%^"+TPQCN+" kneels down and"
" examines something at the base of the "
"%^RESET%^%^ORANGE%^sto%^WHITE%^n%^ORANGE%^e ar%^WHITE%^ch"
"%^ORANGE%^way%^BOLD%^%^BLACK%^.",TP);
}

int insert_func(string str) {
  if(!str) {
    notify_fail("Um, insert what?\n");
    return 0;
  }
  if(str != "fetish") {
    notify_fail("Um, insert what?\n");
    return 0;
  }
  if(!present("fetishkey",TP)){
    write("%^RESET%^%^BLUE%^Seems you don't have that on "
"you.");
    say("%^RESET%^%^BLUE%^"+TPQCN+" fiddles around with the "
"hole at the archway's bottom.",TP);
    return 1;
  } else {
    write("%^BOLD%^%^CYAN%^Realizing its purpose, you slide "
"the key into place...and are drawn in as the portal "
"awakens!");
    say("%^RESET%^%^RED%^"+TPQCN+" inserts the key into the "
"archway...and suddenly %^CYAN%^v%^MAGENTA%^a"
"%^BOLD%^%^MAGENTA%^n%^CYAN%^i%^RESET%^%^CYAN%^s%^MAGENTA%^h"
"%^BOLD%^%^MAGENTA%^e%^CYAN%^s %^RESET%^%^RED%^in a burst "
"of light!",TP);
    TP->move_player("/d/dagger/marsh/witchlair/rooms/clearing1.c");
    return 1;
  }
}
