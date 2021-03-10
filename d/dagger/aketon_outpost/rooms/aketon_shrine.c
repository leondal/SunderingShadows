#include <std.h>
#include "../aketon_outpost.h"

inherit ROOM;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
   set_name("%^GREEN%^Corellon's Glade%^RESET%^");
   set_short("%^GREEN%^Corellon's Glade%^RESET%^");
   set_long("%^GREEN%^Corellon's Glade%^RESET%^\n"+
      "%^GREEN%^Nestled among the foliage of the trees"+
 " lays this awe inspiring shrine.  %^BOLD%^%^MAGENTA%^M"
 "%^GREEN%^o%^CYAN%^t%^BLUE%^e%^WHITE%^s%^RESET%^%^GREEN%^ "
 "of light float in the air, casting their auras onto the "
 "area in a playful manner.  The limbs of the trees have been"+
 " magically shaped to create ornate %^ORANGE%^arches%^GREEN%^"
 " that tower high into the air.  The smaller limbs of the "+
 "branches have been shaped to create delicate designs, though "+
 "still keeping the trees healthy and undamaged.  Set about in a "+
 "circular fashion around the shrine are a series of "+
 "%^BOLD%^%^CYAN%^statues%^RESET%^%^GREEN%^.  The statues pay tribute "+
 "to the Seldarine, the gods of the elven race.\n");
