/* Adapted from Bane's Laerad commandos by Styx for the Shadow jail
 * - Should we set him to no dominate?
 * - Why won't he wield the key?  Made it wearable and that works, but still..
 * - Features > attacks people trying to unlock the door or pick the lock
 * -> Jails bound people & records their name in a list
 * -> Checks to be sure he's at the jail before taking them
 * -> Will call Shadow watch and has "shadow law" id so they won't attack him
 * by Styx - 3/31/02
 * -- Figure out how to make him yell shut up in there if someone yells?
 */

/* *************
 * Notes to those creating new ones or to follow up to handle here
 * Need to have a proper ID of JailLoc_guard set or added from a callout in create
 * Have a set_key also ??
 *   - would have to use a callout to load it so do that with the add_id??
 * !! or, have an is_law(JailLoc) function and a variable setting them for that?
 * Leave the attack special function but let it be overridden?
 */

#include <std.h>
#include <daemons.h>

inherit NPC;

void set_jail_location(string loc); // must match the jail room's location
void set_jail(string filename);     // main jail filename for the area
void set_cell(string filename);     // cell filename
void set_key(string filename);      // cell key filename

string JailLoc, JailFile, CellFile, KeyFile;

int __AskDrop(object targ);
int __CheckLists(object who);
int __JailerCell(object jailwho);
int __GetKey(string str);

void create()
{
    ::create();
    set_id(({ "jailer" }));
    set_name("jailer");
    set_short("temp jailer");
    set_long("The basic inheritable jailer.  If you're seeing this description, there is a problem so please do a bug report.");
    set_race("human");
    set_alignment(2);
    set_class("fighter");
    set_property("no bows", 1);
    set_property("no dominate", 1);
    set_funcs(({ "headlock", "key_swipe", "key_swipe" }));
    set_func_chance(90);
    set_property("swarm", 1);
}

void set_jail_location(string loc)
{
    JailLoc = loc;
    set_property("official", loc);
}

void set_jail(string filename)
{
    JailFile = filename;
}

void set_cell(string filename)
{
    CellFile = filename;
}

void set_key(string filename)
{
    KeyFile = filename;
}

int query_jail_location()
{
    return JailLoc;
}

int query_jail()
{
    return JailFile;
}

int query_cell()
{
    return CellFile;
}

int query_key()
{
    return KeyFile;
}

/************************
 * can I make this use the KeyFile info. and do we need an inheritable jail key?
 *
 * void reset() {
 *   object ob;
 *   ::reset();
 *   if(ob = present("skeleton key"))
 *      if(!ob->query_worn())
 *	force_me("wear key");
 *}
 **************************/

void init()
{
    ::init();
    add_action("no_way", "rush");
    add_action("no_way", "stab");
    add_action("__GetKey", "request");
    if (!objectp(TP)) {
        return;
    }
    if (objectp(ETO) && base_name(ETO) == JailFile) {
// the pick and unlock prevention may be too tricky to get to work for an inherit
        add_action("guard_check", "pick");
        add_action("guard_check", "unlock");
        if (TP->query_bound() || TP->query_unconscious()) {
            call_out("__AskDrop", 3, TP);
        }
    }
    if (base_name(TO) != "/std/jailer") {
        call_out("__CheckLists", 1, TP);
    }
}

int __AskDrop(object targ)
{
    if (!objectp(TO) || !objectp(ETO) || !objectp(targ)) {
        return 0;
    }
    if (base_name(ETO) == JailFile) {
        if (targ->query_property("draggee")) {
            force_me("say Drop your captive if you want me to <jail> them for you.");
            return 1;
        }
    }
    return 1;
}

int __CheckLists(object who)
{
    if (!objectp(who)) {
        return 0;
    }
    if (who->query_invis()) {
        return 0;
    }
    if (AREALISTS_D->is_jailer(who, JailLoc, TO)) {
        force_me("emoteat " + who->query_name() + " snaps to attention and salutes $N");
    }
    if (AREALISTS_D->is_wanted(who, JailLoc, TO)) {
        force_me("say Well now, if it isn't one we've been looking for.");
        force_me("say Always room for another prisoner!");
    }
    if (AREALISTS_D->has_bounty(who, JailLoc, TO)) {
        force_me("say I see there's a bounty on your head.");
        force_me("smirk " + who->query_name());
        force_me("say Anyone here wanting to claim it?");
        force_me("emote looks around expectantly.");
    }
    if (AREALISTS_D->has_fine(who, JailLoc, TO)) {
        force_me("say You here to pay up your fine?");
        force_me("smirk " + who->query_name());
        force_me("emote taps a page in the book on the desk.");
    }
    return 1;
}

