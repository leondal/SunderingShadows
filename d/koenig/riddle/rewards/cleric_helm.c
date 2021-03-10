#include <std.h>
inherit "/d/common/obj/armour/breastplate";

int OWNED;

string owner;

void create(){
   ::create();
   set_name("%^BOLD%^%^WHITE%^Breastplate of the Watcher%^RESET%^");
   set_short("%^BOLD%^%^WHITE%^Beastplate of the Watcher%^RESET%^");
   set_obvious_short("%^RESET%^M%^BOLD%^%^WHITE%^i%^RESET%^rr%^BOLD%^%^WHITE%^o%^RESET%^r%^BOLD%^%^WHITE%^e%^RESET%^d Breastplate");
   set_id(({"breastplate","breast plate","plate","armor"}));
   set_long("%^BOLD%^%^WHITE%^This breastplate is made of"
" exquisite %^RESET%^pl%^BOLD%^%^BLACK%^a%^WHITE%^t%^RESET%^i"
"%^BOLD%^%^BLACK%^n%^WHITE%^u%^RESET%^m %^BOLD%^%^WHITE%^that"
" is polished to a fine, %^RESET%^m%^BOLD%^%^WHITE%^i%^RESET%^"
"rr%^BOLD%^%^WHITE%^o%^RESET%^r%^BOLD%^%^WHITE%^e%^RESET%^d %^"
"BOLD%^%^WHITE%^shine.  The image of an upraised %^RESET%^g"
"%^BOLD%^%^BLACK%^a%^RESET%^u%^BOLD%^%^WHITE%^n%^BLACK%^t"
"%^RESET%^l%^BOLD%^%^WHITE%^e%^RESET%^t %^BOLD%^%^WHITE%^"
"studded with %^RESET%^diamonds %^BOLD%^%^WHITE%^in the knuckles"
" is engraved upon the surface.  In the center of the"
" %^RESET%^g%^BOLD%^%^BLACK%^a%^WHITE%^u%^RESET%^n%^BOLD%^"
"%^WHITE%^t%^BLACK%^l%^WHITE%^e%^RESET%^t %^BOLD%^%^WHITE%^is"
" an ever watching eye that curiously enough, seems to always"
" be focused on you.  %^BLACK%^Ancient, %^WHITE%^mystical runes"
" swirl out from around each of the %^RESET%^diamonds"
" %^BOLD%^%^WHITE%^and concentrate around the eye in a warm"
" %^CYAN%^glow %^WHITE%^before bursting out across the actual"
" plate itself.%^RESET%^\n");
   set_lore("%^BOLD%^%^WHITE%^Not much is known about the story"
" of this plate, but it is said to be linked to Sir Alexander"
" Yelevien III, a dedicated knight of Helm that fell in a great"
" battle over the fate of the Shadowgate realms in the early"
" 100's.  Though it is highly doubted this is the actual"
" breastplate that he wore, it is thought that the diamonds"
" studded into the original plate were taken and inserted into a"
" few specially designed plates and then given Helm's"
" blessings to draw the magical nature of the original armor.%^RESET%^");
   set_property("lore difficulty",12);
    set_property("enchantment",2);
    if(TO->query_property("enchantment")< 2){
       remove_property("enchantment");
       set_property("enchantment",2);
    }   
   set_value(0);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
}

void init()
{
   ::init();
   if(!interactive(ETO)) return;
   if(interactive(TP) && TP == environment(TO) && !OWNED) {
   owner = TPQN;
   OWNED = 1;
   set_size(TP->query_size());
   }
}

int wearme()
{
   if((string)TPQN != owner) {
      tell_object(ETO,"%^RED%^The eye turns and stares at you angrily! 
You are not its master!
As the eye slowly closes and opens again, a %^BOLD%^%^CYAN%^burst %^RESET%^%^RED%^of %^YELLOW%^energy %^RESET%^%^RED%^flies forth from it, hitting you squarely in the head!%^RESET%^");
      tell_room(environment(ETO),"%^RESET%^%^RED%^"+ETO->query_cap_name()+" screams in pain as the eye turns angrily on "+ETO->query_objective()+", sending a %^BOLD%^%^CYAN%^burst %^RESET%^%^RED%^of %^YELLOW%^energy %^RESET%^%^RED%^hurtling "+ETO->query_possessive()+" way!",ETO);
      set_property("magic",1);
      ETO->do_damage("torso",random(20)+10);
      ETO->add_attacker(TO);
      ETO->continue_attack();
      ETO->remove_attacker(TO);
      remove_property("magic");
      return 0;
   }
   tell_object(ETO,"%^BOLD%^%^WHITE%^The eye in the center of the armor blinks slowly and %^YELLOW%^bursts %^WHITE%^with a %^CYAN%^magical aura %^WHITE%^as it opens.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^WHITE%^As "+ETO->query_cap_name()+" wears the armor, the eye in the center closes briefly before %^YELLOW%^bursting %^WHITE%^with a %^CYAN%^magical aura %^WHITE%^as it opens again.%^RESET%^",ETO);
    return 1;
}


int removeme(){
   tell_object(ETO,"%^BOLD%^%^WHITE%^The eye slowly closes as you take off the armor, sucking the %^CYAN%^magic %^WHITE%^back into it.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The eye slowly closes as "+ETO->query_cap_name()+" takes off the armor, sucking the %^CYAN%^magic %^WHITE%^back into it.%^RESET%^",ETO);

   return 1;
}

void set_owner(string str){
   owner = str;
   OWNED = 1;
}
