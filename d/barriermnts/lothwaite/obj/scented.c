#include <std.h>
#include "../lothwaite.h"

#define SCENTS ({"lilac","pine","cinnamon","ocean air","blood","autumn","apple","peach","lemon","orange","jasmine","spice","earth","rose","gardenia"})

inherit OBJECT;

nosave int lit;

int j,fuel, light_time;
string SCENT,VAR;

void create()
{
   ::create();
	j = random(sizeof(SCENTS));
	SCENT = SCENTS[j];
	set_value(25+random(25));
      set_cointype("gold");
      VAR = "a";
      if(SCENT == "ocean air" || SCENT == "autumn" || SCENT == "apple" || SCENT == "orange" || SCENT == "earth"){
         VAR = "an";
      }
	set_name(""+VAR+" "+SCENT+" scented candle%^RESET%^");
	set_id(({"candle",""+SCENT+" candle","scented","scented candle",""+SCENT+" scented candle"}));
      switch(SCENT){
         case "lilac":  
            set_long("%^BOLD%^%^MAGENTA%^This small votive candle is "+
               "dyed a light purple shade and set within a %^RESET%^"+
               "%^CYAN%^glass votive holder%^BOLD%^%^MAGENTA%^.  "+
               "The holder has been painted with delicate %^RESET%^"+
               "sprigs of lilac %^BOLD%^%^MAGENTA%^and wrapped with "+
               "a deeper %^RESET%^%^MAGENTA%^violet ribbon%^BOLD%^.  "+
               "The soft fragrance of lilac rises from the candle.  "+
               "You may light or douse the candle as you wish, both "+
               "to enjoy the fragrance and to produce a small amount "+
               "of light.%^RESET%^");
            set_short("%^BOLD%^%^MAGENTA%^a lilac scented candle%^RESET%^");
            break;
         case "pine":
            set_long("This wide pillar candle is left its natural "+
               "shade.  Just beneath the outer surface are sprigs "+
               "of %^GREEN%^pine needles %^RESET%^and tiny %^ORANGE%^"+
               "pine cones%^RESET%^.  A slender piece of natural "+
               "%^ORANGE%^twine %^RESET%^has been tied around the "+
               "middle of the candle in a bow.  The clean scent "+
               "of %^GREEN%^pine %^RESET%^rises from the candle.  "+ 
               "You may light or douse the candle as you wish, both "+
               "to enjoy the fragrance and to produce a small amount "+
               "of light.%^RESET%^");
            set_short("%^GREEN%^a pine scented candle%^RESET%^");
            break;
         case "cinnamon":
            set_long("This tall pillar candle is made of wax "+
               "dyed a %^RED%^deep red%^RESET%^ shade.  The "+
               "candle is surrounded by %^ORANGE%^cinnamon "+
               "sticks %^RESET%^glued upright to its surface, "+
               "forming its own unique holder.  The crisp scent "+
               "of cinnamon rises from the candle.  "+
               "You may light or douse the candle as you wish, both "+
               "to enjoy the fragrance and to produce a small amount "+
               "of light.%^RESET%^");
            set_short("%^RED%^a cinnamon scented candle%^RESET%^");
            break;
         case "ocean air":
            set_long("This tall pillar candle is made of wax "+
               "dyed a %^BOLD%^%^CYAN%^light azure %^RESET%^"+
               "shade.  Waves rise up the side of the candle, "+
               "descending from the %^BOLD%^%^CYAN%^azure top "+
               "%^RESET%^through %^CYAN%^darker blues %^RESET%^"+
               "to a %^BOLD%^%^BLUE%^deep ocean blue %^RESET%^"+
               "at the base.  Around the base, a line of "+
               "%^BOLD%^seashells %^RESET%^has been glued for an "+
               "added decoration.  The crisp, clean scent of the "+
               "sea rises from the candle.  "+
               "You may light or douse the candle as you wish, both "+
               "to enjoy the fragrance and to produce a small amount "+
               "of light.%^RESET%^");
            set_short("%^CYAN%^an ocean air scented candle%^RESET%^");
            break;
         case "blood":
            set_long("%^RED%^This somewhat gruesome candle has been dyed "+
               "a rusty %^BOLD%^crimson %^RESET%^%^RED%^shade.  Rather "+
               "than being round, this pillar candle is triangular "+
               "in shape.  Small %^BOLD%^bubbles %^RESET%^%^RED%^"+
               "rose to the surface during the making, causing the "+
               "candle to have a rough appearance.  The strange "+
               "metallic odor of %^BOLD%^blood%^RESET%^%^RED%^ "+
               "rises from the candle.  "+
               "You may light or douse the candle as you wish, both "+
               "to enjoy the fragrance and to produce a small amount "+
               "of light.%^RESET%^");
            set_short("%^RED%^a blood scented candle%^RESET%^");
            break;
         case "autumn" :
            set_long("%^ORANGE%^This tall, slender pillar candle "+
               "is made from orange wax.  A ring of tiny l%^YELLOW%^"+
               "e%^RESET%^%^GREEN%^a%^RED%^v%^GREEN%^e%^YELLOW%^s "+
               "%^RESET%^%^ORANGE%^in fall colors has been woven "+
               "around it near the base.  Within the leaves are "+
               "miniature %^YELLOW%^pumpkins%^RESET%^%^ORANGE%^.  "+
               "The delicate fragrance of spiced pumpkin rises "+
               "from the candle.  "+
               "You may light or douse the candle as you wish, both "+
               "to enjoy the fragrance and to produce a small amount "+
               "of light.%^RESET%^");
            set_short("%^RESET%^%^ORANGE%^an autumn scented candle%^RESET%^");
            break;
         case "apple" :
            set_long("%^RED%^This short, round candle is made in "+
               "the shape of an %^BOLD%^apple%^RESET%^%^RED%^.  "+
               "The outer portion is dyed a lovely %^BOLD%^red "+
               "shade%^RESET%^%^RED%^, while the inside is %^WHITE%^"+
               "white%^RED%^.  A slice of the 'apple' has been cut "+
               "out, letting you see the %^BOLD%^%^BLACK%^small "+
               "black seeds %^RESET%^%^RED%^inside.  A %^GREEN%^"+
               "green wick %^RED%^serves as the stem.  The crisp "+
               "aroma of a juicy apple rises from the candle.  "+
               "You may light or douse the candle as you wish, both "+
               "to enjoy the fragrance and to produce a small amount "+
               "of light.%^RESET%^");
            set_short("%^BOLD%^%^RED%^an apple scented candle%^RESET%^");
            break;
         case "peach" :
            set_long("%^ORANGE%^This wide pillar candle is made of "+
               "orange wax.  Just under the surface you can see what "+
               "look to be slices of %^YELLOW%^golden peaches%^RESET%^"+
               "%^ORANGE%^.  The sugary scent of peaches rises from "+
               "this candle.  "+
               "You may light or douse the candle as you wish, both "+
               "to enjoy the fragrance and to produce a small amount "+
               "of light.%^RESET%^");
            set_short("%^RESET%^%^ORANGE%^a peach scented candle%^RESET%^");
            break;
         case "lemon" :
            set_long("%^YELLOW%^This unusual candle is made from "+
               "sunny yellow wax.  It looks almost like a taper "+
               "candle, but it twists into a spiral midway up.  The "+
               "wick sprouts from the center of the spiral, and the "+
               "tart fragrance of lemon rises from the candle.  "+
               "You may light or douse the candle as you wish, both "+
               "to enjoy the fragrance and to produce a small amount "+
               "of light.%^RESET%^");
            set_short("%^YELLOW%^a lemon scented candle%^RESET%^");
            break;
         case "orange" :
            set_long("%^RESET%^%^ORANGE%^This squat pillar candle "+
               "is almost as wide as it is tall.  It is a bright "+
               "%^YELLOW%^orange color %^RESET%^%^ORANGE%^and "+
               "corrugated around the edges.  About midway up "+
               "the candle, a smooth %^BOLD%^%^GREEN%^green band "+
               "%^RESET%^%^ORANGE%^runs, encircling the candle and "+
               "adding a touch of decoration.  The clean, tropical  "+
               "scent of orange rises from the candle.  "+
               "You may light or douse the candle as you wish, both "+
               "to enjoy the fragrance and to produce a small amount "+
               "of light.%^RESET%^");
            set_short("%^RESET%^%^ORANGE%^an orange scented candle%^RESET%^");
            break;
         case "jasmine" :
            set_long("%^BOLD%^%^BLACK%^This ebony urn is fitted "+
               "with a lid painted with brilliant %^WHITE%^white "+
               "jasmine blossoms%^BLACK%^.  The delicate flowers "+
               "dance upon the lid, which may be lifted to reveal "+
               "a light jasmine-scented candle inside.  "+
               "You may light or douse the candle as you wish, both "+
               "to enjoy the fragrance and to produce a small amount "+
               "of light.%^RESET%^");
            set_short("%^BOLD%^a jasmine scented candle%^RESET%^");
            break;
         case "spice" :
            set_long("%^RESET%^%^ORANGE%^This taupe candle has been "+
               "poured into a round %^BOLD%^%^WHITE%^alabastar jar"+
               "%^RESET%^%^ORANGE%^.  A short piece of twine passes "+
               "through a hole in the lid and a matching on in the "+
               "jar, keeping it always close at hand.  An exotic "+
               "spicy scent rises from the candle - sandlewood mixed "+
               "with the lighter fragrances of ginger and coriandar.  "+
               "You may light or douse the candle as you wish, both "+
               "to enjoy the fragrance and to produce a small amount "+
               "of light.%^RESET%^");
            set_short("%^RESET%^%^ORANGE%^a spice scented candle%^RESET%^");
            break;
         case "earth" :
            set_long("%^GREEN%^This candle was made by first finding "+
               "a substantial %^MAGENTA%^ame%^BOLD%^th%^RESET%^%^MAGENTA%^"+
               "yst geode%^GREEN%^ and opening it.  Then, a round "+
               "recess was carved into the center, into which a "+
               "%^RESET%^natural-colored candle %^GREEN%^has been "+
               "poured.  The fragrances of the %^ORANGE%^earth "+
               "%^GREEN%^rise from the candle - moss, soil, and leaf.  "+
               "You may light or douse the candle as you wish, both "+
               "to enjoy the fragrance and to produce a small amount "+
               "of light.%^RESET%^");
            set_short("%^GREEN%^an earth scented candle%^RESET%^");
            break;
         case "rose" :
            set_long("%^BOLD%^This tall pillar candle is made of "+
               "smooth white wax.  Spiralling down the sides of the "+
               "candles are elegant %^RED%^rose %^GREEN%^vines "+
               "%^WHITE%^sculpted of colored wax.  The full fragrance "+
               "of a rose garden rises from the candle.  "+
               "You may light or douse the candle as you wish, both "+
               "to enjoy the fragrance and to produce a small amount "+
               "of light.%^RESET%^");
            set_short("%^BOLD%^%^RED%^a rose scented candle%^RESET%^");
            break;
         case "gardenia" :
            set_long("%^BOLD%^This lovely candle might well have "+
               "been grown in a garden in springtime!  It is rather "+
               "simple in design but elegant in its execution.  It "+
               "appears to be a single gardenia blossom, perfect "+
               "in every way.  The light, sweet smell of gardenias "+
               "rises from the candle.  "+
               "You may light or douse the candle as you wish, both "+
               "to enjoy the fragrance and to produce a small amount "+
               "of light.%^RESET%^");
            set_short("%^BOLD%^a gardenia scented candle%^RESET%^");
            break;
         default:  set_long("This is a candle.  It should have "+
                      "a better description, but something has "+
                      "gone wrong.  Damn.  Mail Circe and tell her.");
                   set_short("a candle");
                   break;
      }
      set_lore("Scented candles often kindle memories from days "+
         "past.  Other fragrances may help clear the mind and "+
         "senses.  And still others, it is said, may possess a "+
         "mystical energy all their own.  Regardless, scented "+
         "candles and incense have long been a part of religious "+
         "ceremonies and traditions.  This particular candle was "+
         "made by Galen, the Tallow Chandler of Lothwaite, who "+
         "has spent the last fifty years of his life among the "+
         "firbolgs there, practicing the art of candlemaking he "+
         "learned from his father as a young boy.");
      set_property("lore difficulty",8);
	set_weight(1);
      fuel = 800;
      lit = 0;
}
void init() {
    add_action("extinguish", "douse");
    add_action("light","light");
    add_action("extinguish","extinguish");
}

