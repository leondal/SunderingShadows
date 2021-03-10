#include <std.h>
#include "../dragon.h";

inherit OBJECT;

void create() {
   ::create();
   set_name("paper");
   set_id(({"paper"}));
   set_short("%^RESET%^%^GREEN%^A sheet of paper%^RESET%^");
   set_value(0);
   set_weight(0);
   set_long(
   "%^RESET%^%^YELLOW%^You look over the paper and read:\n"+
   "%^BOLD%^%^BLUE%^List of things to do:\n"+
   " %^RESET%^1) Send word to Malverin about our success in Sanctuary.\n"+
   " 2) Prepare the symbols for the six point summoning in the summoning chamber.\n"+
   " 3) Make sure the coffins with the best of the undead are ready to be shipped.\n"+
   " 4) Check the quality of the magical items awaiting inspection in the lab.\n"+
   "Personal note: I don't even know where to begin to send word to Malverin. I have"+
   " no clue where he is for sure. The last I was told he was building the fifth point"+
   " for the summoning on an island inhabited by dinosaurs. The symbols should be easy"+
   " enough to fix. My sister has them written down exactly. I will need to see her about"+
   " them. The coffins are already sealed, but Everardus insists that I check them three"+
   " to five times a day. I think he is being hard on me, because he is jealous of my mother."+
   " I helped my sister make the items in the lab, there should be no problem with them at all"+
   ", but I will check to be sure."
   );
}
