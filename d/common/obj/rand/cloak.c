//random cloak file coded by Circe 4/26/05
#include <std.h>
inherit ARMOUR;

#define COLORS ({"%^BOLD%^%^BLACK%^pitch black",\
"%^BOLD%^%^WHITE%^snow white",\
"%^BOLD%^%^RED%^cardinal red",\
"%^RESET%^%^RED%^blood red",\
"%^RESET%^%^ORANGE%^sunset orange",\
"%^RESET%^%^ORANGE%^walnut brown",\
"%^YELLOW%^goldenrod",\
"%^BOLD%^%^GREEN%^jade green",\
"%^RESET%^%^GREEN%^forest green",\
"%^BOLD%^%^BLUE%^cerulean blue",\
"%^RESET%^%^BLUE%^midnight blue",\
"%^RESET%^%^CYAN%^slate blue",\
"%^BOLD%^%^CYAN%^teal",\
"%^RESET%^%^MAGENTA%^violet",\
"%^BOLD%^%^MAGENTA%^bright pink",\
"%^BOLD%^%^BLACK%^charcoal gray",\
"%^BOLD%^%^GREEN%^emerald green",\
"%^BOLD%^%^BLUE%^sapphire blue",\
"%^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r",\
"%^ORANGE%^g%^BOLD%^o%^RESET%^%^ORANGE%^l%^BOLD%^d",\
"%^BOLD%^%^RED%^ruby red",\
"%^BOLD%^%^WHITE%^light cream",\
"%^BOLD%^%^BLACK%^raven black",\
"%^BOLD%^%^CYAN%^sky blue",\
"%^MAGENTA%^wine",\
"%^BOLD%^%^MAGENTA%^pale pink",\
"%^CYAN%^sea-green"})

#define KINDS ({"half-","long ","short "})

void create(){
   string kind,color;
   ::create();
   kind = KINDS[random(sizeof(KINDS))];
   color = COLORS[random(sizeof(COLORS))];
   set_name("cloak");
   set_id(({"cloak",""+kind+"cloak",""+color+" cloak"}));
   set_short("a "+kind+"cloak colored "+color+"%^RESET%^");
   set_limbs(({"neck"}));
   set_weight(2);
   set_type("clothing");
   if(!random(3)){
      set_size(2);
   }else{
      set_size(random(3)+1);
   }
   set_lore("This cloak is a rather common one, made by "+
      "tailors and seamstresses throughout the realms.  No "+
      "unique markings place it in the hands of anyone in "+
      "particular.  Cloaks such as these can be found on the "+
      "backs of most members of the merchant class.");
   set_property("lore difficulty",3);
   switch(kind){
      case "half-": set_long("This half-cloak is made of a soft "+
         ""+color+" wool fabric%^RESET%^.  It comes to the wearer's "+
         "knees and is made without a hood.  It is quite narrow, "+
         "and it may not be pulled over both shoulders at once.  "+
         "Such a cloak is typically worn as decoration or as a "+
         "finishing touch to an outfit rather than protection against "+
         "the elements.  A cloak clasp of "+color+" cording %^RESET%^"+
         "worked into an intricate knot finishes the look, though "+
         "it is made to be removed should the wearer desire another "+
         "clasp.");
         set_value(10);
         break;
      case "long ": set_long("This long cloak is made of luxurious "+
         "soft wool dyed "+color+"%^RESET%^.  The cloak has been "+
         "made with plenty of fabric, and it almost brushes the "+
         "ground as the wearer walks.  It features a deep hood "+
         "lined with "+color+" silk%^RESET%^, and it may be pulled "+
         "over both shoulders to fully encase the wearer with its "+
         "warmth.  Costume stones of "+color+" %^RESET%^form three "+
         "buttons along the chest of the cloak.");
         set_value(20);
         break;
      case "short ": set_long("Designed to reach the wearer's knees, "+
         "this short cloak is made of soft "+color+" wool%^RESET%^.  "+
         "The cloak is quite wide, allowing it to be drawn over both "+
         "shoulders for warmth.  A hood lined with "+color+" silk "+
         "%^RESET%^provides added protection against harsh weather "+
         "as well.  A frog made of "+color+" cording %^RESET%^rests "+
         "at the throat, though it may be replaced with a clasp of the "+
         "owner's choosing rather easily.");
         set_value(15);
         break;
      default: set_long("Ack, something's wrong.  Better mail Circe.");
         set_value(10);
         break;
   }
}