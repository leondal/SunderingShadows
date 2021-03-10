//inn_suite.c by ~Circe~ 12/26/15
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",3);
   set_name("Guest Suite of the Tropical Breeze Inn, Seneca");
   set_short("%^BOLD%^%^MAGENTA%^Guest Suite of the Tropical Breeze Inn, Seneca%^RESET%^");
   set_long("%^BOLD%^%^MAGENTA%^Guest Suite of the Tropical Breeze Inn, Seneca%^RESET%^\n"+
      "%^RESET%^%^ORANGE%^This spacious room is defined by simple elegance "
      "crafted from n%^RESET%^a%^ORANGE%^tu%^RED%^r%^ORANGE%^a%^RESET%^l %^ORANGE%^"
      "st%^RESET%^o%^ORANGE%^ne and lush fabrics. The western wall is exposed stone set "
      "with tall, arched %^CYAN%^windows %^ORANGE%^opening onto the %^BOLD%^%^BLUE%^Attayan "
      "sky%^RESET%^%^ORANGE%^. Wrought iron %^BOLD%^%^BLACK%^window boxes %^RESET%^%^ORANGE%^bursting "
      "with %^RED%^c%^ORANGE%^o%^YELLOW%^l%^GREEN%^o%^RESET%^%^GREEN%^r%^CYAN%^f%^BOLD%^u"
      "%^BLUE%^l %^MAGENTA%^f%^RESET%^%^MAGENTA%^l%^CYAN%^o%^GREEN%^w%^ORANGE%^e%^RED%^r"
      "%^BOLD%^s %^RESET%^%^ORANGE%^brighten the room, their sweet fragrance mingling "
      "with the scent of the ocean. A framework of %^BOLD%^%^BLACK%^dark wood %^RESET%^%^ORANGE%^is "
      "suspended above the bed, partially obscured by %^GREEN%^ivy%^ORANGE%^ and "
      "delicate teardrop-shaped %^CYAN%^g%^GREEN%^l%^YELLOW%^o%^WHITE%^b%^CYAN%^e%^RESET%^"
      "%^CYAN%^s %^ORANGE%^emitting soft light. Soft cotton sheets the color of a "
      "%^CYAN%^clear sky %^ORANGE%^make up the bed, topped with a coordinating duvet. "
      "The eastern wall features a carved %^BOLD%^%^BLACK%^wardrobe%^RESET%^%^ORANGE%^ "
      "beside a decorative %^RESET%^screen %^ORANGE%^shielding a %^BOLD%^%^BLACK%^"
      "washstand%^RESET%^%^ORANGE%^. Two overstuffed %^BOLD%^%^BLACK%^leather chairs "
      "%^RESET%^%^ORANGE%^are arranged to either side of a small %^RESET%^coffee table"
      "%^ORANGE%^ in the southwestern corner of the room, providing a comfortable place "
      "to relax. The exquisitely %^CYAN%^w%^RESET%^o%^BLUE%^v%^CYAN%^e%^RESET%^n %^CYAN%^"
      "r%^BLUE%^u%^CYAN%^g%^ORANGE%^ stretches from the entrance all the way to the clear "
      "%^CYAN%^glass doors%^ORANGE%^ that open onto a %^RESET%^balcony %^ORANGE%^in the "
      "southern wall. Dark %^BLUE%^blue curtains%^ORANGE%^ designed to mimic the hue of "
      "the %^BLUE%^de%^CYAN%^e%^BLUE%^p o%^CYAN%^c%^BLUE%^ean %^ORANGE%^are gathered on "
      "either side of the glass, offering the occupants a means to ensure their privacy, "
      "though that hardly seems necessary this high up.%^RESET%^\n");
   set_smell("default","The light fragrance of the sea mingles with the fresh scent of flowers.");
   set_listen("default","The silence is broken by a gentle breeze and tinkling of windchimes.");
   set_items(([
      ({"floor","stone"}) : "The stone floor is made up of "+
         "locally quarried %^BOLD%^st%^RESET%^o%^BOLD%^ne %^RESET%^"+
         "fashioned into irregularly shaped tiles.  A faintly "+
         "%^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^WHITE%^e"+
         "%^RESET%^n grout fits the tiles together, making the "+
         "floor smooth. A thick rug stretches across the stone, providing cushion for weary feet.",
      ({"globe","globes","teardrop globes","teardrop-shaped globes"}) : "Seemingly miniature "
         "versions of the globes that light most of the inn, these teardrop-shaped constructions "
         "of glass are delicate and contain a soft white light. Some twinkle blue or yellow, "
         "adding to the magical appearance of the ivy they decorate.",
      ({"ivy","framework","frame","wooden frame"}) : "Suspended over the bed is a framework "
         "of dark wood that brings the vaulted ceiling closer, providing a sense of intimacy. "
         "Ivy vines have been trained around the exposed wood and lend a touch of the "
         "outdoors to the suite. Nestled within the leaves are countless teardrop globes filled with a soft glow.",
      ({"wall","walls"}) : "Most of the walls are covered with the cream-colored "
         "stucco common in the inn, but the western wall is crafted from exposed "
         "stone while the southern wall is dominated by glass doors.",
      ({"western wall","window","windows"}) : "The western wall features a patchwork of natural "
         "stone in shades of cream, tan, and rust. The decorative arrangement is "
         "broken up by the wide arching windows opening out onto the Attayan sky.",
      ({"window box","window boxes","flower","flowers","colorful flowers","boxes"}) : "The "
         "windows in the western wall support wrought iron %^BOLD%^%^BLACK%^window boxes "
         "%^RESET%^much like those that grace the streetlights. Each box is filled with %^BOLD%^"
         "coir fibers %^RESET%^and an astonishing collection of flowers: brilliant "
         "%^ORANGE%^orange anthurium%^RESET%^, "
         "%^BOLD%^%^RED%^tor%^WHITE%^c%^RED%^h gin%^WHITE%^g%^RED%^er%^RESET%^, "
         "%^YELLOW%^birds of paradise%^RESET%^, and pristine %^BOLD%^"
         "calla lilies %^RESET%^are sprinkled among a field of %^BOLD%^"
         "%^MAGENTA%^p%^WHITE%^ink-%^MAGENTA%^t%^WHITE%^ipped "
         "%^MAGENTA%^p%^WHITE%^lumeria%^RESET%^, luminous %^BOLD%^%^BLUE%^b"
         "%^RESET%^%^CYAN%^l%^BOLD%^%^BLUE%^u%^RESET%^%^CYAN%^e %^BOLD%^"
         "%^BLUE%^o%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^c%^RESET%^%^CYAN%^h"
         "%^BOLD%^%^BLUE%^i%^RESET%^%^CYAN%^d%^RESET%^, "
         "and sprawling %^MAGENTA%^purple bougainvillea%^RESET%^.",
      ({"sheets","duvet","bed"}) : "The bed is fashioned from a dark wood that "
         "glows softly in the light from the globes. The sheets are a faint blue "
         "of the softest cotton imaginable - perfect for the heat of Seneca. "
         "The duvet is a darker shade blue quilted with abstract swirling designs.",
      "wardrobe" : "The wardrobe is carved with simple, clean lines that make it "
         "unobtrusive. A guest could use it to store clothing, if desired.",
      ({"screen","wash stand","stand"}) : "%^RESET%^%^ORANGE%^A silk screen painting "
         "with simply %^YELLOW%^flowers %^RESET%^%^ORANGE%^ shields the northwestern "
         "corner of the room, offering some privacy for changing or using the wash basin. The wash stand is "
         "well-crafted and supports a small mirror for guests to use. A %^RESET%^porcelain "
         "pitcher %^ORANGE%^and matching %^RESET%^basin%^ORANGE%^ stand ready for "
         "use, alongside several small cakes of floral-scented %^YELLOW%^soap"
         "%^RESET%^%^ORANGE%^. A %^CYAN%^blue towel%^ORANGE%^ hangs from a slender "
         "rod, waiting for guests to use after they %^CYAN%^wash%^ORANGE%^ in "
         "the basin.%^RESET%^",
      ({"chair","chairs","leather chair","leather chairs"}) : "%^BOLD%^%^BLACK%^The "
         "chairs are oversized and overstuffed, nearly wide enough for two humans to sit together. "
         "Each is covered in brown leather so dark it is nearly black. Small throw "
         "pillows of %^RESET%^cream%^BOLD%^%^BLACK%^, %^RESET%^%^CYAN%^blue%^BOLD%^"
         "%^BLACK%^, and %^YELLOW%^yellow %^BLACK%^rest in each chair.%^RESET%^",
      ({"table","coffee table"}) : "A low, oval wooden table sits between the chairs, "
         "offering a place for guests to rest their drinks. The legs are carved in "
         "graceful curves, contrasting the straight lines in much of the room.",
      ({"rug","woven rug"}) : "The rug is woven in undulating shades of blue and white, "
         "reminiscent of the sea. The thick fabric is soft on the feet and stretches "
         "nearly from wall to wall.",
      ({"curtain","curtains","blue curtains"}) : "%^RESET%^%^BLUE%^To each side of the "
         "windows and the glass doors are %^BOLD%^%^BLACK%^iron rods %^RESET%^%^BLUE%^"
         "supporting thick blue curtains. These can be drawn to block out the light and "
         "shield the occupants from prying eyes.%^RESET%^",
   ]));
   set_exits(([
      "north" : ROOMS"inn_stairs3",
      "south" : ROOMS"inn_balcony"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/inn_stairs3","north",0);
   set_door("glass doors","/d/attaya/newseneca/rooms/inn_balcony","south",0);
   set_door_description("glass doors","%^RESET%^%^ORANGE%^A simple wooden frame polished "
      "to a glossy sheen supports the double doors that open onto the balcony. The "
      "%^CYAN%^glass %^ORANGE%^is nearly flawless, providing a clear view of the city sky.%^RESET%^");
}

void init(){
   ::init();
   add_action("brighten_em","brighten");
   add_action("darken_em","darken");
   add_action("wash_em","wash");
}

int wash_em(string str){
   if(!str){
      tell_object(TP,"You might want to try washing in the basin.");
      return 1;
   }
   if(str == "in basin" || str == "in the basin"){
      tell_object(TP,"Using the soap and lukewarm water, you scrub your "+
         "face and wash your hands, then rinse throroughly.  You dry "+
         "your hands and face on one of the warm towels on the shelf.  "+
         "Ahh...much better.  It feels good to get rid of that grime.");
      tell_room(ETP,""+TPQCN+" washes "+TP->QP+" face and hands in "+
         "the basin.",TP);
      TP->set("long");
      return 1;
   }
   tell_object(TP,"You want to wash where??");
   return 1;
}

int brighten_em(string str){
   if(!str){
      tell_object(TP,"What are you trying to brighten? Maybe the lights?");
      return 1;
   }
   if(str == "light" || str == "lights" || str == "room" || str == "globes"){
      if((int)TO->query_property("light") > 5){
         tell_object(TP,"The globes are already at their brightest.");
         return 1;
      }
      tell_object(TP,"%^YELLOW%^As you concentrate on the globes, they seem to respond to your will, glowing a little brighter.%^RESET%^");
      tell_room(TO,"%^YELLOW%^The globes glow a little brighter, lightening the room.%^RESET%^",TP);
      set_property("light",1);
      return 1;
   }
   else return 0;
}

int darken_em(string str){
   if(!str){
      tell_object(TP,"What are you trying to darken? Maybe the lights?");
      return 1;
   }
   if(str == "light" || str == "lights" || str == "room" || str == "globes"){
      if((int)TO->query_property("light") < 0){ 
         tell_object(TP,"The globes are already at their darkest.");
         return 1;
      }
      tell_object(TP,"%^BOLD%^%^BLACK%^As you concentrate on the globes, they seem to respond to your will and dim.%^RESET%^");
      tell_room(TO,"%^BOLD%^%^BLACK%^The globes dim, darkening the room.%^RESET%^",TP);
      set_property("light",-1);
      return 1;
   }
   else return 0;
}