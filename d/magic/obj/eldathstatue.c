#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("statue");
   set_id(({ "statue", "crystalline statue","statue of a woman"}));
   set_short("%^BOLD%^%^WHITE%^A crystalline statue of a woman%^RESET%^");
   set_long("%^CYAN%^Fashioned out of %^BOLD%^%^WHITE%^crystal %^RESET%^%^CYAN%^is a "
"statue of a woman leaning over the %^BOLD%^spring%^RESET%^%^CYAN%^.  Her slender fingers "
"dip into the water, as if nurturing it.  The woman is carved to be dressed in a simple "
"shift that clings to her body, but strangely enough not in a lustful manner.  Etched "
"upon her face is a look of %^GREEN%^peace %^CYAN%^and %^BOLD%^serenity%^RESET%^%^CYAN%^, "
"as if she was in a state of pure calm.  Her hair cascades over her back like a "
"waterfall.  She rests on a base that is overgrown with %^GREEN%^moss%^CYAN%^, giving her "
"the appearance of a connection with nature.  An aura of "
"%^BOLD%^%^BLUE%^peace%^RESET%^%^CYAN%^ radiates outwards from the statue, spreading "
"deep into the grove and forest.%^RESET%^");
   set_weight(1000);
   set_value(0);
   set_property("no animate", 1);
}
