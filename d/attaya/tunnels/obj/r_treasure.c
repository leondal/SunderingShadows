// Coded by Lujke, with code brutally plundered from Cythera, who had  
// asked nicely to borrow it from Tsera. Gods only know where Tsera got 
// it. Maybe she was a smartass and wrote it for herself :)

#include <std.h>
inherit OBJECT;

#define COLORS ({"%^BOLD%^%^BLACK%^jet bl%^RESET%^a%^BOLD%^%^BLACK%^ck",\
"%^BOLD%^%^WHITE%^cryst%^RESET%^a%^BOLD%^%^WHITE%^l %^CYAN%^clear",\
"%^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^by red",\
"%^RESET%^%^RED%^blood red",\
"%^RESET%^%^YELLOW%^c%^RESET%^%^ORANGE%^i%^YELLOW%^trine",\
"%^YELLOW%^golden",\
"%^BOLD%^%^GREEN%^jade green",\
"%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^er%^BOLD%^a%^RESET%^%^GREEN%^ld g%^BOLD%^r%^RESET%^%^GREEN%^ee%^BOLD%^n",\
"%^BOLD%^%^BLUE%^cerulean blue",\
"%^RESET%^%^BLUE%^m%^BOLD%^%^BLACK%^i%^RESET%^%^BLUE%^dn%^BOLD%^%^BLACK%^i%^RESET%^%^BLUE%^ght blue",\
"%^CYAN%^cry%^RESET%^s%^CYAN%^t%^RESET%^all%^RESET%^i%^CYAN%^ne",\
"%^RESET%^%^MAGENTA%^violet",\
"%^BOLD%^%^MAGENTA%^bright pink",\
"%^BOLD%^%^BLUE%^s%^CYAN%^a%^BLUE%^pph%^WHITE%^i%^BLUE%^re blue",\
"%^BOLD%^%^CYAN%^sky blue",\
"%^MAGENTA%^wine coloured",\
"%^BOLD%^%^MAGENTA%^pale pink"})

#define types ({"quartz stones","crystals","crystal shards","gem stones"})

void create()
{
  int i,x;
  string type, COLOR;

  i = random(sizeof(COLORS));
  COLOR = COLORS[i];
  x = random(sizeof(types));
  type = types[x];
  ::create();
  switch(type)
  {
  case "quartz stones":
    set_long("A small handful of " + COLOR + "%^RESET%^ quartz"
            +" stones. They are rough and unpolished, but %^BOLD%^"
            +"%^WHITE%^s%^RESET%^p%^BOLD%^%^CYAN%^a%^RESET%^r"
            +"%^BOLD%^%^WHITE%^k%^RESET%^l%^BOLD%^%^YELLOW%^e"
            +"%^RESET%^ brightly nonetheless. There is a strange,"
            +" %^MAGENTA%^gl%^BOLD%^%^MAGENTA%^i%^RESET%^"
            +"%^MAGENTA%^mmer%^RESET%^i%^MAGENTA%^ng %^MAGENTA%^a"
            +"ura %^RESET%^around them and you guess that their"
            +" worth might be greater than ordinary stones.\n");
    set_name("quartz");
    set_short("glimmering%^RESET%^"+COLOR+" quartz stones"
             +"%^RESET%^ of power");
    set_obvious_short("%^RESET%^"+COLOR+" quartz stones%^RESET%^");
    set_id(({"quartz","quartz stones", "stones"}));
    break;
  case "crystals":
    set_long("A set of exotically shaped " + COLOR 
            +" %^RESET%^crystals, which seem to glow with a strange"
            +" innner light.\n");  
    set_name("crystals");
    set_short("%^RESET%^"+COLOR+" crystals of %^RESET%^%^MAGENTA%^power%^RESET%^");
    set_obvious_short("%^RESET%^"+COLOR+" crystals%^RESET%^");
    set_id(({"crystal","crystals", "set"}));   
    break;
  case "crystal shards":
    set_long("A set of " + COLOR + " %^CYAN%^cr%^BOLD%^%^WHITE%^y"
            +"%^RESET%^%^CYAN%^stal %^RESET%^shards that appears to"
            +" have been shattered from a single larger rock\n");
    set_name("crystal shards");
    set_short("%^RESET%^"+COLOR+" crystal shards%^RESET%^");
    set_id(({"shards","crystal shards","crystal","crystals"}));
    break;
  case "gem stones":
    set_long("A set of " + COLOR + " gem stones in different sizes."
            +" They appear to be uncut, but are very pretty all the"
            +" same\n");
    set_name("gem stones");
    set_short("%^RESET%^"+COLOR+" gem stones%^RESET%^");
    set_id(({"stones","gem stones","gems","gem", "stone"}));
    break;
  }
  set_weight(2);
  set_value(random(6+1)*200);
}

