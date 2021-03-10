#include <std.h>

inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("%^RESET%^%^ORANGE%^T%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^v%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^rn%^WHITE%^");
    set_long("%^BOLD%^%^BLACK%^The Stone, %^RESET%^as it is commonly referred to, is a large stone building that serves %"
			 "^ORANGE%^Kinaro's %^WHITE%^rising need for %^BOLD%^%^MAGENTA%^entertainment%^RESET%^. Dwarf miners, merchan"
			 "ts and their mercenaries, adventurers and off-duty guards all come here to eat, %^BOLD%^dri%^RESET%^nk, pla"
			 "y games and occasionally pick fights with one another. This sturdy building thus serves as a holding pen fo"
			 "r the more rowdy elements necessary to grease the wheels of commerce. The tavern itself is build from dull,"
			 " brown bricks. Its first floor is a wide, open, common room filled with %^ORANGE%^sturdy tables %^WHITE%^an"
			 "d %^CYAN%^furniture %^WHITE%^in various sizes. the second floor consist of a %^BOLD%^balcony %^RESET%^overl"
			 "ooking the main %^BOLD%^%^BLACK%^bar%^RESET%^, more tables and a few %^BOLD%^private %^RESET%^rooms for rel"
			 "atively quiet discussions. %^BOLD%^%^BLACK%^The Stone's %^RESET%^reputation for %^RED%^rowdiness %^WHITE%"
			 "^is well earned. %^ORANGE%^Axe %^WHITE%^and %^CYAN%^knife-throwing %^WHITE%^contests, %^BOLD%^%^BLACK%^ar"
			 "m-wrestling %^RESET%^matches, %^GREEN%^pin-the-goblin %^WHITE%^and other assorted competitions that becom"
			 "e more interesting with frothy mugs of %^ORANGE%^dw%^RED%^a%^ORANGE%^rve%^RED%^n a%^ORANGE%^l%^RED%^e%^WH"
			 "ITE%^, keep its customers busy until dawn. Several target %^ORANGE%^dummies %^WHITE%^representing various"
			 " %^GREEN%^monsters %^WHITE%^line the left wall for use in just such merriment. The long %^BOLD%^%^BLACK%^b"
			 "ar %^RESET%^that dominates the room seems to be crafted from a single massive piece of %^BOLD%^%^BLACK%^s"
			 "tone%^RESET%^. Most noteworthy is the %^BOLD%^%^BLACK%^gr%^WHITE%^a%^BLACK%^ff%^WHITE%^i%^BLACK%^t%^WHITE"
			 "%^i %^RESET%^that covers it. The owners encourages visitors to carve small %^ORANGE%^maps %^WHITE%^of the"
			 "ir travels into the %^BOLD%^%^BLACK%^bar%^RESET%^. A huge %^BOLD%^%^BLACK%^iron chandelier %^RESET%^casts"
			 " a warm, cozy %^YELLOW%^glow %^RESET%^over the main chamber. A %^BOLD%^%^CYAN%^menu %^RESET%^hangs behind t"
			 "he %^BOLD%^%^BLACK%^bar%^RESET%^.");
	set_smell("default", "%^RESET%^%^ORANGE%^You can smell a combination of pipe smoke, stale ale and food cooking. ");
    set_listen("default", "%^RESET%^%^GREEN%^You can hear loud discussions mixed with the sound of clinking tankards, and bawdy music.");
    set_items(([
	"menu" : "Maybe it would help if you read it.",
	"bar" :  "The %^BOLD%^%^BLACK%^bar %^RESET%^is covered with a number of"
			" %^ORANGE%^map-drawings%^WHITE%^, ranging from the %^GREEN%^in"
			"comprehensible %^WHITE%^to the work of %^BOLD%^expert cartogra"
			"phers%^RESET%^. %^BOLD%^%^CYAN%^Rumors %^RESET%^in %^BOLD%^%^B"
			"LACK%^The Stone %^RESET%^persists that some of the maps lead to"
			" hidden %^YELLOW%^treasure%^RESET%^. ",
	"balcony" : "The %^BOLD%^balcony %^RESET%^overlooking the %^BOLD%^%^BLAC"
				"K%^bar %^RESET%^is 10 feet up and, like the rest of the fou"
				"ndation stone, is carved from %^BOLD%^%^BLACK%^rock%^RESET%^.",
	     ]));
    set_exits(
      (["west" : "/d/dagger/kinaro/street2"]) );
    set_property("no castle", 1);
    set_property("no attack", 1);
}

void reset() {
    ::reset();
    if(!present("barkeep"))
	new("/d/dagger/kinaro/mon/barkeep")->move(this_object());
}

int read(string str) {
    object ob;
    int i;

    ob = present("barkeep");
    if(!ob) {
	write("You cannot read the menu, as it is smeared with grease.");
	return 1;
    }
    message("Ninfo", "The following specials are availiable today at the Kinaro Bar!\n", this_player());
    message("Ninfo", "-----------------------------------------------------------\n", this_player());
    message("Ninfo", "A Dwarven ale\t\t\t"+ (int)ob->get_price("dwarven ale")+" gold\n", this_player());
   message("Ninfo", "A swamp water\t\t\t"+(int)ob->get_price("swamp water")+" gold\n", this_player());
    message("Ninfo", "A mystery mix\t\t\t"+(int)ob->get_price("mystery mix")+" gold\n", this_player());
   message("Ninfo", "A mug of water\t\t\t "+(int)ob->get_price("water")+" gold\n", this_player());
    message("Ninfo", "-----------------------------------------------------------\n", this_player());
    message("Ninfo", "<buy drink_name> gets you a drink.\n", this_player());
    return 1;
}
