//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/// Originally coded by Tristan and Styx for the shadow city       ///
/// city guards.  Made into inheritable form by Ares 08/29/05      ///
/// The file inherit's NPC, and has several basic actions handling ///
/// guard behavior.  Things such as fighting in the presence of    ///
/// the guards and stealing will need to be handled in the guard   ///
/// file itself, in order to make the inheritable as open ended    ///
/// and broadly available as possible.  Below is a list of         ///
/// all necessary functions and variables to use guardsman.c       ///
/// Any shopkeeper with set_property("official",<area guarded>)    ///
/// will be protected by the guards the same as jailers.           ///
/// IMPORTANT: All guards will only respond to invisible           ///
/// creatures if they have set_detecting_invis(1).  It is only     ///
/// necessary for 1 guard in the room to have this set however.    ///
//////////////////////////////////////////////////////////////////////
/*////////////////////////////////////////////////////////////////////

  inherit GUARDSMAN;

  void create()
  {
    ::create();

    ARREST_MSG       = Message the guard says when it wants to arrest someone
    CAPTURE_MSG      = Message used when the guard has captured someone
    RACE_CAPTURE_MSG = Message given for race when race_action() is set to "capture"
    EXPEL_MSG        = Message given for race when race_action() is set to "expel"
    KILL_MSG         = Message given for race when race_action() is set to "kill"
    JAIL_MSG         = Message given just before the guard takes captive to jail

    **Tells the guard what to do if it catches a bad race
    set_race_action("kill" || "capture" || "expel");

    **Sets all 'bad races' for the area
    set_bad_races({ "race1","race2",..."raceN"});

    **Sets the message the guard says when it first encounters a bad race
    **Should have a message set for each race set with set_bad_races

    set_race_messages( (["race1" : "message1", "raceN" : "messageN" ]) );

    **Assigns the area that the guard is 'guarding' ie: Shadow, or Tabor
    void set_guarding("Area");

    **This function is ONLY necessary if the guard is a temple guard.
    **If followers of "deity" are being attacked the guards are present
    **they will protect them.

    void set_temple_guard("deity");

    **This is the file name of the location of the jail.  The jail must
    **have waystations set via destinations_d.c or this will not work.
    void set_jail_location("location");

    **If you use set_race_action("expel") this will need to be set.  This
    **is where the guards will drag a bad race to and leave them if they
    **are going to expel them
    void set_expel_location("location");

    **This is an optional setting, if you want for the bad races that get
    **captured by your guards to be taken to a different jail, or to some
    **other room, such as a public torture place, or to be sacrificed to
    **some beast

    void set_capture_location("location");

    **You should stick any special actions you want the guard to perform
    **in combat in this function.  They will happen as soon as battle begins.
    **This is useful if you want them to rush their attackers right away
    **of blow a horn, similar to the shadow watch.
    **IMPORTANT: This function is made to be overridden, and not called
    void do_special_combat_actions();

    **This function can be overridden with a call to ::put_in_jail() if
    **you want for your guards to do anything special before putting
    **someone in their cell.  Such as beating, maiming, etc.
    void put_in_jail();

    **This function MUST be overridden if you want your guards to do
    **anything special to bad races they capture.  This MUST be set also
    **if the capture_location, and jail_location are different.
    **Note:  //DO NOT// call ::capture()

    void capture();

    **This function MUST be overridden if you have set the race_action("expel")
    **and the expel_location.  It will do any special action you specify
    **when the guard reaches the expel location, Such as drop off the victim
    **and start walking back to it's post.  Note: //DO NOT// call ::expel()
    void expel();

    **This is a global variable for the captive, once they've been caught
    **so your guards know who to use and abuse
    captive;

    **Useful if you want to use ranks, but /NOT/ necessary, if the HD of
    **the guard are <= the number, it returns "rank"
    string set_ranks( ([ 10 : "rank1", 20 : "rank2", N : "rankN" ]) );
  }
*/

#include <std.h>
#include <daemons.h>

inherit NPC;

#define VALID_GODS ({"jarmila","callamir","kreysneothosies","seija","lord shadow","the faceless one","kismet","lysara","nimnavanon","nilith","khyron","cevahir"})

