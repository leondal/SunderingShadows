//Had to add a check for lrweapon with the weight check for the
//put_into and sheath_into.  The lrweapon code increases the query_size
//to lrweapons to force them to two handed for larger races, which made
//the size 3 bow not fit in a size 3 sheath when a large PC was holding it.
//Garrett identified the source of the problem, fix by Styx  8/3/01

#include <std.h>
#include <move.h>
inherit PARMOUR;

#define CM TO->query_property("call_myself")

// STUFF I OVERLOADED FOR THIS BEAST!

int query_internal_encumbrance() {

int iter;
int weight;
object * inv;
  weight = 0;
  if (!sizeof(all_inventory(TO))) return 0;

for (iter=0,inv=all_inventory(TO);iter<sizeof(inv);iter++)
  weight += inv[iter]->query_weight();

return weight;
}

int query_value() {
  int holder;
  if (!(holder=::query_value())) {
    return ( 5  * (int)query_property("sheath_size")  * (int)query_property("sheath_size"));
  } else {
    return holder;
  }
}
int query_weight() {
  if (sizeof(all_inventory(TO)))
    return TO->query_property("original_weight") + TO->query_internal_encumbrance();
  else
    return TO->query_property("original_weight");
}

string query_long(string i_do_not_know_why) {
  string str, type;
  string *possible_places=({});
  int iter,maxiter;
  function QPROP=(:TO, "query_property":);

  str = ::query_long(i_do_not_know_why);
  if(!str) { str = ""; }

  if(query_property("soulbound")) str += "\n%^RESET%^%^CYAN%^This item gives off a faintly glowing aura of binding.%^RESET%^";
  maxiter=sizeof(possible_places=TO->query_property("can_wear_limbs"));
  if ( maxiter > 1) {
    str += "\nThis "+CM+" can be worn in the following places: ";
    for (iter=1;iter<maxiter ;iter++)
      if (maxiter > 2)
	str += possible_places[iter-1]+", ";
      else
	str += possible_places[iter-1]+" ";
    str += "and "+possible_places[maxiter-1]+".\n";
    // str += "You can %^BLUE%^adjust "+((string *)TO->query_id())[0]+" into";
    // str += " <place> %^RESET%^to change it's position.\n";
  } else
    str += "This "+CM+" can be worn only on "+possible_places[0]+".\n";
  maxiter=sizeof(possible_places=TO->query_property("can_hold"));
  if ( maxiter > 1) {
    str += "This "+CM+" can likely hold the following basic types: ";
    for (iter=1;iter<maxiter ;iter++)
      if (maxiter > 2)
	str += possible_places[iter-1]+", ";
      else
	str += possible_places[iter-1]+" ";
    str += "and "+possible_places[maxiter-1]+".\n";
    str += "";
  } else
    str += "This "+CM+" can only contain "+possible_places[0]+".\n";
  if (TP==TP)
    str += "%^BOLD%^(Try typing <help "+CM+"> as well.)\n";
  return str;
}

int query_size(){
  if(!objectp(TP) || !living(TP)) return 2;
  return TP->query_size();
}

// END OVERLOADS

void create(){
  ::create();
  if (!stringp(TO->query_property("call_myself")))
    set_property("call_myself","sheath");
  if (!pointerp(TO->query_property("can_hold")))
    set_property("can_hold",({ "small blades", "medium blades" }));
  if (!pointerp(TO->query_property("can_wear_limbs")))
    set_property("can_wear_limbs",({ "waist" , "torso"}));
  if (!intp(TO->query_property("sheath_size")))
    set_property("sheath_size",2);
  if (!intp(TO->query_property("original_weight")))
    set_property("original_weight",2);
    set_property("repairtype",({ "jewel","armorsmith" }));
  set_name("sheath");
  set_id(({"sheath","sheaths","Sheaths","Sheath"}));
  set_short("A "+CM);
  set_long(
@GARRETT
This is a weapons sheath. It is meant to hold a single weapon,
and has adjustable straps to hold it on your body. The straps could be
easily adjusted to hold the sheath in more than one location, allowing
easy access for the weapon that it holds.
GARRETT
);

  // This should be sheath or something else... But for now I call it a ring.

  set_type("sheath");

  // This is so it's adjusted for the first place it can be attached.
  // I made it easy enough to change, so this shouldn't be an issue.

  set_limbs(({ ((string *)query_property("can_wear_limbs"))[0] }));

  // Value dependent on size.

  set_cointype("gold");
  // Doing that elsewhere, in the overloads.

  set_max_internal_encumbrance(20);
}

