#include <std.h>

inherit OBJECT;

void create()
{
	::create();
	set_value(1000);
	set_weight(1);
}

void set_portal(int num)
{
	string prim_color, sec_color;
	if(!num) num = 1;
	switch(num)
	{
		case 1:
			set_name("a yellow stone");		
			set_obvious_short("A yellow stone");	
			set_id(({"stone", "yellow stone", "glyph key", 
			"yellow glyph key", "yellow key", "catyellowrunekey"}));			
			prim_color = "%^BOLD%^%^YELLOW%^";			
			sec_color = "%^BOLD%^%^RED%^";
			break;
		case 2:
			set_name("a green stone");
			set_obvious_short("A green stone");
			set_id(({"stone", "green stone", "glyph key", 
			"green glyph key", "green key", "catgreenrunekey"}));
			prim_color = "%^BOLD%^%^GREEN%^";
			sec_color = "%^BOLD%^%^WHITE%^";
			break;			
		case 3:
			set_name("a blue stone");
			set_obvious_short("A blue stone");
			set_id(({"stone", "blue stone", "glyph key", 
			"blue glyph key", "blue key", "catbluerunekey"}));
			prim_color = "%^BOLD%^%^BLUE%^";
			sec_color = "%^BOLD%^%^BLACK%^";			
			break;
		case 4:			
			set_name("a purple stone");
			set_obvious_short("A purple stone");
			set_id(({"stone", "purple stone", "glyph key", 
			"purple glyph key", "purple key", "catpurplerunekey"}));
			prim_color = "%^BOLD%^%^MAGENTA%^";
			sec_color = "%^BOLD%^%^GREEN%^";			
			break;
		default:
			set_name("a yellow stone");			
			set_id(({"stone", "yellow stone", "glyph key", 
			"yellow glyph key", "yellow key", "catyellowrunekey"}));			
			prim_color = "%^BOLD%^%^YELLOW%^";			
			sec_color = "%^BOLD%^%^RED%^";
			break;
	}
	set_short(prim_color+"Gl"+sec_color+"yp"+prim_color+"h "+
	"k"+sec_color+"e"+prim_color+"y%^RESET%^");

	set_long(prim_color+"This stone appears to "+
	"be any regular rock that you might pick up.  "+
	"It is not perfect, rather almost entirely "+
	sec_color+"tarnished"+prim_color+ " to the "+
	"point of being what one might consider "+
	"ugly.  It is oddly shapen, with"+
	sec_color+" indentions "+prim_color+
	"throughout.  However, it seems to be"+
	sec_color+" glowing "+prim_color+
	"constantly and shows no signs of stopping.  "+
	"You believe it serves some"+
	sec_color+" function"+prim_color+
	", perhaps a very important one.%^RESET%^");	
	add_id("key");	
}

