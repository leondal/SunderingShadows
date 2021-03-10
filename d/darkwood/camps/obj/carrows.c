#include <std.h>

inherit "/std/ammo";

create() {
   ::create();
   set_id(({ "arrows","larrows","longbow arrows","longbow arrow","quiver","missiles" }));
   set_name("arrows");
   set_short("A bundle of %^BOLD%^%^RED%^c%^BOLD%^%^YELLOW%^o%^BOLD%^%^BLUE%^l%^BOLD%^%^MAGENTA%^o%^BOLD%^%^CYAN%^r%^BOLD%^%^WHITE%^f%^RESET%^u%^BOLD%^%^GREEN%^l %^RESET%^arrows");
   set_long(
      "This is a bundle of flight arrows for a long bow. The arrows are fletched with the"+
      " feathers of many different birds. Some of the feathers come from common birds such"+
      " as the %^BOLD%^%^BLACK%^raven%^RESET%^ to rare birds such as the %^BOLD%^%^WHITE%^gray falcon%^RESET%^."
   );
   set_shots(-1);
   set_wc(2,5);
   set_large_wc(2,5);
   set_ammo_type("longbow arrow");
}
int is_arrows(){return 1;}

