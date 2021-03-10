#include <std.h>
#include "../seneca.h"

inherit MONSTER;

#define TOYS ({"%^RESET%^%^ORANGE%^teddy bear%^RESET%^%^CYAN%^","%^BOLD%^%^WHITE%^stuffed animal%^RESET%^%^CYAN%^","%^BOLD%^%^CYAN%^toy doll%^RESET%^%^CYAN%^","%^BOLD%^%^RED%^b%^YELLOW%^a%^RED%^l%^YELLOW%^l%^RESET%^%^CYAN%^","%^BOLD%^%^BLACK%^jump rope%^RESET%^%^CYAN%^","%^BOLD%^%^RED%^puppet%^RESET%^%^CYAN%^","%^RESET%^box of %^RED%^%^BOLD%^c%^BLUE%^o%^GREEN%^l%^YELLOW%^o%^GREEN%^r%^BLUE%^e%^RED%^d %^RESET%^blocks%^RESET%^%^CYAN%^"})

#define EYECOLOR ({"%^BOLD%^%^GREEN%^emerald%^RESET%^%^CYAN%^","%^BOLD%^%^CYAN%^sapphire%^RESET%^%^CYAN%^","%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^z%^BOLD%^u%^RESET%^%^CYAN%^r%^BOLD%^e%^RESET%^%^CYAN%^","%^RESET%^%^CYAN%^cyan%^RESET%^%^CYAN%^","%^BOLD%^%^BLACK%^s%^RESET%^%^RED%^a%^ORANGE%^b%^BOLD%^%^BLACK%^le%^RESET%^%^CYAN%^","%^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^h%^RESET%^o%^ORANGE%^col%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^te%^RESET%^%^CYAN%^","%^RESET%^%^ORANGE%^coffee%^RESET%^%^CYAN%^","%^RESET%^%^GREEN%^green%^RESET%^%^CYAN%^","%^RESET%^%^ORANGE%^h%^GREEN%^a%^BOLD%^%^BLACK%^z%^RESET%^%^GREEN%^e%^ORANGE%^l%^RESET%^%^CYAN%^","%^RESET%^%^ORANGE%^brown%^RESET%^%^CYAN%^","%^BOLD%^%^BLUE%^blue%^RESET%^%^CYAN%^","%^RESET%^gray%^RESET%^%^CYAN%^"})

#define CLOTHES ({"%^BOLD%^%^BLACK%^s%^RESET%^%^RED%^a%^ORANGE%^b%^BOLD%^%^BLACK%^le%^RESET%^%^CYAN%^","%^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^h%^RESET%^o%^ORANGE%^col%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^te%^RESET%^%^CYAN%^","%^BOLD%^%^GREEN%^green%^RESET%^%^CYAN%^","%^RESET%^%^ORANGE%^brown%^RESET%^%^CYAN%^","%^BOLD%^%^BLUE%^blue%^RESET%^%^CYAN%^","%^RESET%^gray%^RESET%^%^CYAN%^","%^BOLD%^%^RED%^scarlet%^RESET%^%^CYAN%^","%^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^","%^RESET%^%^ORANGE%^brown%^RESET%^%^CYAN%^","%^YELLOW%^yellow%^RESET%^%^CYAN%^","%^RESET%^%^RED%^red%^RESET%^%^CYAN%^","%^BOLD%^%^WHITE%^white%^RESET%^%^CYAN%^"})