int light(string str) {
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
     if(effective_light(this_player()) + TP->query_sight_bonus() < -1) {
	notify_fail("It is too dark.\n");
	return 0;
    }
    if(!id(str)) {
        notify_fail("Light what?\n");
        return 0;
    }
    if(!fuel) {
        notify_fail("The candle has burned out.\n");
        return 0;
    }
    if(lit) {
        notify_fail("It is already lit!\n");
        return 0;
    }
    tell_object(TP,"You light the "+str+".\n");
    tell_room(ETP,""+TPQCN+" lights a "+str+".\n",TP);
    switch(SCENT){
       case "lilac":  tell_room(EETO,"%^BOLD%^%^MAGENTA%^The scent "+
                         "of lilacs fill the air.%^RESET%^");
                      break;
       case "pine":  tell_room(EETO,"%^GREEN%^The fresh scent of a "+
                         "mountain-grown pine fills the air.%^RESET%^");
                      break;
       case "cinnamon":  tell_room(EETO,"%^RED%^The lightly spiced "+
                         "fragrance of cinnamon rises in the air.%^RESET%^");
                      break;
       case "ocean air":  tell_room(EETO,"%^CYAN%^The crisp, clean "+
                          "scent of ocean air permeates the area.%^RESET%^");
                      break;
       case "blood":  tell_room(EETO,"%^RED%^The eerie, metallic "+
                         "fragrance of blood fills the air.%^RESET%^");
                      break;
       case "autumn":  tell_room(EETO,"%^ORANGE%^The wholesome fragrance "+
                       "of spiced pumpkin rises in the air.%^RESET%^");
                       break;
       case "apple":  tell_room(EETO,"%^BOLD%^%^RED%^The crisp aroma of "+
                         "a fresh, juicy apple fills the air.%^RESET%^");
                      break;
       case "peach":  tell_room(EETO,"%^ORANGE%^The sugary sweet smell "+
                         "of peaches fills the air.%^RESET%^");
                      break;
       case "lemon":  tell_room(EETO,"%^YELLOW%^The tart fragrance of "+
                         "lemon rises into the air.%^RESET%^");
                      break;
       case "orange":  tell_room(EETO,"%^ORANGE%^The clean, tropical "+
                         "scent of orange rises into the air.%^RESET%^");
                      break;
       case "jasmine":  tell_room(EETO,"%^BOLD%^The cool, soothing "+
                         "fragrance of jasmine rises into the air.%^RESET%^");
                      break;
       case "spice":  tell_room(EETO,"%^ORANGE%^The heady scent of sandlewood "+
                         "mixed with spices rises into the air.%^RESET%^");
                      break;
       case "earth":  tell_room(EETO,"%^ORANGE%^The solid, mossy "+
                         "smell of the earth rises into the air.%^RESET%^");
                      break;
       case "rose":  tell_room(EETO,"%^BOLD%^%^RED%^The full, soft smell "+
                        "of a rose garden fills the air.%^RESET%^");
                      break;
       case "gardenia":  tell_room(EETO,"%^BOLD%^The sweet, innocent "+
                        "smell of spring gardenias fills the air.%^RESET%^");
                      break;
       default:  tell_room(EETO,"This should be a scent.");
                 break;
    }
    call_out("fragrance",random(10)+25);
    ETO->set_property("light", 2);
    call_out("go_dark", fuel);
    light_time = time();
    lit = 1;
    return 1;
}

