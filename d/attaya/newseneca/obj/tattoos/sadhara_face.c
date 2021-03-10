#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_weight(0);
	set_ac(0);
	set_type("ring");
	set_property("death keep",1);
	set_property("no animate",1);
	set_name("tattoo");
	set_value(25000);
	set_id(({ "cyan", "tattoo", "face", "face tattoo", "cyan tattoo", "marking", "markings" }));
	set_short("%^BOLD%^%^CYAN%^A large facial tattoo%^RESET%^");
	set_long(
@MYLONG
%^BOLD%^%^CYAN%^These cyan tattoos contrast so well against Sadhara's skin tone, they almost seem to glow in a mystical blue light.
%^BOLD%^%^CYAN%^From the bottom of her eyes, to the ends of her lips, two thick limes curve over her high cheekbones.
%^BOLD%^%^CYAN%^On closer inspection, however, they seem to actually be delicate Tsarvani script, boardered on the sides by thicker lines.
%^BOLD%^%^CYAN%^It seems that, to get close enough to read it, you'd be less than an inch from kissing her.
%^BOLD%^%^CYAN%^Below where this section ends, an area of the jaw not quite chin or cheek, bordered rectangles have larger script written in them.
%^BOLD%^%^CYAN%^From a distance, the lines and boxes seem like stylized scroll tears from her eyes.
%^BOLD%^%^CYAN%^3 above each eyebrow, 1 on her chin and %^RED%^1 on her forhead%^BOLD%^CYAN%^, ten circular Tsarvani glyphs decorate her face.

MYLONG
	);
	set_limbs(({"head"}));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "large"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

