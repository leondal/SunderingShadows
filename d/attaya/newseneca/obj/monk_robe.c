//monk robe for new Seneca - standard robe with
//flavor ;)  ~Circe~ 12/11/07
#include <std.h>

inherit ARMOUR;

void create(){
   ::create();
   set_name("monk's robe");
   set_id(({"robe","armor","monk robe","monk's robe","robe of the altherian monks","Altherian monk robe","Robe of the Altherian Monks"}));
   set_obvious_short("%^RESET%^%^ORANGE%^g%^YELLOW%^o%^RESET%^"+
      "%^ORANGE%^l%^YELLOW%^d%^RESET%^%^ORANGE%^e%^YELLOW%^n"+
      "%^RESET%^%^ORANGE%^-%^YELLOW%^o%^RESET%^%^ORANGE%^r"+
      "%^YELLOW%^a%^RESET%^%^ORANGE%^n%^YELLOW%^g%^RESET%^"+
      "%^ORANGE%^e robe%^RESET%^");
   set_short("%^RESET%^%^ORANGE%^Robe of the %^YELLOW%^Altherian Monks%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^Crafted from exquisitely soft "+
      "%^RESET%^%^ORANGE%^g%^YELLOW%^o%^RESET%^"+
      "%^ORANGE%^l%^YELLOW%^d%^RESET%^%^ORANGE%^e%^YELLOW%^n"+
      "%^RESET%^%^ORANGE%^-%^YELLOW%^o%^RESET%^%^ORANGE%^r"+
      "%^YELLOW%^a%^RESET%^%^ORANGE%^n%^YELLOW%^g%^RESET%^"+
      "%^ORANGE%^e cotton, this robe is simple in design.  "+
      "The voluminous sleeves are long, reaching over the tips "+
      "of the fingers, though they are often pushed back for "+
      "convenience.  The bottom of the robe reaches to about "+
      "mid-calf on the wearer, allowing freedom of movement for "+
      "most any task.  A brilliant %^BOLD%^%^RED%^crimson "+
      "sash %^RESET%^%^ORANGE%^completes the robe, and it is worn "+
      "in many ways at different times.  Sometimes, it is folded "+
      "and tied about the waist as a belt, while at other times "+
      "it is looped over the shoulder and across the chest, twisted "+
      "rather than tied.%^RESET%^");
   set_lore("This robe is a symbol of the Altherian monks of "+
      "Seneca.  An order that was largely wiped out during the "+
      "first war with the Intruder, the survivors have nonetheless "+
      "continued the traditions of the monks and kept the order "+
      "alive.  By all accounts, the Altherian monks fought "+
      "valiantly during the war, despite the grim outcome.  "+
      "The leadership of the Order continues to teach its monks "+
      "the arts of combat as well as the balance of the soul, "+
      "and they vow that should Seneca ever fall under attack again, "+
      "they will once more stand ready.  This robe is worn by the monks "+
      "at all times, and the positions of the sash differ according to "+
      "days, ceremonies, and occurences.");
   set_property("lore difficulty",15);
   set_weight(8); //slightly lighter than normal robes due to masterwork construction
   set_value(1250);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_ac(1);
}

int isMagic(){
   int magicrobe;
   magicrobe = ::isMagic();
   magicrobe = magicrobe+1;
   return magicrobe;
}
