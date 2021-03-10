#include <std.h>
inherit OBJECT;

#define GEMS ({"%^YELLOW%^topaz","%^BOLD%^%^WHITE%^moonstone","quartz","%^MAGENTA%^amethyst","%^ORANGE%^amber","%^BOLD%^%^RED%^agate","%^BOLD%^%^CYAN%^aquamarine","%^ORANGE%^tiger's eye","%^RED%^garnet","%^BOLD%^%^BLACK%^onyx","%^GREEN%^malachite","%^YELLOW%^citrine","%^GREEN%^bloodstone","%^BOLD%^%^MAGENTA%^tourmaline","%^BOLD%^%^RED%^carnelian","%^BOLD%^%^BLACK%^hematite"})

void create() {
   int i, j, val;
   string str;
   ::create();
   j = random(sizeof(GEMS)-1);
   str = GEMS[j];
   val = random(150);
   set_id(({"gem",str}));
   set_name("gem");
   switch(val) {
     case 0..40:
       set_long("%^BOLD%^%^WHITE%^This is a tiny %^RESET%^"+str+"%^BOLD%^%^WHITE%^. The light catches in the "
"gem and it looks like it would sell for a bit of money.");
       set_short("%^RESET%^A tiny "+str+"%^RESET%^");
       set_weight(1);
     break;
     case 41..80:
       set_long("%^BOLD%^%^WHITE%^This is a small %^RESET%^"+str+"%^BOLD%^%^WHITE%^. The light catches in the "
"gem and it looks like it would sell for a fair price.");
       set_short("%^RESET%^A small "+str+"%^RESET%^");
       set_weight(2);
     break;
     case 81..100:
       set_long("%^BOLD%^%^WHITE%^This is a polished %^RESET%^"+str+"%^BOLD%^%^WHITE%^. The light reflects off "
"the gem beautifully and you could probably get a nice sum of money for it.");
       set_short("%^RESET%^A polished piece of "+str+"%^RESET%^");
       set_weight(2);
     break;
     case 101..150:
       set_long("%^BOLD%^%^WHITE%^This is a cut piece of %^RESET%^"+str+"%^BOLD%^%^WHITE%^ that would no doubt "
"bring in quite a bit of money if you could find a buyer.");
       set_short("%^RESET%^A cut piece of "+str+"%^RESET%^");
       set_weight(2);
     break;
   }
   if(val < 20) {
      set_value(20);
   }
   else {
      set_value(val);
   }
}

int is_gem() { return 1; }
