#include <std.h>
#include "/d/dagger/drow/temple/short.h"
inherit MONSTER;
void create() {
    :: create();
    set_name("spider");
    set_id(({
	"spider","small spider"
    }));
    set_short("%^RED%^Small spider");
    set_long(
	"%^RED%^This spider while small compared to most is still the "
	"size of a small dog. "
   "Below its beady eyes you can see a large mouth filled "
	"with unnatural razor sharp teeth."
    );
    set_gender("male");
    set_hd(10,1);
    set_size(2);
    set_overall_ac(0);
    set_hp(80);
    set_max_hp(80);
    set_exp(1000);
    set_body_type("arachnid");
    set_race("spider");
    set_class("fighter");
    set_guild_level("fighter",10);
    set_stats("strength",18);
    set_stats("constitution",19);
    set_stats("dexterity",17);
    set_stats("wisdom",12);
    set_stats("intelligence",15);
    set_stats("charisma",10);
    set_alignment(9);
    new ( OPATH "bread.c" )->move(TO);
    set_emotes(4, ({
	"%^RED%^The spiders tears at your flesh!%^RESET%^",
	"%^GREEN%^The spider bites into your skin!%^RESET%^",
	"%^MAGENTA%^The spider covers you in webbing, but it fails "
	"to hold you!%^RESET%^"
    }),1);
}

	
