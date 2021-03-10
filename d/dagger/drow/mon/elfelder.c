#include "/d/shadow/mon/melnmarn.h"
#include "/d/shadow/mon/dir.h"

inherit MONSTER;
void create() {
   ::create();
     set_name("elven elder");
     set_id( ({ "elf", "elder","healer","elven elder"}) );
     set_property("no attack",1);
   set_short("%^GREEN%^Elven elder%^RESET%^");
     set("aggressive", 0);
     set_level(19);
     set_long("He is an old elf, who tends to the injured \n"+
	      "heros who dare venture into the Drow city of Underdark.");
     set_languages( ({ "common" }) );
     set_gender("male");
     set_alignment(4);
     set("race", "elf");
     add_money("gold", random(500));
     set_body_type("humanoid");
     set_property("no attack", 1);
     set_hd(19,3);
     set_max_hp(query_hp());
     set_max_sp(query_hp());
     set_sp(query_max_sp());
     set_mp(random(500));
     set_max_mp(query_mp());
     set_emotes(3, ({
	"We are here to aid any hero who seeks to remove the Drow threat.",
	"The temple doors are sealed shut by the elements.",
	"The key to entrance lies within the city.",
	"Four parts to remove the locks of the temple.",
	"%^BOLD%^%^RED%^Fire%^WHITE%^ will scorch the %^GREEN%^earth%^WHITE%^ "
	"upon which the %^BLUE%^water%^WHITE%^ will flow...and %^CYAN%^air "
	"%^WHITE%^will blow it all away.%^RESET%^",
	"To understand the elements is to understand the secret of the locks.",
	"One tower holds a key. One tower holds a portal.",
	"Please save humanity from the threat.",
	"Have you looked hard for answers? Have you looked hard for hints?"
    }), 0);
}