void init() {
  ::init();
  if (TP!=TP)
    return;
  add_action("change_limb","adjust");
  add_action("draw_from","draw");
  add_action("sheath_into", "sheath");
  add_action("help","help");
}

int is_mixable() {return 1;}

int check_shifted(object tp)
{
    if(!objectp(tp)) { return 1; }
    if(tp->query_property("shapeshifted"))
    {
        tell_object(tp,"You can't use sheaths while shapeshifted.");
        return 0;
    }
    return 1;
}



int will_work(object ths, object tht) {
  string trash;
  string *allowed;

  allowed = tht->query_property("can_hold");

  if(!sizeof(allowed))
  {
      return notify_fail("Error, no valid types fit in this object. Contact a wiz.");
  }

  // Allow for explicit cases first...

  if (member_array(ths->query_prof_type(),allowed) != -1)
    return 1;

  // Then screen out obvious rejects...

  if (member_array(ths->query_basic_prof_type(),allowed) == -1)
    return 0;

  // Then take a good guess at axes. :P Note other code should stop greataxes
  // from going into size-1 holsters. :P

  if (sscanf(ths->query_prof_type(),"%s axe",trash) == 1) {
    if ((member_array("bludgeoning", allowed) != -1) ||
	(member_array("bludgeoning", allowed) != -1) )
      return 1;
    else
      return 0;
  }  else if ((string)ths->query_prof_type() == "polearm")
      return 0;
  else if (((string)ths->query_prof_type() == "whip") ||
	   (string)ths->query_prof_type() == "drider whip")
    return 0;

  return 1;
}


int change_limb(string str) {
  string alpha, beta;
  object ob;
    if(TP->query_bound() || TP->query_unconscious()
    || TP->query_paralyzed()){
	    TP->send_paralyzed_message("info",TP);
	    return 1;
    }

    if(!check_shifted(TP)) { return 1; }

  if ( (!stringp(str)) || (sscanf(str,"%s onto %s", alpha, beta) != 2))
    return notify_fail("Adjust <what> onto <where>?\n");
  else {
    // if (!TO->id(alpha)) return 0;
    // if(id(alpha)) ob = this_object();
    // else
  ob =present(alpha,TP);
    if(ob != this_object()) return 0;

    if (member_array(beta,TP->query_limbs()) == -1)
      return notify_fail("You don't have that limb! You can't adjust it for that!\n");
    if (member_array(beta,TO->query_property("can_wear_limbs")) == -1)
      return notify_fail("This sheath cannot be worn there.\n");
    if (TO->query_worn())
      return notify_fail("You would have to take it off first!\n");
    set_limbs(({beta}));
    return 1+write("You adjust it so you can wear the sheath on your "+beta+".");
  }

}

int put_into(string str)
{
    int res, i, silly;
    object ths,tht,*inv;
    string this, that;
    if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed())
    {
	    TP->send_paralyzed_message("info",TP);
	    return 1;
    }

   if (ETO == ETP) return 0;
