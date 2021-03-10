#include <std.h>

#define MATS ({"%^BOLD%^horn","%^BOLD%^bone","%^ORANGE%^oak","%^GREEN%^pine","%^ORANGE%^willow"})

#define DESIGNS ({"studded with %^BOLD%^%^RED%^c%^RESET%^%^ORANGE%^o%^YELLOW%^l%^GREEN%^o%^CYAN%^r%^BLUE%^e%^RESET%^%^BLUE%^d %^BOLD%^%^WHITE%^glass",\
"decorated with alternating fusils of different %^BOLD%^%^RED%^c%^RESET%^%^ORANGE%^o%^YELLOW%^l%^GREEN%^o%^CYAN%^r%^BLUE%^s",\
"etched with carvings of %^GREEN%^evergreens %^RESET%^centered around a %^ORANGE%^brown bear","bordered with %^YELLOW%^gold",\
"decorated with a large %^BOLD%^platinum knot",\
"decorated only with a solid %^GREEN%^green stripe %^RESET%^running longways",\
"burned with the outline of a %^BOLD%^%^RED%^rose %^RESET%^painted %^BOLD%^%^MAGENTA%^pink",\
"carved with many %^BOLD%^interlocking knots",\
"highly decorated with intricate %^BOLD%^geometric patterns %^RESET%^in %^YELLOW%^gold %^RESET%^and %^BOLD%^%^GREEN%^green",\
"fitted with three %^YELLOW%^golden fleur-de-lis%^RESET%^ with painted %^BOLD%^%^BLUE%^blue ribbons %^RESET%^between them",\
"carved with a set of %^ORANGE%^antlers",\
"set with a beautiful %^BOLD%^escarbuncle %^RESET%^made of a central %^BOLD%^%^RED%^ruby %^RESET%^radiating outward with smaller %^BOLD%^%^RED%^rubies %^RESET%^and %^YELLOW%^topaz%^RESET%^","decorated with a %^BOLD%^silver estoile",\
"decorated with the burned images of three %^RED%^hawks %^RESET%^flying on a field of %^CYAN%^blue"})

inherit OBJECT;

int i,j;
string str,MAT,DESIGN;

void create()
{
   ::create();
	j = random(sizeof(MATS));
	MAT = MATS[j];
	i = random(sizeof(DESIGNS));
	DESIGN = DESIGNS[i];
	set_value(random(25)+250);
	set_name(""+MAT+" comb");
	set_short(""+MAT+" comb");
	set_id(({"comb",""+MAT+" comb"}));
	set_long("This comb has been made from a solid piece of "+
         ""+MAT+" %^RESET%^fitted between two thin panels of "+
         "matching "+MAT+"%^RESET%^.  The teeth were cut using a fine "+
         "saw before the top of the comb was "+DESIGN+" %^RESET%^on both "+
         "sides.  The comb comes in a matching "+MAT+" case %^RESET%^"+
         "and may be used to comb any length of hair.");
      set_lore("Combs such as these have long been made by the "+
         "firbolgs of Lothwaite with the materials closest at "+
         "hand.  A finely decorated comb is often given as a "+
         "wedding gift from a bride to her groom as well as "+
         "from a groom to his bride.");
      set_property("lore difficulty",12);
	set_weight(2);
}

void init()
{
	::init();
	add_action("brush_hair","comb");
}

int brush_hair(string str)
{
	if((string)TP->query_gender() == "male") {
		if(str == "short hair") {
			write("%^ORANGE%^You run the comb through your shortly"+
			" cropped hair.");
			say("%^ORANGE%^"+TPQCN+" runs a comb"+
			" through his shortly cropped hair.");
			return 1;
		}
		if(str == "long hair") {
			write("%^BOLD%^%^CYAN%^You carefully comb out your long hair.");
			say("%^BOLD%^"+TPQCN+" carefully combs"+
			" out his long hair.");
			return 1;
		}
		if(str == "hair") {
			write("You comb your hair.");
			say(""+TPQCN+" combs his hair.");
			return 1;
		}
	}
	if((string)TP->query_gender() == "female") {
		if(str == "long hair") {
			write("%^BOLD%^%^RED%^You run the comb gently through"+
			" your luxurious hair.");
			say("%^BOLD%^%^RED%^"+TPQCN+" runs the"+
			" comb through her luxurious tresses.");
			return 1;
		}
		if(str == "short hair") {
			write("%^YELLOW%^You run the comb through your short hair,"+
			" getting rid of the tangles and smoothing it out.");
			say("%^YELLOW%^"+TPQCN+" runs a brush through"+
			" her shortly cropped hair.");
			return 1;
		}
		if(str == "hair") {
			write("%^BOLD%^You leisurely comb out your pretty locks.");
			say("%^BOLD%^"+TPQCN+" leisurely brushes"+
			" out her pretty locks.");
			return 1;
		}
	}
	if(str == "hair") {
		write("%^BOLD%^You run the comb through your hair.");
		say(""+TPQCN+" combs "+TP->QP+""+
		" hair.");
		return 1;
	}
	else {
		notify_fail("You can comb your hair, whether it is long or"+
		" short or of normal length.\n");
		return 0;
	}
}
