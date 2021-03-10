//The Unquiet Grave
#include <std.h>
#include "../antioch.h"
inherit OBJECT;

void create()
{
	::create();
	set_name("a ballad");
	set_id(({"song","ballad","a ballad","an old ballad","scroll","old scroll"}));
	set_short("%^RESET%^An old scroll");
	set_long("This scroll is written on old paper in black ink. The"+
	" edges of the pages are whithered with age and it is slowly"+
	" turning yellow. Perhaps you should read it.");
	set_weight(3);
	set_value(10);
	set_cointype("copper");
}

void init()
{
	::init();
	add_action("read_scroll","read");
}

int read_scroll(string str)
{
	if(str == "scroll" || str == "ballad" || str == "song") {
	write("\n		   The Unquiet Grave\n\n"+
	"	  %^BOLD%^%^BLUE%^Cold blows the wind to my true love,\n"+
	"	       And gently drops the rain,\n"+
	"	    I never had but one sweetheart,\n"+
	"	    And in greenwood she lies slain,\n"+
	"	    And in greenwood she lies slain.\n\n"+
	"	  %^CYAN%^I'll do as much for my sweetheart\n"+
	"	        As any young man may;\n"+
	"	  I'll sit and mourn all on her grave\n"+
	"	      For a twelvemonth and a day\n\n"+
	"	When the twelvemonth and one day was past,\n"+
	"	      The ghost began to speak;\n"+
	"	  %^RESET%^'Why sittest here all on my grave,\n"+
	"	      And will not let me sleep?'\n\n"+
	"	  %^BOLD%^'There's one thing that I want, sweetheart,\n"+
	"	        There's one thing that I crave\n"+
	"	And that is a kiss from your lily-white lips--\n"+
	"	        Then I'll go from your grave.'\n\n"+
	"	    %^RESET%^'My breast it is as cold as clay,\n"+
	"	    My breath smells earthly strong\n"+
	"	   And if you kiss my cold clay lips,\n"+
	"	     Your days they won't be long.\n\n"+
	"	    Go fetch me %^BOLD%^%^BLUE%^water%^RESET%^ from the desert,\n"+
	"	      And %^RED%^blood%^RESET%^ from out of a stone;\n"+
	"	Go fetch me %^BOLD%^milk%^RESET%^ from a fair maid's breast\n"+
	"	    That a young man never had known.'\n\n"+
	"	    %^BOLD%^O down in yonder grove, sweetheart,\n"+
	"	        Where you and I would walk,\n"+
	"	     The first flower that ever I saw\n"+
	"	          Is wither'd to a stalk\n\n"+
	"	  The stalk is wither'd and dry, sweetheart,\n"+
	"	       And the flower will never return\n"+
	"	     And since I lost my own sweetheart,\n"+
	"	         What can I do but mourn?\n\n"+
	"	  %^BOLD%^'When shall we meet again, sweetheart?\n"+
	"	        When shall we meet again?'\n"+
	"	%^RESET%^'When the %^ORANGE%^oaken leaves%^RESET%^ that fall from trees\n"+
	"	      Are %^GREEN%^green%^RESET%^ and spring up again\n"+
	"	      Are %^GREEN%^green%^RESET%^ and spring up again.'\n");
	say(""+TP->query_cap_name()+" reads an ancient scroll.");
	return 1;
	}
}
