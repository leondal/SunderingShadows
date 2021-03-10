/* revamped to make it a little more user friendly, cleaned up use of variables, made a lit fire weigh too much to be easy to carry (think encumbrance), added color & room emotes on creation of fire, and have them put the wood down before lighting it.  *Styx*  10/28/02
*/
/*
Added ability to cook various things so long as they are raw food.  Any food able to be cooked will need set_raw(x); with x being a number from 1-10.  How raw a meat is will determine how long it takes to cook.  Limbs are automatically set.  Circe 7/27/04
*/

#include <std.h>
#include <daemons.h>
inherit OBJECT;

int lit, fuel;
object meat;

void init() {
	::init();
	add_action("make_fire","start");
	add_action("douse_fire","douse");
	add_action("fuel_fire","fuel");
	add_action("cook_em","cook");
}

void create() {
    ::create();
    set_id( ({"wood", "firewood"}) );
    set_name("wood");
    set_short("Some firewood");
    set_weight(20);
    set_long("A bundle of firewood.  If you had something to create a spark, "
	"you could probably %^BOLD%^%^RED%^<%^WHITE%^start fire%^RED%^>%^RESET%^ with it.\n");
    set_value(0);
    lit=0;
    fuel = (250 + random(250));
}

int adj_lit(int x) { lit += x; }
int add_fuel(int x) { fuel += x; }
int query_fuel() { return fuel; }

void check_fire(object fire) {
    if((int)fire->query_fuel() < 1800) {
        fire->set_short("A nice %^YELLOW%^ca%^RED%^mp%^YELLOW%^fi%^RED%^re%^RESET%^");
	    fire->set_long("A lit campfire.  More wood could probably fuel it later.");
        return;
    }
    if((int)fire->query_fuel() < 4000) {
        fire->set_short("A blazing %^YELLOW%^ca%^RED%^mp%^YELLOW%^fi%^RED%^re%^RESET%^");
        fire->set_long("A blazing campfire.  The heat given off of it is "+
        "beginning to become oppressive.  More fuel can always be "+
        "added, but it is not needed.");
        return;
    }
    if((int)fire->query_fuel() >= 4000 && (int)fire->query_fuel() <= 6000) {
        fire->set_short("An out of control %^YELLOW%^f%^RED%^ir%^YELLOW%^e%^RESET%^");
        fire->set_long("This fire is blazing out of control and rapidly "+
        "approaching a disaster, adding more fuel to it would be "+
        "dangerous and unwise.");
        return;
    }
    else {
        fire->set_short("A blazing, out of control %^YELLOW%^f%^RED%^ir%^YELLOW%^e%^RESET%^");
        fire->set_long("This fire is blazing out of control and "+
        "has peaked to the point where being near it is dangerous!");
        fire->begin_burning(fire);
        return;
    }
}

void monstrous_fire(object fire) {
    object *vics;
    object eto;
    int x;
    if(!objectp(fire)) return;
    eto = environment(fire);
    if(!objectp(eto)) return;
    if((int)fire->query_fuel() < 6000) return;
    vics = all_living(eto);
    tell_room(eto,"%^RED%^The blazing and out of control fire scorchers "+
    "everything in the area!%^RESET%^");

    for(x = 0;x < sizeof(vics);x++) {
        if(vics[x]->query_true_invis()) continue;
        tell_object(vics[x],"%^RED%^Your body is seared by the "+
        "heat from the intense fire!%^RESET%^");
        tell_room(eto,vics[x]->QCN+"%^RED%^'s body is seared by "+
        "heat from the intense fire!%^RESET%^",vics[x]);
        set_property("magic",1);
        vics[x]->do_damage("torso",roll_dice(1,10));
        set_property("magic",-1);
        vics[x]->add_attacker(fire);
        vics[x]->continue_attack();
        if(objectp(vics[x])) {
            vics[x]->remove_attacker(fire);
        }
        continue;
    }
    if((int)fire->query_fuel() >= 6000) {
        fire->begin_burning(fire);
        return;
    }
}

void begin_burning(object fire) {
    call_out("monstrous_fire",75,fire);
}

void heart_beat() {
    int tmp;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;

    if(fuel > 0) {
        fuel--;
        tmp++;
        if(tmp > 1200) {
            check_fire(TO);
            tmp = 0;
        }
        return;
    }
    if(fuel < 0) {
        remove();
        return;
    }
}

