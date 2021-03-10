//~Circe~ 10/31/07
#include <std.h>

inherit BAG;

#define SHAPES ({"circlular","oval","heart-shaped","square","rectangular","triangular","scalloped"})

void create(){
   string SHAPE, str;
   SHAPE = SHAPES[random(sizeof(SHAPES))];
   ::create();
   set_name("shell jewelry box");
   set_id(({"box","jewelry box","shell jewelry box",""+SHAPE+" jewelry box"}));
   str = "a";
   if(SHAPE == "oval"){ str = "an";}
   set_short("%^RESET%^%^ORANGE%^"+str+" "+SHAPE+" jewelry box%^RESET%^");
   set_long("This pretty little jewelry box is "+SHAPE+" "+
      "and covered with tiny %^BOLD%^s%^RESET%^h%^BOLD%^e"+
      "%^RESET%^l%^BOLD%^l%^RESET%^s in %^ORANGE%^tan%^RESET%^, "+
      "%^BOLD%^%^MAGENTA%^pale pink%^RESET%^, and %^BOLD%^white"+
      "%^RESET%^.  The jewelry box is lined with %^BOLD%^"+
      "%^BLACK%^black velvet%^RESET%^ and provides a "+
      "space for storing small items such as jewelry and "+
      "keepsakes.");
   set_no_clean(1);
   set_weight(10);
   set_value(1);
   set_max_internal_encumbrance(5);
   set_possible_to_close(1);
   set_closed(1);
   set_open_long("This pretty little jewelry box is "+SHAPE+" "+
      "and covered with tiny %^BOLD%^s%^RESET%^h%^BOLD%^e"+
      "%^RESET%^l%^BOLD%^l%^RESET%^s in %^ORANGE%^tan%^RESET%^, "+
      "%^BOLD%^%^MAGENTA%^pale pink%^RESET%^, and %^BOLD%^white"+
      "%^RESET%^.  The jewelry box is lined with %^BOLD%^"+
      "%^BLACK%^black velvet%^RESET%^ and provides a "+
      "space for storing small items such as jewelry and "+
      "keepsakes.\nIt is open.");
   set_closed_long("This pretty little jewelry box is "+SHAPE+" "+
      "and covered with tiny %^BOLD%^s%^RESET%^h%^BOLD%^e"+
      "%^RESET%^l%^BOLD%^l%^RESET%^s in %^ORANGE%^tan%^RESET%^, "+
      "%^BOLD%^%^MAGENTA%^pale pink%^RESET%^, and %^BOLD%^white"+
      "%^RESET%^.  The jewelry box is lined with %^BOLD%^"+
      "%^BLACK%^black velvet%^RESET%^ and provides a "+
      "space for storing small items such as jewelry and "+
      "keepsakes.\nIt is closed.");
}
