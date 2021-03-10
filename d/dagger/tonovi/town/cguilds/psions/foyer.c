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
    set_short("%^RESET%^%^GREEN%^An open-air foyer%^RESET%^");
    set_long("%^RESET%^%^GREEN%^An open-air foyer%^RESET%^\n"+
       "The %^CYAN%^wind %^RESET%^blows gently, switching directions "+
       "continually in this unusual open-air foyer.  The sky above "+
       "reveals that this is no ordinary place, as it is %^BOLD%^%^BLACK%^"+
       "deep black %^RESET%^streaked with %^GREEN%^greens%^RESET%^, "+
       "%^CYAN%^blues%^RESET%^, %^MAGENTA%^purples%^RESET%^, and "+
       "brilliant spots of %^YELLOW%^gold%^RESET%^.  The foyer seems "+
       "to have been grown here rather than built, though it is shaped "+
       "something like the classic buildings of the realms.  Rising "+
       "from the %^GREEN%^cr%^BOLD%^y%^RESET%^%^GREEN%^stalli%^BOLD%^n"+
       "%^RESET%^%^GREEN%^e ground %^RESET%^is a ring of smooth "+
       "translucent %^GREEN%^pillars %^RESET%^that shift in color from "+
       "%^GREEN%^deep emerald %^RESET%^to a %^BOLD%^%^GREEN%^light "+
       "viridian %^RESET%^and end in jagged crowns, almost as if they still "+
       "bear the ghost of a roof.  %^BOLD%^%^CYAN%^Flashes %^RESET%^of "+
       "%^BOLD%^%^RED%^crim%^RESET%^%^RED%^s%^BOLD%^on li%^RESET%^%^RED%^g"+
       "%^BOLD%^ht %^RESET%^illuminate the ring of columns and reveal a "+
       "%^BOLD%^circle %^RESET%^carved into the crystal of the ground.  "+
       "An %^CYAN%^ethereal building %^RESET%^carved from shimmering "+
       "crystal walls rises to the east.\n\n"+
       "A sign has been carved into one of the pillars.\n");
    set_listen("default","The low moan of the wind breaks the silence.");
    set_smell("default","A light fragrance of ozone resides in the air here.");
    set_items(([
      ({"circle","dust","glittering dust"}) : "%^BOLD%^%^BLUE%^A circle has "
         "been carved into the %^RESET%^%^GREEN%^smooth crystalline ground"+
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
      ({"pillars","columns","pillar","column"}):"%^RESET%^%^GREEN%^"+
         "Encircling the smooth crystalline floor is a ring of "+
         "pillars made of emer%^BOLD%^a%^RESET%^%^GREEN%^ld crystal.  "+
         "Each column ends in a jagged top, almost as if some force "+
         "ripped a roof away at one time.  Carved into one of the "+
         "pillars is a %^RESET%^sign %^GREEN%^you could read.%^RESET%^",
      "sign":"%^BOLD%^%^GREEN%^A small %^RESET%^sign "+
         "%^BOLD%^%^GREEN%^has been carved into the pillar, engraved "+
         "with elegant script you could read.%^RESET%^",
      "building" : "Looming on the east is a fanciful building with "+
         "arching lines and curves.  Like the pillars, it seems almost "+
         "organic, grown from crystals of varying colors."
    ]));
    set_exits(([
      "south":"/d/dagger/tonovi/town/cguilds/psions/fountain"
    ]));
    add_location("tharis",0,55,"/d/tharis/road/road9");
    add_location("juran",0,55,"/d/shadow/room/forest/owagon26");
    add_location("verbobone",15,75,"/d/deku/town/road13");
    add_location("seneca",25,95,"/d/attaya/newseneca/rooms/boardwalk3");
    add_location("tonovi",0,0,"/d/dagger/tonovi/road2");
}

query_weather() { return "%^BOLD%^%^BLUE%^The constant wind swirls "+
   "through the %^GREEN%^co%^CYAN%^lo%^RESET%^%^MAGENTA%^r-%^YELLOW%^st"+
   "%^GREEN%^re%^CYAN%^ak%^RESET%^%^MAGENTA%^ed %^BOLD%^%^BLUE%^sky%^RESET%^."; }

void reset(){
    ::reset();
    if(!present("portalpsion")) {
      new("/d/shadow/mon/evilnomad")->move(TO);
      tell_room(TO,"%^CYAN%^A robed human enters quietly into the area, to stand behind the etched circle.%^RESET%^");
    }
}