//Octothorpe (1/21/17)
//Shadow, Mage Tower Second Floor Landing
//Designed by Ivyes

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_climate("temperate");
   set_name("Second Floor Landing in the Shadow Mage Tower");
   set_short("%^BOLD%^%^MAGENTA%^Second Floor Landing in the "+
      "%^BOLD%^%^BLACK%^Shadow %^MAGENTA%^Mage Tower%^RESET%^");
   set_long("%^BOLD%^%^MAGENTA%^Second Floor Landing in the "+
      "%^BOLD%^%^BLACK%^Shadow %^MAGENTA%^Mage Tower\n"+
      "%^RESET%^%^MAGENTA%^You're standing on a balcony the wraps "+
      "around the entirety of the second floor, and allows you to "+
      "peer down into the foyer below. The %^BOLD%^%^RED%^pl%^RESET%^"+
      "%^RED%^u%^BOLD%^sh r%^RESET%^%^RED%^e%^BOLD%^d c%^RESET%^%^RED%^"+
      "a%^BOLD%^rp%^RESET%^%^RED%^e%^BOLD%^t %^RESET%^%^MAGENTA%^"+
      "beneath your feet muffles most sounds, leaving only %^BOLD%^soft "+
      "conversations %^RESET%^%^MAGENTA%^and the %^BOLD%^strange music "+
      "%^RESET%^%^MAGENTA%^that drifts down from the %^YELLOW%^golden "+
      "piping %^RESET%^%^MAGENTA%^overhead. A few %^ORANGE%^benches "+
      "%^MAGENTA%^are scattered around the balcony, providing a place "+
      "to relax.\n\n"+
      "%^RESET%^%^CYAN%^Shops lay to your east and west, their arched "+
      "doorways open and inviting. Before you looms the narrow "+
      "staircase that begins the long ascension toward the roof.%^RESET%^\n");
   set_smell("default","%^BOLD%^%^CYAN%^Curious %^RESET%^%^CYAN%^scents "+
      "%^BOLD%^drift from the open shops.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLACK%^Haunting %^MAGENTA%^m%^RESET%^"+
      "%^MAGENTA%^u%^BOLD%^sic %^BLACK%^plays from overhead.%^RESET%^");
   set_items(([
      "balcony" : "%^RESET%^%^CYAN%^The balcony wraps around the "+
         "entire floor, allowing you to peer down to the foyer below, "+
         "or upward at the narrow staircase that spirals toward the "+
         "roof. A %^BOLD%^%^RED%^red carpet %^RESET%^%^CYAN%^with a "+
         "muted %^GREEN%^floral pattern %^CYAN%^lines the floor. A "+
         "%^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^, %^BOLD%^%^BLACK%^"+
         "wrought-iron railing %^RESET%^%^CYAN%^lines the balcony.%^RESET%^",
      "carpet" : "%^RESET%^%^CYAN%^A %^BOLD%^%^RED%^red carpet "+
         "%^RESET%^%^CYAN%^with a muted %^GREEN%^floral pattern "+
         "%^CYAN%^lines the floor.%^RESET%^",
      "benches" : "%^RESET%^%^CYAN%^Simple benches provide a place to "+
         "rest your weary bones.%^RESET%^",
      "shops" : "%^RESET%^%^CYAN%^Do you want to look at the shop to "+
         "the %^BOLD%^east%^RESET%^%^CYAN%^, or the shop to the "+
         "%^BOLD%^west%^RESET%^%^CYAN%^?%^RESET%^",
      "west shop" : "%^BOLD%^%^GREEN%^The %^RESET%^open archway "+
         "%^BOLD%^%^GREEN%^leads into a %^RESET%^%^CYAN%^components "+
         "shop%^BOLD%^%^GREEN%^. A %^RESET%^%^ORANGE%^wooden "+
         "sign %^BOLD%^%^GREEN%^hanging above the door reads: %^MAGENTA%^"+
         "The Mad Hat.%^RESET%^",
      "east shop" : "%^BOLD%^%^GREEN%^The %^RESET%^open archway "+
         "%^BOLD%^%^GREEN%^leads into a %^RESET%^%^CYAN%^scroll "+
         "shop%^BOLD%^%^GREEN%^. A %^RESET%^%^ORANGE%^wooden sign "+
         "%^BOLD%^%^GREEN%^hanging above the door reads: %^RESET%^"+
         "%^GREEN%^The Green Hag's Relics and Runes.%^WHITE%^",
      ({"stairs","staircase","spire"}) : "%^RESET%^%^CYAN%^Glancing "+
         "upwards produces a sudden case of vertigo. A %^BOLD%^%^WHITE%^"+
         "white marble staircase%^RESET%^%^CYAN%^, inlaid with a complex "+
         "twisting maze of %^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^ld "+
         "%^RESET%^%^CYAN%^along the bottom, spirals up, and up, and up. "+
         "While quite extraordinary to see, it's a bit daunting to "+
         "think of how many stairs one must climb from here if they "+
         "wish to reach the top.%^RESET%^",
   ]));
   set_exits(([
      "east" : ROOMS"magescrolls",
      "west" : ROOMS"magecomps",
      "down" : ROOMS"magefoyer",
      "up" : ROOMS"mage3rdlanding"
   ]));
}