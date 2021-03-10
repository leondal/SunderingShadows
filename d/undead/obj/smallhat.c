#include <std.h>
inherit ARMOUR;
int FLAG;

void create(){
    ::create();
    set_name("leather hat");
    set_id(({"fedora","hat","leather hat","leather fedora","stylish hat"}));
    set_short("%^RESET%^%^ORANGE%^a s%^BOLD%^%^BLACK%^t%^RESET%^y%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^h brown l%^BOLD%^%^BLACK%^e%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^r fedora%^RESET%^");
    set_obvious_short("%^RESET%^%^ORANGE%^a stylish leather hat%^RESET%^");
    set_long("%^ORANGE%^Made from a pale, earthy-brown leather, this hat is "
"styled with a wide, flexible brim that provides protection for the face and "
"sheds water off the collar instead of down one's back.  The cap is pinched to "
"a %^RESET%^point %^ORANGE%^in the front, creating a pair of ridges that angle "
"back around the top of the head.  A strip of %^BOLD%^%^BLACK%^black silk "
"%^RESET%^%^ORANGE%^ribbon is fitted around the inner edge of the brim, "
"providing a little contrast as well as a place to secure a %^RESET%^feather "
"%^ORANGE%^or other such %^MAGENTA%^token%^ORANGE%^.  The brim can be turned up "
"or down in the front, providing a little shade for the eyes, or creating a "
"different style all together.%^RESET%^\n");
    set_lore("Like the 'wide brimmed gray', a wool hat of similar styling, "
"that became so popular with the docks men and sailors in the mid-fifth century "
"the leather fedora was favored by the city goers for many of the same reasons"
".  The wide brim could be turned up or down depending on the mood of the person"
".  Providing shade or a clear view, while shedding water and granting "
"protection from the sun.  That the brim could also be shaped and set with a "
"pin or other fixture added to the appear of the hat, which some even had "
"enchanted so that their sense of style wasn't obscured by their need for "
"protective wear.");
    set_weight(3);
    set_value(500);
    set_property("lore difficulty",18);
    set_type("leather");
    set_limbs(({ "head" }));
    set_size(1);
    set_property("enchantment",4);
    while (query_property("enchantment") != 4) {
      remove_property("enchantment");
      set_property("enchantment",4);
    }
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    FLAG = 0;
}

int wear_func(){
    tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" slips "+ETO->QP+" fedora on "
"with practiced flare.%^RESET%^",ETO);
    tell_object(ETO,"%^BOLD%^%^BLACK%^You slide your fedora on and realize you "
"could lift or lower the brim to give you a bit of shade.%^RESET%^");
    return 1;
}

int remove_func(){
    tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" takes "+ETO->QP+" hat off and "
"shakes out "+ETO->QP+" hair.%^RESET%^",ETO);
    tell_object(ETO,"%^BOLD%^%^BLACK%^The hat lifts off your head and you feel "
"just a little less stylish.%^RESET%^");
    return 1;
}

void init() {
   ::init();
   add_action("dark_func","lower");
   add_action("light_func","lift");
}

int dark_func(string str) {
   if(!objectp(ETO)) return 0;
   if(!userp(ETO)) return 0;
   if(!str) {
     notify_fail("What do you want to lower?\n");
     return 0;
   }
   if(str != "hat" && str != "brim") {
     notify_fail("You could try <lower brim>.\n");
     return 0;
   }
   if(!TO->query_worn()) {
     notify_fail("You should wear the hat first.\n");
     return 0;
   }
   if(FLAG) {
     notify_fail("The brim is already down, any further and you wouldn't be able to see!\n");
     return 0;
   }
   tell_object(ETO,"You tilt the hat's brim down to shade your eyes.");
   tell_room(EETO,""+ETOQCN+" tilts the brim of "+ETO->QP+" hat down to shade "+ETO->QP+" eyes.",ETO);  
   ETO->add_sight_bonus(-3);
   FLAG = 1;
   return 1;
}

int light_func(string str) {
   if(!objectp(ETO)) return 0;
   if(!userp(ETO)) return 0;
   if(!str) {
     notify_fail("What do you want to lift?\n");
     return 0;
   }
   if(str != "hat" && str != "brim") {
     notify_fail("You could try <lower brim>.\n");
     return 0;
   }
   if(!FLAG) {
     notify_fail("You can already see just fine.\n");
     return 0;
   }
   tell_object(ETO,"You lift the brim of the hat back up, so you can see clearly.");
   tell_room(EETO,""+ETOQCN+" lifts the brim of "+ETO->QP+" hat back up to see clearly.",ETO);  
   ETO->add_sight_bonus(3);
   FLAG = 0;
   return 1;
}
