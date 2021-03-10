#include <std.h>
inherit OBJECT;

int type,type2;
#define TYPES ({"an %^BOLD%^%^WHITE%^ivory","a %^GREEN%^jade","an %^BOLD%^%^BLACK%^ebony","an %^BOLD%^%^BLACK%^onyx","a %^BOLD%^%^CYAN%^crystalline","an %^ORANGE%^amber","an %^RED%^oak","a %^BOLD%^%^WHITE%^bone","an %^BOLD%^%^BLACK%^obsidian"})
#define IDZ ({"%^BOLD%^%^WHITE%^ivory","%^GREEN%^jade","%^BOLD%^%^BLACK%^ebony","%^BOLD%^%^BLACK%^onyx","%^BOLD%^%^CYAN%^crystal","%^ORANGE%^amber","%^RED%^oak","%^BOLD%^%^WHITE%^bone","%^BOLD%^%^BLACK%^obsidian"})
#define DESIGNS ({"a dancing elven silhouette","a pouncing panther","a coiled serpent","a magnificent eagle","a leaping dolphin","a razor-sharp curved dagger","a wide-boughed oak tree","a loyal hound","a tiny finch","a blooming rose","three small children","a slinking lizard","a wailing wraith","a great dragon with spread wings","a shield crossed by a longsword","a small scarab","a bare human skull","a moon and three stars","a rearing unicorn"})

void create(){
   ::create();
   type = random(sizeof(TYPES));
   type2 = random(sizeof(DESIGNS));
   set_name("statue");
   set_id(({"statue"}));
   set_short("%^RESET%^"+TYPES[type]+"%^RESET%^ statue of "+DESIGNS[type2]+"");
   set_long("%^RESET%^This statue is exquisitely crafted from "+IDZ[type]+"%^RESET%^.  The superb design captures the details of "+DESIGNS[type2]+" perfectly, and its surface has been polished smooth.  For a work of art this finely carved, it would probably be worth quite a sum of money.");
   set_weight(1);
   set_value(8000+random(1500));
}