#include <std.h>
#include "../tormdefs.h"
inherit ROOM;

void create()
{
  ::create();
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
  set_property("light",2);
  set_short("Top of a watchtower on Torm's walls");
  set_long(
    "%^BOLD%^Top of a watchtower on Torm's walls.\n"+
  "  You stand at the top of a turret on the green walls of Torm."+
  "  To the west you can see the beach end and the forests of Dagger"+
  " start.  Far to the north shrouded in mist mountains can occasionally"+
  " be seen in the haze.  The Dagger Sea stretches off from the city's"+
  " docks to the east to the horizon.  The city itself seems to bustle"+
  " with life and seems carefree and happy to be making money in the"+
  " great open market place."
  );
  set("night long",
  "%^BLUE%^"
  "You stand at the top of a turret over the dark and still city of"+
  " Torm.  A light fog blankets the bay in which Torm was built, wispy"+
  " tendrils stretch out into the city streets, but stays low to the"+
  " ground.  The fog is probably quite natural, and most likely provided"+
  " protection to Torm from pirates and such in the early days, with"+
  " no one willing to risk their ship on the deadly rocks that are"+
  " concealed by the fog.  All the shutters in the city are closed fast"+
  " and even the Torm guards have sought their beds, apparently trusting"+
  " to the city walls to protect them from danger."
  );
  set_smell("default","Sea salt assaults your nose.");
  set_listen("default","The gentle sound of the waves of the Dagger Sea reach you.");
  set_items(([
  ({"watchtower","tower","watch tower","turret"}) : "This guardpost is barely"+
  " an archer's nest from the size of it.  It's covered with a peaked roof,"+
  " from which a spire like many of the other buildings in Torm have emerges.",
  ({"walls","city walls"}) : "%^GREEN%^The walls of Torm are made of a"+
  " strange green stone.  They are very thin for a wall expected to keep out"+
  " invaders, whith no room even for a walkway between watchtowers at their"+
  " top.%^RESET%^",
  ({"city","Torm","torm","buildings","building"}) : "The city of Torm is very"+
  " ornate, with many of the buildings having tall spires reaching from their"+
  " roofs.  You can see three walled mansions in the city, one in each corner"+
  " besides the one open to the sea where the harbor is. A great open"+
  " marketplace lies in the center of Torm with a walled park, as well as"+
  " another great building in it to the marketplaces north.", 
  ({"sea","dagger sea","Dagger Sea"}) : "%^BLUE%^The Dagger Sea sparkles as"+
  " it comes right into the city of Torm on its east side in a great harbor"+
  " with boardwalks and docks stretching out onto it.%^RESET%^",
  ({"boardwalks","docks"}) : "Long wooden docks stretch out on the harbor"+
  " providing space for the ships that sail these waters access to the city."+
  " A few of them are big enough to have shops and stalls set out on them.",
  "fog" : "A light fog blankets the entire city, but stays low to the"+
  " ground so you can still see the tops of the buildings and the tall"+
  " spires of Torm.",
  "harbor" : "The east side of Torm is open to the Dagger Sea, with many"+
  " boardwalks and docks from the city going out into it.",
  ]));
}
void reset(){
   object ob;
   ::reset();
   if(!(query_night())){
      if(!present("archer")){
         ob=new(MON+"guard3.c");
         ob->move(TO);
      }
   }
}