mapping race_messages=([]);
string *bad_races=({}),race_action,area_guarded,temple_guarded,jail_location,expel_location,capture_location;
int is_stuck=0; // just in case the guard doesn't have a place to go
object captive; // tracks the dragged player so they can be put in jail
object *bad_people = ({}); // using this to track who the guard has been in a fight with

// These messages should be set in the guard itself
string ARREST_MSG,CAPTURE_MSG,RACE_CAPTURE_MSG,EXPEL_MSG,KILL_MSG,JAIL_MSG;
// All these are necessary to be set for a working guard.
void set_bad_races(string *races);

void set_race_action(string action);
void set_race_messages(mapping messages);
void set_guarding(string where);
void set_temple_guard(string deity);
void set_jail_location(string location);
void set_expel_location(string location);
void set_capture_location(string location);
void do_special_combat_actions();
string set_ranks(mapping ranks);

// internal functions below, handle the actions of the guards.
int is_guardsman();
string query_race_action();
int query_bad_race(object live);
string query_race_message(object targ);
string query_guarding();
int is_guard(string area);
void add_to_wanted(object live);
int is_jailer(object live);
int is_local_guard(object guard);
int wanted(object live);
int is_bad_race(object live);

void remove_fines_and_bounties(object live);
void do_battle(object live);
void set_bad_people(object guard, object live);
object *get_bad_people();
// main interactions check for things like true_invis, wanted, and bad races
void interactions(object live);
void race_action(object live);
void do_laws(object live);
void capture_target(object live,string action);
void take_to_jail(string action);
void put_in_jail();
void capture();
void expel();

void create()
{
    ::create();
    set_property("knock unconscious",1);
}

string set_ranks(mapping ranks) // Probably don't need this, but I guess we have it now
{
    int i,j,rank=0,lvl,*hd=({});

    if(!query_hd())  return error("GUARDSMAN set_hd() must be set before set_ranks().\n");

    lvl = query_hd();

    if(sizeof(keys(ranks)))
    {
        hd = sort_array(keys(ranks),"numerical_sort",FILTERS_D);

        for(j=1,i=0;i<sizeof(hd),j<sizeof(hd);i++,j++)
        {
            if(lvl < hd[j])                     { rank = hd[i]; break; }
            if(lvl == hd[j])                    { rank = hd[j]; break; }
            if(lvl >= hd[j] && j==sizeof(hd)-1) { rank = hd[j]; break; }
        }
    }
    return ranks[rank];
}

void set_bad_races(string *races) { bad_races = races; return; }

void set_race_action(string action) { race_action = lower_case(action); return; }

void set_race_messages(mapping messages) { race_messages = messages; return; }

void set_guarding(string where) { area_guarded = where; return; }

void set_temple_guard(string deity)
{
    deity = lower_case(deity);
    if(member_array(deity,VALID_GODS) != -1)
    {
        temple_guarded = deity;
    }
    return;
}

void set_jail_location(string location)
{
    jail_location = replace_string(location,".c","");
    return;
}

void set_expel_location(string location)
{
    expel_location = replace_string(location,".c","");
    return;
}

void set_capture_location(string location)
{
    capture_location = replace_string(location,".c","");
    return;
}
string query_jail_location()
{
    return jail_location;
}

string query_capture_location()
{
    return capture_location;
}

int is_guardsman()
{
    return 1;
}

string query_race_action()
{
    if (race_action) {
        return race_action;
    }
}

int query_bad_race(object live)
{
    if(!objectp(live)) { return 0; }
    if(!bad_races)     { return 0; }
    if(member_array((string)live->query_visual_race(),bad_races) != -1) { return 1; }
    return 0;
}

string query_race_message(object targ)
{
    string *races=({});
    if(!objectp(targ)) { return 0; }

    races = keys(race_messages);
    if(member_array((string)targ->query_visual_race(),races) != -1)
    {
        return race_messages[(string)targ->query_visual_race()];
    }
    return 0;
}

string query_guarding() { return area_guarded; }

