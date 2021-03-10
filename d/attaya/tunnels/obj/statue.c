#include <std.h>
#include "../tunnel.h"

#define MATERIALS ({"%^BOLD%^%^WHITE%^ivory%^RESET%^",\
"%^BOLD%^%^GREEN%^jade%^RESET%^",\
"%^BOLD%^%^RED%^ruby%^RESET%^",\
"%^RED%^garnet%^RESET%^",\
"%^MAGENTA%^amethyst%^RESET%^",\
"%^ORANGE%^topaz%^RESET%^",\
"%^BOLD%^%^BLACK%^ebony%^RESET%^",\
"%^BOLD%^%^WHITE%^o%^CYAN%^p%^WHITE%^a%^MAGENTA%^l%^RESET%^",\
"%^ORANGE%^amber%^RESET%^",\
"%^BOLD%^%^WHITE%^cr%^CYAN%^y%^WHITE%^stal%^RESET%^"})

#define SUBJECTS ({"human",\
"elf",\
"halfling",\
"half-elf",\
"knight",\
"warrior",\
"mage",\
"soldier",\
"elven mage",\
"great orator",\
"noble",\
"sorceror",\
"priest",\
"barbarian"})

inherit OBJECT;

void create()
{
  int i,j, val;
  string subject, material, adjective;
  ::create();
  i=random(sizeof(MATERIALS));
  material = MATERIALS[i];
  j=random(sizeof(SUBJECTS));
  subject = SUBJECTS[j];
  val = random(4000);
  if (val>2000){val += random(6000);}
  switch (val){
  case 0..1000:
    adjective = "nice";
    break;
  case 1001..2000:
    adjective = "decorative";
    break;
  case 2001..3000:
    adjective = "exotic";
    break;
  case 3001..4000:
    adjective = "beautiful";
    break;
  case 4001..5000:
    adjective = "wonderful";
    break;
  case 5001..10000:
    adjective = "fabulous";
    break;
  }
  set_id(({"statue"}));
  set_name("statue");
  set_weight(5);
  if (subject[0] =='a'||subject[0] =='e'||subject[0] =='i'
                      ||subject[0] =='o'||subject[0] =='u'){
    set_short("%^RESET%^%^GREEN%^" + adjective +" "+ material 
             + "%^GREEN%^"+" statue of an " + subject);
  }
  else{
    set_short("%^RESET%^%^GREEN%^" + adjective +" "+ material 
             + "%^GREEN%^"+" statue of a " + subject);
  }
  switch(subject) {
  case "human":
    set_long("A nicely executed sculpture of an individual human. The"
            +" sculptor was clearly very accomplished and has captured an"
            +" interesting, somewhat wistful expression on the subject's"
            +" face.");
    break;
  case "elf":
    if (material=="ebony"){
      subject = "%^BOLD%^%^BLACK%^drow%^RESET%^";
      set_long("This %^BOLD%^%^BLACK%^ebony sculpture is frighteningly"
              +" accurate. The %^BOLD%^%^BLACK%^drow's%^RESET%^ features"
              +" are entirely elf-like, but there is a cruel cast to them"
              +" that belies their surface beauty");
      break;
    }
    set_long("The %^GREEN%^e%^BOLD%^%^GREEN%^lf%^RESET%^ carries a"
            +" %^ORANGE%^bow%^RESET%^ and appears to be looking a long"
            +" way off in the distance. The sculptor has managed to give"
            +" the figure a posture of %^BOLD%^%^BLUE%^grace%^RESET%^ and"
            +" %^MAGENTA%^balance%^RESET%^, and to convey something of"
            +" the beauty of the %^GREEN%^e%^BOLD%^%^GREEN%^lv%^RESET%^"
            +"%^GREEN%^es%^RESET%^.");
    break;
  case "halfling":
    set_long("The statue is, naturally, not very large. The halfling is"
            +" carrying a %^YELLOW%^short sword%^RESET%^ in one hand and"
            +" a mug of %^ORANGE%^ale%^RESET%^ in the other. A few"
            +" %^MAGENTA%^bulges%^RESET%^ in the figure's clothing"
            +" suggest that there might be various %^BOLD%^"
            +"%^BLUE%^valuables%^RESET%^ secreted about its person.");
    break;
  case "half-elf":
    set_long("The half-elf appears to be %^MAGENTA%^d%^BOLD%^%^MAGENTA%^a"
            +"%^RESET%^%^MAGENTA%^ncing%^RESET%^, or possibly"
            +" %^RED%^fighting%^RESET%^, though there is no weapon in"
            +" sight. Its posture is extended and it appears balanced on"
            +" the ball of one foot, the other leg lifting behind it as"
            +" its arms reach up toward the %^BOLD%^%^CYAN%^s%^BOLD%^"
            +"%^WHITE%^k%^CYAN%^y%^RESET%^.");
    break;
  case "knight":
    set_long("The %^BOLD%^%^BLUE%^knight%^RESET%^ is sitting atop a proud"
            +" %^BOLD%^%^WHITE%^war horse%^RESET%^, which appears to be"
            +" pawing at the ground, its head slightly bowed. The knight,"
            +" however is sitting up straight, %^YELLOW%^lance%^RESET%^"
            +" held upright, with a %^BOLD%^%^BLUE%^pennant%^RESET%^ at"
            +" the end appearing to be snapping in the wind. Both knight"
            +" and mount are heavily armoured and the knight's face is"
            +" hidden behind the closed %^BOLD%^%^GREEN%^visor of its"
            +" helmet");
    break;
  case "warrior":
    set_long("A statue of a bold %^BOLD%^%^RED%^warrior%^RESET%^, weapons"
            +" drawn and standing in a half-crouch, ready for %^BOLD%^"
            +"%^RED%^battle%^RESET%^. The figure's %^MAGENTA%^musculature"
            +"%^RESET%^ and %^BOLD%^%^BLUE%^equipment%^RESET%^ are"
            +" wonderfully detailed and it is clear that this statue is a"
            +" work of art. Though of course, not everyone has the same"
            +" tastes.");
    break;
  case "mage":
    set_long("This figure's face is completed in great detail. The"
            +" %^MAGENTA%^mage%^RESET%^ stands tall, with a"
            +" %^ORANGE%^book%^RESET%^ in one hand, while the other hand"
            +" is raised in an %^GREEN%^a%^BOLD%^%^GREEN%^rc%^RESET%^"
            +"%^GREEN%^a%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^e%^RESET%^"
            +" gesture. The story of the piece, however, is conveyed in"
            +" the figures %^BOLD%^%^WHITE%^e%^BLUE%^ye%^WHITE%^s"
            +"%^RESET%^, which somehow hold decades of %^BLUE%^learning"
            +"%^RESET%^ and %^MAGENTA%^knowledge%^RESET%^, great %^BOLD%^"
            +"%^BLUE%^power%^RESET%^, but also great %^GREEN%^sadness"
            +"%^RESET%^.");    
    break;
  case "soldier":
    set_long("The %^BOLD%^%^RED%^soldier%^RESET%^ appears to be well"
            +" equipped and well trained. He is standing to"
            +" %^YELLOW%^attention%^RESET%^ and presenting arms, as at"
            +" some form of inspection. He wears a half face helmet, and"
            +" the %^MAGENTA%^grim%^RESET%^ set of his face can be seen");    
    break;
  case "elven mage":
    set_long("The %^GREEN%^e%^BOLD%^%^GREEN%^lf%^RESET%^ wears a %^BOLD%^"
            +"%^WHITE%^c%^CYAN%^i%^WHITE%^rclet%^RESET%^, with a"
            +" %^MAGENTA%^g%^RED%^e%^MAGENTA%^m%^RESET%^ set boldy in its"
            +" front. The figure is clearly engaged in %^GREEN%^spell"
            +"-casting%^RESET%^, with wide eyes and slightly parted lips"
            +" as an %^CYAN%^incantation%^RESET%^ is completed. Deft,"
            +" slender hands are held out in front, with a %^BOLD%^"
            +"%^BLUE%^sorcerous%^RESET%^ gesture shown clearly by the"
            +" sculptor's talents");    
    break;
  case "great orator":
    set_long("This is a statue of a figure standing at a"
            +" %^ORANGE%^lectern%^RESET%^, both hands gripping the edges"
            +" of the %^BOLD%^%^BLACK%^plate%^RESET%^ as it appears to be"
            +" addressing a great %^BOLD%^%^BLUE%^crowd%^RESET%^. The"
            +" figure's posture manages to portray passion, commitment"
            +" and also great %^MAGENTA%^dignity%^RESET%^. The"
            +" artist who made this piece is clearly a master sculptor");    
    break;
  case "noble":
    set_long("A statue of a figure dressed in %^MAGENTA%^f%^RED%^i"
            +"%^MAGENTA%^ne r%^RED%^o%^MAGENTA%^bes%^RESET%^ and carrying"
             +" %^BOLD%^%^RED%^regal%^RESET%^ accoutrements. The face"
             +"looks implausibly %^BOLD%^%^CYAN%^young%^RESET%^ and"
             +" %^MAGENTA%^b%^BOLD%^%^BLUE%^eau%^RESET%^%^MAGENTA%^t"
             +"%^BOLD%^%^BLUE%^i%^RESET%^%^MAGENTA%^f%^BOLD%^%^BLUE%^u"
             +"%^RESET%^%^MAGENTA%^l%^RESET%^, with smooth unlined skin"
             +"and wornderfully proportioned features. It makes you"
             +" wonder who was paying the sculptor's wages at the time.");    
    break;
  case "sorceror":
    set_long("A sculpture of a %^GREEN%^s%^BOLD%^%^GREEN%^o%^RESET%^"
            +"%^GREEN%^rc%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^r%^BOLD%^"
            +"%^GREEN%^o%^RESET%^%^GREEN%^r%^RESET%^ standing before a"
            +" great %^BOLD%^%^BLACK%^c%^RESET%^a%^BOLD%^%^BLACK%^uldron"
            +"%^RESET%^. The work is so exacting that you can make out"
            +" the texture of the %^BOLD%^%^BLUE%^l%^CYAN%^i%^BLUE%^qu"
            +"%^CYAN%^i%^BLUE%^d %^RESET%^%^RED%^b%^BOLD%^%^RED%^o"
            +"%^RESET%^%^RED%^il%^BOLD%^%^RED%^i%^RESET%^%^RED%^ng"
            +"%^RESET%^ in the cauldron.");    
    break;
  case "priest":
    set_long("A sculpture of a %^BOLD%^%^BLUE%^priest%^RESET%^ engaged in"
            +" some form of %^MAGENTA%^devotion%^RESET%^. The worship and"
            +" adoration is clearly visible on the figure's face. Eyes"
            +" turn towards the %^YELLOW%^holy symbol%^RESET%^ held in"
            +" its hands, and its posture is one of %^GREEN%^supplication"
            +"%^RESET%^");    
    break;
  case "barbarian":
    set_long("This statue is of a %^BOLD%^%^CYAN%^wild%^RESET%^ looking"
            +" figure dressed in %^ORANGE%^furs%^RESET%^ and"
            +" %^ORANGE%^leather%^RESET%^, with %^BOLD%^%^WHITE%^bushy"
            +" hair%^RESET%^ and wide, %^BOLD%^%^GREEN%^fierce%^RESET%^"
            +" eyes. An axe is held in one hand and a great round"
            +" %^ORANGE%^wooden shield%^RESET%^ is worn on the"
            +" other arm. The figure wears large boots with tufted fur"
            +" lining sprouting from the top.");    
    break;

  default:               
    set_long("This is a statue. Big deal, huh? What does art, or beauty,"
            +" matter to you?");
  }
  if(val < 500) {
    set_value(500);
  }
  else {
    set_value(val);
  }

}
