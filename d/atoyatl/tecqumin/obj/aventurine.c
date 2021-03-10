//Coded by Lujke

#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("aventurine");
    set_id( ({"jewel","aventurine","blue aventurine", "blue jewel", "blue aventurine of Helm"}) );
    set_short("A blue aventurine");
    set_obvious_short("%^BOLD%^%^CYAN%^A %^BLUE%^blue %^CYAN%^av%^BLUE%^"
      +"ent%^RESET%^%^BLUE%^u%^BOLD%^ri%^CYAN%^ne");
    set_weight(4);
    set_long("%^BOLD%^%^CYAN%^A %^BLUE%^blue %^CYAN%^av%^BLUE%^"
      +"ent%^RESET%^%^BLUE%^u%^BOLD%^ri%^CYAN%^ne");
    set_lore("The %^BOLD%^%^CYAN%^av%^BLUE%^ent%^RESET%^%^BLUE%^u%^BOLD%^"
      +"%^BLUE%^ri%^CYAN%^ne%^RESET%^ set on the wrist of the war gauntlet"
      +" appears to form part of a %^BOLD%^%^RED%^p%^RESET%^o%^ORANGE%^w"
      +"%^RESET%^e%^BOLD%^%^RED%^r %^RESET%^%^ORANGE%^c%^BOLD%^%^WHITE%^o"
      +"%^RESET%^n%^ORANGE%^d%^RESET%^u%^BOLD%^%^WHITE%^i%^RESET%^%^ORANGE%^"
      +"t%^RESET%^ towards the %^BOLD%^%^CYAN%^e%^BLUE%^y%^CYAN%^e%^RESET%^"
      +" that is a central repository for the power of the seal. Perhaps if"
      +" you had an appropriate power source, you might be able to use it to"
      +" strengthen the seal and thwart any effort to open it or release"
      +" whatever lies within.");
  set_property("lore",50);
}


