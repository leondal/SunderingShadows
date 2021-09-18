//ACTIVELY USED

// In Character Srying and Location Broker Daemon
// Initiates all legal magical location and scrying in character
// to allow checks to be made for anti-scry or anti-location spells
// without adding them to every spell.
// Thorn@ShadowGate
// 2 January 2001
// /daemon/ic_scry_locate_d.c

#include <std.h>
#include <security.h>

// DEBUG mode enabled on 1, 0 is off.  Make sure and set DEBUGGER
// to yourself if you are testing this.
#define DEBUG 0
#define DEBUGGER "thorn"

#define BLOCKER "/d/magic/obj/scry_blocker"
#define DETECTOR "/d/magic/obj/scry_detector"
#define SCRY_CONTROL "/d/magic/obj/scry_control"
#define SCRY_OBJECT "/d/magic/obj/scry_object"

inherit DAEMON;

private void SAVE();
private void LOG(string msg);

// DONE

// Utility fun to allow proper error messages for players.
string error_msg(string str);

// Make the scry control object.
object make_scry_control(object observer, object target);

// Make the living scry observer object.
object make_scry_object(object control, object target);

// Ends scrying and cleans up the objects.  If the stop event was
// not the natural end of the spell (as in a block scry), then set
// early to non-zero to allow that to be passed on to the observer.
int stop_scry(object control, int early);

// Add scry protection to the target.
// Return the scry blocker object.
object add_block_scrying(object target);

// Add scry detection to the target.
// Return the scry detector object.
object add_detect_scrying(object target);

// Master interface to initiate scrying.
string scry_interface(object observer, object target, object item, string *extra);

// Returns all of the scry objects that are tagged to the target
// of a scrying.  Useful for checking if target is being scryed
// and also for the turnabout feature of detect scrying.
object *query_scrys(object target);

// Where an item exists that acts as a scry control, e.g. a
// crystal ball object.
string item_scry(object observer, object target, object item, string *extra);

// Utility fun to allow proper error messages for players.
string error_msg(string str);

// NOT DONE

// Call this to return the location of the target, assuming that
// the target is not blocking locate attempts or in an anti-magic
// shell, etc.  Also call detection measures on the target when
// the attempt is made.
string locate_interface(object observer, object target, string *extra);

void create() {
    ::create();
}

void LOG(string msg) {
//  seteuid(UID_LOG);
//  log_file("scry_locate", ctime(time())+": "+msg+"\n");
//  seteuid(getuid());
}

// Call this to return the location of the target, assuming that
// the target is not blocking locate attempts or in an anti-magic
// shell, etc.  Also call detection measures on the target when
// the attempt is made.
string locate_interface(object observer, object target, string *extra) {
    object ob,locale;
    string file;
    string *tempdir;
    int i;
    object *inv;
    string desc;

    if(target->query_true_invis()) return "Nice try.";

    if(target->is_room()) locale = target;
    else locale = environment(target);

    desc = (string)locale->query_short()+"\n";
    inv = all_inventory(locale);

    for(i=0; i<sizeof(inv); i++) {
        if(inv[i]->query_invis()) continue;
        desc += (string)inv[i]->query_short()+"\n";
    }
    return desc;
}

// Master interface to initiate scrying.
string scry_interface(object observer, object target, object item, string *extra) {
    return item_scry(observer, target, item, extra);
}

// Where an item exists that acts as a scry control, e.g. a
// crystal ball object.
string item_scry(object observer, object target, object item, string *extra) {
    object scry_object, control;

    control = item;
    if(!objectp(control)) return error_msg("No controller!");

    // Only one scry at a time!
    if(observer->query_property("scrying")) return "You are already scrying!";

    // First check if the target is scryable.  No wizzes and avatars
    // also, check for block scrying.  Return a string error for any
    // error.
    if(!objectp(target)) return error_msg("Target is not an object");
//    if(avatarp(target)) return "Nice try.";
    // ADD: Check for scry blocking here...

    // Make the scry control and objects return any errors or messages.
    // Put the scry object under control of the item.
    scry_object = make_scry_object(control, target);
    if(!objectp(scry_object)) return error_msg("No scry object");

    // Add reference information to the target allowing it to know
    // it is being scryed and by who, under certain instances.
    target->set_property("scryed_by",({control}));
    observer->set_property("scrying",1);
    // ADD: Check for detect scrying here...

    // Send the control back to the client spell or object to place
    // it as required.
    return "An image begins to take shape!";
}


