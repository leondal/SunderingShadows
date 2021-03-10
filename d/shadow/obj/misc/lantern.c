//Styx - 6/01 created base inherited file in process of -
//adding ability to check remaining fuel
//fixing problem with some increasing in fuel when they were doused
//added value for brighter to be able to use inherited file by setting that
//fixed so lantern 2 etc. works for ID and can pick which lantern to work with
//the last fix thanks to a LOT of help from Garrett

#include <std.h>

inherit OBJECT;

nosave int lit;
int fuel, full_fuel, light_time, brighter;

void create() {
  ::create();
    set_name("lantern");
    set_id( ({ "lantern", "hooded", "hooded lantern" }) );
    set_short("A hooded lantern");
    set_long(
@STYX
A basic hooded lantern to light up the dark times.  You can probably <check> it to see about how much fuel it has.
STYX
);
    set_weight(2);
    set_value(30);
    full_fuel = 2000;
    fuel = 2000;
    lit = 0;
    brighter = 1;
}

/*Plura 9302??*/
int query_lit() { return lit; }

/*Plura*/
int query_fuel() { return fuel; }

void init() {
    add_action("extinguish", "douse");
    add_action("light","light");
    add_action("extinguish","extinguish");
    add_action("check_fuel","check");
}

int light(string str) {
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(effective_light(TP) + TP->query_sight_bonus() < -1){
      notify_fail("It is too dark.\n");
      return 0;
   }
   
   if(!str) { 
      notify_fail("Light what?\n");
      return 0;
   } 
   if(!id(str))
   if (TO != present(str,ETO)) {
     notify_fail("You can only light things designed to burn and only if you have them.\n"); 
     return 0;
   }
   if(!fuel) {
       write("The lantern is out of fuel.\n");
       return 1;
     }
     if(lit) {
       write("It is already lit!\n");
       return 1;
     } 
    write ("You light the lantern.\n");
    say(TPQCN+" lights a lantern.\n", TP);
    ETO->set_property("light", brighter);
    if(fuel>200)
       call_out("warn",fuel-200);
     else
       call_out("warn", 1);
    light_time = time();
    lit = 1;
    return 1;
}

int extinguish(string str) {
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   
   if(!str) { 
      notify_fail("Douse what?\n");
      return 0;
   } 
   if(!id(str))
   if (TO != present(str,ETO)) {
     notify_fail("You can only douse things you have that are lit.\n"); 
     return 0;
   }
   if(!lit) { 
      write("The lantern is not lit!");
      return 1;
   }
    write("You extinguish the lantern.");
    say(TPQCN+" extinguishes a lantern.",TP);
    ETO->set_property("light", -brighter);
    fuel -= (time() - light_time);
    remove_call_out("warn");
    remove_call_out("go_dark");
    lit = 0;
    return 1;
}

set_fuel() {
   fuel = full_fuel;
   write("You fill your lantern with oil.");
   return 1;
}

void go_dark() {
    fuel = 0;
    ETO->set_property("light", -brighter);
    if(living(ETO)){
       tell_object(ETO, "Your lantern goes dark.");
    }
    lit = 0;
}

void warn(){
   tell_object(ETO,"The lantern is flickering and may be running low on fuel.");
   if(fuel>200)
      call_out("go_dark",200);
   else
      call_out("go_dark",fuel);
}

string query_short() {
    string str;
    str = ::query_short();
    if(lit) str = str+ " (lit)";
    return str;
}

int move(mixed dest) {
    int x;
    if(lit) ETO->set_property("light", -brighter);
    x = ::move(dest);
    if(lit) ETO->set_property("light", brighter);
    return x;
}

/* Valodin */
remove() {
   if (lit){
     ETO->set_property("light", -brighter);
     fuel -= (light_time - time());
     remove_call_out("warn");
     remove_call_out("go_dark");
     lit = 0;
   }
   return ::remove();
}

int check_fuel(string str) {
   if(!str) { 
      notify_fail("Check what?\n");
      return 0;
   } 
   if(!id(str))
   if (TO != present(str,ETO)) {
     notify_fail("You can only check the fuel in lanterns you have.\n"); 
     return 0;
   } 
   if(!living(ETO)) {
     notify_fail("You need to have it in your possession to try to guess how much fuel remains.\n");
     return 0;
   }
   if(!interactive(ETO)) {
      notify_fail("You need to have it in your possession to try to guess how much fuel remains.\n");
      return 0;
   } 
   if(lit) {
      write("You should douse it before you go shaking or opening it to try to check the fuel.");
      return 1;
   }
   switch(fuel) {
      case 1900..2000:
         tell_object(ETO,"When you shake the lantern, it sounds pretty much full of fuel.");
         break;
      case 1000..1899:
         tell_object(ETO,"When you shake the lantern, you guess it's still over half full of fuel.");
         break;
      case 100..999:
         tell_object(ETO,"When you shake the lantern, it seems to be less than half full of fuel.");
         break;
      case 1..99:
         tell_object(ETO,"The lantern feels pretty light now.  When you shake it, you realize it's probably nearly out of fuel.");
         break;
      case 0:
         tell_object(ETO,"The lantern is empty.  Maybe you should refill it with oil.");
         break;
      default:
         fuel = full_fuel;         
         write("If you get this message more than once with this lantern, you should bug report it.  The first time you get the message, the problem should be fixing itself.  If it happens again, there is a real problem.\n");
         return 1;
   }
   return 1;
}
