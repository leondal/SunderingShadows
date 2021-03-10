//random instrument generator for Riddle Quest.  Circe 2/6/04
#include <std.h>

#define KINDS ({"lute","lyre","fiddle","flute","mandolin","lap-harp","drum","tabor"})
#define WOODS ({"light oak","maple","mahogany","birch","pine"})

inherit DAEMON;

int j, k, val;
string str, TYPE;


void create_instrument(object obj){
   j = random(sizeof(KINDS));
       str = KINDS[j];
   k = random(sizeof(WOODS));
       TYPE = WOODS[k];
   obj->set_name("instrument");
   switch(j) {
      case 0:
         obj->set_long("This simple "+TYPE+" instrument has a pear-shaped body "+
            "fitted with a distinctive bent neck.  The neck has frets "+
            "for fingering, and six strings stretch along the "+
            "neck, attaching to wooden pegs.  This lute is about 32 "+
            "inches long, although most of that length is taken up by "+
            "the large, rounded bowl.  The instrument can be strummed "+
            "or plucked to create an enormous variety of notes and "+
            "inflections.  It has a rich, full sound.  A string of writing "+
            "has been engraved along the neck.");
         break;
      case 1:
         obj->set_long("A predecessor to the lap-harp, this lyre is made "+
            "from a turtle shell fitted with two curved "+TYPE+" arms and a "+
            "crossbar holding six gut strings taut.  All a "+
            "musician must do to play the lyre is hold it in one "+
            "hand while strumming or plucking the strings with the "+
            "other.  Even a novice can strum a lyre to wonderful effect.  "+
            "A message has been carved into the crossbar.");
         break;
      case 2:
         obj->set_long("This "+TYPE+" instrument is small and portable "+
            "with strings stretched over an hourglass body.  The "+
            "fiddle has five strings made of gut that are "+
            "anchored at the top of a long thin neck by pegs.  The "+
            "fiddle is played by drawing a bow - which is a long, "+
            "thin piece of wood fitted with fine strands of "+
            "animal hair - across the strings.  The fiddle produces "+
            "lively music often used for dancing.  Along the neck "+
            "a short message has been burned into the wood.");
         break;
      case 3:
         obj->set_long("This small wooden instrument is a thin, hollow "+
            "wooden tube drilled with six fingerholes.  It is made to be "+
            "held at a right angle to the lips, and air is blown across a "+
            "small opening.  The fingerholes can be covered or "+
            "uncovered to produce a variety of different notes, all of "+
            "which have a light, airy quality.  This flute is about a "+
            "foot and a half long and is made of "+TYPE+".  A brief "+
            "message has been engraved into the wood.");
         break;
      case 4:
         obj->set_long("A smaller version of the lute, the mandolin is "+
            "less than 2 feet long and has a very round body.  It is "+
            "fitted with twelve streams which are placed very close "+
            "together.  It lacks the lute's distinctive bent neck, and "+
            "it produces a much sweeter, higher-pitched sound.  A "+
            "mandolin is usually played with a pick - both to protect "+
            "the musician's fingers and to allow accurate plucking of "+
            "the strings.  Along the neck, a short message has been written.");
         break;
      case 5:
         obj->set_long("Intricately carved, this lap-harp is fitted "+
            "with seventeen wires, all made of silver.  The light "+TYPE+" "+
            "of this lap-harp has been highly polished so that the "+
            "scrollwork carvings shine.  The harp is about two "+
            "and a half feet tall and a little over a foot wide.  It "+
            "is played by the musician strumming his fingers across "+
            "the silver wires, which produces a gentle, rippling melody.  "+
            "A message has been carved in an elegant script beneath the strings.");
         break;
      case 6:
         obj->set_long("A simple instrument, this drum was formed by "+
            "stretching a tanned skin across the opening of the "+
            ""+TYPE+" pot.  The drum may be struck with padded "+
            "mallets or with the musician's fingers, creating a booming "+
            "sound.  Just beneath the drum head is a message.");
         break;
      default:
         obj->set_long("This specialized "+TYPE+" drum hangs from a leather "+
            "strap worn across the musician's chest.  The drum is "+
            "roughly one foot in diameter and about two feet long.  "+
            "Both ends are stretched with tanned skin, and the bottom drum "+
            "head has bands of gut stretched across it, which gives the "+
            "drum a distinctive rattle.  The tabor is light enough to "+
            "wear comfortably, and it is easily played "+
            "by tapping the top drumhead with the fingers.  Burned into "+
            "the strap is a short message.");
         break;
      }
   obj->set_value(0);
   obj->set_read("%^BOLD%^%^WHITE%^You may %^CYAN%^<%^WHITE%^play%^CYAN%^> %^WHITE%^this instrument to create a bright light.%^RESET%^");
   obj->set_lore("This instrument possesses strange powers.  Several "+
       "such instruments have been seen around the realms over the "+
       "years, each one unique though they share certain "+
       "characteristics.  They are said to hold power over "+
       "beasts and bring light to those who need it.");
   obj->set_property("lore difficulty",12);
   obj->set_name("bard instrument");
   obj->set_weight(4);
   obj->set_short("A "+TYPE+" "+str+"");
   obj->set_id(({"instrument","wooden instrument",""+TYPE+" "+str+"",""+str+""}));
}
