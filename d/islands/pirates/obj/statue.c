#include <std.h>
inherit OBJECT;

#define TYPES ({"an %^WHITE%^%^BOLD%^ivory","a %^GREEN%^%^BOLD%^jade","an %^BLACK%^%^BOLD%^ebony","an %^BLACK%^%^BOLD%^onyx","a %^CYAN%^%^BOLD%^crystalline","an %^RESET%^%^ORANGE%^amber"})
#define DESIGNS ({"a dancing elven silhouette","a pouncing panther","a coiled serpent","a magnificent eagle","a leaping dolphin","a razor-sharp curved dagger","a wide-boughed oak tree","a loyal hound","a tiny finch","a blooming rose","three small children","a slinking lizard","a wailing wraith","a great dragon with spread wings","a shield crossed by a longsword","a small scarab","a bare human skull"})
int type,type2;

void create(){
   ::create();
   type = random(sizeof(TYPES));
   type2 = random(sizeof(DESIGNS));
   set_name("statue");
   set_id(({"statue"}));
   set_short(""+TYPES[type]+"%^RESET%^ statue of "+DESIGNS[type2]+"");
   set_long("This statue is exquisitely crafted from "+TYPES[type]+".  The superb design captures the details of "+DESIGNS[type2]+" perfectly.  For a work of art this flawlessly created, it would probably be worth quite a sum of money.");
   set_weight(1);
   set_value(1000+random(700));
}
