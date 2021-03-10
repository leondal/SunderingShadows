#include <std.h>
#include "/d/deku/inherits/graveyard.h"
#include <daemons.h>
#define TOMB_ITEMS ({"building","tomb","glowing building","ghostly building","ghostly glowing building","ghostly tomb","glowing tomb"})
inherit GRAVEYARD2;
string original_long;

void do_tombs();

void create() {
    ::create();
 original_long = TO->query_long();
 set_exits(([
   "west":GY_ROOMS +"grave6-6",
   "south":GY_ROOMS +"grave5-5",
   "east" : GY_ROOMS +"grave6-4",
   "north" : GY_ROOMS +"grave7-5"
  ] ));
 do_tombs();
}

void reset() {
  ::reset();
  do_tombs();
}

void do_tombs() {
 int x;

 if((string)EVENTS_D->query_time_of_day() == "night" && member_array("tomb",query_exits()) == -1) {
   TO->add_exit(GY_ROOMS+"tomb2","tomb");
   set_door("glowing door",GY_ROOMS +"tomb2","tomb");	
   set_string("glowing door", "open", "%^CYAN%^The door swings silently outward and through your body.%^RESET%^");
   set_door_description("glowing door","%^BOLD%^%^CYAN%^This glowing door is made from an unknown substance.  It doesn't appear to be solid yet somehow it manages to completely obscure any attempt at viewing whatever may linger behind it.%^RESET%^");
   tell_room(TO,"%^BOLD%^%^CYAN%^As the soft moonlight cascades through the graveyard, a ghostly, glowing building appears here amongst the ruins.%^RESET%^");
   TO->set_long(original_long + "%^BOLD%^%^WHITE%^  A %^BOLD%^%^CYAN%^ghostly, glowing building%^BOLD%^%^WHITE%^ rests undisturbed here amongst the ruins.%^RESET%^");
  for(x = 0;x < sizeof(TOMB_ITEMS);x++) {
    TO->add_item(TOMB_ITEMS[x],"%^BOLD%^%^CYAN%^This glowing building is made from an unknown substance.  It doesn't appear solid, yet seems to somehow mask whatever may rest within it.  It continually gives off a bright, ghostly glow.  An eerie feeling begins to eat at you as you behold it.%^RESET%^");
  }
 }
 if((string)EVENTS_D->query_time_of_day() == "day" && member_array("tomb",query_exits()) != -1) {
  TO->remove_door("glowing door");
  TO->remove_exit("tomb");
  TO->set_long(original_long);
  tell_room(TO,"%^BOLD%^%^YELLOW%^As the daylight cascades through the graveyard, the ghostly, glowing building silently fades from existence.%^RESET%^");
  for(x = 0;x < sizeof(TOMB_ITEMS);x++) {
    TO->remove_item(TOMB_ITEMS[x]);
   }
 }
}
