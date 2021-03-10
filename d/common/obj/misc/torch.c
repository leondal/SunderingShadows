#include <std.h>

inherit "/d/common/obj/weapon/club";

nosave int lit;
int fuel, light_time;

void create() {
  ::create();
    set_name("torch");
    set_id( ({ "torch" }) );
    set_short("A torch");
    set_long("A torch to light up the dark parts of your life. You can <light>, you can <extinguish> or <douse> it.\n");
    set_weight(1);
    set("coin_type","copper");
    set_value(5);
    set_cointype("copper");
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
        notify_fail("The torch is out of fuel.\n");
        return 0;
    }
    if(lit) {
        notify_fail("It is already lit!\n");
        return 0;
    }
    write ("You light the torch.\n");
    say(this_player()->query_cap_name()+" lights a torch.\n", this_player());
    environment(this_object())->set_property("light", 2);
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
        notify_fail("The torch is not lit!\n");
        return 0;
    }
    write("You extinguish the torch.\n");
    say(this_player()->query_cap_name()+" extinguishes a torch.\n",
        this_player());
    environment(this_object())->set_property("light", -2);
    fuel -= (time() - light_time );
    remove_call_out("go_dark");
    lit = 0;
    return 1;
}

void go_dark() {
    environment(this_object())->set_property("light", -2);
    fuel = 0;
    if(living(environment(this_object())))
	tell_object(environment(this_object()), "Your torch goes dark.\n");
    set_short(::query_short()+" (out of fuel)");
    set_long("The torch has exhausted its fuel.\n");
    set_destroy();
    set("coin_type","electrum");
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

    if(lit) environment(this_object())->set_property("light", -2);
    x = ::move(dest);
    if(lit) environment(this_object())->set_property("light", 2);
    return x;
}

int query_lit() { return lit; }

int query_fuel() { return fuel; }

remove() {
   if (lit) environment(this_object())->set_property("light",-2);
   return ::remove();
}
