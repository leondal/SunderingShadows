// Coded by Lujke, with code brutally plundered from Cythera, who had  
// asked nicely to borrow it from Tsera. Gods only know where Tsera got 
// it. Maybe she was a smartass and wrote it for herself :)

#include <std.h>
inherit OBJECT;


#define SPELLS ({"fireball",\
"lightning bolt",\
"acid arrow",\
"monster summoning i",\
"stoneskin",\
"magic missile",\
"scorcher",\
"phantom guardians",\
"blink",\
"hold person",\
"ray of enfeeblement",\
"prismatic spray",\
"monster summoning vi",\
"magic mirror"})

#define WTYPES ({"maple",\
"ivory",\
"steel",\
"slender willow",\
"white tipped black",\
"cherry wood",\
"iron",\
"ebony"})

void make_me();

void create()
{
  TO->set_name("wand");
  make_me();
  set_weight(2);
  set_value(random(6+1)*50);
}

void make_me()
{ 
  int i,y;
  string type, spell;
  i = random(sizeof(WTYPES));
  type = WTYPES[i];
  y = random(sizeof(SPELLS));
  spell=SPELLS[y];
  ::create();

  switch(type)
  {
  case "maple":
    set_long("%^RESET%^A tapered %^ORANGE%^maple wand%^RESET%^, about"
                +" five inches in length. A few faint runes are carved"
                +" into the side of the wand.");
    set_short("%^ORANGE%^maple wand of "+spell);
    set_obvious_short("%^ORANGE%^maple wand");
    set_id(({"wand of "+spell,"maple wand", "wand"}));
    break;
  case "ivory":
    set_long("%^RESET%^A short %^BOLD%^%^WHITE%^i%^RESET%^v%^BOLD%^"
            +"%^WHITE%^ory%^RESET%^ wand. A few faint runes are"
            +" etched into the side of the wand.");
    set_short("%^BOLD%^%^WHITE%^i%^RESET%^v%^BOLD%^%^WHITE%^ory"
              +" wand of "+spell);
    set_obvious_short("%^BOLD%^%^WHITE%^i%^RESET%^v%^BOLD%^"
                     +"%^WHITE%^ory wand");
    set_id(({"wand of "+spell,"ivory wand", "wand"}));
    break;    
  case "steel":
    set_long("%^RESET%^A solid %^CYAN%^s%^RESET%^t%^CYAN%^ee%^RESET%^"
            +"l wand. A few faint runes are etched into the side of"
            +" the wand.");
    set_short("%^CYAN%^s%^RESET%^t%^CYAN%^ee%^RESET%^l wand of "
             + spell);
    set_obvious_short("%^CYAN%^s%^RESET%^t%^CYAN%^ee%^RESET%^l wand");
    set_id(({"wand of "+spell,"steel wand", "wand"}));
    break;    
  case "slender willow":
    set_long("%^RESET%^A slender %^ORANGE%^w%^RESET%^i%^ORANGE%^ll"
            +"%^RESET%^o%^ORANGE%^w %^RESET%^ wand. A few faint runes"
            +" are carved into the side of the wand.");
    set_short("%^ORANGE%^w%^RESET%^i%^ORANGE%^ll%^RESET%^o%^ORANGE%^w"
             +" %^RESET%^ wand of " + spell);
    set_obvious_short("%^ORANGE%^w%^RESET%^i%^ORANGE%^ll%^RESET%^o"
                     +"%^ORANGE%^w %^RESET%^ wand");
    set_id(({"wand of "+spell,"willow wand", "slender wand","wand"}));
    break;    
  case "white tipped black":
    set_long("%^RESET%^A %^BOLD%^%^WHITE%^wh%^BOLD%^%^BLACK%^ite"
            +" tipped bla%^BOLD%^%^WHITE%^ck%^RESET%^ wand, about six"
            +" inches in lenth");
    set_short("%^RESET%^A %^BOLD%^%^WHITE%^wh%^BOLD%^%^BLACK%^ite"
            +" tipped bla%^BOLD%^%^WHITE%^ck%^RESET%^ wand " + spell);
    set_obvious_short("%^BOLD%^%^WHITE%^wh%^BOLD%^%^BLACK%^ite"
                     +" tipped bla%^BOLD%^%^WHITE%^ck%^RESET%^ wand");
    set_id(({"wand of "+spell,"black wand", 
                                      "white tipped wand","wand"}));
    break;    
  case "cherry wood":
    set_long("%^RESET%^A %^ORANGE%^c%^RED%^h%^ORANGE%^er%^RED%^r"
            +"%^ORANGE%^y w%^RED%^oo%^ORANGE%^d wand. A few faint"
            +" runes are carved into the side of the wand.");
    set_short("%^RESET%^A %^ORANGE%^c%^RED%^he%^ORANGE%^r%^RED%^r"
             +"%^ORANGE%^y w%^RED%^oo%^ORANGE%^d wand of " + spell);
    set_obvious_short("%^ORANGE%^c%^RED%^h%^ORANGE%^r%^RED%^r"
                     +"%^ORANGE%^y w%^RED%^oo%^ORANGE%^d wand");
    set_id(({"wand of "+spell,"cherry wand", 
                                     "cherry wood wand","wand"}));
    break;    
  case "iron":
    set_long("%^RESET%^An %^BOLD%^%^BLACK%^ir%^RESET%^o%^BOLD%^"
            +"%^BLACK%^n wand, about five inches in length. A few"
            +" faint runes are embossed into the side of the wand.");
    set_short("%^RESET%^An %^BOLD%^%^BLACK%^ir%^RESET%^o%^BOLD%^"
             +"%^BLACK%^n wand of " + spell);
    set_obvious_short("%^BOLD%^%^BLACK%^ir%^RESET%^o%^BOLD%^"
                         +"%^BLACK%^n wand");
    set_id(({"wand of "+spell,"iron wand","iron wand of "+spell}));
    break;    
  case "ebony":
    set_long("%^RESET%^An %^BOLD%^%^BLACK%^ebony wand%^RESET%^,"
            +" about six inches long. A few faint runes are carved"
            +" into the side of the wand.");
    set_short("%^RESET%^An %^BOLD%^%^BLACK%^ebony wand%^RESET%^ of " 
              + spell);
    set_obvious_short("%^BOLD%^%^BLACK%^ebony wand%^RESET%^");
    set_id(({"wand of "+spell,"ebony wand","ebony wand of "+spell}));
    break;    
  }
  set("effect","spell_effect");
  set("uses",random(3)+2);
  set("spell",spell);
  set("spell type","mage");
  set("level",10+random(31));
  set("language","common");
  set("read","The runes indicate that you should %^YELLOW%^'use wand on"
            +" target'");
}
