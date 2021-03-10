inherit "/std/armour";
#include <std.h>;
#include "/std/money.c";
//string class;
int  real_str;
void create(){
    ::create();
    set_name("gloves");
    set_id(({"gloves","gauntlets","glove","gauntlet"}));
    set("short", "leather gloves");
    set("long",
      "These gloves are made from heavy leather, and designed to protect your hands, though they have a fur lining, and actually keep your hands very warm."
    );
    set_type("clothing");
    set_limbs(({"right arm","left arm"}));
    set_weight(1);
  set_value(20);
}
