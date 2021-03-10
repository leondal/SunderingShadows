//Coded by Lujke


#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("Crystal hexagon");
    set_id( ({"hexagon","crystal hexagon", "pyramidkey", "crystal" }) );
    set_short("%^CYAN%^A small hexagonal chunk of %^BOLD%^cr"
      +"%^WHITE%^y%^CYAN%^s%^WHITE%^t%^CYAN%^al%^RESET%^");
    set_weight(1);
    set_long("%^CYAN%^The %^BOLD%^cr%^WHITE%^y%^CYAN%^s%^WHITE%^t"
      +"%^CYAN%^al%^RESET%^%^CYAN%^ is about the size of a gold piece,"
      +" and has a neat hexagonal shape. It seems like it might be for"
      +" a more than simply decorative purpose.");
}