int is_guard(string area)
{
    if (query_guarding() == area) {
        return 1;
    }else {
        return 0;
    }
}

void add_to_wanted(object live)
{
    if (!objectp(live)) {
        return;
    }
    if (!live->is_player()) {
        return;
    }

    if (!AREALISTS_D->is_wanted(live, query_guarding(), TO)) {
        AREALISTS_D->add_wanted(live, query_guarding(), TO);
    }
    return;
}

int is_jailer(object live)
{
    if (!objectp(live)) {
        return 0;
    }
    if (live->query_true_invis()) {
        return 0;
    }
    if (live->query_invis() && !detecting_invis()) {
        return 0;
    }
    if (temple_guarded && (string)live->query_diety() == temple_guarded) {
        return 1;
    }
    if ((string)live->query_property("official") == query_guarding()) {
        return 1;
    }
    if (AREALISTS_D->is_jailer(live, query_guarding(), TO)) {
        return 1;
    }else {
        return 0;
    }
}

int is_local_guard(object guard)
{
    if (!objectp(guard)) {
        return 0;
    }
    if (guard->query_true_invis()) {
        return 0;
    }
    if (guard->is_guard(query_guarding())) {
        return 1;
    }else {
        return 0;
    }
}

int wanted(object live)
{
    if (!objectp(live)) {
        return 0;
    }
    if (live->query_true_invis()) {
        return 0;
    }
    if (live->query_invis() && !detecting_invis()) {
        return 0;
    }
    if (live->query_unconscious()) {
        return 0;
    }
    if (!live->is_player()) {
        return 0;
    }
    if (AREALISTS_D->is_wanted(live, query_guarding(), TO)) {
        return 1;
    }
// added banned lists so need banned to be counted with wanted people here *Styx* 10/05
    if (AREALISTS_D->is_banned(live, query_guarding(), TO)) {
        return 1;
    }
    return 0;
}

int is_bad_race(object live)
{
    if (!objectp(live)) {
        return 0;
    }
    if (live->query_true_invis()) {
        return 0;
    }
    if (live->query_invis() && !detecting_invis()) {
        return 0;
    }
    if (live->query_unconscious()) {
        return 0;
    }
    if (live->id("wild_world_monster")) {
        return 1;
    }
    if (query_bad_race(live)) {
        return 1;
    }else {
        return 0;
    }
}

void remove_fines_and_bounties(object live)
{
    if (!objectp(live)) {
        return 0;
    }
    if (!live->is_player()) {
        return 0;
    }

    if (AREALISTS_D->is_wanted(live, query_guarding(), TO)) {
        AREALISTS_D->remove_wanted(live, query_guarding(), TO);
    }
    if (AREALISTS_D->query_bounty_amount(live, query_guarding(), TO)) {
        AREALISTS_D->remove_bounty(live, query_guarding(), TO);
    }
    if (AREALISTS_D->query_fine_amount(live, query_guarding(), TO)) {
        AREALISTS_D->remove_fine(live, query_guarding(), TO);
    }
    return;
}

// This function is somewhat complicated, in an attempt to get quick reaction
// from the guards when new threats enter the area.  It checks each time
// do_battle is called, for all people from the wanted list, bad races, and
// current attackers that are currenly in the room.  It then checks for all
// the local guards that are in the room, and sticks them all into battle.
// This will prevent 50 guards from all yelling the same message before they
// attack, and also get them fighting at the same time.  The guards will also
// protect anyone who is a jailer of their areas.  This would make for a very
// interesting player vs player battle if you attack someone inside their
// fortress

