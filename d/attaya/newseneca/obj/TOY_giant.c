#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("stuffed toy giant");
	set_id(({ "toy", "stuffed toy", "stuffed animal toy", "stuffed animal", "toy giant", "giant stuffed animal" }));
	set_short("%^RESET%^A giant shaped stuffed animal%^RESET%^");
	set_obvious_short("%^RESET%^A giant shaped stuffed animal%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This stuffed animal is fairly large and shaped like a humanoid doll.  Completely bald, it has large ears and a dopey yarn mouth.  %^RESET%^%^ORANGE%^Brown buttons %^BOLD%^%^WHITE%^have been used to make its eyes and a triangle shaped peace of %^RESET%^%^ORANGE%^peach felt %^BOLD%^%^WHITE%^is used to make a nose.  Bushy %^BLACK%^black yarn eyebrows %^WHITE%^are sewn above the eyes giving him a constant state of mild surprise.  The giant doll, about a foot tall total, is made from cotton and wears a %^BLUE%^blue vest %^WHITE%^and %^RESET%^%^ORANGE%^brown pants %^BOLD%^%^WHITE%^made out of homespun, while the boots on its feet are made of small pieces of %^RESET%^%^ORANGE%^brown leather%^BOLD%^%^WHITE%^.  All told he's kind of cute and silly at the same time.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(400);
}