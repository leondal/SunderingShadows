//writer's kit by Circe 6/15/07
#include <std.h>
inherit OBJECT;

#define COLORS ({"black","tan","cream","maroon"})

void create(){
   string COLOR, str;
        ::create();
        COLOR = COLORS[random(sizeof(COLORS))];
        switch(COLOR){
           case "black" : str = "%^BOLD%^%^BLACK%^";
                          break;
           case "tan" : str = "%^RESET%^%^ORANGE%^";
                        break;
           case "cream" : str = "%^BOLD%^%^WHITE%^";
                          break;
           case "maroon" : str = "%^RESET%^%^RED%^";
                           break;
           default : str = "%^RESET%^";
                     break;
        }
        set_name("writing case");
        set_id(({"case","writing case","leather case","leather writing case",""+COLOR+" leather writing case"}));
        set_short(""+str+""+COLOR+" leather writing case%^RESET%^");
        set_long(
           "This handsome writing case is fashioned from "+str+""+COLOR+" leather "+
           "%^RESET%^made into a box.  The lid is padded and fitted with small "+
           "%^YELLOW%^dull brass rivets %^RESET%^arranged in a simple square "+
           "design.  Inside the box are arranged all the materials a writer "+
           "might need, each stowed into a snug individual compartment.  "+
           "There are two bottles of %^BOLD%^%^BLACK%^black ink %^RESET%^"+
           "along with a row of %^BOLD%^%^CYAN%^c%^BLUE%^o%^MAGENTA%^l%^RED%^o"+
           "%^YELLOW%^r%^RESET%^%^ORANGE%^e%^BOLD%^%^GREEN%^d %^RESET%^inks "+
           "in tiny bottles.  A small, sharp knife is included for sharpening "+
           "a dull quill, and a rather large portion of the box is taken up "+
           "by a %^BOLD%^%^BLACK%^velvet bag%^RESET%^ filled with fine "+
           "sand for drying the ink on parchment or paper.");
        set_weight(1);
        set_value(350);
        set_lore("This is the type of case one might carry on journeys, "+
           "providing the necessary materials to write a letter and "+
           "keep quills in good shape.");
        set_property("lore difficulty",3);
         set_item_bonus("academics",2);
}
