#include <std.h>
#include "../tunnel.h"

#define GEMS ({"%^BOLD%^%^WHITE%^diamond%^RESET%^",\
"%^BOLD%^%^GREEN%^emerald%^RESET%^",\
"%^BOLD%^%^RED%^ruby%^RESET%^",\
"%^BOLD%^%^BLUE%^sapphire%^RESET%^",\
"%^RED%^garnet%^RESET%^",\
"%^MAGENTA%^amethyst%^RESET%^",\
"%^ORANGE%^topaz%^RESET%^",\
"%^BOLD%^%^RED%^fire opal%^RESET%^",\
"%^BOLD%^%^WHITE%^moonstone%^RESET%^",\
"%^BOLD%^%^BLACK%^black opal%^RESET%^",\
"%^BOLD%^%^WHITE%^o%^CYAN%^p%^WHITE%^a%^MAGENTA%^l%^RESET%^",\
"%^ORANGE%^piece of amber%^RESET%^",\
"%^BOLD%^%^GREEN%^piece of jade%^RESET%^",\
"%^BOLD%^%^CYAN%^water opal%^RESET%^"})

inherit OBJECT;

void create()
{
  int i,j, val;
  string str;
  ::create();
  j=random(9);
  str= GEMS[j];
  val = random(4000);
  if (val>3000){val += random(4000);}
  switch(val) {
  case 0..200:
    set_long("This is a small "+str+". The light catches"
	      +" in the gem and it looks like it would sell for a"
            +" nice price.");
    set_short("Small "+str+"");
    break;
  case 201..400:
    set_long("This is a "+str+" of a nice size. From the"
            +" way the light catches within the gem, it could"
            +" probably be sold for a fair sum.");
    set_short("Medium "+str+"");
    break;
  case 401..600:
    set_long("This is a fairly nice sized "+str+". The"
            +" light twinkles within the gem very prettily and"
            +" it is obviously worth a fair bit of gold.");
    set_short("Large "+str+"");
    break;
  case 601..2500:
    set_long("This is a fine "+str+". It is a very nice size and"
             +" the facets are bright and finely cut. The"
             +" light twinkles within the gem very prettily"
             +" and it is obviously worth a good bit of"
             +" gold.");
    set_short("Fine "+str+"");
    break;
  case 2501..5000:
    set_long("This is an exquisite "+str+". It is large and fine."
             +" The cut and shape of the gem are beautiful. The"
             +" light twinkles within it very attractively"
             +" and it is obviously worth a lot of"
             +" gold.");
    set_short("Exquisite "+str+"");
    break;
  default:               
    set_long("This is a fabulous "+str+". It is not huge in size, but"
             +" the clarity and perfection of form is simply breathtaking"
             +". The light shines so brightly within the gem you could"
             +" almost imagine it was lit from within. This gem must be"
             +" worth a fortune!");
    set_short("Fabulous "+str+"");
  }
  if(val < 50) {
    set_value(50);
  }
  else {
    set_value(val);
  }
  set_id(({"gem",str}));
  set_name("gem");
  set_weight(5);
}

int is_gem(){return 1;}