int make_fire(string str) {
    object ob;
    string * classes;
    if (query_verb()=="make"){
      classes = TP->query_classes();
      if (member_array("thief", classes)!=-1 ||member_array("thief", classes)!=-1){
        notify_fail("Try 'start fire'");
        return 0;
      }
    }

    if(ETP->query_property("indoors")){
	  write("You need to be outdoors to build a fire!");
	  return(1);
	}

    if(present("fire",ETP)){
	    write("You already have a fire lit!");
	    return(1);
	}

	if(ETO == TP) {
	   write("You should put the wood down before you try to make a fire.");
	   return 1;
	}

	if(ob=present("flint",TP)) {
 	   write("You strike the flint and steel over some firewood.");
	   tell_room(ETO, TPQCN+" strikes a flint to steel over some firewood.", TP);
	   TP->set_paralyzed(12, "%^BOLD%^%^RED%^You are busy starting the fire!%^RESET%^");
	   call_out("fire_started", 8);
       return(1);
	}
	write("You have no flint and steel.");
	return(1);
}

void fire_started() {
	if(!objectp(ETO)) return;
	if(!ETO->is_room()) {
		tell_object(TP, "The wood is no longer on the ground!");
		return;
	}
	tell_room(ETO,"After a few tries and some attention, a small "
	 "campfire %^BOLD%^%^RED%^blazes %^RESET%^up.");
	lit=(random(2)+1);
	set_id(({"fire", "campfire", "mirror"}));
	set_name("fire");
	set_value(1001);
	check_fire(TO);
	set_weight(100000); // don't want them carrying it around
	set_heart_beat(1);
	ETO->set_property("light", lit);
	set_property("no animate", 1);
	//call_out("remove",fuel);
}

void reset() {
    ::reset();
    if(lit) {
        switch(random(4)) {
	        case 0:
                tell_room(ETO, "The campfire sputters and a few sparks fly.");
		        break;
	        case 1:
                tell_room(ETO, "The wind stirs the campfire and some sparks "
		        "drift off on the breeze.");
		        break;
            case 2:
                tell_room(ETO, "Some smoke billows from the campfire into your face.");
		        break;
            default:  return;
        }
    }
}

void go_out() {
    if(!objectp(TO))  return;
    tell_room(ETO, "A campfire goes out.");
    ETO->set_property("light", -lit);
    remove_call_out("cook_em");
    lit = 0;
}

// with the weight & no animate it shouldn't be moving, but just to be safe
// borrowed from lantern code by *Styx*
int move(mixed dest) {
    int x;
    if(lit) ETO->set_property("light", -lit);
    x = ::move(dest);
    if(lit) ETO->set_property("light", lit);
    return x;
}

void fuel_msg(object fire, object vic) {
    object eto;
    eto = environment(vic);

    if((int)fire->query_fuel() < 1800) {
        tell_object(vic,"You add the wood to the fire and it %^RED%^blazes%^RESET%^ up.");
	    tell_room(eto, vic->QCN+" adds some wood to the fire and it %^RED%^blazes%^RESET%^ up.", vic);
        return;
    }
	if((int)fire->query_fuel() < 4000) {
        tell_object(vic,"You add more wood to the fire, its heat "+
        "beginning to become oppressive, and it "+
        "%^RED%^blazes%^RESET%^ up even more "+
        "powerfully!");

        tell_room(eto,vic->QCN+" adds more wood to the fire "+
        "and it %^RED%^blazes%^RESET%^ up even more "+
        "powerfully as the heat from it begins to "+
        "become oppressive!",vic);
        return;
    }
    if((int)fire->query_fuel() < 6000) {
        tell_object(vic,"You add more wood to the fire and barely "+
        "get your arm back in time, as the %^RED%^flames"+
        "%^RESET%^ begin burning out of control!");

        tell_room(eto,vic->QCN+" barely pulls "+vic->QP+" arm "+
        "back in time as the %^RED%^flames%^RESET%^ "+
        "begin burning out of control!",vic);
        return;
    }
    if((int)fire->query_fuel() >= 6000) {
        tell_object(vic,"You feed the already out of control %^RED%^"+
        "fire%^RESET%^ and your arm is burned before you "+
        "can pull away!");

        tell_room(eto,vic->QCN+" feeds the already out of control "+
        "%^RED%^fire and is burned by its dangerous flames before "+
        vic->QS+ " can pull "+vic->QP+" arm away!",vic);

        set_property("magic",1);
        vic->do_damage("left arm",roll_dice(5,6));
        vic->add_attacker(TO);
        vic->continue_attack();
        if(objectp(vic)) {
            vic->remove_attacker(TO);
        }
        set_property("magic",-1);
        return;
    }
}

int fuel_fire(string str)
{
    object fire;
    if (present("wood", TP)) {
        if (fire = present(str, ETP)) {
            if (base_name(fire) != "/d/common/obj/misc/wood") {
                write("This is not the fire you're looking for.");
                return 1;
            }
            fire->add_fuel(present("wood", TP)->query_fuel());
            fuel_msg(fire, TP);
            check_fire(present("fire", ETP));
            if (ETP->query_property("light") < 3) {
                present("fire", ETP)->adj_lit(1);
                ETP->set_property("light", 1);
            }
            present("wood", TP)->remove();
            return (1);
        }
        write("There is no fire! You need to make one first!");
        return 1;
    }
    write("You need wood in hand to fuel the fire. Try gathering some!");
    return 1;
}