/*
    if(total_light(this_player())+(int)this_player()->query_sight_bonus()<-1){
        notify_fail("It is too dark.\n");
        return 0;
    }
*/
/* agreed with the theory that the point is you'd know where they are or could feel for them, also more player friendly.... *Styx* 2/13/06
    if (silly=TP->light_blind(-1)) {
        notify_fail(TP->light_blind_fail_message(silly)+"\n");
        return 0;
    }
*/
    if (stringp(str) && sscanf(str,"%s in %s",this,that) == 2)
    {
        if (present(this,this_player()))
        {
            if (present(that,this_player()) || present(that,environment(this_player())))
            {
	            ths = present(this,this_player());
	            tht = present(that, this_player());
	            if(ths == tht) /* Plura 930208 */{
                    notify_fail("Get real!\n");
                    return 0;
                }
//                if(!tht) tht = present(that, environment(this_player()));
                if(ths->drop() && !ths->query_property("soulbound")) {
                    notify_fail("You cannot drop that!\n");
                    return 0;
                }
                if(tht != TO) return 0;
                if(!ths->is_weapon() && !TO->is_instrument_case()){
                    notify_fail("This is meant for weapons only.\n");
                    return 0;
                }
                if(sizeof(all_inventory(TO)) > 0) {
                    notify_fail("This "+CM+" is already holding something.\n");
                    return 0;
                }
                if(!will_work(ths,tht)) {
                    notify_fail("That kind of weapon is not meant for this "+CM+".\n");
                    return 0;
                }

                if((ths->query_is_lrweapon() != 0) &&
                (ths->query_size() > query_property("sheath_size"))) {
                    notify_fail("This weapon is too large for this "+CM+"!\n");
                    return 0;
                }

                if(!check_shifted(TP)) { return 1; }

                if (tht->receive_objects()) {
                    res = (int)ths->move(tht);
                    if (res == MOVE_OK) {
	                    write("You put "+ths->query_short()+" in "+tht->query_short()+".\n");
	                    say(this_player()->query_cap_name()+" puts "+ths->query_short()+ " in "+tht->query_short()+".\n");
	                    TP->add_encumbrance(ths->query_weight());
	                    return 1;
                    }
                    if (res == MOVE_NO_ROOM)
	                    notify_fail("For some reason it does not fit...\n");
                    if (res == MOVE_NOT_ALLOWED)
	                    notify_fail("You are not allowed to do that...\n");
                    return 0;
                }
                notify_fail("It is closed.\n");
                return 0;
            }
            notify_fail(capitalize(that)+" is not here.\n");
            return 0;
      }
    notify_fail("You are not carrying "+this+".\n");
        return 0;
}
return 0;
}


