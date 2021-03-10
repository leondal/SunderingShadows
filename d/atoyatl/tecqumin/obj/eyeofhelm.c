//Coded by Lujke

#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("eye");
    set_id( ({"eye","eye of Helm","blue eye", "blue eye of Helm"}) );
    set_short("The blue eye of Helm");
    set_obvious_short("%^BOLD%^%^CYAN%^The %^BLUE%^blue %^CYAN%^e%^BLUE%^"
      +"y%^CYAN%^e%^RESET%^ of %^BOLD%^%^RED%^H%^RESET%^e%^BOLD%^%^WHITE%^l"
      +"%^BOLD%^%^BLUE%^m");
    set_weight(4);
    set_long("%^BOLD%^%^CYAN%^The %^BLUE%^blue %^CYAN%^e%^BLUE%^"
      +"y%^CYAN%^e%^RESET%^ of %^BOLD%^%^RED%^H%^RESET%^e%^BOLD%^%^WHITE%^l"
      +"%^BOLD%^%^BLUE%^m");
    set_lore("The eye, symbol of %^BOLD%^%^RED%^H%^RESET%^e%^BOLD%^%^WHITE%^"
      +"l%^BLUE%^m%^RESET%^, vibrates slightly with a watchful energy. It"
      +" seems to be the confluence or repository for an immense power"
      +" that is holding closed the seal beneath the image. If you wanted"
      +" to break the seal open and unleash whatever lays behind it, this"
      +" would be the place to attack it. Perhaps if you had an object"
      +" imbued with sufficient power, there might be a way to break it open.");
  set_property("lore",50);
}


