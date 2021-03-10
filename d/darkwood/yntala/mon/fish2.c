#include <std.h>
#include "../yntala.h"

inherit "/std/monster";

void create() {
  object ob;
  ::create();
  set_name("fish");
  set_id(( { "fish", "small fish"} ));
  set_race("fish");
  set_gender("male");
  set_short("%^BOLD%^%^CYAN%^A tiny blue fish%^RESET%^");
  set_long("%^BOLD%^%^CYAN%^This is a pretty little fish that is light blue in color.  It has a long, slender body and looks like it could move around pretty quickly.%^RESET%^\n");
  set_hd(2,2);
  set_alignment(5);
  set_body_type("snake");
  set_size(1);
  set_hp(15);  
  set_stats("dexterity",20);
  set_overall_ac(6);
  set_exp(15);
  set_moving(1);
  set_nogo(({INRMS+"spring"}));
  set_speed(5);
  set_property("water breather",1);
  set("aggressive", 2);
  set_emotes(1, ({
  "%^BOLD%^%^CYAN%^B%^RESET%^%^CYAN%^u%^RESET%^b%^BOLD%^%^WHITE%^b%^RESET%^l%^CYAN%^e%^BOLD%^%^CYAN%^s get thrown up as the %^RESET%^fish %^BOLD%^%^CYAN%^darts around.%^RESET%^",
"%^RESET%^%^CYAN%^The %^RESET%^fish %^CYAN%^moves easily through the water.%^RESET%^",
"%^RESET%^%^BLUE%^With a swish of its tail, the %^RESET%^fish %^BLUE%^takes off!",
}), 0);

}
