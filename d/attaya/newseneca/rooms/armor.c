//~Circe~ for new Seneca 12/14/07
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create() {
   ::create();
   set_indoors(1);
   set_light(3);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("Armor Shop, Seneca");
   set_short("%^BOLD%^%^WHITE%^Armor Shop, Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Armor Shop, Seneca%^RESET%^\n"+
      "A smooth floor made of %^BOLD%^%^BLACK%^slate tiles "+
      "%^RESET%^in different %^BOLD%^%^BLACK%^s%^RESET%^h"+
      "%^BOLD%^a%^BLACK%^d%^RESET%^e%^BOLD%^s %^RESET%^of "+
      "%^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^a%^BLACK%^y%^RESET%^ "+
      "sets the tone for this neatly ordered shop.  All along "+
      "the eastern wall march rows of %^ORANGE%^wooden heads "+
      "%^RESET%^topped by %^BOLD%^helms %^RESET%^of all different "+
      "shapes and sizes.  Balancing this display is the counter "+
      "to the north where the shopkeeper conducts business.  "+
      "Beneath the counter's overhang runs a shelf displaying "+
      "pairs of %^BOLD%^%^BLACK%^gauntlets %^RESET%^ranging from "+
      "the most basic %^BOLD%^steel %^RESET%^to fantasical "+
      "%^RED%^clawed %^RESET%^creations meant to strike fear "+
      "into the hearts of one's opponents.  Resting on a "+
      "final %^ORANGE%^shelf %^RESET%^in the counter just above "+
      "the floor is a row of paired %^BOLD%^greaves%^RESET%^.  "+
      "%^ORANGE%^Wooden stands %^RESET%^spread around the shop "+
      "sport finished pieces of armor from simple %^BOLD%^"+
      "breastplates %^RESET%^to body-encasing %^BOLD%^%^BLACK%^"+
      "suits of armor%^RESET%^.  The showpiece of the shop, "+
      "though, are the %^BOLD%^display cases%^RESET%^ that "+
      "stand proudly in each of the two %^CYAN%^windows%^RESET%^.  "+
      "To the west, a doorway leads into the smithy.  No door "+
      "has been hung, helping the heat from the forge dissipate.\n");
   set_smell("default", "The acrid odor of burning metal fills the air.");
   set_listen("default", "The sound of ringing hammers and a "+
      "crackling fire floats in from the smithy.");
   set_exits(([
      "west" : ROOMS"smithy",
      "south" : ROOMS"viento58"
   ]));
   set_items(([
      ({"floor","tiles","slate tiles"}) : "%^BOLD%^%^BLACK%^The "+
         "floor of this shop is tiled in rectangular pieces of "+
         "%^RESET%^slate %^BOLD%^%^BLACK%^in varying s%^RESET%^h"+
         "%^BOLD%^a%^BLACK%^d%^RESET%^e%^BOLD%^s %^RESET%^of "+
         "%^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^a%^BLACK%^y.  It "+
         "is always kept neatly swept and gleaming, helping "+
         "give the shop a clean, welcoming atmosphere.%^RESET%^",
      ({"heads","wooden heads","helms","eastern wall"}) : "Protruding "+
         "from the eastern wall are neat %^ORANGE%^wooden blocks "+
         "%^RESET%^that are vaguely head-shaped.  Each sports a "+
         "different style of helm for sale, all of which show off "+
         "the armorsmith's skill.  One helmet features a %^BOLD%^"+
         "%^BLACK%^blackened helm %^RESET%^with curving %^BOLD%^"+
         "white horns %^RESET%^centered between a %^BOLD%^%^BLACK%^"+
         "topknot %^RESET%^of %^BOLD%^%^BLACK%^horsehair %^RESET%^that "+
         "runs down the wearer's back, while another has been fitted "+
         "with gleaming %^BOLD%^steel wings %^RESET%^tipped with "+
         "%^YELLOW%^gold %^RESET%^that give the wearer an %^CYAN%^"+
         "angelic %^RESET%^appearance.",
      "counter" : "The counter lining the northern wall features "+
         "two recessed shelves beneath the overhang.  The top "+
         "shelf holds paired gauntlets, while the bottom shelf holds "+
         "matched greaves.  From this counter, the shopkeeper "+
         "conducts all transactions.",
      "gauntlets" : "%^ORANGE%^The top shelf of the counter holds "+
         "a neat row of paired gauntlets.  You see several different "+
         "styles, from %^CYAN%^pure mithril %^ORANGE%^with elegant "+
         "curves and flowing engraving to thick, spiked %^BOLD%^"+
         "%^BLACK%^blackened affairs %^RESET%^%^ORANGE%^that would "+
         "surely tear apart an opponent.",
      "greaves" : "The lowest shelf set within the counter is just "+
         "above the tiled floor.  It holds pairs of polished greaves "+
         "in %^YELLOW%^m%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^t%^RESET%^"+
         "a%^WHITE%^l%^RESET%^%^CYAN%^s %^RESET%^of all kinds, all "+
         "lined and fitted with %^ORANGE%^leather straps%^RESET%^.",
      ({"stands","wooden stands","breastplates","suits of armor"}) : 
         "The %^ORANGE%^wooden stands %^RESET%^around the room have "+
         "been carved with the likenesses of humanoid forms.  You "+
         "see a %^BOLD%^mithril breastplate %^RESET%^fitted for a "+
         "dwarf here, an impressive set %^CYAN%^steel fullplate %^RESET%^"+
         "made for a human there, and various other bits of armor "+
         "spread around the room.",
      ({"cases","display cases"}) : "%^CYAN%^There are two display "+
         "cases, one in front of the eastern window and another "+
         "before the western window.%^RESET%^",
      ({"eastern window","eastern case","eastern display case"}) : 
         "%^CYAN%^The tall display case in the eastern end takes up "+
         "most of the huge window, encasing a breathtaking set of "+
         "%^BOLD%^%^WHITE%^mithril armor%^RESET%^%^CYAN%^.  "+
         "The armor has been polished to a high %^BOLD%^sheen%^RESET%^"+
         "%^CYAN%^, revealing intricate details of the exquisite "+
         "%^RESET%^s%^BOLD%^c%^RESET%^a%^BOLD%^l%^RESET%^e %^BOLD%^m"+
         "%^RESET%^a%^BOLD%^i%^RESET%^l %^CYAN%^chestpiece that "+
         "r%^BOLD%^i%^RESET%^%^CYAN%^p%^BOLD%^p%^RESET%^%^CYAN%^l"+
         "%^BOLD%^e%^RESET%^%^CYAN%^s in the light.  The scale shirt "+
         "extends past the wearer's hips, covering the %^RESET%^plated "+
         "leggings%^CYAN%^ topped with fluted greaves.  Impressive "+
         "%^BOLD%^%^WHITE%^shoulder guards %^RESET%^%^CYAN%^have been "+
         "fitted with fanciful expansive %^BOLD%^%^WHITE%^wings "+
         "%^RESET%^%^CYAN%^in glittering mithril, each wingtip seeming "+
         "a dagger.  Completing the suit of armor is a %^BOLD%^"+
         "%^WHITE%^winged helm %^RESET%^%^CYAN%^designed to reveal "+
         "the wearer's angelic countenance.%^RESET%^",
      ({"western window","western case","western display case"}) : 
         "%^RESET%^%^CYAN%^The western window is blocked by the huge "+
         "display case containing a fantastic suit of %^BOLD%^"+
         "%^BLACK%^blackened steel armor%^RESET%^%^CYAN%^.  "+
         "Thick %^BOLD%^%^BLACK%^black plates%^RESET%^%^CYAN%^ "+
         "overlap on the chestpiece, topped by smooth shoulder "+
         "guards that lead to %^BOLD%^%^BLACK%^spiked gauntlets "+
         "%^RESET%^%^CYAN%^made to shred flesh.  The elbow of each "+
         "arm has been fitted with a %^BOLD%^%^BLACK%^blackened dagger %^RESET%^"+
         "%^CYAN%^to pierce through armor, allowing the wearer to dominate "+
         "even in close combat.  Likewise, each knee has a pointed "+
         "%^BOLD%^%^BLACK%^spike %^RESET%^%^CYAN%^protruding upward, "+
         "mimicking the wicked boots.  The focal point of this armor "+
         "must be the helm, shaped as a %^BOLD%^%^BLACK%^crown "+
         "%^RESET%^%^CYAN%^that molds around the wearer's head, "+
         "sending thorns in all directions and leaving the wearer's "+
         "face just visible between the cheek guards that encase "+
         "him in steel.  A single %^BOLD%^%^BLACK%^spike%^RESET%^"+
         "%^CYAN%^, rather like a perversion of the unicorn's horn "+
         "rises from the front of the crown.%^RESET%^"
   ]));
   set_door("armory door","/d/attaya/newseneca/rooms/viento58","south",0,0);
   set_door_description("armory door","The wide wooden door in the "+
      "the southern wall leads back to Viento Lane.  It is often left "+
      "open to keep the room cool.");
}

void reset(){
   ::init();
   if(!present("armorsmith")){
      find_object_or_load(MON"armorer")->move(TO);
   }
}