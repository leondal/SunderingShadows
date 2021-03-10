//grotto2 - Nereid's cave for Riddle quest.  Circe 12/7/03
#include <std.h>
#include "../koenig.h"

inherit ROOM;

void create() {
    	::create();
      set_terrain(NAT_TUNNEL);
      set_travel(SLICK_FLOOR);
      set_property("indoors",1);
    	set_property("light",3);
    	set_short("A secret grotto");
    	set_name("A secret grotto");
    	set_long(
         "%^BOLD%^%^WHITE%^As sparkling and radiant as the tunnel west of "+
         "here is, this hidden grotto %^YELLOW%^shines %^WHITE%^in comparison.  "+
         "A large, oval %^CYAN%^pool %^WHITE%^of measureless %^BLACK%^depth "+
         "%^WHITE%^dominates the center of the floor.  Only a narrow ledge "+
         "seemingly made of %^BLUE%^sapp%^CYAN%^h%^BLUE%^ires %^WHITE%^provides a "+
         "place to stand, although it, too, is covered with a thin layer of running "+
         "%^CYAN%^water%^WHITE%^.  The %^BOLD%^%^CYAN%^m%^WHITE%^i%^RESET%^c%^CYAN%^a "+
         "%^BOLD%^%^WHITE%^walls here are shot through with veins of %^YELLOW%^gold "+
         "%^WHITE%^alternating with %^BLUE%^g%^CYAN%^e%^GREEN%^m%^YELLOW%^s%^RED%^t"+
         "%^MAGENTA%^o%^RESET%^%^MAGENTA%^n%^BOLD%^%^BLUE%^e%^CYAN%^s%^WHITE%^.  "+
         "An enormous %^YELLOW%^topaz %^WHITE%^hangs suspended from the ceiling by "+
         "a thin %^YELLOW%^golden wire%^WHITE%^, and the brilliant light from it "+
         "illuminates the whole cavern."+
         "\n"
      );
     	set_smell("default","The crisp, clear scent of water masks all other smells.");
     	set_listen("default","An ethereal voice singing rises above the roar of the waterfall.");
    	set_exits(([
       	"west" : VILSTREAM"grotto1",
    	] ));
    	set_items(([
         ({"wall","mica","walls"}) : "The walls are made of layers of the translucent "+
            "rock mica that sparkles and adds its own radiance to the cavern.  The walls "+
            "arch overhead, forming a relatively smooth ceiling.  The walls are spider "+
            "webbed with veins of gold and gemstones.",
         ({"ceiling","topaz"}) : "%^YELLOW%^The ceiling is carved of mica just like "+
            "the walls.  No moss grows here, but the "+
            "large topaz suspended from the ceiling provides ample light.  Its many-"+
            "faceted shape causes the light to twinkle iridescently.",
         ({"pool","water","pond"}) : "The water from the stream forms a deep pool here.  "+
            "No matter which way you peer into the water, you cannot see a bottom.  The "+
            "water is crystal clear and cool.",
         ({"veins","veins of gold","gems","gemstones"}) : "Slender veins of gold make their "+
            "way through the walls of mica.  They provide additional illumination to the "+
            "cavern and make is sparkle as though the entire room was gilted.  Gemstones "+
            "in all shades of red, blue, green, yellow, and purple are scattered throughout "+
            "the walls as well.",
         ({"ledge","ground","floor"}) : "The narrow ledge running around the edge of the "+
            "pool is translucent and a deep blue, seemingly made of sapphire.  It is smooth "+
            "and covered with a layer of running water."
    	] ));
}

void reset() {
   ::reset();
   if(!present("Laurelinduin")){
      new("/d/koenig/riddle/nereid")->move(TO);
   }
   switch(random(4)){
      case 0:   tell_room(TO,"%^BOLD%^%^CYAN%^A gentle wave ripples across the surface of the pool.");
                break;
      case 1:   tell_room(TO,"%^BOLD%^An ethereal song rises in the cavern.");
                break;
      case 2:   tell_room(TO,"%^BOLD%^%^BLUE%^The soothing babble of the stream ripples through the cavern.");
                break;
      case 3:   tell_room(TO,"%^YELLOW%^The topaz glows brightly, causing the walls to sparkle.");
                break;
      default:  break;
   }
}