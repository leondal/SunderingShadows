#include <std.h>
#include <daemons.h>
inherit "/std/fence";

void create() {
   ::create();
   set_name("nicoli");
   set_id(({"nicoli","Nicoli","fence"}));
   set_short("Nicoli, the guild fence");
   set("aggressive", 0);
   set_level(19);
   set_long("%^RESET%^%^CYAN%^This ex-Daggerdale fence seems to be doing "
"quite well for himself here, judging by his content demeanor and well-kept "
"appearance.  Nicoli seems to fit in well with the mixed citizenry of this "
"town, given his own questionable heritage.  His %^BOLD%^%^BLACK%^dusky "
"grey skin%^RESET%^%^CYAN%^, where not hidden by garments of black leather, "
"is telltale of his partial drow heritage.  The %^RED%^sickly red color "
"%^CYAN%^of his eyes is unsettling, as he watches a variety of rogueish "
"figures come and go from his small corner of the city.%^RESET%^");
   set_gender("male");
   set_alignment(6);
   set_class("thief");
   set_race("half-drow");
   add_money("gold", random(100));
   set_body_type("human");
   set_property("no bump", 1);
   set_hd(19,6);
   set_exp(10);
}
