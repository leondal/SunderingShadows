//chapel3.c - Path to the chapel.  Circe 8/16/04
#include <std.h>
#include "../lothwaite.h"
inherit PATHEXIT"chapel1";

void create(){
   ::create();
   set_exits(([
      "west" : PATHEXIT"chapel4",
      "northeast" : PATHEXIT"chapel2"
   ]));
   add_item("windows","%^YELLOW%^S%^GREEN%^t%^CYAN%^a%^BLUE%^i%^RESET%^%^MAGENTA%^n"+
         "%^YELLOW%^e%^GREEN%^d %^CYAN%^g%^BLUE%^l%^RESET%^%^MAGENTA%^a"+
         "%^YELLOW%^s%^GREEN%^s %^RESET%^%^ORANGE%^windows depict various "+
         "scenes of life in the firbolg valley, watched over by the "+
         "everpresent gods.");
   add_item("panel","The exquisite panel above the door is made of "+
      "beautiful %^YELLOW%^s%^GREEN%^t%^CYAN%^a%^BLUE%^i%^RESET%^%^MAGENTA%^n"+
      "%^YELLOW%^e%^GREEN%^d %^CYAN%^g%^BLUE%^l%^RESET%^%^MAGENTA%^a"+
      "%^YELLOW%^s%^GREEN%^s %^RESET%^shaped into a triangle that fills "+
      "the entire upper portion of the chapel front.  The panel "+
      "depicts a fanciful meeting of many of the deities the "+
      "firbolgs revere - an indistinct face peers forth from a "+
      "%^BOLD%^%^BLUE%^winding river %^RESET%^on the banks of which "+
      "reclines a dark-skinned man strumming a %^MAGENTA%^lyre %^RESET%^"+
      "beneath the limbs of the %^GREEN%^forest trees%^RESET%^.  A "+
      "feminine figure approaches through the trees, her %^ORANGE%^"+
      "bow %^RESET%^resting on her back as she walks beside a "+
      "stunning %^BOLD%^unicorn%^RESET%^.  The trees appear ruffled "+
      "by a %^CYAN%^wind %^RESET%^blown by a feminine figure drapped "+
      "in %^BOLD%^white linen %^RESET%^who hovers near the right corner "+
      "of the image.  A %^BOLD%^%^RED%^ribbon of red mist %^RESET%^"+
      "swirls around the picture, ending at a gorgeous woman in a "+
      "hooded %^BOLD%^%^BLUE%^blue %^RESET%^and %^BOLD%^silver "+
      "%^RESET%^cloak who stands serenely on the near side of the "+
      "river.  Competing sources of light brighten the sky - "+
      "the %^BOLD%^silvery radiance of the moon %^RESET%^shines from "+
      "a pair of %^BOLD%^%^BLACK%^dark feminine eyes %^RESET%^on the "+
      "left side, while the %^YELLOW%^brilliant light of the sun "+
      "%^RESET%^springs forth, seeming to radiate "+
      "outward from the image of the flawless man on the right.  "+
      "Strangely, a %^BOLD%^%^BLACK%^darkened, thin figure %^RESET%^"+
      "shrouded in a deeply hooded cloak stands just at the edge of "+
      "sight.");
   add_item("window","The exquisite panel above the door is made of "+
      "beautiful %^YELLOW%^s%^GREEN%^t%^CYAN%^a%^BLUE%^i%^RESET%^%^MAGENTA%^n"+
      "%^YELLOW%^e%^GREEN%^d %^CYAN%^g%^BLUE%^l%^RESET%^%^MAGENTA%^a"+
      "%^YELLOW%^s%^GREEN%^s %^RESET%^shaped into a triangle that fills "+
      "the entire upper portion of the chapel front.  The panel "+
      "depicts a fanciful meeting of many of the deities the "+
      "firbolgs revere - an indistinct face peers forth from a "+
      "%^BOLD%^%^BLUE%^winding river %^RESET%^on the banks of which "+
      "reclines a dark-skinned man strumming a %^MAGENTA%^lyre %^RESET%^"+
      "beneath the limbs of the %^GREEN%^forest trees%^RESET%^.  A "+
      "feminine figure approaches through the trees, her %^ORANGE%^"+
      "bow %^RESET%^resting on her back as she walks beside a "+
      "stunning %^BOLD%^unicorn%^RESET%^.  The trees appear ruffled "+
      "by a %^CYAN%^wind %^RESET%^blown by a feminine figure drapped "+
      "in %^BOLD%^white linen %^RESET%^who hovers near the right corner "+
      "of the image.  A %^BOLD%^%^RED%^ribbon of red mist %^RESET%^"+
      "swirls around the picture, ending at a gorgeous woman in a "+
      "hooded %^BOLD%^%^BLUE%^blue %^RESET%^and %^BOLD%^silver "+
      "%^RESET%^cloak who stands serenely on the near side of the "+
      "river.  Competing sources of light brighten the sky - "+
      "the %^BOLD%^silvery radiance of the moon %^RESET%^shines from "+
      "a pair of %^BOLD%^%^BLACK%^dark feminine eyes %^RESET%^on the "+
      "left side, while the %^YELLOW%^brilliant light of the sun "+
      "%^RESET%^springs forth, seeming to radiate "+
      "outward from the image of the flawless man on the right.  "+
      "Strangely, a %^BOLD%^%^BLACK%^darkened, thin figure %^RESET%^"+
      "shrouded in a deeply hooded cloak stands just at the edge of "+
      "sight.");
   add_item("stained glass panel","The exquisite panel above the door is made of "+
      "beautiful %^YELLOW%^s%^GREEN%^t%^CYAN%^a%^BLUE%^i%^RESET%^%^MAGENTA%^n"+
      "%^YELLOW%^e%^GREEN%^d %^CYAN%^g%^BLUE%^l%^RESET%^%^MAGENTA%^a"+
      "%^YELLOW%^s%^GREEN%^s %^RESET%^shaped into a triangle that fills "+
      "the entire upper portion of the chapel front.  The panel "+
      "depicts a fanciful meeting of many of the deities the "+
      "firbolgs revere - an indistinct face peers forth from a "+
      "%^BOLD%^%^BLUE%^winding river %^RESET%^on the banks of which "+
      "reclines a dark-skinned man strumming a %^MAGENTA%^lyre %^RESET%^"+
      "beneath the limbs of the %^GREEN%^forest trees%^RESET%^.  A "+
      "feminine figure approaches through the trees, her %^ORANGE%^"+
      "bow %^RESET%^resting on her back as she walks beside a "+
      "stunning %^BOLD%^unicorn%^RESET%^.  The trees appear ruffled "+
      "by a %^CYAN%^wind %^RESET%^blown by a feminine figure drapped "+
      "in %^BOLD%^white linen %^RESET%^who hovers near the right corner "+
      "of the image.  A %^BOLD%^%^RED%^ribbon of red mist %^RESET%^"+
      "swirls around the picture, ending at a gorgeous woman in a "+
      "hooded %^BOLD%^%^BLUE%^blue %^RESET%^and %^BOLD%^silver "+
      "%^RESET%^cloak who stands serenely on the near side of the "+
      "river.  Competing sources of light brighten the sky - "+
      "the %^BOLD%^silvery radiance of the moon %^RESET%^shines from "+
      "a pair of %^BOLD%^%^BLACK%^dark feminine eyes %^RESET%^on the "+
      "left side, while the %^YELLOW%^brilliant light of the sun "+
      "%^RESET%^springs forth, seeming to radiate "+
      "outward from the image of the flawless man on the right.  "+
      "Strangely, a %^BOLD%^%^BLACK%^darkened, thin figure %^RESET%^"+
      "shrouded in a deeply hooded cloak stands just at the edge of "+
      "sight.");
   set_door("chapel door",PATHEXIT"chapel4","west",0);
   set_door_description("chapel door","The ornate chapel door has been "+
      "carved from imported oak wood that bears intricate scrollwork "+
      "along the edges.  The door rises to a point that seems to emphasize "+
      "the %^YELLOW%^s%^GREEN%^t%^CYAN%^a%^BLUE%^i%^RESET%^%^MAGENTA%^n"+
      "%^YELLOW%^e%^GREEN%^d %^CYAN%^g%^BLUE%^l%^RESET%^%^MAGENTA%^a"+
      "%^YELLOW%^s%^GREEN%^s %^RESET%^panel just above it.");
}