#include <std.h>
inherit OBJECT;

int type,type2;
#define TYPES ({"an %^ORANGE%^oil painting","a %^BOLD%^%^BLACK%^charcoal sketch","a %^BLUE%^watercolor image","a %^RED%^layered print","a %^MAGENTA%^chalk pastel drawing","a %^CYAN%^delicate painted glass","a %^ORANGE%^glazed ceramic plate"})
#define IDZ ({"painting","sketch","image","print","drawing","glass","plate"})
#define DESIGNS ({"a still pond","a rolling landscape","a solemn cathedral","a flock of sparrows","a quiet farmyard","a herd of wild horses","a moonlight night","a brilliant sunrise","a magnificent dragon in flight","a golden griffon","a stealthy assassin","a small town at night","cheerful halflings","a gnome tinkerer","a bowl of fruit","a cloudswept sky","a dark and ominous forest","colorful roses"})

void create(){
   ::create();
   type = random(sizeof(TYPES));
   type2 = random(sizeof(DESIGNS));
   set_name("artwork");
   set_id(({"artwork",IDZ[type]}));
   set_short("%^RESET%^"+TYPES[type]+"%^RESET%^ of "+DESIGNS[type2]+"");
   set_long("%^RESET%^This artwork is breathtaking to look upon. The "+IDZ[type]+" captures a fantastic scene of "+DESIGNS[type2]+", right down to the tiniest detail.  For a work of art this finely made, it would probably be worth quite a sum of money.");
   set_weight(1);
   set_value(10000+random(1500));
}