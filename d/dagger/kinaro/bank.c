// Writen by Fire Dragon. (Disciptions by Melnmarn)
//recoded for his little hellhole by Grendel

#include <std.h>

inherit BANK;

void create() {
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_short("%^YELLOW%^L%^RESET%^%^ORANGE%^o%^BOLD%^y%^RESET%^%^ORANGE%^a%^BOLD%^l V%^RESET%^%^ORANGE%^a%^BOLD%^ul%^RESET%^%^O"
			 "RANGE%^t%^BOLD%^s B%^RESET%^%^ORANGE%^a%^BOLD%^nk%^RESET%^ ");
   set_property("indoors", 1);
   set_long("This imposing %^BOLD%^%^BLACK%^structure %^RESET%^is a long, low %^BOLD%^%^BLACK%^stone %^RESET%^edifice covered wi"
			"th %^BOLD%^bas relief %^RESET%^%^CYAN%^carvings %^WHITE%^of %^ORANGE%^dwarf warriors %^WHITE%^standing at attention."
			" The doors are cast in %^RED%^fever iron, %^WHITE%^with several prominent %^BOLD%^%^BLACK%^locks %^RESET%^running up"
			" and down them. The %^YELLOW%^trade bank %^RESET%^of %^ORANGE%^Kinaro %^WHITE%^is perhaps the most %^CYAN%^secure bui"
			"lding %^WHITE%^in town. With %^BOLD%^six steel-clad %^CYAN%^defenders %^RESET%^roaming its halls at %^BOLD%^%^BLACK%^n"
			"ight %^RESET%^and a troop of %^CYAN%^city guards %^WHITE%^assigned to watch it on their %^YELLOW%^patrols%^RESET%^. A"
			" massive and expertly carved %^ORANGE%^oak counter %^WHITE%^divides the room in two. Behind the %^ORANGE%^counter %^WH"
			"ITE%^sits two %^BOLD%^elderly dwarven clerks%^RESET%^, armed with %^BOLD%^%^MAGENTA%^quill %^RESET%^and %^BOLD%^ledger%^R"
			"ESET%^. Almost every %^BOLD%^%^CYAN%^merchant %^RESET%^of importance stores his or her most %^CYAN%^precious %^WHITE%^good,"
			" %^MAGENTA%^family heirlooms %^WHITE%^and other valuables here. It is rumoured that behind a solid looking %^BOLD%^%^BLACK%^stone"
			" door %^RESET%^in the back, is the stairs to the %^YELLOW%^four vaults %^RESET%^carved out beneath the bank. As a more recent action"
			" %^ORANGE%^Kinaro %^WHITE%^seizes any valuables still in storage, if their owners should be unfortunate enough to %^BOLD%^%^RED%^die"
			" %^RESET%^and no heirs are marked in the banks records, this %^YELLOW%^money %^RESET%^goes both towards bolstering the %^ORANGE%^outposts"
			" %^BOLD%^%^CYAN%^defences %^RESET%^and expanding the %^ORANGE%^mining %^BOLD%^%^BLACK%^tunnels%^RESET%^.");
   set_exits((["east" : "/d/dagger/kinaro/street4"]));
   set_smell("default","The smell of parchment and coins fills your nostrils.");
   set_listen("default","The sounds of rustling coins fill your ears.");
}