int __Jail(object jailwho)
{
    if (!objectp(jailwho) || !objectp(ETO)) {
        return 0;
    }

    tell_room(ETO, "The guard peers through the grating in the door and "
              "pulls a lever.  You hear something click inside the cell before "
              "he unlocks the door.\n\nHe quickly shoves " + jailwho->QCN +
              " inside the cell.", jailwho);
    tell_room(CellFile, TOQCN + " peers through the grating in the door "
              "and pulls a lever.  You hear something click inside the cell as "
              + TO->QS + " quickly shoves " + jailwho->QCN + " inside.", jailwho);
    tell_object(jailwho, "The guard peers through the grating in the door "
                "and pulls a lever.  You hear something click inside the cell "
                "before he unlocks the door and quickly shoves you into the cell.\n");
    tell_room(ETO, "%^ORANGE%^The cell door creaks as it swings on the hinges but "
              "shuts with an ominous, solid thud.\n");
    tell_room(CellFile, "%^ORANGE%^The cell door creaks as it swings on the hinges but "
              "shuts with an ominous, solid thud.\n");
    jailwho->force_me("look");
    force_me("close cell door");
    force_me("lock cell door with key");
    force_me("emote quickly makes some notes in a book and points to the entry.");
    force_me("say I need any and all names this criminal is known by.");
    tell_room(ETO, "OOC note:  Use <help jail> for commands to see the list and add aliases.");
    return 1;
}

int __GetKey(string str)
{
    if (AREALISTS_D->is_jailer(TP, JailLoc, TO) || avatarp(TP)) {
        if (str != "key") {
            return notify_fail("Request what?\n");
        }
        if (!present("key", TO)) {
            return notify_fail("The jailer apparently does not have a key.\n");
        }
        tell_room(ETO, TPQCN + " whispers something to the jailer.", TP);
        tell_object(TP, "You whisper your request to the jailer.");
        force_me("say As you wish.");
        command("give key to " + TPQN);
        return 1;
    }
    return notify_fail("I don't think you're authorized!\n");
}

void headlock(object targ)
{
    if (!objectp(TO)) {
        return;
    }
    if (!"daemon/saving_d"->saving_throw(targ, "paralyzation_poison_death")) {
        tell_object(targ, "%^BOLD%^%^BLUE%^The jailer slips in behind you "
                    "and puts you in a painful headlock, suffocating you!");
        tell_room(ETO, "%^BOLD%^BLUE%^The jailer slips in behind "
                  + targ->query_cap_name() + " and puts " + targ->query_objective() + " in "
                  "a headlock!", targ);
        targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(3, 5) + 10, "untyped");
        targ->set_paralyzed(50, "You are in a headlock.");
        return 1;
    }
    tell_object(targ, "%^BOLD%^BLUE%^The jailer attempts to slip in "
                "behind you but you cut him off!");
    tell_room(ETO, "%^BOLD%^BLUE%^The jailer attempts to slip in behind "
              + targ->query_cap_name() + " but " + targ->query_subjective() + " cuts "
              "him off!", targ);
    return 1;
}

void key_swipe(object targ)
{
    if (!objectp(TO)) {
        return;
    }
    if (!"daemon/saving_d"->saving_throw(targ, "rod_staff_wand")) {
        tell_object(targ, "%^BOLD%^RED%^The jailer deftly swings the heavy "
                    "key across your throat, nearly crushing it!");
        tell_room(ETO, "%^BOLD%^RED%^The jailer deftly swings the heavy key "
                  "across " + targ->QCN + "'s throat, nearly crushing it!", targ);
        targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(5, 10) + 10, "bludgeoning");
        return 1;
    }
    tell_object(targ, "%^GREEN%^The jailer swings the heavy key at your "
                "throat, barely missing it but still hitting and bruising you badly!");
    tell_room(ETO, "%^GREEN%^The jailer swings the heavy key at "
              + targ->QCN + "'s throat and " + targ->query_subjective() +
              " ducks but still gets badly bruised by it!", targ);
    targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(3, 5) + 10, "bludgeoning");
    return 1;
}

int no_way()
{
    write("The jailer easily catches you at your pitiful attempt in "
          "this small room.");
    return 1;
}
