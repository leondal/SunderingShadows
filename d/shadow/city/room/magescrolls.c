//Octothorpe (1/21/17)
//Shadow, Mage Tower Green Hag Spell Shop
//Designed by Ivyes

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_climate("temperate");
   set_name("The Green Hag");
   set_short("%^BOLD%^%^GREEN%^The Green Hag's Relics and Runes, "+
      "%^BOLD%^%^BLACK%^Shadow %^GREEN%^Mage Tower%^RESET%^");
   set_long("%^BOLD%^%^GREEN%^The Green Hag's Relics and Runes, "+
      "%^BOLD%^%^BLACK%^Shadow %^GREEN%^Mage Tower\n"+
      "%^RESET%^%^GREEN%^Exactly eight steps leads down into this "+
      "very %^BOLD%^curious %^RESET%^%^GREEN%^room. It stands out "+
      "from the other rooms of the tower because it is mostly made "+
      "from %^ORANGE%^old wo%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^d"+
      "%^GREEN%^, managing to look both %^MAGENTA%^ancient %^GREEN%^"+
      "and %^MAGENTA%^extraordinary %^GREEN%^at once. At the right of "+
      "the stairs grows a stocky little %^BOLD%^tree%^RESET%^"+
      "%^GREEN%^, with a fat girth and a fatter crown. %^BOLD%^"+
      "%^MAGENTA%^Glowing fruits %^RESET%^%^GREEN%^hang from the thick "+
      "branches. Dirty %^WHITE%^windows %^GREEN%^are set high in the "+
      "walls above %^ORANGE%^wooden shelves %^GREEN%^that contain all "+
      "sorts of intriguing trinkets. A small ladder gives access to the "+
      "highest shelves. %^ORANGE%^Cupboards %^GREEN%^are tucked away "+
      "here and there, holding perfectly square compartments with "+
      "mismatched %^WHITE%^handles %^GREEN%^and %^WHITE%^knobs"+
      "%^GREEN%^. A small %^ORANGE%^desk %^GREEN%^sits back in a small "+
      "alcove and, given everything else in the room, you barely even "+
      "notice it. Strange %^BOLD%^%^BLACK%^lights %^RESET%^%^GREEN%^"+
      "hang from the ceiling, unabashedly white and bright. A "+
      "%^CYAN%^mesmerizing %^GREEN%^young woman sits quietly on a "+
      "stool in a corner of the room, watching you with wide, %^BOLD%^"+
      "%^BLACK%^dark %^RESET%^%^GREEN%^eyes.%^WHITE%^\n\n"+
      "Please use %^BOLD%^<help shop> %^RESET%^for information on how "+
      "to use this shop.%^RESET%^\n");
   set_smell("default","%^BOLD%^%^BLACK%^It smells like parchment and "+
      "ink.%^RESET%^");
   set_listen("default","%^ORANGE%^A %^RESET%^%^MAGENTA%^bird "+
      "%^ORANGE%^cheerily chirps from somewhere amongst the "+
      "tree's branches.%^RESET%^");
   set_items(([
      "steps" : "%^RESET%^%^CYAN%^The %^GREEN%^wooden steps "+
         "%^CYAN%^are wide and painted %^GREEN%^dark green%^CYAN%^, "+
         "flanked by short walls wide enough that someone could easily "+
         "use them as a sliding board.%^RESET%^",
      "cylinders" : "%^RESET%^%^CYAN%^The %^GREEN%^wooden steps "+
         "%^CYAN%^are wide and painted %^GREEN%^dark green%^CYAN%^, "+
         "flanked by short walls wide enough that someone could easily "+
         "use them as a sliding board.%^RESET%^",
      "tree" : "%^RESET%^%^CYAN%^The %^GREEN%^tree %^CYAN%^juts up "+
         "from the floorboards as if it's the most natural thing to "+
         "find inside of a room. The ceiling is not incredibly high, "+
         "but the tree manages to touch it. It's a squat tree with "+
         "%^BOLD%^%^GREEN%^bright green leaves%^RESET%^%^CYAN%^, and "+
         "an old, %^ORANGE%^fat trunk%^CYAN%^. %^BOLD%^G%^GREEN%^lo"+
         "%^BLUE%^w%^MAGENTA%^in%^GREEN%^g %^RESET%^%^CYAN%^round "+
         "fruits hang from its thick branches.%^RESET%^",
      "fruits" : "%^RESET%^%^CYAN%^The fruits most closely resemble "+
         "some sort of berry, but you're not entirely sure. And do "+
         "you really want to consume something that glows? They come "+
         "in every color of the %^BOLD%^%^RED%^r%^ORANGE%^a%^GREEN%^"+
         "i%^BLUE%^n%^CYAN%^b%^MAGENTA%^o%^GREEN%^w%^RESET%^"+
         "%^CYAN%^.%^RESET%^",
      "windows" : "%^RESET%^%^CYAN%^The windows are so dusty very "+
         "little light manages to peek its way through.%^RESET%^",
      ({"shelves","trinkets"}) : "%^RESET%^%^CYAN%^The shelves have "+
         "compartments of all different shapes and sizes, and they are "+
         "very cluttered with an array of strange things - some quite "+
         "priceless, others obviously junk. One thing is for certain..."+
         "there is a LOT of it.%^RESET%^",
      "ladder" : "%^RESET%^%^CYAN%^A short ladder helps to reach the "+
         "upper shelves.%^RESET%^",
      "cupboards" : "%^RESET%^%^CYAN%^Some short cupboards line the "+
         "walls, and others are free standing throughout the shop. "+
         "Each small, square compartment is labeled, some with familiar "+
         "sounding names, such as: Magic Missile, Conjure Elemental, "+
         "and so forth. Others have more foreign sounding spells "+
         "listed, and the rest aren't even in a language you recognize. "+
         "Each of the drawers features some sort of handle or knob, "+
         "although no two are similar. It adds a point of quirk to an "+
         "already quirky place.%^RESET%^",
      "desk" : "%^RESET%^%^CYAN%^The desk is tidy and almost empty "+
         "besides a stack of blank paper and an inkwell.%^RESET%^",
      "lights" : "%^RESET%^%^CYAN%^The lights are long, clear %^WHITE%^"+
         "cylinders %^CYAN%^encased in %^BOLD%^%^BLACK%^wrought iron "+
         "%^RESET%^%^CYAN%^that is shaped into pretty %^BOLD%^%^GREEN%^"+
         "ivy vines %^RESET%^%^CYAN%^and %^BOLD%^%^GREEN%^flowers"+
         "%^RESET%^%^CYAN%^. The bright white light shines through "+
         "the cutout sections of the metal, making strange %^BOLD%^"+
         "%^BLACK%^patterns %^RESET%^%^CYAN%^and %^BOLD%^%^BLACK%^"+
         "shadows %^RESET%^%^CYAN%^dance around the room.%^RESET%^",
   ]));
   set_exits(([
      "west" : ROOMS"mage2ndlanding",
   ]));
}

void reset()
{
    ::reset();
    if (!present("alicia")) {
        find_object_or_load(MON "alicia")->move(TO);
    }
}
