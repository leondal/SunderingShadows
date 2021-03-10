#include <std.h>
#include <move.h>
#include "../tecqumin.h"


inherit CITY_JUNG;


void create() {
  ::create();
  add_item ( ({"road", "ancient road","causeway", "stone causeway",
    "remains of ancient road", "stone", "patches of stone", 
    "patches of worked stone", "worked gray stone"}), 
    "The ancient road runs east-west here. The broad causeway has"
  +" a slightly cambered stone surface, indicative of skilled"
  +" construction. It is mostly intact, though time and the elements"
  +" have weathered the surface, and %^BOLD%^%^GREEN%^j%^RESET%^"
  +"%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l%^BOLD%^e pl%^RESET%^"
  +"%^GREEN%^a%^GREEN%^nts %^RESET%^writhe up through cracks in the"
  +" stone here and there." );
  add_item ( ({"road", "ancient road", 
    "remains of ancient road", "stone", "patches of stone", 
    "patches of worked stone", "worked gray stone"}), 
    "The ancient road runs east-west here. The broad causeway has"
  +" a slightly cambered stone surface, indicative of skilled"
  +" construction. It is mostly intact, though time and the elements"
  +" have weathered the surface, and %^BOLD%^%^GREEN%^j%^RESET%^"
  +"%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l%^BOLD%^e pl%^RESET%^"
  +"%^GREEN%^a%^GREEN%^nts %^RESET%^writhe up through cracks in the"
  +" stone here and there." );
  add_item ( ({"plaza", "stone plaza", 
    "large stone plaza"}), 
    "The plaza opens out a huge area in the %^BOLD%^%^GREEN%^j"
  +"%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l%^BOLD%^e%^RESET%^,"
  +" giving a clear view of the expanse of %^BOLD%^%^CYAN%^sky%^RESET%^"
  +" above. A stone ziggurat lies to the north of the plaza, and another,"
  +" strange stone structure to the south." );
  add_item ( ({"ziggurat", "stone ziggurat",
    "pyramid", "stone pyramid"}), 
    "The ziggurat takes the form of a huge stone ziggurat rising above"
   +" the plaza. The top of it can be made out even above the tops of the"
   +" trees here. You will need to get closer to see more." );
  add_item ( ({"structure", "strange structure", 
    "strange stone structure", "stone structure", "palace", 
    "stone palace"}), 
    "The strange stucture to the north of the plaza can only be partly"
   +" made out from here, but it seems to have been built in the shape"
   +" of some form of animal. You will need to get closer to see better." );
}


string short_desc(){
  return "%^BOLD%^%^GREEN%^An %^RESET%^ancient road bordered by %^RESET%^%^GREEN%^encroaching%^BOLD%^"
           +" %^GREEN%^jungle";
}

