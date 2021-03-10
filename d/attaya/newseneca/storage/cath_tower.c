//cath_tower.c - inherit for the cathedral bell tower
//for new Seneca ~Circe~ 1/14/08
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_light(3);
   set_name("Bell Tower of the Cathedral, Seneca");
   set_short("Bell Tower of the Cathedral, Seneca");
   set_long("%^BOLD%^Bell Tower of the Cathedral, Seneca%^RESET%^\n"+
      "The smooth %^BOLD%^sa%^RESET%^n%^BOLD%^d"+
      "st%^YELLOW%^o%^BOLD%^%^WHITE%^ne %^RESET%^w%^BOLD%^al%^YELLOW%^l"+
      "%^BOLD%^%^WHITE%^s %^RESET%^form a perfect square, enclosing "+
      "the narrow %^ORANGE%^wooden staircase %^RESET%^that winds "+
      "its way upward.  Each level features gracefully arched "+
      "%^BOLD%^windows %^RESET%^left glassless to let in light "+
      "and the %^CYAN%^elements%^RESET%^, though the fantastic "+
      "weather in Seneca helps ensure that the latter is not often a "+
      "problem.  The stairs climb ever upward, leading to the "+
      "beautiful %^ORANGE%^brass bells %^RESET%^housed within the "+
      "upper chamber on the tenth story.\n");
   set_smell("default","The clean scent of the ocean wafts in through the windows.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"walls","sandstone walls"}) : "The sandstone walls are "+
         "smooth and cool to the touch.  They have been well-"+
         "fitted, but the interior lacks the decorative %^YELLOW%^"+
         "gold %^RESET%^and %^BOLD%^silver %^RESET%^edgings of the "+
         "exterior wall, and as such, the joints can be more "+
         "readily seen.",
      ({"staircase","stairs","wooden staircase"}) : "No grand "+
         "marble affair climbs the bare sandstone walls here.  "+
         "Instead, simple wooden stairs rise upward, following "+
         "the planes of the walls as they curve around.  Here "+
         "and there, you can see %^BOLD%^%^BLACK%^cobwebs %^RESET%^"+
         "collecting in the corners.",
      ({"window","windows","arched windows","arched window"}) : 
         "To the east and west, a narrow window rises in a "+
         "graceful arch, looking out over the city of Seneca.  "+
         "The windows have no glass, letting in both light "+
         "and wind - and occasionally rain or snow.",
      ({"bell","bells","brass bells","brass bell"}) : "Looking "+
         "up, you can see the twin %^ORANGE%^brass bells %^RESET%^"+
         "hanging above, the spiralling staircases creating a "+
         "dizzying sense of vertigo."
   ]));
}
