//Updated by ~Circe~ 8/14/15 to reflect construction for Asgard Keep

#include <std.h>

inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create() {
    ::create();
    set_indoors(0);
    set_property("no teleport",1);
    set_light(2);
  set_terrain(BARREN);
  set_travel(DECAYED_FLOOR);
    set_short("Laerad Docks");
    set_long(
	"You stand on the docks of the massive island Laerad. A %^ORANGE%^ferry%^RESET%^ "+
	"sails in and out once in a while, carrying passengers to the "+
	"island. The beautiful %^BOLD%^%^CYAN%^ocean %^RESET%^lies to the west, waves crashing "+
	"up onto the %^ORANGE%^sh%^YELLOW%^o%^RESET%^%^ORANGE%^re%^RESET%^. The idyllic "
      "view stands in stark contrast to the %^ORANGE%^w%^GREEN%^a%^ORANGE%^st%^BOLD%^"
      "%^BLACK%^e%^RESET%^%^ORANGE%^la%^RESET%^n%^ORANGE%^ds%^RESET%^ stretching to the "
      "east. Some great tragedy has left the land scarred and broken, belching up waves "
      "of %^YELLOW%^sulfurous mist%^RESET%^. New construction along the %^ORANGE%^docks%^RESET%^ "
      "hints that this island is perhaps being reclaimed. Further testament to these developments "
      "are the %^BOLD%^ships %^RESET%^that come and go, depositing huge quantities of %^BOLD%^"
      "stone%^RESET%^, %^ORANGE%^wood%^RESET%^, and other %^GREEN%^supplies%^RESET%^ into the "
      "%^ORANGE%^fenced yard%^RESET%^ that protects them. Despite the progress, the great expanse "
      "of %^ORANGE%^bl%^RED%^a%^ORANGE%^st%^YELLOW%^e%^RESET%^%^ORANGE%^d la%^RED%^n%^ORANGE%^d "
      "%^RESET%^makes it clear there is much work to be done here.\n"
    );
/*
Original description - can be returned after Asgard Keep opens
    set_long(
	"You stand on the docks of the massive island Laerad. A ferryboat "+
	"sails in and out once in a while carrying passengers to the "+
	"island. The beautiful ocean lies to the west, waves crashing "+
	"up onto the shore. To the east lies the wasted plains of Laerad."
    );
*/
    set_items(([
       ({"ocean","sea"}) : "%^RESET%^%^CYAN%^The ocean stretches out into the distance, "
          "the cool waters sparkling %^BOLD%^blue%^RESET%^%^CYAN%^ and %^GREEN%^green "
          "%^CYAN%^in the light of the sun and %^RESET%^silver %^CYAN%^in the %^BOLD%^"
          "%^WHITE%^moonlight%^RESET%^%^CYAN%^.%^RESET%^",
       ({"shore","sand","beach"}) : "The wasted lands of Laerad give way to a bare "
          "stretch of sandy shore here at the dock. Rocks rise up from the ground, giving "
          "support to the wooden structures that stretch out into the water, providing "
          "safe docking for ships. It is not the most inviting place to relax, but it is "
          "undoubtedly more serene than the sulfurous plains to the east.",
       ({"wasteland","wastelands","mist","sulfurous mist"}) : "The barren plains stretches "
          "far to the east, broken only by jets of sulfurous mist and the occasional twisted "
          "cactus. Shapes seem to lurk and shamble in the distance, or perhaps that is "
          "simply the mist warping the air.",
       ({"dock","docks","ship","ships"}) : "Long structures of wood and stone stretch "
          "into the ocean, providing safe mooring for the many ships that come from the "
          "mainland. The colors of the sails proclaim the ships for Shadow, Torm, Seneca - "
          "even Tonovi. Most seem to carry supplies rather than passengers.", 
       ({"supplies","stone","wood","yard","fence","fenced yard"}) : "The supplies are "
          "piled behind the tall wooden fence to the northeast. The fence runs all the "
          "way down to the shore, where it turns up the coastline, effectively cutting "
          "off all access save through the guarded gate. The piles of stone, wood, and "
          "supplies are put to good use building the new keep that is rising atop the hill."
    ]));
    set_exits(([
	"east":"/d/laerad/wasteland/waste1"
      ]));
    set_smell("default","You smell the parched desert winds blowing in from the east.");
    find_object_or_load("d/shadow/virtual/sea/obj/ferryboat1")->move(TO);
    set_listen("default","You hear the sounds of waves crashing against the sandy beaches."); 
}