int extinguish(string str) {
    if(!id(str)) {
        notify_fail("Extinguish what?\n");
        return 0;
    }
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
    if(!lit) {
        notify_fail("The candle is not lit!\n");
        return 0;
    }
    tell_object(TP,"You blow out the candle.");
    tell_room(ETP,""+TPQCN+" blows out a candle.",TP);
    ETO->set_property("light", -2);
    fuel -= (time() - light_time );
    remove_call_out("fragrance");
    remove_call_out("go_dark");
    lit = 0;
    return 1;
}

void go_dark() {
    ETO->set_property("light", -2);
    fuel = 0;
    if(living(ETO))
	tell_object(ETO, "Your candle burns out.\n");
    set_short(::query_short()+" (burned down)");
    set_long("The candle has burned down to a small puddle of wax.");
    set_destroy();
    set_value(0);
    lit = 0;
    remove_call_out("fragrance");
}

void fragrance(){
    switch(SCENT){
       case "lilac":  tell_room(EETO,"%^BOLD%^%^MAGENTA%^The scent "+
                         "of lilacs fill the air.%^RESET%^");
                      break;
       case "pine":  tell_room(EETO,"%^GREEN%^The fresh scent of a "+
                         "mountain-grown pine fills the air.%^RESET%^");
                      break;
       case "cinnamon":  tell_room(EETO,"%^RED%^The lightly spiced "+
                         "fragrance of cinnamon rises in the air.%^RESET%^");
                      break;
       case "ocean air":  tell_room(EETO,"%^CYAN%^The crisp, clean "+
                          "scent of ocean air permeates the area.%^RESET%^");
                      break;
       case "blood":  tell_room(EETO,"%^RED%^The eerie, metallic "+
                         "fragrance of blood fills the air.%^RESET%^");
                      break;
       case "autumn":  tell_room(EETO,"%^ORANGE%^The wholesome fragrance "+
                       "of spiced pumpkin rises in the air.%^RESET%^");
                       break;
       case "apple":  tell_room(EETO,"%^BOLD%^%^RED%^The crisp aroma of "+
                         "a fresh, juicy apple fills the air.%^RESET%^");
                      break;
       case "peach":  tell_room(EETO,"%^ORANGE%^The sugary sweet smell "+
                         "of peaches fills the air.%^RESET%^");
                      break;
       case "lemon":  tell_room(EETO,"%^YELLOW%^The tart fragrance of "+
                         "lemon rises into the air.%^RESET%^");
                      break;
       case "orange":  tell_room(EETO,"%^ORANGE%^The clean, tropical "+
                         "scent of orange rises into the air.%^RESET%^");
                      break;
       case "jasmine":  tell_room(EETO,"%^BOLD%^The cool, soothing "+
                         "fragrance of jasmine rises into the air.%^RESET%^");
                      break;
       case "spice":  tell_room(EETO,"%^ORANGE%^The heady scent of sandlewood "+
                         "mixed with spices rises into the air.%^RESET%^");
                      break;
       case "earth":  tell_room(EETO,"%^ORANGE%^The solid, mossy "+
                         "smell of the earth rises into the air.%^RESET%^");
                      break;
       case "rose":  tell_room(EETO,"%^BOLD%^%^RED%^The full, soft smell "+
                        "of a rose garden fills the air.%^RESET%^");
                      break;
       case "gardenia":  tell_room(EETO,"%^BOLD%^The sweet, innocent "+
                        "smell of spring gardenias fills the air.%^RESET%^");
                      break;
       default:  tell_room(EETO,"This should be a scent.");
                 break;
    }
    call_out("fragrance",random(10)+25);
    return;
}

string query_short() {
    string str;
    str = ::query_short();
    if(lit) str = str+ " (%^YELLOW%^lit%^RESET%^)";
    return str;
}

int move(mixed dest) {
    int x;
    if(lit) ETO->set_property("light", -2);
    x = ::move(dest);
    if(lit) ETO->set_property("light", 2);
    return x;
}

int query_lit() { return lit; }

int query_fuel() { return fuel; }

remove() {
   if (lit) ETO->set_property("light",-2);
   return ::remove();
}

