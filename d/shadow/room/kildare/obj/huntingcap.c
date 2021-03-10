#include <std.h>
inherit ARMOUR;

int FLAG;

void create() {
   ::create();
   set_name("hunting cap");
   set_id(({"cap","hat","hunting cap","hunting hat"}));
   set_short("%^RESET%^%^GREEN%^A hunting cap%^RESET%^");
   set_long(
@CIRCE
%^RESET%^%^GREEN%^The suede used to make this hunting cap has been dyed 
a dark green color.  The hat is round and has two ear flaps 
tied with a leather cord on top that can be pulled down to 
keep the wearer's ears warm.  The inside of the hat is lined 
with fuzzy white wool that makes it soft and comfortable. There 
seems to be a tag sewn inside you could read. 
CIRCE
   );
   set("read",
      "The flaps of this hat may be raised or lowered to keep your ears "+
      "warm or allow them to breathe.  <flaps>."
   );
   set_lore("This is a finely-tailored hat made by Mariel "+
      "of Kildare Glen.  A small tag bearing her mark has been "+
      "sewn into it.");
   set_property("lore difficulty",3);
   set_weight(4);
   set_value(45);
   set_type("clothing");
   set_limbs(({"head"}));
   set_size(random(3)+1);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
}

int wearme() {
   tell_object(ETO,"%^GREEN%^You settle the hat on top of your head with "+
      "the flaps tied up.%^RESET%^");
   tell_room(environment(ETO),"%^GREEN%^"+ETO->query_cap_name()+" plops the hat on "+
      ""+ETO->query_possessive()+" head and looks a little silly.%^RESET%^",ETO);
   return 1;
}

int unwearme() {
   tell_object(ETO,"%^GREEN%^Your head feels cold as you remove the hat.");
   tell_room(environment(ETO),"%^GREEN%^"+ETO->query_cap_name()+" looks more "+
      "like "+ETO->query_objective()+"self as "+ETO->query_subjective()+" takes "+
      "off the hat.%^RESET%^",ETO);
   return 1;
}

void init()
{
   ::init();
   add_action("flaps","flaps");
}

void flaps(string str)
{
      if(!query_worn()){ 
         write("You don't seem to be wearing that!");
      }
      if(FLAG == 1) {
      write("%^BOLD%^You raise the flaps on top of the hat and tie the "+
         "leather cord snugly.%^RESET%^");
      tell_room(ETP,"%^BOLD%^%^GREEN%^"+TPQCN+" pulls the flaps over the hat "+ 
          "and ties the cord.%^RESET%^",TP);
      FLAG = 0;
      return 1;
      }
      else {
      write("%^BOLD%^You lower the flaps on top of the hat and tie the "+
         "leather cord under your chin.%^RESET%^");
      tell_room(ETP,"%^BOLD%^%^GREEN%^"+TPQCN+" lowers the flaps on the hat "+ 
          "and ties the cord under "+ETO->query_possessive()+" chin.%^RESET%^",TP);
      FLAG = 1;
      return 1;
      }
}
