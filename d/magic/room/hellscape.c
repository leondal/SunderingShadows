#include <std.h>;
inherit ROOM;

void create(){
   ::create();
   set_property("indoors", 1);
   set_property("light", 1);
   set_property("no teleport",1);
   set_smell("default", "The air is thick with the smell of brimstone.");
   set_listen("default", "You can't hear anything.");
   set_short("%^BOLD%^%^WHITE%^Inside white void");
   set_long("%^BOLD%^%^BLACK%^This is a %^RESET%^%^CYAN%^immense%^BOLD%^%^BLACK%^ cavern stretching %^RESET%^%^WHITE%^thousands%^BOLD%^%^BLACK%^ of feet in all directions. The %^RED%^heat%^BOLD%^%^BLACK%^ in here is almost unbearable. A g%^CYAN%^i%^BOLD%^%^BLACK%^gant%^WHITE%^i%^BOLD%^%^BLACK%^c %^CYAN%^obs%^WHITE%^i%^BOLD%^%^BLACK%^di%^CYAN%^a%^BOLD%^%^BLACK%^n %^WHITE%^staircase%^BOLD%^%^BLACK%^ rises hundred feet into the air and at the far end a %^RESET%^%^MAGENTA%^massive%^BOLD%^%^BLACK%^ t%^YELLOW%^h%^BLACK%^r%^YELLOW%^o%^BLACK%^n%^YELLOW%^e%^BOLD%^%^BLACK%^ resides. Made of %^RED%^d%^BLACK%^e%^RED%^m%^BLACK%^o%^RED%^n %^WHITE%^skulls%^BOLD%^%^BLACK%^ and %^WHITE%^bones%^BOLD%^%^BLACK%^ the massive t%^YELLOW%^h%^BLACK%^r%^YELLOW%^o%^BLACK%^n%^YELLOW%^e%^BOLD%^%^BLACK%^ could seat a %^CYAN%^giant%^BOLD%^%^BLACK%^. %^RED%^Bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^ seeps from the %^RED%^e%^YELLOW%^y%^RED%^es%^BOLD%^%^BLACK%^ and %^MAGENTA%^mouth%^BOLD%^%^BLACK%^ of the %^WHITE%^skulls%^BOLD%^%^BLACK%^ and a small %^RESET%^%^GREEN%^river%^BOLD%^%^BLACK%^ of %^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^ runs down the stairs ending into a large %^RESET%^%^RED%^pool%^BOLD%^%^BLACK%^ of boiling %^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^ that bubbles in the %^RED%^h%^YELLOW%^e%^RESET%^%^RED%^a%^BOLD%^%^RED%^t%^BOLD%^%^BLACK%^. The steps are large and sticky. %^RED%^H%^YELLOW%^e%^BLACK%^ll%^RED%^f%^YELLOW%^i%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^e roars around the edges of the %^CYAN%^staircase%^BOLD%^%^BLACK%^ and the waves of %^RED%^h%^YELLOW%^e%^RESET%^%^RED%^a%^BOLD%^%^RED%^t%^BOLD%^%^BLACK%^ almost %^RED%^blisters%^BOLD%^%^BLACK%^ your skin. Sh%^CYAN%^a%^BOLD%^%^BLACK%^pes and f%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^rms %^MAGENTA%^phases %^BOLD%^%^BLACK%^in and out of %^CYAN%^existence%^BOLD%^%^BLACK%^ around you and the %^RESET%^%^MAGENTA%^wailing%^BOLD%^%^BLACK%^ screams of a%^RED%^g%^BOLD%^%^BLACK%^ony pierces the room making your ears %^RED%^bleed.");
}