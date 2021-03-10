//~Circe~ 10/30/07 for new Seneca
#include <std.h>
#include "../seneca.h"

#define COLORS ({"%^BOLD%^%^CYAN%^sky blue","%^BOLD%^%^WHITE%^pure white","%^BOLD%^%^RED%^vibrant red","%^RESET%^%^MAGENTA%^majestic purple","%^YELLOW%^sunny yellow","%^BOLD%^%^GREEN%^bright green","%^RESET%^%^GREEN%^pine green","%^RESET%^%^RED%^deep maroon","%^BOLD%^%^BLACK%^inky black"})

#define STUFFS ({"%^ORANGE%^starfish","%^BOLD%^%^WHITE%^sand dollars","shark teeth","%^RESET%^%^ORANGE%^seahorses","%^BOLD%^%^WHITE%^white seashells","%^BOLD%^%^BLACK%^black seashells","%^RESET%^%^GREEN%^c%^CYAN%^o%^YELLOW%^l%^BLUE%^o%^MAGENTA%^r%^RESET%^%^MAGENTA%^f%^BOLD%^%^RED%^u%^CYAN%^l shells"})

inherit OBJECT;

nosave int lit;

int fuel, light_time;
string COLOR, STUFF;

void create(){
   ::create();
	COLOR = COLORS[random(sizeof(COLORS))];
	STUFF = STUFFS[random(sizeof(STUFFS))];
	set_value(30+random(11));
	set_name("jar candle");
	set_id(({"candle",""+COLOR+" candle","jar candle",""+COLOR+" jar candle"}));
      set_short("a "+COLOR+" jar candle%^RESET%^");
      set_long("This candle is made from "+COLOR+" wax %^RESET%^"+
         "poured into a %^BOLD%^jar %^RESET%^with a %^ORANGE%^"+
         "cork stopper%^RESET%^.  Trapped between the "+
         ""+COLOR+" wax %^RESET%^and the %^CYAN%^glass %^RESET%^"+
         "are several small, scattered "+STUFF+"%^RESET%^ that "+
         "add a nice decorative touch.  A matching "+COLOR+" "+
         "ribbon %^RESET%^has been tied near the top to add a "+
         "finishing touch.  Rising from the candle is the "+
         "fresh fragrance of an %^BOLD%^%^CYAN%^ocean breeze%^RESET%^.");
      set_lore("Crafted in Seneca by Tarolina, this particular "+
         "candle is meant to be a reminder of the sea.  Tarolina "+
         "fell in love with the sea as a young gnome in the "+
         "town of Leilani.  Her parents gave their blessing for her "+
         "to leave the town in pursuit of her life quest - to "+
         "find the perfect seashell.  Leilani was under constant "+
         "attack by spriggans, and Tarolina often waits anxiously "+
         "for word from her parents.  She makes trinkets such as "+
         "this to help bring her love of the sea to all others.");
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
    tell_room(EETO,"%^BOLD%^%^CYAN%^The crisp scent "+
       "of an ocean breeze fills the air.%^RESET%^");
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
    tell_room(EETO,"%^BOLD%^%^CYAN%^The crisp scent "+
       "of an ocean breeze fills the air.%^RESET%^");
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
