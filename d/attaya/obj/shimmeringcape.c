// Gave it lore and the ability to change its colours (since syntax is in the lore). Nienne, 10/04. //
// Moved the hidden AC points over to the enchantment for better transparency of bonuses. Nienne, 02/07
#include <std.h>
//inherit ARMOUR;
inherit "/d/common/obj/clothing/cloak.c";

void create(){
   ::create();
   set_name("cape");
   set_id(({"cape","shimmering cape","cape of displacement","minor cape of displacement","displacement cape","minor cape",}));
   set_short("%^WHITE%^%^BOLD%^Min%^RESET%^%^WHITE%^o%^BOLD%^r Ca%^RESET%^%^WHITE%^p%^BOLD%^e of %^RESET%^%^WHITE%^D%^BOLD%^isp%^RESET%^%^WHITE%^l%^BOLD%^ace%^RESET%^%^WHITE%^m%^BOLD%^ent%^RESET%^");
   set_obvious_short("%^WHITE%^%^BOLD%^Shi%^RESET%^%^WHITE%^m%^BOLD%^mer%^RESET%^%^WHITE%^i%^BOLD%^ng C%^RESET%^%^WHITE%^a%^BOLD%^pe%^RESET%^");
   set_long("This is an incredible garment, similar in design to a cloak, but much shorter and not quite "
"wide enough to cover the shoulders.  It constantly shimmers and hints at every possible shade of "
"%^WHITE%^%^BOLD%^wh%^RESET%^%^WHITE%^i%^BOLD%^te%^RESET%^ in a beautiful myriad of patterns and shapes, "
"that somehow seem to move of their own accord, though perhaps that is only a trick of the light.  The "
"patterns are cut in everything from odd to normal shapes, but the border of the cape is smooth and lined "
"perfectly.");
   set_weight(2);
   set_size(-1);
   //set_type("clothing");
   //set_limbs(({"neck",}));
   set_property("enchantment",5);
   set_value(10000);
   set_lore("%^WHITE%^%^BOLD%^Garments of this distinctive style of cape were imbued with a rather "
"interesting enchantment, by an unnamed mage in the employ of the Kinnesarudan empire.  Through the "
"enchantment, and with correctly focussed intentions by the wearer of the cloak, one could actually "
"%^YELLOW%^<will>%^WHITE%^ the garment to change colour.");
   set_property("lore difficulty",18);
   set_wear((:TO,"wear_it":));
   set_struck((:TO,"struck":));
}


void init() {
   ::init();
   add_action("changeme","will");
}

int wear_it(){
        if((int)ETO->query_highest_level() < 30) 
	{
	   tell_object(ETO,"%^BOLD%^%^RED%^The cape rejects you.");
	   return 0;
	}
	tell_object(ETO, "%^BOLD%^%^RED%^You wrap the cloak around your "+
	"neck and feel as if you have moved without taking a step.%^RESET%^");
        tell_room(EETO, "%^BOLD%^%^BLUE%^"+ETOQCN+" wears the cape and all "+
        "the colors seem to %^BOLD%^%^WHITE%^intensify%^RESET%^.",ETO);
   	return 1;
}

int struck(int damage, object what, object who){
   if(!random(3)){
     tell_room(environment(query_worn()),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+" almost appears to be in a different spot as the cape %^BOLD%^%^WHITE%^shimmers%^RESET%^!",({who,ETO}));
     tell_object(who,"%^BOLD%^%^BLUE%^As you try to hit "+ETO->query_cap_name()+", the cloak %^BOLD%^%^WHITE%^shimmers%^BOLD%^%^BLUE%^ and your target almost appears to be in a different spot%^RESET%^!");
     tell_object(ETO,"%^BOLD%^%^BLUE%^Your cape lights up with color as you watch the blow go completely by you!%^RESET%^");
     return 0;
   }
   
   return damage;
}

