#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("kit of dyes");
	set_id(({ "kit", "kit of dyes" }));
	set_short("%^BOLD%^%^MAGENTA%^A kit of dyes%^RESET%^");
	set_long("This %^ORANGE%^leather satchel%^RESET%^ houses"+
            " an assortment of %^BOLD%^%^CYAN%^glass bottles%^RESET%^"+
            " with %^ORANGE%^cork%^RESET%^ stoppers.  Inside each "+
            "bottle lays the needed raw ingredients to produce smaller"+
            " vats of dyes.  Everything from %^BLUE%^in%^MAGENTA%^d%^BLUE%^igo"+
            "%^RESET%^, %^RED%^ver%^BOLD%^m%^RESET%^%^RED%^il%^BOLD%^i%^RESET%^"+
            "%^RED%^on%^RESET%^ to %^YELLOW%^go%^RESET%^%^ORANGE%^l%^BOLD%^den%^RESET%^"+
            "%^ORANGE%^r%^BOLD%^od%^RESET%^ can be found.  Other glass vials "+
            "of needed powders and chemicals needed to set the dyes are added"+
            " to the satchel, from %^YELLOW%^urea%^RESET%^ to help set the "+
            "color to %^BOLD%^salt%^RESET%^ to produce dramatic effects.  A "+
            "small %^CYAN%^guide%^RESET%^ is added with all the necessary recipes.");
        set_weight(1);
	set_value(300);
}
