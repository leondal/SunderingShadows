
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
	set_property("light",3);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Mysterious tropical paradise");
        set_long("%^GREEN%^My%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^te%^BOLD%^%^GREEN%^r%^GREEN%^i%^GREEN%^o%^RESET%^%^GREEN%^us %^GREEN%^t%^GREEN%^r%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^p%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^c%^BOLD%^%^GREEN%^a%^GREEN%^l %^RESET%^%^GREEN%^para%^BOLD%^%^GREEN%^d%^RESET%^%^GREEN%^is%^BOLD%^%^GREEN%^e%^RESET%^
%^BOLD%^%^GREEN%^You step out into a tropical paradise. It is just like the jungles of Attaya, yet more ordered. A mist shrouds %^RESET%^%^WHITE%^g%^BOLD%^%^WHITE%^r%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^nd %^WHITE%^lig%^RESET%^%^WHITE%^h%^BOLD%^%^WHITE%^t%^RESET%^%^WHITE%^i%^WHITE%^n%^BOLD%^%^WHITE%^g%^GREEN%^ far above you and the %^GREEN%^w%^BLACK%^alls%^GREEN%^ have been designed to mimic natural rock. Rich soil hosts a variety of tropical %^RESET%^%^GREEN%^pl%^BOLD%^%^GREEN%^a%^GREEN%^n%^GREEN%^t%^RESET%^%^GREEN%^s%^BOLD%^%^GREEN%^ and %^RESET%^%^GREEN%^tree%^BOLD%^%^GREEN%^s%^GREEN%^. %^RESET%^%^GREEN%^J%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^st%^BOLD%^%^GREEN%^ to the south, you can see a strange %^RESET%^%^MAGENTA%^b%^BOLD%^%^BLACK%^la%^RESET%^%^MAGENTA%^c%^BOLD%^%^BLACK%^k %^BLACK%^ve%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^.
");
       set_exits(([
       "east" : "/d/attaya/tower/cbattle",
       "south" : "/d/attaya/tower/floor18",
]));
  set_invis_exits( ({"south"}) );
       set_items(([
    "ground" : "You are on a small stone path.  Rich soil lies just off of it from which spring various tropical plants.",
    "plants" : "A wide variety of tropical plants flourishes here.",
    "trees" : "Royal palm trees stand in an orderly row along the path.",
    "walls" : "They have been covered with natural rock or carved.  It is hard to tell that you are still inside!",
    "veil" : "%^BLUE%^A phantom veil of deception hangs here, placed to hide this passage from the other side where the veil mimics a normal wall!",
    "lighting" : "It is impossible to see the source of the brilliant lighting that fills this chamber.  Mist hangs heavy in the air.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));

}
