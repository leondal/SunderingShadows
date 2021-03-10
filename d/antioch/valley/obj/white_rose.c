#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("white rose");
   set_short("%^BOLD%^%^WHITE%^A pretty white rose%^RESET%^");
   set_id(({"rose","white rose","pretty rose","pretty white rose","tea rose","white tea rose"}));
   set_long("%^BOLD%^%^WHITE%^The white rose is of the tea rose variety,"+
   " which is smaller than most other roses but they tend to be more"+
   " durable and last through all sorts of weather conditions. The petals"+
   " are dainty and rounded and you can see the %^YELLOW%^pollen%^WHITE%^"+
   " in the very center. It has a light fragrance to it that is quite"+
   " nice.");
   set_weight(1);
   set_value(1);
   set_cointype("copper");
}

// void save_me(string file) {return 1;}
