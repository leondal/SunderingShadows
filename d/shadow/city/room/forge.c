//Octothorpe (6/4/16)
//Shadow, Weaponsmith and Armorsmith forge
//Borrowed from /d/shadow/city/rooms/weap_forge.c

#include <std.h>
#include "../defs.h"

inherit ROOM;

void create()
{
   ::create();
   set_indoors(1);
   set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("smithy",1); 
   set_name("Forge");
   set_short("Forge");
   /*set_long("%^BOLD%^%^BLACK%^Forge%^RESET%^\n"+
      "This room has thick stone walls, %^BOLD%^%^BLACK%^blackened "+
      "with soot %^RESET%^from the nearly perpetual fire. The northeast "+
      "corner has a wall about three foot high across it that encloses "+
      "a fire pit. Several anvils sit about the room, along with barrels "+
      "of dirty water used for quenching the metals, various tools, and "+
      "of course sharpening stones for the edged weapons. You sweat "+
      "profusely from the %^BOLD%^%^RED%^heat of the forging fire "+
      "%^RESET%^that is kept roaring.\n");
   set_smell("default", "Smoke from the fire irritates your nostrils.");
   set_listen("default", "The coals in the fire pop and crackle.");*/
   set_long("%^RESET%^%^WHITE%^You find %^ORANGE%^yourself %^WHITE%^in "+
      "the %^YELLOW%^grand %^BLACK%^sm%^WHITE%^i%^BLACK%^t%^WHITE%^h"+
      "%^BLACK%^y %^RESET%^of %^BOLD%^%^BLACK%^Shadow%^RESET%^. This "+
      "is one of the %^YELLOW%^great %^RED%^f%^RESET%^%^RED%^o%^BOLD%^rg"+
      "%^RESET%^%^RED%^e%^BOLD%^s %^RESET%^of the %^BOLD%^%^GREEN%^realm "+
      "%^RESET%^and it is clear that the %^BOLD%^%^BLACK%^master smith "+
      "%^RESET%^here runs his shop with %^BOLD%^%^MAGENTA%^passion "+
      "%^RESET%^and %^BOLD%^%^CYAN%^discipline%^RESET%^. You see "+
      "several %^BOLD%^young %^ORANGE%^boys %^RESET%^running around, "+
      "dragging %^BOLD%^%^BLUE%^water %^RESET%^in barrels, and manning "+
      "2 %^BOLD%^%^BLACK%^g%^RESET%^i%^BOLD%^%^BLACK%^g%^RESET%^"+
      "a%^BOLD%^%^BLACK%^n%^RESET%^t%^BOLD%^%^BLACK%^ic "+
      "b%^CYAN%^e%^BLACK%^ll%^CYAN%^o%^BLACK%^ws%^RESET%^. At the "+
      "center of the room you can see the big %^BOLD%^%^RED%^f%^RESET%^"+
      "%^RED%^o%^BOLD%^rg%^RESET%^%^RED%^e%^WHITE%^, with %^BOLD%^%^RED%^"+
      "f%^RESET%^%^RED%^i%^BOLD%^r%^RESET%^%^RED%^e %^WHITE%^as "+
      "%^BOLD%^%^RED%^h%^WHITE%^o%^RED%^t %^RESET%^as %^BOLD%^%^RED%^"+
      "h%^RESET%^%^RED%^e%^BOLD%^ll %^RESET%^itself. The %^BOLD%^%^RED%^"+
      "f%^RESET%^%^RED%^o%^BOLD%^rg%^RESET%^%^RED%^e %^WHITE%^has been "+
      "built in massive %^BOLD%^blocks %^RESET%^of %^BOLD%^%^BLACK%^"+
      "stone%^RESET%^, and is open in the %^CYAN%^front %^WHITE%^and "+
      "a huge %^ORANGE%^chimney %^WHITE%^at the top to let out the "+
      "s%^BOLD%^%^BLACK%^m%^RESET%^o%^BOLD%^%^BLACK%^k%^RESET%^e. "+
      "Several sized %^ORANGE%^a%^BOLD%^n%^RESET%^%^ORANGE%^v%^BOLD%^"+
      "i%^RESET%^%^ORANGE%^l%^BOLD%^s %^RESET%^are placed near the "+
      "%^BOLD%^%^RED%^f%^RESET%^%^RED%^o%^BOLD%^rg%^RESET%^%^RED%^e"+
      "%^WHITE%^, and with %^BOLD%^%^BLACK%^sm%^CYAN%^i%^BLACK%^th"+
      "%^CYAN%^i%^BLACK%^ng %^RESET%^tools, neatly %^ORANGE%^arranged "+
      "%^WHITE%^around each %^ORANGE%^a%^BOLD%^n%^RESET%^%^ORANGE%^v"+
      "%^BOLD%^i%^RESET%^%^ORANGE%^l%^WHITE%^. %^BOLD%^%^BLACK%^Tongs"+
      "%^RESET%^, %^BOLD%^hammers%^RESET%^, %^CYAN%^chisels %^WHITE%^and "+
      "%^GREEN%^specialized %^BOLD%^%^BLACK%^tools %^RESET%^are never "+
      "far from a %^BOLD%^%^BLACK%^sm%^CYAN%^i%^BLACK%^th %^RESET%^when "+
      "he is working the %^BOLD%^%^RED%^h%^WHITE%^o%^RED%^t %^BLACK%^m"+
      "%^WHITE%^e%^BLACK%^t%^WHITE%^a%^BLACK%^l%^RESET%^.");
   set_smell("default","%^CYAN%^You can smell %^BOLD%^%^BLACK%^b%^RED%^u"+
      "%^BLACK%^r%^RED%^n%^BLACK%^e%^RED%^d %^BLACK%^c%^RESET%^o%^BOLD%^"+
      "%^BLACK%^al%^RESET%^%^CYAN%^, %^BOLD%^%^BLACK%^h%^RESET%^%^RED%^e"+
      "%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^e%^RESET%^"+
      "%^RED%^d %^BOLD%^%^BLACK%^m%^WHITE%^e%^BLACK%^t%^WHITE%^a%^BLACK%^"+
      "l%^RESET%^%^CYAN%^, and days old %^ORANGE%^sweat%^CYAN%^.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLACK%^You can hear the %^CYAN%^"+
      "banging %^BLACK%^of a %^RESET%^%^ORANGE%^hammer %^BOLD%^%^BLACK%^"+
      "against m%^WHITE%^e%^BLACK%^t%^WHITE%^a%^BLACK%^l, and the "+
      "%^RESET%^large %^BOLD%^%^BLACK%^b%^CYAN%^e%^BLACK%^ll%^CYAN%^o"+
      "%^BLACK%^ws bl%^WHITE%^o%^BLACK%^w%^WHITE%^i%^BLACK%^ng %^CYAN%^"+
      "air %^BLACK%^into the %^RED%^f%^RESET%^%^RED%^i%^BOLD%^r%^RESET%^"+
      "%^RED%^e%^RESET%^.");
   set_exits(([
      "southwest" : ROOMS"armor",
      "southeast" : ROOMS"weapon",
   ]));
   set_items(([
      ({"anvil", "anvils"}): "They are large blocks of metal or stone "+
         "in various shapes to form the metal over.",
      ({"tools", "stones"}): "Small and large hammers, piercing tools, "+
         "vises to clamp the metal in for bending, sharpening stones, "+
         "and other things you probably don't know the names of or what "+
         "they do.",
      "fire" : "%^BOLD%^%^RED%^It seems to be fueled from both wood and "+
         "coal, with baffles used to pump extra air in at the base to "+
         "make it even hotter when needed.",
   ]));
}