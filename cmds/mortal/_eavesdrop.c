/* adapted from Grendel's guild/avatar command for nwps by *Styx* 10/2002
   /cmds/mortal/persnoop.c mob is created for use of hb to clean up properties as needed
   whisper command sends info. to the mob for passing back to PC eavesdropping
 NPC trainers include:
	/d/attaya/seneca/mon/trainer (20)
	/d/guilds/fist/mon/wait1 (Fist hall in Torm barkeep) (10)
	/d/npc/alinbar (5) - he's too drunk to teach well
*/
/* probably combined with possibly someone else (targets) eavesdropping
(Styx) <wiz> Oh, and duration without trying again too?
Someone <wiz> also we should change the command to allow more then one person to eaves drop
*/
/*
Someone <wiz> based on the message type it does some stuff and then calls catch tell

(Styx) <wiz> OK, boiled down to the really basic stuff, I see that.
Someone <wiz> The hard(er) part is where do you intercept it to be the best fit with everything you want to do.
Someone <wiz> because you want the person to his own tranlations I'd say that you intercept and resend immediately

Someone <wiz> you might want to parse out the whisper
Someone <wiz> the Joe whispers to you: and change it to Joe whispers to bob:
Someone <wiz> that would be a cool feature

(Styx) <wiz> I had already decided the whisper thing needed to send the prefix separate from the message.

Someone <wiz> make it so that cap names get translated to you if ...
Someone <wiz> Look at how say is parsed.
Someone <wiz> It finds the colon, then translates past the colon.
(Styx) <wiz> OK, let's see if I have the right general idea of how this would work for the eavesdrop to use receive_message?

(Styx) <wiz> We would add something into the whisper part that would check for an eavesdropper property and include the eavesdropping person/object/whatever in the list of who receives that message?
Someone <wiz> Right

(Styx) <wiz> OK, and then we'd need the code to send it what we wanted it to get versus what the normal recipient gets?
~styx/bin  Someone <wiz> So you could call find_player("grendel")->subscribe_message("say",TP) and it would send his says to you to be processed, however that's going to work.

(Styx) <wiz> And that's where he was saying it would be cool if the code could use one tell_object or whatever and substitute name for you?
~styx/bin  Someone <wiz> right
Someone <wiz> You break the whisper at the colon, then take the 'you' and parse it to '$$&&$$name$$&&$$
--------------
(Garrett) replies: No, I was thinking what if you wanted to send the subscribed messages to a different function rather than receive_message.

You reply to (Garrett): Is there a subscribe message thing too?
You reply to (Garrett): Or that's what you're calling the list of people who get a given one?
~styx/bin  (Garrett) replies: No, i was giving that as an example of what the new function in user might be called.

You reply to (Garrett): I did remember why I was poking around in it before btw.  It was cleaning up the color/resets on the in/out messages or something.
You reply to (Garrett): I figured out enough to fix some of it, but I remember some of it not cooperating too because of the way that function was laid out or something.
~styx/bin  (Garrett) replies: If you pass it as a string you can use the function form
of call_other(object ob, ({ string function, string argument }) )

(Garrett) replies: And the messages thing, you might have wanted to go lower and check out /std/user/env.c or something there.

*/

#include <std.h>
#include <move.h>
#include <daemons.h>

#define LISTENER "/realms/grendel/obj/roomsnoop.c"
#define PLISTENER "/cmds/mortal/persnoop.c"

inherit DAEMON;

int listen_room(string dir);
int listen_person(object ob, int prof);
int help();

