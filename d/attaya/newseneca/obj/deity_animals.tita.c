//Deity-specific stuffed animals for the 
//Seneca Toy Shop.  Descriptions by Lurue, 
//Coded by Circe 11/25/07
//Updated to fit new gods by Titania 7/14/2020

#include <std.h>
#include "../seneca.h"

inherit DAEMON;

#define DEITIES ({"jarmila","kismet","krey","lordshadow","lysara","nilith"})

string MYDEITY,myanimal,myshort,mylong;

void create_animal(object obj){
   ::create();
   MYDEITY = DEITIES[random(sizeof(DEITIES))];
   switch(MYDEITY){
      case "krey": 
         myanimal = "hawk";
         myshort = "A stuffed animal in the shape of a %^RESET%^%^ORANGE%^hawk%^RESET%^";
         mylong = "%^RESET%^This %^ORANGE%^gold %^RESET%^and "+
            "%^BOLD%^%^WHITE%^white %^RESET%^hawk is made from "+
            "lightly brushed suede leather.  His eloquent body "+
            "is poised at rest with his %^YELLOW%^yellow claws "+
            "%^RESET%^wrapped neatly around a %^ORANGE%^dark brown "+
            "branch %^RESET%^of cotton fabric.  Though at rest, "+
            "he presents a watchful countenance, his %^YELLOW%^"+
            "yellow-topaz eyes %^RESET%^sewn in such a way as to "+
            "make him appear to be looking about himself, ever "+
            "watchful.  A %^ORANGE%^dark brown leather beak "+
            "%^RESET%^is highlighted with %^YELLOW%^yellow "+
            "stitching %^RESET%^along the top where it meets the "+
            "face, and a softer %^BOLD%^%^WHITE%^white suede "+
            "%^RESET%^has been used for his chest and belly.  "+
            "On his left side, just under the wing tip, a small "+
            "symbol has been neatly embroidered.";
         break;
      case "lordshadow":
         myanimal = "nightmare";
         myshort = "A stuffed animal in the shape of a %^BOLD%^"+
            "%^BLACK%^n%^RED%^i%^BLACK%^ghtm%^RED%^a%^BLACK%^re%^RESET%^";
         mylong = "%^BOLD%^%^BLACK%^Black as midnight and just as "+
            "fierce, this equine stands upon four powerful legs "+
            "bathed in %^RED%^crimson fire%^BLACK%^.  Like his "+
            "%^RESET%^%^RED%^dark red eyes%^BOLD%^%^BLACK%^, more "+
            "embroidered %^RED%^fire %^BLACK%^leaps about his muzzle "+
            "and contrasts the very dark black cotton that makes up "+
            "the rest of the body.  His mane and tail are crafted "+
            "of what appears to be real horse's hair, neatly "+
            "trimmed and carefully sewn into place to give the "+
            "equine a more authentic appearance then yarn might "+
            "portray.  Thick and muscular, he looks ready to run, "+
            "carrying his rider swiftly forward.  Sewn upon his "+
            "left rear flank an embroidered symbol can be seen.%^RESET%^";
         break;
      case "jarmila":
         myanimal = "phoenix";
         myshort = "A stuffed animal in the shape of a %^BOLD%^"+
            "%^RED%^ph%^YELLOW%^o%^RESET%^%^ORANGE%^e%^YELLOW%^"+
            "n%^RED%^ix%^RESET%^";
         mylong = "%^RESET%^%^RED%^Like the fires from which "+
            "he will transform, this stuffed animal is made from "+
            "%^ORANGE%^gold%^RED%^, %^YELLOW%^yellow%^RESET%^"+
            "%^RED%^, %^BOLD%^red %^RESET%^%^RED%^and burgundy "+
            "lame and gauze fabrics.  His body is supported on "+
            "two stocky legs of %^ORANGE%^b%^RED%^u%^ORANGE%^rnt "+
            "u%^RED%^m%^ORANGE%^ber %^RED%^and his long tail "+
            "flares out in a dazzling display of %^YELLOW%^"+
            "yellow%^RESET%^%^RED%^, %^ORANGE%^gold %^RED%^and "+
            "%^BOLD%^red %^RESET%^%^RED%^tail feathers.  A "+
            "%^YELLOW%^yellow beak%^RESET%^%^RED%^ and "+
            "%^ORANGE%^golden %^RED%^embroidered eyes are "+
            "framed by splashes of lame feathers in alternating "+
            "%^ORANGE%^gold %^RED%^and %^BOLD%^red%^RESET%^%^RED%^, "+
            "while his wings lift toward the sky in eloquent curves "+
            "of fiery %^YELLOW%^yellow%^RESET%^%^RED%^, burgundy "+
            "and %^BOLD%^crimson%^RESET%^%^RED%^.  On his left "+
            "side, under the upraised wing, an embroidered symbol "+
            "can be seen.  Certainly, this animal is a majestic "+
            "creature heralding %^YELLOW%^light %^RESET%^%^RED%^"+
            "and %^ORANGE%^life%^RESET%^%^RED%^.%^RESET%^";
         break;
      case "kismet":
         myanimal = "blue jay";
         myshort = "A stuffed animal in the shape of a %^BOLD%^"+
            "%^CYAN%^blue jay%^RESET%^";
         mylong = "%^RESET%^%^BLUE%^This small stuffed animal is "+
            "very well made from rich pieces of %^BOLD%^%^CYAN%^"+
            "blue %^RESET%^%^BLUE%^and %^BOLD%^%^WHITE%^white "+
            "%^RESET%^%^BLUE%^feather-patterned brocade.   Each "+
            "panel used to make this little %^BOLD%^%^CYAN%^bl"+
            "%^WHITE%^u%^CYAN%^e j%^WHITE%^a%^CYAN%^y %^RESET%^"+
            "%^BLUE%^is carefully placed so that all the feathers "+
            "of the pattern seem to go in one direction.  "+
            "%^YELLOW%^Golden eyes %^RESET%^%^BLUE%^are "+
            "embroidered on its head, and it has a %^BOLD%^%^BLACK%^black "+
            "beak %^RESET%^%^BLUE%^and set of %^BOLD%^%^BLACK%^"+
            "talons%^RESET%^%^BLUE%^.  On its left side at the "+
            "base of the wing, an embroidered symbol can be seen.%^RESET%^";
         break;
      case "lysara":
         myanimal = "owl";
         myshort = "A stuffed animal in the shape of an "+
            "%^BOLD%^%^WHITE%^owl%^RESET%^";
         mylong = "%^RESET%^Made from soft %^BOLD%^%^WHITE%^"+
            "white %^RESET%^and %^BOLD%^%^BLACK%^gray %^RESET%^"+
            "cotton, this owl seems almost ready to sleep "+
            "except for the way that the embroidered "+
            "%^ORANGE%^brown eyes %^RESET%^keep watch on its "+
            "surroundings.  The wide, flat, %^BOLD%^%^WHITE%^"+
            "white face %^RESET%^is framed with a %^BOLD%^%^BLACK%^"+
            "pale gray color %^RESET%^that covers the body, tail, "+
            "and outside of the wings.  The underside of the wings "+
            "and the belly are made of similar %^BOLD%^%^WHITE%^"+
            "white cotton %^RESET%^as the face while the two feet "+
            "are sewn from %^ORANGE%^brown%^RESET%^ cotton.  Under "+
            "the left wing, near where the tail starts, a small "+
            "embroidered symbol can be seen.";
         break;
      case "nilith":
         myanimal = "raven";
         myshort = "A stuffed animal in the shape of a "+
            "%^BOLD%^%^BLACK%^raven%^RESET%^";
         mylong = "%^RESET%^%^MAGENTA%^Shaped from %^BOLD%^"+
            "%^BLACK%^black velvet panels%^RESET%^%^MAGENTA%^, "+
            "this raven is as startlingly beautiful as it is "+
            "frighteningly fierce.  Carefully sewn to look "+
            "like every feather is in place, the bird's body "+
            "%^BOLD%^%^BLACK%^gl%^RESET%^%^MAGENTA%^i%^CYAN%^m"+
            "%^BOLD%^%^BLACK%^m%^RESET%^%^MAGENTA%^e%^BOLD%^"+
            "%^BLACK%^rs %^RESET%^%^MAGENTA%^with a dark luster "+
            "from its %^BOLD%^%^BLACK%^black leather beak "+
            "%^RESET%^%^MAGENTA%^to the embroidered symbol "+
            "just below its left wing tip.  Sharp looking "+
            "%^BOLD%^%^BLACK%^talons%^RESET%^%^MAGENTA%^, "+
            "fitted with metal wire and wrapped in inky black "+
            "leather, keep the bird upright.  Its head is tilted "+
            "just a little as though watching you with its dark, "+
            "%^BOLD%^%^BLACK%^depthless%^RESET%^%^MAGENTA%^ eyes.%^RESET%^";
         break;
      default :      myanimal = "bug";
                     MYDEITY = "kismet"; //just so read won't bug
                     myshort = "Oh no! You found a bug!";
                     mylong = "This should have been a deity-specific "+
                        "stuffed animal.  Please send a bug report "+
                        "so Circe can fix it.";
                     break;
   }
   obj->set_value(285);
   obj->set_cointype("gold");
   obj->set_weight(1);
   obj->set_name("stuffed animal");
   obj->set_id(({"animal","stuffed animal",""+MYDEITY+" animal",""+MYDEITY+" stuffed animal",""+myanimal+"","stuffed "+myanimal+"","deity stuffed animal"}));
   obj->set_short(""+myshort+"");
   obj->set_long(""+mylong+"  %^BOLD%^Something about the cute little "+
      "stuffed animal makes you just want to %^RED%^<%^WHITE%^"+
      "squeeze%^RED%^> %^WHITE%^it!%^RESET%^");
   obj->set_property("deity",""+MYDEITY+"");
}