#include <std.h>
#include "../lothwaite.h"

#define COLORS ({"natural","%^BOLD%^white","%^RED%^crimson","%^BOLD%^%^RED%^scarlet","%^ORANGE%^taupe","%^YELLOW%^sunny yellow","%^GREEN%^pine green","%^BOLD%^%^GREEN%^vibrant green","%^CYAN%^sea green","%^BOLD%^%^CYAN%^sky blue","%^BLUE%^midnight blue","%^BOLD%^%^BLUE%^royal blue","%^MAGENTA%^violet","%^BOLD%^%^MAGENTA%^lilac","%^BOLD%^%^BLACK%^black"})

#define COLORS2 ({"s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r","%^YELLOW%^gold","%^BOLD%^plati%^CYAN%^n%^WHITE%^um"})

#define DESIGNS ({"%^BOLD%^snowflake","%^GREEN%^tree","%^YELLOW%^knot","%^BOLD%^%^MAGENTA%^heart","%^BOLD%^%^BLACK%^panther","%^GREEN%^serpent","%^ORANGE%^horse","%^CYAN%^dolphin","%^YELLOW%^bee","%^BOLD%^dagger","%^YELLOW%^daffodil","%^BOLD%^%^RED%^rose","%^BOLD%^%^BLUE%^ship","%^RED%^hawk","%^MAGENTA%^ribbon"})

inherit OBJ"candle_inherit";

int j,k,l;
string str, COLOR,COLOR2,DESIGN;

void create()
{
   ::create();
	j = random(sizeof(COLORS));
	COLOR = COLORS[j];
	k = random(sizeof(COLORS2));
	COLOR2 = COLORS2[k];
	l = random(sizeof(DESIGNS));
	DESIGN = DESIGNS[l];
	set_value(20);
      set_cointype("gold");
	set_name("a "+COLOR+" pillar candle%^RESET%^");
	set_short("a "+COLOR+" pillar candle%^RESET%^");
	set_id(({"candle",""+COLOR+" candle","pillar candle","pillar"}));
      if(COLOR == "natural"){
         set_long("This pillar candle is left its natural beige "+
            "shade.  The candle is about six inches tall and two "+
            "inches in diameter with a single wick.  Carved around "+
            "the bottom of the candle is a repeating "+DESIGN+"%^RESET%^ "+
            "border, filled in with molten wax dyed a metallic "+
            ""+COLOR2+"%^RESET%^.  You may light the candle when "+
            "you need more light, or douse it when you are finished.");
      }else{
         set_long("This pillar candle has been dyed a "+COLOR+" shade"+
            "%^RESET%^.  The candle is about six inches tall and two "+
            "inches in diameter with a single wick.  Carved around "+
            "the bottom of the candle is a repeating "+DESIGN+"%^RESET%^ "+
            "border, filled in with molten wax dyed a metallic "+
            ""+COLOR2+"%^RESET%^.  You may light the candle when "+
            "you need more light, or douse it when you are finished.");
      }
	set_weight(3);
}
