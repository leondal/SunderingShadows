//sstreet48 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VERDE;

void create(){
   ::create();
   set_long(::query_long()+"Just north of here is a humble %^ORANGE%^"+
      "adobe building %^RESET%^with a flat roof.  You do not see an "+
      "entrance from this side.  The south seems oddly open, as the %^BOLD%^"+
      "town walls %^RESET%^do not cover this stretch of the street, "+
      "and you can see the %^YELLOW%^beach %^RESET%^far below the "+
      "edge of the cliff on which %^BOLD%^Seneca %^RESET%^stands.  A "+
      "%^ORANGE%^rocky pathway %^RESET%^leads south of here, "+
      "seemingly heading toward the beach.\n");
   set_exits(([
      "east" : ROOMS"sstreet26",
      "west" : ROOMS"sstreet48",
      "south" : ROOMS"rockypath1"
   ]));
   add_item("building","The building to the north looks somewhat out "+
      "of place, being made of humble adobe while the buildings "+
      "around it are so much more grand.  Perhaps it is a shop of "+
      "some sort - or maybe a home?");
   add_item("beach","Seneca stands on the edge of a cliff overlooking "+
      "a portion of the beach below.  From here, you can see a small "+
      "stretch of %^YELLOW%^g%^WHITE%^o%^RESET%^l"+
      "%^YELLOW%^d%^WHITE%^e%^RESET%^n sand and %^CYAN%^waves %^RESET%^"+
      "pounding the shore far below you.");
   add_item("cliff","Seneca stands on the edge of a cliff overlooking "+
      "a portion of the beach below.  From here, you can see a small "+
      "stretch of %^YELLOW%^g%^WHITE%^o%^RESET%^l"+
      "%^YELLOW%^d%^WHITE%^e%^RESET%^n sand and %^CYAN%^waves %^RESET%^"+
      "pounding the shore far below you.");
   add_item("path","The southern pathway looks to have been carved "+
      "from the cliff face itself.  It reveals veins of %^YELLOW%^"+
      "golden rock %^RESET%^throughout the otherwise ordinary %^ORANGE%^"+
      "brown%^RESET%^, clearly the reason for the sand's color here.");
   add_item("pathway","The southern pathway looks to have been carved "+
      "from the cliff face itself.  It reveals veins of %^YELLOW%^"+
      "golden rock %^RESET%^throughout the otherwise ordinary %^ORANGE%^"+
      "brown%^RESET%^, clearly the reason for the sand's color here.");
   remove_item("wall");
   remove_item("walls");
   remove_item("coquina");
   remove_item("coquina walls");
}