int changeme(string str) {
   if(!str) return 0;
   if(!TO->query_worn()) {
     tell_object(TP,"You can't feel anything from the cloak, without it wrapped about you.");
     return 1;
   }
   switch(str) {
     case "blue":
       tell_object(TP,"The cloak shimmers and takes on a myriad of %^BLUE%^bl%^BOLD%^u%^RESET%^%^BLUE%^e%^RESET%^ shades.");
       if(!TP->query_invis()) { tell_room(ETP,""+TP->QCN+"'s cloak shimmers and takes on a myriad of %^BLUE%^bl%^BOLD%^u%^RESET%^%^BLUE%^e%^RESET%^ shades.",TP); }
       TO->docolour(str);
     break;
     case "green":
       tell_object(TP,"The cloak shimmers and takes on a myriad of %^GREEN%^gre%^BOLD%^e%^RESET%^%^GREEN%^n%^RESET%^ shades.");
       if(!TP->query_invis()) { tell_room(ETP,""+TP->QCN+"'s cloak shimmers and takes on a myriad of %^GREEN%^gre%^BOLD%^e%^RESET%^%^GREEN%^n%^RESET%^ shades.",TP); }
      TO->docolour(str);
     break;
     case "red":
       tell_object(TP,"The cloak shimmers and takes on a myriad of %^RED%^r%^BOLD%^e%^RESET%^%^RED%^d%^RESET%^ shades.");
       if(!TP->query_invis()) { tell_room(ETP,""+TP->QCN+"'s cloak shimmers and takes on a myriad of %^RED%^r%^BOLD%^e%^RESET%^%^RED%^d%^RESET%^ shades.",TP); }
       TO->docolour(str);
     break;
     case "azure":
       tell_object(TP,"The cloak shimmers and takes on a myriad of %^CYAN%^azu%^BOLD%^r%^RESET%^%^CYAN%^e%^RESET%^ shades.");
       if(!TP->query_invis()) { tell_room(ETP,""+TP->QCN+"'s cloak shimmers and takes on a myriad of %^CYAN%^azu%^BOLD%^r%^RESET%^%^CYAN%^e%^RESET%^ shades.",TP); }
       TO->docolour(str);
     break;
     case "violet":
       tell_object(TP,"The cloak shimmers and takes on a myriad of %^MAGENTA%^vio%^BOLD%^l%^RESET%^%^MAGENTA%^et%^RESET%^ shades.");
       if(!TP->query_invis()) { tell_room(ETP,""+TP->QCN+"'s cloak shimmers and takes on a myriad of %^MAGENTA%^vio%^BOLD%^l%^RESET%^%^MAGENTA%^et%^RESET%^ shades.",TP); }
       TO->docolour(str);
     break;
     case "white":
       tell_object(TP,"The cloak shimmers and takes on a myriad of %^WHITE%^%^BOLD%^wh%^RESET%^%^WHITE%^i%^BOLD%^te%^RESET%^ shades.");
       if(!TP->query_invis()) { tell_room(ETP,""+TP->QCN+"'s cloak shimmers and takes on a myriad of %^WHITE%^%^BOLD%^wh%^RESET%^%^WHITE%^i%^BOLD%^te%^RESET%^ shades.",TP); }
       TO->docolour(str);
     break;
     case "black":
       tell_object(TP,"The cloak shimmers and takes on a myriad of %^BLACK%^%^BOLD%^bla%^RESET%^%^WHITE%^c%^BLACK%^%^BOLD%^k%^RESET%^ shades.");
       if(!TP->query_invis()) { tell_room(ETP,""+TP->QCN+"'s cloak shimmers and takes on a myriad of %^BLACK%^%^BOLD%^bla%^RESET%^%^WHITE%^c%^BLACK%^%^BOLD%^k%^RESET%^ shades.",TP); }
       TO->docolour(str);     
     break;
     case "gold":
       tell_object(TP,"The cloak shimmers and takes on a myriad of %^ORANGE%^gol%^BOLD%^d%^RESET%^%^ORANGE%^en%^RESET%^ shades.");
       if(!TP->query_invs()) { tell_room(ETP,""+TP->QCN+"'s cloak shimmers and takes on a myriad of %^ORANGE%^gol%^BOLD%^d%^RESET%^%^ORANGE%^en%^RESET%^ shades.",TP); }
       TO->docolour(str);
     break;
     default:
       tell_object(TP,"The cloak shimmers a little, reflecting varied shades of %^BLUE%^bl%^BOLD%^u%^RESET%^%^BLUE%^e%^RESET%^, %^GREEN%^gre%^BOLD%^e%^RESET%^%^GREEN%^n%^RESET%^, %^RED%^r%^BOLD%^e%^RESET%^%^RED%^d%^RESET%^,"
" %^CYAN%^azu%^BOLD%^r%^RESET%^%^CYAN%^e%^RESET%^, %^MAGENTA%^vio%^BOLD%^l%^RESET%^%^MAGENTA%^et%^RESET%^,"
" %^WHITE%^%^BOLD%^wh%^RESET%^%^WHITE%^i%^BOLD%^te%^RESET%^, %^BLACK%^%^BOLD%^bla%^RESET%^%^WHITE%^c%^BLACK%^%^BOLD%^k%^RESET%^ and"
" %^ORANGE%^go%^BOLD%^l%^RESET%^%^ORANGE%^d%^RESET%^."); 
     break;
   }
   return 1;
}

