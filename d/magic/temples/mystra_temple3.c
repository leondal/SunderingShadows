//Designed by Isaiah, coded by Circe 11/10/04
//cleaned and coloured by Nienne, 12/04 //
#include <std.h>
inherit "/std/templemisc";
//global variable to show which painting is active will be zero if no paintings showing
int showing = 0;
int scene = 0;
string painting;

void create() {
     ::create();
     set_property("indoors",1);
     set_property("light",2);
     set_terrain(STONE_BUILDING);
     set_travel(PAVED_ROAD);
     set_name("Hall of Paintings");
     set_short("Hall of Paintings");
     set_long("%^MAGENTA%^This enchanted-looking hallway adds "+
        "to the mystery that embodies the temple of %^BOLD%^"+
        "Mystra%^RESET%^%^MAGENTA%^.  To the south, there are "+
        "%^BOLD%^%^BLACK%^black-streaked marble pillars%^RESET%^"+
        "%^MAGENTA%^ like the main part of the temple.  They "+
        "support a rather large stone overhang that goes to the "+
        "outside road.  The eastern and western walls are draped "+
        "with %^BOLD%^curtains of thick velvet%^RESET%^%^MAGENTA%^"+
        ".  The ceiling is painted %^BOLD%^%^BLACK%^black%^RESET%^"+
        "%^MAGENTA%^ and steeply arched in a %^BOLD%^%^BLACK%^gothic "+
        "manner%^RESET%^%^MAGENTA%^.  A large set of double double "+
        "doors leads to the temple proper.  Evenly-spaced %^BOLD%^"+
        "glowing magenta balls%^RESET%^ %^MAGENTA%^float towards the "+
        "top of the ceiling.  They %^BOLD%^illuminate%^RESET%^"+
        "%^MAGENTA%^ the elaborate hall with a dim lighting.  The "+
        "most stunning feature of this hall remains the %^BOLD%^"+
        "paintings%^RESET%^%^MAGENTA%^.  They are life-sized and "+
        "spaced several feet apart.   Both sides of the hallway each "+
        "have four.  Under the paintings are plaques with elegant "+
        "writing on them.  In the center of the room sits a %^BOLD%^"+
        "crystal ball%^RESET%^%^MAGENTA%^ on a pedestal.%^RESET%^\n");
   set_smell("default","The smell is crisp and clean as a high "+
      "quality building should be.");
   set_listen("default","The temple is oddly quiet.");
   set_items(([
     ({"plaque","plaques"}) : "These plaques are made of brass and "+
        "have elegant scripted writing engraved on them.",
     ({"door","doors","double doors"}) : "These massive double doors"+
        " are each nearly 10 feet high and 5 feet wide.  They are made"+
        " of marble with streaks of black in them.  They look very "+
        "difficult to open.  They open inward into the temple.",  
     ({"ball","crystal ball"}) : "This ball sits on top of a obsidian "+
        "pedestal engraved with rubies and seems to have a magical "+
        "aura about it.",
     "hallway" : "This hallways is long and looks mysterious with "+
        "the violet light from the magic balls.",
     ({"wall","walls","east wall","west wall","eastern wall","western wall"}) : 
        "The walls are covered with rich velvet drapes of a violet "+
        "hue.  Obviously, this structure was added on to the "+
        "original construction.",
     "ceiling" : "The ceiling is black and slopes upward sharply "+
        "with thinly cut beams which are a matching black.  The "+
        "flicker and glow of the violet orbs dance off the sleek "+
        "surface.",
     ({"ball", "balls"}) : "The balls twinkle with a dim violet "+
        "light, they cast a mysterious flicker throughout the hall.",
     "drapes" : "Part of the north end of the hallway as well as "+
        "the longer east and west walls are covered in rich violet "+
        "velvet drapes.  The paintings have been placed on top of "+
        "these drapes which are brighter and stand out more to the "+
        "darkly contrasted walls.",
     "pedestal" : "The obsidian pedestal has a crystal ball sitting on it.",
     "overhang" : "The pillars hold up a large overhang that shades "+
        "the entrance to the temple.",
     ({"painting", "paintings"}) : "There are a total of eight "+
        "paintings in the hall.  Each of them depict someone that "+
        "is related of import in magic in the lands of Shadowgate, "+
        "and to Mystra herself.",
//Here are the short descs of the paintings
     "painting 1" : "This is a painting of an average looking "+
        "female half-elf standing near a tower and holding a book. "+
        " She appears to be confident preaching to a crowd of "+
        "mages.  It is titled S'lore.",
     "painting 2" : "This is a tall male human who looks middle "+
        "aged.  He is dressed in shining armor and sits atop a "+
        "horse with a lance in one hand and a large shining "+
        "shield in the other.  It is titled Trevize.",
     "painting 3" : "This is a painting of a woman of mixed "+
        "elven and human heritage.  She is of a svelte figure "+
        "and has honey eyes and sable hair.  She is wearing a "+
        "fancy dress and is in a position of movement holding a "+
        "whip in one hand as it spirals around her in a dance.  "+
        "It is titled Nicolya.",
     "painting 4" : "Two elves sit together, the male elf "+
        "with his hand around the female's shoulder and the "+
        "female elf with her hand around the other elf's torso.  "+
        "The female has rose-red short spiked hair with crisp "+
        "blue eyes and the male is wearing a mage's robe.  He "+
        "has green eyes and black hair.  It is titled Kirin and Asalyr.",
     "painting 5" : "A female half-elf with long auburn hair "+
        "stands poised and dignified in this picture.  She is "+
        "dressed exotically in the garb of a bard.  It is titled "+
        "Gwenhwyfar.",
     "painting 6" : "This painting shows an elf with hazel eyes "+
        "and black hair.  He wears the robes of a mage but also "+
        "has sheathed blades strapped to the parted robe.  "+
        "Likewise, he has sheaths strapped to his wrists.  It "+
        "is titled Renicus",
     "painting 7" : "This a picture of an amber-eyed, silver-"+
        "haired male elf of a small build.  He is dressed in a "+
        "white robe that is open wearing thin armor and with a "+
        "pair of crossing belts each holding a blade loosely in "+
        "it.  One blade is longer than the other apparently as "+
        "evidenced by the different sheaths.  He has his arms "+
        "crossed and is looking up.  It is titled Isaiah.",
     "painting 8" : "In this painting there is a perky looking "+
        "female halfling. She wears what appears to be a mage "+
        "robe and holds a bag of components in her hand.  She is "+
        "lean of build and has blue eyes with red hair.  She looks "+
        "eager and full of life, ready for adventure.  It is titled "+
        "Tara."
  ]));
//One exit to the temple one back outside
   set_exits(([
      "north" : "/d/magic/temples/mystra",
      "out"   : "/d/shadow/room/village/mainroad3"
   ]));
       set_temple("mystra");
}

