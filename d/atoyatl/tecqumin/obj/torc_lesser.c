#include <std.h>
#include <clock.h>

inherit "/d/common/obj/jewelry/necklace";
int uses;
int head;

void create(){
    string * heads, * head_shorts;
    heads = ({"a %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^e%^BOLD%^rp"
               +"%^RESET%^%^GREEN%^e%^BOLD%^nt%^RESET%^ with a"
               +" %^BOLD%^%^RED%^p%^BLUE%^l%^RED%^u%^BLUE%^m%^RED%^e"
               +" %^RESET%^of %^BOLD%^%^RED%^f%^BLUE%^ea%^RED%^th"
               +"%^BLUE%^e%^RED%^rs%^RESET%^", "a%^BOLD%^%^WHITE%^"
               +" snarling %^BOLD%^%^BLACK%^j%^RESET%^a%^BOLD%^"
               +"%^BLACK%^g%^RESET%^%^BLUE%^u%^BOLD%^%^BLACK%^ar",
                "a hero %^BOLD%^%^YELLOW%^wreathed %^RESET%^in"
               +" %^BOLD%^%^RED%^f%^YELLOW%^l%^RESET%^%^RED%^a"
               +"%^BOLD%^me%^RESET%^", "a %^BOLD%^%^GREEN%^tr"
               +"%^RESET%^%^GREEN%^ee %^BOLD%^sp%^RESET%^%^GREEN%^"
               +"i%^BOLD%^r%^RESET%^%^GREEN%^i%^BOLD%^t%^RESET%^",
                "a %^BOLD%^%^YELLOW%^sun G%^RESET%^%^ORANGE%^o"
               +"%^BOLD%^d%^RESET%^"});
    head_shorts = ({"%^BOLD%^%^GREEN%^serpent%^RESET%^",
      "%^BOLD%^%^BLACK%^j%^RESET%^a%^BOLD%^%^BLACK%^g%^RESET%^"
     +"%^BLUE%^u%^BOLD%^%^BLACK%^ar", "%^ORANGE%^hero%^RESET%^",
      "%^GREEN%^tree", "%^BOLD%^%^YELLOW%^sun"});
    ::create();
    head = random(sizeof(heads));
    set_name("Silver torc");
    set_id(({"torc","silver torc","tecqumin torc","tecqumin silver torc",
             "silver tecqumin torc"}));
    set_short("%^BOLD%^%^WHITE%^S%^RESET%^i%^BOLD%^%^WHITE%^lv%^RESET%^e"
      +"%^BOLD%^%^WHITE%^r " +head_shorts[head] + " t%^RESET%^o%^BOLD%^"
      +"%^WHITE%^rc %^RESET%^of the %^CYAN%^Tecqumin");
    set_obvious_short("A %^BOLD%^%^WHITE%^S%^RESET%^i%^BOLD%^%^WHITE%^lv"
      +"%^RESET%^e%^BOLD%^%^WHITE%^r " + head_shorts[head]
      +" t%^RESET%^o%^BOLD%^%^WHITE%^rc%^RESET%^");
    set_long("This %^BOLD%^%^WHITE%^rigid s%^RESET%^i%^BOLD%^%^WHITE%^lv"
      +"%^RESET%^e%^BOLD%^%^WHITE%^r%^RESET%^ neck ring is of fine"
      +" quality. The two bulbs at the ends come close to meeting each"
      +" other at the front. Each one is fashioned into the head of "
      + heads[head] +"\n");
   set_lore("The priests of the Tecqumin wore torcs that indicated their"
      +" allegiance to one or another of the gods that they worshipped."
      +" Some of them were blessed with the powers of their particular gods."
      +" The high priests were rumoured to be gifted with torcs carrying"
      +" enchantments relating to more than one god.");
   set_property("enchantment",6);
   switch(head){
   case 0:
     //serpent
    set_item_bonus("wisdom", 6);
     break;
   case 1:
     //jaguar
    set_item_bonus("dexterity", 6);
     break;
   case 2:
     //flame hero
    set_item_bonus("fire resistance", 30);
     break;
   case 3:
     //tree spirit
    set_item_bonus("survival", 30);
     break;
   case 4:
     //sun god
    set_item_bonus("caster level", 3);
     break;
   }
}

int wear_it(string str){
    tell_object(ETO,"You drag the ends of the torc apart far enough to get it"
      +" round your neck.");
    tell_room(environment(ETO), ETO->query_cap_name()+ " fastens the "
      + query_obvious_short() + " around "+ETO->query_possessive()+" neck.",ETO);
    return 1;
}
void init() {
    ::init();
}