void docolour(string str) {
   string colour;
   switch(str) {
     case "blue":
       TO->set_short("%^RESET%^%^BLUE%^Min%^BOLD%^o%^RESET%^%^BLUE%^r Ca%^BOLD%^p%^RESET%^%^BLUE%^e of %^BOLD%^D%^RESET%^%^BLUE%^isp%^BOLD%^l%^RESET%^%^BLUE%^ace%^BOLD%^m%^RESET%^%^BLUE%^ent%^RESET%^");
       TO->set_obvious_short("%^RESET%^%^BLUE%^Shi%^BOLD%^m%^RESET%^%^BLUE%^mer%^BOLD%^i%^RESET%^%^BLUE%^ng C%^BOLD%^a%^RESET%^%^BLUE%^pe%^RESET%^");
       colour = "%^BLUE%^bl%^BOLD%^u%^RESET%^%^BLUE%^e%^RESET%^";
     break;
     case "green":
       TO->set_short("%^RESET%^%^GREEN%^Min%^BOLD%^o%^RESET%^%^GREEN%^r Ca%^BOLD%^p%^RESET%^%^GREEN%^e of %^BOLD%^D%^RESET%^%^GREEN%^isp%^BOLD%^l%^RESET%^%^GREEN%^ace%^BOLD%^m%^RESET%^%^GREEN%^ent%^RESET%^");
       TO->set_obvious_short("%^RESET%^%^GREEN%^Shi%^BOLD%^m%^RESET%^%^GREEN%^mer%^BOLD%^i%^RESET%^%^GREEN%^ng C%^BOLD%^a%^RESET%^%^GREEN%^pe%^RESET%^");
       colour = "%^GREEN%^gre%^BOLD%^e%^RESET%^%^GREEN%^n%^RESET%^";
     break;
     case "red":
       TO->set_short("%^RESET%^%^RED%^Min%^BOLD%^o%^RESET%^%^RED%^r Ca%^BOLD%^p%^RESET%^%^RED%^e of %^BOLD%^D%^RESET%^%^RED%^isp%^BOLD%^l%^RESET%^%^RED%^ace%^BOLD%^m%^RESET%^%^RED%^ent%^RESET%^");
       TO->set_obvious_short("%^RESET%^%^RED%^Shi%^BOLD%^m%^RESET%^%^RED%^mer%^BOLD%^i%^RESET%^%^RED%^ng C%^BOLD%^a%^RESET%^%^RED%^pe%^RESET%^");
       colour = "%^RED%^r%^BOLD%^e%^RESET%^%^RED%^d%^RESET%^";
     break;
     case "azure":
       TO->set_short("%^RESET%^%^CYAN%^Min%^BOLD%^o%^RESET%^%^CYAN%^r Ca%^BOLD%^p%^RESET%^%^CYAN%^e of %^BOLD%^D%^RESET%^%^CYAN%^isp%^BOLD%^l%^RESET%^%^CYAN%^ace%^BOLD%^m%^RESET%^%^CYAN%^ent%^RESET%^");
       TO->set_obvious_short("%^RESET%^%^CYAN%^Shi%^BOLD%^m%^RESET%^%^CYAN%^mer%^BOLD%^i%^RESET%^%^CYAN%^ng C%^BOLD%^a%^RESET%^%^CYAN%^pe%^RESET%^");
       colour = "%^CYAN%^azu%^BOLD%^r%^RESET%^%^CYAN%^e%^RESET%^";
     break;
     case "violet":
       TO->set_short("%^RESET%^%^MAGENTA%^Min%^BOLD%^o%^RESET%^%^MAGENTA%^r Ca%^BOLD%^p%^RESET%^%^MAGENTA%^e of %^BOLD%^D%^RESET%^%^MAGENTA%^isp%^BOLD%^l%^RESET%^%^MAGENTA%^ace%^BOLD%^m%^RESET%^%^MAGENTA%^ent%^RESET%^");
       TO->set_obvious_short("%^RESET%^%^MAGENTA%^Shi%^BOLD%^m%^RESET%^%^MAGENTA%^mer%^BOLD%^i%^RESET%^%^MAGENTA%^ng C%^BOLD%^a%^RESET%^%^MAGENTA%^pe%^RESET%^");
       colour = "%^MAGENTA%^vio%^BOLD%^l%^RESET%^%^MAGENTA%^et%^RESET%^";
     break;
     case "white":
       TO->set_short("%^WHITE%^%^BOLD%^Min%^RESET%^%^WHITE%^o%^BOLD%^r Ca%^RESET%^%^WHITE%^p%^BOLD%^e of %^RESET%^%^WHITE%^D%^BOLD%^isp%^RESET%^%^WHITE%^l%^BOLD%^ace%^RESET%^%^WHITE%^m%^BOL%^ent%^RESET%^");
       TO->set_obvious_short("%^WHITE%^%^BOLD%^Shi%^RESET%^%^WHITE%^m%^BOLD%^mer%^RESET%^%^WHITE%^i%^BOLD%^ng C%^RESET%^%^WHITE%^a%^BOLD%^pe%^RESET%^");
       colour = "%^WHITE%^%^BOLD%^wh%^RESET%^%^WHITE%^i%^BOLD%^te%^RESET%^";
     break;
     case "black":
       TO->set_short("%^BLACK%^%^BOLD%^Min%^RESET%^%^WHITE%^o%^BLACK%^%^BOLD%^r Ca%^RESET%^%^WHITE%^p%^BLACK%^%^BOLD%^e of %^RESET%^%^WHITE%^D%^BLACK%^%^BOLD%^isp%^RESET%^%^WHITE%^l%^BLACK%^%^BOLD%^ace%^RESET%^%^WHITE%^m%^BLACK%^%^BOLD%^ent%^RESET%^");
       TO->set_obvious_short("%^BLACK%^%^BOLD%^Shi%^RESET%^%^WHITE%^m%^BLACK%^%^BOLD%^mer%^RESET%^%^WHITE%^i%^BLACK%^%^BOLD%^ng C%^RESET%^%^WHITE%^a%^BLACK%^%^BOLD%^pe%^RESET%^");
       colour = "%^BLACK%^%^BOLD%^bla%^RESET%^%^WHITE%^c%^BLACK%^%^BOLD%^k%^RESET%^";
     break;
     case "gold":
       TO->set_short("%^RESET%^%^ORANGE%^Min%^BOLD%^o%^RESET%^%^ORANGE%^r Ca%^BOLD%^p%^RESET%^%^ORANGE%^e of %^BOLD%^D%^RESET%^%^ORANGE%^isp%^BOLD%^l%^RESET%^%^ORANGE%^ace%^BOLD%^m%^RESET%^%^ORANGE%^ent%^RESET%^");
       TO->set_obvious_short("%^RESET%^%^ORANGE%^Shi%^BOLD%^m%^RESET%^%^ORANGE%^mer%^BOLD%^i%^RESET%^%^ORANGE%^ng C%^BOLD%^a%^RESET%^%^ORANGE%^pe%^RESET%^");
       colour = "%^ORANGE%^go%^BOLD%^l%^RESET%^%^ORANGE%^d%^RESET%^";
     break;
     default:
       tell_object("Wow, you broke it somehow. Contact a wiz!");
     break;
   }
   TO->set_long("This is an incredible garment, similar in design to a cloak, but much shorter and not quite "
"wide enough to cover the shoulders.  It constantly shimmers and hints at every possible shade of "+colour+
" in a beautiful myriad of patterns and shapes, that somehow seem to move of their own accord, though "
"perhaps that is only a trick of the light.  The patterns are cut in everything from odd to normal shapes, "
"but the border of the cape is smooth and lined perfectly.");
}

