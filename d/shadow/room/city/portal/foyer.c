#include <std.h>
#include <daemons.h>
inherit "/std/psionportal";

void create(){
    ::create();
    set_property("indoors",0);
    set_property("light",2);
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_name("An open-air foyer");
    set_short("%^RESET%^%^MAGENTA%^An open-air foyer%^RESET%^");
    set_long("%^RESET%^%^MAGENTA%^An open-air foyer%^RESET%^\n"+
       "The %^CYAN%^wind %^RESET%^blows gently, switching directions "+
       "continually in this unusual open-air foyer.  The sky above "+
       "reveals that this is no ordinary place, as it is %^BOLD%^%^BLACK%^"+
       "deep black %^RESET%^streaked with %^GREEN%^greens%^RESET%^, "+
       "%^CYAN%^blues%^RESET%^, %^MAGENTA%^purples%^RESET%^, and "+
       "brilliant spots of %^YELLOW%^gold%^RESET%^.  The foyer seems "+
       "to have been grown here rather than built, though it is shaped "+
       "something like the classic buildings of the realms.  Rising "+
       "from the %^MAGENTA%^cr%^BOLD%^y%^RESET%^%^MAGENTA%^stalli%^BOLD%^n"+
       "%^RESET%^%^MAGENTA%^e ground %^RESET%^is a ring of smooth "+
       "translucent %^MAGENTA%^pillars %^RESET%^that shift in color from "+
       "%^MAGENTA%^deep purple %^RESET%^to a %^BOLD%^%^MAGENTA%^light "+
       "blush %^RESET%^and end in jagged crowns, almost as if they still "+
       "bear the ghost of a roof.  %^BOLD%^%^CYAN%^Flashes %^RESET%^of "+
       "%^BOLD%^sil%^CYAN%^v%^WHITE%^ery li%^CYAN%^g%^WHITE%^ht %^RESET%^"+
       "illuminate the ring of columns and reveal a %^BOLD%^circle "+
       "%^RESET%^carved into the crystal of the ground.  An "+
       "%^CYAN%^ethereal building %^RESET%^carved from shimmering "+
       "crystal walls rises to the east.\n\n"+
       "A sign has been carved into one of the pillars.\n");
    set_listen("default","The low moan of the wind breaks the silence.");
    set_smell("default","A light fragrance of ozone resides in the air here.");
    set_items(([
      ({"circle","dust","glittering dust"}) : "%^BOLD%^%^BLUE%^A circle has "
         "been carved into the %^RESET%^%^MAGENTA%^smooth crystalline ground"+
         "%^BOLD%^%^BLUE%^, and filled with some kind of %^RESET%^gli%^BOLD%^"+
         "t%^RESET%^ter%^BOLD%^i%^RESET%^ng %^BOLD%^%^BLUE%^dust, perhaps to "+
         "highlight its presence.",
      ({"sky","colors","streaks","light","flashes","lights"}) : "%^BOLD%^%^BLACK%^The "+
         "inky black sky is lightened in places "+
         "with streaks and swirls of %^GREEN%^greens%^BLACK%^, "+
         "%^CYAN%^blues%^BLACK%^, %^RESET%^%^MAGENTA%^purples%^BOLD%^"+
         "%^BLACK%^, and %^YELLOW%^golds%^BLACK%^.  Flashes of light "+
         "reminiscent of lightning without the thunder brighten the sky "+
         "in fitful intervals.%^RESET%^",
      ({"pillars","columns","pillar","column"}):"%^RESET%^%^MAGENTA%^"+
         "Encircling the smooth crystalline floor is a ring of "+
         "pillars made of pur%^BOLD%^p%^RESET%^%^MAGENTA%^le crystal.  "+
         "Each column ends in a jagged top, almost as if some force "+
         "ripped a roof away at one time.  Carved into one of the "+
         "pillars is a %^RESET%^sign %^MAGENTA%^you could read.%^RESET%^",
      "sign":"%^BOLD%^%^MAGENTA%^A small %^RESET%^sign "+
         "%^BOLD%^%^MAGENTA%^has been carved into the pillar, engraved "+
         "with elegant script you could read.%^RESET%^",
      "building" : "Looming on the east is a fanciful building with "+
         "arching lines and curves.  Like the pillars, it seems almost "+
         "organic, grown from crystals of varying colors."
    ]));
    set_exits(([
      "east":"/d/shadow/room/city/portal/fountain"
    ]));
    add_location("azha",0,55,"/d/azha/town/wroad");
    add_location("torm",0,55,"/d/dagger/Torm/road/path12");
    add_location("verbobone",15,75,"/d/deku/town/road13");
    add_location("seneca",25,95,"/d/attaya/newseneca/rooms/boardwalk3");
    add_location("shadow",0,0,"/d/darkwood/room/road1");
}

query_weather() { return "%^BOLD%^%^BLUE%^The constant wind swirls "+
   "through the %^GREEN%^co%^CYAN%^lo%^RESET%^%^MAGENTA%^r-%^YELLOW%^st"+
   "%^GREEN%^re%^CYAN%^ak%^RESET%^%^MAGENTA%^ed %^BOLD%^%^BLUE%^sky%^RESET%^."; }

void reset(){
    ::reset();
    if(!present("portalpsion")) {
      new("/d/shadow/mon/nomad")->move(TO);
      tell_room(TO,"%^CYAN%^A robed human enters quietly into the area, to stand behind the etched circle.%^RESET%^");
    }
}