int cmd_eavesdrop(string str){
    object targ;
    int prof, delay, bonus;
    string posxxx;
    if(!objectp(TP)) { return 0; }
    posxxx = lower_case((string)TP->query_position());
    if(posxxx == "builder" || posxxx == "apprentice")
    {
        tell_object(TP,"You cannot use this command as a builder or apprentice.");
        return 1;
    }
    if(!str) return help();
    if(TP->query_property("eavesdropping"))
	return notify_fail("You can only eavesdrop one conversation at a time.\n");

    if(avatarp(TP)) {
       if(member_array(str, ETP->query_exits()) != -1) {
          return listen_room(str);
       }
//       return 1;
    }

    targ = present(str, ETP);

    if(!targ || !objectp(targ))
        return notify_fail("You don't see that target here now do you?\n");

    if(avatarp(TP))
	return listen_person(targ, 100);

    if((object)TP->query_attackers() != ({}))
	return notify_fail("Get real, not while you're fighting!\n");

    if(targ == TP)
	return notify_fail("You can't eavesdrop yourself silly.\n");

    if(targ->query_true_invis() ||
      (targ->query_invis() && !TP->detecting_invis()) )
         return notify_fail("You don't see that target here now do you?\n");

    if(!living(targ)) return notify_fail("You can't eavesdrop that.\n");
    if( (avatarp(targ) && targ->query_lowest_level() > 99 && !wizardp(TP)) || (targ->query_property("no eavesdrop")))
       return notify_fail("You can't do that.\n");
// take this out once the list thing is working
    if(targ->query_property("eavesdropper"))
	return notify_fail("Someone is in your way.\n");

    prof = TP->query_skill("perception");;
    if(FEATS_D->usable_feat(TP,"spot"))
        prof += prof*6/5;
    if( prof > 15)  { delay = 5; }
 	else { delay = 14 - (prof/2); }

    if(!TP->query_time_delay("eavesdropping",delay))
       return notify_fail("You need to wait so you can get back in position discretely.\n");
    TP->set_time_delay("eavesdropping");

    if(!targ->query_detecting_invis() && TP->query_invis())
	bonus=4;
// this needs to be the first check for nwp effect
    if( (targ->query_skill("perception")) > prof ) {
      if (TP->query_hidden()) {
        if (objectp(present("TSR80",TP))) present("TSR80",TP)->force_cancel();
      }
      tell_object(targ, TPQCN+" moves uncomfortably closer to you.");
      tell_object(TP, targ->query_cap_name()+" seems to be uncomfortable from you being so close.");
      return 1;
    }
    return listen_person(targ, prof);
}

int listen_person(object ob, int prof){
    object lis;
    int x;
    lis = new(PLISTENER);
    lis->set_caster(TP);
    lis->set_targ(ob);
    lis->set_caster_prof(prof/2);
    x = lis->move(ETP);

    if(x != MOVE_OK){
      lis->remove();
      return notify_fail("Hmm, somthing went wrong, you can't listen to that person.\n");
    } else {
      tell_object(TP, "You begin listening to "+ob->query_cap_name()+"'s conversation.");
    }
    return 1;
}

int listen_room(string dir) {
    object ob, room;
    int x;
    string exit;

    exit = ETP->query_exit(dir);
    room = find_object_or_load(exit);

    ob = new(LISTENER);
    ob->set_caster(TP);
    x = ob->move(room);

    if(x != MOVE_OK){
      ob->remove();
      return notify_fail("Hmm, something went wrong.  You can't eavesdrop there.\n");
    } else {
      tell_object(TP, "You begin listening into the room.");
    }
    return 1;
}

void help(){

    write("
%^CYAN%^NAME%^RESET%^

eavesdrop - tap onto conversation

%^CYAN%^SYNOPSIS%^RESET%^

eavesdrop [%^ORANGE%^%^ULINE%^TARGET%^RESET%^]");
    if(avatarp(TP))
        write("eavesdrop %^ORANGE%^%^ULINE%^EXIT%^RESET%^");
    write("
%^CYAN%^DESCRIPTION%^RESET%^

This command lets you attempt to discern the whispers of another person It is a combination, depending on circumstances and your skill, of lipreading and/or managing to get in a position to overhear the whispers.

Success of this command depends on your and targets perception skill.

Without an argument, you will stop listening to other conversation.

%^CYAN%^SEE ALSO%^RESET%^

spy, look, tell, communication, step, hide_in_shadows
");
}
