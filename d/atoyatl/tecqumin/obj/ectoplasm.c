//Coded by Lujke


#include <std.h>
inherit OBJECT;
string spirit_name;

void create() {
    ::create();
    set_name("ectoplasm");
    set_id( ({"plasm","ectoplasm","smear", "smear of ectoplasm",
                             "faint smear", "ghostly ectoplasm" }) );
    set_short("%^BOLD%^%^WHITE%^A faint smear of ghostly ectoplasm");
    set_weight(1);
    set_long((:TO, "long_desc":));
}

void set_spirit_name(string sn){
  spirit_name = sn;
}

string query_spirit_name(){
  return spirit_name;
}

string long_desc(){
  return "%^BOLD%^%^WHITE%^This smudge of ectoplasm is all that"
      +" remains of the %^RESET%^%^CYAN%^Tecqumin%^BOLD%^%^WHITE%^"
      +" sp%^RESET%^i%^BOLD%^%^WHITE%^r%^RESET%^i%^BOLD%^%^WHITE%^t,"
      +" %^RESET%^%^CYAN%^" + spirit_name + "%^BOLD%^%^WHITE%^. It"
      +" is silvery in colour, and silky to the touch.";
}