void do_battle(object live)
{
    object* living = ({}), * guards = ({}), * targets = ({}), * races = ({}), * attackers = ({}), * jailers = ({}), * sparring = ({});
    int i, j, n;
    if (!objectp(live)) {
        return 0;
    }
    if (!objectp(TO)) {
        return 0;
    }
    if (present("trainer", ETO)) {
        return 0;
    }                                        // to prevent "training accidents"
    living = all_living(ETO);

    guards = filter_array(living, "is_local_guard", TO);
    targets = filter_array(living, "wanted", TO);
    races = filter_array(living, "is_bad_race", TO);
    jailers = filter_array(living, "is_jailer", TO);
    attackers = query_attackers();

    if (member_array(live, attackers) == -1) {
        if (!is_jailer(live)) {
            targets += ({ live });
        }
    }
    if (sizeof(races)) {
        targets += races;
    }
    if (sizeof(attackers)) {
        targets += attackers;
    }
    guards = distinct_array(guards);
    targets = distinct_array(targets);

    for (i = 0; i < sizeof(guards); i++) {
        for (n = 0; n < sizeof(jailers); n++) { // protect jailers if they get attacked
            if (member_array(guards[i], jailers[n]->query_protectors()) == -1) {
                if (member_array(guards[i], jailers[n]->query_attackers()) != -1) {
                    continue;
                }
                tell_object(guards[i], "You boldly stand in protection "
                            "of " + jailers[n]->QCN + ".");
                tell_object(jailers[n], "" + guards[i]->QCN + " stands boldly "
                            "in protection of you.");
                tell_room(environment(guards[i]), "" + guards[i]->QCN + " stands"
                          "boldly in protection of " + jailers[n]->QCN + "!", ({ guards[i], jailers[n] }));
                jailers[n]->add_protector(guards[i]);
            }
        }

        for (j = 0; j < sizeof(targets); j++) {
            if (guards[i] == targets[j]) {
                continue;
            }
            if (is_local_guard(targets[j])) {
                continue;
            }
            if (is_jailer(targets[j])) {
                continue;
            }
            add_to_wanted(targets[j]);
            if (targets[j]->query_unconscious() || targets[j]->query_bound()) {
                continue;
            }                                                                              // hopefully to prevent overkill
            if (member_array(targets[j], guards[i]->query_attackers()) == -1 && !guards[i]->query_unconscious()) {
                tell_object(guards[i], "You attack " + targets[j]->QCN + "!");
                tell_object(targets[j], "" + guards[i]->QCN + " attacks you!");
                tell_room(environment(guards[i]), "" + guards[i]->QCN + " attacks "
                          "" + targets[j]->QCN + "!", ({ guards[i], targets[j] }));
                guards[i]->set_bad_people(guards[i], targets[j]);
                guards[i]->kill_ob(targets[j], 0);
                do_special_combat_actions();
            }
        }
    }
    living = ({}); guards = ({}); targets = ({}); races = ({}); attackers = ({}); jailers = ({}); sparring = ({});
    return;
}

int set_bad_people(object guard, object live)
{
    if (!objectp(guard)) {
        return 0;
    }
    if (!objectp(live)) {
        return 0;
    }
    if (member_array(live, bad_people) != -1) {
        return 0;
    }
    live->set_property(query_guarding(), 1);
    bad_people += ({ live });
    return 1;
}

object* get_bad_people()
{
    return bad_people;
}

void do_special_combat_actions()
{
}

//int clean_up() { return 1; }  // not sure if we want this here or not?

void heart_beat()
{
    int i;
    object* living;
    ::heart_beat();

    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (objectp(captive) && file_name(ETO) == jail_location) {
        put_in_jail();
        return;
    }
// found it needs a check so they don't try to attack unconscious *Styx* 12/26/05
    if (TO->query_unconscious()) {
        return;
    }
    if (!sizeof(query_attackers())) {
        if (random(2)) {
            return;
        }
    }

    living = all_living(ETO);
    living -= ({ TO });
    if (!sizeof(living)) {
        return;
    }
    for (i = 0; i < sizeof(living); i++) {
        if (!objectp(living[i])) {
            continue;
        }
        interactions(living[i]);
    }
    return;
}

void interactions(object live)
{
    if (!objectp(live)) {
        return;
    }
    // important, this checks from monster.c to see if the guard is walking to it's destination
    if (is_walking || is_stuck) {
        return;
    }
    if (live->query_true_invis()) {
        return;
    }
    if (live->query_invis() && !detecting_invis()) {
        return;
    }
    if (is_guard((string)live->query_guarding())) {
        return;
    }
    if (sizeof(live->query_attackers())) {
        do_battle(live); return;
    }
    if (query_bad_race(live)) {
        race_action(live); return;
    }
// and adding for banned here too *Styx* 10/09/05
    if (AREALISTS_D->is_wanted(live, query_guarding(), TO)) {
        do_laws(live); return;
    }
    if (AREALISTS_D->is_banned(live, query_guarding(), TO)) {
        do_laws(live); return;
    }
}

