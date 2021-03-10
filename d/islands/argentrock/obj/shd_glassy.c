//updated by Cythera 8/05 with new desc, lore, etc.
//nerfed a little, 3 stat bonuses on a trash drop is highly unbalanced so one now removed. N, 1/20
#include <std.h>

inherit "/d/common/obj/armour/shield.c";
int is_metal() { return 0; }
string owner;

void create() {
   ::create();
   set_name("glass dragon shield");
   set_id(({"shield","glass dragon shield","glass shield"}));
   set_obvious_short("%^BOLD%^%^CYAN%^A darkened glassteel shield%^RESET%^");
   set_short("%^BOLD%^%^CYAN%^Glassteel Dragon Shield%^RESET%^");
   set_long("%^RESET%^%^CYAN%^This round shield has been constructed "+
      "entirely of glass.  The glass has been %^BOLD%^%^BLACK%^"+
	"darkened%^RESET%^%^CYAN%^ to a glossy black shade.  A relief image "+
	"of a snarling dragon rests on the front of this large shield."+
	"  The dragon's %^RESET%^%^RED%^ruby red%^CYAN%^ eyes and "+
	"%^GREEN%^jade green%^CYAN%^ scales are dulled and darkened."+
	"  The convex kite shield features leather strips made from "+
	"%^BOLD%^%^GREEN%^green dragon%^RESET%^%^CYAN%^ skin.%^RESET%^");
   set_lore("Once used the famous wyrm-slayer Siegfied Elrond, this"+
	" glass dragon shield was said to be able to protect its ower"+
	" from the breath of any known dragon in the lands.  The "+
	"glassteel shield use to be praised for its crystal clear "+
	"beauty.  The relief image of the dragon on the front of the"+
	" shield was said to morph and change color, cycling through "+
	"known types of dragon.  Though this does match Siegfied's famed"+
	" shield, something great and powerful must have happened to"+
	" permanatley darken the glassteel shield and strip away the "+
	"illusions it once bore.  Who is to say if even it retains its "+
	"famed ability to resist dragon breath.");
   set_property("lore",15);
   set_value(1000);
   set_property("enchantment",5);
//   set_item_bonus("intelligence",4);
   set_item_bonus("athletics",4);
   set_item_bonus("fire resistance",35);   
   set_struck((:TO,"strikeme":));
   set_wear( (: TO,"limited_wear" :) );
   set_remove( (: TO,"unwear_msg" :) );
}

void init() {
   ::init();
   if(interactive(TP) && TP == environment(TO) && !owner) {
      owner = TPQN;
   }
}

int limited_wear() {
   if( !interactive(TP) )
      return 1;
   if((int)TP->query_level() < 20 ){
      tell_object(ETO,"%^BOLD%^%^BLACK%^The glassteel shield refuses"+
		" to bond with you and vanishes!");
      TO->remove();
      return 0;
   }
   else {
      if( (string)TPQN != owner ) {
         tell_room(EETO,"%^BOLD%^%^BLACK%^The glassteel shield "+
             "refuses to fit "+ETOQCN+"'s arm!\nThe eyes of the"+
		" dragon blaze to life and the shield melts away.",ETO);
         tell_object(ETO,"%^BOLD%^%^BLACK%^The glassteel shield "+
             "refuses to fit your arm!\nThe eyes of the dragon"+
		 " blaze to life and the shield melts away.");
         ETO->add_attacker(TO);
         ETO->continue_attack();
         ETO->do_damage("torso",50 + random(50));
         ETO->remove_attacker(TO);
         TO->remove();
         return 0;
      }
// why is this alignment locked? Removing, no real reason to limit from broader playerbase. N, 1/20
/*      else {
         switch( (int)ETO->query_alignment() ) {
            case 2:
			case 4:
            case 5:
			case 6:
            case 8: */
               tell_object(ETO,"%^CYAN%^The eyes of the dragon blaze"+
			" with a %^BOLD%^%^RED%^bright red%^RESET%^%^CYAN%^"+
			" light as the shield recognizes you as its new master.");
               tell_room(EETO,"%^CYAN%^ The eyes of the dragon on "+ETOQCN+"'s"+
			" blazes with a %^BOLD%^%^RED%^bright red%^RESET%^"+
			"%^CYAN%^ light as "+ETO->QS+" wears it.",ETO);
               return 1;
/*               break;
            default:
               tell_room(EETO,"%^BOLD%^%^CYAN%^The glassteel shield "+
                  "refuses to fit "+ETOQCN+"'s arm and grows red hot!",ETO);
               tell_object(ETO,"%^BOLD%^%^CYAN%^The glassteelshield "+
                   "refuses to fit your arm and grows red hot!");
               ETO->add_attacker(TO);
               ETO->continue_attack();
               ETO->do_damage("torso",80 + random(50));
               ETO->remove_attacker(TO);
               return 0;
         }
      } */
   }
}
int unwear_msg() {
	tell_room(environment(query_worn()),"%^BOLD%^%^RED%^The bright red "+
		"light in the dragon's eyes on "+ETOQCN+"'s shield goes dim"+
		" once more.",ETO);
      tell_object(ETO,"%^BOLD%^%^RED%^The bright red light in the dragon's"+
		" eyes on your shield goes dim once more.");
   return 1;
}

int strikeme(int damage, object what, object who){
        if(random(1000) < 250){
        tell_room(environment(query_worn()),"%^BOLD%^%^RED%^The bright "+
		"red eyes of the dragon image on "+ETOQCN+"'s shield starts "+
		"to pulse rhythmically at "+who->QCN+"!",({ETO,who}));
        tell_object(ETO,"%^BOLD%^%^RED%^The bright red eyes of the dragon image"+
		" on your shield starts to pulse rhythmically at "+who->QCN+"!");
        tell_object(who,"%^BOLD%^%^RED%^You feel yourself drawn to the "+
		"pulsing red eyes of the dragon image on "+ETOQCN+"'s shield"+
		" for a moment!");
        who->set_paralyzed(1,"You are confused from the shield!");
        return 1;
      }
}