int get_from(string str) {
    int res, i, silly, weight;
    object ob, tmp, *inv;
    string what, where;
    if(!stringp(str)) return 0;
    if(this_player()->query_ghost()) return 0;

    if(TP->query_bound() || TP->query_unconscious()
    || TP->query_paralyzed()){
	    TP->send_paralyzed_message("info",TP);
	    return 1;
    }

/*
    if(total_light(this_player())+(int)this_player()->query_sight_bonus()<-1) {
	notify_fail("It is too dark.\n");
	return 0;
    }
*/
/* you could easily enough feel for the hilt of the weapon to draw it *Styx* 2/13/06
    if (silly=TP->light_blind(-1)) {
        notify_fail(TP->light_blind_fail_message(silly)+"\n");
        return 0;
    }
*/
    if(sscanf(str, "%s from %s", what, where) != 2) return 0;
    if(id(where)) tmp = this_object();
    else tmp = parse_objects(environment(this_object()), where);
    if(tmp != this_object()) return 0;

    if(!check_shifted(TP)) { return 1; }

    if(this_object()->receive_objects())
    {
	if(what != "all")
    {
	    ob = present(what, this_object());
	    if(!ob) ob = parse_objects(this_object(), what);
	    if(!ob) {
		write("There is no "+what+" in "+this_object()->query_short()+".");
		return 1;
	    }
	    // Fudge it so the user doesn't get penalized for drawing a sword while
	    // at max encumberance.
	    //
	    // g
	    weight = ob->query_weight();
	    ob->set_weight(0);
	    res = (int)ob->move(this_player());
	    ob->set_weight(weight);
	    if(res == MOVE_OK) {
	      if (weight > 0)
		 weight *= -1;
	      TO->add_encumbrance(weight);
	      write("You get "+ob->query_short()+" from "+this_object()->query_short()+".");
	      tell_room(ETP,this_player()->query_cap_name()+" gets "+ob->query_short()+" from "+this_object()->query_short()+".", this_player());
	      return 1;
	    }
	    if(res == MOVE_NOT_ALLOWED) write("You can't do that!");
	    if(res == MOVE_NO_ROOM) write("You can't carry that!");
	    return 1;
	  }
	  inv = all_inventory(this_object());
	  if(!sizeof(inv)) {
	    write("There is nothing in "+this_object()->query_short()+".");
	    return 1;
	  }
	  // Backwards compatibility, for people who REALLY like to do 'get all'
	  for(i=0; i<sizeof(inv); i++) {
	    weight = inv[i]->query_weight();
	    inv[i]->set_weight(0);
	    res = (int)inv[i]->move(this_player());
	    inv[i]->set_weight(weight);
	    if(res == MOVE_OK) {
	      if (weight > 0)
		 weight *= -1;
	      TO->add_encumbrance(weight);
	      write("You get "+inv[i]->query_short()+" from "+this_object()->query_short()+".");
	      tell_room(ETP,this_player()->query_cap_name()+" gets "+inv[i]->query_short()+" from "+this_object()->query_short()+".", this_player());

	    }
	    if(res == MOVE_NO_ROOM) write(inv[i]->query_short()+": Too heavy.\n");
	  }
	  return 1;
	}
	write(query_short()+" is closed.");
	return 1;
      }

int draw_from(string str) {
	int silly;
	int res, i, weight;
	object ob, tmp, *inv;
	string what, where;
	if(!stringp(str)) return 0;
	if(this_player()->query_ghost()) return 0;
	if(TP->query_bound() || TP->query_unconscious()
    || TP->query_paralyzed()){
	    TP->send_paralyzed_message("info",TP);
	    return 1;
    }

    if(!check_shifted(TP)) { return 1; }

//        if(silly=TP->light_blind(-1)) {
//          notify_fail(TP->light_blind_fail_message(silly)+"\n");
//	  return 0;
//	}
	if(sscanf(str, "%s", what) != 1) return 0;
	if(this_object()->receive_objects()) {
	  ob = present(what, this_object());
	  if(!ob) ob = parse_objects(this_object(), what);
	  if(!ob) {
	    notify_fail("You don't have a "+what+" in any of your "+CM+".\n");
	    return 0;
	  }
	  // Fudge it so the user doesn't get penalized for drawing a sword while
	  // at max encumbrance.
	  //
	  // g
	  weight = ob->query_weight();
	  ob->set_weight(0);
	  res = (int)ob->move(this_player());
	  ob->set_weight(weight);
	  if(res == MOVE_OK) {
	    if (weight > 0)
	      weight *= -1;
	      TO->add_encumberance(weight);
      //      if(TO->add_encumbrance(weight)) write("removed extra weight.");
      //      else write("failed to remove extra baggage");
	    write("You get "+ob->query_short()+" from your "+this_object()->query_short()+".");
	    tell_room(ETP,"%^BOLD%^%^BLUE%^"+this_player()->query_cap_name()+" draws "+ob->query_short()+" from "+this_object()->query_short()+".", this_player());
	    if (ob->size() <= TP->size())
	      TP->force_me("wield "+ ((string *)ob->query_id())[0]);
	    else
	      TP->force_me("wield "+ ((string *)ob->query_id())[0] +" in right hand and left hand");

	    return 1;
	  }
	  if(res == MOVE_NOT_ALLOWED) write("You can't do that!");
	  if(res == MOVE_NO_ROOM) write("You can't carry that!");
	  return 1;
	}
	write(query_short()+" is closed.");
	return 1;
}


