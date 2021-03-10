#include <std.h>
#include "../farm.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(GRASSLANDS);
   set_travel(RUTTED_TRACK);
   set_name("A weathered bridge");
   set_property("light",3);
   set_property("indoors",0);
   set_short("%^BOLD%^%^WHITE%^A weathered bridge%^RESET%^");
   set_long("This narrow bridge is made of aged pine that has "+
      "%^BOLD%^silvered %^RESET%^over the years.  It is made of "+
      "roughly hewn planks, seemingly made by someone not highly "+
      "skilled in such construction.  Still, it is functional and "+
      "leads safely over the %^BOLD%^%^BLUE%^stream %^RESET%^that "+
      "begins plunging over rocky falls here.  The northern end "+
      "of the bridge ends directly at a %^ORANGE%^door %^RESET%^"+
      "leading into the %^BOLD%^building %^RESET%^housing the "+
      "%^ORANGE%^water wheel%^RESET%^.  The turning of the wheel "+
      "stirs up a more pleasant scent from the stream, and the "+
      "movement keeps the wheel algae free.  The bridge has been fitted "+
      "with %^BOLD%^rails %^RESET%^to allow a certain sense of "+
      "safety.\n");
   set_smell("default","The sweet fragrance of the stream rises "+
      "above the scent of the barnyard animals.");
   set_listen("default","The gentle music of the water wheel masks "+
      "sounds from the barnyard.");
   add_item(({"building","water wheel","wheel","waterwheel"}),"The "+
         "building is made of pine that has weathered to silver over "+
         "time.  Unlike the bridge, it seems to have been crafted "+
         "with ingenuity and easily supports the water wheel.  The "+
         "wheel itself turns endlessly, a slight creaking sound "+
         "mixing with the splashing water.");
   add_item(({"bridge","rails"}),"The bridge is very narrow, allowing "+
         "passage of only one person at once.  The rails rise only "+
         "hip-high on a human, suggesting the bridge was built "+
         "for use by one much smaller.");
   set_exits(([
      "north": PATHS"wheelhouse1",
      "south": PATHS"farm3"
   ]));
   set_door("door",PATHS"wheelhouse1","north","piaf_house_key");
   set_door_description("door","The door is made of thick pine planks "+
      "bound with iron and stained a deep brown.  The color makes it "+
      "stand in stark contrast to the silvered building around it, and "+
      "it bears a thick iron lock.");
   set_lock_description("door","lock","This lock is made of thick "+
      "iron set with a large keyhole.  It is completely free of "+
      "rust, and it looks as thought it could take much battering "+
      "before it ever broke.");
   set_locked("door",1,"lock");
   lock_difficulty("door",20,"lock");
}