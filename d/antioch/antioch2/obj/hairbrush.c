#include <std.h>
#include "../antioch.h"
inherit OBJECT;

void create()
{
	::create();
	set_name("hairbrush");
	set_id(({"brush","hair brush","hairbrush"}));
	set_short("A hairbrush");
	set_long(
	"%^ORANGE%^The hairbrush is made out of oak wood. The handle is"+
	" worn smooth and the wood is a warm golden shade. The bristles"+
	" of the brush are made from some stiffened animal hair. The back"+
	" of the brush is engraved with the symbol of an acorn with two"+
	" oak leaves on either side of it. This brush could be used on"+
	" many different lengths of hair."
	);
	set_weight(1);
	set_value(40);
	set_cointype("silver");
}

void init()
{
	::init();
	add_action("brush_hair","brush");
}

int brush_hair(string str)
{
	if((string)TP->query_gender() == "male") {
		if(str == "short hair") {
			write("%^ORANGE%^You run the brush through your shortly"+
			" cropped hair.");
			say("%^ORANGE%^"+TP->query_cap_name()+" runs a brush"+
			" through his shortly cropped hair.");
			return 1;
		}
		if(str == "long hair") {
			write("%^BOLD%^%^CYAN%^You carefully brush out your long hair.");
			say("%^BOLD%^"+TP->query_cap_name()+" carefully brushes"+
			" out his long hair.");
			return 1;
		}
		if(str == "hair") {
			write("You brush your hair.");
			say(""+TP->query_cap_name()+" brushes his hair.");
			return 1;
		}
	}
	if((string)TP->query_gender() == "female") {
		if(str == "long hair") {
			write("%^BOLD%^%^RED%^You run the brush gently through"+
			" your luxurious hair.");
			say("%^BOLD%^%^RED%^"+TP->query_cap_name()+" runs the"+
			" brush through her luxurious tresses.");
			return 1;
		}
		if(str == "short hair") {
			write("%^YELLOW%^You run the brush through your short hair,"+
			" getting rid of the tangles and smoothing it out.");
			say("%^YELLOW%^"+TP->query_cap_name()+" runs a brush through"+
			" her shortly cropped hair.");
			return 1;
		}
		if(str == "hair") {
			write("%^BOLD%^You leisurely brush out your pretty locks.");
			say("%^BOLD%^"+TP->query_cap_name()+" leisurely brushes"+
			" out her pretty locks.");
			return 1;
		}
	}
	if(str == "hair") {
		write("%^BOLD%^You run the brush through your hair.");
		say(""+TP->query_cap_name()+" brushes "+TP->query_possessive()+""+
		" hair.");
		return 1;
	}
	else {
		notify_fail("You can brush your hair, whether it is long or"+
		" short or of normal length.\n");
		return 0;
	}
}
