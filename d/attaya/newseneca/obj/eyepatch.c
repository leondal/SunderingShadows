//~Circe~ 10/27/07
//Some code borrowed from Torm eyepatch

#include <std.h>
inherit ARMOUR;

#define GEMS ({"%^BOLD%^%^WHITE%^diamond","%^BOLD%^%^GREEN%^emerald","%^BOLD%^%^RED%^ruby","%^BOLD%^%^BLUE%^sapphire","%^BOLD%^%^BLACK%^onyx","%^BOLD%^%^WHITE%^o%^CYAN%^p%^MAGENTA%^a%^WHITE%^l","%^RESET%^%^MAGENTA%^amethyst","%^RESET%^%^ORANGE%^topaz","%^RESET%^%^RED%^garnet","%^RESET%^%^ORANGE%^tiger's eye","%^RESET%^%^ORANGE%^amber","%^BOLD%^%^CYAN%^aquamarine","%^RESET%^%^GREEN%^agate","%^BOLD%^%^BLACK%^ma%^GREEN%^l%^BLACK%^ach%^GREEN%^i%^BLACK%^te","%^BOLD%^%^WHITE%^moonstone","%^BOLD%^%^BLACK%^beryl","%^BOLD%^%^WHITE%^pearl","%^BOLD%^%^BLACK%^hematite","%^BOLD%^%^MAGENTA%^rose quartz","%^BOLD%^%^GREEN%^tourmaline","%^YELLOW%^citrine","%^BOLD%^%^RED%^carnelian","%^BOLD%^%^GREEN%^blo%^RED%^o%^GREEN%^dst%^RED%^o%^GREEN%^ne","%^RESET%^%^CYAN%^azurite","%^BOLD%^%^GREEN%^per%^YELLOW%^i%^GREEN%^dot"})

void create(){
   string GEM;
   ::create();
   GEM = GEMS[random(sizeof(GEMS))];
   set_name("eyepatch");
   set_id(({"eyepatch","studded eyepatch","patch","eye patch"}));
   set_short(""+GEM+"-studded %^BOLD%^%^BLACK%^eyepatch%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This eyepatch is made of black leather, "+
      "a simple curved piece to protect the eye attached to leather "+
      "thongs meant to tie in the back.  This particular eyepatch "+
      "has been spruced up a bit with tiny "+GEM+" chips %^BOLD%^"+
      "%^BLACK%^arranged around the outer edge.  The gems are small, likely left "+
      "over from true gems cut for other purposes, but they add a "+
      "bit of color and make this an attractive piece - if you like "+
      "that sort of thing.%^RESET%^");
   set_weight(1);
   set_value(35+random(6));
   set_type("ring");
   set_limbs(({"head"}));
   set_wear((:TO,"wearit":));
}

int wearit(){
  object *stuff;
  int i,j,flag;
  stuff=TP->all_armour();
  j=sizeof(stuff);
  for(i=0;i<j;i++){
     if((string)stuff[i]->query_name()=="eyepatch"){
        flag=1;
        break;
     }
  }
  if(flag){
     tell_object(ETO,"You'd look a little silly with an eyepatch "+
        "over both eyes.");
     return 0;
  }
  tell_object(ETO,"You slide the eyepatch on and adjust it, noticing a "+
     "shift in your vision.");
  tell_room(EETO,""+ETOQCN+" ties an eyepatch over one eye.",ETO);
  return 1;
}
