#include <std.h>
#include "../lothwaite.h"

#define COLORS ({"natural","%^BOLD%^white","%^RED%^crimson","%^BOLD%^%^RED%^scarlet","%^ORANGE%^taupe","%^YELLOW%^sunny yellow","%^GREEN%^pine green","%^BOLD%^%^GREEN%^vibrant green","%^CYAN%^sea green","%^BOLD%^%^CYAN%^sky blue","%^BLUE%^midnight blue","%^BOLD%^%^BLUE%^royal blue","%^MAGENTA%^violet","%^BOLD%^%^MAGENTA%^lilac","%^BOLD%^%^BLACK%^black"})

inherit OBJ"candle_inherit";

int j;
string str, COLOR;

void create()
{
   ::create();
	j = random(sizeof(COLORS));
	COLOR = COLORS[j];
	set_value(15);
      set_cointype("gold");
	set_name("a "+COLOR+" taper candle%^RESET%^");
	set_short("a "+COLOR+" taper candle%^RESET%^");
	set_id(({"candle",""+COLOR+" candle","taper candle","taper"}));
      if(COLOR == "natural"){
         set_long("This is a tall, slender taper candle made "+
            "of high quality wax left its natural shade.  "+
            "The candle gives off little scent, and would probably "+
            "make a decent source of %^YELLOW%^light %^RESET%^"+
            "for a short time.  Because the radius of the %^YELLOW%^"+
            "light %^RESET%^is small, it might "+
            "be useful for not drawing attention to oneself.  You "+
            "may light or douse the candle.");
      }else{
	   set_long("This is a tall, slender taper candle made of "+
            "high quality wax dyed a "+COLOR+" shade%^RESET%^.  "+
            "The candle gives off little scent, and would probably "+
            "make a decent source of %^YELLOW%^light %^RESET%^"+
            "for a short time.  Because the radius of the %^YELLOW%^"+
            "light %^RESET%^is small, it might "+
            "be useful for not drawing attention to oneself.  You "+
            "may light or douse the candle.");
      }
	set_weight(2);
}
