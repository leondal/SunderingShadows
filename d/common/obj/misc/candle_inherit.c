#include <std.h>

inherit OBJECT;

nosave int lit;
int fuel, light_time;

void create() {
  ::create();
    set_name("candle");
    set_id( ({ "candle" }) );
    set_short("A candle");
    set_long("This is a candle.");
    fuel = 1200;
    lit = 0;
}

void init() {
	::init();
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
}

string query_short() {
    string str;
    str = ::query_short();
    if(lit) str = str+ " (lit)";
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

