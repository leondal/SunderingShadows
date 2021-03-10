#include <std.h>
inherit "/d/common/obj/weapon/hhlance";

int charged;

void create() {
    ::create();
    set_name("lance");
    set_id(({"lance","glass lance","heavy lance","heavyweight lance","prism lance","Prism Lance"}));
    set_short("%^RESET%^%^CYAN%^P%^BOLD%^r%^WHITE%^i%^RESET%^%^ORANGE%^s%^YELLOW%^m L%^RESET%^%^ORANGE%^a%^WHITE%^%^BOLD%^n%^CYAN%^c%^RESET%^%^CYAN%^e%^RESET%^");
    set_obvious_short("%^RESET%^%^CYAN%^a heavyweight lance made of glass%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^The pole of this glimmering, heavyweight lance "
"is forged out of a thin sleeve of %^BLACK%^clear glass %^WHITE%^that glints "
"like %^CYAN%^pale ice %^WHITE%^in the light. This ice-like appearance is "
"enhanced by the ribbons of %^YELLOW%^wire %^WHITE%^that twist and bundle deep "
"within the glassy shaft, passing through what appears to be thousands of pea-"
"sized, pearl-shaped %^CYAN%^diamonds%^WHITE%^. Perfectly balanced, the butt of "
"the lance is wrapped in white leather and banded with %^YELLOW%^copper wire "
"%^WHITE%^that flows out from under the platinum capped butt of the lance and "
"merges into the %^YELLOW%^wires %^WHITE%^that twist about the protective "
"%^BLACK%^titanium guard%^WHITE%^. Designed to protect the grip, and thus the "
"hands of the wielder, the large circular guard is decorated with a network of "
"crisscrossing %^YELLOW%^wires %^WHITE%^that lead to and away from a pair of "
"glittering gemstones. One, a diamond cut %^GREEN%^emerald%^WHITE%^, the other "
"a square cut %^RED%^ruby%^WHITE%^. Each ringed in wire that connects them "
"together with an intricate design of overlapping copper and platinum"
".%^RESET%^\n");
   set_value(5500);
   set_property("enchantment",5);
   set_item_bonus("attack bonus",3);
   set_item_bonus("sight bonus",2);
   set_lore("The story behind this lance is a long one indeed. It begins with "
"the tale of an adventuring party that took to exploring the most remote and "
"difficult to reach places in order to find long lost treasure and continues on "
"through their successes and failures and the eventual addition of Sylren the "
"Lordless Knight. Sylren joined the adventuring group late in their career, "
"when most were considering retiring and enjoying their fabulous wealth. It was "
"a late night and after much drinking and storytelling the group was getting "
"ready to retire to their rooms when Sylren stepped from the shadows and "
"offered them a chance they couldn't resist. 'Slay a God,' said this knight "
"without a lord or god to follow. And how could this band of great heroes "
"resist such an offer? 'But,' Sylren claimed, 'god-slaying weapons and armor "
"would need to be forged.' To this task the next twenty years and the majority "
"of the group's fortune were spent until each of the four owned an item created "
"for the task at hand. Only then did Sylren lead them to where the entry lay. "
"Down into the earth they traversed, past trap and guardian till they faced the "
"God himself. Only to be betrayed by the one that had guided them. It is said "
"that Sylren had a god after all, but She did not protect him in the end and "
"his corpse rots with the rest deep inside the halls of Ibrandul.");
   set_property("lore difficulty",18);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
   charged = 0;
}

int wield_fun(){
    tell_object(ETO,"%^BOLD%^%^WHITE%^As you grip the lance solidy and set it into position the %^GREEN%^green emerald"
"%^WHITE%^ begins to glow and a faint humming sound can be heard coming from within the lance.%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^WHITE%^As "+ETOQCN+" grips the lance solidy and sets it into position the %^GREEN%^green "
"emerald%^WHITE%^ begins to glow and a faint humming sound can be heard coming from within the lance.%^RESET%^",ETO);
    return 1;
}

int unwield_fun() {
   tell_object(ETO,"%^BOLD%^%^WHITE%^You release the lance and the faint humming ceases as the %^RED%^red ruby "
"%^WHITE%^begins to glow once more.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" releases the lance and the faint humming ceases as the %^RED%^red ruby "
"%^WHITE%^begins to glow once more.%^RESET%^",ETO);
   return 1;
}

int hit_fun(object targ) {
   ::check(targ);
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   targ = ETO->query_current_attacker();
   if(!objectp(targ)) return 1;

   if(!random(8)){
     if(charged < (3+ random(6))) {
       tell_room(EETO,"%^YELLOW%^Sparks %^WHITE%^fly and the glass of the lance %^RED%^glows%^WHITE%^ as the %^RESET%^%^ORANGE%^wires%^BOLD%^%^WHITE%^ within begin to heat and charge with %^YELLOW%^energy%^WHITE%^.%^RESET%^");
       charged ++;
     }
     else {
       tell_object(targ,"%^BOLD%^%^WHITE%^A high pitched whine takes up as %^YELLOW%^energy %^WHITE%^pulses along the "
"%^CYAN%^glassy length%^WHITE%^ of the lance. The waves of energy pour along the shaft until suddenly spraying from the "
"tip in a pulse of pure %^YELLOW%^power %^WHITE%^to strike you!%^RESET%^");
       tell_room(EETO,"%^BOLD%^%^WHITE%^A high pitched whine takes up as %^YELLOW%^energy %^WHITE%^pulses along the "
"%^CYAN%^glassy length%^WHITE%^ of the lance. The waves of energy pour along the shaft until suddenly spraying from the "
"tip in a pulse of pure %^YELLOW%^power %^WHITE%^to strike "+targ->QCN+"!%^RESET%^",targ);
       charged = 0;
       return (random(10)+25);
     }
   }
   return 1;
}