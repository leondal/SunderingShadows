#include <std.h>
#include "../seneca.h"

inherit MONSTER;

#define TOYS ({"%^RESET%^%^ORANGE%^teddy bear%^RESET%^%^CYAN%^","%^BOLD%^%^WHITE%^stuffed animal%^RESET%^%^CYAN%^","%^BOLD%^%^CYAN%^toy doll%^RESET%^%^CYAN%^","%^BOLD%^%^RED%^b%^YELLOW%^a%^RED%^l%^YELLOW%^l%^RESET%^%^CYAN%^","%^BOLD%^%^BLACK%^jump rope%^RESET%^%^CYAN%^","%^BOLD%^%^RED%^puppet%^RESET%^%^CYAN%^","%^RESET%^box of %^RED%^%^BOLD%^c%^BLUE%^o%^GREEN%^l%^YELLOW%^o%^GREEN%^r%^BLUE%^e%^RED%^d %^RESET%^blocks%^RESET%^%^CYAN%^"})

#define EYECOLOR ({"%^BOLD%^%^GREEN%^emerald%^RESET%^%^CYAN%^","%^BOLD%^%^CYAN%^sapphire%^RESET%^%^CYAN%^","%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^z%^BOLD%^u%^RESET%^%^CYAN%^r%^BOLD%^e%^RESET%^%^CYAN%^","%^RESET%^%^CYAN%^cyan%^RESET%^%^CYAN%^","%^BOLD%^%^BLACK%^s%^RESET%^%^RED%^a%^ORANGE%^b%^BOLD%^%^BLACK%^le%^RESET%^%^CYAN%^","%^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^h%^RESET%^o%^ORANGE%^col%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^te%^RESET%^%^CYAN%^","%^RESET%^%^ORANGE%^coffee%^RESET%^%^CYAN%^","%^RESET%^%^GREEN%^green%^RESET%^%^CYAN%^","%^RESET%^%^ORANGE%^h%^GREEN%^a%^BOLD%^%^BLACK%^z%^RESET%^%^GREEN%^e%^ORANGE%^l%^RESET%^%^CYAN%^","%^RESET%^%^ORANGE%^brown%^RESET%^%^CYAN%^","%^BOLD%^%^BLUE%^blue%^RESET%^%^CYAN%^","%^RESET%^gray%^RESET%^%^CYAN%^"})

#define CLOTHES ({"%^BOLD%^%^BLACK%^s%^RESET%^%^RED%^a%^ORANGE%^b%^BOLD%^%^BLACK%^le%^RESET%^%^CYAN%^","%^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^h%^RESET%^o%^ORANGE%^col%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^te%^RESET%^%^CYAN%^","%^BOLD%^%^GREEN%^green%^RESET%^%^CYAN%^","%^RESET%^%^ORANGE%^brown%^RESET%^%^CYAN%^","%^BOLD%^%^BLUE%^blue%^RESET%^%^CYAN%^","%^RESET%^gray%^RESET%^%^CYAN%^","%^BOLD%^%^RED%^scarlet%^RESET%^%^CYAN%^","%^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^","%^RESET%^%^ORANGE%^brown%^RESET%^%^CYAN%^","%^YELLOW%^yellow%^RESET%^%^CYAN%^","%^RESET%^%^RED%^red%^RESET%^%^CYAN%^","%^BOLD%^%^WHITE%^white%^RESET%^%^CYAN%^"})

#define HAIRSTYLE ({"curly","wavy","straight","thin","thick","kinky"})

#define HAIRCOLOR ({"%^BOLD%^%^BLACK%^ebony%^RESET%^%^CYAN%^","%^YELLOW%^golden%^RESET%^%^CYAN%^","%^BOLD%^%^BLACK%^s%^RESET%^%^RED%^a%^ORANGE%^b%^BOLD%^%^BLACK%^le%^RESET%^%^CYAN%^","%^RESET%^%^RED%^a%^MAGENTA%^u%^BOLD%^%^BLACK%^b%^RESET%^%^RED%^ur%^BOLD%^%^BLACK%^n%^RESET%^%^CYAN%^","%^BOLD%^%^RED%^scarlet%^RESET%^%^CYAN%^","%^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^","%^RESET%^%^ORANGE%^brown%^RESET%^%^CYAN%^","%^YELLOW%^b%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^n%^YELLOW%^d%^RESET%^%^ORANGE%^e%^RESET%^%^CYAN%^","%^RESET%^%^RED%^red%^RESET%^%^CYAN%^"})

#define HAIRA ({"tumbles about his head","is held back with a leather tie","is kept out of his eyes with a leather headband","lays flat against his head","falls to his shoulders","covers most of his face"})

void create(){
string TOY,EYES,CLOTH,HAIR,HAIRC,HAIRDO;
   ::create();
   TOY = TOYS[random(sizeof(TOYS))];
   EYES = EYECOLOR[random(sizeof(EYECOLOR))];
   CLOTH = CLOTHES[random(sizeof(CLOTHES))];
   HAIR = HAIRSTYLE[random(sizeof(HAIRSTYLE))];
   HAIRC = HAIRCOLOR[random(sizeof(HAIRCOLOR))];
   HAIRDO = HAIRA[random(sizeof(HAIRA))];
   set_name("a little boy");
   set_short("%^RESET%^%^CYAN%^A little boy with "+EYES+" eyes and "+HAIRC+" hair%^RESET%^");
   set_id(({"boy","little boy","orphan","boy orphan"}));
   set_long("%^RESET%^%^CYAN%^This little boy has "+HAIR+" "+
      ""+HAIRC+" hair that "+HAIRDO+".  The skin on his hands "+
      "and face is a little dirty as though he hasn't been as "+
      "well-cared-for as most children, but he looks healthy "+
      "enough in his "+CLOTH+" shirt and matching pants, the "+
      "cuffs of which have been tucked into a set of calf-high "+
      "boots.  Wide "+EYES+" eyes gaze out at the world "+
      "from under long "+HAIRC+" eyelashes, and a small, shy "+
      "smile turns his lips up into a cute little bow.  In his "+
      "hands he clutches a "+TOY+", and you can almost see the "+
      "eagerness to play lingering in his eyes as he gazes at "+
      "you.%^RESET%^");
   set_gender("male");
   set_race("human");
   set_hd(1,5);
   set_exp(1);
   set_emotes(4,({
	"The young boy studies the toy in his hands.",
	"The young boy gazes up at you.",
	"The young boy wipes a runny nose on the back of his hand."
   }),0);
}
