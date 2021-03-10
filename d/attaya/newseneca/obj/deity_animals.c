//Deity-specific stuffed animals for the 
//Seneca Toy Shop.  Descriptions by Lurue, 
//Coded by Circe 11/25/07

#include <std.h>
#include "../seneca.h"

inherit DAEMON;

#define DEITIES ({"akadi","anhur","auppenser","auril","bane","beshaba","cyric","grumbar","helm","istishia","kelemvor","kossuth", "lathander","malar","mask","mielikki","mystra","oghma","selune","shar","shaundakul","sune","talos","tempus","torm","tymora","tyr"})

string MYDEITY,myanimal,myshort,mylong;

void create_animal(object obj){
   ::create();
   MYDEITY = DEITIES[random(sizeof(DEITIES))];
   switch(MYDEITY){
      case "akadi" : 
         myanimal = "crane";
         myshort = "A stuffed animal in the shape of a %^BOLD%^%^WHITE%^crane%^RESET%^";
         mylong = "%^RESET%^%^CYAN%^Graceful as the sky "+
            "it soars through, this %^BOLD%^%^BLACK%^g"+
            "%^RESET%^%^CYAN%^r%^BLUE%^a%^BOLD%^%^BLACK%^"+
            "y-b%^RESET%^%^CYAN%^l%^BLUE%^u%^BOLD%^%^BLACK%^"+
            "e %^RESET%^%^CYAN%^stuffed animal holds her "+
            "wings aloft and her long %^BOLD%^%^BLACK%^gray "+
            "cotton legs %^RESET%^%^CYAN%^close to her "+
            "body as she hangs in mid-flight.  %^BOLD%^J"+
            "%^GREEN%^e%^WHITE%^w%^GREEN%^e%^CYAN%^l"+
            "%^RESET%^ %^CYAN%^toned, embroidered %^BLUE%^"+
            "blue eyes %^CYAN%^watch the horizon and her "+
            "long %^ORANGE%^orange beak %^CYAN%^points "+
            "the way to her destination.  A widely flared "+
            "tail, carefully sewn to look like several "+
            "long feathers, helps her navigate as she "+
            "flies the sky with complete freedom.  Upon "+
            "her left side, just under the wing, an "+
            "embroidered symbol can be seen.%^RESET%^";
         break;
      case "anhur" : 
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
      case "auppenser" : 
         myanimal = "couatl";
         myshort = "A stuffed animal in the shape of a %^BOLD%^"+
            "%^GREEN%^c%^RESET%^%^CYAN%^o%^BOLD%^%^GREEN%^u"+
            "%^BLUE%^a%^RED%^t%^BOLD%^%^GREEN%^l%^RESET%^";
         mylong = "%^GREEN%^This stuffed animal's body is made from "+
            "a deep %^CYAN%^g%^GREEN%^r%^BLUE%^e%^GREEN%^e%^CYAN%^"+
            "ni%^GREEN%^s%^BLUE%^h%^CYAN%^-b%^GREEN%^l%^BLUE%^u"+
            "%^CYAN%^e %^GREEN%^leather that has been pressed to "+
            "look like scales.  About three feet long from the top "+
            "of its head to the tip of it's tail it is quite "+
            "impressive with detail.  %^YELLOW%^Golden embroidered "+
            "eyes %^RESET%^%^GREEN%^and shaded scales being only part "+
            "of what makes the toy magnificent.  Sprouting from the "+
            "back of this snake like creature are two %^YELLOW%^golden "+
            "wings%^RESET%^%^GREEN%^, fixed with thin strips of metal "+
            "within their stuffing that keeps them arched upward.  "+
            "Additional thin strips of metal wire have been sewn "+
            "within the tail of the snake allowing it to be coiled "+
            "about and made to stand upward.  Toward the end of the "+
            "tail on the left side, a small embroidered symbol can be "+
            "seen.%^RESET%^";
         break;
      case "auril":
         myanimal = "snow leopard";
         myshort = "A stuffed animal in the shape of a %^BOLD%^"+
            "%^WHITE%^sn%^BLACK%^o%^WHITE%^w l%^BLACK%^e%^WHITE%^"+
            "op%^BLACK%^a%^WHITE%^rd%^RESET%^";
         mylong = "%^BOLD%^%^WHITE%^Slinking his way through the ice, "+
            "this white and %^BLACK%^gray %^WHITE%^wool snow leopard "+
            "looks ready for the %^CYAN%^coldest %^WHITE%^weather.  "+
            "His thick coat has been dyed white with a molting of light "+
            "%^BLACK%^gray %^WHITE%^coloring that is almost unseen.  "+
            "Dark %^BLACK%^gray eyes %^WHITE%^are embroidered on his "+
            "face and a small %^BLACK%^black nose %^WHITE%^tips his "+
            "muzzle.  White ears laid close to his head and tail sewn "+
            "in an alert position, he surveys his %^CYAN%^snowy "+
            "%^WHITE%^domain with care.  On his left rear flank a "+
            "small embroidered symbol can be seen.%^RESET%^";
         break;
      case "bane":
         myanimal = "hellhound";
         myshort = "A stuffed animal in the shape of a %^RESET%^"+
            "%^RED%^h%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^llh%^BOLD%^"+
            "%^BLACK%^o%^RESET%^%^RED%^und%^RESET%^";
         mylong = "%^BOLD%^%^BLACK%^This stuffed animal is truly "+
            "frightening.  Made of black and red suede, the body is "+
            "soft and textured, almost coarse to the touch.  Sleek "+
            "and eloquent, the hellhound's body is the %^RED%^bright "+
            "red of fire %^BLACK%^chased through with swaths of black "+
            "along its flanks and mussel.  %^RED%^Ember red eyes "+
            "%^BLACK%^almost glow where they've been embroidered, and "+
            "the sewn %^RED%^fl%^YELLOW%^a%^RESET%^%^ORANGE%^m%^BOLD%^"+
            "%^RED%^es %^BLACK%^that rise from the toy's feet glitter "+
            "with %^YELLOW%^gold %^BLACK%^and %^RED%^red %^BLACK%^"+
            "metallic threads.  The mouth of this creature is open, "+
            "and %^WHITE%^white canines %^BLACK%^can be seen, ready "+
            "to rip apart anything that defies it.  On its left rear "+
            "flank, a symbol has been embroidered. %^RESET%^";
         break;
      case "beshaba":
         myanimal = "rat";
         myshort = "A stuffed animal in the shape of a %^BOLD%^%^BLACK%^rat%^RESET%^";
         mylong = "%^BOLD%^%^BLACK%^Short, squat, and black is what "+
            "defines this little stuffed animal.  Almost cute, its "+
            "long %^RESET%^gray tail %^BOLD%^%^BLACK%^is made from a "+
            "deep %^RESET%^gray leather %^BOLD%^%^BLACK%^that has been "+
            "roughed to give it texture.  The body is make from a "+
            "thickly brushed wool that gives it a nubbly texture.  "+
            "Dyed black, you almost miss the beady black eyes but "+
            "for the %^RESET%^gl%^BOLD%^%^BLACK%^i%^WHITE%^t%^BLACK%^"+
            "t%^RESET%^ery %^BOLD%^%^BLACK%^shine of the metallic "+
            "black thread that was used to embroider them.  Circular "+
            "ears, one of which appears to have a bite taken out of "+
            "it, sharp looking %^RESET%^gray leather claws, %^BOLD%^"+
            "%^BLACK%^and long horse-tail strand whiskers finish "+
            "out this little guy's appearance.  On the left rear "+
            "haunch an embroidered symbol can be seen.%^RESET%^";
         break;
      case "cyric":
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
      case "grumbar":
         myanimal = "mole";
         myshort = "A stuffed animal in the shape of a "+
            "%^RESET%^%^ORANGE%^mole%^RESET%^";
         mylong = "%^BOLD%^%^BLACK%^Created from moleskin leather "+
            "and stuffed with cotton, this little %^RESET%^"+
            "%^ORANGE%^gr%^RESET%^a%^ORANGE%^y%^RESET%^-%^ORANGE%^"+
            "br%^RESET%^o%^ORANGE%^wn %^BOLD%^%^BLACK%^mole keeps "+
            "his eyes tightly shut as the %^MAGENTA%^pink nose "+
            "%^BLACK%^scents the air.  Long %^RESET%^%^ORANGE%^"+
            "leather claws %^BOLD%^%^BLACK%^show the way that he "+
            "might dig through the earth on his way to seek a meal "+
            "or find his home, while his short %^RESET%^gray-furred "+
            "tail %^BOLD%^%^BLACK%^curls out behind him.  On his "+
            "left rear flank a small symbol has been embroidered "+
            "with the same style as his tightly closed eyes.%^RESET%^";
         break;
      case "helm":
         myanimal = "watch dog";
         myshort = "A stuffed animal in the shape of a %^RESET%^"+
            "%^ORANGE%^w%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^t"+
            "%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^h d%^BOLD%^"+
            "%^BLACK%^o%^RESET%^%^ORANGE%^g%^RESET%^";
         mylong = "%^RESET%^%^ORANGE%^This large canine is made "+
            "of soft brown wool and stands in an alert and dominant "+
            "position.  With %^BOLD%^%^BLACK%^gray muzzle%^RESET%^"+
            "%^ORANGE%^ raised and %^BOLD%^%^BLACK%^gray felt ears "+
            "%^RESET%^%^ORANGE%^cocked forward, he surveys his domain "+
            "with bright %^YELLOW%^golden eyes %^RESET%^%^ORANGE%^and "+
            "an almost tangible sense of attention.  Like a mastiff, "+
            "his nose is short and wrinkled, his body wide and thick, "+
            "and his legs powerful and sturdy.  His tail is thin and "+
            "whippet-like, curved down against his body as he stands "+
            "vigilant.  Upon his left rear flank a small symbol "+
            "appears to have been embroidered.%^RESET%^";
         break;
      case "istishia":
         myanimal = "dolphin";
         myshort = "A stuffed animal in the shape of a %^RESET%^"+
            "%^CYAN%^dolphin%^RESET%^";
         mylong = "%^BOLD%^%^CYAN%^Crafted from %^BLUE%^blue "+
            "%^CYAN%^and %^WHITE%^white %^CYAN%^cotton, this small "+
            "stuffed animal is posed mid-swim with his long tail "+
            "lifted just a little, ready to splash downward and "+
            "send him soaring through the %^BLUE%^water%^CYAN%^.  "+
            "From pointed nose to tail tip, his body is covered "+
            "in soft %^BLUE%^blue cotton%^CYAN%^, while his sides "+
            "and belly are made from equally soft %^WHITE%^white "+
            "cotton%^CYAN%^.  Both flippers are %^BLUE%^blue "+
            "%^CYAN%^and contrast well against the %^WHITE%^white "+
            "%^CYAN%^sides.  %^BLACK%^Black embroidered eyes "+
            "%^CYAN%^can be seen to either side of the gently "+
            "curved face, and %^BLACK%^black embroidery %^CYAN%^"+
            "gives this little guy a slight smile.  On the left "+
            "tail flipper a small symbol has been neatly "+
            "embroidered.%^RESET%^";
         break;
      case "kelemvor":
         myanimal = "panther";
         myshort = "A stuffed animal in the shape of a "+
            "%^BLACK%^%^BOLD%^panther%^RESET%^";
         mylong = "%^BOLD%^%^BLACK%^This fuzzy, black wool "+
            "panther might almost be mistaken for a black cat "+
            "of some sort except for the muscular, long body "+
            "that has a more feral presence to it.  Alert, "+
            "rounded ears perk forward and keen, %^RESET%^"+
            "%^CYAN%^gray-blue %^BOLD%^%^BLACK%^embroidered "+
            "eyes watch his surroundings carefully.  His "+
            "strong legs hold him upright and in a state of "+
            "motion, while the long black tail curves behind "+
            "him, helping him balance.  On his left rear "+
            "flank can be seen a small embroidered symbol.%^RESET%^";
         break;
      case "kossuth":
         myanimal = "salamander";
         myshort = "A stuffed animal in the shape of a %^BOLD%^"+
            "%^RED%^sal%^RESET%^%^RED%^a%^YELLOW%^m%^RESET%^"+
            "%^RED%^a%^BOLD%^nd%^YELLOW%^e%^RED%^r%^RESET%^";
         mylong = "%^RESET%^%^ORANGE%^Made out of bright orange "+
            "leather, this little salamander has a smooth, "+
            "glossy skin punctuated by dozens of tiny %^RED%^"+
            "red spots %^ORANGE%^all over his long body.  Huge, "+
            "embroidered %^GREEN%^green eyes %^ORANGE%^can be "+
            "seen on either side of his head and his mouth is "+
            "sewn partly open so you can see the long %^BOLD%^"+
            "%^MAGENTA%^pink tongue%^RESET%^%^ORANGE%^ ready to "+
            "slip out and snatch a %^BOLD%^%^BLACK%^bug %^RESET%^"+
            "%^ORANGE%^from the air.  The long tail curls back "+
            "around behind him, almost as long as his body and "+
            "equally speckled with the %^RED%^red spotting "+
            "%^ORANGE%^that gives him a bit of texture.  Just "+
            "before the tail starts, on the left leg, an "+
            "embroidered symbol can be seen.%^RESET%^";
         break;
      case "lathander":
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
      case "malar":
         myanimal = "wolverine";
         myshort = "A stuffed animal in the shape of a "+
             "%^RESET%^%^ORANGE%^wolverine%^RESET%^";
         mylong = "%^RESET%^%^ORANGE%^This dark brown stuffed "+
            "animal is made out of real, semi-coarse fur.  The "+
            "stubby body is supported by four squat legs each "+
            "with sharp-looking leather claws curling out from "+
            "the paws.  Along its belly and around its mouth is "+
            "a light colored fur, almost %^RESET%^cream%^ORANGE%^ "+
            "in color, while its tail is a deep%^BOLD%^%^BLACK%^ "+
            "charcoal%^RESET%^%^ORANGE%^.  Small, round ears "+
            "made of leather stick up from the side of its head "+
            "and a leather nose tips its muzzle.  %^BOLD%^"+
            "%^BLACK%^Black %^RESET%^%^ORANGE%^embroidered eyes "+
            "glint amongst the fur, as does an embroidered symbol "+
            "on its left hind leg.%^RESET%^";
         break;
      case "mask":
         myanimal = "gray horse";
         myshort = "A stuffed animal in the shape of a %^BOLD%^"+
            "%^BLACK%^gr%^RESET%^a%^BOLD%^%^BLACK%^y h%^RESET%^o"+
            "%^BOLD%^%^BLACK%^r%^RESET%^s%^BOLD%^%^BLACK%^e%^RESET%^";
         mylong = "%^BOLD%^%^BLACK%^This large %^RESET%^d%^BOLD%^"+
            "%^BLACK%^a%^RESET%^pp%^BOLD%^%^BLACK%^l%^RESET%^e-gr"+
            "%^BOLD%^%^BLACK%^a%^RESET%^y %^BOLD%^%^BLACK%^stallion "+
            "looks as though he's strong and swift enough for any "+
            "rider.  Made from %^RESET%^gray cotton %^BOLD%^"+
            "%^BLACK%^that has been dyed with %^WHITE%^white "+
            "spots %^BLACK%^along his flanks, this equine stands "+
            "alert with his ears cocked forward, his %^BLUE%^dark "+
            "blue eyes %^BLACK%^watchful, and his nostrils flared.  "+
            "Black yarn is sewn along his mane and tail, all "+
            "neatly trimmed and flowing.  A %^RESET%^%^ORANGE%^"+
            "brown leather saddle%^BOLD%^%^BLACK%^ and a set of "+
            "%^RESET%^%^ORANGE%^leather reins %^BOLD%^%^BLACK%^can "+
            "be removed or slid onto his body, and a small symbol "+
            "has been embroidered onto his left rear flank.%^RESET%^";
         break;
      case "mielikki":
         myanimal = "unicorn";
         myshort = "A stuffed animal in the shape of a "+
            "%^BOLD%^%^WHITE%^unicorn%^RESET%^";
         mylong = "%^BOLD%^%^WHITE%^Like magic itself this "+
            "%^YELLOW%^golden-horned %^WHITE%^equine stands on "+
            "four golden %^YELLOW%^lame %^WHITE%^hooves, watching "+
            "the forestlands around her with keen %^GREEN%^green "+
            "eyes%^WHITE%^.  Made from soft, white velvet and golden "+
            "lame, she is both delicate and fierce in her vigilant "+
            "stance.  With her ears lifted high, listening, she "+
            "seems perfectly still and yet ready to race ahead with "+
            "her rider's imagination in tow.  A small embroidered "+
            "marking can be seen sewn upon her left rear flank. %^RESET%^";
         break;
      case "mystra":
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
      case "oghma":
         myanimal = "calico cat";
         myshort = "A stuffed animal in the shape of a %^RESET%^"+
            "%^ORANGE%^c%^RED%^a%^ORANGE%^li%^YELLOW%^c%^RESET%^"+
            "%^ORANGE%^o c%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^t%^RESET%^";
         mylong = "%^RESET%^%^ORANGE%^Playfully alert, this cotton, "+
            "%^BOLD%^%^BLACK%^c%^WHITE%^a%^RESET%^%^ORANGE%^l%^BOLD%^"+
            "%^BLACK%^i%^WHITE%^c%^RESET%^%^ORANGE%^o %^BOLD%^"+
            "%^BLACK%^k%^WHITE%^i%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^"+
            "t%^WHITE%^y %^RESET%^%^ORANGE%^appears to be caught "+
            "mid-caper as he rests on his hind legs with one forepaw "+
            "lifted in play.  %^BLUE%^Blue%^ORANGE%^, inquisitive "+
            "eyes are embroidered onto the %^BOLD%^%^BLACK%^black"+
            "%^RESET%^%^ORANGE%^, orange, and %^WHITE%^%^BOLD%^"+
            "white %^RESET%^%^ORANGE%^face.  A light %^BOLD%^"+
            "%^MAGENTA%^pink %^RESET%^%^ORANGE%^nose has likewise "+
            "been sewn into place and two white felt ears lift up "+
            "in eager anticipation.  His long, banded tail coils "+
            "about behind him, swinging to either side with any "+
            "movement, and on his left hind flank a small "+
            "embroidered symbol can be seen.%^RESET%^";
         break;
      case "selune":
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
      case "shaundakul":
         myanimal = "squirrel";
         myshort = "A stuffed animal in the shape of a "+
            "%^BOLD%^%^BLACK%^squirrel%^RESET%^";
         mylong = "%^BOLD%^%^BLACK%^This little gray squirrel "+
            "sits perked up and watchful.  His %^RESET%^fuzzy"+
            "%^BOLD%^%^BLACK%^, brushed wool tail rises almost "+
            "all the way to his cute pointed cotton ears before "+
            "folding over in a curve.  Made from soft %^RESET%^"+
            "gray cotton%^BOLD%^%^BLACK%^, this little guy looks "+
            "ready for a day of %^RESET%^%^GREEN%^hunting %^BOLD%^"+
            "%^BLACK%^and %^RESET%^%^ORANGE%^exploring %^BOLD%^"+
            "%^BLACK%^with his embroidered black eyes almost "+
            "gleaming in excitement as he scents the air.  On his "+
            "left hind flank a symbol can also be seen "+
            "embroidered clearly.%^RESET%^";
         break;
      case "shar":
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
      case "sune":
         myanimal = "tressym";
         myshort = "A stuffed animal in the shape of a "+
            "%^MAGENTA%^tr%^BOLD%^%^BLACK%^e%^RED%^s%^RESET%^"+
            "%^MAGENTA%^s%^BOLD%^%^BLACK%^y%^RED%^m%^RESET%^";
         mylong = "%^BOLD%^%^WHITE%^This little kitten is curled "+
            "up in a little %^BLACK%^black %^WHITE%^and %^RESET%^"+
            "white %^BOLD%^%^WHITE%^ball of fur.  His embroidered "+
            "eyes are closed, showing only the thin line of dainty "+
            "%^BLACK%^black eyelashes%^WHITE%^.  His cute "+
            "%^MAGENTA%^pink nose %^WHITE%^is carefully tucked "+
            "under his one %^RESET%^white %^BOLD%^%^WHITE%^paw, "+
            "while the other three paws are %^BLACK%^black%^WHITE%^.  "+
            "On his rear left flank a small, embroidered symbol can "+
            "be seen, though it's a bit difficult to notice as he "+
            "is curled up, laying on that side.  Small felt ears "+
            "are lain smooth against his head and the long, %^RESET%^"+
            "white cotton tail %^BOLD%^%^WHITE%^tipped in %^BLACK%^"+
            "black%^WHITE%^ circles around and up against the middle "+
            "of his body, right under the large %^RED%^red %^WHITE%^"+
            "and %^MAGENTA%^pink %^WHITE%^wings that lay along his "+
            "back.  Snuggled up close to his body, the feather-covered "+
            "wings are made of tiny pieces of colored gauze that "+
            "simulates the feathered effect.  The way they move "+
            "just a little with every brush of %^CYAN%^air %^WHITE%^"+
            "almost gives this stuffed animal the appearance of "+
            "breathing in his sleep, yet he is made out of cotton "+
            "and stuffed with wool.%^RESET%^";
         break;
      case "talos":
         myanimal = "bloodhawk";
         myshort = "A stuffed animal in the shape of a "+
            "%^RESET%^%^RED%^bloodhawk%^RESET%^";
         mylong = "%^RESET%^%^RED%^Created from dark, %^BOLD%^"+
            "blood-red %^RESET%^%^RED%^velvet fabric, this stuffed "+
            "animal holds its long wings outward as though about "+
            "to lift into the air.  %^RESET%^%^ORANGE%^Dark brown "+
            "leather %^RED%^has been sewn into two sets of almost "+
            "sharp-looking %^ORANGE%^talons %^RED%^as well as a "+
            "long %^ORANGE%^beak %^RED%^that is just slightly open.  "+
            "Beady %^BOLD%^%^BLACK%^black eyes %^RESET%^%^RED%^have "+
            "been embroidered into the hawk's face, and additional "+
            "needle work has given the whole toy the appearance of "+
            "%^ORANGE%^f%^RED%^ea%^ORANGE%^th%^RED%^er%^ORANGE%^s"+
            "%^RED%^.  Just above this bird's left leg an "+
            "embroidered symbol can be seen.%^RESET%^";
         break;
      case "tempus":
         myanimal = "tiger";
         myshort = "A stuffed animal in the shape of a %^RESET%^"+
            "%^ORANGE%^t%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^g"+
            "%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^r%^RESET%^";
         mylong = "%^RESET%^This empress of the forest stands "+
            "regal and watchful upon four mighty legs.  Her body "+
           "is made of soft %^RESET%^%^ORANGE%^orange cotton "+
           "%^RESET%^with strips of %^BOLD%^%^BLACK%^black velvet "+
           "%^RESET%^making the bands across her back and around "+
           "her legs.  Her belly is made of %^BOLD%^%^WHITE%^white "+
           "cotton %^RESET%^that is brushed so that its slightly "+
           "fuzzy and soft.  Standing with her mouth open, a "+
           "%^BOLD%^%^MAGENTA%^pink piece of felt %^RESET%^has been "+
           "placed for her tongue while tiny %^BOLD%^%^WHITE%^white "+
           "triangles %^RESET%^have been applied for her upper and "+
           "lower canines.  Her eyes are a brilliant %^BOLD%^"+
           "%^GREEN%^emerald green %^RESET%^and on her left rear "+
           "flank is a symbol that is likewise embroidered.";
         break;
      case "torm":
         myanimal = "lion";
         myshort = "A stuffed animal in the shape of a "+
            "%^YELLOW%^lion%^RESET%^";
         mylong = "%^YELLOW%^Standing proudly on four wide feet, "+
            "this lion-shaped stuffed animal is a majestic "+
            "representation of the animal found in the wild.  "+
            "%^RESET%^%^ORANGE%^Golden cotton %^YELLOW%^has been "+
            "used to make the body while hundreds of neatly-trimmed "+
            "yarn strips in a darker %^RESET%^%^ORANGE%^brown "+
            "%^YELLOW%^have been sewn along the neck to make this "+
            "lion's mane and tail tuft.  %^BLUE%^Blue eyes %^YELLOW%^"+
            "have been embroidered onto his face, and his mouth is "+
            "sewn so that it is open in a perpetual and mighty "+
            "%^WHITE%^roar%^YELLOW%^!  A symbol has been embroidered "+
            "on the rear left flank of this toy.%^RESET%^";
         break;
      case "tymora":
         myanimal = "faerie dragon";
         myshort = "A stuffed animal in the shape of a %^MAGENTA%^"+
            "%^BOLD%^f%^WHITE%^a%^MAGENTA%^er%^WHITE%^i%^MAGENTA%^e "+
            "dr%^WHITE%^a%^MAGENTA%^g%^WHITE%^o%^MAGENTA%^n%^RESET%^";
         mylong = "%^RESET%^%^ORANGE%^This little stuffed animal is "+
            "about the size of a %^YELLOW%^ripe peach %^RESET%^"+
            "%^ORANGE%^and is about the same color too!  Soft, "+
            "fuzzy %^YELLOW%^peach-colored velvet %^RESET%^%^ORANGE%^"+
            "has been used to make the body of this little dragon, "+
            "while %^MAGENTA%^%^BOLD%^bright pink %^RESET%^%^ORANGE%^"+
            "cotton triangles have been sewn on as floppy wings "+
            "extending from the middle of his back.  A piece of "+
            "%^RED%^red felt %^ORANGE%^extends from the %^BOLD%^"+
            "%^BLACK%^black yarn mouth %^RESET%^%^ORANGE%^as the "+
            "dragon's forked tongue, while bright %^YELLOW%^gold "+
            "eyes %^RESET%^%^ORANGE%^have been embroidered onto "+
            "the face giving him a clever, eager expression.  A "+
            "symbol can be seen embroidered on its left rear flank "+
            "as well.  While crouched down on all fours, looking "+
            "as though about to pounce, you can't image this little "+
            "dragon chasing anything bigger then a %^YELLOW%^butterfly "+
            "%^RESET%^%^ORANGE%^or %^GREEN%^grasshopper%^RESET%^"+
            "%^ORANGE%^.%^RESET%^";
         break;
      case "tyr":
         myanimal = "bald eagle";
         myshort = "A stuffed animal in the shape of a %^RESET%^"+
            "%^ORANGE%^b%^WHITE%^a%^ORANGE%^ld e%^WHITE%^ag"+
            "%^ORANGE%^le%^RESET%^";
         mylong = "%^RESET%^%^ORANGE%^This %^BOLD%^%^WHITE%^white "+
            "%^ORANGE%^and %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^"+
            "ld %^RESET%^%^ORANGE%^cotton eagle sits majestically "+
            "with his wings tight against his sides.  His %^RESET%^"+
            "bald head %^ORANGE%^is turned slightly to the side and "+
            "%^YELLOW%^b%^RESET%^%^ORANGE%^ro%^YELLOW%^w%^RESET%^"+
            "%^ORANGE%^ni%^YELLOW%^s%^RESET%^%^ORANGE%^h-g%^YELLOW%^"+
            "o%^RESET%^%^ORANGE%^l%^YELLOW%^d %^RESET%^%^ORANGE%^eyes "+
            "watch his surroundings carefully.  A %^YELLOW%^bright "+
            "yellow%^RESET%^%^ORANGE%^ felt beak and talons give "+
            "contrast to the %^YELLOW%^g%^RESET%^%^ORANGE%^old"+
            "%^YELLOW%^e%^RESET%^%^ORANGE%^n-b%^YELLOW%^r%^RESET%^"+
            "%^ORANGE%^ow%^YELLOW%^n %^RESET%^%^ORANGE%^and %^BOLD%^"+
            "%^WHITE%^white %^RESET%^%^ORANGE%^of the body.  Long, "+
            "elegant tail and pin feathers have been carefully sewn "+
            "to make this stuffed animal look even more real, and a "+
            "small symbol has been stitched at the base of his left "+
            "wing.%^RESET%^";
         break;
      default :      myanimal = "bug";
                     MYDEITY = "talos"; //just so read won't bug
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