#define DESIGNS ({"%^RESET%^d%^CYAN%^o%^BOLD%^%^BLUE%^l%^RESET%^ph%^CYAN%^i%^RESET%^n%^RESET%^%^CYAN%^",\
"%^RESET%^%^GREEN%^s%^CYAN%^e%^GREEN%^ah%^BLUE%^o%^CYAN%^r%^GREEN%^se%^RESET%^%^CYAN%^",\
"%^YELLOW%^%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld f%^RESET%^%^ORANGE%^i%^YELLOW%^sh%^RESET%^%^CYAN%^",\
"%^BOLD%^%^WHITE%^swan%^RESET%^%^CYAN%^",\
"%^BOLD%^%^GREEN%^p%^YELLOW%^a%^RED%^r%^GREEN%^rot%^RESET%^%^CYAN%^",\
"%^BOLD%^%^RED%^robin%^RESET%^%^CYAN%^",\
"%^RESET%^%^ORANGE%^p%^WHITE%^u%^ORANGE%^ppy d%^WHITE%^o%^ORANGE%^g%^RESET%^%^CYAN%^",\
"%^RESET%^%^ORANGE%^k%^BOLD%^%^BLACK%^i%^YELLOW%^t%^RESET%^%^ORANGE%^ty%^RESET%^%^CYAN%^",\
"%^RESET%^%^ORANGE%^horse%^RESET%^%^CYAN%^",\
"%^BOLD%^%^MAGENTA%^b%^WHITE%^u%^YELLOW%^t%^MAGENTA%^te%^WHITE%^r%^YELLOW%^f%^MAGENTA%^ly%^RESET%^%^CYAN%^",\
"%^BOLD%^%^GREEN%^d%^BLUE%^r%^RESET%^%^CYAN%^a%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^o%^CYAN%^n%^BOLD%^%^BLUE%^f%^GREEN%^ly%^RESET%^%^CYAN%^",\
"%^YELLOW%^b%^BLACK%^u%^YELLOW%^mb%^BLACK%^l%^YELLOW%^e b%^BLACK%^e%^YELLOW%^e%^RESET%^%^CYAN%^",\
"%^BOLD%^%^MAGENTA%^flower%^RESET%^%^CYAN%^",\
"%^BOLD%^%^RED%^rose%^RESET%^%^CYAN%^",\
"%^YELLOW%^daisy%^RESET%^%^CYAN%^",\
"%^RESET%^%^MAGENTA%^tulip%^RESET%^%^CYAN%^",\
"%^BOLD%^%^WHITE%^star%^RESET%^%^CYAN%^",\
"%^RESET%^%^GREEN%^lizard%^RESET%^%^CYAN%^",\
"%^BOLD%^%^GREEN%^f%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^o%^GREEN%^g%^RESET%^%^CYAN%^",\
"%^BOLD%^%^BLACK%^w%^RESET%^o%^BOLD%^%^BLACK%^lf%^RESET%^%^CYAN%^",\
"%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^g%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^r%^RESET%^%^CYAN%^",\
"%^BOLD%^%^WHITE%^z%^BLACK%^e%^WHITE%^b%^BLACK%^r%^WHITE%^a%^RESET%^%^CYAN%^",\
"%^BOLD%^%^YELLOW%^gi%^RESET%^%^ORANGE%^r%^YELLOW%^a%^RESET%^%^ORANGE%^f%^YELLOW%^fe%^RESET%^%^CYAN%^",\
"%^RESET%^%^ORANGE%^squirrel%^RESET%^%^CYAN%^",\
"%^BOLD%^%^WHITE%^bunny%^RESET%^%^CYAN%^",\
"%^RESET%^%^ORANGE%^deer%^RESET%^%^CYAN%^"})

#define HAIRSTYLE ({"curly","wavy","straight","thin","thick","kinky"})

#define HAIRCOLOR ({"%^BOLD%^%^BLACK%^ebony%^RESET%^%^CYAN%^","%^YELLOW%^golden%^RESET%^%^CYAN%^","%^BOLD%^%^BLACK%^s%^RESET%^%^RED%^a%^ORANGE%^b%^BOLD%^%^BLACK%^le%^RESET%^%^CYAN%^","%^RESET%^%^RED%^a%^MAGENTA%^u%^BOLD%^%^BLACK%^b%^RESET%^%^RED%^ur%^BOLD%^%^BLACK%^n%^RESET%^%^CYAN%^","%^BOLD%^%^RED%^scarlet%^RESET%^%^CYAN%^","%^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^","%^RESET%^%^ORANGE%^brown%^RESET%^%^CYAN%^","%^YELLOW%^b%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^n%^YELLOW%^d%^RESET%^%^ORANGE%^e%^RESET%^%^CYAN%^","%^RESET%^%^RED%^red%^RESET%^%^CYAN%^"})

#define HAIRLENGTH ({"neck","shoulder","waist","hip","knee"})

void create(){
string TOY,EYES,CLOTH,DESIGN,HAIR,HAIRC,LENGTH;
   ::create();
   TOY = TOYS[random(sizeof(TOYS))];
   EYES = EYECOLOR[random(sizeof(EYECOLOR))];
   CLOTH = CLOTHES[random(sizeof(CLOTHES))];
   DESIGN = DESIGNS[random(sizeof(DESIGNS))];
   HAIR = HAIRSTYLE[random(sizeof(HAIRSTYLE))];
   HAIRC = HAIRCOLOR[random(sizeof(HAIRCOLOR))];
   LENGTH = HAIRLENGTH[random(sizeof(HAIRLENGTH))];
   set_name("a little girl");
   set_short("%^RESET%^%^CYAN%^A little girl with "+EYES+" eyes and "+HAIRC+" hair%^RESET%^");
   set_id(({"girl","little girl","orphan","girl orphan"}));
   set_long("%^RESET%^%^CYAN%^Holding a "+TOY+" close, this little "+
      "girl looks at you with wide, expressive "+EYES+" eyes.  Her "+
      "small nose is a little dirty and you notice that her "+CLOTH+" "+
      "dress has signs of being patched, but someone has taken the "+
      "time to sew pretty little "+DESIGN+" designs over the patches.  A "+
      "mop of "+HAIR+" "+HAIRC+" hair crowns her head and falls "+
      "down to "+LENGTH+"-length, where it is held back by a "+
      ""+CLOTH+" ribbon.  Small, scuff-toed shoes adorn her feet, "+
      "and a lightweight "+CLOTH+" smock hangs open, giving her a "+
      "little more warmth as she capers about.%^RESET%^");
   set_gender("female");
   set_race("human");
   set_hd(1,5);
   set_exp(1);
   set_emotes(4,({
	"The young girl skips about in circles.",
	"The young girl rubs her sleepy eyes.",
	"The young girl's eyes study you for a moment before returning to her toy."
   }),0);
}