int douse_fire(string str) {
    if(!present("fire"))   return 0;
    if(!objectp(TO))  	   return 0;
    if(str == "fire" || str == "campfire"){
       if((int)present("fire",ETP)->query_fuel() < 4000) {
           write("You kick dirt over the campfire and manage to douse it.");
           tell_room(ETP, TPQCN+" kicks some dirt over the campfire and douses it.", TP);
           remove();
           return 1;
       }
       else {
           write("The fire is far too out of control, it must "+
           "be allowed to burn down, before you can put it out!");
           return 1;
       }
   }
   return 0;
}

void remove() {
    if(lit) {
        go_out();
    }
    ::remove();
}

int cook_em(string str) {
    object meat,fire;
    int raw, count;
    string shortstr, longstr;
    fire = TO;
    count = TP->query_property("cooking food");
    if(!objectp(TO)) return 1;
    if(!objectp(TP)) return 1;
    if(!str){
       tell_object(TP,"What are you trying to cook?");
       return 1;
    }
    if(meat = present(str,TP)){
       shortstr = meat->query_short();
       longstr = meat->query_long();
       if(!meat->query_raw()){
          tell_object(TP,"You can only cook raw food!");
          return 1;
       }
       if((int)meat->query_property("cooked") == 1){
          tell_object(TP,"You can only cook raw food!");
          return 1;
       }
       if(!lit){
          tell_object(TP,"The fire is not lit.");
          return 1;
       }
       if((int)fire->query_fuel() < 200) {
          tell_object(TP,"That fire is too low to cook food.  "+
             "You will need to add more fuel first.");
          return 1;
       }
       if((int)fire->query_fuel() > 4000) {
          tell_object(TP,"That fire is out of control!  You can't get "+
             "close enough to cook on that!");
          return 1;
       }
       raw = meat->query_raw();
       if((int)TP->query_property("cooking food") < 1){
          tell_object(TP,"%^RED%^You place the "+meat->query_short()+" "+
             "%^RESET%^%^RED%^over the fire and begin cooking it.%^RESET%^");
          tell_room(ETP,"%^RED%^"+TPQCN+" %^RESET%^%^RED%^places the "+
             ""+meat->query_short()+" %^RESET%^%^RED%^over the fire and "+
             "begins cooking it.%^RESET%^",TP);
          TP->set_property("cooking food",1);
       }
       if(count > raw){
          tell_object(TP,"%^BOLD%^%^RED%^The "+meat->query_short()+" %^BOLD%^"+
             "%^RED%^finishes cooking, and you pull it out of the fire.");
          tell_room(ETP,"%^BOLD%^%^RED%^The "+meat->query_short()+" %^BOLD%^"+
             "%^RED%^finishes cooking, and "+TPQCN+" %^BOLD%^%^RED%^pulls it "+
             "out of the fire.",TP);
          shortstr += " %^RESET%^(%^BOLD%^%^RED%^cooked%^RESET%^)";
          meat->set_short(shortstr);
          longstr += " %^BOLD%^%^RED%^It has been cooked and is ready "+
             "to eat.%^RESET%^";
          meat->set_long(longstr);
          meat->set_my_mess("You eat the cooked "+meat->query_short()+".");
          meat->set_your_mess("eats a cooked "+meat->query_short()+".");
          meat->set_property("cooked",1);
          TP->remove_property("cooking food");
          return 1;
       }
       switch(random(7)){
         case 0:  tell_room(ETO,"%^RED%^Flames leap up from the fire, "+
                     "encasing the cooking "+str+" for a moment.");
                  break;
         case 1:  tell_room(ETO,"%^RED%^The fire sputters as a bit of "+
                     "the cooking "+str+" falls into the fire.");
                  break;
         case 2:  tell_room(ETO,"%^YELLOW%^The "+str+" begins to darken "+
                     "as it cooks.");
                  break;
         case 3:  tell_room(ETO,"%^BOLD%^%^BLACK%^Smoke billows out above "+
                     "the fire as the "+str+" cooks.");
                  break;
         case 4:  tell_room(ETO,"%^ORANGE%^The flames dance around, "+
                     "making the "+str+" sizzle.");
                  break;
         case 5:  tell_room(ETO,"%^BOLD%^%^RED%^The cooking "+str+" causes "+
                     "the fire to shift erratically.");
                  break;
         case 6:  tell_room(ETO,"%^CYAN%^A breeze rises in the air, dampening "+
                     "the flames around the cooking "+str+".");
                  break;
       }
       TP->set_property("cooking food",1);
       call_out("cook_em",(raw*5),str);
       return 1;
   }
   tell_object(TP,"You seem to have lost the "+str+" you were trying to cook.");
   TP->remove_property("cooking food");
   return 1;
}

int is_scrying_mirror()
{
	if(lit)
	{
		return 1;
	}
	return 0;
}
