#include <std.h>

#define STONES ({"%^RESET%^%^MAGENTA%^amethyst%^RESET%^",\
"%^BOLD%^%^WHITE%^ivory%^RESET%^",\
"%^BOLD%^%^BLACK%^ebony%^RESET%^",\
"%^RESET%^%^GREEN%^agate%^RESET%^",\
"%^BOLD%^%^CYAN%^aquamarine%^RESET%^",\
"%^BOLD%^%^BLACK%^onyx%^RESET%^",\
"%^RESET%^%^ORANGE%^amber%^RESET%^",\
"%^BOLD%^%^GREEN%^jade%^RESET%^",\
"%^BOLD%^%^WHITE%^crystal quartz%^RESET%^",\
"%^BOLD%^%^MAGENTA%^rose quartz%^RESET%^",\
"%^BOLD%^%^BLACK%^smokey quartz%^RESET%^",\
"%^RESET%^%^ORANGE%^tigers eye%^RESET%^",\
"%^BOLD%^%^RED%^fire agate%^RESET%^",\
"%^BOLD%^%^WHITE%^moonstone%^RESET%^",\
"%^BOLD%^%^GREEN%^blo%^RED%^o%^GREEN%^dst%^RED%^o%^GREEN%^ne%^RESET%^",\
"%^GREEN%^jasper%^RESET%^",\
"%^RESET%^%^RED%^carnelian%^RESET%^",\
"%^YELLOW%^citrine%^RESET%^",\
"%^RESET%^%^BLUE%^lapis lazuli%^RESET%^",\
"%^RESET%^%^GREEN%^beryl%^RESET%^",\
"%^RESET%^%^ORANGE%^topaz%^RESET%^",\
"%^RESET%^%^GREEN%^malachite%^RESET%^",\
"%^BOLD%^%^BLUE%^blue spinel%^RESET%^",\
"%^BOLD%^%^WHITE%^o%^CYAN%^p%^MAGENTA%^a%^WHITE%^l%^RESET%^",\
"%^BOLD%^%^BLACK%^bl%^GREEN%^a%^BLACK%^ck op%^GREEN%^a%^BLACK%^l%^RESET%^",\
"%^BOLD%^%^CYAN%^water opal%^RESET%^",\
"%^BOLD%^%^RED%^flamedance%^RESET%^",\
"%^RESET%^%^RED%^garnet%^RESET%^",\
"%^BOLD%^%^BLACK%^hematite%^RESET%^"})
inherit DAEMON;

int i, j, val;
string str, VAR;

void create()
{
   ::create();
}

void create_comb(object obj)
{
   j = random(sizeof(STONES));
   str = STONES[j];
   VAR = "A";
   if(str == "ivory" || str == "ebony" || str == "amethyst" || str == "agate" || str == "aquamarine" || str == "onyx") {
      VAR = "An";
   }
   val = random(20)+20;
   switch(random(2)) {
      case 0:
         obj->set_short("A pair of "+str+" hair combs");
         obj->set_id(({"hair comb","hair combs","pair of hair combs","combs",""+str+" combs",""+str+" hair combs","pair of "+str+" hair combs"}));
         obj->set_long("These hair combs are made out of "+str+" that has"+
         " been smoothly polished and expertly crafted into an identical"+
         " pair of combs. They are worn together, pulling hair back on both"+
         " sides.");
         obj->set_weight(2);
         obj->set_value(random(10)+10);
         obj->set_wear("The combs slip easily into your hair, keeping it stylishly out of your face.");
         obj->set_remove("You take out the combs, letting your hair fall free.");
         break;
      case 1:
         obj->set_short(""+VAR+" "+str+" hair comb");
         obj->set_id(({"hair comb",""+str+" hair comb",""+str+" comb","comb"}));
         obj->set_long("This hair comb is slightly larger than normal and"+
         " can be used to hold back even the thickest hair. It is typically"+
         " worn alone, sweeping back one side of the woman's hair only in"+
         " a stylish fashion. It is made of "+str+" that has been polished"+
         " smooth.");
         obj->set_weight(1);
         obj->set_value(random(5)+10);
         obj->set_wear("You sweep part of your hair back and secure the comb in place.");
         obj->set_remove("You take out the "+str+" hair comb.");
         break;
   }
   obj->set_name("hair comb");
   obj->set_type("ring");
   obj->set_limbs(({"head"}));
}