set_smell("default","The perfumes of the forest hangs in the air.");
   set_listen("default","Songbirds sing among the rustle of leaves.");
   set_items(([
      ({"statues","seldarine"}) : "The statues depict how the elves view "+
"the gods there revere.  %^YELLOW%^Corellon%^RESET%^ is seen as the "+
"leader of the elven pantheon.  %^BOLD%^%^WHITE%^Sehanine%^RESET%^ is"+
" often times depicted as his consort.  %^BOLD%^%^CYAN%^Aerdrie%^RESET%^"+
" is the goddess of the air and fertility, while %^BOLD%^%^MAGENTA%^Hanali"+
" %^RESET%^is the goddess of love and beauty.  %^CYAN%^Deep Sashelas%^RESET%^"+
" is the god of the sea and the sea elves.  %^BOLD%^%^BLUE%^Erevan%^RESET%^ is"+
" a trickster god, playing up to the elves' humor.  %^GREEN%^Fenmarel%^RESET%^ "+
"is the god of outcast, venerated by those isolationist elves.  %^BOLD%^%^GREEN%^"+
"Khalreshaar%^RESET%^ is a half-elf goddess of the forest, who holds a special place"+
" in the Seldarine.  %^MAGENTA%^Labelas%^RESET%^ is the god of knowledge, and time."+
"  %^ORANGE%^Rillifane%^RESET%^ is the god of nature, while his brother "+
"%^BOLD%^%^GREEN%^Solonar%^RESET%^ is the god of archery and hunting.  A grim figure"+
" among the elves is %^BOLD%^%^BLACK%^Shevarash%^RESET%^, god of retribution and"+
" usually called upon by those with an all consuming hatred of the drow.",
      ({"corellon","lathander"}) : "Standing in the center of the shrine is the largest of"
" the statues.  Carefully and lovingly cared, the features of a slender but muscular"+
" male elf is decked out in %^BOLD%^mi%^CYAN%^t%^WHITE%^hr%^CYAN%^i%^WHITE%^l%^RESET%^"+
" chainmail and an %^BOLD%^%^BLUE%^a%^CYAN%^z%^BLUE%^u%^CYAN%^r%^BLUE%^e%^RESET%^ blue"+
" tabard.  The chainmail is of obvious elven make, with echoes of nature throughout the"+
" suit.  Looking up into the heavens, %^YELLOW%^Corellon%^RESET%^ strikes a proud stance."+
"  His %^ORANGE%^bronze%^RESET%^ skin and long %^YELLOW%^golden%^RESET%^ hair note him to "+
"be a Sun Elf, as the Father of all Elves is typically presented.  Sheathed in a elaborate"+
" scabbard around his waist is his legendary long sword, %^BOLD%^%^BLUE%^Sahandrian%^RESET%^."+
"  His right hand curls around a fine %^BOLD%^silvery%^RESET%^ long bow that rests against "+
"the ground, adding to the martial feeling of the statue.  His left hand holds a spiraling "+
"lap harp that shimmers in %^BOLD%^c%^RESET%^%^CYAN%^e%^MAGENTA%^l%^BOLD%^%^BLUE%^e%^WHITE%^"+
"s%^RESET%^%^CYAN%^t%^MAGENTA%^i%^BOLD%^%^BLUE%^a%^WHITE%^l%^RESET%^ colors, noting his role"+
" as both a protector-warrior and an artist.  To those ignorant of elven customs, Corellon is"+
" known as Lathander.",
      ({"sehanine","selune"}) : "This statue of a lithe female elf has pale skin and hair, noting her "+
"role as the mother to the Moon Elves."+
"  Her hair is braided and twisted with %^BOLD%^pearls%^RESET%^, %^CYAN%^%^BOLD%^"+
"silver strands%^RESET%^, and %^BOLD%^moonstones%^RESET%^. Dressed in a flowing gown"+
" of pleated silk, %^BOLD%^%^CYAN%^Sehanine%^RESET%^ possess an otherworldly feeling"+
" to her.  Her eyes glance up at the sky, with a thoughtful dreamy expression.  "+
"Cradled in her hands is an orb that takes the appearance of a %^BOLD%^%^CYAN%^f%^WHITE%^u"+
"%^CYAN%^ll m%^WHITE%^o%^CYAN%^on%^RESET%^.  As the goddess of diviners, Sehanine is"+
" often called upon by elven oracles for insight in their dreams and the future.  Among"+
" those outside of the elves, Sehanine is known as Selune.",
     ({"aerdrie","akadi"}) : "Large %^BLUE%^fe%^BOLD%^%^CYAN%^a%^RESET%^%^BLUE%^th%^BOLD%^e"+
"%^RESET%^%^BLUE%^red%^RESET%^ wings frame the slender form of this statue.  The wings are "+
"arched above the statue's body, as if it is ready to soar into the air, depicting "+
" the goddess of the air %^BOLD%^%^CYAN%^Aerdrie%^RESET%^.  Her long hair streams "+
"about her, as if dancing on a breeze.  A simple silken shift adorns her body, with"+
" long strips of %^BOLD%^%^CYAN%^s%^BLUE%^i%^CYAN%^l%^BLUE%^k%^RESET%^ wrap around "+
"her.  The silk ribbons are left unfurrowed, to billow in the winds.  In Aerdrie's "+
"hands, a %^BOLD%^%^CYAN%^thunderbolt%^RESET%^ is shown, invoking her role as a weather"+
" goddess.  Aerdrie is known as Akadi among those outside of the elven communities. ",
      ({"hanali","sune"}) : "Dressed in a short %^BOLD%^white%^RESET%^ shift, this statue is of "+
"an unearthly comely female elf.   Her fine features are in perfect harmony with the rest"+
" of her form, her %^BOLD%^%^MAGENTA%^beauty%^RESET%^ even surpassing that of the nymphs."+
"  Long ringlets of %^YELLOW%^golden%^RESET%^ hair frame her face, with delicate pieces"+
" of %^BOLD%^j%^RED%^e%^MAGENTA%^w%^RED%^e%^YELLOW%^l%^WHITE%^r%^RED%^y%^RESET%^ adorn "+
"her.  %^BOLD%^%^MAGENTA%^Hanali%^RESET%^ is the elven goddess of love and beauty.  The statue"+
" is shown with bare feet, a typical depiction of Hanali.  Anklets of fine %^YELLOW%^gold"+
" %^RESET%^caress each ankle, with glittering charms of tressyms, roses, and golden hearts"+
" suspended from the wire.  The statue is shown with one hand over her heart, the other"+
" caressing one of her ears, as a sign that she hears all that is in the heart.  Hanali is "+
"known as Sune among those outside of the elven culture.",
({"deep sashelas","istishia","sashelas"}) : "Riding on top of a leaping %^BOLD%^%^BLACK%^dolphin"+
"%^RESET%^, this statue of a male aquatic elf represents %^CYAN%^Deep Sashelas%^RESET%^, "+
"the elven god of water and the sea.  His long %^BOLD%^%^CYAN%^sea green%^RESET%^ hair "+
"is adorned with %^BOLD%^s%^YELLOW%^h%^WHITE%^e%^RESET%^%^ORANGE%^l%^BOLD%^%^WHITE%^l%^MAGENTA%^s"+
"%^RESET%^ and %^YELLOW%^starfish%^RESET%^, treasures of the ocean depths.  His %^BOLD%^%^BLUE%^"+
"pale blue%^RESET%^ skin is mottled with %^GREEN%^green%^RESET%^ splotches, as all sea elves are."+
"  With his muscular chest and arms, Deep Sashelas has the appearance of a powerful swimmer.  "+
"In one hand he holds an elaborate trident, the other clings to the dolphin he rides upon."+
" Among those outside of the elves Deep Sashelas is known as Istishia.",
({"erevan","tymora"}) : "With a mischievous smirk and a playful glint in his eyes, this statue of"+
" %^BOLD%^%^BLUE%^Erevan%^RESET%^ stands tall.  The slim male elf is dressed in studded"+
" leather armor dyed %^BLUE%^deep blue%^RESET%^.  The studs of his armor take the shape "+
"of chaotic starbursts that always seem to be changing %^GREEN%^s%^YELLOW%^h%^CYAN%^a"+
"%^BLUE%^p%^MAGENTA%^e%^RESET%^ and %^BOLD%^%^RED%^c%^WHITE%^o%^BLACK%^l%^BLUE%^o%^CYAN%^r"+
"%^RESET%^.  His short %^BOLD%^white%^RESET%^ hair is spiked up, adding to his impish"+
" quality.  One gloved hand is hidden behind his back, while the other proudly displays"+
" a %^ORANGE%^dwarven%^RESET%^ trinket, no doubt gained from some form of trickery."+
"  Among those outside of the elves, Erevan is known as Tymora.",
({"fenmarel","grumbar"}) : "Looking %^GREEN%^sullen%^RESET%^ and %^ORANGE%^withdrawn%^RESET%^"+
", this statue of %^GREEN%^Fenmarel%^RESET%^ looks isolated from the other statues."+
"  Dressed in a rather "+
"primitive fashion of %^BOLD%^%^GREEN%^leaves%^RESET%^ and %^ORANGE%^leather%^RESET%^,"+
" Fenmarel still retains an elven look to him.  His dark brown skin is tinged with "+
"green accents, connecting him to the Wild Elves.  His matted %^ORANGE%^brown%^RESET%^"+
" hair is adorned with %^RED%^f%^CYAN%^e%^BLUE%^a%^GREEN%^t%^WHITE%^h%^YELLOW%^e%^RED%^r"+
"%^RESET%^ and %^BOLD%^bone%^RESET%^ totems.  Intricate "+
"%^CYAN%^t%^GREEN%^a%^ORANGE%^t%^CYAN%^t%^GREEN%^o%^ORANGE%^o%^CYAN%^s%^RESET%^ of "+
"animal shapes and geometrical designs cover the exposed skin of this statue.  To "+
"those not of the elven nation, Fenmarel is known as Grumbar.",
({"khalreshaar","mielikki"}) : "This statue is an oddity among the other statues gathered here."+
"  Her half-elven features are as glaring as the sun in the sky.  Despite this difference,"+
" the statue stands as one with the other elven icons here.  Dressed in a %^BOLD%^%^GREEN%^"+
"green%^RESET%^ tunic and leggings, this half-elf has a rugged spirit to her.  %^GREEN%^"+
"Twin axes%^RESET%^ are sheathed in her leather belt, while a quiver full of arrows drape"+
" across her chest.  Her %^RED%^r%^ORANGE%^u%^RED%^ss%^ORANGE%^e%^RED%^t%^RESET%^ colored hair is "+
"woven into a single braid.  In her hands she cradles a %^BOLD%^unicorn%^RESET%^ colt, "+
"nurturing and protecting it. Khalreshaar is the name that Mielikki takes among the elves.",
({"labelas","oghma"}) : "Looking lost in a thought, this statue of a slender short elven male"+
" posses as sagacious quality to it.  Dressed in an elegant tunic and breeches of "+
"%^MAGENTA%^purple%^RESET%^ and %^BOLD%^white%^RESET%^ silk, his clothing carry a feeling"+
" %^MAGENTA%^a%^BOLD%^%^BLACK%^n%^RESET%^%^MAGENTA%^t%^RESET%^i%^MAGENTA%^q%^BOLD%^%^BLACK%^"+
"u%^RESET%^%^MAGENTA%^i%^RESET%^t%^MAGENTA%^y%^RESET%^ to them.  One notable feature of this"+
" elven male, is a %^BOLD%^%^BLACK%^black eye%^RESET%^ patch that conceals his left eye.  "+
"His %^BOLD%^silv%^CYAN%^e%^WHITE%^ry%^RESET%^ hair is brushed back and held in check with"+
" a wide circlet.  In his left hand he holds an opened %^BOLD%^%^BLACK%^massive tome%^RESET%^."+
"  A %^YELLOW%^feathered %^RESET%^quill is grasped in his right, as he prepares to preserve"+
" a thought.  To those not familiar with the elves, Labelas is known as Oghma.",
({"rillifane","silvanus"}) : "Dressed in leather armor that takes the shape of %^ORANGE%^oak"+
" %^RESET%^leaves, this elven figure strikes a balance between a protector and a nurture."+
"  On his face, a kind and caring expression has been carved.  His braided %^GREEN%^green"+
" %^RESET%^hair hangs about his shoulders.  In one hand he holds a %^ORANGE%^liveoak%^RESET%^"+
" sapling, that %^YELLOW%^thrives%^RESET%^ and %^GREEN%^grows%^RESET%^.  In his other hand "+
"he holds a worn and scarred %^ORANGE%^quarterstaff%^RESET%^, that seems as if it has seen "+
"it's share of battle.  %^ORANGE%^Rillifane%^RESET%^ is the god of nature, and deeply respected"+
" among the elves.  To those unknowing of the elven customs, Rillifane is known as Silvanus.",
({"solonar","shaundakul"}) : "Posed as if in the middle of firing an arrow, this statue of "+
"%^BOLD%^%^GREEN%^Solonar%^RESET%^ strikes a powerful pose.  The %^BOLD%^white%^RESET%^"+
" haired elven male has been carved with well defined arms and upper body, displaying his"
" prowess with the bow.  He is dressed simply in a %^GREEN%^green%^RESET%^ tunic and breeches."+
"  A hooded %^CYAN%^c%^GREEN%^l%^CYAN%^o%^GREEN%^a%^CYAN%^k%^RESET%^ and matching "
"%^GREEN%^b%^CYAN%^o%^GREEN%^o%^CYAN%^t%^GREEN%^s%^RESET%^ of elven quality adorn his body."+
"  His white hair is drawn back into a ponytail.  Hanging from his waist, a quiver full of"+
" %^BOLD%^%^GREEN%^green%^RESET%^ feather notched arrows can be seen.  The arrows, oddly enough,"+
" all look to be fashioned from %^BOLD%^silver%^RESET%^.  Solonar draws his elegant elven "+
"%^ORANGE%^l%^CYAN%^o%^GREEN%^n%^WHITE%^g %^ORANGE%^b%^GREEN%^o%^ORANGE%^w%^RESET%^ back,"+
" and has an arrow ready to launch, as if in the middle of a hunt.  To those outside of the"+
" elven communities, Solonar is known as Shaundakul.",
({"shevarash","tyr"}) : "A grim figure among the statues here is that of %^BOLD%^%^BLACK%^Shevarash"+
"%^RESET%^.  Looking %^BLUE%^joyless%^RESET%^ and %^RED%^serious%^RESET%^, this statue lacks "+
"any of the mirth and joy the elves are known for.  Dressed in a full regalia of "+
"%^BOLD%^%^BLACK%^b%^BLUE%^l%^BLACK%^ac%^BLUE%^k%^RESET%^ elven chainmail, this tall elven "+
"figure looks dressed for war.  A long %^BOLD%^%^BLACK%^black%^RESET%^ cloak flows about him,"+
" adding to the grim air around him.  A quiver filled with %^BOLD%^%^BLACK%^black %^RESET%^arrows"+
" hangs across his chest.  In both hands he holds a deadly looking "+
"%^BOLD%^%^BLACK%^l%^RED%^o%^BLUE%^n%^BLACK%^g %^BLUE%^b%^BLACK%^o%^BLUE%^w%^RESET%^, one meant"+
" for war instead of hunting.  To those unknowing of elven customs, Shevarash is known as Tyr."
   ]));
   set_exits(([
      "northeast" : ROOMS"aketon_central",
   ]));
} 
