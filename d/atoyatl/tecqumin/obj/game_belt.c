#include <std.h>
#include <move.h>

inherit ARMOUR;

int stamina_track;

void create(){
        ::create();
        set_name("leather belt");
        set_id(({ "belt", "leather belt" }));
        set_short("Tecqumin game belt");
        set_obvious_short("%^BOLD%^%^BLACK%^broad %^RESET%^%^ORANGE%^leather %^BOLD%^%^BLACK%^belt");
        set_long(

@LUJKE
This broad belt is designed to offer padding and support to the waist, rather than to secure other clothing. It is wider at the front than the back. It seems to be designed to reduce the strain and risk of damage from exertion

LUJKE
        );
        set_weight(3);
   set_value(150000);
        set_lore(
@AVATAR
The Tecqumin people are known to have played some form of game which involved teams of players wearing belts of this design. The belt offered protection from impacts of the heavy stone ball that was used, as well as guarding against the strains involved in playing the game.

AVATAR
        );
        set_property("lore difficulty",35);
        set_type("clothing");
        set_limbs(({ "waist" }));
        set_size(-1);
        TO->set_property("enchantment",6);
        set_wear((:TO,"wear_func":));
        set_overallStatus(320);
       set_property("quest required", "%^GREEN%^Sealed the %^BLUE%^U%^MAGENTA%^nf"
    +"%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d"
    +" %^GREEN%^back into the %^BLUE%^v%^BOLD%^%^BLACK%^o%^RESET%^i%^BLUE%^d");
}

int isMagic(){ return 1; }

int wear_func(){
  int bonus;
  if (!objectp(ETO)){
    return;
  }
  if((int)ETO->query_level() < 41) {
    tell_object(ETO,"You aren't experienced enough to handle an item of this power.");
    return 0;
  }
  bonus = ETO->query_property("bonus stamina");
  bonus += ETO->query_lowest_level() * 8;
  stamina_track = ETO->query_lowest_level() * 8;
  tell_room(EETO ,ETO->QCN + " appears better prepared for rigorous action as " 
    + ETO->QS + " fastens the belt around " + ETO->QP + " waist" , ETO);
  tell_object(ETO,"You fasten the belt around your waist and appreciate the feeling of support it provides.");
  return 1;
}

int remove_func(){
  int bonus;
  if (!objectp(ETO)){
    return;
  }
  bonus = ETO->query_property("bonus stamina");
  bonus -= stamina_track;
  ETO->set_property("bonus stamina", bonus);
  return 1;
}