int sheath_into(string str){
    int silly;
	int res, i;
	object ths,tht,*inv;
	string this, that;
    if(TP->query_bound() || TP->query_unconscious()
    || TP->query_paralyzed()){
	    TP->send_paralyzed_message("info",TP);
	    return 1;
    }

    if(!check_shifted(TP)) { return 1; }

    if (ETP == ETO) return 0;
/*        if(silly=TP->light_blind(-1)) {
          notify_fail(TP->light_blind_fail_message(silly)+"\n");
	  return 0;
	}*/
	if (stringp(str)) {
      if(sscanf(str,"%s into %s",this,that) == 2) {
        if(!tht = present(that,this_player())) {
          notify_fail("You are not carrying "+that+".\n");
          return 0;
        }
      }
      else if (stringp(str) && sscanf(str,"%s",this) == 1) {
        tht = TO;
      }
	  if (present(this,this_player())) {
	    ths = present(this,this_player());
	    if(ths == tht) /* Plura 930208 */{
		notify_fail("Get real!\n");
		return 0;
	    }
	    if(ths->drop() && !ths->query_property("soulbound")) {
		notify_fail("You cannot put that away!\n");
		return 0;
	    }
	    if(!ths->is_weapon() && !TO->is_instrument_case()){
		notify_fail("This is meant for weapons only.\n");
		return 0;
	    }
	    if(sizeof(all_inventory(TO)) > 0) {
		notify_fail("You can't find somewhere free to put that.\n");
		return 0;
	    }
	    if(!will_work(ths,tht)) {
		    notify_fail("You can't seem to find one that will work for that weapon unused.\n");
		    return 0;
	    }
	    if((ths->query_is_lrweapon() != 0) &&
	      (ths->query_size() > query_property("sheath_size"))) {
		    notify_fail("This weapon is too large for your available "+CM+"!\n");
		    return 0;
	    }
	    if (tht->receive_objects()) {
		    res = (int)ths->move(tht);
		    if (res == MOVE_OK) {
		        write("You sheathe "+ths->query_short()+" into "+tht->query_short()+".\n");
		        say("%^BOLD%^%^BLUE%^"+TPQCN+" sheathes "+ths->query_short()+ " in "+tht->query_short()+".\n");
		        TP->add_encumbrance(ths->query_weight());
		        return 1;
		    }
		    if (res == MOVE_NO_ROOM)
		        notify_fail("For some reason it does not fit in any of your "+CM+".\n");
		    if (res == MOVE_NOT_ALLOWED)
		        notify_fail("You are not allowed to do that.\n");
		    return 0;
	    }
	    notify_fail("It is closed.\n");
	    return 0;
	}
	notify_fail("You are not carrying "+this+".\n");
	return 0;
    }
    return 0;
}

string query_short() {
    string str;
    string inv;
    int i;
    inv = all_inventory(TO);
    str = ::query_short();
    if(!sizeof(inv))
	str = str+" (empty)";
    /*  This worked to add what it was holding.  However, when you "put"
    or "sheath" the weapon, the messages showed it was already holding the
    weapon when it went in.  Styx 6/25/01
	if(sizeof(inv) != 0)
	str = str +" holding "+ (string)inv[i]->query_short();
    */
    return str;
}

int help(string str){
    if ( !TO->id(str) && str != "sheath" )
	return 0;
    write(
@OLI
Commands for weapon sheaths

   adjust <what> onto <position>

This command moves the sheath around to a different position.
You are not doing magic, you are repositioning the thing by
moving buckles and straps.

  put <weapon> in <what>
  get <weapon> from <what>

These work the same as a normal bag, if the weapon fits.

  draw <weapon>

Takes a weapon from a sheath, and makes you wield it.

  sheath <weapon>

Sticks a weapon in the first available sheath it can fit in.

  sheath <weapon> into <sheath>

Sticks a weapon into a specific sheath if it can fit.

OLI
    );
    return 1;
}

int is_sheath() { return 1; }
