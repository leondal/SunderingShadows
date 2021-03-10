//updated by Circe to allow psions 8/15/05
//moved to /d/common 12/14/03 by Circe.  To be used as an inherit
//for all bracers to make maintenance easier (if we change them to be
//worn on arms, etc.  Do not remove this file.
//No lore is in this file
//Changed AC around after talk with circe - Cythera 7/05
//AC to 1 and wearable at normal levels by rangers also. In line with new changes, nienne 08/07.
#include <std.h>

inherit ARMOUR;

int metal;

void create(){
    ::create();
    set_id(({"bracers"}));
    set_name("bracers");
   set_limbs(({"left arm", "right arm"}));
   set_ac(1);
    set_property("repairtype",({ "jewel","armorsmith" }));
    switch(random(20)){
       case 0..4:  set_long("%^ORANGE%^This set of bracers has "+
                      "been formed "+
                      "of cured leather hardened and tanned.  They "+
                      "are quite simple and fasten around the forearms "+
                      "with %^WHITE%^rawhide laces%^ORANGE%^.  "+
                      "The edges of the leather "+
                      "are a much %^BOLD%^%^BLACK%^deeper brown"+
                      "%^RESET%^%^ORANGE%^, adding definition "+
                      "to this plain armor.%^RESET%^");
                  // set_ac(1);
                   set_value(500+random(100));
                   metal = 0;
                   add_id("leather bracers");
                   set_obvious_short("%^ORANGE%^leather bracers%^RESET%^");
                   set_short("%^ORANGE%^leather bracers of defense%^RESET%^");
                   break;
       case 5..8:  set_long("This delicate pair of bracers has been "+
                      "made from %^BOLD%^thin silver %^RESET%^"+
                      "burnished with a %^BOLD%^h%^RESET%^a%^BOLD%^m"+
                      "%^RESET%^m%^BOLD%^e%^RESET%^r%^BOLD%^e"+
                      "%^RESET%^d finish.  The underside is made "+
                      "of softened %^ORANGE%^leather %^RESET%^to "+
                      "provide comfort to the wearer's "+
                      "forearms.  The bracers may be tied on with "+
                      "%^ORANGE%^leather thongs%^RESET%^.");
                   //set_ac(1);
                   set_value(600+random(200));
                   metal = 1;
                   add_id("silver bracers");
                   set_obvious_short("%^RESET%^%^BOLD%^silver bracers%^RESET%^");
                   set_short("%^RESET%^%^BOLD%^silver bracers of defense%^RESET%^");
                   break;
       case 9..11:  set_long("%^BOLD%^Highly polished %^YELLOW%^"+
                      "gold %^WHITE%^forms the "+
                      "beautiful outer shell of these fashionable "+
                      "bracers.  The surface has been covered "+
                      "with delicate %^YELLOW%^etched filigree"+
                      "%^WHITE%^, adding a touch "+
                      "of elegance.  The undersides of the bracers "+
                      "have been lined with white silk to ensure "+
                      "the wearer's comfort, and the bracers attach "+
                      "to the wearer's forearms by intricate "+
                      "%^YELLOW%^golden clasps%^WHITE%^.%^RESET%^");
                   add_id("golden bracers");
                   metal = 1;
                   set_obvious_short("%^YELLOW%^golden bracers%^RESET%^");
                   set_short("%^YELLOW%^golden bracers of defense%^RESET%^");
                   //set_ac(1);
                   set_value(700+random(300));
                   break;
       case 12..14:  set_long("Cool %^BOLD%^ivory %^RESET%^has "+
                      "been shaped into "+
                      "thin curving bracers that fit snuggly "+
                      "around the wearer's forearms.  %^CYAN%^"+
                      "Strange runes %^RESET%^have been carved "+
                      "into the surface of the %^BOLD%^ivory "+
                      "%^RESET%^and have become %^ORANGE%^brown "+
                      "%^RESET%^with "+
                      "age.  No lining has been attached to the "+
                      "bracers, but they seem to be unusually "+
                      "comfortable and attach themselves without "+
                      "the aid of physical clasps.");
                   set_value(800+random(400));
                   //set_ac(1);
                   add_id("ivory bracers");
                   metal = 0;
                   set_obvious_short("%^RESET%^%^BOLD%^ivory bracers%^RESET%^");
                   set_short("%^RESET%^%^BOLD%^ivory bracers of defense%^RESET%^");
                   break;
       case 15..17:  set_long("%^BOLD%^%^BLACK%^These bracers "+
                      "are formed from solid, curving pieces "+
                      "of g%^RESET%^l%^BOLD%^%^BLACK%^i%^RESET%^t"+
                      "%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^r"+
                      "%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^g "+
                      "%^BOLD%^%^BLACK%^jet that is black as a "+
                      "%^RESET%^midnight sky%^BOLD%^%^BLACK%^.  The jet "+
                      "is impeccably smooth, so much so that even "+
                      "the long hinge running down the side disappears "+
                      "when the bracers are clasped.%^RESET%^");
                   //set_ac(1);
                   set_value(800+random(400));
                   add_id("jet bracers");
                   metal = 0;
                   set_obvious_short("%^BOLD%^%^BLACK%^jet bracers%^RESET%^");
                   set_short("%^BOLD%^%^BLACK%^jet bracers of defense%^RESET%^");
                   break;
       case 18..19:  set_long("%^BOLD%^%^WHITE%^These bracers are "+
                      "made from flawless %^RESET%^%^CYAN%^adamantium"+
                      "%^BOLD%^%^WHITE%^, one of the strongest substances "+
                      "known to the world.  The metal is highly polished "+
                      "and studded with all manner of %^BOLD%^%^RED%^"+
                      "j%^RESET%^%^ORANGE%^e%^YELLOW%^w%^GREEN%^e"+
                      "%^CYAN%^l%^BLUE%^s%^BOLD%^%^WHITE%^.  The inner "+
                      "portion of the bracers has been lined with "+
                      "the %^RESET%^softest wool%^BOLD%^, making "+
                      "the bracers "+
                      "exquisitely comfortable.");
                   //set_ac(2);
                   set_value(900+random(400));
                   add_id("jeweled bracers");
                   metal = 1;
                   add_id("adamantium bracers");
                   set_obvious_short("%^RESET%^%^CYAN%^jeweled bracers%^RESET%^");
                   set_short("%^RESET%^%^CYAN%^jeweled bracers of defense%^RESET%^");
                   break;
    }
    set_type("bracer");
    set_limbs(({"left arm", "right arm"}));
    set_weight(2);
    set_wear( (:TO,"check":) );
    set_size(-1);
}

int check(){
   int level;

   if(objectp(ETO) && ETO->query_property("no bracers"))
   {
       tell_object(ETO,"You are currently using an object that cannot be worn with bracers.");
       return 0;
   }
   // letting everybody wear bracers now if they want -Ares
   //if(TP->is_class("psion") || TP->is_class("mage") || TP->is_class("bard") || TP->is_class("thief") || TP->is_class("ranger")) return 1;
   //write("Your class does not allow you to use these.");
   //return 0;
   return 1;
}

int is_metal() { return metal; }

/*
Taken out since it's now being used as an inherit, and it was messing with
the shorts being set.  Changed to use set_obvious_short.  Circe 1/17/04
void set_property(string prop, mixed value) {
    ::set_property(prop, value);
    if(prop == "enchantment") {
        set_short("Bracers of Defense");
        set_name("bracers of defense");
    }
}
*/
