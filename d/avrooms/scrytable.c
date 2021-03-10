#include <std.h>
inherit OBJECT;

create() {
   ::create();
   set_name("mirror");
   set_id(({"table","stone table","top","grid","lines","bejeweled lines","mountain","mountain top","scrytable","mirror"}));
   set_short("%^BOLD%^%^BLACK%^a smooth topped stone table%^RESET%^");
   set_property("no animate", 1);
   set_long((:TO,"table_desc":));
   set("value", 1001);
   set_weight(100000);
   set_no_clean(1);
   set_heart_beat(1);
}

int get() { return 0; }
int drop() { return 1; }

string table_desc(){
   if(TO->query_property("magic mirror")) {
     return("%^BOLD%^%^BLACK%^Set in the center of the room, this table looks like nothing more then a %^RESET%^%^CYAN%^mountain top %^BOLD%^%^BLACK%^poking up through the %^WHITE%^cl%^CYAN%^o%^WHITE%^uds %^BLACK%^of the carpet below. This effect is made more apparent by the way that the sides have been left natural and slope "
"outward from the top, widening as they make their way to the floor. The top has been sheered away to provide a glossy %^CYAN%^sm%^RESET%^o%^CYAN%^o%^BOLD%^th %^BLACK%^surface into which %^RED%^j%^YELLOW%^e%^RESET%^%^ORANGE%^w%^GREEN%^e%^BLUE%^l%^CYAN%^e%^MAGENTA%^d %^BOLD%^%^BLACK%^lines have been etched in a grid pattern. At the moment, the jeweled lines seem alive, revealing a map of a distant place within their shimmering glow.%^RESET%^");
       }
     return("%^BOLD%^%^BLACK%^Set in the center of the room, this table looks like nothing more then a %^RESET%^%^CYAN%^mountain top %^BOLD%^%^BLACK%^poking up through the %^WHITE%^cl%^CYAN%^o%^WHITE%^uds %^BLACK%^of the carpet below. This effect is made more apparent by the way that the sides have been left natural and slope "
"outward from the top, widening as they make their way to the floor. The top has been sheered away to provide a glossy %^CYAN%^sm%^RESET%^o%^CYAN%^o%^BOLD%^th %^BLACK%^surface into which %^RED%^j%^YELLOW%^e%^RESET%^%^ORANGE%^w%^GREEN%^e%^BLUE%^l%^CYAN%^e%^MAGENTA%^d %^BOLD%^%^BLACK%^lines have been etched in a grid pattern. Though the lines seem inert at the moment, their colored patterns suggest a map of some sort. Maybe by %^CYAN%^view%^BLACK%^ing the %^CYAN%^grid %^BLACK%^one could cause it to reveal more.%^RESET%^");
}