void init()  
{	   
  ::init(); //touching the paintings activates them 
  add_action("touch","touch");
  
}

int touch(string str)
{
//if they try to touch the anything but the 8 paintings
//nothing happens
  if(str != "painting 1" && str != "painting 2" && str != "painting 3" && str != "painting 4" && str != "painting 5" && str != "painting 6" && str != "painting 7" && str != "painting 8"){
   tell_object(TP,"Touching that does nothing special.");
   return 1;
  }
  if(showing != 0){
     tell_object(TP,"Please let the current scene finish first.");
     return 1;
  }
  else{
      switch(str){
         case "painting 1":  showing = 1;
                             break;
         case "painting 2":  showing = 2;
                             break;
         case "painting 3":  showing = 3;
                             break;
         case "painting 4":  showing = 4;
                             break;
         case "painting 5":  showing = 5;
                             break;
         case "painting 6":  showing = 6;
                             break;
         case "painting 7":  showing = 7;
                             break;
         case "painting 8":  showing = 8;
                             break;
      }
   }
  tell_room(TO,""+TPQCN+" places a hand on the painting, and "+
          "the picture seems to come to life.",TP);
  tell_object(TP,"You place your hand on the painting and it comes "+
         "to life.");
  call_out("display_painting",3);
  return 1;
}

