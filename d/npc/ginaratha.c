#include <std.h>;

inherit VENDOR;

void create() {
   ::create();
   set_name("Ginaratha");
   set_id( ({ "Ginaratha", "ginaratha", "vendor", "tool vendor"}) );
   set_short("Ginaratha, tool vendor");
   set_long("%^CYAN%^Ginaratha is a gnomish female dressed in a variety of"+
	" %^RED%^b%^CYAN%^r%^YELLOW%^i%^GREEN%^g%^MAGENTA%^h%^BLUE%^t%^RESET%^"+
	"%^CYAN%^ colors and patterns, typical for her race.  Her loose fitting "+
	"garments do little to hide her ample mass, a sign of a woman who enjoys"+
	" life to its fullest.  Set into a single braid, her %^ORANGE%^nut brown"+
	"%^CYAN%^ hair hangs down to her back.  Her alert %^ORANGE%^hazel%^CYAN%^"+
	" eyes glance at the bazaar around her through a pair of glass %^BOLD%^"+
	"spectacles%^RESET%^%^CYAN%^. Her small %^YELLOW%^wooden cart%^RESET%^%^CYAN%^"+
	" is set up to show the tools and sets that she has made herself.  Oddly enough"+
	" her cart seems drawn by a single fat %^RESET%^gray mouse%^CYAN%^, who rests in"+
	" her lap.  A decorative pipe rests between her thin lips as the scent of "+
	"fragrant tobacco linger around her.  She gives you a kind smile and waves you"+
	" over to her wares.");
   set_gender("female");
   set_alignment(6);
   set_race("gnome");
   set_level(19);
   set_storage_room("/d/npc/storage/ginaratha_storage");
   set_hd(19,3);
   set_exp(10);
   set_items_allowed("misc");
}
