#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("stuffed toy monster");
	set_id(({ "stuffed animal", "toy", "toy monster", "stuffed toy monster", "stuffed wooly monster", "wooly toy", "stuffed animalz" }));
	set_short("%^BOLD%^%^BLACK%^a wooly stuffed toy%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a wooly stuffed toy%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This little stuffed animal is humanoid in shape with two legs and two arms and a curly little tail.  All covered in a thick, rich pelt of soft curly sheep's wool.  Shiny %^GREEN%^green buttons %^BLACK%^have been used for eyes and somewhere in all that thick weave is a small %^MAGENTA%^pink nose %^BLACK%^button.  What makes this little creature so cute though are the tiny %^RESET%^%^ORANGE%^brown leather horns %^BOLD%^%^BLACK%^and the oversized, floppy %^RESET%^%^ORANGE%^brown leather ears%^BOLD%^%^BLACK%^. Though he's a monster, it's hard to be scared of him with such a dopey %^RED%^red yarn%^BLACK%^ grin.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(225+random(16));
}