//Displays the painting to the room element by element until done
void display_painting()
{
  switch(showing)
 {
  case 1:  //first painting of slore
  {painting =({
"%^WHITE%^%^BOLD%^The painting %^RESET%^%^GREEN%^s%^BLUE%^w%^MAGENTA%^i%^RED%^r%^ORANGE%^l%^YELLOW%^s%^WHITE%^ about and the paint seems to reform itself on the parchment.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The colors streak into a very large firbolg holding a %^RESET%^%^RED%^massive hammer %^WHITE%^%^BOLD%^in both hands with ease.  He is wearing powerful armor that barely fits his bulging muscles.%^RESET%^\n",  
"%^WHITE%^%^BOLD%^A surprising thing happens: the firbolg in the painting swings the hammer effortlessly, crushing numerous opponents with one blow.  His strength is amazing.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The image fans out, and the half-elf from the painting defiantly faces the mighty firbolg.  He doesn't seem to be afraid of her, and %^RESET%^%^BLUE%^towers %^WHITE%^%^BOLD%^in comparison to the average looking half-elven woman.%^RESET%^\n",
"%^WHITE%^%^BOLD%^While the firbolg is standing there, the half-elf begins casting, and her finger glows with an %^RESET%^%^WHITE%^eerie light%^BOLD%^.  She touches the mighty firbolg, who %^BLACK%^pales %^WHITE%^to a sickly white.%^RESET%^\n",
"%^WHITE%^%^BOLD%^His soul is shown being torn from his body and whisked away to the afterlife.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The paint reforms into a completely different scene.  It becomes a depiction of the earlier half-elf in a %^BLACK%^dimly lit room%^WHITE%^ with other robed magic users.  All of them sit at a round table and wear cowls.  There are %^RESET%^%^BLUE%^shady looking%^WHITE%^%^BOLD%^ characters, and those that glow like heros of %^YELLOW%^light%^WHITE%^.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The half-elf woman is shown in the guild, protecting a young elven mage.  Someone sneaks in through the %^BLACK%^shadows%^WHITE%^, advancing upon them.%^RESET%^\n",
"%^WHITE%^%^BOLD%^A drow appears and quickly strikes down the guild's leader, running her through with a sharp %^BLACK%^black blade%^WHITE%^.%^RESET%^\n",
"%^WHITE%^%^BOLD%^She lays on the ground still... %^RESET%^%^RED%^blood %^WHITE%^%^BOLD%^pools on the floor around her.\n",
"%^WHITE%^%^BOLD%^Next it shows the same woman looking defeated, hanging up her cowl on a board and walking down the stairs, though the library and out of the guild.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The painting animates itself, and the guild members appear to be talking and sharing parchments with %^RESET%^%^MAGENTA%^runes %^WHITE%^%^BOLD%^written on them.  One by one all of the cowled mages blur out of the picture, until only a male half-elf bearing the holy symbol of %^RED%^Talos %^WHITE%^remains.%^RESET%^\n",
"%^WHITE%^%^BOLD%^This image holds for a long time, then %^RESET%^%^WHITE%^fades %^BOLD%^as the colours seep away, leaving the parchment blank.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The half-elf appears again, this time not wearing the cowl.  She is teaching young mages in a smaller temple, pointing them to the symbol of Mystra.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The female half-elf stays and the background changes to that of a city, where she continues to reprimand mages for their disrespect of magic.%^RESET%^\n",
"%^WHITE%^%^BOLD%^She speaks with great authority, often shouting at times, and the young mages take it to heart.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The painting then slowly swirls the ink back into it's original picture, of the female half-elf holding a book and teaching, and stays that way.%^RESET%^\n"});
 break;
 }
 case 2: //second one is trevize
 {painting = ({  
"%^WHITE%^%^BOLD%^The painting clears itself and reform into a picture of the knight, only looking much younger.%^RESET%^\n", 
"%^WHITE%^%^BOLD%^He travels along in the lands of Shadow, performing the deeds of a %^YELLOW%^true knight%^WHITE%^.  He slays orcs, gnolls and other mongrel races, and saves villagers who cannot protect themselves.%^RESET%^\n",
"%^WHITE%^%^BOLD%^It eventually shows him standing with other knights in the Order - the knights of old, all dressed in their best, with shining magical armor.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The paint swirls off into the frame leaving the canvas %^RESET%^%^WHITE%^blank%^BOLD%^.%^RESET%^\n",
"%^WHITE%^%^BOLD%^Slowly, a picture of the knight's, head is shown, covered in a helm so that all you can see are his %^RESET%^%^BLUE%^sad eyes%^WHITE%^%^BOLD%^.%^RESET%^\n",
"%^WHITE%^%^BOLD%^It zooms out, and the knight sets down his lance and his holy symbol of Tyr, and walks away from his knighthood to be something much simpler.%^RESET%^\n",
"%^WHITE%^%^BOLD%^This image holds for quite a few moments of the man: once a knight, now a mere swordsman.%^RESET%^\n",
"%^WHITE%^%^BOLD%^After the painting holds still for a while longer, it repaints itself, into the same swordsman kneeling before an altar with a large book on it.  A holy symbol of %^BLUE%^Mystra %^WHITE%^is around his neck now.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The next show him dressed again in the garb of a knight, but different; he is older and wiser than before.  He sits atop a great steed and carries a powerful looking lance.\n",
"%^WHITE%^%^BOLD%^Acolytes and other adventurers gather behind him, following his leadership.  His posture is good and he looks %^RESET%^%^RED%^proud %^WHITE%^%^BOLD%^to do what he does for Mystra.%^RESET%^\n",
"%^WHITE%^%^BOLD%^As the magic finishes, the painting returns to its original image.%^RESET%^\n"});
 break;
 }
 case 3: //Nicolya
 {painting = ({
"%^WHITE%^%^BOLD%^The painting starts out with the %^RESET%^%^ORANGE%^honey-eyed %^WHITE%^%^BOLD%^half-elf looking around confused.  She spends some time in one temple, then some time in another.%^RESET%^\n",
"%^WHITE%^%^BOLD%^This scene repeats itself a few times until it shows the her, bound and gaged with some wicked people looming over her.  There is shimmer as a %^BLUE%^magical-looking %^WHITE%^female figure appears and whisks away the woman from her captors.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The canvas clears and the image of the dancer fades into view, swirling around the altar of Mystra with a large book on it.  She dances on, and whisps of %^CYAN%^magic %^WHITE%^flit about her.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The image reforms, showing a Talossian knight raining havoc about the countryside, destroying everything in sight.  Eventually he levels his lance at Mystra's temple and begins charging.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The scene on the canvas reforms, to show the spell-dancer worriedly trying to make preparations to defend the temple.  A male half-elf cleric and his woman are with her.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The image of the temple reshapes to show the aftermath.  The female half-elf is sitting there, looking distraught, and the book that was on the alter is %^RESET%^%^RED%^burned%^WHITE%^%^BOLD%^ and ruined.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The woman continues in the temple of Mystra, dancing and standing up for the art to those in the city.%^RESET%^\n",
"%^WHITE%^%^BOLD%^It shows the woman sitting close to a grim looking human with a look of %^RED%^madness %^WHITE%^in his eyes.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The human draws an axe made from %^BLACK%^shadows %^WHITE%^and runs off, going beserk and hacking with it at anything in reach.%^RESET%^\n",
"%^WHITE%^%^BOLD%^It then shows the woman alone, sneaking into the temple at night.%^RESET%^\n",
"%^WHITE%^%^BOLD%^She grabs some items and sneaks out.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The items from the temple she uses to distroy the axe of %^BLACK%^shadow%^WHITE%^, a powerful relic.%^RESET%^\n",
"%^WHITE%^%^BOLD%^In next scene she leaves the temple.%^RESET%^\n",
"%^WHITE%^%^BOLD%^It shows a close-up of her, as she walks out.  She looks distraught, as though she had committed a great sin against Mystra, and no longer sees herself fit to serve.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The magic spent, the image settles and goes back to being a normal painting.%^RESET%^\n"});
 break;
 }
 case 4: //kirin & asalyr
 {painting = ({
"%^WHITE%^%^BOLD%^The painting begins with the two elves walking down a pathway, out of a gated human city towards the old temple of Mystra.%^RESET%^\n",
"%^WHITE%^%^BOLD%^They make their way into the temple, hand and hand, approaching the altar with a large book upon it.%^RESET%^\n",
"%^WHITE%^%^BOLD%^A priest comes out and they recite vows together at the altar, dedicating themselves to the service of Mystra.  It is a very %^RESET%^%^RED%^romantic %^WHITE%^%^BOLD%^picture.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The two stay together, working side by side in a lab in the next image.%^RESET%^\n",
"%^WHITE%^%^BOLD%^After that it shows them adventuring together, the male elf casting powerful spells, and the female both casting spells and using daggers with deadly precision.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The two of them appear to complement each other very well.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The painting turns for the worse though, when it shows the two elves parting ways, leaving the %^RED%^red-haired %^WHITE%^female alone and sad.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The next image shows her devoting herself entirely to her work.  It shows her in the lab surrounded by books and summoning circles within the %^YELLOW%^daylight %^WHITE%^hours.  The sun goes down and a %^RESET%^%^BLUE%^blue moon %^WHITE%^%^BOLD%^replaces it, and she is still there studying diligently, completely committed to her work.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The next image shows a great %^RED%^Balor %^WHITE%^attacking an elven village, and a group of adventurers standing against it.  There are two elves: one a slender female with %^BLUE%^sapphire eyes %^WHITE%^and %^BLACK%^long sable hair%^WHITE%^, the other a tattooed male with %^CYAN%^blue eyes %^WHITE%^and %^RESET%^%^ORANGE%^shoulder-length brown hair%^WHITE%^%^BOLD%^.%^RESET%^\n", 
"%^WHITE%^%^BOLD%^With them there is a human knight with %^RESET%^%^BLUE%^steel blue eyes%^WHITE%^%^BOLD%^, an %^RESET%^%^ORANGE%^amber-eyed%^WHITE%^%^BOLD%^ silver-haired elf, and a lean female woman of mixed heritage with %^CYAN%^sparkling azure eyes%^WHITE%^.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The gathered group of adventurers makes quick work of the powerful winged %^RED%^Balor%^WHITE%^, swords flashing and %^YELLOW%^lighting %^WHITE%^striking him down from the heavens.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The red-haired female elf stumbles upon the aftermath and discovers an elven mage who lays upon the ground, burnt completely.  A scorched scroll is next to him.%^RESET%^\n",
"%^WHITE%^%^BOLD%^She picks up the scroll and examines it closely for several moments.%^RESET%^\n",
"%^WHITE%^%^BOLD%^Her eyes open wide in shock; she gasps and tucks the scroll away.%^RESET%^\n",
"%^WHITE%^%^BOLD%^Later, the canvas shows the red-haired elf gasp, and dark runes of evil form upon the scorched scroll.%^RESET%^\n",
"%^WHITE%^%^BOLD%^She narrows her eyes as the evil magic reveals itself, the once-hidden runes now glowing an %^RESET%^%^RED%^angry red%^WHITE%^%^BOLD%^.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The scroll is given to the temple and an acolyte takes it, running off to the shadows.%^RESET%^\n",
"%^WHITE%^%^BOLD%^Color fades and reforms into the red-headed elf giving lessons of magic to other elves.  The one that stands out is a male elf with %^RESET%^%^ORANGE%^hazel eyes %^WHITE%^%^BOLD%^and %^BLACK%^black hair%^WHITE%^.%^RESET%^\n",
"%^WHITE%^%^BOLD%^She appears to be taking special interest in his teaching, still glancing at him while she speaks with the other elves nearby.%^RESET%^\n",
"%^WHITE%^%^BOLD%^Next it shows her alone with the same elf, who is somewhat quiet and subdued, as she teaches him how to cast spells on an open field.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The paints reform back to the original picture and stops moving around.%^RESET%^\n"});
 break;
 }
 case 5: //gwen
 {painting = ({									
"%^WHITE%^%^BOLD%^The painting shimmers and the depicted woman's age reverses itself,%^RESET%^\n", 
"%^WHITE%^%^BOLD%^slowly at first,%^RESET%^\n",
"%^WHITE%^%^BOLD%^she looks young, and younger%^RESET%^\n", 
"%^WHITE%^%^BOLD%^.   .   .   and younger.%^RESET%^\n",
"%^WHITE%^%^BOLD%^It stops when she's a beautiful baby girl in the arms of her mother.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The baby is taken away from her mother.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The painting again swirls again to show a good looking young woman of mixed heritage, setting out as a bard.  She keeps to the cities, and makes a name for herself as an entertainer.%^RESET%^\n",
"%^WHITE%^%^BOLD%^Next, the paints reform into her with several other half-elves, standing before a library in a bustling city.  The %^RESET%^%^RED%^auburn-haired %^WHITE%^%^BOLD%^woman seems pleased.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The paints re-arrange themselves to a main street, where the woman looks stricken as a building burns, along with the pile of books in front of it.  People scramble around in chaos, some running from the fire, and some trying to get water to put it out.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The bard is trying to gather books from the fire.  She gets her hair and clothing %^BLACK%^singed %^WHITE%^doing so, but manages to save some of the books of magic from destruction.%^RESET%^\n",
"%^WHITE%^%^BOLD%^Paint seeps back into the canvas and it shows the bard kneeling before the altar, with an older male human mage there before her.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The image reforms and it shows the bard with the same human from the last image.  He is holding a whip and crying out in pain.  He falls to the ground and drops the wicked looking whip.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The half-elven woman picks up the whip and runs off.  The painting fades.%^RESET%^\n",
"%^WHITE%^%^BOLD%^Next, the image reforms of the bardess chained to a wall, and a %^RED%^scarlet-haired %^WHITE%^human before her.%^RESET%^\n",
"%^WHITE%^%^BOLD%^He takes the whip from her and releases her.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The painting %^RESET%^%^WHITE%^darkens%^BOLD%^, and becomes an image of a group of adventures in a cave.  The half-elven bardess is with them.%^RESET%^\n",
"%^WHITE%^%^BOLD%^They travel downwards, and a white dragon jumps out from the %^BLACK%^shadows%^WHITE%^.  It exhales a breath of ice, as a white whirl that rushes at the group.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The whip is thrown into dragon's chilling breath and explodes, causing the whole cave to %^RESET%^%^BLUE%^shake %^WHITE%^%^BOLD%^in the painting.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The shaking stops and fades, leaving a %^RESET%^%^WHITE%^blank %^BOLD%^parchment.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The original painting slowly redraws itself, color by color.%^RESET%^\n"});
 break;
 }
 case 6: // renicus
 {painting = ({
"%^WHITE%^%^BOLD%^The %^BLACK%^black-haired %^WHITE%^elf in the painting begins to move.%^RESET%^\n",
"%^WHITE%^%^BOLD%^He looks to the left, then to the right.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The painting pans out and he beings to walk.  He battles hoards of orcs, goblins, and even drow alone, taking great risks but fighting with obvious skill.  He slashes with his short swords and hidden daggers, and fluidly integrating spellcraft into his fighting style.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The paint swirls away in a spiral and repaints the image of him with a %^RED%^red-haired %^WHITE%^female elf at night in the temple of Mystra.%^RESET%^\n",
"%^WHITE%^%^BOLD%^She smiles and talks to him, showing him scrolls and giving him lessons.%^RESET%^\n",
"%^WHITE%^%^BOLD%^Again the painting reforms, pausing a little while to signify that time passes.  It shows the male elf staring in awe at the altar of Mystra.  He looks surprised, as though he had just seen a ghost.%^RESET%^\n",
"%^WHITE%^%^BOLD%^It shows the male elf with a female elf, who has %^YELLOW%^long golden hair %^WHITE%^and is very beautiful.  They are holding hands.%^RESET%^\n",  
"%^WHITE%^%^BOLD%^There is another male elf there with silver hair and %^RESET%^%^ORANGE%^amber eyes%^WHITE%^%^BOLD%^, but the conversation is focussed upon the first two, a heated exchange between the %^BLACK%^black-haired %^WHITE%^elf and the female.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The next painting shows the same %^BLACK%^black-haired %^WHITE%^elf with a seven starred cloak, looking quite regal and official in it.  He is standing in the temple of Mystra looking like a great leader.%^RESET%^\n",
"%^WHITE%^%^BOLD%^Now that the images are finished, the paints mesh until it looks like the original picture.%^RESET%^\n"});
 break;
 }
 case 7: //isaiah
 {painting = ({
"%^WHITE%^%^BOLD%^The elf looks around from left to right as the painting animates itself.%^RESET%^\n",
"%^WHITE%^%^BOLD%^He looks sad, and the painting pans out.%^RESET%^\n", 
"%^WHITE%^%^BOLD%^When it's fully panned out, one can see the elf in a wooden house made from the living form of a tree.%^RESET%^\n",
"%^WHITE%^%^BOLD%^A %^RESET%^%^ORANGE%^honey-eyed %^WHITE%^%^BOLD%^female half-elf appears next to him through %^CYAN%^soft blue light%^WHITE%^.  She sits next to the broken elf, consoling and comforting him, her arm gently around his small shoulders.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The painting clears and reforms, showing the %^RESET%^%^ORANGE%^amber-eyed %^WHITE%^%^BOLD%^elf watching in silence as a newly knighted human with %^RESET%^%^BLUE%^steel blue eyes %^WHITE%^%^BOLD%^rides a horse down a main road.  He is wearing shining armor, and the peasants and onlookers watch in awe.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The elf walks up to the knight and they being to speak.%^RESET%^\n",  
"%^WHITE%^%^BOLD%^The elf seems to take great hope in what the knight is saying, often nodding eagerly.%^RESET%^\n",
"%^WHITE%^%^BOLD%^Again the painting fades and reforms, showing the two going back to the temple of Mystra, where a burnt book rests upon the altar.  The elf kneels down and dedicates himself to the cause of Mystra with the knight standing beside him.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The next picture shows two stricken elves, one the same male as before, and the other a tall beautiful female elf with %^RESET%^%^CYAN%^pale blue hair%^WHITE%^%^BOLD%^.%^RESET%^\n",  
"%^WHITE%^%^BOLD%^The pair frantically rush off down the road into the temple of Mystra.%^RESET%^\n",  
"%^WHITE%^%^BOLD%^What goes on inside isn't shown in detail.%^RESET%^\n",
"%^RED%^%^BOLD%^Blazing meteors %^WHITE%^rain down from outside to hit the temple, and the stone structure cracks and shatters with each of them.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The next image shows the male elf looking very sad.  He is back in his room and pouring over papers.  His eyes are bloodshot, as though he hasn't rested in a long time.%^RESET%^\n",
"%^WHITE%^%^BOLD%^After that, there is a depiction of stout-looking dwarves rebuilding the temple, hacking away at a very large slab of marble.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The painting then shows the new temple in all its brilliance, larger and more elaborate then the last.  It has an impressive dome at the top.%^RESET%^\n",
"%^WHITE%^%^BOLD%^Another image paints itself, one of a group of adventurers: many elves, a half-elf, a human and a voadkyn.  They step through a portal and re-appear in the %^RESET%^%^RED%^burning waste %^WHITE%^%^BOLD%^of a different dimension.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The group battles their way through the vile place, slaying the powerful female drow and the old male human who oppose them.%^RESET%^\n",
"%^WHITE%^%^BOLD%^They fight a great demon and kill him also, though the battle is fierce.  A %^RESET%^%^WHITE%^white-haired %^BOLD%^ranger and another old male human, identical to the first, are taken from a cell filled with instruments of torture.%^RESET%^\n",
"%^WHITE%^%^BOLD%^Together the group drags the unconscious pair though a portal, reappearing back in the temple of Mystra.%^RESET%^\n",
"%^WHITE%^%^BOLD%^Now that the magic is finished the painting goes back to its static form.%^RESET%^\n"});
 break;
 }
 case 8: //tara
 {painting = ({
"%^WHITE%^%^BOLD%^The painting shimmers and changes, showing the little halfling in action.  She goes into a gloomy chamber, with an evil-looking mage that is wearing an amulet.%^RESET%^\n",
"%^WHITE%^%^BOLD%^She draws daggers, one in each hand and slashes him from many different directions.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The %^BLACK%^dark mage %^WHITE%^winces and pales after receiving some very critical looking blows.%^RESET%^\n",
"%^WHITE%^%^BOLD%^He casts magic at her but she cries out and continues to attack, the magic disperses harmlessly and she launches a strike from behind the mage.%^RESET%^\n",
"%^WHITE%^%^BOLD%^He falls to the ground; the corrupt user of magic lays dead at her feet.%^RESET%^\n",
"%^WHITE%^%^BOLD%^Next, it shows the female halfling meeting with an old human in the robes of a mage.  Two elves are with her.  The old mage speaks, and the elves get grim looks upon their faces.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The halfling just smiles and shrugs it off.  She jumps up and heads out, ready to tackle the task head on.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The next scene on the parchment shows the halfling with a %^RESET%^%^ORANGE%^brown-haired %^WHITE%^%^BOLD%^human who is working at a forge.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The halfling hands him some %^RESET%^%^WHITE%^glittering white dust%^BOLD%^, and he continues at his work.%^RESET%^\n",
"%^WHITE%^%^BOLD%^The paints swirl away and show the halfling smiling, as the old male human holds up a diamond-tipped dagger, shimmering with magical power.%^RESET%^\n",
"%^WHITE%^%^BOLD%^Now that the magic is done the painting goes back to the original picture.%^RESET%^\n"});
 break;
 }
 default : return;
 }
// display the array to the room line by line
  tell_room(TO,painting[scene]);
  scene++;
    if(sizeof(painting) == scene) {
        showing = 0;
        scene = 0;
        return; //it increments after the last element so should be equal to the last element
    }
    else {
        call_out("display_painting",6);
    }
}
