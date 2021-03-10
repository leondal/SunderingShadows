#include <std.h>
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("Temple Ruins");
   set_short("Temple Ruins");
   set_long("%^RESET%^%^MAGENTA%^This circular temple must once have "
      "been an exquisite contrast to the plain countryside around it, "
      "but if so those days have passed.  Most of it now lies as a "
      "charred pile of %^RESET%^white marble%^MAGENTA%^, pocked and "
      "burnt with signs of extreme force.  In the center stands "
      "a %^BOLD%^%^BLACK%^melted marble lump %^RESET%^%^MAGENTA%^that "
      "may once have been the altar.  Scattered fragments of glass and "
      "wood, cloth and carpet suggest the %^BOLD%^%^RED%^fine %^RESET%^"
      "%^MAGENTA%^quality of artwork it must once have held, but to the "
      "last they are now shredded and ruined by weather.%^RESET%^");
   set_items(([
      "countryside" : "%^RESET%^%^GREEN%^The rolling countryside here is "
         "lush and green, with fields breaking up the landscape with their "
         "orderly rows of crops. Farmhouses can be seen in the distance "
         "along the Quiet Forest Road, and a small village is visible just to the south.%^RESET%^",
      ({"marble","white marble","pile","charred pile"}) : "%^RESET%^Huge "
         "chunks of %^BOLD%^white marble %^RESET%^veined with %^BOLD%^s%^RESET%^i"
         "%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r litter the area. A few rise up "
         "taller, hinting at the walls that once shaped this temple back in "
         "its glory days. Little remains to indicate who or what this temple was dedicated to.",
      ({"altar","lump","marble lump"}): "One can only imagine what might "
         "have caused the %^BOLD%^%^BLACK%^altar %^RESET%^at the center of this "
         "temple to be melted into is current amorphous shape. Here and there, "
         "you see streaks of %^RESET%^%^CYAN%^bl%^BOLD%^u%^RESET%^%^CYAN%^e%^RESET%^, "
         "%^BOLD%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r, and %^RESET%^%^RED%^"
         "red%^RESET%^, some merely smears or sparkles within the marble.",
      ({"fragments","artwork","glass","wood","cloth","carpet"}) : "The sheer amount "
         "of debris from artwork scattered around the ruins is mind-boggling. "
         "This place must have been almost a museum of sorts, housing brilliant "
         "%^RESET%^%^MAGENTA%^tapestries%^RESET%^, %^CYAN%^relics%^RESET%^, and "
         "%^BOLD%^statues%^RESET%^. Sadly, all is now lost, and only detritus remains."
   ]));
   set_smell("default","A faint residue of smoke lingers about these ruins.");
   set_listen("default","Silence hangs heavily upon this place.");
   set_exits(([
      "south" : "/d/magic/temples/m_ruin"
   ]));

}