void race_action(object live)
{
    if(!objectp(live)) { return; }

    if(sizeof(query_attackers()))
    {
        if(!live->query_unconscious()) { do_battle(live); }
        return;
    }

    if(live->query_unconscious())
    {
        switch(query_race_action())
        {
        case "kill":
            command("say "+KILL_MSG);
            command("hit "+live->query_name());
            return;
        case "capture":
            capture_target(live,"capture");
            return;
        case "expel":
            capture_target(live,"expel");
            return;
        }
    }

    if(live->query_bound())
    {
        switch(query_race_action())
        {
        case "capture":
            command("say "+RACE_CAPTURE_MSG);
            capture_target(live,"capture");
            return;
        case "expel":
            command("say "+EXPEL_MSG);
            capture_target(live,"expel");
            return;
        }
    }

    if (member_array(live, query_attackers()) == -1 && !live->query_bound())
    {
        if(query_race_message(live))
        {
            command("yell "+query_race_message(live));
        }
        do_battle(live);
    }
    return;
}

void do_laws(object live)
{
    if (!objectp(live)) {
        return;
    }
    if (sizeof(query_attackers())) {
        if (!live->query_unconscious()) {
            do_battle(live);
        }
        return;
    }
    if (live->query_unconscious()) {
        capture_target(live, "jail");
        command("say " + CAPTURE_MSG);
        return;
    }
    if (live->query_bound()) {
        command("say " + JAIL_MSG);
        capture_target(live, "jail");
        return;
    }
    if (member_array(live, query_attackers()) == -1 && !live->query_bound()) {
        command("yell " + ARREST_MSG);
        do_battle(live);
    }
    return;
}

void capture_target(object live, string action)
{
    int need;
    if (!objectp(live)) {
        return;
    }
    if (!live->query_unconscious() && !live->query_bound()) {
        do_battle(live); return;
    }
    if (!live->query_bound()) {
        tell_room(ETO, "" + TPQCN + " takes some rope and binds "
                  + live->query_cap_name() + "'s hands and feet.", ({ TP, live }));
        live->set_bound(500);
        return;
    }

    if (live->query_unconscious()) {
        tell_room(ETO, TO->QCN + " binds " + live->QCN + "'s wounds.");
        need = live->query_hp();
        live->add_hp(-need + random(20) + 10);
        tell_object(live, "You wake up and find " + TO->QCN + " quickly "
                    "binding your wounds.");
        return;
    }
    if (live->query_bound()) {
        captive = live;
        take_to_jail(action);
        return;
    }
    return;
}

void take_to_jail(string action)
{
    if (query_paralyzed()) {
        return;
    }
    switch (action) {
    case "jail":

        if (!jail_location) {
            is_stuck = 1;
            command("say I don't have a jail to go to, I'll hang on to you for now.");
            return;
        }
        TO->move(jail_location);
        captive->move(ETO);
        return;
    case "expel":
        if (!expel_location) {
            is_stuck = 1;
            command("say I don't know where to expel you to, I'll hang on to you for now.");
            return;
        }
        TO->move(expel_location);
        captive->move(ETO);
        return;
    case "capture":
        if (!capture_location) {
            capture_location = jail_location;
        }
        if (!capture_location) {
            is_stuck = 1;
            command("say I don't have a location to go to, I'll hang on to you for now.");
            return;
        }
        TO->move(jail_location);
        captive->move(ETO);
        return;
    }
    return;
}

int put_in_jail()
{
    if (!objectp(captive)) {
        return 0;
    }
    TO->set_draggee(0);
    ETO->__ToCell(captive, TO, "unknown");
    captive = 0;
    return 1;
}

void capture()
{
    put_in_jail();
}

void expel()
{
    put_in_jail();
}
