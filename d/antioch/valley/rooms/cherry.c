#include <std.h>
#include "../valley.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(BRANCHES);
   set_travel(FRESH_BLAZE);
   set_property("no charge",1);
   set_charge_message("You can't charge something in a tree!");
	set_property("indoors",2);
	set_property("light",3);
	set_short("%^BOLD%^Branches of a cherry tree");
	set_long(
	"%^GREEN%^You are surrounded by delicate %^BOLD%^%^WHITE%^white%^RESET%^"+
        "%^GREEN%^ and %^BOLD%^%^MAGENTA%^pink%^RESET%^%^GREEN%^ blossoms in the upper"+
	" branches of this %^BOLD%^%^RED%^cherry%^RESET%^%^GREEN%^ tree. The limbs you stand on are"+
	" very firm, stretching out and holding numerous %^BOLD%^%^MAGENTA%^cherry"+
	" blossoms%^RESET%^%^GREEN%^ across their length. The tree doesn't seem that"+
	" big now that you're in it, there isn't that much room to"+
	" stand and you can't really climb any higher from here."+
	" When you glance down you can tell that the ground isn't"+
	" that far away, though it would still be safer to climb"+
	" down than to chance a jump. The wind is lightly blowing"+
	" here, picking up some %^BOLD%^%^MAGENTA%^blossoms%^RESET%^%^GREEN%^ and swirling them around"+
	" in the breeze. There are even a couple ripe %^BOLD%^%^RED%^cherries%^RESET%^%^GREEN%^ that"+
	" can be seen on the outer branches.\n"
	);
	set("night long",
	"%^GREEN%^The starlight gives a %^BOLD%^%^WHITE%^silver%^RESET%^%^GREEN%^"+
        " glow to the %^BOLD%^%^MAGENTA%^cherry blossoms%^RESET%^%^GREEN%^,"+
	" they seem to glow as though holding some magic within."+
	" In the branches of the %^BOLD%^%^RED%^cherry%^RESET%^%^GREEN%^ tree you are surrounded"+
	" by these plentiful blossoms. The wind dances through the"+
	" branches, scooping up some of the flowers and carrying"+
	" them away into the %^BLUE%^night%^GREEN%^. They almost seem to come alive"+
	" as they're whisked away, dancing like little %^BOLD%^%^MAGENTA%^fairies"+
        " %^RESET%^%^GREEN%^on"+
	" the breeze. There isn't much to do here, you can't seem"+
	" to climb any higher, indeed, you barely have room enough"+
	" to stand in this tree. The branches are sturdy, though,"+
	" and would hold your weight easily if you wanted to rest"+
	" here for the night.\n"
	);
	set_smell("default",
	"The lovely fragrance of cherry blossoms surrounds you."
	);
	set_listen("default",
	"The wind blows gently through the branches, causing a"+
	" slight rustle as it scoops up some blossoms."
	);
	set_items( ([
	({"blossoms","flowers","cherry blossoms"}) : "%^BOLD%^%^MAGENTA%^The cherry"+
	" blossoms are very delicate, a pale pink in color they"+
	" have a lovely scent to them and are easily carried away"+
	" on the breeze.",
	"branches" : "%^ORANGE%^The branches you're standing on seem quite"+
	" secure, stretching out to hold thousands of blossoms."+
	" They don't leave you much room, though, and this tree"+
	" seems nowhere near as large as it did from the ground,"+
	" there's barely room to stand here.",
	"wind" : "%^BOLD%^%^BLUE%^The wind has picked up some cherry blossoms and"+
	" carries them away, the flowers almost seem to be dancing.",
	"ground" : "%^GREEN%^The ground isn't that far below, really, but"+
	" climbing down would be the best way to get there.",
	({"cherry","cherries"}) : "%^BOLD%^%^RED%^There are several cherries on"+
	" the very outer branches of the tree. They look ripe, but"+
	" you don't think you can reach them safely.",
	]) );
	set_exits( ([
	"down" : ROOMS+"dryad5",
	]) );
}

void reset()
{
	::reset();
	if(!present("dryad")) {
		new(MONS+"cherry_dryad")->move(TO);
	}
}