// Ends scrying and cleans up the objects.  If the stop event was
// not the natural end of the spell (as in a block scry), then set
// early to non-zero to allow that to be passed on to the observer.
int stop_scry(object control, int early) {
    object scry_object, target, observer, parent;

    if(!objectp(control)) return 0;

    observer = control->query_observer();
    target = control->query_target();
    scry_object = control->query_scry_object();

    if(objectp(target)) target->remove_property_value("scryed_by",({control}));
    if(objectp(scry_object)) scry_object->remove();
	if(parent = control->query_parent()) parent->control_failure();
    if(objectp(observer)) {
        observer->remove_property("scrying");
		observer->remove_property("remote scrying");
        tell_object(observer, "The image you were viewing quickly fades away.");
        tell_room(environment(observer), "The scried image quickly fades away.");
	}
  if (control->is_temporary())
    control->remove();
    return early+1;
}

// Make the scry control object.  Returns the control object.
// Higher levels are responsible for placing the control object.
//object make_scry_control(object observer, object target) {
//    object ob;
//
//    if(!objectp(target) || !objectp(observer)) return 0;
//    ob = new(SCRY_CONTROL);
//    ob->set_observer(observer);
//    ob->set_target(target);
//    return ob;
//}

// Make the living scry observer object.
object make_scry_object(object control, object target) {
    object ob, observer;

    if(!objectp(target) || !objectp(control)) return 0;
    ob = new(SCRY_OBJECT);
    ob->set_control(control);
    ob->set_target(target);
	observer = control->query_observer();
    if(!objectp(observer)) return 0;
    ob->set_observer(observer);
    control->set_scry_object(ob);
    if(target->is_room()) {
        ob->no_move();
        ob->move(target);
    }
    else ob->move(environment(target));
    return ob;
}

// Utility fun to allow proper error messages for players.
string error_msg(string str) {
    string msg;

    msg = "%^RED%^[OOC Error]%^RESET%^ ";
    msg += str;
    msg += ": ";
    msg += "\n%^B_BLUE%^YELLOW%^Contact the staff via the bug command to report this error.  "
        "Please include information about what you were doing at the time "
        "you saw this error. Keep any logs or screen captures.%^RESET%^";
    return msg;
}

// See if scry blocking is active for the target.
// Return the scry blocker object.
object add_block_scrying(object target) {
	object blocker;

	if(!objectp(target)) return 0;
	blocker = new(BLOCKER);
	blocker->set_target(target);
/*
Protection from scrying says that it will move with the
target, but it won't if it's set up this way.  I'm going to
try the below (move(target)) and see if everything still
works correctly.  If not, this can go back and I'll try
something else.  ~Circe~ 9/27/05
	if(target->is_room()) blocker->move(target);
	else blocker->move(environment(target));
*/
      blocker->move(target);
	return blocker;
}

// Add scry protection to the target.
// Return the scry blocker object.
object add_detect_scrying(object target) {
	object detector;

	if(!objectp(target)) return 0;
	detector = new(DETECTOR);
	detector->set_target(target);
	if(target->is_room()) detector->move(target);
	else detector->move(environment(target));
	return detector;
}

// Returns all of the scry objects that are tagged to the target
// of a scrying.  Useful for checking if target is being scryed
// and also for the turnabout feature of detect scrying.
//object *query_scrys(object target) {
//	if(!objectp(target)) return 0;
//	if(!target->query_property("scryed_by")) return 0;
//	return target->query_property("scryed_by");
//}
//
